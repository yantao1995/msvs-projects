
// winmineDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "winmine.h"
#include "winmineDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CwinmineDlg 对话框



CwinmineDlg::CwinmineDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WINMINE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CwinmineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_controller);
}

BEGIN_MESSAGE_MAP(CwinmineDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CwinmineDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CwinmineDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CwinmineDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CwinmineDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CwinmineDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CwinmineDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CwinmineDlg 消息处理程序

BOOL CwinmineDlg::OnInitDialog()
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

void CwinmineDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CwinmineDlg::OnPaint()
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
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CwinmineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CwinmineDlg::OnBnClickedButton1()
{
	HWND hwnd = ::FindWindow(NULL, _T("扫雷"));
	if (hwnd == NULL) {
		::MessageBox(NULL, _T("扫雷窗口未运行"), _T("错误"), MB_OK);
		return;
	}
	::SendMessage(hwnd, WM_COMMAND, 0x209, NULL);
}


void CwinmineDlg::OnBnClickedButton2()
{
	HWND hwnd = ::FindWindow(NULL, _T("扫雷"));
	if (hwnd == NULL) {
		::MessageBox(NULL, _T("扫雷窗口未运行"), _T("错误"), MB_OK);
		return;
	}
	::SendMessage(hwnd, WM_COMMAND, 0x20A, NULL);
}


void CwinmineDlg::OnBnClickedButton3()
{
	HWND hwnd = ::FindWindow(NULL, _T("扫雷"));
	if (hwnd == NULL) {
		::MessageBox(NULL, _T("扫雷窗口未运行"), _T("错误"), MB_OK);
		return;
	}
	::SendMessage(hwnd, WM_COMMAND, 0x20B, NULL);
}


void CwinmineDlg::OnBnClickedButton4()
{
	HWND hwnd = ::FindWindow(NULL, _T("扫雷"));
	if (hwnd == NULL) {
		::MessageBox(NULL, _T("扫雷窗口未运行"), _T("错误"), MB_OK);
		return;
	}
	DWORD pid = NULL;
	::GetWindowThreadProcessId(hwnd, (LPDWORD)&pid);

	HANDLE  hp = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hp == NULL) {
		::MessageBox(NULL, _T("打开进程失败"), _T("错误"), MB_OK);
		return;
	}

	unsigned char mem[24][32] = { 0 };
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005361, &mem, SIZE_T(sizeof(mem)), NULL)) {
		::MessageBox(NULL, _T("读取雷区失败"), _T("错误"), MB_OK);
		return;
	}

	int memHeight = 0;
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005338, &memHeight, SIZE_T(sizeof(memHeight)), NULL)) {
		::MessageBox(NULL, _T("读取雷区高度失败"), _T("错误"), MB_OK);
		return;
	}

	int memWidth = 0;
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005334, &memWidth, SIZE_T(sizeof(memWidth)), NULL)) {
		::MessageBox(NULL, _T("读取雷区宽度失败"), _T("错误"), MB_OK);
		return;
	}
	m_list_controller.DeleteAllItems();
	for (int i = 1; i <= 32; i++) {
		m_list_controller.DeleteColumn(0);
	}
	m_list_controller.SetExtendedStyle(LVS_EX_GRIDLINES);
	CString mineStr = _T("");
	mineStr.Format(_T("%d"), 0);
	m_list_controller.InsertColumn(0, mineStr, LVCFMT_LEFT, 26);
	for (int i = 0; i < memWidth; i++) {
		mineStr.Format(_T("%d"), i + 1);
		m_list_controller.InsertColumn(i + 1, mineStr, LVCFMT_LEFT, 26);
	}	

	for (int i = 0; i < memHeight; i++) {
		mineStr.Format(_T("%d"), i + 1);
		m_list_controller.InsertItem(i ,mineStr, 0);
		for (int j = 0; j < memWidth; j++) {
			if (mem[i][j] == 0x8F || mem[i][j] == 0x8E){
			mineStr.Format(_T("x"));
			m_list_controller.SetItemText(i , j+1 , mineStr);
			}		
		}
	}
}


