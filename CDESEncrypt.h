// DESEncrypt.h: interface for the CDes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DES_H__E0A91F40_DF86_11D6_B0C1_00E04C391A51__INCLUDED_)
#define AFX_DES_H__E0A91F40_DF86_11D6_B0C1_00E04C391A51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//////////////////////////////////////////////////////////////////////
#include "FileEx.h"

//////////////////////////////////////////////////////////////////////
#define BUFSIZE (1024*50)
//////////////////////////////////////////////////////////////////////
typedef struct deshead
{
	UCHAR	Ver; //版本
	DWORD	TLen;//文件长度
	char    DesKey[16];//DES密钥密文
}DESHEAD;
typedef bool	(*PSubKey)[16][48];
enum	{ENCRYPT,DECRYPT};

#define KEYSTRING "12345678"   //默认加密密钥
//////////////////////////////////////////////////////////////////////
//DES(class CDes)

class DESEncrypt: public FileEx
{
public:
	bool	Encrypt(const char *OutFile,const char *InFile,const char *KeyStr);//加密
	bool	Decrypt(const char *OutFile,const char *InFile,const char *KeyStr);//解密
	bool	Encrypt(HFILE &fh_out,HFILE &fh_in,const char *KeyStr);//加密
	bool	Decrypt(HFILE &fh_out,HFILE &fh_in,const char *KeyStr);//解密
	bool	Encrypt(char *Out,char *In,UINT len,const char *KeyStr=0);//加密
	bool	Decrypt(char *Out,char *In,UINT len,const char *KeyStr=0);//解密
	bool	SetSubKey(const char *KeyStr);//由输入密钥串设置子密钥
	static	char* RandKeyStr(char KeyStr[9]);//产生随机密钥串
private:
	void	DES(char Out[8],char In[8],const PSubKey pSubKey,bool Type=ENCRYPT);//加/解密
	void	SetSubKey(PSubKey pSubKey,const char Key[8]);//由输入密钥设置16圈子密钥
	void	F_func(bool In[32],const bool Ki[48]);//f 函数
	void	S_func(bool Out[32],const bool In[48]);//S 盒代替
private:
	bool	SubKey[2][16][48];//16圈子密钥
	bool    Is3DES;//3次DES标志
	char    deskey[17];//密钥串缓冲区
	char    databuf[BUFSIZE];//数据缓冲区
	DESHEAD deshead;//信息头
};

#endif // !defined(AFX_DES_H__E0A91F40_DF86_11D6_B0C1_00E04C391A51__INCLUDED_)
