﻿// MazeGameDlg.h: 头文件
//

#pragma once
#include "MazeGame.h"

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
	DECLARE_MESSAGE_MAP()
};

// CMazeGameDlg 对话框
class CMazeGameDlg : public CDialogEx
{
	// 构造
public:
	CMazeGameDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void InitializeMaze(int size);
	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAZEGAME_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	afx_msg BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent); // 添加计时器消息处理函数
	DECLARE_MESSAGE_MAP()

private:
	Maze* m_pMaze;
	int m_mazeSize;
	std::pair<int, int> m_playerPos;
	int m_nSecondsElapsed; // 添加计时器变量

	void MovePossible(int dx, int dy);
	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
};
