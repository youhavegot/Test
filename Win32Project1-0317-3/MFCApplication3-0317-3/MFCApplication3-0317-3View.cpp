
// MFCApplication3-0317-3View.cpp : CMFCApplication303173View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3-0317-3.h"
#endif

#include "MFCApplication3-0317-3Doc.h"
#include "MFCApplication3-0317-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication303173View

IMPLEMENT_DYNCREATE(CMFCApplication303173View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication303173View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
//	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCApplication303173View 构造/析构

CMFCApplication303173View::CMFCApplication303173View()
{
	// TODO: 在此处添加构造代码
	for (int i = 0; i < 99; i++)
		con[i] = false;
}

CMFCApplication303173View::~CMFCApplication303173View()
{
}

BOOL CMFCApplication303173View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication303173View 绘制

void CMFCApplication303173View::OnDraw(CDC* pDC)
{
	CMFCApplication303173Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < pDoc->n; i++)
		pDC->Ellipse(pDoc->ccr[i]);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication303173View 打印

BOOL CMFCApplication303173View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication303173View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication303173View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication303173View 诊断

#ifdef _DEBUG
void CMFCApplication303173View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication303173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication303173Doc* CMFCApplication303173View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication303173Doc)));
	return (CMFCApplication303173Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication303173View 消息处理程序


int CMFCApplication303173View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	for (int i = 0; i < 4; i++) {
		int t = rand() % 50;
		SetTimer(i, t, NULL);
		SetTimer(i + 4, t + 50, NULL);
	}
	// TODO:  在此添加您专用的创建代码

	return 0;
}


void CMFCApplication303173View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CMFCApplication303173Doc* pdoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	if ( con[i]==false &&i >= 0 && i <= 3) {
		pdoc->ccr[i].bottom += 5;
		pdoc->ccr[i].top +=5;
		if (pdoc->ccr[i].bottom >= cr.bottom) {
			KillTimer(i);
			con[i] = true;
		}
	}
	if (i>=4&&i<=7&&con[i-4] == true && pdoc->ccr[i - 4].top >= cr.top + 100) {
		pdoc->ccr[i - 4].bottom -= 5;
		pdoc->ccr[i - 4].top -= 5;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnTimer(nIDEvent);
}

