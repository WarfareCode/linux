//Country.h: interface for the CCountry module.
//!!HDOSE_CLASS(CCountry,CNode)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Communication.h"
class CCountry : public CNode 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
	 
public:
	int m_periodicMessage;
	double ms_growthRate;
	//{{HDOSE_ATTRIBUTE(CCountry)
	double	m_Population	/*参数1*/; 
	char*	m_Name	/*参数2*/; 
	//}}HDOSE_ATTRIBUTE

	CCountry();
	virtual ~CCountry();

	static	void ClassInit(ClassInfo *clsinfo);

	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual	void Simulation(double lasttime);
	virtual	void Output();

private:
	
	
	//{{HDOSE_EVENT_HANDLER(CCountry)
	void	OnCCommunication(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
};

