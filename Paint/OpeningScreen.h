#pragma once
#include "PaintDlg.h"
#include "resource.h"
#include "afxwin.h"
#include "afxdialogex.h"

// OpeningScreen dialog

class OpeningScreen : public CDialogEx
{
	DECLARE_DYNAMIC(OpeningScreen)

public:
	OpeningScreen(CWnd* pParent = NULL);   // standard constructor
	virtual ~OpeningScreen();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	CButton StartBotton;
	virtual BOOL OnInitDialog();
	CBitmap bgBmp;
};
