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
//	���ƣ�Transform
//	���ܣ��任
//  ������
//	���أ��任�ɹ�����true�����򷵻�false
//  ��ע��
/******************************************************************************/
bool Convert::Transform(bool *Out,bool *In,const char *Table,UINT len)
{
    static bool Tmp[128];

	CHECK( Out && In && Table && len<=128 )

	for(UINT i=0; i<len; ++i)
	{
		// ע������� Table[i]-1����Ϊ���е���ʼλΪ1����C�����е������±��0��ʼ
        Tmp[i] = In[ Table[i]-1 ];
	}

    memcpy(Out,Tmp,len);

	return true;
}
/******************************************************************************/
//	���ƣ�RotateL
//	���ܣ�ѭ������
//  ������len���ƶ����ݵĳ��ȣ�loop��ѭ�����Ƶĳ���
//	���أ����Ƴɹ�����true�����򷵻�false
//  ��ע��
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
//	���ƣ�Xor
//	���ܣ����
//  ������
//	���أ����ɹ�����true�����򷵻�false
//  ��ע��
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
//	���ƣ�ByteToBit
//	���ܣ����ֽ���ת����λ��
//  ������len���ֽ��鳤�ȣ�num��һ���ֽ�ת���ɼ���λ�ֽ�
//	���أ�ת���ɹ�����true�����򷵻�false
//  ��ע��
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
//	���ƣ�BitToByte
//	���ܣ���λ��ת�����ֽ���
//  ������len��λ�鳤�ȣ�num������λ�ֽ�ת����һ���ֽ�
//	���أ�ת���ɹ�����true�����򷵻�false
//  ��ע��
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
//	���ƣ�HalfByteToByte
//	���ܣ������ֽ���ת�����ֽ���
//  ������
//	���أ�ת���ɹ�����true�����򷵻�false
//  ��ע��
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
//	���ƣ�ByteToHalfByte
//	���ܣ����ֽ���ת���ɰ��ֽ���
//  ������
//	���أ�ת���ɹ�����true�����򷵻�false
//  ��ע��
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
//	���ƣ�StrToHalfByte
//	���ܣ����ַ���ת���ɰ��ֽ���
//  ������
//	���أ��Ϸ��ַ�('0'-'9','A'-'F')�ĸ���
//  ��ע��
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
//	���ƣ�HalfByteToStr
//	���ܣ������ֽ���ת�����ַ���
//  ������
//	���أ��Ϸ���(0-15)�ĸ���
//  ��ע��
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
	CString name= CWindow::GetFileNameNoExt( output.IsEmpty() ? input : output );//�ļ���
	CString ext = CWindow::GetExtName(input);//��չ��
	CString newext = (run_t) ? "" :f;
	if( path.GetAt( path.GetLength()-1 ) != '\\' ) 
		path += "\\";
	if( run_t)//1����
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
	CString Filter= "�����ļ�(*.*)|*.*|�ı��ļ�(*.txt)|*.txt|"
		           "��ϼ����ļ�(*.mcs)|*.mcs|DES�����ļ�(*.des)|*.des||";
	CMyFileDialog FileDlg (TRUE, NULL, NULL, OFN_HIDEREADONLY, Filter);
	CHECK1( FileDlg.DoModal() == IDOK )

	input = FileDlg.GetPathName();//E:\a-hua��ҵ\��ҵ���\�ϻ��㷨\�������ϵͳ\�ĵ�1.doc
	output = "";
}

///////////////////////////////////////////////////////////////////////////////
// End of Files
///////////////////////////////////////////////////////////////////////////////
