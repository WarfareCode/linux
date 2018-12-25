//MoveAlongDirectionEvt.h: interface for the CMoveAlongDirectionEvt module.
//!!HDOSE_CLASS(CMoveAlongDirectionEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveAlongDirectionEvt_H)
#define AFX_MoveAlongDirectionEvt_H


//{{HDOSE_CLS_DES(CMoveAlongDirectionEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMoveAlongDirectionEvt /*按指定方位运动事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CMoveAlongDirectionEvt();
	virtual ~CMoveAlongDirectionEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetAssignedDirection(double val){m_AssignedDirection=val;}
	double	GetAssignedDirection(){return m_AssignedDirection;}
	void	SetAssignedVel(double val){m_AssignedVel=val;}
	double	GetAssignedVel(){return m_AssignedVel;}

	//{{HDOSE_MEMBER_FUNCTION(CMoveAlongDirectionEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveAlongDirectionEvt)
	double	m_AssignedDirection/*指定方位（角度，正北为0，-180～180度）*/;
	double	m_AssignedVel/*速度*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
