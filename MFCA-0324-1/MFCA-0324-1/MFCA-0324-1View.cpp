
// MFCA-0324-1View.cpp : CMFCA03241View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA-0324-1.h"
#endif

#include "MFCA-0324-1Doc.h"
#include "MFCA-0324-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA03241View

IMPLEMENT_DYNCREATE(CMFCA03241View, CView)

BEGIN_MESSAGE_MAP(CMFCA03241View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOW_01, &CMFCA03241View::OnShow01)
END_MESSAGE_MAP()

// CMFCA03241View 构造/析构

CMFCA03241View::CMFCA03241View()
{
	// TODO: 在此处添加构造代码

}

CMFCA03241View::~CMFCA03241View()
{
}

BOOL CMFCA03241View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA03241View 绘制

void CMFCA03241View::OnDraw(CDC* /*pDC*/)
{
	CMFCA03241Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA03241View 打印

BOOL CMFCA03241View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCA03241View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCA03241View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCA03241View 诊断

#ifdef _DEBUG
void CMFCA03241View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA03241View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA03241Doc* CMFCA03241View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA03241Doc)));
	return (CMFCA03241Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA03241View 消息处理程序


void CMFCA03241View::OnShow01()
{
	// TODO: 在此添加命令处理程序代码
	CString s = CString(_T("陈天德"));
	CClientDC dc(this);
	dc.TextOutW(30, 30, s);
}
