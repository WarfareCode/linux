//ExplosionEvent.h: interface for the CExplosionEvent module.
//!!HDOSE_CLASS(CExplosionEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ExplosionEvent_H)
#define AFX_ExplosionEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CExplosionEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CExplosionEvent /*��ը�¼�(HYCGF)*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CExplosionEvent();
	virtual ~CExplosionEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLocationType(long val){m_LocationType=val;}
	long	GetLocationType(){return m_LocationType;}
	void	SetRefrenceObjId(long val){m_RefrenceObjId=val;}
	long	GetRefrenceObjId(){return m_RefrenceObjId;}
	void	SetEquivalent(double val){m_Equivalent=val;}
	double	GetEquivalent(){return m_Equivalent;}
	void	SetLocation(GeoPt val){m_Location=val;}
	GeoPt	GetLocation(){return m_Location;}
	void	SetHittedObjId(long val){m_HittedObjId=val;}
	long	GetHittedObjId(){return m_HittedObjId;}
	void	SetLchPltObjId(long val){m_LchPltObjId=val;}
	long	GetLchPltObjId(){return m_LchPltObjId;}
	void	SetRefrenceObjType(DtEntityType val){m_RefrenceObjType=val;}
	DtEntityType	GetRefrenceObjType(){return m_RefrenceObjType;}

	//{{HDOSE_MEMBER_FUNCTION(CExplosionEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CExplosionEvent)
	long	m_LocationType/*λ�����ͣ�1-���λ�ú�2-����λ�ã�*/;
	long	m_RefrenceObjId/*���գ���ը��Ŀ��Id*/;
	double	m_Equivalent/*��ը����*/;
	GeoPt	m_Location/*��ըλ��*/;
	long m_HittedObjId/*������Ŀ��Id����Ҫʱ��д*/;
	long m_LchPltObjId/*����ƽ̨����Id�����������ҩ*/;
	DtEntityType m_RefrenceObjType/*���գ���ը��Ŀ������*/;
	//}}HDOSE_ATTRIBUTE
};

// locType - λ������
// refId - �ο�Ŀ��id
// equivalent - ����
// loc-λ��
// refobjtype-�ο�Ŀ������
// hittedId - ����Ŀ��id��Ĭ��0
// lchPltId - ����ƽ̨����id, ���������ҩ
// srcid - �����¼��Ķ���id��Ĭ��0
int HYCGF_API SendExplosionEvt(long locType, long refId, double equivalent, GeoPt loc, DtEntityType refobjtype, long hittedId = 0,  long lchPltId = 0, int srcid = 0);

#endif
