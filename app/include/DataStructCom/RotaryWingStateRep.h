//RotaryWingStateRep.h: interface for the CRotaryWingStateRep module.
//!!HDOSE_CLASS(CRotaryWingStateRep,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RotaryWingStateRep_H)
#define AFX_RotaryWingStateRep_H

//{{HDOSE_CLS_DES(CRotaryWingStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CRotaryWingStateRep /*旋转翼飞机状态池*/ : public CStateRepository 
{
	DECLARE_CREATE;
public:
	CRotaryWingStateRep();
	virtual ~CRotaryWingStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetTorpedoCount(long val){m_TorpedoCount=val;}
	long	GetTorpedoCount(){return m_TorpedoCount;}
	void	SetTorpedoType(long val){m_TorpedoType=val;}
	long	GetTorpedoType(){return m_TorpedoType;}

	//{{HDOSE_MEMBER_FUNCTION(CRotaryWingStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CRotaryWingStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRotaryWingStateRep)
	long	m_TorpedoCount/*鱼雷数量*/;
	long	m_TorpedoType/*鱼雷类型*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
