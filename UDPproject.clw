; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUDPprojectDlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "udpproject.h"
LastPage=0

ClassCount=4
Class1=CUDPprojectApp
Class2=CAboutDlg
Class3=CUDPprojectDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CUdpsocket
Resource2=IDD_UDPPROJECT_DIALOG

[CLS:CUDPprojectApp]
Type=0
BaseClass=CWinApp
HeaderFile=UDPproject.h
ImplementationFile=UDPproject.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=UDPprojectDlg.cpp
ImplementationFile=UDPprojectDlg.cpp

[CLS:CUDPprojectDlg]
Type=0
BaseClass=CDialog
HeaderFile=UDPprojectDlg.h
ImplementationFile=UDPprojectDlg.cpp
LastObject=IDC_EDIT1
Filter=D
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_UDPPROJECT_DIALOG]
Type=1
Class=CUDPprojectDlg
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDC_EDIT_OUTMSG,edit,1350631428
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342178055
Control7=IDC_STATIC_MYINFO,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_PORT,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CONNECT,button,1342242816
Control12=IDC_LIST_MSG,listbox,1353793793
Control13=IDC_STATIC_STATE,static,1342308352
Control14=IDC_SET_IPADDR,edit,1350631553
Control15=IDC_EDIT1,edit,1350631552

[CLS:CUdpsocket]
Type=0
HeaderFile=Udpsocket.h
ImplementationFile=Udpsocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CUdpsocket

