// Driver.h: interface for the CDriver class.
//
//////////////////////////////////////////////////////////////////////

#ifndef DRIVER_H
#define DRIVER_H

#include "BwVehicleKinematic.h"
#include "Environment.h"	// Added by ClassView
#include "Craft.h"	// Added by ClassView
#include "interface.h"	// Added by ClassView


namespace  BW_VEHICLEKINEMATIC {


#define NStage 10  //  飞行阶段数量定义
	class CEnvironment;
	class CCraft;

	class  BW_VEHICLEKINEMATIC_API CDriver  //  驾驶员类（能够驾驶：固定翼飞机、直升机、导弹、陆地车辆、水面舰船、潜艇等）
	{
	public:
		//  设定导弹起飞安全高度
		void set_missile_safe_alti( double alti_m );

		//  命令：编队（解散）
		bool command_format( bool _b);

		//  命令：机动
		bool command_maneuver( int iManeuver );  //  1：左急转弯；2：右急转弯；3：左横滚；4：右横滚；5：斤斗；6：半滚斤斗；7：俯冲拉起；8：跃升下降；

		//  威胁信息
		bool warning_BeingAttacked( int iClock );

		//  外部命令：改变当前飞行速度
		bool change_speed( bool bChangeSpeed, double speed_kmph );

		//  外部命令：改变当前飞行高度
		bool change_alti(  bool bChangeAlti,  double alti_m );

		//  驾驶授权
		void switch_authorize( bool b );

		//  给定任务航线
		void set_route_task( CRoute Route );

		//  给定任务参数
		void set_task( stPatrolPara PatrolPara );

		//  设定基地的海拔高度（不局限于起飞的机场或港口）
		void set_alti_base( double alti_m );

		//  返回判断（因燃油等问题决定返回基地并停车）
		void decide_return( void );

		//  地面准备程序
		bool tick_pro_prepareG( double Dt );

		//  地面待命程序
		bool tick_pro_standbyG( double Dt );

		//  起飞程序
		bool tick_pro_TakeOff( double Dt );

		// 空中待命程序
		bool tick_pro_standbyA( double Dt );

		//  航线飞行程序
		bool tick_pro_route( double Dt );

		//  机动程序
		bool tick_pro_formating( double Dt );

		//  机动程序
		bool tick_pro_maneuver( double Dt );

		//  任务程序
		bool tick_pro_task0( double Dt );  //  默认任务
		bool tick_pro_task1( double Dt );  //  航线往返飞行程序
		bool tick_pro_task2( double Dt );  //  多边形航线飞行程序
		bool tick_pro_task3( double Dt );  //  圆形航线飞行程序
		bool tick_pro_task4( double Dt );  //  椭圆形航线飞行程序
		bool tick_pro_task5( double Dt );  //  8 字形航线飞行程序
		bool tick_pro_task_missile( double Dt );  //  导弹攻击
		bool tick_pro_task_straight(double Dt);		// 直线航行，m_iStage =5且m_iTask=-3时进入 , 只用于潜艇、舰艇，当它们有初速度且没有被赋予任何任务时可用，xks,20180704

		//  进场程序
		bool tick_pro_approaching( double Dt );

		//  着陆程序
		bool tick_pro_landing( double Dt );
		bool tick_pro_landing_heli( double Dt );

		//  阶段检查清零
		void clear_stage_check( void );

		//  命令：攻击
		void command_attack( void );

		//  命令：出航/返航
		void command_go( bool b );

		//  命令：起飞/着陆
		void command_TakeOff( bool b );

		//  单步运行函数
		void tick_driver( double Dt, double Target_alti_m, double Target_lati_rad, double Target_longi_rad );

		//  初始化函数
		void ini_Driver( double alti_base );

		//  补充构建函数
		void con_Driver( CEnvironment *pEnvironment, CCraft *pCraft );

		CDriver();
		virtual ~CDriver();

		//  导弹起飞安全高度
		double m_dMissileSafeAlti;  //  导弹起飞安全高度

