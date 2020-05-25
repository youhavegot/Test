
// UsingLib-0428View.cpp : CUsingLib0428View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UsingLib-0428.h"
#endif

#include "UsingLib-0428Doc.h"
#include "UsingLib-0428View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"w32.h"
#include"W32D.h"


// CUsingLib0428View

IMPLEMENT_DYNCREATE(CUsingLib0428View, CView)

BEGIN_MESSAGE_MAP(CUsingLib0428View, CView)
END_MESSAGE_MAP()

// CUsingLib0428View 构造/析构

CUsingLib0428View::CUsingLib0428View()
{
	// TODO: 在此处添加构造代码

}

CUsingLib0428View::~CUsingLib0428View()
{
}

BOOL CUsingLib0428View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsingLib0428View 绘制

void CUsingLib0428View::OnDraw(CDC* pDC)
{
	CUsingLib0428Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//静态链接库实例
	CString s1, s2; int a;
	s2 = CString(pchar());
	F1 f1;
	a = f1.GetA();
	s1.Format(_T("%d"), a);
	s1 = s1 +","+ s2;
	s2 = "静态链接库返回的数值和字符串为:";
	s1 = s2+s1;
	pDC->TextOutW(200, 200, s1);

	//动态链接库实例
	CString s3;
	s3.Format(_T("动态链接库返回的值为:%d"),GetInt());
	pDC->TextOutW(200, 250, s3);

	// TODO: 在此处为本机数据添加绘制代码
}


// CUsingLib0428View 诊断

#ifdef _DEBUG
void CUsingLib0428View::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLib0428View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLib0428Doc* CUsingLib0428View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLib0428Doc)));
	return (CUsingLib0428Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLib0428View 消息处理程序
