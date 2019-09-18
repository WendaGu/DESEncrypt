#if !defined(AFX_MYFILEDIALOG_H__008D8520_5D01_47F2_9000_D702118CBBF6__INCLUDED_)
#define AFX_MYFILEDIALOG_H__008D8520_5D01_47F2_9000_D702118CBBF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyFileDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyFileDialog dialog

class CMyFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CMyFileDialog)

public:
	CMyFileDialog(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);

protected:
	//{{AFX_MSG(CMyFileDialog)
		// NOTE - the ClassWizard will add and remove member functions here.
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFILEDIALOG_H__008D8520_5D01_47F2_9000_D702118CBBF6__INCLUDED_)
