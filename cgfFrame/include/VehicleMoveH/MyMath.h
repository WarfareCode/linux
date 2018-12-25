//
//  MyMath.h :  �ҵ���ѧ��
#include "BwVehicleKinematic.h"
#include "MyType.h"

//
//  2 ά������ 2 �׷��������������
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
	//  3 ά������ 3 �׷��������������
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
	//  ��ֵ������
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
	//  ����Ի����ĵ���(2005,06,01.)
	//double dxds13( CVector3 *ss, double*xs, int n, CVector3 s );

	//
	//  ����
	//
	double sign( double a );
	int exp10(int n);
	double exp2(int n);

	//  ����ϵͳ
	double fader( double u0, bool b, double *pk, double dk, double x );

	double DeadZone( double DZL, double DZR, double x );

	double Saturation( double Min, double Max, double x );

	//  �������ת�����󣨸��ݶ�ϵ����ڲο�ϵ��ƫ���ǡ������Ǻ͹�ת�ǣ�
	CMatrix33 get_MBG( double psai_rad, double pitch_rad, double gama_rad );

	//  ��������֮��ĵ������������꣨��������ľ�γ�ȡ����ö����򷨣����Ǵ�Բ��������ʺ��ڽ϶̵ľ��룩
	void cal_coord( double *pDxg, double *pDzg, double lati0, double longi0, double lati1, double longi1 );

	//  ��������֮��ĵ������������꣨��������ľ�γ�ȡ����ö����򷨣����Ǵ�Բ��������ʺ��ڽ϶̵ľ��룩
	CVector3 get_Dr( double lati0, double longi0, double alti0, double lati1, double longi1, double alti1 );

	//  �������֮��Ŀռ���루��������ľ�γ�ߡ������ڽϽ��ľ��룩
	double get_distance( double alti1, double lati1, double longi1, double alti2, double lati2, double longi2 );

	//  �������������֮��Ĵ�ԲԲ�Ľǣ���������ľ�γ�ȣ�
	double get_AInGC( double lati1, double longi1, double lati2, double longi2 );

	//  �����������֮��Ĵ�Բ��������������ľ�γ�ȡ���
	double get_SInGC( double lati1, double longi1, double lati2, double longi2 );

	//  �������֮��ĵ������ˮƽ����/��Բ��������������ľ�γ�ȡ����ö�����/��Բ����
	double get_SInGC( double lati1, double longi1, double lati2, double longi2 );

	//  ����γ�Ⱥ;��ȣ�����һ���γ�Ⱥ;��ȣ��Լ���һ������������ꡣ�����򷨣����Ǵ�Բ��������ʺ��ڽ϶̵ľ��룩
	void cal_latilongi( double *plati1, double *plongi1, double lati0, double longi0, double Dxg, double Dzg );

	//  �����ά������ģ��ˮƽģ
	double mod( CVector3 r );
	double mod_h( CVector3 r );

	//  ������� V �ĸ����Ǻ�ƫ����
	double get_PitchV( CVector3 V );
	double get_PsaiV( CVector3 V );

	//  ��ÿռ�����֮���ڵ���ϵ�ĸ����Ǻ�ƫ���ǣ������򷨣����Ǵ�Բ��������ʺ��ڽ϶̵ľ��룩
	double get_Pitch(  double alti0, double lati0, double longi0, double alti1, double lati1, double longi1 );
	double get_Psai(  double lati0, double longi0, double lati1, double longi1 );

	//  ��õ���ϵ������ϵ��������ת���󣨸��ݵ���ϵԭ��ľ�γ�ȣ�
	CMatrix33 get_MEC( double lati, double longi );

	//  ��ÿռ�һ���ֱ�����꣨��������뾶��γ�Ⱥ;��ȣ�
	CVector3 get_GlobeCoord( double r, double cla, double sla, double clg, double slg );

	//  ��ÿռ�һ��������꣨������ֱ�����꣩
	CVector3 get_GlobeCoordG( double x, double y, double z );  //  ����ֵ����Ϊ���뾶��γ�ȣ�����

	//  ��ö̻�
	double get_ShortArc( double angle_deg );

}