		//  靶标位置（两帧数据）
		double m_dTarget_alti_m0,    m_dTarget_alti_m1;     //  海拔高度
		double m_dTarget_lati_rad0,  m_dTarget_lati_rad1;   //  纬度
		double m_dTarget_longi_rad0, m_dTarget_longi_rad1;  //  经度

		double m_dTarget_distance_m0;  //  靶标距离
		double m_dTarget_distance_m1;  //  靶标距离
		double m_dTarget_distance_min_m1;  //  靶标最小距离
		double m_dTarget_speed_mps;    //  靶标相对速度

		double m_dTarget_pitch_deg0;       //  靶标俯仰角
		double m_dTarget_pitch_deg1;       //  靶标俯仰角
		double m_dTarget_pitching_degps;  //  靶标俯仰角速率

		double m_dTarget_psai_deg0;      //  靶标偏航角
		double m_dTarget_psai_deg1;      //  靶标偏航角
		double m_dTarget_yawing_degps;  //  靶标偏航角速率
		double m_dTarget_Dpsai_deg;      //  靶标偏航角

		//  攻击命令值
		bool m_bAttack;

		//  集群命令
		bool m_bCMDFormat;  //  编队（解散）命令

		//  单机命令和作战信息
		bool m_bTakeOff;  //  起飞，出库，出港（否则：着陆，进库，进港）
		bool m_bGo;       //  出航作战（否则：返回）

		int m_iTask;  //  巡逻运动类型。0：默认圆形轨迹；1：航线上来回巡逻；2：多边形航线巡逻；
		//                3：圆形航线巡逻；4：椭圆航线巡逻；  5：八字形航线巡逻；6：备用；10：攻击。

		bool m_bBeingAttacked;  //  被攻击状态
		int m_iAttackedClock;   //  被攻击方向（钟表指针）

		bool m_bCMDManeuver;  //  机动指令
		int m_iManeuver;      //  机动动作：1：左急转弯；2：右急转弯；3：左横滚；4：右横滚；5：斤斗；6：半滚斤斗；7：俯冲拉起；8：跃升下降；

		bool m_bSetSpeed;  //  指定速度
		bool m_bSetAlti;   //  指海拔高度

		double m_dCMDSpeed;  //  指令飞行速度
		double m_dCMDAlti;   //  指令飞行高度

		//  自我控制
		bool m_bFormating;         //  执行编队飞行
		bool m_bManeuveringReady;  //  机动准备好
		bool m_bManeuvering;  //  决定进行机动
		bool m_bOK;  //  完成任务
		bool m_bNewTask;              //  新任务标志
		bool m_bAuthorized;           //  有权驾驶
		bool m_bDecideParking;        //  返航决定
		bool m_bStage_check[NStage];  //  阶段检查

		int m_iStage;  //  运行阶段。0：港内准备；1：港内待命；2：起飞/离港；3：上空/港外待命；4：出航；
		//            5：执行任务；6：返航；7：待命进场/进港；8：进场/进港；9：着陆/停泊

		int m_iStageManeuver;  //  复杂机动的阶段。

		//  状态量
		double m_dBank;   //  滚转角，不限幅，可反映圈数
		double m_dPitch;  //  俯仰角，不限幅，可反映圈数
		double m_dPsai;   //  偏航角，不限幅，可反映圈数
		double m_dH0;     //  动作起始高度
		double m_dV0;     //  动作起始速度
		double m_dT0;     //  动作计时

		double m_dTimePatrol;  //  巡逻时间

		double m_dTimes[NStage];  //  各阶段时间
		double m_dTimeRun;  //  驾驶总时间
		double m_dTime;     //  副驾驶值班总时间

		bool m_bLiftOff;  //  飞机离地（或潜水艇下沉）标志

		//  有关联的系统
		stPatrolPara  m_cPatrolPara;   //  巡逻任务数据包

		CCraft       *m_pCraft;        //  飞行器（车辆）指针
		CEnvironment *m_pEnvironment;  //  环境指针

	private:
		double m_dAlti_base;  //  基地的海拔高度（对于飞行器，为机场，对水面舰船和潜艇为零）

	};

#undef NStage


}  //  namespace end


#endif
