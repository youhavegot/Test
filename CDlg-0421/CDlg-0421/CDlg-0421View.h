
// CDlg-0421View.h : CCDlg0421View 类的接口
//

#pragma once


class CCDlg0421View : public CView
{
protected: // 仅从序列化创建
	CCDlg0421View();
	DECLARE_DYNCREATE(CCDlg0421View)

// 特性
public:
	CCDlg0421Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCDlg0421View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	afx_msg void On32771();
};

#ifndef _DEBUG  // CDlg-0421View.cpp 中的调试版本
inline CCDlg0421Doc* CCDlg0421View::GetDocument() const
   { return reinterpret_cast<CCDlg0421Doc*>(m_pDocument); }
#endif

