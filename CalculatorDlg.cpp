
// CalculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <stack>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

BOOL checkCode = FALSE;
BOOL errorCode = FALSE;
int numLenth = 0;
// CCalculatorDlg 对话框


CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_editResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editResult);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CCalculatorDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_SUB_BUTTON, &CCalculatorDlg::OnBnClickedSubButton)
	ON_BN_CLICKED(IDC_MUL_BUTTON, &CCalculatorDlg::OnBnClickedMulButton)
	ON_BN_CLICKED(IDC_DIV_BUTTON, &CCalculatorDlg::OnBnClickedDivButton)
	ON_BN_CLICKED(IDC_LB_BUTTON, &CCalculatorDlg::OnBnClickedLbButton)
	ON_BN_CLICKED(IDC_Rb_BUTTON, &CCalculatorDlg::OnBnClickedRbButton)
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_CAL_BUTTON, &CCalculatorDlg::OnBnClickedCalButton)
	ON_BN_CLICKED(IDC_DOT_BUTTON, &CCalculatorDlg::OnBnClickedDotButton)
	ON_BN_CLICKED(IDC_BACK_BUTTON, &CCalculatorDlg::OnBnClickedBackButton)
	ON_BN_CLICKED(IDC_ZERO_BUTTON, &CCalculatorDlg::OnBnClickedZeroButton)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculatorDlg::OnBnClickedAddButton()
{
	UpdateData(TRUE);
	m_editResult += _T("+");
	UpdateData(FALSE);

	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);

	GetDlgItem(IDC_LB_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_BACK_BUTTON)->EnableWindow(TRUE);
	SetNumButtonsMode(1, 1);
}

void CCalculatorDlg::OnBnClickedSubButton()
{
	UpdateData(TRUE);
	m_editResult += "-";
	UpdateData(FALSE);

	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);

	GetDlgItem(IDC_LB_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_BACK_BUTTON)->EnableWindow(TRUE);
	SetNumButtonsMode(1, 1);
}

void CCalculatorDlg::OnBnClickedMulButton()
{
	UpdateData(TRUE);
	m_editResult += "*";
	UpdateData(FALSE);

	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);

	GetDlgItem(IDC_LB_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_BACK_BUTTON)->EnableWindow(TRUE);
	SetNumButtonsMode(1, 1);
}

void CCalculatorDlg::OnBnClickedDivButton()
{
	UpdateData(TRUE);
	m_editResult += "/";
	UpdateData(FALSE);

	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);

	GetDlgItem(IDC_LB_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_BACK_BUTTON)->EnableWindow(TRUE);
	SetNumButtonsMode(1,1);
}

void CCalculatorDlg::OnBnClickedLbButton()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "(";
	else {
		m_editResult = "(";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);

	GetDlgItem(IDC_BACK_BUTTON)->EnableWindow(TRUE);
	SetNumButtonsMode(1, 1);

}

void CCalculatorDlg::OnBnClickedRbButton()
{
	UpdateData(TRUE);
	m_editResult += ")";
	UpdateData(FALSE);

	GetDlgItem(IDC_BACK_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(TRUE);

	GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_LB_BUTTON)->EnableWindow(FALSE);
	SetNumButtonsMode(0,0);

	int bracketsCheck = BracketsChecking();
	if (bracketsCheck == 1)
	{
		GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);
	}
		
	else 
	{
		GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(TRUE);
	}
		
}

void CCalculatorDlg::OnBnClickedButton0()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += _T("0");
	else {
		m_editResult = _T("0");
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	if (DotsChecking() == 0)
		NumButtonsResult(1);
	else
		NumberChecking();
}

void CCalculatorDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += _T("1");
	else {
		m_editResult = _T("1");
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);
}

void CCalculatorDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "2";
	else {
		m_editResult = "2";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);

}

void CCalculatorDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "3";
	else {
		m_editResult = "3";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);
}

void CCalculatorDlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "4";
	else {
		m_editResult = "4";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);
}

