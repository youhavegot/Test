
// MFCA-0413-1.h : MFCA-0413-1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFCA04131App:
// 有关此类的实现，请参阅 MFCA-0413-1.cpp
//

class CMFCA04131App : public CWinApp
{
public:
	CMFCA04131App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCA04131App theApp;
