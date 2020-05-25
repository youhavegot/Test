
// MFCA-0420-2View.h : CMFCA04202View 类的接口
//

#pragma once


class CMFCA04202View : public CView
{
protected: // 仅从序列化创建
	CMFCA04202View();
	DECLARE_DYNCREATE(CMFCA04202View)

// 特性
public:
	CMFCA04202Doc* GetDocument() const;

// 操作
public:
	BOOL set = false; CRect cr; 
	BOOL rset = false; CPoint rp;
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
	virtual ~CMFCA04202View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDe();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void On32773();
};

#ifndef _DEBUG  // MFCA-0420-2View.cpp 中的调试版本
inline CMFCA04202Doc* CMFCA04202View::GetDocument() const
   { return reinterpret_cast<CMFCA04202Doc*>(m_pDocument); }
#endif