void CCalculatorDlg::OnBnClickedButton5()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "5";
	else {
		m_editResult = "5";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);

}

void CCalculatorDlg::OnBnClickedButton6()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "6";
	else {
		m_editResult = "6";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);

}

void CCalculatorDlg::OnBnClickedButton7()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "7";
	else {
		m_editResult = "7";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);

}

void CCalculatorDlg::OnBnClickedButton8()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "8";
	else {
		m_editResult = "8";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);

}

void CCalculatorDlg::OnBnClickedButton9()
{
	UpdateData(TRUE);
	if (!checkCode)
		m_editResult += "9";
	else {
		m_editResult = "9";
		checkCode = FALSE;
	}
	UpdateData(FALSE);

	NumButtonsResult(1);
}

void CCalculatorDlg::OnBnClickedDotButton()
{
	UpdateData(TRUE);
	m_editResult += ".";
	UpdateData(FALSE);

	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_LB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);
	
	SetNumButtonsMode(1,1);
}

void CCalculatorDlg::OnBnClickedBackButton()
{
	UpdateData(TRUE);

	CString checkLast;

	int lenth = m_editResult.GetLength();
	m_editResult = m_editResult.Left(lenth - 1);

	UpdateData(FALSE);

	if (lenth == 1) 
		SetOriginalMode();

	else if (lenth >= 2) {
		checkLast = m_editResult.GetAt(lenth - 2);

		if (checkLast.Compare(_T("+")) == 0
			|| checkLast.Compare(_T("-")) == 0
			|| checkLast.Compare(_T("*")) == 0
			|| checkLast.Compare(_T("/")) == 0) {
			GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);

			GetDlgItem(IDC_LB_BUTTON)->EnableWindow(TRUE);
			SetNumButtonsMode(1,1);

		}

		else if (checkLast.Compare(_T("(")) == 0) {
			GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);
			SetNumButtonsMode(1,1);

		}

		else if (checkLast.Compare(_T(".")) == 0) {
			GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_LB_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);

			SetNumButtonsMode(1,1);
		}

		else if (checkLast.Compare(_T(")")) == 0) {
			GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(TRUE);

			GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_LB_BUTTON)->EnableWindow(FALSE);
			SetNumButtonsMode(0,0);

			int bracketsCheck = BracketsChecking();
			if (bracketsCheck == 1)
			{
				GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(TRUE);
				GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);
			}

			else
			{
				GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
				GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(TRUE);
			}

		}

		else if (checkLast.Compare(_T("0")) == 0) {
			if (DotsChecking() == 0)
				NumButtonsResult(1);
			else
				NumberChecking();
		}

		else NumButtonsResult(1);
	}
}

void CCalculatorDlg::OnBnClickedZeroButton()
{
	UpdateData(TRUE);
	m_editResult = _T("");
	UpdateData(FALSE);

	SetOriginalMode();
}

void CCalculatorDlg::SetNumButtonsMode(int order, int zeromode)
{
	if (order == 0)
	{
		GetDlgItem(IDC_BUTTON0)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
	}

	else
	{
		if (order == 1 && zeromode == 1) {
			GetDlgItem(IDC_BUTTON0)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
		}

		else
		{
			GetDlgItem(IDC_BUTTON0)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
		}
	}

}

void CCalculatorDlg::NumButtonsResult(int checkzero)
{
	GetDlgItem(IDC_LB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_BACK_BUTTON)->EnableWindow(TRUE);

	if (checkzero == 1)
		SetNumButtonsMode(1, 1);
	else if (checkzero == 0)
		SetNumButtonsMode(1, 0);
	else
		SetNumButtonsMode(0, 0);
	

	int check1 = BracketsChecking();
	if (check1 == 1)
	{
		GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(TRUE);
	}
		

	int check2 = DotsChecking();
	if (check2 == 1)
		GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
}

