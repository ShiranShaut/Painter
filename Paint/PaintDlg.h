// PaintDlg.h : header file
#pragma once

#include "MyShape.h"
#include "MyEllipse.h"
#include "MyRectangle.h"
#include "MyTriangle.h"
#include "MyTrapeze.h"
#include "MyLine.h"
#include <vector>
#include "afxwin.h"
#include "AddShape.h"
#include <stack>
#include "OpeningScreen.h"
#include "AddColor.h"
#include "resource.h"
#include "DeleteShape.h"
#include "afxbutton.h"
#include "Myhexagonal.h"
#include "MyPentagon.h"

using namespace std;

// CPaintDlg dialog
class CPaintDlg : public CDialogEx
{
// Construction
public:
	CPaintDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_PAINT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	bool isPressed;
	CPoint start;
	CPoint end;
	CTypedPtrArray<CObArray, MyShape*> myShapes;
	stack<command*> commands, undoes;
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
private:
	int shapeType;
//	virtual void OnOK();
public:
	CSliderCtrl m_red;
	CSliderCtrl m_green;
	CSliderCtrl m_blue;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CMFCButton m_StopButton_red;
	CMFCButton m_StopButton_blue;
	CMFCButton m_StopButton_green;
	CMFCButton m_StopButton_yellow;
	CMFCButton m_StopButton_pink;
	CMFCButton m_StopButton_purple;
	CMFCButton m_StopButton_orange;
	CMFCButton m_StopButton_brown;
	CMFCButton m_StopButton_white;
	CMFCButton m_StopButton_gray;
	CMFCButton m_StopButton_black;
	CMFCButton m_StopButton_turkiz;
	CMFCButton m_StopButton_darkGreen;
	CMFCButton m_StopButton_darkPink;
	CMFCButton m_StopButton_purpleLight;
	CMFCButton m_StopButton_grayLight;
	CButton undo;
	CButton redo;
	afx_msg void OnBnClickedButton13(); // undo
	afx_msg void OnBnClickedButton14(); // redo
	afx_msg void OnBnClickedButton1(); // red
	afx_msg void OnBnClickedButton2(); // green
	afx_msg void OnBnClickedButton3(); // blue
	afx_msg void OnBnClickedButton4(); // yellow
	afx_msg void OnBnClickedButton5(); // pink
	afx_msg void OnBnClickedButton6(); // purple
	afx_msg void OnBnClickedButton7(); // orange
	afx_msg void OnBnClickedButton8(); // brown
	afx_msg void OnBnClickedButton9(); // white
	afx_msg void OnBnClickedButton10(); // gray
	afx_msg void OnBnClickedButton12(); // black
	afx_msg void OnBnClickedButton11(); // turkiz
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	CButton exit;
	CButton MoveShapeBotton;
	CButton FillBotton;
	CComboBox PehTypeBotton;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CButton brush1;
	CButton brush2;
	CButton brush3;
	CButton brush4;
	CButton brush5;
	int PenType;
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton16();
	int PenSize;
	CBrush BGColorB;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	bool FillPressed;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton15();
	bool MovePressed;
	int MoveIndex;
	CButton save;
	CButton load;
	afx_msg void OnBnClickedOk3();
	afx_msg void OnBnClickedOk2();
	CButton Delete;
	bool DeleteBotton;
	afx_msg void OnBnClickedButton22();
	CButton NewPage;
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio10();
	bool ChengeSize;
	afx_msg void OnBnClickedButton28();
	CButton ChangeSizeBotton;
	RECT r;
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
};
