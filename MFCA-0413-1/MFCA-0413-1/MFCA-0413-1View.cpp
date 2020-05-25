
// MFCA-0413-1View.cpp : CMFCA04131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA-0413-1.h"
#endif

#include "MFCA-0413-1Doc.h"
#include "MFCA-0413-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA04131View

IMPLEMENT_DYNCREATE(CMFCA04131View, CView)

BEGIN_MESSAGE_MAP(CMFCA04131View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCA04131View 构造/析构

CMFCA04131View::CMFCA04131View()
{
	// TODO: 在此处添加构造代码

}

CMFCA04131View::~CMFCA04131View()
{
}

BOOL CMFCA04131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA04131View 绘制

void CMFCA04131View::OnDraw(CDC* pDC)
{
	CMFCA04131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA04131View 打印

BOOL CMFCA04131View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCA04131View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCA04131View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCA04131View 诊断

#ifdef _DEBUG
void CMFCA04131View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA04131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA04131Doc* CMFCA04131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA04131Doc)));
	return (CMFCA04131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA04131View 消息处理程序


void CMFCA04131View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCA04131Doc* pd = GetDocument();
	if (pd->cr.left < point.x&&point.x < pd->cr.right&&pd->cr.top < point.y&&point.y < pd->cr.bottom) {
		set = true;
		pd->cp = point;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCA04131View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCA04131Doc* pd = GetDocument();
	CClientDC dc(this);
	if (set == true) {
		int xd = point.x - pd->cp.x;
		int yd = point.y - pd->cp.y;
		pd->cr.left = pd->cr.left + xd;
		pd->cr.right = pd->cr.right + xd;
		pd->cr.top = pd->cr.top + yd;
		pd->cr.bottom = pd->cr.bottom + yd;
		pd->cp = point;
		InvalidateRect(NULL, TRUE);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCA04131View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFCA04131View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMFCA04131Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(cr);
	CPoint cp = cr.CenterPoint();
	pDoc->cr = CRect(cp.x - 100, cp.y - 75, cp.x + 100, cp.y + 75);
	dc.Rectangle(pDoc->cr);
	CView::OnRButtonDown(nFlags, point);
}
