//ScnProfile.h: interface for the CScnProfile module.
//!!HDOSE_CLASS(CScnProfile,CLink)
//////////////////////////////////////////////////////////////////////

/// **********************************
/* Note��20161215��xks
	��ͷ�ļ��������붨��Ҫ���붨���в�����
	�����붨���ơ���ʼ����ʱ�䡢���������������ȡ�
	
	0. ԭ���ϣ�ֻҪʹ����Hycgf���ÿһ���붨�ļ�����������������Ķ���
	1. ��������ģ�����ʹ�����е����ݣ����ȼ��SetSimPara�Ƿ�Ϊ�棨1�������ʾ��������Ѿ���������Ϊ���µģ�
	2. ����SetSimPara����Ŀ�����ڣ�����ǵ����붨���ζ������У��붨�����Ѿ���¼��������в�����
		������Ƕ���붨���򵥸��붨���������ʱ��ͨ���ⲿ���ƽӿڴ���������в���ʱ������ͨ��FedParameter
		�����ݵģ����������˸����ⲿ�����޸��붨��������в����Ĺ�����
		Ϊ�˼�˶���ͨ�ã��ر�����SetSimPara��顣
	3. ���������ڼ䣬����ģ�;��Ӵ����ȡ��Ҫ�ķ������в�����
	3. Ϊ��֤�����������У������õ���Hycgf��ʱ���м���Sim�ļ���Parameters������д�룺
		<Parameter Name="ExternScnParaSet" Value="0"/>
		����Ϊ���Ƿ����ⲿ�������в�������붨��������в������˴���ValueĬ��Ϊ0���񣩡�
	4. ������Ҳ��¼�˺�̨ģ�͵ķ���ʱ�䣨0��ʼ�����ʱ�䣬�룩�����ڷ������Կضˣ�����ǰ��̨ʱ��һ�¡�
*/
/// **********************

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ScnProfile_H)
#define AFX_ScnProfile_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CScnProfile)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CScnProfile /*�붨��Ҫ*/ : public CLink 
{
	DECLARE_CREATE;
public:
	CScnProfile();
	virtual ~CScnProfile();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual void OnSetParameter(char *name,char *value);
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetScnName(char* val){strcpy(m_ScnName,val);}
	char*	GetScnName(){return m_ScnName;}
	void	SetOutLine(char* val){SetValueString("OutLine",val);}
	char*	GetOutLine(){return GetValueString("OutLine");}
	void	SetScnStartTime(EpochTimeStruct val){m_ScnStartTime=val;}
	EpochTimeStruct	GetScnStartTime(){return m_ScnStartTime;}
	void	SetScnEndTime(EpochTimeStruct val){m_ScnEndTime=val;}
	EpochTimeStruct	GetScnEndTime(){return m_ScnEndTime;}
// �ֶ��޸�
// 	void	SetSimAreaRange(GeoPt4 val){m_SimAreaRange=val;}
// 	GeoPt4	GetSimAreaRange(){return m_SimAreaRange;}
	void	SetSimAreaRange(char* ptStr)
	{
		this->SetValueString("SimAreaRange",ptStr);
	}
	void	SetSimAreaRange(GeoPtList& ptList)
	{
		String ptStr = GeoPtList2GeoPtStr(ptList);
		this->SetValueString("SimAreaRange",ptStr.GetBuffer(ptStr.GetLength()));
	}
	void	GetSimAreaRange(GeoPtList& ptList)
	{
		GeoPtStr2GeoPtList(ptList, m_SimAreaRange);
	}
	char* GetSimAreaRange(){return GetValueString("SimAreaRange");}

	void	SetRelativeSimTime(double val){m_RelativeSimTime=val;}
	double	GetRelativeSimTime(){return m_RelativeSimTime;}
	void	SetUseRadomSeed(long val){m_UseRadomSeed=val;}
	long	GetUseRadomSeed(){return m_UseRadomSeed;}
	void	SetRadomSeed(long val){m_RadomSeed=val;}
	long	GetRadomSeed(){return m_RadomSeed;}
	void	SetT(double val){m_T=val;}
	double	GetT(){return m_T;}
	void	SetSimNetworkComm(long val){m_SimNetworkComm=val;}
	long	GetSimNetworkComm(){return m_SimNetworkComm;}

	//{{HDOSE_MEMBER_FUNCTION(CScnProfile)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CScnProfile)
	char	m_ScnName[MAX_CHARLEN]/*�붨����*/;
	char*	m_OutLine/*�����������˲�����ע�ᣬ�Ҵ˲���δ���붨�ļ��ж�ȡ��Ӧ����*/;
	EpochTimeStruct	m_ScnStartTime/*���濪ʼ��Ԫʱ��*/;
	EpochTimeStruct	m_ScnEndTime/*���������Ԫʱ��*/;
	long	m_ScnRunN/*ͬһ���붨����ĵڼ���*/;
	char*	m_SimAreaRange/*��������,��������*/;
	double	m_RelativeSimTime/*��Է���ʱ��(��̨����ʱ��)*/;
	long	m_UseRadomSeed/*�Ƿ�ʹ�����������,Ĭ��0*/;
	long	m_RadomSeed/*���������,���Ǹ�������,Ĭ��-1*/;
	double	m_T/*Tʱ��,Ĭ��0.0*/;
	long	m_SimNetworkComm/*�Ƿ����ʵ��������ͨ��,Ĭ��0*/;

	//}}HDOSE_ATTRIBUTE

	String tempPoint;	// ��ʱ�洢WayPoint
	bool SetSimPara; // �Ƿ������˷������
};

/// ��ȡ�붨��ʼʱ��(�ꡢ�¡��ա�ʱ���֡���)���붨����ʱ��(�ꡢ�¡��ա�ʱ���֡���)����ǰ����ʱ��(s)
HYCGF_API bool GetBackScnTime(EpochTimeStruct &scnStartTm, EpochTimeStruct &scnEndTm, double &backSimTm);
/// ��ȡ���붨�����ƣ��ɹ�����ture�����ɹ�����false�����ڷ��濪ʼ���ڲ��Ż��¼�붨���ƣ����Կ�ͨ����ε��ô˺�����õ���ȷ���붨���ƣ�
HYCGF_API bool GetScnName(char* scnName);

#endif
