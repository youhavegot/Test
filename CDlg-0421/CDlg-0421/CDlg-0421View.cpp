
// CDlg-0421View.cpp : CCDlg0421View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CDlg-0421.h"
#endif

#include "CDlg-0421Doc.h"
#include "CDlg-0421View.h"
#include<fstream>
#include<iostream>
#include<string>
#include "MyDlg.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCDlg0421View

IMPLEMENT_DYNCREATE(CCDlg0421View, CView)

BEGIN_MESSAGE_MAP(CCDlg0421View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CCDlg0421View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CCDlg0421View::OnFileSaveAs)
	ON_COMMAND(ID_32771, &CCDlg0421View::On32771)
END_MESSAGE_MAP()

// CCDlg0421View 构造/析构

CCDlg0421View::CCDlg0421View()
{
	// TODO: 在此处添加构造代码

}

CCDlg0421View::~CCDlg0421View()
{
}

BOOL CCDlg0421View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCDlg0421View 绘制

void CCDlg0421View::OnDraw(CDC* /*pDC*/)
{
	CCDlg0421Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CCDlg0421View 打印

BOOL CCDlg0421View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCDlg0421View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCDlg0421View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCDlg0421View 诊断

#ifdef _DEBUG
void CCDlg0421View::AssertValid() const
{
	CView::AssertValid();
}

void CCDlg0421View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCDlg0421Doc* CCDlg0421View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCDlg0421Doc)));
	return (CCDlg0421Doc*)m_pDocument;
}
#endif //_DEBUG


// CCDlg0421View 消息处理程序


void CCDlg0421View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CCDlg0421Doc* pd = GetDocument();
	CFileDialog cfd(true);
	if (cfd.DoModal() == IDOK) {
		pd->filename = cfd.GetPathName();
	}
	CClientDC dc(this);

}


void CCDlg0421View::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(false);
	CCDlg0421Doc* pd = GetDocument();
	if (cfd.DoModal() == IDOK) {
		ofstream ofs(cfd.GetPathName());
		ofs << CT2A(pd->filename.GetString());
	}
}


void CCDlg0421View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	if (dlg.DoModal() == IDOK) {

	}
}
