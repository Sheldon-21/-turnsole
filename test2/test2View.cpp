
// test2View.cpp: Ctest2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test2.h"
#endif

#include "test2Doc.h"
#include "test2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest2View

IMPLEMENT_DYNCREATE(Ctest2View, CView)

BEGIN_MESSAGE_MAP(Ctest2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Ctest2View 构造/析构

Ctest2View::Ctest2View() noexcept
{
	// TODO: 在此处添加构造代码

}

Ctest2View::~Ctest2View()
{
}

BOOL Ctest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest2View 绘图

void Ctest2View::OnDraw(CDC* /*pDC*/)
{
	Ctest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest2View 打印

BOOL Ctest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ctest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ctest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Ctest2View 诊断

#ifdef _DEBUG
void Ctest2View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest2Doc* Ctest2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest2Doc)));
	return (Ctest2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest2View 消息处理程序
