// MazeGameDlg.h: 头文件
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
	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAZEGAME_DIALOG };
#endif

public:
	CMazeGameDlg(CWnd* pParent = nullptr);
	void InitializeMaze(int size);
	int GetElapsedTime() const;
	void updateWall();
	void CalculateCellSizeAndTimerRect();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	afx_msg BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	HICON m_hIcon;
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	Maze* m_pMaze;
	int m_mazeSize;
	std::pair<int, int> m_playerPos;
	int m_nSecondsElapsed;
	bool m_bTimerRunning;
	bool m_bNeedUpdateWalls;
	void MovePossible(int dx, int dy);
	CDC m_memDC;
	CBitmap m_memBitmap;
	std::pair<int, int> m_prevPlayerPos;
	int cellSize;
	int timerX;
	int timerY;
	CRect timerRect;
	int hintX;
};
