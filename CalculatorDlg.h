
// CalculatorDlg.h: 头文件
//

#pragma once


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedSubButton();
	afx_msg void OnBnClickedMulButton();
	afx_msg void OnBnClickedDivButton();
	afx_msg void OnBnClickedLbButton();
	afx_msg void OnBnClickedRbButton();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedCalButton();
	CString m_editResult;
	BOOL checkCode;
	BOOL errorCode;
	int numLenth;
	afx_msg void OnBnClickedDotButton();
	afx_msg void OnBnClickedBackButton();

	void SetOriginalMode();
	void SetNumButtonsMode(int order, int zeromode);
	void NumButtonsResult(int checkzero);
	int BracketsChecking();
	int DotsChecking();
	int NumberChecking();
	double ResultCal(CString expression);
	int PriorityJudging(char first, char second);
	double NumOperating(double fNum, char op, double sNum);
	BOOL IsOperator(CString nowchar);
	 //BOOL DivisorCheck(CString div);
	double ReadNumber(CString nowexpression);
	char CStringToChar(CString change);
	afx_msg void OnBnClickedZeroButton();
};
