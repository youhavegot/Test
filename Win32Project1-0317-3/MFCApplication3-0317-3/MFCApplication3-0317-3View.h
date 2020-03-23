
// MFCApplication3-0317-3View.h : CMFCApplication303173View 类的接口
//

#pragma once


class CMFCApplication303173View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication303173View();
	DECLARE_DYNCREATE(CMFCApplication303173View)

// 特性
public:
	CMFCApplication303173Doc* GetDocument() const;
	BOOL con[99];
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
	virtual ~CMFCApplication303173View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // MFCApplication3-0317-3View.cpp 中的调试版本
inline CMFCApplication303173Doc* CMFCApplication303173View::GetDocument() const
   { return reinterpret_cast<CMFCApplication303173Doc*>(m_pDocument); }
#endif

