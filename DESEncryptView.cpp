// DESEncryptView.cpp : implementation of the CDESEncryptView class
//

#include "stdafx.h"
#include "DESEncrypt.h"

#include "DESEncryptDoc.h"
#include "DESEncryptView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptView

IMPLEMENT_DYNCREATE(CDESEncryptView, CView)

BEGIN_MESSAGE_MAP(CDESEncryptView, CView)
	//{{AFX_MSG_MAP(CDESEncryptView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptView construction/destruction

CDESEncryptView::CDESEncryptView()
{
	// TODO: add construction code here
	m_backBimap.LoadBitmap(IDB_BITMAPBACK);
	BITMAP bmp;
	m_backBimap.GetBitmap(&bmp);
	m_iWidht=bmp.bmWidth;
	m_iHeight=bmp.bmHeight;
}

CDESEncryptView::~CDESEncryptView()
{
}

BOOL CDESEncryptView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptView drawing

void CDESEncryptView::OnDraw(CDC* pDC)
{
	CDESEncryptDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rc;
	GetClientRect(&rc);
	CDC mem;
	mem.CreateCompatibleDC(NULL);
	mem.SelectObject(m_backBimap);
	pDC->StretchBlt(0,0,rc.Width(), rc.Height(),&mem, 0, 0,m_iWidht,m_iHeight, SRCCOPY);
}

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptView printing

BOOL CDESEncryptView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDESEncryptView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDESEncryptView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptView diagnostics

#ifdef _DEBUG
void CDESEncryptView::AssertValid() const
{
	CView::AssertValid();
}

void CDESEncryptView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDESEncryptDoc* CDESEncryptView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDESEncryptDoc)));
	return (CDESEncryptDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDESEncryptView message handlers
