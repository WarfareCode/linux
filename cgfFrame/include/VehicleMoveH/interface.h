// interface.h
//
//////////////////////////////////////////////////////////////////////

#ifndef INTERFACE_H
#define INTERFACE_H

#include "MyType.h"


namespace  BW_VEHICLEKINEMATIC {


#define MAX_MSG_SIZE 512

	//  system identifier define
	enum SYS_ID
	{
		ALL =  0,  //  所有分系统
		MCS =  1,  //  综合控制系统
		MFS =  2,  //  主飞行仿真系统
		SSS =  3,  //  视景
		CLS =  4,  //  操纵
		SWS =  5,  //  音响
		IOS =  6,  //  接口
		AES =  7,  //  航电与仪表
		ADJ =  8,  //  调参台
		VTS =  9,  //  顶控板
		FCS = 10,  //  飞控系统
		MRK = 11   //  三维态势
	};

	//  control command define
	enum CMD_TYPE
	{
		NET_TEST = 0,    //  网络检测
		SYS_INIT = 1,    //  初始化
		SYS_START= 2,    //  仿真开始
		SYS_STOP = 3,    //  仿真停止
		SYS_OFF  = 4,    //  系统关闭
		SYS_FREZ = 5,    //  冻结
		SYS_UNFREZ = 6,  //  解冻
		SYS_ACK  = 7     //  系统运行，用于标识运行过程中发布控制命令
	};

	//  sys status define
	enum SYS_STATUS
	{
		SS_FAIL =  0,  //  故障
		SS_TEST =  1,  //  网络检测
		SS_INIT =  2,  //  初始化
		SS_START = 3,  //  仿真开始	
		SS_STOP =  4,  //  仿真停止
		SS_FREZ = 5,   //  冻结
		SS_UNFREZ = 6  //  解冻
	};

	//  Message Values
	enum MessageValues
	{
		MV_ALL = 0,
		MV_WindLoad = 1,    //  风场加载
		MV_Fuel = 2,        //  重设燃油
		MV_CG = 3,          //  重设重心位置
		MV_Altitude = 4,    //  重设气压高度
		MV_CAS = 5,	        //  重设表速
		MV_Loading = 6,     //  重设装载物
		MV_Reposition = 7,  //  重设水平位置
		MV_PromptStart = 8,  //  发动机迅捷启动
		MV_FuelFreeze = 9,   //  燃油冻结
		MV_EngineFault = 10   //  发动机故障
	};

	//  Vehicle Type  车辆类型
	enum VehicleType
	{
		Vehicle_aircraft = 0,    //  固定翼飞机;
		Vehicle_helicopter = 1,  //  直升机
		Vehicle_land = 2,        //  陆基车辆
		Vehicle_ship = 3,        //  水面舰船
		Vehicle_submarine = 4    //  潜艇
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  通用数据包
	//
	struct CtlCmd
	{
		unsigned char  ucSourceSysId;  //  发送方的系统标识SYS_ID
		unsigned char  ucDestSysId;    //  接收方的系统标识SYS_ID
		unsigned char  ucMsgType;      //  发送的消息类型CTL_CMD
		unsigned char  ucMsgValue;     //  消息值
		unsigned char  ucDummy[4];     //  备用
		char cMsgBody[MAX_MSG_SIZE];   //  消息体
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：控制台 -> 主飞行仿真
	//
	struct stMCStoMFS
	{
		char c;  //  软件进程控制指令（0 - 正常运行；1 - 初始化 ; 2 - 冻结； 3 - 备用；99 - 关机）

		int iCruiseMode;  //  在指定位置巡逻模式（-1：着陆待命；0：悬停待命；1：圆形轨迹；2：椭圆形轨迹；3：8字形轨迹；4：备用；）

		int iRapidClass;  //  急迫等级（0：尽快；1：给定时间；2：给定速度）

		bool bGivenAlti;   //  按规定的高度飞行

		double fGivenAlti_km;
		double fGivenTime;
		double fGivenSpeed_kmph;

		CRoute cRoute;  //  航线（可以只有一个点）
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：主飞行仿真系统 -> 控制台
	//
	struct stMFStoMCS
	{
		int iFlightMode;  //  飞行阶段。0：地面待命；1：起飞过程；2：本场上空待命；3：出航；4：航线末端执行任务（战斗、巡逻、待命）；5：返回本场上空；6：着陆过程；

		double fAlti_m;  //  当前飞行高度（单位：米）
		double fGSpeed;  //  当前地速（单位：千米/小时）
		double fLati_deg;   //  当前纬度（单位：度）
		double fLongi_deg;  //  当前经度（单位：度）
		double fHeading_deg;  //  当前飞行航向（单位：度）
		double fBank_deg;    //  当前飞机滚转角（单位：度）
		double fPitch_deg;    //  当前飞机俯仰角（单位：度）

