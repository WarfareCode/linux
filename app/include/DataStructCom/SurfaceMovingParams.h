//SurfaceMovingParams.h: interface for the CSurfaceMovingParams module.
//!!HDOSE_CLASS(CSurfaceMovingParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SurfaceMovingParams_H)
#define AFX_SurfaceMovingParams_H



//{{HDOSE_CLS_DES(CSurfaceMovingParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSurfaceMovingParams /*舰艇运动参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSurfaceMovingParams();
	virtual ~CSurfaceMovingParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}

	//{{HDOSE_MEMBER_FUNCTION(CSurfaceMovingParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSurfaceMovingParams)
	GeoPt	m_Position/*位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
