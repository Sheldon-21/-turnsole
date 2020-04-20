
// 写字View.cpp: C写字View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "写字.h"
#endif

#include "写字Doc.h"
#include "写字View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C写字View

IMPLEMENT_DYNCREATE(C写字View, CView)

BEGIN_MESSAGE_MAP(C写字View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C写字View 构造/析构

C写字View::C写字View() noexcept
{
	// TODO: 在此处添加构造代码

}

C写字View::~C写字View()
{
}

BOOL C写字View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C写字View 绘图

void C写字View::OnDraw(CDC* /*pDC*/)
{
	C写字Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C写字View 打印

BOOL C写字View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C写字View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C写字View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C写字View 诊断

#ifdef _DEBUG
void C写字View::AssertValid() const
{
	CView::AssertValid();
}

void C写字View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C写字Doc* C写字View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C写字Doc)));
	return (C写字Doc*)m_pDocument;
}
#endif //_DEBUG


// C写字View 消息处理程序


//窗口创建后自动调用
int C写字View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//获取字体信息
	CClientDC dc(this);

	TEXTMETRIC tm;//字体信息结构体
	dc.GetTextMetrics(&tm);

	

	//继承与 CWnd
	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight); //创建插入符

	ShowCaret();//显示

	return 0;
}


void C写字View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	SetCaretPos(point);//让插入符和鼠标点击的位置移动

	//保存点击坐标
	m_point = point;

	str = TEXT("");
	str.Empty();


	CView::OnLButtonDown(nFlags, point);
}


//点击键盘自动调用
void C写字View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	str += (TCHAR)nChar;

	CClientDC dc(this);

	dc.TextOutW(m_point.x, m_point.y, str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
