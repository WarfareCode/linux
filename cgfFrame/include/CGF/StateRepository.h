//StateRepository.h: interface for the CStateRepository module.
//!!HDOSE_CLASS(CStateRepository,CNode)
//////////////////////////////////////////////////////////////////////

// Note: 1.---
// xks,��ʱ��m_OpdExtra1��ΪĬ�ϵ�rcsֵ����������
// ��״̬����m_extra_double1��Ϊ��ʱrcs�����������붨�ļ�����д��Ҳ����Ĭ��ֵ
// �����ʱ�򣬶��߶������ã�������Ĭ��ֵm_OpdExtra1��
// Note: 2.---
// xks,m_OpdEntityTypeΪĬ�ϵ�ʵ�������룬
// ��m_EntityType����m_OpdEntityType��ֵ��ȥ�ģ��ǿɶ��ķ����ı�����
// ͨ�����������붨�ļ����޸�m_EntityType��


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_StateRepository_H)
#define AFX_StateRepository_H

#include "RCSDataStruct.h"
#include "InfraredDataStruct.h"

//{{HDOSE_CLS_DES(CStateRepository)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CStateRepository /*ʵ��״̬��*/: public CNode  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CStateRepository();
	virtual ~CStateRepository();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	virtual void SetValueString(char *att_name,char* pstr);
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	// �õ�ʵ�����
	CNode*	GetEntity()
	{
		return (CNode*)m_parent;
	}

	// ��������ʵ�������ϵͳģ�ͣ�20161218
	// ֻ��ʵ��ģ���п��Ե���
	// input��CObjList�������ͣ�����
	// out�����ҵ���ģ�͸���������CObjList����
	virtual int	LookupEntWeaponMounts(CObjList& wmList)
	{
		int count = 0;	// ���ҵ���ģ�͸���
		wmList.RemoveAll();

		POSITION pos = GetEntity()->m_agtlist.GetHeadPosition();
		while(pos)
		{
			CObj* pItem=(CObj*)GetEntity()->m_agtlist.GetNext(pos);
			if(pItem->IsDrivedFrom("CWeaponMountModel"))
			{
				wmList.AddTail(pItem);
				count++;
			}
		}

		return count;
	}

