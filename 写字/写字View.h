
// 写字View.h: C写字View 类的接口
//

#pragma once


class C写字View : public CView
{
protected: // 仅从序列化创建
	C写字View() noexcept;
	DECLARE_DYNCREATE(C写字View)

// 特性
public:
	C写字Doc* GetDocument() const;

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
	virtual ~C写字View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_point;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CString str;
};

#ifndef _DEBUG  // 写字View.cpp 中的调试版本
inline C写字Doc* C写字View::GetDocument() const
   { return reinterpret_cast<C写字Doc*>(m_pDocument); }
#endif

