//CreateLineEntityEvt.h: interface for the CCreateLineEntityEvt module.
//!!HDOSE_CLASS(CCreateLineEntityEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateLineEntityEvt_H)
#define AFX_CreateLineEntityEvt_H



//{{HDOSE_CLS_DES(CCreateLineEntityEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateLineEntityEvt /*创建线控制对象实体*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCreateLineEntityEvt();
	virtual ~CCreateLineEntityEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	//char*	GetEntityName(){return m_EntityName;}
	//void	SetEntityClassName(char* val){strcpy(m_EntityClassName,val);}
	//char*	GetEntityClassName(){return m_EntityClassName;}
	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetEntityClassName(char* val){SetValueString("EntityClassName",val);}
	char*	GetEntityClassName(){return GetValueString("EntityClassName");}
	void	SetPoints(GeoPt val[10]){
		for(int i=0;i<10;i++)
			m_Points[i]=val[i];
	}
	GeoPt*	GetPoints(){return m_Points;}
	void	SetPointsCount(long val){m_PointsCount=val;}
	long	GetPointsCount(){return m_PointsCount;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateLineEntityEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateLineEntityEvt)
	char*	m_EntityName/*线对象名称*/;
	char*	m_EntityClassName/*线对象属性类名称（CLineControlObject）*/;
	GeoPt	m_Points[10]/*位置点数据（10个点的数组）*/;
	long	m_PointsCount/*位置点的个数*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
