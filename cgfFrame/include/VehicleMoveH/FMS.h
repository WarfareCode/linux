// FMS.h: interface for the CFMS class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FMS_H
#define FMS_H

#include "BwVehicleKinematic.h"
#include "MyType.h"	// Added by ClassView
#include "interface.h"	// Added by ClassView


namespace  BW_VEHICLEKINEMATIC {


	class  BW_VEHICLEKINEMATIC_API CFMS  //  飞行管理系统类（导航，飞管）
	{
	public:
		//  开始曲线导航
		void start_curve( bool b );

		//  修改曲线航线（iType：0-圆形；1-椭圆；8-8字形）
		void recreate_curve_route( double _a_m, double _b_m, double psai_rad, int iType, bool bCounterClockWise );

		//  航路点到达判断
		void ArriveDecide( );

		//  获得到指定航路点的距离
		double get_DistanceToPoint( int iRoute, int iPoint, double lati_rad, double longi_rad);

		//  单步运行
		void tick_FMS( double Dt, double omgyg_rad, double alti_m, double lati_rad, double longi_rad, double psai_rad, double pitch_rad, double gama_rad, double TAS_mps, double GS_mps, double teta_rad, double vx_mps, double vy_mps, double vz_mps );

		//  单步运行：曲线航线
		void tick_RouteCurve( double Dt, double vx_mps, double vy_mps, double vz_mps );

		//  单步运行：大圆航线
		void tick_Route( double Dt, double teta_rad );

		//  以当前位置为起点
		void start( );

		//  加载航线
		void load_route( int iRouteType );

		//  指定着陆航线
		void set_landing_route( double _RW_alti_m, double _RW_lati_rad, double _RW_longi_rad, double _RW_head_deg, int iLandingType );

		//  初始化函数
		void ini_FMS( double _RW_alti_m, double _RW_lati_rad, double _RW_longi_rad, double _RW_head_deg, double P0_alti_m, double P0_lati_rad, double P0_longi_rad, double P0_GS_mps, double P0_head_deg );

		//  补充构造函数
		void con_FMS( stPerformance *pPerformance );

		CFMS();
		virtual ~CFMS();

		//  开始
		bool m_bStart;  //  开始导航
		bool m_bStartCurve;  //  开始曲线导航模式（否则为大圆导航模式）

		//  纵向导航参数
		int    m_iRapidClass;  //  急迫等级（0：尽快；1：指定时间；2：指定速度）2016-05-14

		double V_dAltiPlan;  //  计划高度
		double V_dGSPlan;    //  计划速度
		double V_dDAlti;     //  高度偏差

		//  水平导航参数（适用于大圆导航 和 曲线导航）
		double H_dGamaBase;  //  基准坡度
		double H_dPsaiC;     //  应飞航向
		double H_dDPsai;     //  航向角偏差
		double H_dDz;        //  侧偏距

		//  大圆导航控制量
		int    C_iP0;       //  已完成航路点序号
		int    C_iTurning;  //  水平转弯（-2：向左调头；-1：左转弯；0：非转弯；1：右转弯；2：向右调头）
		double C_dRadius;   //  当前目标圆半径
		double C_dDPsaiC;   //  待转弯角

		//  曲线导航点状态
		bool RC_bCounterClockWise;  //  逆时针标志
		double RC_latiC;
		double RC_longiC;
		double RC_psai0;  //  长轴偏航角
		double RC_xg;  //  x 向坐标
		double RC_zg;  //  z 向坐标

		//  大圆航线飞行状态
		bool   R_bEnd;          //  航线覆盖完毕
		double R_dRangeRemain;  //  本航线剩余里程
		double R_dTimeRemain;   //  本航线剩余时间
		double R_dDistance0;    //  距上一目标点的水平距离
		double R_dDistance1;    //  距下一目标点的水平距离
		double R_dDistanceS0;   //  投影距上一目标点的距离
		double R_dDistanceS1;   //  投影距下一目标点的距离
		double R_dAlfa;         //  在本航段大圆极坐标系的极角
		//	double R_dTime0;      //  距上一目标点的时间
		double R_dTime1;      //  距下一目标点的时间
		double R_dRou;        //  转弯曲率半径
		double R_dPsaiC;      //  当前航线的航向
		double R_dDPsai;      //  偏航角差
		double R_dDz;         //  侧偏距

		//  飞机状态（米，秒，弧度）
		double m_dTrip;     //  行程
		double m_dTimeFly;  //  飞行时间
		double m_dAlti;     //  当前海拔高度
		double m_dLati;     //  当前纬度
		double m_dLongi;    //  当前经度
		double m_dPsai;     //  当前偏航角
		double m_dPitch;    //  当前俯仰角
		double m_dGama;     //  当前坡度
		double m_dTAS;      //  当前真空速
		double m_dGS;       //  当前地速
		double m_dTeta;     //  当前轨迹角

		double m_dRadiusBase_km;  //  距基地半径

		//  曲线在用航线
		CRouteCurve RCurve;  //  曲线航线（有默认值）

		//  大圆航线
		CRoute R;      //  当前在用航线
		CRoute RObj;   //  目标航线（非在用，可编辑）
		CRoute RBase;  //  基地航线（默认航线）

		//	CRoute RBaseC;  //  本场中航线
		//	CRoute RBaseL;  //  本场左航线
		//	CRoute RBaseR;  //  本场右航线

		//  基地参数
		int RW_LandingType;
		double RW_alti_m;
		double RW_lati_rad;
		double RW_longi_rad;
		double RW_head_deg;

		//  性能数据指针
		stPerformance *m_pPer;

	private:

		double m_dBankPlan;  //  计划转弯坡度
	};


}  //  namespace end


#endif
