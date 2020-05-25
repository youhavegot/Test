
// MFCView.cpp : CMFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC.h"
#endif
#include "W32D.h"

#include "MFCDoc.h"
#include "MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCView

IMPLEMENT_DYNCREATE(CMFCView, CView)

BEGIN_MESSAGE_MAP(CMFCView, CView)
END_MESSAGE_MAP()

// CMFCView 构造/析构

CMFCView::CMFCView()
{
	// TODO: 在此处添加构造代码

}

CMFCView::~CMFCView()
{
}

BOOL CMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCView 绘制

void CMFCView::OnDraw(CDC* pDC)
{
	CMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	FAC fac;
	CString s1, s2, s3, st;
	s1.Format(_T("%d"), factorial(5));
	st = "这是factorial(5)的运算结果:";
	s1 = st + s1;
	pDC->TextOutW(100, 100, s1);

	s2.Format(_T("%d"), factorial(18));
	st = "这是factorial(18)的运算结果:";
	s2 = st + s2;
	pDC->TextOutW(100, 150, s2);

	s3.Format(_T("%f"), fac.convert(30.0));
	st = "这是convert(30.0)的运算结果:";
	s3 = st + s3;
	pDC->TextOutW(100, 200, s3);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCView 诊断

#ifdef _DEBUG
void CMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDoc* CMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDoc)));
	return (CMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCView 消息处理程序
