
// plantsVsZombiesDlg.h: 头文件
//

#pragma once


// CplantsVsZombiesDlg 对话框
class CplantsVsZombiesDlg : public CDialogEx
{
// 构造
public:
	CplantsVsZombiesDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLANTSVSZOMBIES_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString sunshine_set;
	afx_msg void OnBnClickedButton1();
	CString sunshine_show;
	afx_msg void OnUserChanged();
protected:
	afx_msg LRESULT OnUpdateSunshine(WPARAM wParam, LPARAM lParam);
public:
	CString gold_show;
	CString gold_set;
protected:
	afx_msg LRESULT OnUpdateGold(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck1();
	BOOL m_check_box;
};
