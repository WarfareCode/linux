//
//  MyMath.h :  我的数学库
#include "BwVehicleKinematic.h"
#include "MyType.h"

//
//  2 维向量与 2 阶方阵函数与操作符集
//

namespace BW_VEHICLEKINEMATIC
{
	class CVector2;
	class CVector3;
	class CMatrix22;
	class CMatrix33;

	CVector2 vec2( double x, double y );
	CVector2 operator*( CMatrix22 m, CVector2 a );
	CMatrix22 operator*( CMatrix22 a, CMatrix22 b );
	CMatrix22 get_m2_1( CMatrix22 a );

	//
	//  3 维向量与 3 阶方阵函数与操作符集
	//

	CVector3 vec3( double x, double y, double z );
	CVector3 operator+( CVector3 a, CVector3 b );
	CVector3 operator-( CVector3 a, CVector3 b );
	CVector3 operator-( CVector3 a );
	CVector3 operator*( CVector3 a, CVector3 b );
	CVector3 operator*( double a, CVector3 b );
	CVector3 operator*( CVector3 a, double b );
	CVector3 operator/( CVector3 a, double b );
	CVector3 operator*( CMatrix33 m, CVector3 a );
	CMatrix33 operator*( CMatrix33 a, CMatrix33 b );
	CMatrix33 operator+( CMatrix33 a, CMatrix33 b );
	CMatrix33 operator-( CMatrix33 a, CMatrix33 b );
	CMatrix33 operator-( CMatrix33 a );
	CMatrix33 get_m_1( CMatrix33 a );
	double get_rc3( CMatrix33 a );
	CMatrix33 get_adj3( CMatrix33 a );
	CMatrix33 mat_T( CMatrix33 a );

	//
	//  插值函数集
	//

	double  lag12( double*xs, double*ys, int n, double x );//, int warning );
	double  lag12( bool bLimitL, bool bLimitR, double*xs, double*ys, int n, double x );//, int warning );
	double  lag22( double*xs,double*ys,double*fs,int m,int n,double x,double y );//, int warning );
	double  lag22( double*xs,double*ys,double*fs,int m,int n,double x,double y, int Saturation );
	double  lag32( double*xs,double*ys,double*zs,double*fs,int l,int m,int n,double x,double y,double z, int Saturation );
	double  lag32( double*xs,double*ys,double*zs,double*fs,int l,int m,int n,double x,double y,double z );//, int warning );
	double  lag13( double*xs, double*ys, int n, double x );//, int warning );
	double dydx13( double*xs, double*ys, int n, double x );//, int warning );
	double dydx13( bool bLimitL, bool bLimitR, double*xs, double*ys, int n, double x );
	//  坐标对弧长的导数(2005,06,01.)
	//double dxds13( CVector3 *ss, double*xs, int n, CVector3 s );

	//
	//  其它
	//
	double sign( double a );
	int exp10(int n);
	double exp2(int n);

	//  控制系统
	double fader( double u0, bool b, double *pk, double dk, double x );

	double DeadZone( double DZL, double DZR, double x );

	double Saturation( double Min, double Max, double x );

	//  获得坐标转换矩阵（根据动系相对于参考系的偏航角、俯仰角和滚转角）
	CMatrix33 get_MBG( double psai_rad, double pitch_rad, double gama_rad );

	//  计算两点之间的地球表面相对坐标（根据两点的经纬度。采用定航向法，而非大圆法，因此适合于较短的距离）
	void cal_coord( double *pDxg, double *pDzg, double lati0, double longi0, double lati1, double longi1 );

	//  计算两点之间的地球表面相对坐标（根据两点的经纬度。采用定航向法，而非大圆法，因此适合于较短的距离）
	CVector3 get_Dr( double lati0, double longi0, double alti0, double lati1, double longi1, double alti1 );

	//  获得两点之间的空间距离（根据两点的经纬高。适用于较近的距离）
	double get_distance( double alti1, double lati1, double longi1, double alti2, double lati2, double longi2 );

	//  获得球面上两点之间的大圆圆心角（根据两点的经纬度）
	double get_AInGC( double lati1, double longi1, double lati2, double longi2 );

	//  获得球面两点之间的大圆弧长（根据两点的经纬度。）
	double get_SInGC( double lati1, double longi1, double lati2, double longi2 );

	//  获得两点之间的地球表面水平距离/大圆弧长（根据两点的经纬度。采用定航向法/大圆法）
	double get_SInGC( double lati1, double longi1, double lati2, double longi2 );

	//  计算纬度和经度（根据一点的纬度和经度，以及另一点相对它的坐标。定航向法，而非大圆法，因此适合于较短的距离）
	void cal_latilongi( double *plati1, double *plongi1, double lati0, double longi0, double Dxg, double Dzg );

	//  获得三维向量的模和水平模
	double mod( CVector3 r );
	double mod_h( CVector3 r );

	//  获得向量 V 的俯仰角和偏航角
	double get_PitchV( CVector3 V );
	double get_PsaiV( CVector3 V );

	//  获得空间两点之间在地面系的俯仰角和偏航角（定航向法，而非大圆法，因此适合于较短的距离）
	double get_Pitch(  double alti0, double lati0, double longi0, double alti1, double lati1, double longi1 );
	double get_Psai(  double lati0, double longi0, double lati1, double longi1 );

	//  获得地面系到地心系的坐标旋转矩阵（根据地面系原点的经纬度）
	CMatrix33 get_MEC( double lati, double longi );

	//  获得空间一点的直角坐标（根据其球半径、纬度和经度）
	CVector3 get_GlobeCoord( double r, double cla, double sla, double clg, double slg );

	//  获得空间一点的球坐标（根据其直角坐标）
	CVector3 get_GlobeCoordG( double x, double y, double z );  //  返回值依次为：半径，纬度，经度

	//  获得短弧
	double get_ShortArc( double angle_deg );

}