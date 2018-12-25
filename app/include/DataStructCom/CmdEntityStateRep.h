//CmdEntityStateRep.h: interface for the CCmdEntityStateRep module.
//!!HDOSE_CLASS(CCmdEntityStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CmdEntityStateRep_H)
#define AFX_CmdEntityStateRep_H

#include "ASMRouteData.h"

//{{HDOSE_CLS_DES(CCmdEntityStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCmdEntityStateRep /*ָ��ʵ��״̬��*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CCmdEntityStateRep();
	virtual ~CCmdEntityStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetIsAutoPlan(int val){m_IsAutoPlan=val;}
	int	GetIsAutoPlan(){return m_IsAutoPlan;}
// 	void	SetASMPlanData(CASMRouteData val[]){
// 		for(int i=0;i<30;i++)
// 			m_ASMPlanData[i]=val[i];}
// 	CASMRouteData*	GetASMPlanData(){return m_ASMPlanData;}
	void	SetASMPlanDataCount(int val){m_ASMPlanDataCount=val;}
	int	GetASMPlanDataCount(){return m_ASMPlanDataCount;}
	void	SetGroupIntptStrategy(int val){m_GroupIntptStrategy=val;}
	int	GetGroupIntptStrategy(){return m_GroupIntptStrategy;}
	void	SetisAutoGroupAntiAir(int val){m_isAutoGroupAntiAir=val;}
	int	GetisAutoGroupAntiAir(){return m_isAutoGroupAntiAir;}
	void	SetisEWPlaneSupport(int val){m_isEWPlaneSupport=val;}
	int	GetisEWPlaneSupport(){return m_isEWPlaneSupport;}

	void	SetASMCoopAttackMode(int val){m_ASMCoopAttackMode=val;}
	int	GetASMCoopAttackMode(){return m_ASMCoopAttackMode;}

	void	SetRoutePlanTime(long val){m_RoutePlanTime=val;}
	long	GetRoutePlanTime(){return m_RoutePlanTime;}
	void	Set1stLaunchTime(long val){m_1stLaunchTime=val;}
	long	Get1stLaunchTime(){return m_1stLaunchTime;}
	void	SetRoutePlanMode(int val){m_RoutePlanMode=val;}
	int	GetRoutePlanMode(){return m_RoutePlanMode;}
	void	SetBatchCount(int val){m_BatchCount=val;}
	int	GetBatchCount(){return m_BatchCount;}
	void	SetBatchInterval(double val){m_BatchInterval=val;}
	double	GetBatchInterval(){return m_BatchInterval;}

	//{{HDOSE_MEMBER_FUNCTION(CCmdEntityStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CCmdEntityStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCmdEntityStateRep)
	int	m_IsAutoPlan/*�Ƿ��Զ����з���������·�滯��Ĭ��Ϊ-1�������壩,0-�˹��滮��1-�Զ��滮��2-���ո�����ʱ�̹滮��·��*/;
	bool m_AutoTime;//�Զ�ʱ��/�˹�ʱ��0-�˹�ʱ��--����Ҫ�����κμ����ˣ���ʱ���䵼�����ɣ�1-�Զ��������򣬲�ȷ������ʱ�̣�
	//CASMRouteData	m_ASMPlanData[10]/*���������滮��Ϣ(���30��)*/;
	int	m_ASMPlanDataCount/*���������滮��Ϣ����*/;

	int	m_GroupIntptStrategy/*��������ӵķ������ز���*/;
	int	m_isAutoGroupAntiAir/*�������Ƿ����Զ����գ�Ĭ��Ϊ-1,0��1�ǣ�*/;
	int m_isEWPlaneSupport/*�������Ƿ���Ԥ����֧��(-1��Ч��0��1��)*/; 

	// 2015/10/02����,��ʱ
	//char m_ScnName[128]; /*��¼���붨������-Ϊ�����붨���ƽ����Զ���¼�洢�붨����*/
	int	m_isAccompanySuppress;/*�췽�Ƿ��а���ѹ�ƣ�0��1��*/

	// 2016/02/18����,�������ֲ�ͬ��ͻ����ʽ��
	// ͬʱ����--���е���ͬʱ����Ŀ��
	// ͬʱͻ��--���е���ͬʱ������Եı�����Ȧ������ݸ��Եĵ����߶ȣ��ֱ�ͬʱ������Եı�����Ȧ
	int	m_ASMCoopAttackMode/*��������Эͬ������ʽ(1-ͬʱ����,2-ͬʱͻ��)*/;
	int m_AttackSingleOrGroup;/*�����������Ǳ��,1-����,2-���*/

	// 2017/02/08,������ʼ���к�·�滮��ʱ��(s)�͵�һö������������ʱ��(s)
	double	m_RoutePlanTime;	//��ʼ���к�·�滮��ʱ��(s)
	double	m_1stLaunchTime;	//��һö������������ʱ��(s)
	// 20171030
	int	m_GroupAAMLaunchMode; // ��ӷ��յ�������ģʽ��Ĭ��0-�������䡢1-��������ģʽ��2-����-�۲�-����ģʽ
	// 20180301
	int	m_RoutePlanMode/*��·�滮Ŀ���ѡ��ʽ��-1��Ĭ��ֵ��˵���˲�����Ч�������ֵ>=0��ʾҪʹ��ȫ�ֵĹ滮��ʽ�滮���к�·������ÿ����·�Լ��ķ�ʽ�滮��·����0-��ǰ��滮��1-ǰ�õ�滮��2-��3-*/;
	int	m_BatchCount/*��������*/;
	double	m_BatchInterval/*���������������μ��ʱ�䣬s*/;

	//}}HDOSE_ATTRIBUTE


	CASMRouteData m_routPlanData[200];	// ������·��������
	int m_routPlanDataCount;	// ������·����
};

#endif
