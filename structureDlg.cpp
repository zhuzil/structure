
// structureDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "structure.h"
#include "structureDlg.h"
#include "afxdialogex.h"
#include<string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

mylist ls;
CRect rect;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CstructureDlg 对话框



CstructureDlg::CstructureDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STRUCTURE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CstructureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_CheckH, m_eidt);
	DDX_Control(pDX, IDC_SHOW, m_edit);
	DDX_Control(pDX, IDC_GetM, m_eidt);
	DDX_Control(pDX, IDC_GetN, n_eidt);
	DDX_Control(pDX, IDC_EDIT2, H_edit);
}

BEGIN_MESSAGE_MAP(CstructureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CreatData, &CstructureDlg::OnClickedCreatdata)
	ON_BN_CLICKED(IDC_QieGe, &CstructureDlg::OnClickedQiege)
	ON_BN_CLICKED(IDC_CheckH, &CstructureDlg::OnClickedCheckh)
	ON_BN_CLICKED(IDC_HuanYuan, &CstructureDlg::OnClickedHuanyuan)
	ON_BN_CLICKED(IDC_CheckXJ, &CstructureDlg::OnClickedCheckxj)
	ON_BN_CLICKED(IDOK, &CstructureDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CstructureDlg 消息处理程序

BOOL CstructureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CstructureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CstructureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	CClientDC dc(this);
	CWnd* p = (CStatic*)GetDlgItem(IDC_HATU);//静态文本框

	p->GetClientRect(&rect);

	p->ScreenToClient(&rect);
	GetDlgItem(IDC_HATU)->GetWindowRect(&rect);//获取控件的屏幕坐标
	ScreenToClient(&rect);//转换为对话框上的客户坐标

	CPen cPen;//创建画笔
	cPen.CreatePen(PS_SOLID, 2, RGB(0, 128, 0));
	dc.SelectObject(&cPen);

	if (ls.head != nullptr && ls.head2 == nullptr) {//先是单链表
		int dx = 35;
		int k = 1;
		node* tmp = ls.head;
		while (tmp != nullptr) {
			dc.SelectObject(cPen);
			CRect trect(rect.left + dx * k - 10, rect.top + 10 - 10, rect.left + dx * k + 10, rect.top + 10 + 10);
			k++;
			//画线
			if (tmp->next != nullptr) {
				dc.SelectObject(cPen);
				dc.MoveTo(trect.left + 10, trect.top + 10);
				dc.LineTo(trect.left + 10 + dx, trect.top + 10);
			}

			//画节点
			dc.Ellipse(&trect);
			CString str = CA2CT(to_string(tmp->val).c_str());
			dc.TextOut(trect.left + 20, trect.top + 20, str);

			tmp = tmp->next;

		}
	}
	else if (ls.head != nullptr && ls.head2 != nullptr) 
	{	//有环后
		node* rk = ls.tail2->next;

		int dx = 40;
		int k = 1;
		node* tmp = ls.head;
		//先画上面
		while (tmp != rk) {
			dc.SelectObject(cPen);
			CRect trect(rect.left + dx * k - 10, rect.top + 10 - 10, rect.left + dx * k + 10, rect.top + 10 + 10);
			k++;
			//画线
			if (tmp->next != rk) {
				dc.SelectObject(cPen);
				dc.MoveTo(trect.left + 10, trect.top + 10);
				dc.LineTo(trect.left + 10 + dx, trect.top + 10);
			}

			//画节点
			dc.Ellipse(&trect);
			CString str = CA2CT(to_string(tmp->val).c_str());
			dc.TextOut(trect.left + 20, trect.top + 20, str);

			tmp = tmp->next;

		}
		//再画下面
		tmp = ls.head2;
		int k2 = 1;//分两个k，到时候画相交结点好画一点
		while (tmp!= rk) {
			dc.SelectObject(cPen);
			CRect trect(rect.left + dx * k2 - 10, rect.top + 110 - 10, rect.left + dx * k2 + 10, rect.top + 110 + 10);
			k2++;
			//画线
			if (tmp->next != rk) {
				dc.SelectObject(cPen);
				dc.MoveTo(trect.left + 10, trect.top + 10);
				dc.LineTo(trect.left + 10 + dx, trect.top + 10);
			}

			//画节点
			dc.Ellipse(&trect);
			CString str = CA2CT(to_string(tmp->val).c_str());
			dc.TextOut(trect.left + 20, trect.top + 20, str);

			tmp = tmp->next;

		}
		//先画从两个尾部到入口的线
		k--; k2--;
		int k3 = max(k, k2);

		CRect trect(rect.left + dx * k - 10, rect.top + 10 - 10, rect.left + dx * k + 10, rect.top + 10 + 10);
		CRect trect_2(rect.left + dx * k2 - 10, rect.top + 110 - 10, rect.left + dx * k2 + 10, rect.top + 110 + 10);
		CRect trect_3(rect.left + dx * k3 - 10, rect.top + 60 - 10, rect.left + dx * k3 + 10, rect.top + 60 + 10);
		if (rk != ls.head) {
			dc.SelectObject(cPen);
			dc.MoveTo(trect.left + 10, trect.top + 10);
			dc.LineTo(trect_3.left + 10 + dx, trect_3.top + 10);

		}

		dc.SelectObject(cPen);
		dc.MoveTo(trect_2.left + 10, trect_2.top + 10);
		dc.LineTo(trect_3.left + 10 + dx, trect_3.top + 10);

		


		//画相交结点
		int tag = 0;//标记是否是第二次到达入口处
		k3++;
		tmp = rk;
		while (tmp != rk||tag==0) {
			dc.SelectObject(cPen);
			CRect trect(rect.left + dx * k3 - 10, rect.top + 60 - 10, rect.left + dx * k3 + 10, rect.top + 60 + 10);
			k3++;
			//画线
			if (tmp->next != rk||tag==0) {
				dc.SelectObject(cPen);
				dc.MoveTo(trect.left + 10, trect.top + 10);
				dc.LineTo(trect.left + 10 + dx, trect.top + 10);
			}

			//画节点
			dc.Ellipse(&trect);
			CString str = CA2CT(to_string(tmp->val).c_str());
			dc.TextOut(trect.left + 20, trect.top + 20, str);

			tmp = tmp->next;
			tag = 1;
		}

		//再从最后一个画个线到前面
		k3--;
		int k4 = max(k, k2)+1;
		//从k3画到k4
		CRect trect_k3(rect.left + dx * k3 - 10, rect.top + 60 - 10, rect.left + dx * k3 + 10, rect.top + 60 + 10);
		CRect trect_k4(rect.left + dx * k4 - 10, rect.top + 60 - 10, rect.left + dx * k4 + 10, rect.top + 60 + 10);
		dc.SelectObject(cPen);
		dc.MoveTo(trect_k3.left + 10, trect_k3.top + 10);
		dc.LineTo(trect_k3.left + 10, trect_k3.top + 50);
		
		dc.MoveTo(trect_k3.left + 10, trect_k3.top + 50);
		dc.LineTo(trect_k4.left + 10, trect_k4.top + 50);

		dc.MoveTo(trect_k4.left + 10, trect_k4.top + 50);
		dc.LineTo(trect_k4.left + 10, trect_k4.top + 10);
	}

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CstructureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CstructureDlg::OnClickedCreatdata()
{
	// TODO: 在此添加控件通知处理程序代码
	srand(time(0));
	int A[15] = { 0 };
	for (int i = 0; i < 15; i++) {
		int Same = 1;
		A[i] = rand() / (double)(200);
		while (Same) {//直到没有重复数字才结束循环
			Same = 0;
			for (int j = 0; j < i; j++) {
				if (A[i] == A[j]) {
					Same = 1;//表示有重复数字，需要重新生成随机数
					A[i] = rand() / (double)(200);
					break;
				}
			}
		}
	}

	for (int i = 0; i < 15; i++) {
		ls.insert(A[i]);
	}

	if (ls.size == 15) {
		MessageBox(_T("生成成功！"), _T("链表"), MB_OK);
		string out = "";
		for (int i = 0; i < 15; i++) {
			out += to_string(A[i]);
			out += " ";
			if ((i+1) % 20 == 0)out += "\r\n";
		}
		CString wout = CA2CT(out.c_str());
		m_edit.SetWindowTextW(wout);
	}
	else {
		MessageBox(_T("生成失败！"), _T("链表"), MB_OK);
		ls.de_list(ls.head);
	}
	InvalidateRect(rect);//刷新 
	OnPaint();
	return;
}


void CstructureDlg::OnClickedQiege()
{
	// TODO: 在此添加控件通知处理程序代码
	if (ls.size != 15) {
		MessageBox(_T("请生成数据！"), _T("链表"), MB_OK);
		return;
	}
	CString str1;
	m_eidt.GetWindowText(str1);
	CString str2;
	n_eidt.GetWindowText(str2);

	string sm = CT2CA(str1);
	string sn = CT2CA(str2);

	int m = atoi(sm.c_str());
	int n = atoi(sn.c_str());

	if (ls.split(m, n)) {
		InvalidateRect(rect);//刷新 
		OnPaint();
		MessageBox(_T("切割成功！"), _T("链表"), MB_OK);
	}
	else {
		MessageBox(_T("切割失败！"), _T("链表"), MB_OK);
	}
	
	return;
}


void CstructureDlg::OnClickedCheckh()
{
	// TODO: 在此添加控件通知处理程序代码
	if (ls.size != 15) {
		MessageBox(_T("请生成数据！"), _T("链表"), MB_OK);
		return;
	}
	else if (ls.head2 == nullptr) {
		MessageBox(_T("无环！"), _T("链表"), MB_OK);
		return;
	}

	CString str1;
	H_edit.GetWindowText(str1);
	string h = CT2CA(str1);
	int hh = atoi(h.c_str());

	node* tmp;
	if (hh == 0) {
		tmp=ls.ishuan(ls.head);
	}
	else if (hh == 1) {
		tmp=ls.ishuan(ls.head2);
	}
	else {
		MessageBox(_T("请输入正确的数！"), _T("链表"), MB_OK);
		return;
	}

	if (tmp == nullptr) {
		MessageBox(_T("无环"), _T("链表"), MB_OK);
	}
	else {
		string out = "有环,m=";
		int n = tmp->val;
		int m = tmp->next->val;
		out += to_string(m);
		out += ",n=" + to_string(n);
		CString wout = CA2CT(out.c_str());
		MessageBox((wout), _T("链表"), MB_OK);
	}
	InvalidateRect(rect);//刷新 
	OnPaint();
}


void CstructureDlg::OnClickedHuanyuan()
{
	// TODO: 在此添加控件通知处理程序代码
	if (ls.size != 15) {
		MessageBox(_T("请生成数据！"), _T("链表"), MB_OK);
		return;
	}
	else if (ls.head2 == nullptr) {
		MessageBox(_T("请先切割！"), _T("链表"), MB_OK);
		return;
	}

	node* tmp = ls.huanyuan();

	if (tmp != nullptr) {
		InvalidateRect(rect);//刷新 
		OnPaint();
		string out = "还原成功，中间节点值为:";
		out += to_string(tmp->val);
		CString wout = CA2CT(out.c_str());
		MessageBox((wout), _T("链表"), MB_OK);
	}
	else {
		MessageBox(_T("还原失败！"), _T("链表"), MB_OK);
	}

}


void CstructureDlg::OnClickedCheckxj()
{
	// TODO: 在此添加控件通知处理程序代码
	if (ls.size != 15) {
		MessageBox(_T("请生成数据！"), _T("链表"), MB_OK);
		return;
	}

	node* tmp = ls.checkxj(ls.head, ls.head2);

	if (tmp != nullptr) {
		string out = "有相交节点，值为：";
		out += to_string(tmp->val);
		CString wout = CA2CT(out.c_str());
		MessageBox((wout), _T("链表"), MB_OK);
	}
	else {
		MessageBox(_T("无相交节点！"), _T("链表"), MB_OK);
		return;
	}
}

void CstructureDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ls.huanyuan();
	CDialogEx::OnOK();
}
