
// MFCApplication3-0316View.h : CMFCApplication30316View 类的接口
//

#pragma once


class CMFCApplication30316View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication30316View();
	DECLARE_DYNCREATE(CMFCApplication30316View)

// 特性
public:
	CMFCApplication30316Doc* GetDocument() const;

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
	virtual ~CMFCApplication30316View();
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
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication3-0316View.cpp 中的调试版本
inline CMFCApplication30316Doc* CMFCApplication30316View::GetDocument() const
   { return reinterpret_cast<CMFCApplication30316Doc*>(m_pDocument); }
#endif

