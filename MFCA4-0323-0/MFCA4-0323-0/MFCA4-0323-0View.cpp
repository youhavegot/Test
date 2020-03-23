
// MFCA4-0323-0View.cpp : CMFCA403230View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA4-0323-0.h"
#endif

#include "MFCA4-0323-0Doc.h"
#include "MFCA4-0323-0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA403230View

IMPLEMENT_DYNCREATE(CMFCA403230View, CView)

BEGIN_MESSAGE_MAP(CMFCA403230View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWROUND, &CMFCA403230View::OnShowround)
END_MESSAGE_MAP()

// CMFCA403230View 构造/析构

CMFCA403230View::CMFCA403230View()
{
	// TODO: 在此处添加构造代码

}

CMFCA403230View::~CMFCA403230View()
{
}

BOOL CMFCA403230View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA403230View 绘制

void CMFCA403230View::OnDraw(CDC* /*pDC*/)
{
	CMFCA403230Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA403230View 打印

BOOL CMFCA403230View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCA403230View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCA403230View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCA403230View 诊断

#ifdef _DEBUG
void CMFCA403230View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA403230View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA403230Doc* CMFCA403230View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA403230Doc)));
	return (CMFCA403230Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA403230View 消息处理程序


void CMFCA403230View::OnShowround()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CRect cr;
	GetClientRect(&cr);
	CPoint point;
	point = cr.CenterPoint();
	int r = 50, g = 0, b = 0;
	int x1 = point.x - 180, y1 = point.y - 180, x2 = point.x + 180, y2 = point.y + 180;
	CRect cr1,cr2;
	for (int i = 0; i < 30; i++) {
		CPen pen(PS_SOLID, 1, RGB(r, g, b));
		CPen *oldPen = dc.SelectObject(&pen);
		cr1=CRect(x1,y1,x2,y2);
		dc.Ellipse(cr1);
		x1 += 4;
		x2 -= 4;
		y1 += 4;
		y2 -= 4;
		r += 6;
		g += 1;
		b += 1;
	}

}
