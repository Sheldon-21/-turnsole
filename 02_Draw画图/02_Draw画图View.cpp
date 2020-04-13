
// 02_Draw画图View.cpp: CMy02Draw画图View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "02_Draw画图.h"
#endif

#include "02_Draw画图Doc.h"
#include "02_Draw画图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02Draw画图View

IMPLEMENT_DYNCREATE(CMy02Draw画图View, CView)

BEGIN_MESSAGE_MAP(CMy02Draw画图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy02Draw画图View 构造/析构

CMy02Draw画图View::CMy02Draw画图View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy02Draw画图View::~CMy02Draw画图View()
{

}

BOOL CMy02Draw画图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy02Draw画图View 绘图

void CMy02Draw画图View::OnDraw(CDC* /*pDC*/)
{
	CMy02Draw画图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy02Draw画图View 打印

BOOL CMy02Draw画图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy02Draw画图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy02Draw画图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy02Draw画图View 诊断

#ifdef _DEBUG
void CMy02Draw画图View::AssertValid() const
{
	CView::AssertValid();
}

void CMy02Draw画图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02Draw画图Doc* CMy02Draw画图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02Draw画图Doc)));
	return (CMy02Draw画图Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy02Draw画图View 消息处理程序


void CMy02Draw画图View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_myPoint = point;//保存点击的坐标

	m_isPress = true;

	CView::OnLButtonDown(nFlags, point);
}

//鼠标抬起
void CMy02Draw画图View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
#if 0

	//创建画家，指定绘图设备
	CClientDC dc(this);

	dc.MoveTo(m_myPoint);
	dc.LineTo(point);

#endif 

	m_isPress = false;


	CView::OnLButtonUp(nFlags, point);
}

//鼠标移动
void CMy02Draw画图View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	if (m_isPress == true)
	{
		//创建画家，指定绘画设备
		CClientDC dc(this);

		dc.MoveTo(m_myPoint);
		dc.LineTo(point);

		//终点作为起点
		m_myPoint = point;

	}
	CView::OnMouseMove(nFlags, point);
}