		double fFlyTime_min;      //  飞行时间（分钟）
		double fCourseDone_km;    //  飞行
		double fCourseRemain_km;  //  剩余飞行距离（千米）
		double fTimeRemain_min;   //  剩余飞行时间（分钟）
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：性能数据
	//
	struct stPerformance
	{
		int iVehicleType;  //  车辆类型（0：固定翼飞机；1：直升机；2：陆基车辆；3：水面舰船；4：潜艇；10：对面巡航导弹）

		double fTimetoPrepare;  //  出动前地面准备时间（暂无明确定义，用户可自己定义）

		//  运动限制和特征
		double fAltiMax;  //  高度上限（如果有）
		double fAltiMin;  //  高度下限（如果有）
		double fHDMax;    //  最大爬升率（m/min）
		double fHDMin;    //  最大下降率（m/min）

		double fVMax;      //  最大速度（m/s）
		double fVMin;      //  最小速度（m/s）  //  暂时不用。
		double fVLiftOff;  //  起飞速度（m/s）  //  仅固定翼
		double fVLanding;  //  接地速度（m/s）  //  仅固定翼
		double fVCruise;   //  巡航速度（m/s）
		double fVDefault;  //  默认速度（m/s）

		//  机动能力
		double fn_engineM;  //  最大推重比
		double fn_brakeM;   //  最大刹重比

		double fn_Max;  //  最大机动过载多少个g（直升机为零）

		double f_pMax;  //  最大滚转角速度（deg/s）
		double f_qMax;  //  最大俯仰角速度（deg/s）（暂时不用）

		//  直升机低速运动能力（适用于船舶）
		double fHeli_rMax;  //  最大偏航角速度（deg/s）
		double fHeli_vxMax;  //  最大纵向速率
		double fHeli_vyMax;  //  最大垂向速率
		double fHeli_vzMax;  //  最大侧向速率

		//  自动控制能力
		double fAP_pitchMax;  //  AP控制最大俯仰角	度
		double fAP_pitchMin;  //  AP控制最小俯仰角	度
		double fAP_bankMax;   //  AP控制最大滚转角	度

		//	double fEnergyConsuming;  //  能量油耗   /s/ax
		double fRangeMax_km;  //  航程 千米

		//  驾驶员眼位坐标（米）
		double fEye_x;  //  前向
		double fEye_y;  //  垂向
		double fEye_z;  //  侧向
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：巡逻参数，航线间来回。序号：1
	//
	struct	stPatrolRouteParams
	{
		//	CRoute Route;  //  航线

		bool IsCrossPoints;  //  过点导航标志
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：巡逻参数，多边形区域。序号：2
	//
	struct	stPatrolPolygonParams
	{
		//	CRoute Route;            //  航线

		bool IsCrossPoints;      //  过点导航标志

		bool bCounterClockWise;  //  逆时针转弯标志

		int  NumStartPoint;      //  起始点编号
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：圆形区域巡逻参数。序号：3
	//
	struct	stPatrolCircleParams
	{
		//	CRoute Route;            //  目标点位置（单段航线）

		double Radius_km;        //  巡逻半径，km

		bool bCounterClockWise;  //  逆时针转弯标志
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：巡逻参数，椭圆形区域。序号：4
	//
	struct	stPatrolEllipseRarams
	{
		//	CRoute Route;  //  目标点位置（单段航线）

		double RadiusMinorSemi_km;    //  短轴半径，km

		double RadiusMajorSemi_km;    //  长轴半径，km

		double HeadingMajorAxis_deg;  //  长轴航向，deg

		bool bCounterClockWise;  //  逆时针转弯标志
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：巡逻参数，8字形区域。序号：5
	//
	struct	stPatrolCurveEightParams
	{
		//	CRoute Route;  //  目标点位置（单段航线）

		double RadiusMinorSemi_km;    //  短轴半径，km

		double RadiusMajorSemi_km;    //  长轴半径，km

		double HeadingMajorAxis_deg;  //  长轴航向，deg

		bool bCounterClockWise;  //  逆时针转弯标志
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  结构体：巡逻任务说明
	//
	struct stPatrolPara
	{
		int PatrolMoveType;  //  巡逻模式：0-默认模式；1-航线上来回巡逻；2-多边形区域巡逻；3-圆形区域巡逻；4-椭圆区域巡逻；5-八字形区域巡逻；6-备用。

		stPatrolRouteParams      PatrolAlongRoute;       //  1：航线往复巡逻参数

		stPatrolPolygonParams    PatrolAlongPolygon;     //  2：多边形区域巡逻参数

		stPatrolCircleParams     PatrolAlongCircle;      //  3：圆形区域巡逻参数

		stPatrolEllipseRarams    PatrolAlongEllipse;     //  4：椭圆区域巡逻参数

		stPatrolCurveEightParams PatrolAlongCurveEight;  //  5：8字形区域巡逻参数

		bool IsAssignPatrolVel;   //  是否指定巡逻速度

		double PatrolVel_kmph;    //  巡逻速度，km/h

		bool IsAssignPatrolTime;  //  是否指定总巡逻时间

		double PatrolTime_min;    //  总巡逻时间，min

		CRoute Route;  //  巡逻航线（如果只有目标点位置，则可看作单段航线）

	};


}  //  namespace end


#endif
