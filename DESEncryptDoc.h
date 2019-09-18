// DESEncryptDoc.h : interface of the CDESEncryptDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESENCRYPTDOC_H__595BE326_EE98_4A93_8BB7_97059E7B0100__INCLUDED_)
#define AFX_DESENCRYPTDOC_H__595BE326_EE98_4A93_8BB7_97059E7B0100__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDESEncryptDoc : public CDocument
{
protected: // create from serialization only
	CDESEncryptDoc();
	DECLARE_DYNCREATE(CDESEncryptDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDESEncryptDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDESEncryptDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDESEncryptDoc)
	afx_msg void OnDesfile();
	afx_msg void OnDesstring();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESENCRYPTDOC_H__595BE326_EE98_4A93_8BB7_97059E7B0100__INCLUDED_)
