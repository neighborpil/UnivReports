// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// SDIView.cpp : implementation of the CSDIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDI.h"
#endif

#include "SDIDoc.h"
#include "SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define ID_DECREASE_BUTTON	3000
#define ID_INCREASE_BUTTON	3100
#define ID_LISTBOX			3200
#define ID_PROGBAR			3300
// CSDIView

IMPLEMENT_DYNCREATE(CSDIView, CView)

BEGIN_MESSAGE_MAP(CSDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSDIView::OnFilePrintPreview)
	ON_COMMAND(ID_DECREASE_BUTTON, OnDecreaseButton)
	ON_COMMAND(ID_INCREASE_BUTTON, OnIncreaseButton)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CSDIView construction/destruction




CSDIView::CSDIView()
{
	// TODO: add construction code here

}

CSDIView::~CSDIView()
{
}

BOOL CSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSDIView drawing

void CSDIView::OnDraw(CDC* /*pDC*/)
{
	CSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSDIView printing


void CSDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSDIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSDIView diagnostics

#ifdef _DEBUG
void CSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIDoc* CSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIDoc)));
	return (CSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIView message handlers


int CSDIView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_Wnd01.Create(AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW),
		_T("첫 번째 차일드 윈도우"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CHILD,
		CRect(50, 50, 300, 200),
		this,
		1010);

	m_Wnd02.Create(AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW),
		_T("두 번째 차일드 윈도우"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CHILD,
		CRect(350, 50, 600, 200),
		this,
		1020);

	m_Increase_Btn.Create(_T("증가"), WS_VISIBLE, CRect(350, 300, 500, 330),
		this, ID_INCREASE_BUTTON);
	m_Decrease_Btn.Create(_T("감소"), WS_VISIBLE, CRect(350, 350, 500, 380),
		this, ID_DECREASE_BUTTON);
	
	m_ListBox.Create(WS_DLGFRAME | WS_VISIBLE, CRect(50, 300, 300, 500),
		this, ID_LISTBOX);
	m_ListBox.AddString(_T("윈도우 프로그래밍"));

	m_ProgressBar.Create(WS_DLGFRAME | WS_VISIBLE, CRect(50, 230, 300, 270),
		this, ID_PROGBAR);
	m_ProgressBar.SetRange(0, 10);
	m_ProgressBar.SetPos(1);

	return 0;
}

void CSDIView::OnDecreaseButton()
{
	int count = m_ListBox.GetCount();
	if (count > 0) 
	{
		m_ListBox.DeleteString(count - 1);
		m_ProgressBar.SetPos(count - 1);
	}
	else
	{
		AfxMessageBox(_T("지울 아이템이 없습니다"));
	}
}

void CSDIView::OnIncreaseButton()
{
	int count = m_ListBox.GetCount();
	if (count < 10)
	{
		m_ListBox.AddString(_T("지울 아이템이 없습니다"));
		m_ProgressBar.SetPos(count+1);
	}
	else
	{
		AfxMessageBox(_T("더이상 추가 할 수 없습니다"));
	}
}
