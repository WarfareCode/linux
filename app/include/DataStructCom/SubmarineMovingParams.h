//SubmarineMovingParams.h: interface for the CSubmarineMovingParams module.
//!!HDOSE_CLASS(CSubmarineMovingParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubmarineMovingParams_H)
#define AFX_SubmarineMovingParams_H



//{{HDOSE_CLS_DES(CSubmarineMovingParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSubmarineMovingParams /*潜艇运动参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSubmarineMovingParams();
	virtual ~CSubmarineMovingParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}

	//{{HDOSE_MEMBER_FUNCTION(CSubmarineMovingParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSubmarineMovingParams)
	GeoPt	m_Position/*位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
