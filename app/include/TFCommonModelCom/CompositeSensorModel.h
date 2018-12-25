//CompositeSensorModel.h: interface for the CCompositeSensorModel module.
//!!HDOSE_CLASS(CCompositeSensorModel,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CompositeSensorModel_H)
#define AFX_CompositeSensorModel_H

//#include "SensorModel.h"

//{{HDOSE_CLS_DES(CCompositeSensorModel)
/*
Author:		
Version:	1.0
Descript:	����+��������������+���ֱ���
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CCompositeSensorModel /*���ϴ�����*/ : public CSensor
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CCompositeSensorModel();
	virtual ~CCompositeSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetMaxDetectDistance(){return m_MaxDetectDistance;}

	//{{HDOSE_MEMBER_FUNCTION(CCompositeSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CCompositeSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CCompositeSensorModel)
	double	m_MaxDetectDistance/*���̽����루���*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCompositeSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
