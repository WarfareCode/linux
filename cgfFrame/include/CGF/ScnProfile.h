//ScnProfile.h: interface for the CScnProfile module.
//!!HDOSE_CLASS(CScnProfile,CLink)
//////////////////////////////////////////////////////////////////////

/// **********************************
/* Note：20161215，xks
	此头文件描述：想定概要及想定运行参数，
	包括想定名称、开始结束时间、随机数、仿真网络等。
	
	0. 原则上，只要使用了Hycgf库的每一个想定文件，都必须包含这个类的对象。
	1. 其它运算模型如果使用其中的内容，请先检查SetSimPara是否为真（1），真表示仿真参数已经设置了且为最新的；
	2. 设置SetSimPara检查的目的在于，如果是单个想定单次独立运行，想定本身已经记录了相关运行参数；
		但如果是多个想定（或单个想定）多次运行时，通过外部控制接口传入仿真运行参数时，则是通过FedParameter
		来传递的，此类又做了根据外部参数修改想定本身的运行参数的工作。
		为了兼顾二者通用，特别设置SetSimPara检查。
	3. 仿真运行期间，其它模型均从此类获取必要的仿真运行参数。
	3. 为保证程序正常运行，凡是用到此Hycgf库时，切记在Sim文件的Parameters区域中写入：
		<Parameter Name="ExternScnParaSet" Value="0"/>
		含义为：是否用外部仿真运行参数替代想定自身的运行参数，此处的Value默认为0（否）。
	4. 此类中也记录了后台模型的仿真时间（0开始的相对时间，秒），用于发布了显控端，保持前后台时间一致。
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

class HYCGF_API CScnProfile /*想定概要*/ : public CLink 
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
// 手动修改
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
	char	m_ScnName[MAX_CHARLEN]/*想定名称*/;
	char*	m_OutLine/*基本描述，此参数不注册，且此参数未从想定文件中读取对应内容*/;
	EpochTimeStruct	m_ScnStartTime/*仿真开始纪元时间*/;
	EpochTimeStruct	m_ScnEndTime/*仿真结束纪元时间*/;
	long	m_ScnRunN/*同一个想定仿真的第几次*/;
	char*	m_SimAreaRange/*仿真区域,矩形区域*/;
	double	m_RelativeSimTime/*相对仿真时间(后台引擎时间)*/;
	long	m_UseRadomSeed/*是否使用随机数种子,默认0*/;
	long	m_RadomSeed/*随机数种子,（非负整数）,默认-1*/;
	double	m_T/*T时刻,默认0.0*/;
	long	m_SimNetworkComm/*是否仿真实体间的网络通信,默认0*/;

	//}}HDOSE_ATTRIBUTE

	String tempPoint;	// 临时存储WayPoint
	bool SetSimPara; // 是否设置了仿真参数
};

/// 获取想定开始时间(年、月、日、时、分、秒)、想定结束时间(年、月、日、时、分、秒)，当前仿真时间(s)
HYCGF_API bool GetBackScnTime(EpochTimeStruct &scnStartTm, EpochTimeStruct &scnEndTm, double &backSimTm);
/// 获取本想定的名称，成功返回ture，不成功返回false（由于仿真开始后内部才会记录想定名称，所以可通过多次调用此函数会得到正确的想定名称）
HYCGF_API bool GetScnName(char* scnName);

#endif
