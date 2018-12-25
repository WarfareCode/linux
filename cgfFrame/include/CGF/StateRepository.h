//StateRepository.h: interface for the CStateRepository module.
//!!HDOSE_CLASS(CStateRepository,CNode)
//////////////////////////////////////////////////////////////////////

// Note: 1.---
// xks,暂时将m_OpdExtra1作为默认的rcs值（常量），
// 且状态参数m_extra_double1作为临时rcs变量，可在想定文件中重写，也可用默认值
// 计算的时候，二者都可以用，建议用默认值m_OpdExtra1。
// Note: 2.---
// xks,m_OpdEntityType为默认的实体类型码，
// 而m_EntityType是由m_OpdEntityType赋值过去的，是可订阅发布的变量。
// 通常不建议在想定文件中修改m_EntityType。


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

class HYCGF_API CStateRepository /*实体状态池*/: public CNode  
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

	// 得到实体对象
	CNode*	GetEntity()
	{
		return (CNode*)m_parent;
	}

	// 查找所属实体的武器系统模型，20161218
	// 只在实体模型中可以调用
	// input：CObjList参数类型，引用
	// out：查找到的模型个数，返回CObjList参数
	virtual int	LookupEntWeaponMounts(CObjList& wmList)
	{
		int count = 0;	// 查找到的模型个数
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


	//参数设置与获取函数
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

	// 静态参数获取
	DtEntityType	GetOpdEntityType(){return m_OpdEntityType;}
	double	GetLength(){return m_Length;}
	double	GetWidth(){return m_Width;}
	double	GetHeight(){return m_Height;}

	//{{HDOSE_MEMBER_FUNCTION(CStateRepository)
	//}}HDOSE_MEMBER_FUNCTION

public:
	//{{HDOSE_PARAMETER(CStateRepository)
	DtEntityType	m_OpdEntityType/*实体类型*/;
	double	m_OpdExtra1/*opd附加参数1,有参数对应*/;
	double	m_OpdExtra2/*opd附加参数2,有参数对应*/;
	double	m_OpdExtra3/*opd附加参数3,有参数对应*/;
	long	m_OpdExtra4/*opd附加参数4,有参数对应*/;
	double	m_Length/*长(m),有参数对应*/;
	double	m_Width/*宽(m),有参数对应*/;
	double	m_Height/*高(m),有参数对应*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CStateRepository)
public:
	// 基本属性
	long	m_Side/*红蓝中立方,1红方、2蓝方、3其他*/;
	long	m_Country/*装备所属(使用)国家/地区*/;
	char		m_EntityName[MAX_CHARLEN]/*所属实体名称*/;
	DtEntityType	m_EntityType/*实体类型(对象7类码)*/;
	char		m_Marking[MAX_CHARLEN]/*代号标识（舷号、机号、部队番号、艇号等，如171）*/;

	// 指控关系
	long	m_Level/*组织标识(组织级别 1-15级, 1级最高)*/;
	char		m_Superior[MAX_CHARLEN]/*上级实体的名称,还可表示编队队长,(对应上级实体的m_EntityName,直接上级,只有一个)*/;

	// 运动、状态
	GeoPt	m_Position/*大地经纬高坐标*/;
	Vec3		m_VelocityVector/*速度矢量*/;
	double	m_Velocity/*速度大小(标量)*/;
	double	m_Heading/*航向(朝向、运动方向)*/;
	double	m_Pitch/*俯仰*/;
	double	m_Roll/*滚转*/;
	Vec3	m_Attitude/*姿态角(x--phi, y--psi, z--gama)*/;
	long	m_SurvivalState/*生存状态（0完好、1损毁）*/;

 //20160908暂时注释
	// RCS、Infrared、Acoustic
	char*	m_RCS/*RCS描述,字符串格式,可通过具体方法获取数据*/;
	char*	m_Infrared/*Infrared描述,字符串格式,可通过具体方法获取数据*/;
	char*	m_Acoustic/*Acoustic描述,字符串格式,可通过具体方法获取数据*/;

	// 隶属、搭载、报告/通报情报、网络
	long	m_ReportToSuperior/*是否向上级报告情报*/;
	long	m_InformToSubordinates/*是否向下级通报情报*/;
	double	m_InformationReleaseCycle/*情报发布周期(s)*/;

	long	m_Embarkation/*是否具有搭载或隶属关系,或具有该关系的实体是否处于停靠/搭载状态,只有三个值：-1为无效，0否，1是，默认为-1。如果该值为-1，表示实体不具有搭载或隶属关系，基地或载体名称也无效*/;
	char*	m_EmbarkedEntityName/*基地或被停靠实体或载体名称，比如飞机属于哪个基地、舰载机属于哪个航母、坦克搭载在哪个登陆舰上等等。只有上一个参数为0或1时，该参数才设置并有意义。*/;
	
	long	m_JoinCommNetwork/*是否加入通信网络,当该想定需要仿真网络通信时，此参数有效*/;
	char*	m_CommNetworkName/*所加入的通信网络名称,当该想定需要仿真网络通信时,此参数有效,字符串格式,用','隔开,可通过具体方法获取网络名称*/;

	// 扩展类型、ID
	long	m_ExEntityId/*用户自定义的用于识别实体的外部编号，注意确保唯一性，不推荐*/;
	long	m_ExEntityDomain/*当不使用EntityType时,用户自定义的用于识别实体的外部域(如水面、水下、陆地、空中、太空等)，注意确保唯一性，不推荐*/;
	long	m_ExPlatFormType/*当不使用EntityType时，用户自定义使用，不推荐*/;
	
	// 20160908暂时注释
	// 附加参数
	char*	m_Dim1_DoublePara/*一维double数组,字符串格式,可通过具体方法获取数据*/;
	char*	m_Dim2_DoublePara/*二维double数组,字符串格式,可通过具体方法获取数据*/;

	long	m_extra_long1/*附加long参数1*/;
	long	m_extra_long2/*附加long参数2*/;
	long	m_extra_long3/*附加long参数3*/;
	long	m_extra_long4/*附加long参数4*/;

	double	m_extra_double1/*附加double参数1*/;
	double	m_extra_double2/*附加double参数2*/;
	double	m_extra_double3/*附加double参数3*/;
	double	m_extra_double4/*附加double参数4*/;
	double	m_extra_double5/*附加double参数5*/;
	double	m_extra_double6/*附加double参数6*/;
	double	m_extra_double7/*附加double参数7*/;
	double	m_extra_double8/*附加double参数8*/;
	double	m_extra_double9/*附加double参数9*/;
	double	m_extra_double10/*附加double参数10*/;

	// 20160908暂时注释
	char*	m_extra_str1/*附加char*参数1*/;
	char*	m_extra_str2/*附加char*参数2*/;
	char*	m_extra_str3/*附加char*参数3*/;
	char*	m_extra_str4/*附加char*参数4*/;

	Vec3	m_extra_Vec1/*附加Vec3参数1*/;
	Vec3	m_extra_Vec2/*附加Vec3参数2*/;
	Vec3	m_extra_Vec3/*附加Vec3参数3*/;
	Vec3	m_extra_Vec4/*附加Vec3参数4*/;

	// 碰撞检测包围球或椭球参数
	double m_ColDetSphereRadius/*碰撞检测球平均半径(m)*/;
	double m_ColDetEllipsoidSemiMajor/*碰撞检测椭球平均长半轴(m)*/;
	double m_ColDetEllipsoidSemiMinor/*碰撞检测椭球平均短半轴(m)*/;

//////////////////////////////////////////////////////////////////////////
	// 不用订阅发布，所以不需要注册，但仍然可以直接从scn文件中读取
	bool	m_UseExternDataFile/*是否使用外部数据文件(0否、1是,默认为0)*/;
	char	m_ExternDataFile[MAX_CHARLEN]/*外部数据文件路径+名称(相对路径或绝对路径)*/;
	double m_ExternDataStep;/*外部数据的步长(s)，默认为0时将取模型本身的步长(timestep*Sample)*/
	// 此参数不直接从scn文件中读取
	FileHandle m_hExternDataFile/*外部数据文件句柄*/;

	// 记录运动数据
	bool	m_IsRecSelfMoveData/*是否记录自身的运动数据（默认为0）*/;
	int	m_RecSample/*记录数据的采样率（步长的整数倍,默认为1表示与步长一致）*/;
//////////////////////////////////////////////////////////////////////////

	//}}HDOSE_ATTRIBUTE

};

#endif
