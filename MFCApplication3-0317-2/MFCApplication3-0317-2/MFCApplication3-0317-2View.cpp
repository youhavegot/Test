
// MFCApplication3-0317-2View.cpp : CMFCApplication303172View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3-0317-2.h"
#endif

#include "MFCApplication3-0317-2Doc.h"
#include "MFCApplication3-0317-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication303172View

IMPLEMENT_DYNCREATE(CMFCApplication303172View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication303172View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication303172View 构造/析构

CMFCApplication303172View::CMFCApplication303172View()
{
	// TODO: 在此处添加构造代码
	
}

CMFCApplication303172View::~CMFCApplication303172View()
{
}

BOOL CMFCApplication303172View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}

// CMFCApplication303172View 绘制

void CMFCApplication303172View::OnDraw(CDC* pDC)
{
	CMFCApplication303172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(pDoc->rect);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication303172View 打印

BOOL CMFCApplication303172View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication303172View::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication303172View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication303172View 诊断

#ifdef _DEBUG
void CMFCApplication303172View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication303172View::Dump(CDumpContext& dc) const
{
	
	CView::Dump(dc);
}

CMFCApplication303172Doc* CMFCApplication303172View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication303172Doc)));
	return (CMFCApplication303172Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication303172View 消息处理程序


void CMFCApplication303172View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication303172Doc* p = GetDocument();
	CRect Crect;
	GetClientRect(&Crect);
	switch (nChar)
	{
	case VK_LEFT:
		if (p->rect.left > 0) {
			p->rect.left -= 8;
			p->rect.right -= 8;
			}
		break;
	case VK_RIGHT:
		if (p->rect.right <= (Crect.right - Crect.left)) {
			p->rect.right += 8;
			p->rect.left += 8;
		}
		break;
	case VK_UP:
		if (p->rect.top > 0) {
			p->rect.top -= 6;
			p->rect.bottom -= 6;
		}
		break;
	case VK_DOWN:
		if (p->rect.bottom <= (Crect.bottom - Crect.top)) {
			p->rect.top += 6;
			p->rect.bottom += 6;
		}
		break;
	case VK_HOME:
		if (p->rect.left>0&& p->rect.top>0) {
			p->rect.left -= 8;
			p->rect.top -= 6;
		}
		break;
	case VK_END:
		if (p->rect.right > p->rect.left&&p->rect.bottom > p->rect.top) {
			p->rect.left += 8;
			p->rect.top += 6;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCApplication303172View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication303172Doc* pdoc = GetDocument();
	pdoc->rect.left = pdoc->rect.right - pdoc->x;
	pdoc->rect.top = pdoc->rect.bottom - pdoc->y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication303172View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication303172Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	CPoint p;
	p = cr.CenterPoint();
	pDoc->rect = CRect(p.x - 100, p.y - 75, p.x + 100, p.y + 75);

	pDoc->x = pDoc->rect.right-pDoc->rect.left;
	pDoc->y = pDoc->rect.bottom-pDoc->rect.top;

	CClientDC dc(this);
	dc.Rectangle(pDoc->rect);

	CView::OnRButtonDown(nFlags, point);
}
