
// UsingLib-0428View.h : CUsingLib0428View 类的接口
//

#pragma once


class CUsingLib0428View : public CView
{
protected: // 仅从序列化创建
	CUsingLib0428View();
	DECLARE_DYNCREATE(CUsingLib0428View)

// 特性
public:
	CUsingLib0428Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CUsingLib0428View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UsingLib-0428View.cpp 中的调试版本
inline CUsingLib0428Doc* CUsingLib0428View::GetDocument() const
   { return reinterpret_cast<CUsingLib0428Doc*>(m_pDocument); }
#endif

