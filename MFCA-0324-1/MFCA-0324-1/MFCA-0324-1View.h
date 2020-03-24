
// MFCA-0324-1View.h : CMFCA03241View 类的接口
//

#pragma once


class CMFCA03241View : public CView
{
protected: // 仅从序列化创建
	CMFCA03241View();
	DECLARE_DYNCREATE(CMFCA03241View)

// 特性
public:
	CMFCA03241Doc* GetDocument() const;

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
	virtual ~CMFCA03241View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShow01();
};

#ifndef _DEBUG  // MFCA-0324-1View.cpp 中的调试版本
inline CMFCA03241Doc* CMFCA03241View::GetDocument() const
   { return reinterpret_cast<CMFCA03241Doc*>(m_pDocument); }
#endif

