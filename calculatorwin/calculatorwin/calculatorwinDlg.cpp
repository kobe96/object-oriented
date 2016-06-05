
// calculatorwinDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculatorwin.h"
#include "calculatorwinDlg.h"
#include "afxdialogex.h"

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


// CcalculatorwinDlg 对话框



CcalculatorwinDlg::CcalculatorwinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATORWIN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorwinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalculatorwinDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorwinDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorwinDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorwinDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON11, &CcalculatorwinDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorwinDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorwinDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorwinDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON12, &CcalculatorwinDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CcalculatorwinDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON17, &CcalculatorwinDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorwinDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorwinDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorwinDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON14, &CcalculatorwinDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CcalculatorwinDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CcalculatorwinDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON10, &CcalculatorwinDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON18, &CcalculatorwinDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CcalculatorwinDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CcalculatorwinDlg::OnBnClickedButton20)
END_MESSAGE_MAP()


// CcalculatorwinDlg 消息处理程序

BOOL CcalculatorwinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorwinDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CcalculatorwinDlg::OnPaint()
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
HCURSOR CcalculatorwinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorwinDlg::OnBnClickedButton1()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "1";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "1";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton2()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "2";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "2";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton3()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "3";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "3";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton11()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
		sumstring += "0+";
	else if ((sumstring[sumstring.GetLength()-1] >='0'&&sumstring[sumstring.GetLength()-1] <= '9')
		||(sumstring[sumstring.GetLength() - 1]==')')
		)
	sumstring += "+";
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton4()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "4";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "4";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton5()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "5";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "5";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton6()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "6";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "6";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton12()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
		sumstring += "0+";
	else if ((sumstring[sumstring.GetLength() - 1] >= '0' &&sumstring[sumstring.GetLength() - 1] <= '9')
		|| sumstring[sumstring.GetLength() - 1]=='('
		|| sumstring[sumstring.GetLength() - 1] == ')'
		||((sumstring[sumstring.GetLength() - 1]>'9'|| sumstring[sumstring.GetLength() - 1]<'0')&& sumstring[sumstring.GetLength() - 1]!='.'&&
			(sumstring[sumstring.GetLength() - 2] >= '0' &&sumstring[sumstring.GetLength() - 2] <= '9'))
		)
		sumstring += "-";
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton13()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring != "")
	{
		if ((sumstring[sumstring.GetLength() - 1] >= '0'&&sumstring[sumstring.GetLength() - 1] <= '9')
			|| (sumstring[sumstring.GetLength() - 1] == ')')
			)
			sumstring += "*";
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton17()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}if (sumstring != "")
	{
		if ((sumstring[sumstring.GetLength() - 1] >= '0'&&sumstring[sumstring.GetLength() - 1] <= '9')
			|| (sumstring[sumstring.GetLength() - 1] == ')')
			)
			sumstring += "/";
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton7()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "7";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "7";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton8()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "8";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "8";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton9()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "9";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "9";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton14()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if(sumstring=="")
		sumstring += "(";
	else if((sumstring[sumstring.GetLength() - 1]>'9'||sumstring[sumstring.GetLength() - 1]<'0')&& sumstring[sumstring.GetLength() - 1]!='.')
		sumstring += "(";
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton15()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
		sumstring += '0';
	else if (sumstring[sumstring.GetLength() - 1]<='9'&&sumstring[sumstring.GetLength() - 1]>='0')
		sumstring += ")";
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton16()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
		sumstring += "0.";
	else if (sumstring[sumstring.GetLength() - 1] >= '0'&&sumstring[sumstring.GetLength() - 1] <= '9')
	{
		int js = 0;
			for (int i = sumstring.GetLength() - 1; i >= 0; i--)
			{
				if (sumstring[i] >= '0'&&sumstring[i] <= '9')
					continue;
				else if (sumstring[i] == '.')
					js++;
				else if ((sumstring[i] < '0'&&sumstring[i] > '9') && (sumstring[i] != '.'))
					break;
			}
			if (js == 0)
			{
				sumstring += ".";
				GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
			}
			else
				GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	

	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton10()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
	{
		sumstring += "0";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	else if (sumstring[sumstring.GetLength() - 1] == ')')
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	else
	{
		sumstring += "0";
		GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton18()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	sumstring.Delete(sumstring.GetLength() - 1, 1);
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton19()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	sumstring.Delete(0, sumstring.GetLength());
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorwinDlg::OnBnClickedButton20()
{

	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	if (sumstring == "error")
	{
		sumstring.Delete(0, sumstring.GetLength());
	}
	else if (sumstring != "")
	{
		if (sumstring[sumstring.GetLength() - 1] == '=')
		{
			sumstring.Delete(0, sumstring.GetLength());
		}
	}
	if (sumstring == "")
		sumstring += "0";
	else if(sumstring[sumstring.GetLength() - 1] >= '0'&&sumstring[sumstring.GetLength() - 1] <='9' )
	{
		sumstring += "=";
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: 在此添加控件通知处理程序代码
}
