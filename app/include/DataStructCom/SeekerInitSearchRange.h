//SeekerInitSearchRange.h: interface for the CSeekerInitSearchRange module.
//!!HDOSE_CLASS(CSeekerInitSearchRange,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SeekerInitSearchRange_H)
#define AFX_SeekerInitSearchRange_H


//{{HDOSE_CLS_DES(CSeekerInitSearchRange)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSeekerInitSearchRange /*����ͷ��ʼ������Χ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSeekerInitSearchRange();
	virtual ~CSeekerInitSearchRange();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSeekerDistSearchNear(double val){m_SeekerDistSearchNear=val;}
	double	GetSeekerDistSearchNear(){return m_SeekerDistSearchNear;}
	void	SetSeekerDistSearchFar(double val){m_SeekerDistSearchFar=val;}
	double	GetSeekerDistSearchFar(){return m_SeekerDistSearchFar;}
	void	SetSeekerAngleSearchLeft(double val){m_SeekerAngleSearchLeft=val;}
	double	GetSeekerAngleSearchLeft(){return m_SeekerAngleSearchLeft;}
	void	SetSeekerAngleSearchRight(double val){m_SeekerAngleSearchRight=val;}
	double	GetSeekerAngleSearchRight(){return m_SeekerAngleSearchRight;}

	//{{HDOSE_MEMBER_FUNCTION(CSeekerInitSearchRange)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSeekerInitSearchRange)
	double	m_SeekerDistSearchNear/*����ͷ������������*/;
	double	m_SeekerDistSearchFar/*����ͷ��������Զ��*/;
	double	m_SeekerAngleSearchLeft/*����ͷ�Ƕ���������*/;
	double	m_SeekerAngleSearchRight/*����ͷ�Ƕ������Ҽ���*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
