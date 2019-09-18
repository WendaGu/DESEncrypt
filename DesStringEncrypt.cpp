// DesStringEncrypt.cpp : implementation file
//

#include "stdafx.h"
#include "DESEncrypt.h"
#include "DesStringEncrypt.h"
#include "Convert.h"
#include "Window.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DesStringEncrypt dialog


DesStringEncrypt::DesStringEncrypt(CWnd* pParent /*=NULL*/)
	: CDialog(DesStringEncrypt::IDD, pParent)
{
	//{{AFX_DATA_INIT(DesStringEncrypt)
	m_strInput = _T("");
	m_strOutPut = _T("");
	m_strDesKey1 = _T("");
	m_strDesKey2 = _T("");
	//}}AFX_DATA_INIT
	m_bRunType=ENCRYPT;//=0
}


void DesStringEncrypt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DesStringEncrypt)
	DDX_Text(pDX, IDC_EDITINPUT, m_strInput);
	DDX_Text(pDX, IDC_EDITOUTPUT, m_strOutPut);
	DDX_Text(pDX, IDC_DesKey1, m_strDesKey1);
	DDX_Text(pDX, IDC_DesKey2, m_strDesKey2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DesStringEncrypt, CDialog)
	//{{AFX_MSG_MAP(DesStringEncrypt)
	ON_BN_CLICKED(IDC_RADIOJIAMI, OnRadiojiami)
	ON_BN_CLICKED(IDC_RADIOJIEMI, OnRadiojiemi)
	ON_BN_CLICKED(IDC_BTNRun, OnBTNRun)
	ON_BN_CLICKED(IDC_BTNReturn, OnBTNReturn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DesStringEncrypt message handlers

void DesStringEncrypt::OnRadiojiami() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_Run,"加密");
	m_bRunType=ENCRYPT;//=0
}

void DesStringEncrypt::OnRadiojiemi() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_Run,"解密");
	m_bRunType=DECRYPT;//=1
}

void DesStringEncrypt::OnBTNRun() 
{
	// TODO: Add your control notification handler code here
	

	bool	flage;
	DWORD   time=GetTickCount();
	
    UpdateData(true);
    int strLen=m_strInput.GetLength();
	if (strLen>0)
	{
		strLen = ((strLen+7)>>3)<<3;
		char *buffer=new char[strLen];
	    memset(buffer,0,strLen);
		if(m_strDesKey1 == m_strDesKey2&&m_strDesKey2.GetLength()!=0)
		{
			if( m_bRunType==ENCRYPT ) 	
	        	flage=m_des.Encrypt(buffer,m_strInput.GetBuffer(0),strLen,m_strDesKey1.GetBuffer(0));
			else
				flage=m_des.Decrypt(buffer,m_strInput.GetBuffer(0),strLen,m_strDesKey1.GetBuffer(0));
			
			if( flage )
			{
				CString strMessage;
				strMessage.Format("%s成功! 用时%u秒。",(m_bRunType==ENCRYPT)?"加密":"解密",(GetTickCount()-time)/1000);
				MessageBox(strMessage,"提示",MB_ICONINFORMATION);		
			}
		}
		else if (m_strDesKey1.GetLength()==0&&m_strDesKey2.GetLength()==0)
		{
			//使用默认密码加密解密
			CString keyString=KEYSTRING;

			if( m_bRunType==ENCRYPT ) 	
				flage=m_des.Encrypt(buffer,m_strInput.GetBuffer(0),strLen,keyString.GetBuffer(0));
			else
				flage=m_des.Decrypt(buffer,m_strInput.GetBuffer(0),strLen,keyString.GetBuffer(0));
			
			if( flage )
			{
				CString strMessage;
				strMessage.Format("%s成功! 用时%u秒。",(m_bRunType==ENCRYPT)?"加密":"解密",(GetTickCount()-time)/1000);
				MessageBox(strMessage,"提示",MB_ICONINFORMATION);		
			}
		}
		else if (m_strDesKey1.GetLength()>0)
		{
			CWindow::ShowMessage("错误：DES密钥不一致! ");
		}
		m_strOutPut.Format("%s",buffer);
		delete []buffer;
	}
	UpdateData(false);

}

void DesStringEncrypt::OnBTNReturn() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
