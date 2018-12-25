// FightingUnit.h: interface for the CFightingUnit class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FIGHTINGUNIT_H
#define FIGHTINGUNIT_H

#include "BwVehicleKinematic.h"
#include "interface.h"	// Added by ClassView
#include "Craft.h"	// Added by ClassView
#include "Environment.h"	// Added by ClassView
#include "Driver.h"	// Added by ClassView
#include "MyType.h"


namespace  BW_VEHICLEKINEMATIC {

	class CFormationServer;
	class CDriver;
	class CCraft;
	class CEnvironment;

	class  BW_VEHICLEKINEMATIC_API CFightingUnit  //  作战单元类（包含环境、车辆、副驾驶员）
	{
	public:
		//  改变本机在编队中的位置
		void change_position( int iPositionID );

		//  命令：编队（解散）
		bool command_format( bool b, int iPositonID, CFormationServer *pFormationServer );

		//  命令：机动
		bool command_maneuver( int iManeuver );  //  1：左急转弯；2：右急转弯；3：左横滚；4：右横滚；5：斤斗；6：半滚斤斗；7：俯冲拉起；8：跃升下降；

		//  威胁警告
		void warning_BeingAttacked( int iClock );

		//  火控引导
		void guide_by_fire_ctrol( double v_kmph, double alti_m, double heading_deg );

		//  火控开关
		void Switch_fire_control( bool b);

		//  查询当前任务是否完成
		bool IsTaskOver( );

		//  查询当前航线飞行是否结束
		bool IsRouteOver( );

		//  设定亲自驾驶
		void set_self_drive( bool b );

		//  设定毁坏（故障、战损、驾驶员失能）
		void set_failed( bool b );

		//  给定任务参数
		void set_task( stPatrolPara PatrolPara );

		//  给定任务航线
		void set_route_task( CRoute Route );

		//  给定飞行航线
		//	void set_route( CRoute Route );

		//  给定返航机场
		void set_base_return( double _RW_alti_m, double _RW_lati_rad, double _RW_longi_rad, double _RW_head_deg, int iLandingType );

		//  命令：攻击（适用于导弹）
		void command_attack( void );

		//  命令：出航/返航
		void command_go( bool b );

		//  命令：起飞/着陆
		void command_TakeOff( bool b );

		//  单步运行
		void tick_FightingUnit( double Dt, double altiG_m, double Target_alti_m, double Target_lati_rad, double Target_longi_rad );

		//  初始化函数
		void ini_FightingUnit( int iUnitID, double RW_alti_m, double RW_lati_deg, double RW_longi_deg, double RW_head_deg, double alti_m, double lati_deg, double longi_deg, double head_deg, double speed_kmph, double teta_deg );

		//  补充构造函数
		void con_FightingUnit( stPerformance stPerformance );

		CFightingUnit();
		virtual ~CFightingUnit();

		//  控制量
		bool m_bFailed;  //  失效（故障、被击毁等）

		bool m_bSelfDrive;  //  亲自驾驶

		//  状态
		bool m_bOK_ini;    //  初始条件已经给定
		bool m_bOK_route;  //  航线已给定
		bool m_bOK_task;   //  任务已下达

		double m_dTime;  //  待机总时间
		double m_dStep;  //  解算步长

		//  作战单元成员
		//	stPatrolPara m_cPatrolPara;  //  巡逻任务数据

		CDriver      m_cDriver2;      //  副驾驶员（主驾驶员为计算操作员）

		CCraft       m_cCraft;        //  车辆（固定翼飞机、直升机、导弹、陆地车辆、水面船只、潜艇）

		CEnvironment m_cEnvironment;  //  环境（大气、陆地、海洋）
	};


}  //  namespace end


#endif
