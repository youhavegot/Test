
// MFCApplication3-0317View.cpp : CMFCApplication30317View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3-0317.h"
#endif

#include "MFCApplication3-0317Doc.h"
#include "MFCApplication3-0317View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication30317View

IMPLEMENT_DYNCREATE(CMFCApplication30317View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication30317View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication30317View 构造/析构

CMFCApplication30317View::CMFCApplication30317View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication30317View::~CMFCApplication30317View()
{
}

BOOL CMFCApplication30317View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication30317View 绘制

void CMFCApplication30317View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication30317Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication30317View 打印

BOOL CMFCApplication30317View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication30317View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication30317View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication30317View 诊断

#ifdef _DEBUG
void CMFCApplication30317View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication30317View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication30317Doc* CMFCApplication30317View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication30317Doc)));
	return (CMFCApplication30317Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication30317View 消息处理程序


void CMFCApplication30317View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	n = 0;
	p2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication30317View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	n++;
	sn++;
	CString s;
	s.Format(_T("%d"), sn);
	CClientDC dc(this);
	dc.TextOutW(30, 30, _T("MouseMove共发生 ") + s + _T(" 次"));
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication30317View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p2 = point;
	int c = p2.x - p1.x;
	int d = c / n;
	CString s;
	s.Format(_T("%d"), n);
	CClientDC dc(this);
	dc.TextOutW(30, 85, _T("左键按下至抬起过程中MouseMove发生 ")+s+_T(" 次"));
	s.Format(_T("%d"), d);
	dc.TextOutW(30, 140, _T("且在这个过程中横向移动 ")+s+_T(" 个像素发生一次"));
	CView::OnLButtonUp(nFlags, point);
}
