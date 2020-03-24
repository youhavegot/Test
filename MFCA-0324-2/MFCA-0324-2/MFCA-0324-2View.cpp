
// MFCA-0324-2View.cpp : CMFCA03242View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA-0324-2.h"
#endif

#include "MFCA-0324-2Doc.h"
#include "MFCA-0324-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA03242View

IMPLEMENT_DYNCREATE(CMFCA03242View, CView)

BEGIN_MESSAGE_MAP(CMFCA03242View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCA03242View 构造/析构

CMFCA03242View::CMFCA03242View()
{
	// TODO: 在此处添加构造代码
	BITMAP bm;
	BM1.LoadBitmap(IDB_BM1);
	BM1.GetBitmap(&bm);
	BM1_Width = bm.bmWidth;
	BM1_Height = bm.bmHeight;
}

CMFCA03242View::~CMFCA03242View()
{
}

BOOL CMFCA03242View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA03242View 绘制

void CMFCA03242View::OnDraw(CDC* pDC)
{
	CMFCA03242Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(BM1);
	pDC->BitBlt(0, 0, BM1_Width, BM1_Height, &MemDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA03242View 打印

BOOL CMFCA03242View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCA03242View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCA03242View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCA03242View 诊断

#ifdef _DEBUG
void CMFCA03242View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA03242View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA03242Doc* CMFCA03242View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA03242Doc)));
	return (CMFCA03242Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA03242View 消息处理程序
