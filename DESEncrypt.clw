; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDESEncryptApp
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DESEncrypt.h"
LastPage=0

ClassCount=7
Class1=CDESEncryptApp
Class2=CDESEncryptDoc
Class3=CDESEncryptView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_DLGDESFILE
Class5=CAboutDlg
Class6=DESFileEncrypt
Resource3=IDD_ABOUTBOX
Class7=DesStringEncrypt
Resource4=IDD_DLGDESSTING

[CLS:CDESEncryptApp]
Type=0
HeaderFile=DESEncrypt.h
ImplementationFile=DESEncrypt.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CDESEncryptApp

[CLS:CDESEncryptDoc]
Type=0
HeaderFile=DESEncryptDoc.h
ImplementationFile=DESEncryptDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_DESSTRING

[CLS:CDESEncryptView]
Type=0
HeaderFile=DESEncryptView.h
ImplementationFile=DESEncryptView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=DESEncrypt.cpp
ImplementationFile=DESEncrypt.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_DESFILE
Command3=ID_DESSTRING
Command4=ID_VIEW_TOOLBAR
Command5=ID_VIEW_STATUS_BAR
Command6=ID_APP_ABOUT
CommandCount=6

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DLGDESFILE]
Type=1
Class=DESFileEncrypt
ControlCount=15
Control1=IDC_return,button,1342177280
Control2=IDC_Input,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_Output,edit,1350631552
Control6=IDC_STATIC,button,1342177287
Control7=IDC_RSASTATICKEY,static,1342308352
Control8=IDC_DesKey1,edit,1350631584
Control9=IDC_RSASTATICMOD,static,1342308352
Control10=IDC_DesKey2,edit,1350631584
Control11=IDC_Run,button,1342242816
Control12=IDC_Browse,button,1342242816
Control13=IDC_STATIC,button,1342177287
Control14=IDC_OutFolder,button,1342242816
Control15=IDC_DESSTATICNOTE,static,1342308352

[CLS:DESFileEncrypt]
Type=0
HeaderFile=DESFileEncrypt.h
ImplementationFile=DESFileEncrypt.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_Input
VirtualFilter=dWC

[DLG:IDD_DLGDESSTING]
Type=1
Class=DesStringEncrypt
ControlCount=16
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIOJIAMI,button,1342177289
Control3=IDC_RADIOJIEMI,button,1342177289
Control4=IDC_BTNRun,button,1342242816
Control5=IDC_BTNReturn,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDITINPUT,edit,1350635716
Control10=IDC_EDITOUTPUT,edit,1350635716
Control11=IDC_STATIC,button,1342177287
Control12=IDC_RSASTATICKEY,static,1342308352
Control13=IDC_DesKey1,edit,1350631584
Control14=IDC_RSASTATICMOD,static,1342308352
Control15=IDC_DesKey2,edit,1350631584
Control16=IDC_DESSTATICNOTE,static,1342308352

[CLS:DesStringEncrypt]
Type=0
HeaderFile=DesStringEncrypt.h
ImplementationFile=DesStringEncrypt.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=DesStringEncrypt

