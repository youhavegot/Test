
// MFCA-0324-3View.h : CMFCA03243View 类的接口
//

#pragma once


class CMFCA03243View : public CView
{
protected: // 仅从序列化创建
	CMFCA03243View();
	DECLARE_DYNCREATE(CMFCA03243View)

// 特性
public:
	CMFCA03243Doc* GetDocument() const;

// 操作
public:
	BOOL set[3]; int n = 3;
	CPoint point1, point2;
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
	virtual ~CMFCA03243View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawli();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawre();
	afx_msg void OnDrawro();
};

#ifndef _DEBUG  // MFCA-0324-3View.cpp 中的调试版本
inline CMFCA03243Doc* CMFCA03243View::GetDocument() const
   { return reinterpret_cast<CMFCA03243Doc*>(m_pDocument); }
#endif

