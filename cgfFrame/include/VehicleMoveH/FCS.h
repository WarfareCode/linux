// FCS.h: interface for the CFCS class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FCS_H
#define FCS_H

#include "BwVehicleKinematic.h"
#include "interface.h"	// Added by ClassView
#include "FMS.h"
#include "AirSpeed.h"
//#include "Filter.h"	// Added by ClassView
#include "MyType.h"


namespace  BW_VEHICLEKINEMATIC {

	class CFormationServer;
	class CFCS;
	class CFMS;

	class  BW_VEHICLEKINEMATIC_API CFCS  //  飞行控制系统类（车辆控制系统类），角度默认单位：度
	{
	public:
		//  编队服务器指针赋值
		void set_formation( bool b, int iPositionID, CFormationServer *pFormationServer );

		//  火控引导
		void guide_by_fire_ctrol( double v_kmph, double alti_m, double heading_deg );

		void heli_ctrl_yaw( double _percent );  //  直升机偏航速率控制
		void heli_ctrl_vz( double _percent );   //  直升机侧向速率控制
		void heli_ctrl_vy( double _percent );   //  直升机垂向速率控制
		void heli_ctrl_vx( double _percent );   //  直升机纵向速率控制

		//  设定目标速度
		void set_AP_speed( double speed_mps );
		void set_AP_speed_i( int speed_percent );

		//  设定目标俯仰角
		void set_AP_pitch( double pitch_deg );
		void set_AP_pitch_i( int pitch_percent );

		//  设定目标高度
		void set_AP_pitch_alti( double alti_m );
		void set_AP_pitch_alti_i( int alti_percent );

		//  设定目标坡度
		void set_AP_bank( double bank_deg );
		void set_AP_bank_i( int bank_percent );

		//  设定目标航向——滚转轴
		void set_AP_bank_psai( double psai_deg );
		void set_AP_bank_psai_i( int psai_percent );

		//  设定目标航向——偏航轴
		void set_AP_yaw_psai( double psai_deg );
		void set_AP_yaw_psai_i( int psai_percent );

		//  设定目标航向——地面转弯轴
		void set_AP_turning_psai( double psai_deg );
		void set_AP_turning_psai_i( int psai_percent );

		//  单步运行函数
		void tick_FCS( double Dt, double altiG_m, double vd_mpsps, double v_mps, double altid_mps, double alti_m,
			double pitchd_degps, double pitch_deg, double bankd_degps, double bank_deg, double psaid_degps, double psai_deg );

		void SwitchAP_fire_control( bool b );  //  火控接通开关

		void SwitchAP_turning_psai_format( bool b );  //  地面转弯轴AP：编队开关——左右位置控制
		void SwitchAP_turning_psai_NAV( bool b );     //  地面转弯轴AP：水平导航开关
		void SwitchAP_turning_psai( bool b );         //  地面转弯轴AP：航向保持开关

		void SwitchAP_yaw_psai_format( bool b );  //  偏航轴AP：编队开关——左右位置控制
		void SwitchAP_yaw_psai_NAV( bool b );     //  偏航轴AP：水平导航开关
		void SwitchAP_yaw_psai( bool b );         //  偏航轴AP：航向保持开关

		void SwitchAP_bank_psai_format( bool b );  //  滚转轴AP：编队开关——左右位置控制，
		void SwitchAP_bank_psai_NAV( bool b );     //  滚转轴AP：水平导航开关
		void SwitchAP_bank_psai( bool b );         //  滚转轴AP：航向保持开关
		void SwitchAP_bank( bool b );              //  滚转轴AP：坡度保持开关

		void SwitchAP_pitch_alti_format( bool b );  //  俯仰轴AP：编队开关——上下位置控制
		void SwitchAP_pitch_alti_NAV( bool b );     //  俯仰轴AP：垂直导航开关
		void SwitchAP_pitch_alti( bool b );         //  俯仰轴AP：高度保持开关
		void SwitchAP_pitch( bool b );              //  俯仰轴AP：俯仰保持开关

		void SwitchAP_speed_format( bool b );  //  速度轴AP：编队开关——前后位置控制
		void SwitchAP_speed_NAV( bool b );     //  速度轴AP：速度导航开关
		void SwitchAP_speed( bool b );         //  速度轴AP：速度保持开关

		//  地面转弯曲率控制
		void ctrl_k_turning( double _percent );

		//  滚转角速率控制
		void ctrl_roll( double _percent );

		//  侧向过载控制
		void ctrl_n_side( double _percent );

		//  法向过载控制
		void ctrl_n_normal( double _percent );

		//  推重比控制
		void ctrl_engine_brake( double _percent );

		//  初始化
		void ini_FCS( int iUnitID, double time0, double v_mps, double alti_m );

		//  补充构造
		void con_FCS( stPerformance *pPerformance, CFMS *pFMS, CAirSpeed *pAS );

		CFCS();
		virtual ~CFCS();

		bool m_bFormationServerOK;  //  编队服务器可用

		bool m_bFixed;  //  飞行器（尤其是导弹）系留（固定）

