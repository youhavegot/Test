
// MFCApplication2(5)View.cpp : CMFCApplication25View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2(5).h"
#endif

#include "MFCApplication2(5)Doc.h"
#include "MFCApplication2(5)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication25View

IMPLEMENT_DYNCREATE(CMFCApplication25View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication25View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication25View 构造/析构

CMFCApplication25View::CMFCApplication25View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication25View::~CMFCApplication25View()
{
}

BOOL CMFCApplication25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication25View 绘制

void CMFCApplication25View::OnDraw(CDC* pDC)
{
	CMFCApplication25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush brush(RGB(0, 0, 255));
	CPoint p;
	pDC->TextOutW(150, 80, _T("A"));
	pDC->TextOutW(450, 80, _T("B"));
	pDC->TextOutW(650, 280, _T("C"));
	pDoc->A=CRect(100, 100, 260, 260);
	pDoc->B=CRect(400, 100, 500, 500);
	pDoc->C=CRect(600, 300, 800, 500);
	pDC->FillRect(&pDoc->A, &brush);
	pDC->FillRect(&pDoc->B, &brush);
	pDC->FillRect(&pDoc->C, &brush);


	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication25View 打印

BOOL CMFCApplication25View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication25View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication25View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication25View 诊断

#ifdef _DEBUG
void CMFCApplication25View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication25Doc* CMFCApplication25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication25Doc)));
	return (CMFCApplication25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication25View 消息处理程序


void CMFCApplication25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);
	CString s;
	CMFCApplication25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (point.x > pDoc->A.left&&point.x<pDoc->A.right&&point.y>pDoc->A.top&&point.y < pDoc->A.bottom) {
		pDoc->a = rand()%40;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(150, 150, s);
	}
	else if (point.x > pDoc->B.left&&point.x<pDoc->B.right&&point.y>pDoc->B.top&&point.y <pDoc->B.bottom) {
		pDoc->b = rand()%40;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(450, 250, s);
	}
	else if (point.x > pDoc->C.left&&point.x<pDoc->C.right&&point.y>pDoc->C.top&&point.y < pDoc->C.bottom) {
		int c = pDoc->a + pDoc->b;
		if (pDoc->a != -1 && pDoc->b != -1) {
			s.Format(_T("%d"), c);
			dc.TextOutW(700, 400, s);
		}
		else
			dc.TextOutW(800, 100, _T("a或b的值未确定"));
	}
	else
		dc.TextOutW(600, 100, _T("点击无效"));

	CView::OnLButtonDown(nFlags, point);
}
