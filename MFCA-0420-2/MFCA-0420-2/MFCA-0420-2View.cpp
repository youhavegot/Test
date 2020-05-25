
// MFCA-0420-2View.cpp : CMFCA04202View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA-0420-2.h"
#endif

#include "MFCA-0420-2Doc.h"
#include "MFCA-0420-2View.h"
#include "MyDlg.h"
#include "MyDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA04202View

IMPLEMENT_DYNCREATE(CMFCA04202View, CView)

BEGIN_MESSAGE_MAP(CMFCA04202View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_MBUTTONDOWN()
ON_WM_LBUTTONDOWN()
//ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONUP()
ON_COMMAND(ID_DE, &CMFCA04202View::OnDe)
ON_WM_RBUTTONDOWN()
ON_COMMAND(ID_32773, &CMFCA04202View::On32773)
END_MESSAGE_MAP()

// CMFCA04202View 构造/析构

CMFCA04202View::CMFCA04202View()
{
	// TODO: 在此处添加构造代码

}

CMFCA04202View::~CMFCA04202View()
{
}

BOOL CMFCA04202View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA04202View 绘制

void CMFCA04202View::OnDraw(CDC* pDC)
{
	CMFCA04202Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Ellipse(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA04202View 打印

BOOL CMFCA04202View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCA04202View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCA04202View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCA04202View 诊断

#ifdef _DEBUG
void CMFCA04202View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA04202View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA04202Doc* CMFCA04202View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA04202Doc)));
	return (CMFCA04202Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA04202View 消息处理程序





void CMFCA04202View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CMFCA04202Doc* pd = GetDocument();
	pd->cr.left = point.x;
	pd->cr.top = point.y;
	set = true;
	CView::OnLButtonDown(nFlags, point);
}





void CMFCA04202View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCA04202Doc* pd = GetDocument();
	if (set == true) {
		pd->cr.right = point.x;
		pd->cr.bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCA04202View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFCA04202View::OnDe()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	CMFCA04202Doc* pd = GetDocument();
	if (IDOK == dlg.DoModal()) {
		this->UpdateData(true);
		pd->cr = CRect(dlg.x, dlg.y, dlg.x + 2 * dlg.a, dlg.y + 2 * dlg.b);
		GetDC()->Ellipse(pd->cr);
		Invalidate();
	}
	
}


void CMFCA04202View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCA04202Doc* pd = GetDocument();
	CDC* dc = GetDC();

	if (pd->cr.left <= point.x&&point.x <= pd->cr.right&&pd->cr.top <= point.y&&point.y <= pd->cr.bottom) {
		dc->Ellipse(pd->cr);
		CPen * pOldPen = NULL;
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
		pOldPen = dc->SelectObject(&pen);
		CBrush * pOldBrush = NULL;
		CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pOldBrush = dc->SelectObject(pBrush);
		cr = pd->cr;
		dc->Rectangle(cr);
		dc->SelectObject(pOldPen);
	}
	CView::OnRButtonDown(nFlags, point);
}


void CMFCA04202View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	if (dlg.DoModal() == IDOK) {

	}
	
}
