
// MFCA4-0323-0View.h : CMFCA403230View 类的接口
//

#pragma once


class CMFCA403230View : public CView
{
protected: // 仅从序列化创建
	CMFCA403230View();
	DECLARE_DYNCREATE(CMFCA403230View)

// 特性
public:
	CMFCA403230Doc* GetDocument() const;

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
	virtual ~CMFCA403230View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowround();
};

#ifndef _DEBUG  // MFCA4-0323-0View.cpp 中的调试版本
inline CMFCA403230Doc* CMFCA403230View::GetDocument() const
   { return reinterpret_cast<CMFCA403230Doc*>(m_pDocument); }
#endif

