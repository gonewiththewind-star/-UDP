// UDPprojectDlg.h : header file
//

#if !defined(AFX_UDPPROJECTDLG_H__2CA3D252_9201_4470_A19F_1EADD9716364__INCLUDED_)
#define AFX_UDPPROJECTDLG_H__2CA3D252_9201_4470_A19F_1EADD9716364__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUDPprojectDlg dialog

class CUDPprojectDlg : public CDialog
{
// Construction
public:

	CUDPprojectDlg(CWnd* pParent = NULL);	// standard constructor
    CString m_clientaddr;
	UINT m_clientport;
// Dialog Data
	//{{AFX_DATA(CUDPprojectDlg)
	enum { IDD = IDD_UDPPROJECT_DIALOG };
	CButton	m_connect;
	CListBox m_list_msg;
	CString	m_outmsg;
	CString	m_ipaddr;
	CString	m_static_state;
	int		m_port;
	CString	m_myinfo;
	BOOL	m_111;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPprojectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUDPprojectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSendMsg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DoAction(LPVOID lParam,char str);
	void DrawPhone();
	void DrawPig();
	void DrawNiu();
    static DWORD WINAPI BindPortThread(LPVOID lpParameter);

	CString m_localaddr;
	CString m_myname;

	CAsyncSocket udpSocket;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPPROJECTDLG_H__2CA3D252_9201_4470_A19F_1EADD9716364__INCLUDED_)
