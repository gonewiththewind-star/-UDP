// UDPprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UDPproject.h"
#include "UDPprojectDlg.h"
#include "Textprotcol.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUDPprojectDlg dialog

CUDPprojectDlg::CUDPprojectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUDPprojectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUDPprojectDlg)
	m_outmsg = _T("");
	m_ipaddr = _T("");
	m_static_state = _T("");
	m_port = 0;
	m_myinfo = _T("");
	m_111 = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUDPprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUDPprojectDlg)
	DDX_Control(pDX, IDC_CONNECT, m_connect);
	DDX_Control(pDX, IDC_LIST_MSG, m_list_msg);
	DDX_Text(pDX, IDC_EDIT_OUTMSG, m_outmsg);
	DDX_Text(pDX, IDC_SET_IPADDR, m_ipaddr);
	DDX_Text(pDX, IDC_STATIC_STATE, m_static_state);
	DDX_Text(pDX, IDC_EDIT_PORT, m_port);
	DDX_Text(pDX, IDC_STATIC_MYINFO, m_myinfo);
	DDX_Text(pDX, IDC_EDIT1, m_111);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUDPprojectDlg, CDialog)
	//{{AFX_MSG_MAP(CUDPprojectDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDOK, OnSendMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUDPprojectDlg message handlers

BOOL CUDPprojectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	// TODO: Add extra initialization here
	this->GetDlgItem(IDC_EDIT_OUTMSG)->EnableWindow(FALSE);
	//m_Active=FALSE;
	m_ipaddr="127.0.0.1";
	m_port=2008;
	m_static_state="    请进行初始化设置@_@";

	char szHostName[128];
	
	if( gethostname(szHostName, 128) == 0 )
	{
		// Get host addresses
		struct hostent * pHost;	
		int i=0; 	
		pHost = gethostbyname(szHostName); 
		LPCSTR psz=inet_ntoa (*(struct in_addr *)pHost->h_addr_list[i]);
		m_myname=szHostName;
		m_localaddr=psz;
	}
	m_myinfo=m_myname;
	m_myinfo+='@';
	m_myinfo+=m_localaddr;
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUDPprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUDPprojectDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CUDPprojectDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CUDPprojectDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strconnect;
	m_connect.GetWindowText(strconnect);
	if(strconnect=="开始聊天")
	{
		BOOL nret;
	HANDLE Thread;

	SOCKADDR_IN addr;
	addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(m_port);


	nret=udpSocket.Create(m_port,SOCK_DGRAM);   
	m_111=nret;
	if(nret==FALSE)
	{
		AfxMessageBox("建立服务器失败！");
	}
	
	
    //建立监听线程
	Thread = CreateThread(NULL,0,BindPortThread,(LPVOID)this,0,NULL);
	CloseHandle(Thread);	
    //设置控件的状态
	this->GetDlgItem(IDC_EDIT_PORT)->EnableWindow(FALSE);
	this->SetDlgItemText(IDC_CONNECT,"结束聊天");
	this->SetDlgItemText(IDC_STATIC_STATE,"    初始化成功，开始聊天");
	this->GetDlgItem(IDC_EDIT_OUTMSG)->EnableWindow(TRUE);
	m_list_msg.AddString("====>成功初始化，开始聊天<====");		
    }
	else
		
	
	{
		udpSocket.Close();
		m_list_msg.ResetContent();
		m_list_msg.AddString("====>成功退出<====");
		this->GetDlgItem(IDC_EDIT_PORT)->EnableWindow(TRUE);
	    this->SetDlgItemText(IDC_CONNECT,"开始聊天");
		this->SetDlgItemText(IDC_STATIC_STATE,"    请进行初始化设置@_@");
		this->GetDlgItem(IDC_EDIT_OUTMSG)->EnableWindow(FALSE);
		

		return;
	}
}


DWORD WINAPI CUDPprojectDlg::BindPortThread(LPVOID lpParameter)
{
	char revBuf[1000];
	CString receive;
	CUDPprojectDlg *pDlg = (CUDPprojectDlg*)lpParameter;

	while(TRUE)
	{
		int res = pDlg->udpSocket.ReceiveFrom(revBuf,sizeof(revBuf),pDlg->m_clientaddr,pDlg->m_clientport);
		if( res!=SOCKET_ERROR )
		{
			revBuf[res]=NULL;
			receive=pDlg->m_clientaddr;
			receive+="  said: ";
			if(revBuf[0]=='/')
			{
				pDlg->m_list_msg.AddString(receive);
				pDlg->DoAction(pDlg,revBuf[1]);
			}
			else 
			{
				receive+=revBuf;
				pDlg->m_list_msg.AddString(receive);
			}
		//	int i=pDlg->m_list_msg.GetCount();
		 //   pDlg->m_list_msg.SetCurSel(i-1);
		//	pDlg->m_list_msg.SetCurSel(-1);
		}
	}
}



void CUDPprojectDlg::OnSendMsg() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int res,i=0;
	CString sendmsg;
	m_ipaddr.TrimLeft();
	m_ipaddr.TrimRight();
	if(m_port<1024)
	{
		AfxMessageBox("请输入合适的端口号！");
		return;
	}
	if(m_ipaddr.IsEmpty())
	{
		AfxMessageBox("请输入正确的IP地址！");
		return;
	}
	if(m_outmsg.IsEmpty())
	{
		AfxMessageBox("不能发送空消息！");
		return;
	}
	res=udpSocket.SendTo(m_outmsg,m_outmsg.GetLength(),(UINT)m_port,m_ipaddr,0);
	if ( res==SOCKET_ERROR )
	{
		AfxMessageBox("消息发送失败！");
	}
	
	sendmsg=m_myname;
	sendmsg+=" said:";
	if(m_outmsg.GetAt(0)=='/'&&m_outmsg.GetLength()!=1)
	{
		
		m_list_msg.AddString(sendmsg);
		char string1 = m_outmsg.GetAt(1);
		DoAction(this,string1);
		
	}
	else
	{
		sendmsg+=m_outmsg;
		m_list_msg.AddString(sendmsg);
	}

	this->SetDlgItemText(IDC_EDIT_OUTMSG,"");
	this->GetDlgItem(IDC_EDIT_OUTMSG)->SetFocus();	
}

void CUDPprojectDlg::DrawNiu()
{
	for(int i=0;i<TP_niu_int;i++)
	{
		m_list_msg.AddString(TP_niu_str[i]);
	}
}

void CUDPprojectDlg::DrawPig()
{
	for(int i=0;i<TP_pig_int;i++)
	{
		m_list_msg.AddString(TP_pig_str[i]);
	}
}

void CUDPprojectDlg::DrawPhone()
{
	for(int i=0;i<TP_phone_int;i++)
	{
		m_list_msg.AddString(TP_phone_str[i]);
	}
}

void CUDPprojectDlg::DoAction(LPVOID lParam, char str)
{
	CUDPprojectDlg *pDlg = (CUDPprojectDlg*)lParam;
	switch(str)
	{
	case 'n': pDlg->DrawNiu();break;
	case 'z': pDlg->DrawPig();break;
	case 'p': pDlg->DrawPhone();break;
	case 'r': ShellExecute(NULL,"explore","C:/windows/media",NULL,NULL,SW_SHOWNORMAL);break;   
    default: pDlg->m_list_msg.AddString("该字母对应操作尚未定义!");break;

	}
}
