
// PaintDlg.cpp : implementation file

#include "stdafx.h"
#include "Paint.h"
#include "PaintDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD) {}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CPaintDlg dialog

CPaintDlg::CPaintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPaintDlg::IDD, pParent), PenType(0), PenSize(1), FillPressed(false), MovePressed(false),
	shapeType(0), DeleteBotton(false), ChengeSize(false), isPressed(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_red);
	DDX_Control(pDX, IDC_SLIDER2, m_green);
	DDX_Control(pDX, IDC_SLIDER3, m_blue);
	DDX_Control(pDX, IDC_BUTTON1, m_StopButton_red);
	DDX_Control(pDX, IDC_BUTTON2, m_StopButton_blue);
	DDX_Control(pDX, IDC_BUTTON3, m_StopButton_green);
	DDX_Control(pDX, IDC_BUTTON4, m_StopButton_yellow);
	DDX_Control(pDX, IDC_BUTTON5, m_StopButton_pink);
	DDX_Control(pDX, IDC_BUTTON6, m_StopButton_purple);
	DDX_Control(pDX, IDC_BUTTON7, m_StopButton_orange);
	DDX_Control(pDX, IDC_BUTTON8, m_StopButton_brown);
	DDX_Control(pDX, IDC_BUTTON9, m_StopButton_white);
	DDX_Control(pDX, IDC_BUTTON10, m_StopButton_gray);
	DDX_Control(pDX, IDC_BUTTON12, m_StopButton_black);
	DDX_Control(pDX, IDC_BUTTON11, m_StopButton_turkiz);
	DDX_Control(pDX, IDC_BUTTON13, undo);
	DDX_Control(pDX, IDC_BUTTON14, redo);
	DDX_Control(pDX, IDCANCEL, exit);
	DDX_Control(pDX, IDC_BUTTON15, MoveShapeBotton);
	DDX_Control(pDX, IDC_BUTTON17, FillBotton);
	DDX_Control(pDX, IDC_COMBO2, PehTypeBotton);
	DDX_Control(pDX, IDC_BUTTON16, brush1);
	DDX_Control(pDX, IDC_BUTTON18, brush2);
	DDX_Control(pDX, IDC_BUTTON19, brush3);
	DDX_Control(pDX, IDC_BUTTON20, brush4);
	DDX_Control(pDX, IDC_BUTTON21, brush5);
	DDX_Control(pDX, IDOK3, save);
	DDX_Control(pDX, IDOK2, load);
	DDX_Control(pDX, IDC_BUTTON22, Delete);
	DDX_Control(pDX, IDC_BUTTON23, NewPage);
	DDX_Control(pDX, IDC_BUTTON24, m_StopButton_darkGreen);
	DDX_Control(pDX, IDC_BUTTON25, m_StopButton_darkPink);
	DDX_Control(pDX, IDC_BUTTON26, m_StopButton_purpleLight);
	DDX_Control(pDX, IDC_BUTTON27, m_StopButton_grayLight);
	DDX_Control(pDX, IDC_BUTTON28, ChangeSizeBotton);
}

BEGIN_MESSAGE_MAP(CPaintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON13, &CPaintDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CPaintDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON1, &CPaintDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPaintDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPaintDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPaintDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPaintDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPaintDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CPaintDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CPaintDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CPaintDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CPaintDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CPaintDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CPaintDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_RADIO4, &CPaintDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CPaintDlg::OnBnClickedRadio5)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CPaintDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON17, &CPaintDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDCANCEL, &CPaintDlg::OnBnClickedCancel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CPaintDlg::OnNMCustomdrawSlider1)
	ON_BN_CLICKED(IDC_BUTTON18, &CPaintDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON20, &CPaintDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON19, &CPaintDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON21, &CPaintDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON16, &CPaintDlg::OnBnClickedButton16)
	ON_WM_CTLCOLOR()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON15, &CPaintDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDOK3, &CPaintDlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK2, &CPaintDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDC_BUTTON22, &CPaintDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CPaintDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CPaintDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CPaintDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CPaintDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CPaintDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_RADIO6, &CPaintDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CPaintDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CPaintDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &CPaintDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &CPaintDlg::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_BUTTON28, &CPaintDlg::OnBnClickedButton28)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CPaintDlg::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CPaintDlg::OnNMCustomdrawSlider3)
