#if !defined(AFX_DESFILEENCRYPT_H__01732673_7500_41C1_81AE_E1AE5348D81C__INCLUDED_)
#define AFX_DESFILEENCRYPT_H__01732673_7500_41C1_81AE_E1AE5348D81C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DESFileEncrypt.h : header file
//
#include "CDESEncrypt.h"
/////////////////////////////////////////////////////////////////////////////
// DESFileEncrypt dialog

class DESFileEncrypt : public CDialog
{
// Construction
public:
	DESFileEncrypt(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DESFileEncrypt)
	enum { IDD = IDD_DLGDESFILE };
	CString	m_strInPut;
	CString	m_strOutPut;
	CString	m_strDesKey1;
	CString	m_strDesKey2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DESFileEncrypt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
	bool m_bRunType;
	CString m_strNewPath;
    DESEncrypt m_des;
	CString m_strMessage;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DESFileEncrypt)
	afx_msg void OnRun();
	afx_msg void Onreturn();
	afx_msg void OnBrowse();
	afx_msg void OnOutFolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESFILEENCRYPT_H__01732673_7500_41C1_81AE_E1AE5348D81C__INCLUDED_)
