// RadioEvt.h: interface for the CRadioEvt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RADIOEVT_H__B35ABD39_EEBF_4379_A485_8172E0A5AB88__INCLUDED_)
#define AFX_RADIOEVT_H__B35ABD39_EEBF_4379_A485_8172E0A5AB88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CGFDS.h"

class HYCGF_API CRadioEvt : public CEvt  
{
	DECLARE_CREATE;
public:
	CRadioEvt();
	virtual ~CRadioEvt();
	static void ClassInit(ClassInfo *clsinfo);

	char m_channel[32];//通道名
	double m_pos[3];//事件位置
	DWORD m_extra;
	char m_info[512];


};

#endif // !defined(AFX_RADIOEVT_H__B35ABD39_EEBF_4379_A485_8172E0A5AB88__INCLUDED_)
