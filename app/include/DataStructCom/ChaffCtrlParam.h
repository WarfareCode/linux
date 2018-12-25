//ChaffCtrlParam.h: interface for the CChaffCtrlParam module.
//!!HDOSE_CLASS(CChaffCtrlParam,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ChaffCtrlParam_H)
#define AFX_ChaffCtrlParam_H



//{{HDOSE_CLS_DES(CChaffCtrlParam)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChaffCtrlParam /*箔条云控制参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CChaffCtrlParam();
	virtual ~CChaffCtrlParam();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}

	//{{HDOSE_MEMBER_FUNCTION(CChaffCtrlParam)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CChaffCtrlParam)
	GeoPt	m_Position/*位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
