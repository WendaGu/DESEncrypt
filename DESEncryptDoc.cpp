// DESEncryptDoc.cpp : implementation of the CDESEncryptDoc class
//

#include "stdafx.h"
#include "DESEncrypt.h"

#include "DESEncryptDoc.h"
#include "DESFileEncrypt.h"
#include "DesStringEncrypt.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptDoc

IMPLEMENT_DYNCREATE(CDESEncryptDoc, CDocument)

BEGIN_MESSAGE_MAP(CDESEncryptDoc, CDocument)
	//{{AFX_MSG_MAP(CDESEncryptDoc)
	ON_COMMAND(ID_DESFILE, OnDesfile)
	ON_COMMAND(ID_DESSTRING, OnDesstring)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptDoc construction/destruction

CDESEncryptDoc::CDESEncryptDoc()
{
	// TODO: add one-time construction code here

}

CDESEncryptDoc::~CDESEncryptDoc()
{
}

BOOL CDESEncryptDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
// CDESEncryptDoc serialization

void CDESEncryptDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptDoc diagnostics

#ifdef _DEBUG
void CDESEncryptDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDESEncryptDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptDoc commands

void CDESEncryptDoc::OnDesfile() 
{
	// TODO: Add your command handler code here
	DESFileEncrypt dlg;
	dlg.DoModal();
}

void CDESEncryptDoc::OnDesstring() 
{
	// TODO: Add your command handler code here
	DesStringEncrypt dlg;
	dlg .DoModal();
}
