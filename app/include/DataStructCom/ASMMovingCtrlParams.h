//ASMMovingCtrlParams.h: interface for the CASMMovingCtrlParams module.
//!!HDOSE_CLASS(CASMMovingCtrlParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMMovingCtrlParams_H)
#define AFX_ASMMovingCtrlParams_H



//{{HDOSE_CLS_DES(CASMMovingCtrlParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CASMMovingCtrlParams /*反舰导弹运动控制参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CASMMovingCtrlParams();
	virtual ~CASMMovingCtrlParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPostion(GeoPt val){m_Postion=val;}
	GeoPt	GetPostion(){return m_Postion;}
	void	SetCourse(double val){m_Course=val;}
	double	GetCourse(){return m_Course;}
	void	SetPitch(double val){m_Pitch=val;}
	double	GetPitch(){return m_Pitch;}
	void	SetRoll(double val){m_Roll=val;}
	double	GetRoll(){return m_Roll;}
	void	SetMoveOrderType(long val){m_MoveOrderType=val;}
	long	GetMoveOrderType(){return m_MoveOrderType;}

	//{{HDOSE_MEMBER_FUNCTION(CASMMovingCtrlParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CASMMovingCtrlParams)
	GeoPt	m_Postion/*位置*/;
	double	m_Course/*航向角*/;
	double	m_Pitch/*俯仰角*/;
	double	m_Roll/*滚转角*/;
	long	m_MoveOrderType/*导弹运动指令（-1沿航路运动，0航战开，1航战关，2高战，3俯冲）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
