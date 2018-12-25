//VehicleMoveCtrlParams.h: interface for the CVehicleMoveCtrlParams module.
//!!HDOSE_CLASS(CVehicleMoveCtrlParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_VehicleMoveCtrlParams_H)
#define AFX_VehicleMoveCtrlParams_H



//{{HDOSE_CLS_DES(CVehicleMoveCtrlParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CVehicleMoveCtrlParams /*车辆运动控制参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CVehicleMoveCtrlParams();
	virtual ~CVehicleMoveCtrlParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPostion(GeoPt val){m_Postion=val;}
	GeoPt	GetPostion(){return m_Postion;}

	//{{HDOSE_MEMBER_FUNCTION(CVehicleMoveCtrlParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CVehicleMoveCtrlParams)
	GeoPt	m_Postion/*位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
