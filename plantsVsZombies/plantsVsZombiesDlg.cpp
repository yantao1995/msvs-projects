
// plantsVsZombiesDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "plantsVsZombies.h"
#include "plantsVsZombiesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_UPDATE_SUNSHINE WM_USER+100
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

CString showSunshine;
UINT MyThreadFunction(LPVOID pParam);
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


// CplantsVsZombiesDlg 对话框



CplantsVsZombiesDlg::CplantsVsZombiesDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLANTSVSZOMBIES_DIALOG, pParent)
	, sunshine_set(_T(""))
	, sunshine_show(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CplantsVsZombiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON1, sunshine_show);
	DDX_Text(pDX, IDC_EDIT2, sunshine_set);
	//  DDX_Text(pDX, IDC_EDIT3, sunshine_show);
	DDX_Text(pDX, IDC_EDIT3, sunshine_show);
}

BEGIN_MESSAGE_MAP(CplantsVsZombiesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CplantsVsZombiesDlg::OnBnClickedButton1)
	ON_WM_USERCHANGED()
	ON_MESSAGE(WM_UPDATE_SUNSHINE, &CplantsVsZombiesDlg::OnUpdateSunshine)
END_MESSAGE_MAP()


// CplantsVsZombiesDlg 消息处理程序

BOOL CplantsVsZombiesDlg::OnInitDialog()
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

void CplantsVsZombiesDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CplantsVsZombiesDlg::OnPaint()
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
	CWinThread* MyThread = AfxBeginThread(MyThreadFunction, NULL, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CplantsVsZombiesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

DWORD SunshineBaseAddreess = 0x00779618;
DWORD SunshineOffset1 = 0x868;
DWORD SunshineOffset2 = 0x5578;


BOOL IsIntNumber( CString str)
{
	char c;
	if (str.GetLength() > 10|| str.GetLength() == 0){
		return FALSE;
	}

	for (int i = 0; i < str.GetLength(); i++)
	{
		c = str.GetAt(i);
		if (c < '0' || c > '9')
		{
			return  FALSE;
		}
	}
}


void CplantsVsZombiesDlg::OnBnClickedButton1()
{

	CString setValStr  ;
	GetDlgItem(IDC_EDIT2)->GetWindowText(setValStr);
	if (!IsIntNumber(setValStr)) {
		::MessageBox(NULL, _T("只能输入1e10内整数"), _T("错误"), MB_OK);
		return;
	}

	HWND hwnd = ::FindWindow(_T("MainWindow"), _T("Plants vs. Zombies GOTY "));
	if (hwnd == NULL) {
		::MessageBox(NULL, _T("未找到游戏窗口"), _T("错误"), MB_OK);
		return;
	}

	DWORD pid;
	::GetWindowThreadProcessId(hwnd, &pid);

	HANDLE hprocess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hprocess == NULL) {
		::MessageBox(NULL, _T("打开进程失败"), _T("错误"), MB_OK);
		return;
	}

	DWORD baseAddr = 0x0;
	if (!::ReadProcessMemory(hprocess, (LPCVOID)SunshineBaseAddreess, &baseAddr, sizeof(baseAddr), NULL)) {
		::MessageBox(NULL, _T("读基址失败"), _T("错误"), MB_OK);
		return;
	}

	DWORD offset1Addr = 0x0;
	if (!::ReadProcessMemory(hprocess, (LPCVOID)(baseAddr + SunshineOffset1), &offset1Addr, sizeof(offset1Addr), NULL)) {
		::MessageBox(NULL, _T("读基址偏移1失败"), _T("错误"), MB_OK);
		return;
	}
	int numer = _ttoi(setValStr);
	if (!::WriteProcessMemory(hprocess, (void *)(offset1Addr + SunshineOffset2), &numer, sizeof(numer), NULL)) {
		::MessageBox(NULL, _T("写地址数据失败"), _T("错误"), MB_OK);
	}
}


void CplantsVsZombiesDlg::OnBnClickedButton2()
{
	

}


//CWinThread* MyThread = AfxBeginThread(MyThreadFunction, NULL, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
UINT MyThreadFunction(LPVOID pParam)
{
	//Sleep(1000);
	while (TRUE) {
		Sleep(500);
		HWND hwnd = ::FindWindow(_T("MainWindow"), _T("Plants vs. Zombies GOTY "));
		if (hwnd == NULL) {
			continue;
		}

		DWORD pid;
		::GetWindowThreadProcessId(hwnd, &pid);

		HANDLE hprocess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		if (hprocess == NULL) {
			continue;
		}

		DWORD baseAddr = 0x0;
		if (!::ReadProcessMemory(hprocess, (LPCVOID)SunshineBaseAddreess, &baseAddr, sizeof(baseAddr), NULL)) {
			continue;
		}

		DWORD offset1Addr = 0x0;
		if (!::ReadProcessMemory(hprocess, (LPCVOID)(baseAddr + SunshineOffset1), &offset1Addr, sizeof(offset1Addr), NULL)) {
			continue;
		}

		int sunshineCount;
		if (!::ReadProcessMemory(hprocess, (LPCVOID)(offset1Addr + SunshineOffset2), &sunshineCount, sizeof(sunshineCount), NULL)) {
			continue;
		}
		showSunshine.Format(_T("%d"), sunshineCount);

		HWND  thisHwnd = ::FindWindow(NULL, _T("植物大战僵尸辅助"));
		if (thisHwnd == NULL) {
			continue;
		}
		::SendMessage(thisHwnd,WM_UPDATE_SUNSHINE,NULL,NULL);
	};
}

void CplantsVsZombiesDlg::OnUserChanged()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnUserChanged();
}


afx_msg LRESULT CplantsVsZombiesDlg::OnUpdateSunshine(WPARAM wParam, LPARAM lParam)
{
	sunshine_show.SetString(showSunshine);
	GetDlgItem(IDC_EDIT3)->SetWindowText(showSunshine);
	return 0;
}
