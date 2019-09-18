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
	UCHAR	Ver; //�汾
	DWORD	TLen;//�ļ�����
	char    DesKey[16];//DES��Կ����
}DESHEAD;
typedef bool	(*PSubKey)[16][48];
enum	{ENCRYPT,DECRYPT};

#define KEYSTRING "12345678"   //Ĭ�ϼ�����Կ
//////////////////////////////////////////////////////////////////////
//DES(class CDes)

class DESEncrypt: public FileEx
{
public:
	bool	Encrypt(const char *OutFile,const char *InFile,const char *KeyStr);//����
	bool	Decrypt(const char *OutFile,const char *InFile,const char *KeyStr);//����
	bool	Encrypt(HFILE &fh_out,HFILE &fh_in,const char *KeyStr);//����
	bool	Decrypt(HFILE &fh_out,HFILE &fh_in,const char *KeyStr);//����
	bool	Encrypt(char *Out,char *In,UINT len,const char *KeyStr=0);//����
	bool	Decrypt(char *Out,char *In,UINT len,const char *KeyStr=0);//����
	bool	SetSubKey(const char *KeyStr);//��������Կ����������Կ
	static	char* RandKeyStr(char KeyStr[9]);//���������Կ��
private:
	void	DES(char Out[8],char In[8],const PSubKey pSubKey,bool Type=ENCRYPT);//��/����
	void	SetSubKey(PSubKey pSubKey,const char Key[8]);//��������Կ����16Ȧ����Կ
	void	F_func(bool In[32],const bool Ki[48]);//f ����
	void	S_func(bool Out[32],const bool In[48]);//S �д���
private:
	bool	SubKey[2][16][48];//16Ȧ����Կ
	bool    Is3DES;//3��DES��־
	char    deskey[17];//��Կ��������
	char    databuf[BUFSIZE];//���ݻ�����
	DESHEAD deshead;//��Ϣͷ
};

#endif // !defined(AFX_DES_H__E0A91F40_DF86_11D6_B0C1_00E04C391A51__INCLUDED_)