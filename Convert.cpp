// GfL.cpp: implementation of the CGfL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Convert.h"
#include "Window.h"
#include "MyFileDialog.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define CHECK(x)		{if( !(x) ) return false;}
/////////////////////////////////////////////////////////////////////////////
#define CHECK1(x)			{if( !(x) ) return;}
#define CHECK_MSG(x,msg)	{if( !(x) ){CWindow::ShowMessage(msg);return;}}
/////////////////////////////////////////////////////////////////////////////

/******************************************************************************/
//	名称：Transform
//	功能：变换
//  参数：
//	返回：变换成功返回true，否则返回false
//  备注：
/******************************************************************************/
bool Convert::Transform(bool *Out,bool *In,const char *Table,UINT len)
{
    static bool Tmp[128];

	CHECK( Out && In && Table && len<=128 )

	for(UINT i=0; i<len; ++i)
	{
		// 注意必须是 Table[i]-1，因为表中的起始位为1，而C语言中的数组下标从0开始
        Tmp[i] = In[ Table[i]-1 ];
	}

    memcpy(Out,Tmp,len);

	return true;
}
/******************************************************************************/
//	名称：RotateL
//	功能：循环左移
//  参数：len—移动数据的长度；loop—循环左移的长度
//	返回：左移成功返回true，否则返回false
//  备注：
/******************************************************************************/
bool Convert::RotateL(char *In,UINT len,UINT loop)
{
    static char Tmp[256];

	CHECK( In && len && (loop%=len)<=256 )

	memcpy(Tmp,In,loop);
    memcpy(In,In+loop,len-loop);
    memcpy(In+len-loop,Tmp,loop);

	return true;
}
/******************************************************************************/
//	名称：Xor
//	功能：异或
//  参数：
//	返回：异或成功返回true，否则返回false
//  备注：
/******************************************************************************/
bool Convert::Xor(bool *InA,const bool *InB,UINT len)
{
	CHECK( InA && InB )

	for(UINT i=0; i<len; ++i)
	{
        InA[i] ^= InB[i];   
	}

	return true;
}
/******************************************************************************/
//	名称：ByteToBit
//	功能：将字节组转换成位组
//  参数：len—字节组长度；num—一个字节转换成几个位字节
//	返回：转换成功返回true，否则返回false
//  备注：
/******************************************************************************/
bool Convert::ByteToBit(bool *Out,const char *In,UINT len,UINT num)
{
	CHECK( Out && In && num<=8 )

	for(UINT i=0,j; i<len; ++i,Out+=num)
	{
		for(j=0; j<num; ++j)
		{
			Out[j] = (In[i]>>j) & 1;
		}
	}

	return true;
}
/******************************************************************************/
//	名称：BitToByte
//	功能：将位组转换成字节组
//  参数：len—位组长度；num—几个位字节转换成一个字节
//	返回：转换成功返回true，否则返回false
//  备注：
/******************************************************************************/
bool Convert::BitToByte(char *Out,const bool *In,UINT len,UINT num)
{
	CHECK( Out && In )

	memset(Out,0,(len+num-1)/num);
    for(UINT i=0,j,L=len/num; i<L; ++i,In+=num)
	{
		for(j=0; j<num; ++j)
		{
			Out[i] |= In[j]<<j;
		}
	}
	for(j=0; j<len%num; ++j)
	{
		Out[i] |= In[j]<<j;
	}

	return true;
}
/******************************************************************************/
//	名称：HalfByteToByte
//	功能：将半字节组转换成字节组
//  参数：
//	返回：转换成功返回true，否则返回false
//  备注：
/******************************************************************************/
bool Convert::HalfByteToByte(char *Out,const char *In,UINT len)
{
	CHECK( Out && In )

	for(UINT i=0,j=len>>1; i<j; ++i)
	{
		*Out = In[0];
		*Out |= In[1]<<4;
		++Out; In += 2;
	}
   
	if( len%2 )
		*Out = *In;

	return true;
}
/******************************************************************************/
//	名称：ByteToHalfByte
//	功能：将字节组转换成半字节组
//  参数：
//	返回：转换成功返回true，否则返回false
//  备注：
/******************************************************************************/
bool Convert::ByteToHalfByte(char *Out,const char *In,UINT len)
{
	CHECK( Out && In )

	for(UINT i=0; i<len; ++i)
	{
		Out[0] = (*In)&0xf;
		Out[1] = ((*In)>>4)&0xf;
		Out += 2; ++In;
	}

	return true;
}
/******************************************************************************/
//	名称：StrToHalfByte
//	功能：将字符串转换成半字节组
//  参数：
//	返回：合法字符('0'-'9','A'-'F')的个数
//  备注：
/******************************************************************************/
int Convert::StrToHalfByte(char *Out,char *In,UINT len)
{
	CHECK( Out && In )

	for(UINT i=0,j=0; i<len; ++i)
	{
		if( (In[i]>='0') && (In[i]<='9') )
			Out[j++] = In[i]-'0';
		else if( (In[i]>='A') && (In[i]<='F') )
			Out[j++] = In[i]-'A'+10;
		else if( (In[i]>='a') && (In[i]<='f') )
			Out[j++] = In[i]-'a'+10;
	}

	return j;
}
/******************************************************************************/
//	名称：HalfByteToStr
//	功能：将半字节组转换成字符串
//  参数：
//	返回：合法数(0-15)的个数
//  备注：
/******************************************************************************/
int  Convert::HalfByteToStr(char *Out,char *In,UINT len)
{
	CHECK( Out && In )

	for(UINT i=0,j=0; i<len; ++i)
	{
		if( (In[i]>=0) && (In[i]<10) )
			Out[j++] = In[i]+'0';
		else if( (In[i]>9) && (In[i]<16) )
			Out[j++] = In[i]-10+'A';
	}
	Out[j] = '\0';

	return j-1;
}
///////////////////////////
void Convert::BuildOutputFileName(CString &input,CString &output,bool run_t,CString p,CString f)
{
	CString path=CWindow::GetPath(input);//(p==' '?CWindow::GetPath(input):p );
	CString name= CWindow::GetFileNameNoExt( output.IsEmpty() ? input : output );//文件名
	CString ext = CWindow::GetExtName(input);//扩展名
	CString newext = (run_t) ? "" :f;
	if( path.GetAt( path.GetLength()-1 ) != '\\' ) 
		path += "\\";
	if( run_t)//1解密
		if( ext.GetLength()>4 && ext.GetAt(ext.GetLength()-4)=='.' )
			ext = ext.Left( ext.GetLength()-4 );
	    else
			ext = "";
	output =path +  name;
	if( ext.GetLength() )
		output += "." + ext;
	if( newext.GetLength() )
		output += "." + newext;
}
void Convert::Browse(CString &input,CString &output)
{ 
	CString Filter= "所有文件(*.*)|*.*|文本文件(*.txt)|*.txt|"
		           "混合加密文件(*.mcs)|*.mcs|DES加密文件(*.des)|*.des||";
	CMyFileDialog FileDlg (TRUE, NULL, NULL, OFN_HIDEREADONLY, Filter);
	CHECK1( FileDlg.DoModal() == IDOK )

	input = FileDlg.GetPathName();//E:\a-hua作业\毕业设计\上机算法\混合密码系统\文档1.doc
	output = "";
}

///////////////////////////////////////////////////////////////////////////////
// End of Files
///////////////////////////////////////////////////////////////////////////////
