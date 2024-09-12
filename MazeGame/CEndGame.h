// CEndGame.h
#pragma once
#include "afxdialogex.h"
#include "afxwin.h"
#include <vector>
#include <string>
#include "CImagingDlg.h"
#include "MazeGameDlg.h"

class CImagingDlg; // 前向声明

// CEndGame 对话框
class CEndGame : public CDialogEx
{
    DECLARE_DYNAMIC(CEndGame)

public:
    CEndGame(CWnd* pParent = nullptr);   // 标准构造函数
    virtual ~CEndGame();
    CString m_time;

    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDC_ENDGAME };
#endif
protected:
    HICON m_hIcon;
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedExitEnd();
    afx_msg void OnBnClickedHistory();
    afx_msg void OnEnChangeScoredit();
    afx_msg void OnEnChangeScorebest();
    //CString ReadTime();
    std::vector<CString> m_timeRecordsVector;
    void LoadTimeRecords(); // 新增函数声明
    void UpdateScoreEdit(); // 声明函数
    void UpdateScoreBest(); // 声明函数
    afx_msg void OnBnClickedPlaybackButton();
};
