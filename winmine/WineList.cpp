// WineList.cpp: 实现文件
//

#include "pch.h"
#include "winmine.h"
#include "WineList.h"
#include "afxdialogex.h"


// WineList 对话框

IMPLEMENT_DYNAMIC(WineList, CDialogEx)

WineList::WineList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WINMINE_DIALOG, pParent)
{
	
}

WineList::~WineList()
{

}

void WineList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WineList, CDialogEx)
END_MESSAGE_MAP()


// WineList 消息处理程序
