
// MFCApplication2(5)View.h : CMFCApplication25View 类的接口
//

#pragma once


class CMFCApplication25View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication25View();
	DECLARE_DYNCREATE(CMFCApplication25View)

// 特性
public:
	CMFCApplication25Doc* GetDocument() const;

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
	virtual ~CMFCApplication25View();
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
};

#ifndef _DEBUG  // MFCApplication2(5)View.cpp 中的调试版本
inline CMFCApplication25Doc* CMFCApplication25View::GetDocument() const
   { return reinterpret_cast<CMFCApplication25Doc*>(m_pDocument); }
#endif

