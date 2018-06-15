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

// SDIView.h : interface of the CSDIView class
//

#pragma once

#include "ChildWnd.h"

class CSDIView : public CView
{
protected: // create from serialization only
	CSDIView();
	DECLARE_DYNCREATE(CSDIView)

// Attributes
public:
	CSDIDoc* GetDocument() const;

// Operations
public:
	CChildWnd m_Wnd01;
	CChildWnd m_Wnd02;
	CButton m_Decrease_Btn;
	CButton m_Increase_Btn;
	CListBox m_ListBox;
	CProgressCtrl m_ProgressBar;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void CSDIView::OnDecreaseButton();
	afx_msg void CSDIView::OnIncreaseButton();
};

#ifndef _DEBUG  // debug version in SDIView.cpp
inline CSDIDoc* CSDIView::GetDocument() const
   { return reinterpret_cast<CSDIDoc*>(m_pDocument); }
#endif

