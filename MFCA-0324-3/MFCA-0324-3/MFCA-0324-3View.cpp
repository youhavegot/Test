
// MFCA-0324-3View.cpp : CMFCA03243View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA-0324-3.h"
#endif

#include "MFCA-0324-3Doc.h"
#include "MFCA-0324-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA03243View

IMPLEMENT_DYNCREATE(CMFCA03243View, CView)

BEGIN_MESSAGE_MAP(CMFCA03243View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DRAWLI, &CMFCA03243View::OnDrawli)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAWRE, &CMFCA03243View::OnDrawre)
	ON_COMMAND(ID_DRAWRO, &CMFCA03243View::OnDrawro)
END_MESSAGE_MAP()

// CMFCA03243View 构造/析构

CMFCA03243View::CMFCA03243View()
{
	// TODO: 在此处添加构造代码
	for (int i = 0; i < n; i++) {
		set[i] = false;
	}
}

CMFCA03243View::~CMFCA03243View()
{
}

BOOL CMFCA03243View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA03243View 绘制

void CMFCA03243View::OnDraw(CDC* /*pDC*/)
{
	CMFCA03243Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA03243View 打印

BOOL CMFCA03243View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCA03243View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCA03243View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCA03243View 诊断

#ifdef _DEBUG
void CMFCA03243View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA03243View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA03243Doc* CMFCA03243View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA03243Doc)));
	return (CMFCA03243Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA03243View 消息处理程序


void CMFCA03243View::OnDrawli()
{
	// TODO: 在此添加命令处理程序代码
	set[0] = true;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			set[i] = false;
		}
	}
	Invalidate();
}


void CMFCA03243View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	point1 = point;
	//Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCA03243View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	for (int i = 0; i < n; i++) {
		if (set[0] == true) {
			dc.MoveTo(point1);
			dc.LineTo(point);
		}
		else if (set[1] == true) {
			CRect cr1 = CRect(point1.x, point1.y, point.x, point.y);
			dc.Rectangle(cr1);
		}
		else if (set[2] == true) {
			CRect cr2 = CRect(point1.x, point1.y, point.x, point.y);
			dc.Ellipse(cr2);
		}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMFCA03243View::OnDrawre()
{
	// TODO: 在此添加命令处理程序代码
	set[1] = true;
	for (int i = 0; i < n; i++) {
		if (i != 1) {
			set[i] = false;
		}
	}
	Invalidate();
}


void CMFCA03243View::OnDrawro()
{
	// TODO: 在此添加命令处理程序代码
	set[2] = true;
	for (int i = 0; i < n; i++) {
		if (i != 2) {
			set[i] = false;
		}
	}
	Invalidate();
}
