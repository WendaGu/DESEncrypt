// DESEncrypt.h : main header file for the DESENCRYPT application
//

#if !defined(AFX_DESENCRYPT_H__C4DD20EE_CD57_4465_A98A_70501F78ADE7__INCLUDED_)
#define AFX_DESENCRYPT_H__C4DD20EE_CD57_4465_A98A_70501F78ADE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptApp:
// See DESEncrypt.cpp for the implementation of this class
//

class CDESEncryptApp : public CWinApp
{
public:
	CDESEncryptApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDESEncryptApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDESEncryptApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESENCRYPT_H__C4DD20EE_CD57_4465_A98A_70501F78ADE7__INCLUDED_)
