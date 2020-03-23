
// MFCApplication3-0317-2View.h : CMFCApplication303172View 类的接口
//

#pragma once


class CMFCApplication303172View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication303172View();
	DECLARE_DYNCREATE(CMFCApplication303172View)

// 特性
public:
	CMFCApplication303172Doc* GetDocument() const;
	
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
	virtual ~CMFCApplication303172View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication3-0317-2View.cpp 中的调试版本
inline CMFCApplication303172Doc* CMFCApplication303172View::GetDocument() const
   { return reinterpret_cast<CMFCApplication303172Doc*>(m_pDocument); }
#endif