public:
	bool m_bInitPermit;
	long m_oldId;


	//�����������ȡ����
	void	SetSide(long val){m_Side=val;}
	long	GetSide(){return m_Side;}
	void	SetCountry(long val){m_Country=val;}
	long	GetCountry(){return m_Country;}
	void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	char*	GetEntityName(){return m_EntityName;}

	void	SetEntityType(DtEntityType val){m_EntityType=val;}
	DtEntityType	GetEntityType(){return m_EntityType;}
	void	SetMarking(char* val){strcpy(m_Marking,val);}
	char*	GetMarking(){return m_Marking;}

	void	SetLevel(long val){m_Level=val;}
	long	GetLevel(){return m_Level;}
	void	SetSuperior(char* val){strcpy(m_Superior,val);}
	char*	GetSuperior(){return m_Superior;}

	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}
	void	SetVelocityVector(Vec3 val){m_VelocityVector=val;}
	Vec3	GetVelocityVector(){return m_VelocityVector;}
	void	SetVelocity(double val){m_Velocity=val;}
	double	GetVelocity(){return m_Velocity;}

	void	SetHeading(double val){m_Heading=val;}
	double	GetHeading(){return m_Heading;}
	void	SetPitch(double val){m_Pitch=val;}
	double	GetPitch(){return m_Pitch;}
	void	SetRoll(double val){m_Roll=val;}
	double	GetRoll(){return m_Roll;}

	void	SetAttitude(Vec3 val){m_Attitude=val;}
	Vec3	GetAttitude(){return m_Attitude;}

	void	SetSurvivalState(long val){m_SurvivalState=val;}
	long	GetSurvivalState(){return m_SurvivalState;}

	void	SetRCS(char* val){SetValueString("RCS",val);}
	void	SetRCS(CRCSDataStructList& list)
	{
		String RcsStr = RCSDataList2RCSDataStr(list);
		SetValueString("RCS",RcsStr.GetBuffer(RcsStr.GetLength()));
	}
	void	GetRCS(CRCSDataStructList& RcsList)
	{
		RCSDataStr2RCSDataList(RcsList, m_RCS);
	}
	char* GetRCS(){return GetValueString("RCS");}

	void	SetInfrared(char* val){SetValueString("Infrared",val);}
	char*	GetInfrared(){return GetValueString("Infrared");}
	void	SetAcoustic(char* val){SetValueString("Acoustic",val);}
	char*	GetAcoustic(){return GetValueString("Acoustic");}

	void	SetReportToSuperior(long val){m_ReportToSuperior=val;}
	long	GetReportToSuperior(){return m_ReportToSuperior;}
	void	SetInformToSubordinates(long val){m_InformToSubordinates=val;}
	long	GetInformToSubordinates(){return m_InformToSubordinates;}
	void	SetInformationReleaseCycle(double val){m_InformationReleaseCycle=val;}
	double	GetInformationReleaseCycle(){return m_InformationReleaseCycle;}

	void	SetEmbarkation(long val){m_Embarkation=val;}
	long	GetEmbarkation(){return m_Embarkation;}
	void	SetEmbarkedEntityName(char* val){SetValueString("EmbarkedEntityName",val);}
	char*	GetEmbarkedEntityName(){return GetValueString("EmbarkedEntityName");}

	void	SetJoinCommNetwork(long val){m_JoinCommNetwork=val;}
	long	GetJoinCommNetwork(){return m_JoinCommNetwork;}
	void	SetCommNetworkName(char* val){SetValueString("CommNetworkName",val);}
	char*	GetCommNetworkName(){return GetValueString("CommNetworkName");}

	void	SetExEntityId(long val){m_ExEntityId=val;}
	long	GetExEntityId(){return m_ExEntityId;}
	void	SetExEntityName(char* val){SetValueString("ExEntityName",val);}
	char*	GetExEntityName(){return GetValueString("ExEntityName");}
	void	SetExEntityDomain(long val){m_ExEntityDomain=val;}
	long	GetExEntityDomain(){return m_ExEntityDomain;}
	void	SetExPlatFormType(long val){m_ExPlatFormType=val;}
	long	GetExPlatFormType(){return m_ExPlatFormType;}

	void	SetDim1_DoublePara(char* val){SetValueString("Dim1_DoublePara",val);}
	char*	GetDim1_DoublePara(){return GetValueString("Dim1_DoublePara");}
	void	SetDim2_DoublePara(char* val){SetValueString("Dim2_DoublePara",val);}
	char*	GetDim2_DoublePara(){return GetValueString("Dim2_DoublePara");}

	void	Setextra_long1(long val){m_extra_long1=val;}
	long	Getextra_long1(){return m_extra_long1;}
	void	Setextra_long2(long val){m_extra_long2=val;}
	long	Getextra_long2(){return m_extra_long2;}
	void	Setextra_long3(long val){m_extra_long3=val;}
	long	Getextra_long3(){return m_extra_long3;}
	void	Setextra_long4(long val){m_extra_long4=val;}
	long	Getextra_long4(){return m_extra_long4;}

	void	Setextra_double1(double val){m_extra_double1=val;}
	double	Getextra_double1(){return m_extra_double1;}
	void	Setextra_double2(double val){m_extra_double2=val;}
	double	Getextra_double2(){return m_extra_double2;}
	void	Setextra_double3(double val){m_extra_double3=val;}
	double	Getextra_double3(){return m_extra_double3;}
	void	Setextra_double4(double val){m_extra_double4=val;}
	double	Getextra_double4(){return m_extra_double4;}
	void	Setextra_double5(double val){m_extra_double5=val;}
	double	Getextra_double5(){return m_extra_double5;}
	void	Setextra_double6(double val){m_extra_double6=val;}
	double	Getextra_double6(){return m_extra_double6;}
	void	Setextra_double7(double val){m_extra_double7=val;}
	double	Getextra_double7(){return m_extra_double7;}
	void	Setextra_double8(double val){m_extra_double8=val;}
	double	Getextra_double8(){return m_extra_double8;}
	void	Setextra_double9(double val){m_extra_double9=val;}
	double	Getextra_double9(){return m_extra_double9;}
	void	Setextra_double10(double val){m_extra_double10=val;}
	double	Getextra_double10(){return m_extra_double10;}

	void	Setextra_str1(char* val){SetValueString("extra_str1",val);}
	char*	Getextra_str1(){return GetValueString("extra_str1");}
	void	Setextra_str2(char* val){SetValueString("extra_str2",val);}
	char*	Getextra_str2(){return GetValueString("extra_str2");}
	void	Setextra_str3(char* val){SetValueString("extra_str3",val);}
	char*	Getextra_str3(){return GetValueString("extra_str3");}
	void	Setextra_str4(char* val){SetValueString("extra_str4",val);}
	char*	Getextra_str4(){return GetValueString("extra_str4");}

	void	Setextra_Vec1(Vec3 val){m_extra_Vec1=val;}
	Vec3	Getextra_Vec1(){return m_extra_Vec1;}
	void	Setextra_Vec2(Vec3 val){m_extra_Vec2=val;}
	Vec3	Getextra_Vec2(){return m_extra_Vec2;}
	void	Setextra_Vec3(Vec3 val){m_extra_Vec3=val;}
	Vec3	Getextra_Vec3(){return m_extra_Vec3;}
	void	Setextra_Vec4(Vec3 val){m_extra_Vec4=val;}
	Vec3	Getextra_Vec4(){return m_extra_Vec4;}

	void	SetColDetSphereRadius(double val){m_ColDetSphereRadius=val;}
	double	GetColDetSphereRadius(){return m_ColDetSphereRadius;}
	void	SetColDetEllipsoidSemiMajor(double val){m_ColDetEllipsoidSemiMajor=val;}
	double	GetColDetEllipsoidSemiMajor(){return m_ColDetEllipsoidSemiMajor;}
	void	SetColDetEllipsoidSemiMinor(double val){m_ColDetEllipsoidSemiMinor=val;}
	double	GetColDetEllipsoidSemiMinor(){return m_ColDetEllipsoidSemiMinor;}

	void	SetUseExternDataFile(bool val){m_UseExternDataFile=val;}
	bool	GetUseExternDataFile(){return m_UseExternDataFile;}
	void	SetExternDataFile(char* val){strcpy(m_ExternDataFile,val);}
	char*	GetExternDataFile(){return m_ExternDataFile;}
	void	SetExternDataStep(double val){m_ExternDataStep=val;}
	double	GetExternDataStep(){return m_ExternDataStep;}

	void	SetIsRecSelfMoveData(bool val){m_IsRecSelfMoveData=val;}
	bool	GetIsRecSelfMoveData(){return m_IsRecSelfMoveData;}
	void	SetRecSample(int val){m_RecSample=val;}
	int	GetRecSample(){return m_RecSample;}

	// ��̬������ȡ
	DtEntityType	GetOpdEntityType(){return m_OpdEntityType;}
	double	GetLength(){return m_Length;}
	double	GetWidth(){return m_Width;}
	double	GetHeight(){return m_Height;}

	//{{HDOSE_MEMBER_FUNCTION(CStateRepository)
	//}}HDOSE_MEMBER_FUNCTION

