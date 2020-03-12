
// MFCApplication2(3)View.h : CMFCApplication23View 类的接口
//

#pragma once


class CMFCApplication23View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication23View();
	DECLARE_DYNCREATE(CMFCApplication23View)

// 特性
public:
	CMFCApplication23Doc* GetDocument() const;

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
	virtual ~CMFCApplication23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication2(3)View.cpp 中的调试版本
inline CMFCApplication23Doc* CMFCApplication23View::GetDocument() const
   { return reinterpret_cast<CMFCApplication23Doc*>(m_pDocument); }
#endif

