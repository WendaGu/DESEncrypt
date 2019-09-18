// DESEncryptView.h : interface of the CDESEncryptView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESENCRYPTVIEW_H__6AD360C1_D699_4189_8189_BF117289C7AF__INCLUDED_)
#define AFX_DESENCRYPTVIEW_H__6AD360C1_D699_4189_8189_BF117289C7AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDESEncryptView : public CView
{
protected: // create from serialization only
	CDESEncryptView();
	DECLARE_DYNCREATE(CDESEncryptView)

// Attributes
public:
	CDESEncryptDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDESEncryptView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDESEncryptView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CBitmap m_backBimap;
	int     m_iWidht;
	int     m_iHeight;
// Generated message map functions
protected:
	//{{AFX_MSG(CDESEncryptView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DESEncryptView.cpp
inline CDESEncryptDoc* CDESEncryptView::GetDocument()
   { return (CDESEncryptDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESENCRYPTVIEW_H__6AD360C1_D699_4189_8189_BF117289C7AF__INCLUDED_)
