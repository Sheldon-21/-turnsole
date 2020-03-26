
// 矩形View.cpp: C矩形View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "矩形.h"
#endif

#include "矩形Doc.h"
#include "矩形View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C矩形View

IMPLEMENT_DYNCREATE(C矩形View, CView)

BEGIN_MESSAGE_MAP(C矩形View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C矩形View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C矩形View 构造/析构

C矩形View::C矩形View() noexcept
{
	// TODO: 在此处添加构造代码

}

C矩形View::~C矩形View()
{
}

BOOL C矩形View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C矩形View 绘图

void C矩形View::OnDraw(CDC* pDC)
{
	C矩形Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect(30, 30, 300, 300);//规定矩形的位置，左上角的坐标和右下角的坐标
	pDC->Rectangle(&rect);//形参
}


// C矩形View 打印


void C矩形View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C矩形View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C矩形View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C矩形View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C矩形View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C矩形View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C矩形View 诊断

#ifdef _DEBUG
void C矩形View::AssertValid() const
{
	CView::AssertValid();
}

void C矩形View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C矩形Doc* C矩形View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C矩形Doc)));
	return (C矩形Doc*)m_pDocument;
}
#endif //_DEBUG


// C矩形View 消息处理程序
