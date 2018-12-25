//PlatformModel.h: interface for the CPlatformModel module.
//!!HDOSE_CLASS(CPlatformModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_PlatformModel_H)
#define AFX_PlatformModel_H


//{{HDOSE_CLS_DES(CPlatformModel)
/*
Author:		
Version:	1.0
Descript:	主要负责机动、目标特性模拟
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CPlatformModel /*平台*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CPlatformModel();
	virtual ~CPlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CPlatformModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CPlatformModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CPlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CPlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
