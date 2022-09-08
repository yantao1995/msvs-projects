#pragma once


// WineList 对话框

class WineList : public CDialogEx
{
	DECLARE_DYNAMIC(WineList)

public:
	WineList(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~WineList(); 

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINMINE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
