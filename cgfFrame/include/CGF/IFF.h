//IFF.h: interface for the CIFF module.
//!!HDOSE_CLASS(CIFF,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_IFF_H)
#define AFX_IFF_H

#include "Sensor.h"

//{{HDOSE_CLS_DES(CIFF)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CIFF /*µÐÎÒÊ¶±ðÆ÷*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CIFF();
	virtual ~CIFF();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CIFF)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CIFF)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CIFF)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CIFF)
	//}}HDOSE_ATTRIBUTE
};

#endif
