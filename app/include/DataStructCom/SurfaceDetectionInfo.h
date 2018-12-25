//SurfaceDetectionInfo.h: interface for the CSurfaceDetectionInfo module.
//!!HDOSE_CLASS(CSurfaceDetectionInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SurfaceDetectionInfo_H)
#define AFX_SurfaceDetectionInfo_H

#include "SensorData.h"

//{{HDOSE_CLS_DES(CSurfaceDetectionInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSurfaceDetectionInfo /*��ͧ̽����Ϣ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSurfaceDetectionInfo();
	virtual ~CSurfaceDetectionInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetData(CSensorData val[100]){
		for(int i=0;i<100;i++)
			m_TargetData[i]=val[i];
	}
	CSensorData*	GetTargetData(){return m_TargetData;}
	void	SetTargetDataCount(long val){m_TargetDataCount=val;}
	long	GetTargetDataCount(){return m_TargetDataCount;}
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}
	//{{HDOSE_MEMBER_FUNCTION(CSurfaceDetectionInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSurfaceDetectionInfo)
	CSensorData	m_TargetData[100]/*Ŀ������(10��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_TargetDataCount/*Ŀ�����ݸ��������10����*/;
	long	m_ForceType/*��������ʶ��0����1�죩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
