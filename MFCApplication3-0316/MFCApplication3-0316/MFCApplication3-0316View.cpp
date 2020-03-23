
// MFCApplication3-0316View.cpp : CMFCApplication30316View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3-0316.h"
#endif

#include "MFCApplication3-0316Doc.h"
#include "MFCApplication3-0316View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication30316View

IMPLEMENT_DYNCREATE(CMFCApplication30316View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication30316View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_NCMOUSEMOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication30316View 构造/析构

CMFCApplication30316View::CMFCApplication30316View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication30316View::~CMFCApplication30316View()
{
}

BOOL CMFCApplication30316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication30316View 绘制

void CMFCApplication30316View::OnDraw(CDC* pDC)
{
	CMFCApplication30316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication30316View 打印

BOOL CMFCApplication30316View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication30316View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication30316View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication30316View 诊断

#ifdef _DEBUG
void CMFCApplication30316View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication30316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication30316Doc* CMFCApplication30316View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication30316Doc)));
	return (CMFCApplication30316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication30316View 消息处理程序


void CMFCApplication30316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC clientDC(this);
	CMFCApplication30316Doc* pd = GetDocument();
	pd->D_rect.left = point.x;
	pd->D_rect.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication30316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC clientDC(this);
	CMFCApplication30316Doc* pd = GetDocument();
	pd->D_rect.right = point.x;
	pd->D_rect.bottom = point.y;
	clientDC.Rectangle(pd->D_rect);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication30316View::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnNcMouseMove(nHitTest, point);
}


void CMFCApplication30316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC clientDC(this);
	CString s1, s2, s11, s22;
	s1 = _T("X=");
	s11.Format(_T("%d"), point.x);
	s1 = s1 + s11;
	s2 = _T("Y=");
	s22.Format(_T("%d"), point.y);
	s2 = s2 + s22;
	s1 = s1 + s2;
	clientDC.TextOutW(30, 30, s1);
	CView::OnMouseMove(nFlags, point);
}