		//  火控指令
		double m_dFC_v, m_dFC_alti, m_dFC_psai;

		//  速度轴的各级AP开关
		bool m_bAP_speed;         //  速度保持
		bool m_bAP_speed_NAV;     //  速度导航
		bool m_bAP_speed_format;  //  编队——纵向位置

		//  俯仰轴的各级AP开关
		bool m_bAP_pitch;              //  俯仰角保持
		bool m_bAP_pitch_alti;         //  高度保持
		bool m_bAP_pitch_alti_NAV;     //  垂直导航
		bool m_bAP_pitch_alti_format;  //  编队——垂向位置

		//  滚转轴的各级AP开关
		bool m_bAP_bank;              //  坡度保持
		bool m_bAP_bank_psai;         //  航向保持
		bool m_bAP_bank_psai_NAV;     //  水平导航
		bool m_bAP_bank_psai_format;  //  编队——侧向位置

		//  偏航轴的各级AP开关（主要用于X形导弹）
		bool m_bAP_yaw_psai;         //  航向保持
		bool m_bAP_yaw_psai_NAV;     //  水平导航
		bool m_bAP_yaw_psai_format;  //  编队——侧向位置

		//  地面转弯轴的各级AP开关（用于陆基车辆的运动、飞机地面滑行）
		bool m_bAP_turning_psai;         //  航向保持
		bool m_bAP_turning_psai_NAV;     //  水平导航
		bool m_bAP_turning_psai_format;  //  编队——侧向位置

		bool m_bAP_fire_control;   //  火控接通

		//  整型AP控制目标;
		int m_iAPObj_speed;      //  整型速度（0，100）

		int m_iAPObj_pitch;       //  整型俯仰角（-100，100）
		int m_iAPObj_pitch_alti;  //  整型高度（-100，100）

		int m_iAPObj_bank;       //  整型目标滚转角（-100，100）
		int m_iAPObj_bank_psai;  //  整型目标偏航角（-100，100）

		int m_iAPObj_yaw_psai;   //  整型目标偏航角（-100，100）

		int m_iAPObj_turning_psai;   //  整型目标偏航角（-100，100）

		//  整型直接控制量（-100，100）
		int m_iCMD_engine_brake;   //  推力或刹车比
		int m_iCMD_n_normal;       //  法向过载增量（直升机不用）
		int m_iCMD_n_side;         //  侧向过载
		int m_iCMD_RollRate;       //  滚转速率
		int m_iCMD_k_turning;      //  地面转弯曲率（通过方向盘转弯）

		//  整形直接控制量——直升机模式
		int m_iCMD_YawRate;  //  偏航速率（-100，100）
		int m_iCMD_vx;       //  前向运动速度（-100，100）
		int m_iCMD_vy;       //  垂向运动速度（-100，100）
		int m_iCMD_vz;       //  侧向运动速度（-100，100）

		//  AP控制目标
		double m_dAPObj_speed;  //  目标速度

		double m_dAPObj_pitch;       //  目标俯仰角
		double m_dAPObj_pitch_alti;  //  目标高度

		double m_dAltiG0, m_dAltiG1;  //  前后两帧车辆在地面投影点的海拔高度（地形高度）
		double m_dHdG_i, m_dHdG;  //  地形起伏速度（滤波前后）
		double m_dHR;  //  雷达高度

		double m_dAPObj_bank;       //  目标滚转角
		double m_dAPObj_bank_psai;  //  目标偏航角（滚转轴）

		double m_dAPObj_yaw_psai;  //  目标偏航角（偏航轴）

		double m_dAPObj_turning_psai;  //  目标偏航角（地面转弯轴）

		//  直接飞行控制
		double m_dCMD_engine_brake;  //  推力或刹车比
		double m_dCMD_n_normal;      //  法向过载增量（直升机不用）
		double m_dCMD_n_side;        //  侧向过载
		double m_dCMD_RollRate;      //  滚转速率
		double m_dCMD_k_turning;     //  水平转弯曲率（通过方向盘实施地面转弯）

		//  低速控制（直升机模式，船舶模式）
		double m_dCMD_YawRate;  //  偏航速率
		double m_dCMD_vx;       //  前向运动速率
		double m_dCMD_vy;       //  垂向运动速率
		double m_dCMD_vz;       //  侧向运动速率

		//  侧偏距的前后帧和速率
		double m_dDz0, m_dDz1, m_dDzd;

		//  时间
		double m_dTime;
		double m_dT_defix;  //  脱离计时

		//  本机在机群中的位置号
		int m_iPositionID;

		//  本机识别号
		int m_iUnitID;

		//  相关系统
		CFormationServer *m_pFormationServer;  //  编队服务器指针

		CFMS          *m_pFMS;  //  飞管系统指针
		CAirSpeed     *m_pAS;   //  空速系统指针

		stPerformance *m_pPer;  //  性能数据包指针

	private:

		double m_dTFilter_HdG;  //  地形起伏滤波器时间常数

	};


}  //  namespace end


#endif
