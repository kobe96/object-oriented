
// calculatorwinDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculatorwin.h"
#include "calculatorwinDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CcalculatorwinDlg �Ի���



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


// CcalculatorwinDlg ��Ϣ�������

BOOL CcalculatorwinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorwinDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorwinDlg::OnBnClickedButton18()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	sumstring.Delete(sumstring.GetLength() - 1, 1);
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorwinDlg::OnBnClickedButton19()
{
	CString sumstring;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumstring);
	sumstring.Delete(0, sumstring.GetLength());
	GetDlgItem(IDC_EDIT1)->SetWindowText(sumstring);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