void CwinmineDlg::OnBnClickedButton5()
{
	HWND hwnd = ::FindWindow(NULL, _T("扫雷"));
	if (hwnd == NULL) {
		::MessageBox(NULL, _T("扫雷窗口未运行"), _T("错误"), MB_OK);
		return;
	}
	DWORD pid = NULL;
	::GetWindowThreadProcessId(hwnd, (LPDWORD)&pid);

	HANDLE  hp = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hp == NULL) {
		::MessageBox(NULL, _T("打开进程失败"), _T("错误"), MB_OK);
		return;
	}

	unsigned char mem[24][32] = { 0 };
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005361, &mem, SIZE_T(sizeof(mem)), NULL)) {
		::MessageBox(NULL, _T("读取雷区失败"), _T("错误"), MB_OK);
		return;
	}

	int memHeight = 0;
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005338, &memHeight, SIZE_T(sizeof(memHeight)), NULL)) {
		::MessageBox(NULL, _T("读取雷区高度失败"), _T("错误"), MB_OK);
		return;
	}

	int memWidth = 0;
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005334, &memWidth, SIZE_T(sizeof(memWidth)), NULL)) {
		::MessageBox(NULL, _T("读取雷区宽度失败"), _T("错误"), MB_OK);
		return;
	}

	int baseX,x, baseY,y;
	baseX = 19;
	baseY = 64;
	for (int i = 0; i < memHeight; i++) {
		for (int j = 0; j < memWidth; j++) {
			if (mem[i][j] != 0x8F){
				x = baseX + 16 * j;
				y = baseY + 16 * i;
				::SendMessage(hwnd, WM_LBUTTONDOWN, 0, (y << 16) | x);
				::SendMessage(hwnd, WM_LBUTTONUP, 0, (y << 16) | x);
			}			
		}
	}
}


void CwinmineDlg::OnBnClickedButton6()
{
	HWND hwnd = ::FindWindow(NULL, _T("扫雷"));
	if (hwnd == NULL) {
		::MessageBox(NULL, _T("扫雷窗口未运行"), _T("错误"), MB_OK);
		return;
	}
	DWORD pid = NULL;
	::GetWindowThreadProcessId(hwnd, (LPDWORD)&pid);

	HANDLE  hp = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hp == NULL) {
		::MessageBox(NULL, _T("打开进程失败"), _T("错误"), MB_OK);
		return;
	}

	unsigned char mem[24][32] = { 0 };
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005361, &mem, SIZE_T(sizeof(mem)), NULL)) {
		::MessageBox(NULL, _T("读取雷区失败"), _T("错误"), MB_OK);
		return;
	}

	int memHeight = 0;
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005338, &memHeight, SIZE_T(sizeof(memHeight)), NULL)) {
		::MessageBox(NULL, _T("读取雷区高度失败"), _T("错误"), MB_OK);
		return;
	}

	int memWidth = 0;
	if (!ReadProcessMemory(hp, (LPCVOID)0x01005334, &memWidth, SIZE_T(sizeof(memWidth)), NULL)) {
		::MessageBox(NULL, _T("读取雷区宽度失败"), _T("错误"), MB_OK);
		return;
	}

	int baseX, x, baseY, y;
	baseX = 19;
	baseY = 64;
	for (int i = 0; i < memHeight; i++) {
		for (int j = 0; j < memWidth; j++) {
			if (mem[i][j] == 0x8F) {
				x = baseX + 16 * j;
				y = baseY + 16 * i;
				::SendMessage(hwnd, WM_RBUTTONDOWN, 0, (y << 16) | x);
				::SendMessage(hwnd, WM_RBUTTONUP, 0, (y << 16) | x);
			}
		}
	}
}
