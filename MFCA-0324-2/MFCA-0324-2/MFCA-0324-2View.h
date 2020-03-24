
// MFCA-0324-2View.h : CMFCA03242View 类的接口
//

#pragma once


class CMFCA03242View : public CView
{
protected: // 仅从序列化创建
	CMFCA03242View();
	DECLARE_DYNCREATE(CMFCA03242View)

// 特性
public:
	CMFCA03242Doc* GetDocument() const;
	
// 操作
public:
	CBitmap BM1;
	int BM1_Width, BM1_Height;
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
	virtual ~CMFCA03242View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCA-0324-2View.cpp 中的调试版本
inline CMFCA03242Doc* CMFCA03242View::GetDocument() const
   { return reinterpret_cast<CMFCA03242Doc*>(m_pDocument); }
#endif

