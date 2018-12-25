// MyType.h: interface for My Type
//
//////////////////////////////////////////////////////////////////////

#ifndef MyType_h
#define MyType_h
#include "BwVehicleKinematic.h"

namespace  BW_VEHICLEKINEMATIC {


	//  二维向量
	class  BW_VEHICLEKINEMATIC_API CVector2  
	{
	public:

		CVector2();
		virtual ~CVector2();

		double x, y;
	};

	//  二阶方阵
	class  BW_VEHICLEKINEMATIC_API CMatrix22  
	{
	public:
		CMatrix22();
		virtual ~CMatrix22();

		double m[2][2];
	};

	//  三维向量
	class  BW_VEHICLEKINEMATIC_API CVector3  
	{
	public:
		CVector3();
		virtual ~CVector3();

		double x, y, z;
	};

	//  三阶方阵
	class  BW_VEHICLEKINEMATIC_API CMatrix33  
	{
	public:
		CMatrix33();
		virtual ~CMatrix33();

		double m[3][3];
	};


	//  大圆。如果没有说明，则单位为弧度、米、秒。

	class  BW_VEHICLEKINEMATIC_API CGreatCircle
	{
	public:
		void cal_ShadowInGreatCircle( double *platiS_rad, double *plongiS_rad, double *palfa_rad, double lati_rad, double longi_rad );

		double get_psai( double lati_rad, double longi_rad, double alfa_rad );

		double get_alfa( double x, double z );

		void set_GreatCircle( double lati1_rad, double longi1_rad, double lati2_rad, double longi2_rad );

		CGreatCircle();
		virtual ~CGreatCircle();

		double S;      //  两点间大圆弧长（地球大圆表面）
		double A;      //  两点间大圆圆心角

		double psai1;  //  起点的偏航角
		double psai2;  //  终点的偏航角

		double alfa1;  //  起点在大圆极轴系的极角
		double alfa2;  //  终点在大圆极轴系的极角

		double latiN;   //  大圆轴的纬度
		double longiN;  //  大圆轴的经度

		CVector3 V;  //  大圆轴向量

		CMatrix33 MGC_C;  //  大圆直角轴系转换矩阵
	};


	//  航路点。如果没有说明，则单位为弧度、米、秒。

	class  BW_VEHICLEKINEMATIC_API CRoutePoint
	{
	public:
		double get_alti( );
		double get_lati( );
		double get_longi( );
		double get_speed( );

		//  设置航路点
		void set_RoutePoint( double _lati_rad, double _longi_rad, double _alti_m, double _GS_mps, bool _bCross );

		CRoutePoint();
		virtual ~CRoutePoint();

		bool m_bCross;  //  要求过点标志。

	private:

		double GS;     //  地速
		double lati;   //  纬度
		double longi;  //  经度
		double alti;   //  海拔
	};


	//  大圆航线。如果没有说明，则单位为弧度、米、秒。

#define NRP 32  //  航路点最大数量

	class  BW_VEHICLEKINEMATIC_API CRoute 
	{
	public:
		//  滚动闭合航线
		bool roll_route( int iStart, bool bCounterClockWise );

		//  颠倒航线
		void reverse_route( void );

		//  获得航线中最后航路点的序号
		int get_iRPMax( );

		//  航线清零：将所有航路点的值置为当前点的值
		void clear_route( double alti_m, double lati_rad, double longi_rad );

		//  航线清零：将最后航路点序号设为 0
		void clear_route( );

		//  输入航路点（强制采用逐点顺序输入方式）
		bool input_point( double lati_rad, double longi_rad, double alti_m, double GS_mps, bool bCross );

		//  计算航线。从第 i 点开始计算到最后一点。
		void cal_routei_( int i, double alti_m, double lati_rad, double longi_rad, double GS_mps );

		//  计算航线。从第 1 点开始计算到最后一点。
		void cal_route1_( );

		CRoute();
		virtual ~CRoute();

		double m_dRouteRad;  //  航线总转角

		int m_i0;  //  航线起点

		double RangeDelta[NRP-1];  //  各航路点之间的距离（大圆弧长）
		double RangeRemain[NRP];   //  各航路点的剩余里程

		CGreatCircle GC[NRP-1];  //  各航段对应的大圆

		CRoutePoint RP[NRP];  //  航路点

	private:
		int m_iRPMax;  //  最后航路点序号
	};


	//  曲线航线。如果没有说明，则单位为弧度、米、秒。2016-07-07。

	class  BW_VEHICLEKINEMATIC_API CRouteCurve
	{
	public:
		//  求航线上某位置的极径
		double get_r( double A_deg );

		//  求航线上某位置的曲率半径
		double get_rou( double A_deg );

		//  求航线上某位置的航向
		double get_psai( double A_deg );

		//  生成曲线
		void create_curve( double _a, double _b, double psai0_rad, int iType, bool bCounterClockWise );

		CRouteCurve();
		virtual ~CRouteCurve();

		//  以中心点为原点的地轴系坐标（供图形显示用，导航不用）
		double xs[37];
		double zs[37];

	private:

		bool m_bCounterClockWise;  //  逆时针旋向（只适用于封闭曲线）

		int m_iType;  //  曲线类型。0：圆，1：椭圆；3：8字形

		double a;  //  长轴半径
		double b;  //  短轴半径
		double psai0;  //  长轴航向

		//  曲线函数数组
		double As[37];    //  极角，度
		double rs[37];    //  极半径
		double psais[37];  //  当地航向
		double rous[37];   //  当地曲率半径
	};

	//#undef NRP


#define NPos 6

	class BW_VEHICLEKINEMATIC_API CFormationServer  //  编队服务器。2017-12-15
	{
	public:

		//  设定队形位置参数
		bool set_pos( int iPos, double x_m, double y_m, double z_m );

		//  刷新。
		void refresh( int iPos, double longi_rad, double lati_rad, double alti_m, double v_mps, double teta_rad, double psais_rad, double gamas_rad, CVector3 v_rg_m, CVector3 v_vg_mps, CVector3 v_omg_radps );

		CFormationServer();
		virtual ~CFormationServer();

		//  各成员实际位置
		double f_longi_rad[NPos];
		double f_lati_rad[NPos];
		double f_alti_m[NPos];

		//  各成员目标位置（用于编队效果测试）。2018-03-17
		double f_obj_longi_rad[NPos];
		double f_obj_lati_rad[NPos];
		double f_obj_alti_m[NPos];

		double f_vg_obj[NPos];  //  僚机目标速度

		CVector3 v_delta_rNow[NPos];  //  僚机相对于站位的位置偏差
		CVector3 v_delta_vNow[NPos];  //  僚机相对于长机的速度
		CVector3 v_r_0_Now[NPos];     //  僚机相对于长机的位置偏差

		//  长机运动参数
		double f_alti0;
		double f_vg0;
		double f_teta0;
		double f_psais0;
		double f_gamas0;

		//  长机角速度投影于长机速度轴系
		CVector3 v_omg0;

		//  长机速度投影于地轴系
		CVector3 v_vg0;

		//  长机坐标
		//	CVector3 v_rg0;

		//  长机坐标转换矩阵：地轴系 -> 速度轴系
		CMatrix33 MVG0, MGV0;

		//  僚机在长机参考系的目标位置
		CVector3 v_delta_r_obj[NPos];

	};

#undef NPos


}  //  namespace end


#endif
