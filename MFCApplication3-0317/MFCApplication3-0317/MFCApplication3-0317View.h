
// MFCApplication3-0317View.h : CMFCApplication30317View 类的接口
//

#pragma once


class CMFCApplication30317View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication30317View();
	DECLARE_DYNCREATE(CMFCApplication30317View)

// 特性
public:
	CMFCApplication30317Doc* GetDocument() const;
	int n;
	int sn=0;
	CPoint p1, p2;
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
	virtual ~CMFCApplication30317View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication3-0317View.cpp 中的调试版本
inline CMFCApplication30317Doc* CMFCApplication30317View::GetDocument() const
   { return reinterpret_cast<CMFCApplication30317Doc*>(m_pDocument); }
#endif