public:
	//{{HDOSE_PARAMETER(CStateRepository)
	DtEntityType	m_OpdEntityType/*ʵ������*/;
	double	m_OpdExtra1/*opd���Ӳ���1,�в�����Ӧ*/;
	double	m_OpdExtra2/*opd���Ӳ���2,�в�����Ӧ*/;
	double	m_OpdExtra3/*opd���Ӳ���3,�в�����Ӧ*/;
	long	m_OpdExtra4/*opd���Ӳ���4,�в�����Ӧ*/;
	double	m_Length/*��(m),�в�����Ӧ*/;
	double	m_Width/*��(m),�в�����Ӧ*/;
	double	m_Height/*��(m),�в�����Ӧ*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CStateRepository)
public:
	// ��������
	long	m_Side/*����������,1�췽��2������3����*/;
	long	m_Country/*װ������(ʹ��)����/����*/;
	char		m_EntityName[MAX_CHARLEN]/*����ʵ������*/;
	DtEntityType	m_EntityType/*ʵ������(����7����)*/;
	char		m_Marking[MAX_CHARLEN]/*���ű�ʶ���Ϻš����š����ӷ��š�ͧ�ŵȣ���171��*/;

	// ָ�ع�ϵ
	long	m_Level/*��֯��ʶ(��֯���� 1-15��, 1�����)*/;
	char		m_Superior[MAX_CHARLEN]/*�ϼ�ʵ�������,���ɱ�ʾ��Ӷӳ�,(��Ӧ�ϼ�ʵ���m_EntityName,ֱ���ϼ�,ֻ��һ��)*/;

	// �˶���״̬
	GeoPt	m_Position/*��ؾ�γ������*/;
	Vec3		m_VelocityVector/*�ٶ�ʸ��*/;
	double	m_Velocity/*�ٶȴ�С(����)*/;
	double	m_Heading/*����(�����˶�����)*/;
	double	m_Pitch/*����*/;
	double	m_Roll/*��ת*/;
	Vec3	m_Attitude/*��̬��(x--phi, y--psi, z--gama)*/;
	long	m_SurvivalState/*����״̬��0��á�1��٣�*/;

 //20160908��ʱע��
	// RCS��Infrared��Acoustic
	char*	m_RCS/*RCS����,�ַ�����ʽ,��ͨ�����巽����ȡ����*/;
	char*	m_Infrared/*Infrared����,�ַ�����ʽ,��ͨ�����巽����ȡ����*/;
	char*	m_Acoustic/*Acoustic����,�ַ�����ʽ,��ͨ�����巽����ȡ����*/;

	// ���������ء�����/ͨ���鱨������
	long	m_ReportToSuperior/*�Ƿ����ϼ������鱨*/;
	long	m_InformToSubordinates/*�Ƿ����¼�ͨ���鱨*/;
	double	m_InformationReleaseCycle/*�鱨��������(s)*/;

	long	m_Embarkation/*�Ƿ���д��ػ�������ϵ,����иù�ϵ��ʵ���Ƿ���ͣ��/����״̬,ֻ������ֵ��-1Ϊ��Ч��0��1�ǣ�Ĭ��Ϊ-1�������ֵΪ-1����ʾʵ�岻���д��ػ�������ϵ�����ػ���������Ҳ��Ч*/;
	char*	m_EmbarkedEntityName/*���ػ�ͣ��ʵ����������ƣ�����ɻ������ĸ����ء����ػ������ĸ���ĸ��̹�˴������ĸ���½���ϵȵȡ�ֻ����һ������Ϊ0��1ʱ���ò��������ò������塣*/;
	
	long	m_JoinCommNetwork/*�Ƿ����ͨ������,�����붨��Ҫ��������ͨ��ʱ���˲�����Ч*/;
	char*	m_CommNetworkName/*�������ͨ����������,�����붨��Ҫ��������ͨ��ʱ,�˲�����Ч,�ַ�����ʽ,��','����,��ͨ�����巽����ȡ��������*/;

	// ��չ���͡�ID
	long	m_ExEntityId/*�û��Զ��������ʶ��ʵ����ⲿ��ţ�ע��ȷ��Ψһ�ԣ����Ƽ�*/;
	long	m_ExEntityDomain/*����ʹ��EntityTypeʱ,�û��Զ��������ʶ��ʵ����ⲿ��(��ˮ�桢ˮ�¡�½�ء����С�̫�յ�)��ע��ȷ��Ψһ�ԣ����Ƽ�*/;
	long	m_ExPlatFormType/*����ʹ��EntityTypeʱ���û��Զ���ʹ�ã����Ƽ�*/;
	
	// 20160908��ʱע��
	// ���Ӳ���
	char*	m_Dim1_DoublePara/*һάdouble����,�ַ�����ʽ,��ͨ�����巽����ȡ����*/;
	char*	m_Dim2_DoublePara/*��άdouble����,�ַ�����ʽ,��ͨ�����巽����ȡ����*/;

	long	m_extra_long1/*����long����1*/;
	long	m_extra_long2/*����long����2*/;
	long	m_extra_long3/*����long����3*/;
	long	m_extra_long4/*����long����4*/;

	double	m_extra_double1/*����double����1*/;
	double	m_extra_double2/*����double����2*/;
	double	m_extra_double3/*����double����3*/;
	double	m_extra_double4/*����double����4*/;
	double	m_extra_double5/*����double����5*/;
	double	m_extra_double6/*����double����6*/;
	double	m_extra_double7/*����double����7*/;
	double	m_extra_double8/*����double����8*/;
	double	m_extra_double9/*����double����9*/;
	double	m_extra_double10/*����double����10*/;

	// 20160908��ʱע��
	char*	m_extra_str1/*����char*����1*/;
	char*	m_extra_str2/*����char*����2*/;
	char*	m_extra_str3/*����char*����3*/;
	char*	m_extra_str4/*����char*����4*/;

	Vec3	m_extra_Vec1/*����Vec3����1*/;
	Vec3	m_extra_Vec2/*����Vec3����2*/;
	Vec3	m_extra_Vec3/*����Vec3����3*/;
	Vec3	m_extra_Vec4/*����Vec3����4*/;

	// ��ײ����Χ����������
	double m_ColDetSphereRadius/*��ײ�����ƽ���뾶(m)*/;
	double m_ColDetEllipsoidSemiMajor/*��ײ�������ƽ��������(m)*/;
	double m_ColDetEllipsoidSemiMinor/*��ײ�������ƽ���̰���(m)*/;

