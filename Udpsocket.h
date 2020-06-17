#if !defined(AFX_UDPSOCKET_H__6B8D7859_0A6C_4AF4_86C1_767F8C3C5D5D__INCLUDED_)
#define AFX_UDPSOCKET_H__6B8D7859_0A6C_4AF4_86C1_767F8C3C5D5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Udpsocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CUdpsocket command target

class CUdpsocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CUdpsocket();
	virtual ~CUdpsocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUdpsocket)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CUdpsocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPSOCKET_H__6B8D7859_0A6C_4AF4_86C1_767F8C3C5D5D__INCLUDED_)
