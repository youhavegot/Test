
// DLG-0427-1-1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CDLG042711Dlg 对话框
class CDLG042711Dlg : public CDialogEx
{
// 构造
public:
	CDLG042711Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG042711_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString s;
	CListBox Lbox;
	afx_msg void OnEnChangeEdit2();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnLbnSelchangeList1();
};
