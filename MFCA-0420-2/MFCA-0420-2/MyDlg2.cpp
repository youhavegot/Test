// MyDlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCA-0420-2.h"
#include "MyDlg2.h"
#include "afxdialogex.h"


// MyDlg2 对话框

IMPLEMENT_DYNAMIC(MyDlg2, CDialogEx)

MyDlg2::MyDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, r(0)
	, g(0)
	, b(0)
{

}

MyDlg2::~MyDlg2()
{
}

void MyDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r);
	DDV_MinMaxInt(pDX, r, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, g);
	DDV_MinMaxInt(pDX, g, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, b);
	DDV_MinMaxInt(pDX, b, 0, 255);
}


BEGIN_MESSAGE_MAP(MyDlg2, CDialogEx)
END_MESSAGE_MAP()


// MyDlg2 消息处理程序