END_MESSAGE_MAP()

static int Memory = 0;
// CPaintDlg message handlers
BOOL CPaintDlg::OnInitDialog()
{
	if (Memory == 0)
	{
		Memory++;
		this->OnCancel();
		OpeningScreen b;
		b.DoModal();
	}
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	r.left = 195;
	r.top = 72;
	r.right = 1200;
	r.bottom = 525;

	BGColorB.CreateSolidBrush(RGB(255,255,255));

	CheckRadioButton(IDC_RADIO1, IDC_RADIO5, IDC_RADIO1);
	m_red.SetRangeMax(255);
	m_red.SetRangeMin(0);
	m_green.SetRangeMax(255);
	m_green.SetRangeMin(0);
	m_blue.SetRangeMax(255);
	m_blue.SetRangeMin(0);

	save.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	exit.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP3)));
	load.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP18)));
	undo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP15)));
	redo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP16)));
	brush1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP9)));
	brush2.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP10)));
	brush3.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP13)));
	brush4.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP12)));
	brush5.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP7)));
	FillBotton.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP5)));
	MoveShapeBotton.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP17)));
	Delete.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP19)));
	NewPage.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP20)));
	ChangeSizeBotton.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP6)));

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CPaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPaintDlg::OnPaint()
{
	CPaintDC dc(this);
	for (int i = 0; i < myShapes.GetSize(); ++i)
		myShapes[i]->draw(&dc);

	CBrush brush(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
	CPen pen(PS_SOLID, 1, RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos())); 
	CBrush *old = dc.SelectObject(&brush);
	CPen *oldP = dc.SelectObject(&pen);
	dc.Rectangle(82, 500, 102, 520); // show the color in real time

	// Set the background color for the button.
	m_StopButton_red.SetFaceColor(RGB(255,0,0),true);
	m_StopButton_blue.SetFaceColor(RGB(0,128,255),true); 
	m_StopButton_green.SetFaceColor(RGB(85,255,85),true);
	m_StopButton_yellow.SetFaceColor(RGB(255,255,23),true);
	m_StopButton_pink.SetFaceColor(RGB(255,104,180),true);
	m_StopButton_purple.SetFaceColor(RGB(98,0,196),true);
	m_StopButton_orange.SetFaceColor(RGB(255,141,28),true);
	m_StopButton_brown.SetFaceColor(RGB(89,0,0),true);
	m_StopButton_white.SetFaceColor(RGB(255,255,255),true);
	m_StopButton_gray.SetFaceColor(RGB(89,89,89),true);
	m_StopButton_black.SetFaceColor(RGB(0,0,0),true);
	m_StopButton_turkiz.SetFaceColor(RGB(0,223,223),true);
	m_StopButton_darkGreen.SetFaceColor(RGB(0,113,0),true);
	m_StopButton_darkPink.SetFaceColor(RGB(255,0,128),true);
	m_StopButton_purpleLight.SetFaceColor(RGB(188,121,255),true);
	m_StopButton_grayLight.SetFaceColor(RGB(149,149,149),true);

	dc.SelectObject(old);
	dc.SelectObject(oldP);

	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CPaintDC dc(this);

	if (isPressed)
	{
		if(MovePressed)
		{			
			myShapes[MoveIndex]->end.x += (point.x - myShapes[MoveIndex]->start.x);
			myShapes[MoveIndex]->end.y += (point.y - myShapes[MoveIndex]->start.y);
			myShapes[MoveIndex]->start.x = point.x;
			myShapes[MoveIndex]->start.y = point.y;
			InvalidateRect(&r);
		}
		else
		{
			if (ChengeSize)
			{
				myShapes[MoveIndex]->start.x = point.x;
				myShapes[MoveIndex]->start.y = point.y;
				InvalidateRect(&r);
			}
			else
			{
				myShapes[myShapes.GetSize()-1]->setEnd(point);
				InvalidateRect(&r);
			}
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CPaintDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	isPressed = true;
	if(MovePressed || ChengeSize) // move shape or change size of shape
	{
		for (int i=myShapes.GetSize()-1; i>=0; i--)
		{
			if (myShapes[i]->InShape(point))
			{
				MoveIndex = i;
				break;
			}
		}
	}
	else 
	{
		if (FillPressed) // fill shape
		{
			for (int i = myShapes.GetSize()-1; i >= 0; i--)
			{
				if (myShapes[i]->InShape(point))
				{
					command *c = new AddColor(myShapes[i],RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
					c->perform(); // change the color of this shape
					commands.push(c);
					break;
				}
			}
		}
		else
		{
			if (DeleteBotton) // deledt shape
			{
				for (int i = myShapes.GetSize()-1; i >= 0; i--)
				{
					if (myShapes[i]->InShape(point))
					{
						command *c = new DeleteShape(myShapes,myShapes[i]);
						c->perform();
						commands.push(c);
						InvalidateRect(&r);
						break;
					}
				} 
			}
			else // new shape
			{
				MyShape *s = 0;
				switch (shapeType) // create the shape the user pressed
				{
				case 0: s = new MyLine(); break;
				case 1: s = new MyRectangle(); break;
				case 2: s = new MyEllipse(); break;
				case 3: s = new MyTriangle(); break;
				case 4: s = new MyTrapeze(); break;
				case 5: s = new Myhexagonal(); break;
				case 6: s = new MyPentagon(); break;
				}
				command *c = new AddShape(myShapes, s);
				c->perform(); // add shape to the array
				commands.push(c);
				s->setBg(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
				s->setP(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
				s->setShapePenType(PenType);
				s->setShapePenSize(PenSize);
				s->setStart(point);
				s->setEnd(point);
			}
		}
	}
	Invalidate();

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CPaintDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(!MovePressed && !FillPressed && !DeleteBotton && !ChengeSize) // we done to draw - not move, fill or delete!
		myShapes[myShapes.GetSize()-1]->setEnd(point);
	isPressed = false;
	MovePressed = false;
	FillPressed = false;
	DeleteBotton = false;
	ChengeSize = false;
	Invalidate();

	CDialogEx::OnLButtonUp(nFlags, point);
}

void CPaintDlg::OnRButtonDown(UINT nFlags, CPoint point) // fill object by click on right botton
{
	for (int i = myShapes.GetSize()-1; i >= 0; i--)
	{
		if (myShapes[i]->InShape(point))
		{
			command *c = new AddColor(myShapes[i],(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos())));
			c->perform();
			commands.push(c);
			break;
		}
	}
	Invalidate();
	CDialogEx::OnRButtonDown(nFlags, point);
}

void CPaintDlg::OnBnClickedRadio7() // line
{ shapeType = 0; }

void CPaintDlg::OnBnClickedRadio8() // rectangle
{ shapeType = 1; }

void CPaintDlg::OnBnClickedRadio9() // ellipse
{ shapeType = 2; }

void CPaintDlg::OnBnClickedRadio4() // triangle
{ shapeType = 3; }

void CPaintDlg::OnBnClickedRadio5() // trapeze
{ shapeType = 4; }

void CPaintDlg::OnBnClickedRadio6() // hexagonal
{ shapeType = 5; }

void CPaintDlg::OnBnClickedRadio10() // pentagon
{ shapeType = 6; }

void CPaintDlg::OnBnClickedCancel()
{ CDialogEx::OnCancel(); }

void CPaintDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	InvalidateRect(&r);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CPaintDlg::OnBnClickedButton13() // undo
{
	if (!(commands.empty()))
	{
		command *c = commands.top();
		c->rollback();
		undoes.push(c);
		commands.pop();
	}
	InvalidateRect(&r);
}

void CPaintDlg::OnBnClickedButton14() // redo
{
	if (!(undoes.empty()))
	{
		command *c = undoes.top();
		c->perform();
		commands.push(c);
		undoes.pop();
	}
	InvalidateRect(&r);	
}

void CPaintDlg::OnBnClickedButton1() // red color botton
{
	m_red.SetPos(255);
	m_green.SetPos(0);
	m_blue.SetPos(0);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton2() // green color botton
{
	m_red.SetPos(0);
	m_green.SetPos(128);
	m_blue.SetPos(255);	
	Invalidate();
}

void CPaintDlg::OnBnClickedButton3() // blue color botton
{
	m_red.SetPos(85);
	m_green.SetPos(255);
	m_blue.SetPos(85);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton4() //  yellow color botton
{
	m_red.SetPos(255);
	m_green.SetPos(242);
	m_blue.SetPos(0);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton5() // pink color botton
{
	m_red.SetPos(255);
	m_green.SetPos(104);
	m_blue.SetPos(180);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton6() // purple color botton
{
	m_red.SetPos(98);
	m_green.SetPos(0);
	m_blue.SetPos(196);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton7() // orange color botton
{
	m_red.SetPos(255);
	m_green.SetPos(141);
	m_blue.SetPos(28);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton8() // brown color botton
{
	m_red.SetPos(89);
	m_green.SetPos(0);
	m_blue.SetPos(0);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton9() // white color botton
{
	m_red.SetPos(255);
	m_green.SetPos(255);
	m_blue.SetPos(255);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton10() // gray color botton
{
	m_red.SetPos(89);
	m_green.SetPos(89);
	m_blue.SetPos(89);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton12() // black color botton
{
	m_red.SetPos(0);
	m_green.SetPos(0);
	m_blue.SetPos(0);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton11() // turkiz color botton
{
	m_red.SetPos(0);
	m_green.SetPos(223);
	m_blue.SetPos(223);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton24() // dark green
{
	m_red.SetPos(0);
	m_green.SetPos(113);
	m_blue.SetPos(0);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton25() // dark pink
{
	m_red.SetPos(255);
	m_green.SetPos(0);
	m_blue.SetPos(128);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton26() // purple light
{
	m_red.SetPos(188);
	m_green.SetPos(121);
	m_blue.SetPos(255);
	Invalidate();
}

void CPaintDlg::OnBnClickedButton27() // light gray
{
	m_red.SetPos(149);
	m_green.SetPos(149);
	m_blue.SetPos(149);
	Invalidate();
}

void CPaintDlg::OnCbnSelchangeCombo2() // pen's thick choice
{
	int index = PehTypeBotton.GetCurSel();

	switch(index)
	{
	case 0:
		{
			PenSize = 1;
			break;
		}
	case 1:
		{
			PenSize = 4; 
			break;
		}
	case 2:
		{
			PenSize = 7;
			break;
		}
	case 3:
		{
			PenSize = 9;
			break;
		}
	case 4:
		{
			PenSize = 12;
			break;
		}
	}
}

void CPaintDlg::OnBnClickedButton17() // fill
{ FillPressed = true; }

void CPaintDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	*pResult = 0;
}

void CPaintDlg::OnBnClickedButton18() // ps_solid
{
	PenType = PS_SOLID;
	Invalidate();
}

void CPaintDlg::OnBnClickedButton20()
{
	PenType = PS_DASH;
	Invalidate();
}

void CPaintDlg::OnBnClickedButton19()
{
	PenType = PS_DOT;
	Invalidate();
}

void CPaintDlg::OnBnClickedButton21()
{
	PenType = PS_DASHDOT;
	Invalidate();
}

void CPaintDlg::OnBnClickedButton16()
{
	PenType = PS_DASHDOTDOT;
	Invalidate();
}

HBRUSH CPaintDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) // set the dialog bg color to white
{
	HBRUSH hbr = BGColorB;
	return hbr;
}

void CPaintDlg::OnBnClickedButton15() // move shape botton
{ MovePressed = true; }

void CPaintDlg::OnBnClickedOk3() // save
{
	CFile file(L"FILE.$$", CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	myShapes.Serialize(ar);
}

void CPaintDlg::OnBnClickedOk2() // load
{
	try 
	{
		CFile file(L"FILE.$$", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		myShapes.Serialize(ar);
	} 
	catch(...)
	{}

	InvalidateRect(&r);
}

void CPaintDlg::OnBnClickedButton22()
{ DeleteBotton = true; }

void CPaintDlg::OnBnClickedButton23() // new page
{
	while(!commands.empty())
		commands.pop();

	while(!undoes.empty())
		undoes.pop();

	myShapes.RemoveAll();
	Invalidate();
}

void CPaintDlg::OnBnClickedButton28()
{ ChengeSize = true; }

void CPaintDlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CPaintDlg::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}