int CCalculatorDlg::BracketsChecking()
{
	int left = 0, right = 0;
	
	left = m_editResult.Replace(_T("("), _T("("));
	right = m_editResult.Replace(_T(")"), _T(")"));

	if (left - right > 0)
		return 1;
	else
		return 0;
}

int CCalculatorDlg::DotsChecking()
{
	CString aux;

	int len = m_editResult.GetLength();

	int checkingCode;

	for (int i = len - 1; i >= 0; i--) {
		aux = m_editResult.GetAt(i);

		if (aux.Compare(_T("0")) == 0
			|| aux.Compare(_T("1")) == 0
			|| aux.Compare(_T("2")) == 0
			|| aux.Compare(_T("3")) == 0
			|| aux.Compare(_T("4")) == 0
			|| aux.Compare(_T("5")) == 0
			|| aux.Compare(_T("6")) == 0
			|| aux.Compare(_T("7")) == 0
			|| aux.Compare(_T("8")) == 0
			|| aux.Compare(_T("9")) == 0) {

			checkingCode = 1;
			continue;
		}

		else {
			if (aux.Compare(_T(".")) == 0) {
				checkingCode = 0;
				break;
			}

			else {
				checkingCode = 1;
				break;
			}
		}

	}

	return checkingCode;
}

int CCalculatorDlg::NumberChecking()
{
	CString aux;

	int len = m_editResult.GetLength();

	if (len == 1)
	{
		NumButtonsResult(2);
	}

	else
	{
		aux = m_editResult.GetAt(len - 2);

		if (aux.Compare(_T("0")) == 0
			|| aux.Compare(_T("1")) == 0
			|| aux.Compare(_T("2")) == 0
			|| aux.Compare(_T("3")) == 0
			|| aux.Compare(_T("4")) == 0
			|| aux.Compare(_T("5")) == 0
			|| aux.Compare(_T("6")) == 0
			|| aux.Compare(_T("7")) == 0
			|| aux.Compare(_T("8")) == 0
			|| aux.Compare(_T("9")) == 0)
		{
			NumButtonsResult(1);
		}

		else if (aux.Compare(_T("(")) == 0
			|| aux.Compare(_T("+")) == 0
			|| aux.Compare(_T("-")) == 0
			|| aux.Compare(_T("*")) == 0
			|| aux.Compare(_T("/")) == 0)
		{
			NumButtonsResult(2);
		}
	}
	
	return 0;
}

void CCalculatorDlg::SetOriginalMode()
{
	GetDlgItem(IDC_ADD_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUB_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_DIV_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_Rb_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_LB_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_DOT_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_CAL_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_BACK_BUTTON)->EnableWindow(FALSE);

	SetNumButtonsMode(1,1);
}

void CCalculatorDlg::OnBnClickedCalButton()
{
	CString expression;

	UpdateData(TRUE);

	expression = m_editResult;
	expression += "#";

	UpdateData(FALSE);

	double result = ResultCal(expression);

	if (errorCode) {
		UpdateData(TRUE);
		m_editResult = _T("Maths Error: The divisor is 0!");
		UpdateData(FALSE);
		errorCode = FALSE;
	}

	else {
		UpdateData(TRUE);
		m_editResult.Format(_T("%f"), result);
		UpdateData(FALSE);
	}


	checkCode = TRUE;
	SetOriginalMode();
}

double CCalculatorDlg::ResultCal(CString expression)
{

	stack<char> Operator;
	stack<double> Operand;

	CString aux, numCheck;
	double result;
	int priority;

	Operator.push('#');

	int auxNum = 0;
	int EXPlenth = expression.GetLength();

	aux = expression.GetAt(auxNum);

	while (aux.Compare(_T("#")) != 0 || Operator.top() != '#') {

		if (!IsOperator(aux)) {
			numCheck = expression.Mid(auxNum, EXPlenth);
			Operand.push(ReadNumber(numCheck));
			auxNum += numLenth;
			aux = expression.GetAt(auxNum);
		}

		else {
			priority = PriorityJudging(Operator.top(), CStringToChar(aux));
			switch (priority)
			{
			case -1:
			{
				Operator.push(CStringToChar(aux));
				auxNum++;
				aux = expression.GetAt(auxNum);
				break;
			}
			case 0:
			{
				Operator.pop();
				auxNum++;
				aux = expression.GetAt(auxNum);
				break;
			}
			case 1:
			{
				char op = Operator.top();
				Operator.pop();
				double s = Operand.top();
				Operand.pop();
				double f = Operand.top();
				Operand.pop();
				Operand.push(NumOperating(f, op, s));
				break;
			}
			default:
				break;
			}
		}
	}

	result = Operand.top();
	Operand.pop();
	
	return result;
	
}

