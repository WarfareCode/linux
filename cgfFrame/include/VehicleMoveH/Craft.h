// Craft.h: interface for the CCraft class.
//
//////////////////////////////////////////////////////////////////////

#ifndef Craft_h
#define Craft_h

#include "BwVehicleKinematic.h"
#include "FCS.h"	// Added by ClassView
#include "FMS.h"	// Added by ClassView
#include "AirSpeed.h"	// Added by ClassView
#include "MyType.h"	// Added by ClassView
#include "Environment.h"	// Added by ClassView
#include "interface.h"	// Added by ClassView


namespace  BW_VEHICLEKINEMATIC {


#define NE 10
	class CFormationServer;
	class CFCS;
	class CFMS;
	class CAirSpeed;
	class CEnvironment;
	class CVector3;
	class CMatrix33;

	class  BW_VEHICLEKINEMATIC_API  CCraft  //  车辆类。适用于固定翼飞机、直升机、导弹、陆地车辆、水面船只、潜艇等
	{
	public:
		//  设置编队服务器
		void set_formation( bool b, int iPositionID, CFormationServer *pFormationServer );

		//  计算空速向量
		void cal_AirSpeed( void );

		//  计算海浪影响
		void cal_WavePara( void );

		//  运动限制
		void motion_limit( void );

		//  加油
		void refueling( );

		//  单步运行函数
		void tick_craft( double Dt, double altiG_m );

		//  计算辅助参数
		void cal_ParaAux( void );

		//  龙格-库塔积分函数
		void RK4( int n, int io, double h, double*y, double*doy, double*b, double*c );

		//  微分方程组（运动模型）
		void dery( int n, double*y, double*doy );

		//  自定义初始化函数
		void ini_Craft( int iUnitID, double alti_m, double lati_deg, double longi_deg, double head_deg, double GroundSpeed_kmph, double teta_deg );

		//  补充构建函数
		void con_Craft( CEnvironment *p, stPerformance stPerformanceData );

		CCraft();
		virtual ~CCraft();

		bool m_bFormationServerOK;  //  编队服务器可用

		bool m_bInSurface;  //  面内运动标志（飞机和直升机可在地面内运动，潜艇可在水面内运动，陆基车辆和水面舰船总是在水面内运动。运动方程有特殊性）

		//  用于数值积分的数组
		double m_y[NE], m_doy[NE], m_b[NE], m_c[NE];

		//  各参数的指针
		double  *pTime;       //  0: 名义时间 ( s )
		double  *pvg;         //  1: 地速 ( m/s )
		double  *pTeta;       //  2: 航迹俯仰角 ( rad/s )
		double  *pPsais;      //  3: 航迹偏航角 ( rad/s )
		double  *pGamas;      //  4: 航迹滚转角 ( rad/s )
		double  *pxg;         //  5: 质心位置在地面系 x 轴的投影 ( m )
		double  *pyg;         //  6: 质心位置在地面系 y 轴的投影 ( m )
		double  *pzg;         //  7: 质心位置在地面系 z 轴的投影 ( m )
		double  *pLongitude;  //  8: 经度 ( rad )
		double  *pLatitude;   //  9: 纬度 ( rad )

		double  *pTimed;       //  0: 名义时间变化率 ( s/s )
		double  *pvgd;         //  1: 地速变化率 ( m/s/s )
		double  *pTetad;       //  2: 航迹俯仰角变化率 ( rad/s/s )
		double  *pPsaisd;      //  3: 航迹偏航角变化率 ( rad/s/s )
		double  *pGamasd;      //  4: 航迹滚转角变化率 ( rad/s/s )
		double  *pxgd;         //  5: 质心位置在地面系 x 轴的投影变化率 ( m/s )
		double  *pygd;         //  6: 质心位置在地面系 y 轴的投影变化率 ( m/s )
		double  *pzgd;         //  7: 质心位置在地面系 z 轴的投影变化率 ( m/s )
		double  *pLongituded;  //  8: 经度 ( rad )
		double  *pLatituded;   //  9: 纬度 ( rad )

		double m_dHeading;  //  真航向 ( deg )

		double m_dvgv;  //  垂直地速，m/s
		double m_dvgh;  //  地速水平分量，m/s
		double m_dsH;   //  水平面航迹弧长，m
		double m_ds;    //  航迹弧长，m

		double m_dRemainDistance_km;  //  剩余飞行距离
		double m_dRemainTime;      //  剩余飞行时间（s）

		bool m_bCraftReady;  //  飞机准备好

		int m_iCrash;  //  撞毁变量

		//  海浪对船舶的影响。2017-02-25，26。
		double m_dE_WaveSpeed;  //  波速（米/秒）2017-07-15
		double m_dE_WaveLenth;  //  波长（米）   2017-07-15
		double m_dE_WaveOmg;    //  角频率   ( rad/s )
		double m_dE_WaveHd;     //  浮沉速率 ( m/s )
		double m_dE_WaveH;      //  浮沉量   ( m   )
		double m_dE_WavePitch;  //  俯仰量   ( rad )
		double m_dE_WaveBank;   //  滚转量   ( rad )

		//  空速向量。2017-09-12。
		double m_dAir_speed;  //  对空气速度( m/s )
		double m_dAir_teta;   //  对空气轨迹角( rad )
		double m_dAir_psai;   //  对空气偏航角( rad )

		//  视景输出量
		double m_dEye_Alti;
		double m_dEye_Lati;
		double m_dEye_Longi;
		double m_dEye_Pitch;
		double m_dEye_Gama;
		double m_dEye_Psai;

		//  飞行控制变量
		double m_dnxO;  //  当前推重比
		double m_dnyO;  //  当前法向过载增量
		double m_dnzO;  //  当前侧向过载

		double m_dStep;  //  积分步长

		//	int m_iVehicleType;  //  车辆类型

		//  能量消耗属性
		//	double m_dTimeEquivalence;  //  当量飞行时间
		double m_dEnergyRemain;  //  剩余能量（%）

		double m_dq0;  //  最小燃油流量
		double m_dkq_n;  //  燃油对推力的消耗系数

		//  属性或物理子系统
		//	CFormationServer *m_pFormationServer;  //  编队服务器指针
		CFormationServer *m_pFormationServer;  //  编队服务器指针

		CFMS          m_cFMS;           //  飞管系统
		CFCS          m_cFCS;           //  飞控系统
		CAirSpeed     m_cAS;            //  空速系统
		stPerformance m_cPerformance;   //  性能参数
		CEnvironment  *m_pEnvironment;  //  环境类指针

		//  本机在机群中的位置号。2017-12-17
		int m_iPositionID;

		//  本机识别号。2017-12-17
		int m_iUnitID;

	private:

		//  如果本“车辆”为航母，则其几何参数如下
		//  着陆跑道与拦阻索参数
		double m_dLandingHead;  //  着陆跑道航向（相对于舰体纵轴）

		double m_dxBlocks[4];  //  拦阻索纵向位置（着陆跑道坐标系）
		double m_dzBlock;      //  拦阻索侧向坐标（着陆跑道坐标系。对称布置）
		double m_dyBlock;      //  拦阻索距甲板高度

		CVector3  m_rORWLD;  //  着陆跑道坐标系原点在航母本体系的坐标
		CMatrix33 m_MC_CRW;  //  航母本体系到着陆跑道系的坐标转换矩阵

		//  弹射轨道始终点位置（本体系）

		//  航母甲板水平轮廓数据
		double m_dXs[7];
		double m_dZLs[7];
		double m_dZRs[7];
	};

#undef NE

}  //  namespace end

#endif
