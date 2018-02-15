// OpeningScreen.cpp : implementation file

#include "stdafx.h"
#include "Paint.h"
#include "PaintDlg.h"
#include "OpeningScreen.h"
#include "afxdialogex.h"
// OpeningScreen dialog

IMPLEMENT_DYNAMIC(OpeningScreen, CDialogEx)

OpeningScreen::OpeningScreen(CWnd* pParent /*=NULL*/)
	: CDialogEx(OpeningScreen::IDD, pParent) {
		bgBmp.LoadBitmapW(IDB_BITMAP8);
}

OpeningScreen::~OpeningScreen() {}

void OpeningScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); DDX_Control(pDX, IDC_BUTTON1, StartBotton);
}

BEGIN_MESSAGE_MAP(OpeningScreen, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &OpeningScreen::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// OpeningScreen message handlers

void OpeningScreen::OnBnClickedButton1()
{
	this->OnCancel();
	CPaintDlg a;
	a.DoModal();
}

void OpeningScreen::OnPaint()
{
	CPaintDC dc(this);

	CDC memDc; // set the bg picture
	memDc.CreateCompatibleDC(&dc);
	memDc.SelectObject(&bgBmp);
	dc.BitBlt(0,0,2750,600, &memDc, 0, 0, SRCCOPY);

	CDialogEx::OnPaint();
}

BOOL OpeningScreen::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	StartBotton.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP2))); // set the start icon

	return TRUE; 
}
