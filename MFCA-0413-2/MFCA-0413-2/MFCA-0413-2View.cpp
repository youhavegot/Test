
// MFCA-0413-2View.cpp : CMFCA04132View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA-0413-2.h"
#endif

#include "MFCA-0413-2Doc.h"
#include "MFCA-0413-2View.h"
#include "ADD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA04132View

IMPLEMENT_DYNCREATE(CMFCA04132View, CView)

BEGIN_MESSAGE_MAP(CMFCA04132View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_POPOUT, &CMFCA04132View::OnPopout)
END_MESSAGE_MAP()

// CMFCA04132View 构造/析构

CMFCA04132View::CMFCA04132View()
{
	// TODO: 在此处添加构造代码

}

CMFCA04132View::~CMFCA04132View()
{
}

BOOL CMFCA04132View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA04132View 绘制

void CMFCA04132View::OnDraw(CDC* /*pDC*/)
{
	CMFCA04132Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA04132View 打印

BOOL CMFCA04132View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCA04132View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCA04132View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCA04132View 诊断

#ifdef _DEBUG
void CMFCA04132View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA04132View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA04132Doc* CMFCA04132View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA04132Doc)));
	return (CMFCA04132Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA04132View 消息处理程序


void CMFCA04132View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	ADD dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {

	}
}
