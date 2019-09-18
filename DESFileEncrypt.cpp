// DESFileEncrypt.cpp : implementation file
//

#include "stdafx.h"
#include "DESEncrypt.h"
#include "DESFileEncrypt.h"
#include "Convert.h"
#include "Window.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define CHECK(x)			{if( !(x) ) return;}
#define CHECK_MSG(x,msg)	{if( !(x) ){CWindow::ShowMessage(msg);return;}}
#define DESEXT _T("DES")
/////////////////////////////////////////////////////////////////////////////
// DESFileEncrypt dialog


DESFileEncrypt::DESFileEncrypt(CWnd* pParent /*=NULL*/)
	: CDialog(DESFileEncrypt::IDD, pParent)
{
	//{{AFX_DATA_INIT(DESFileEncrypt)
	m_strInPut = _T("");
	m_strOutPut = _T("");
	m_strDesKey1 = _T("");
	m_strDesKey2 = _T("");
	//}}AFX_DATA_INIT
}


void DESFileEncrypt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DESFileEncrypt)
	DDX_Text(pDX, IDC_Input, m_strInPut);
	DDX_Text(pDX, IDC_Output, m_strOutPut);
	DDX_Text(pDX, IDC_DesKey1, m_strDesKey1);
	DDX_Text(pDX, IDC_DesKey2, m_strDesKey2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DESFileEncrypt, CDialog)
	//{{AFX_MSG_MAP(DESFileEncrypt)
	ON_BN_CLICKED(IDC_Run, OnRun)
	ON_BN_CLICKED(IDC_return, Onreturn)
	ON_BN_CLICKED(IDC_Browse, OnBrowse)
	ON_BN_CLICKED(IDC_OutFolder, OnOutFolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DESFileEncrypt message handlers

void DESFileEncrypt::OnRun() 
{
	// TODO: Add your control notification handler code here
	//CHECK( IDYES == MessageBox("真的要进行该操作吗? ","提示",MB_YESNO | MB_ICONQUESTION))
	
	bool	flage;
	DWORD   time=GetTickCount();
	
    UpdateData(true);
    Convert::BuildOutputFileName(m_strInPut,m_strOutPut,m_bRunType,m_strNewPath,DESEXT);
    UpdateData(false);
	
	if(m_strDesKey1 == m_strDesKey2)
	{
		if( m_bRunType==ENCRYPT ) 
			flage=m_des.Encrypt(m_strOutPut.GetBuffer(0),m_strInPut.GetBuffer(0),m_strDesKey1.GetBuffer(0));
		else
			flage=m_des.Decrypt(m_strOutPut.GetBuffer(0),m_strInPut.GetBuffer(0),m_strDesKey1.GetBuffer(0));
		
		if( flage )
		{
			m_strMessage.Format("%s成功! 用时%u秒。",(m_bRunType==ENCRYPT)?"加密":"解密",(GetTickCount()-time)/1000);
			MessageBox(m_strMessage,"提示",MB_ICONINFORMATION);		
		}
	}
	else
	{
		CWindow::ShowMessage("错误：DES密钥不一致! ");
	}

}

void DESFileEncrypt::Onreturn() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void DESFileEncrypt::OnBrowse() 
{
	// TODO: Add your control notification handler code here
	Convert::Browse(m_strInPut,m_strOutPut);
    UpdateData(false);
    if(!m_strInPut.IsEmpty())
	{
		m_bRunType=DECRYPT;//=1
		SetDlgItemText(IDC_Run,"解密");
		if(m_strInPut.Find(".des")>0 || m_strInPut.Find(".DES")>0)
		{
			Convert::BuildOutputFileName(m_strInPut,m_strOutPut,m_bRunType,m_strNewPath,DESEXT);
            UpdateData(false);
		}
		else
		{
			m_bRunType = ENCRYPT;//加密
			SetDlgItemText(IDC_Run,"加密");
			Convert::BuildOutputFileName(m_strInPut,m_strOutPut,m_bRunType,m_strNewPath,DESEXT);
            UpdateData(false);
		}
	}
}

void DESFileEncrypt::OnOutFolder() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if( m_strInPut.IsEmpty() )
		MessageBox("请先输入要保存文件 ","提示",MB_ICONINFORMATION);
    else 
	{
		CWindow::GetFolder(m_strNewPath);
		Convert::BuildOutputFileName(m_strInPut,m_strOutPut,m_bRunType,m_strNewPath,DESEXT);
	}
	//   saveas = tmp;
	UpdateData(false);	
}