//////////////////////////////////////////////////////////////////////////
	// ���ö��ķ��������Բ���Ҫע�ᣬ����Ȼ����ֱ�Ӵ�scn�ļ��ж�ȡ
	bool	m_UseExternDataFile/*�Ƿ�ʹ���ⲿ�����ļ�(0��1��,Ĭ��Ϊ0)*/;
	char	m_ExternDataFile[MAX_CHARLEN]/*�ⲿ�����ļ�·��+����(���·�������·��)*/;
	double m_ExternDataStep;/*�ⲿ���ݵĲ���(s)��Ĭ��Ϊ0ʱ��ȡģ�ͱ���Ĳ���(timestep*Sample)*/
	// �˲�����ֱ�Ӵ�scn�ļ��ж�ȡ
	FileHandle m_hExternDataFile/*�ⲿ�����ļ����*/;

	// ��¼�˶�����
	bool	m_IsRecSelfMoveData/*�Ƿ��¼������˶����ݣ�Ĭ��Ϊ0��*/;
	int	m_RecSample/*��¼���ݵĲ����ʣ�������������,Ĭ��Ϊ1��ʾ�벽��һ�£�*/;
//////////////////////////////////////////////////////////////////////////

	//}}HDOSE_ATTRIBUTE

};

#endif
