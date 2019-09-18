#if !defined(AFX_DESSTRINGENCRYPT_H__42FDF62C_9A7B_4F62_BB17_46154515BA72__INCLUDED_)
#define AFX_DESSTRINGENCRYPT_H__42FDF62C_9A7B_4F62_BB17_46154515BA72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DesStringEncrypt.h : header file
//
#include "CDESEncrypt.h"
/////////////////////////////////////////////////////////////////////////////
// DesStringEncrypt dialog

class DesStringEncrypt : public CDialog
{
// Construction
public:
	DesStringEncrypt(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DesStringEncrypt)
	enum { IDD = IDD_DLGDESSTING };
	CString	m_strInput;
	CString	m_strOutPut;
	CString	m_strDesKey1;
	CString	m_strDesKey2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DesStringEncrypt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bRunType;
	DESEncrypt m_des;

	// Generated message map functions
	//{{AFX_MSG(DesStringEncrypt)
	afx_msg void OnRadiojiami();
	afx_msg void OnRadiojiemi();
	afx_msg void OnBTNRun();
	afx_msg void OnBTNReturn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESSTRINGENCRYPT_H__42FDF62C_9A7B_4F62_BB17_46154515BA72__INCLUDED_)
