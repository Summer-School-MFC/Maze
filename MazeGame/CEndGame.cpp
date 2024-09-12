// CEndGame.cpp
#include "pch.h"
#include "MazeGame.h"
#include "afxdialogex.h"
#include "framework.h"
#include "CEndGame.h"
#include "CImagingDlg.h"
#include<fstream>
#include<string>
#include<iostream>


using namespace std;

// CEndGame 对话框
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CEndGame, CDialogEx)
    ON_BN_CLICKED(IDC_EXITEND, &CEndGame::OnBnClickedExitEnd) // 添加按钮点击事件映射
    ON_EN_CHANGE(IDC_SCOREDIT, &CEndGame::OnEnChangeScoredit)
    ON_BN_CLICKED(IDC_HISTORY, &CEndGame::OnBnClickedHistory) // 添加按钮点击事件映射
    ON_EN_CHANGE(IDC_SCOREBEST, &CEndGame::OnEnChangeScorebest)
    ON_BN_CLICKED(IDC_PLAYBACK_BUTTON, &CEndGame::OnBnClickedPlaybackButton)
END_MESSAGE_MAP()

IMPLEMENT_DYNAMIC(CEndGame, CDialogEx)

CEndGame::CEndGame(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDC_ENDGAME, pParent)
{
}

CEndGame::~CEndGame()
{
}

void CEndGame::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_SCOREDIT, m_time); // 绑定 IDC_SCOREDIT 控件
}

BOOL CEndGame::OnInitDialog()
{
    CDialogEx::OnInitDialog();


    // 其他初始化代码...

    LoadTimeRecords(); // 加载时间记录
    UpdateScoreEdit();
    UpdateScoreBest();
    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEndGame::OnBnClickedExitEnd()
{
    EndDialog(IDOK); // 关闭对话框
}

void CEndGame::OnBnClickedHistory()
{
    // 使用 ShellExecute 函数打开文本文件
    ShellExecute(NULL, _T("open"), _T("TimeRecords.txt"), NULL, NULL, SW_SHOWNORMAL);
}


void CEndGame::OnEnChangeScoredit()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}


void CEndGame::OnEnChangeScorebest()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}

void CEndGame::LoadTimeRecords()
{
    ifstream ifs("TimeRecords.txt");
    if (!ifs.is_open())
    {
        MessageBox(_T("文件打开失败"));
        return;
    }

    string line;
    while (getline(ifs, line))
    {
        m_timeRecordsVector.push_back(CString(line.c_str()));
    }
    ifs.close();
}
void CEndGame::UpdateScoreEdit()
{
    if (!m_timeRecordsVector.empty())
    {
        m_time = m_timeRecordsVector.back(); // 获取最后一个记录
        UpdateData(FALSE); // 更新控件显示
    }
}
void CEndGame::UpdateScoreBest()
{
    if (!m_timeRecordsVector.empty())
    {
        // 找到最小的时间记录
        auto minElement = std::min_element(m_timeRecordsVector.begin(), m_timeRecordsVector.end());
        CString minTime = *minElement;

        // 更新 IDC_SCOREBEST 控件显示
        SetDlgItemText(IDC_SCOREBEST, minTime);
    }
}

//void CEndGame::OnBnClickedPlaybackButton()
//{
//    CImagingDlg imagingDlg;
//    // 假设 pMazeGameDlg 是一个指向 MazeGameDlg 实例的指针
//    extern CMazeGameDlg* pMazeGameDlg;
//    imagingDlg.LoadMazeData(pMazeGameDlg->GetMazeData()); // 获取并加载迷宫数据
//    imagingDlg.m_playerPath = pMazeGameDlg->GetPlayerPath(); // 获取玩家路径
//    imagingDlg.DoModal(); // 弹出 IDD_IMAGING 窗口
//}