int CCalculatorDlg::PriorityJudging(char first, char second)
{
	char theOPs[7] = {'+', '-', '*', '/', '(', ')', '#'};
	char ill = NULL;
	char judgement;
	int index1 = 0, index2 = 0;

	char thePriority[7][7] = { '>', '>', '<', '<', '<', '>', '>',
							  '>', '>', '<', '<', '<', '>', '>',
							  '>', '>', '>', '>', '<', '>', '>',
							  '>', '>', '>', '>', '<', '>', '>',
							  '<', '<', '<', '<', '<', '=', ill, 
							  '>', '>', '>', '>', ill, '>', '>', 
							  '<', '<', '<', '<', '<', ill, '='};

	for (int i = 0; i < 7; i++) {
		{
			if (theOPs[i] == first) {
				index1 = i;
				break;
			}
		}
	}
	for (int j = 0; j < 7; j++) {
		{
			if (theOPs[j] == second) {
				index2 = j;
				break;
			}
		}
	}

	judgement = thePriority[index1][index2];

	if (judgement == '>')
		return 1;
	else if (judgement == '=')
		return 0;
	else if (judgement == '<')
		return -1;
	else
		return 2;
}

double CCalculatorDlg::NumOperating(double fNum, char op, double sNum)
{
	if (op == '+')
		return (fNum + sNum);
	else if (op == '-')
		return (fNum - sNum);
	else if (op == '*')
		return (fNum * sNum);
	else if (op == '/') {
		if (sNum == 0) {
			errorCode = TRUE;
			return 1;
		}
		else return (fNum / sNum);
	}	
	else
		return 2.3;
}

BOOL CCalculatorDlg::IsOperator(CString nowchar)
{
	if (nowchar.Compare(_T("+")) == 0
		|| nowchar.Compare(_T("-")) == 0
		|| nowchar.Compare(_T("*")) == 0
		|| nowchar.Compare(_T("/")) == 0
		|| nowchar.Compare(_T("(")) == 0
		|| nowchar.Compare(_T(")")) == 0
		|| nowchar.Compare(_T("#")) == 0)
		return TRUE;
	else 
		return FALSE;
}

double CCalculatorDlg::ReadNumber(CString nowexpression)
{
	CString aux;
	int index = 0;

	for (int i = 0; i < nowexpression.GetLength(); i++) {
		aux = nowexpression.GetAt(i);
		if (IsOperator(aux)) {
			index = i;
			break;
		}
	}
	double num;

	numLenth = index;
	num = _ttof(nowexpression.Mid(0, index));

	return num;
}

char CCalculatorDlg::CStringToChar(CString change)
{
	if (change.Compare(_T("+")) == 0)
		return '+';
	else if (change.Compare(_T("-")) == 0)
		return '-';
	else if (change.Compare(_T("*")) == 0)
		return '*';
	else if (change.Compare(_T("/")) == 0)
		return '/';
	else if (change.Compare(_T("(")) == 0)
		return '(';
	else if (change.Compare(_T(")")) == 0)
		return ')';
	else return 'f';
}

/*
BOOL CCalculatorDlg::DivisorCheck(CString div)
{
	int lenth = div.GetLength();
	CString aux;

	aux = div.GetAt(lenth - 2);

	if (aux.Compare(_T("/")) == 0) return FALSE;

	else return FALSE;
}
*/