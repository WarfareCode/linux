//SeekerElecAxisDirection.h: interface for the CSeekerElecAxisDirection module.
//!!HDOSE_CLASS(CSeekerElecAxisDirection,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SeekerElecAxisDirection_H)
#define AFX_SeekerElecAxisDirection_H

#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CSeekerElecAxisDirection)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSeekerElecAxisDirection /*导引头电轴方向*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSeekerElecAxisDirection();
	virtual ~CSeekerElecAxisDirection();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSeekerElecAxisAzimuth(CAzimuth3D val){m_SeekerElecAxisAzimuth=val;}
	CAzimuth3D	GetSeekerElecAxisAzimuth(){return m_SeekerElecAxisAzimuth;}

	//{{HDOSE_MEMBER_FUNCTION(CSeekerElecAxisDirection)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSeekerElecAxisDirection)
	CAzimuth3D	m_SeekerElecAxisAzimuth/*导引头电轴方位*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
