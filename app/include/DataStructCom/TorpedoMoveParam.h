//TorpedoMoveParam.h: interface for the CTorpedoMoveParam module.
//!!HDOSE_CLASS(CTorpedoMoveParam,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoMoveParam_H)
#define AFX_TorpedoMoveParam_H



//{{HDOSE_CLS_DES(CTorpedoMoveParam)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoMoveParam /*鱼雷运动参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTorpedoMoveParam();
	virtual ~CTorpedoMoveParam();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoMoveParam)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoMoveParam)
	GeoPt	m_Position/*位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
