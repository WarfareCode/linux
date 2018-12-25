//AircraftMoveCtrlParams.h: interface for the CAircraftMoveCtrlParams module.
//!!HDOSE_CLASS(CAircraftMoveCtrlParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AircraftMoveCtrlParams_H)
#define AFX_AircraftMoveCtrlParams_H



//{{HDOSE_CLS_DES(CAircraftMoveCtrlParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAircraftMoveCtrlParams /*�ɻ��˶����Ʋ���*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAircraftMoveCtrlParams();
	virtual ~CAircraftMoveCtrlParams();
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

	//{{HDOSE_MEMBER_FUNCTION(CAircraftMoveCtrlParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAircraftMoveCtrlParams)
	GeoPt	m_Postion/*λ��*/;
	double	m_Course/*�����*/;
	double	m_Pitch/*������*/;
	double	m_Roll/*��ת��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
