
#ifndef __BW_Coordinates_H__
#define __BW_Coordinates_H__

#pragma once

#include "BwCal.h"
#include "BwMath.h"
#include "BwPt.h"

//来源： Delta3D DtUtil
//修改：皮学贤，2009年11月
//功能：坐标转换有关的常数与函数
//以函数有形式，实现UTM、GeoDetic、GeoCentric三种坐标之间的转换
// 地球参考系采用WGS84

namespace BwCal
{
	const double MUSE_PI   = 3.14159265358979323846;
	const double MAX_DELTA_LONG  = ( MUSE_PI * 90/180.0);		/* 90 degrees in radians */

	//const double MIN_LAT = ( (-80.5 * BwCal::Math::ONE_PI) / 180.0 );		/* -80.5 degrees in radians    */
	//const double MAX_LAT = ( (84.5 * BwCal::Math::ONE_PI) / 180.0 );		/* 84.5 degrees in radians     */
	//const double MIN_EASTING = 100000;
	//const double MAX_EASTING = 900000;
	//const double MIN_NORTHING = 0;
	//const double MAX_NORTHING = 10000000;
	//const double MIN_SCALE_FACTOR = 0.3;
	//const double MAX_SCALE_FACTOR = 3.0;
	//const double COS_67P5 = 0.38268343236508977;  /* cosine of 67.5 degrees */
	//const double AD_C     =  1.0026000;            /* Toms region 1 constant */

	// 地球平均半径,xks,20160709
	const double RE= 6371000;//地球平均半径m
	const double E_e = 0.0818133340169312L;				// 地球椭圆体第一偏心率e
	const double E_e_2 = 	0.0409066670084656L;		// 地球椭圆体第一偏心率e/2
	const double w_e = 7.292115e-5;							// 地球平均自转角速度，rad/s
	const double GM = 398600.4405;							// 地球引力常数，km^3/(s^2)

	//The reciprocal of the flattening parameter (WGS 84).
	const double flatteningReciprocal = 298.257223563;
	// The length of the semi-major axis, in meters (WGS 84).
	const double semiMajorAxis = 6378137.0;
	// Ellipsoid parameters in WGS 84 
	const double Geocent_a = semiMajorAxis;						/* Semi-major axis of ellipsoid in meters */
	const double Geocent_f = 1 / flatteningReciprocal;			/* Flattening of ellipsoid           */
	const double Geocent_e2 = (2.0 - Geocent_f) * Geocent_f;	/* Eccentricity squared  */
	const double Geocent_ep2 = Geocent_e2 / (1.0 - Geocent_e2); /* 2nd eccentricity squared */
	const double Geocent_ef = Geocent_f / (2.0 - Geocent_f);
	const double Geocent_ef_3 = Geocent_ef * Geocent_ef * Geocent_ef;
	const double Geocent_ef_4 = Geocent_ef_3 * Geocent_ef;
	const double Geocent_e2_2 = Geocent_e2 * Geocent_e2;
	const double Geocent_e2_3 = Geocent_e2_2* Geocent_e2;

	///Scale used in UTM calculations.
	const double CentralMeridianScale = 0.9996;
	const double MagneticNorthLatitude  = 82.116; 
	const double MagneticNorthLongitude = 114.0666;

	// Semi-minor axis of ellipsoid, in meters 
	const double Geocent_b = Geocent_a * (1 - Geocent_f);

	//===========================================================================================================================================
	static double	TranMerc_a =  6378137.0;					/* Semi-major axis of ellipsoid i meters */
	static double	TranMerc_es = 0.0066943799901413800;		/* Eccentricity (0.08181919084262188000) squared */

	// * Isometeric to geodetic latitude parameters, default to WGS 84 */
	static double   TranMerc_ap = 6367449.1458008;
	static double   TranMerc_bp = 16038.508696861;
	static double   TranMerc_cp = 16.832613334334;
	static double   TranMerc_dp = 0.021984404273757;
	static double   TranMerc_ep = 3.1148371319283e-005;

	// * Transverse_Mercator projection Parameters */
	static double  TranMerc_Origin_Lat = 0.0;           /* Latitude of origin in radians */
	static double  TranMerc_Origin_Long = 0.0;          /* Longitude of origin in radians */
	static double  TranMerc_False_Northing = 0.0;       /* False northing in meters */
	static double  TranMerc_False_Easting = 0.0;        /* False easting in meters */
	static double  TranMerc_Scale_Factor = 1.0;         /* Scale factor  */

	//* Maximum variance for easting and northing values for WGS 84. */
	static double  TranMerc_Delta_Easting  = 40000000.0;
	static double  TranMerc_Delta_Northing = 40000000.0;

	//* Ellipsoid Parameters, default to WGS 84  */
	static double TranMerc_f = Geocent_f;				/* Flattening of ellipsoid  */
	static double TranMerc_ebs = 0.0067394967565869;	/* Second Eccentricity squared */
	
	//-------------------------------------------------------------------------------------------------------------------------------------------
	// 测试可用，满足精度要求
	// 1-1) 地心坐标==>地理坐标，输入数据以米为单位，输出数据以“弧度”为单位
	// 此函数原来的经度正负号不对，已经修正！
	BW_CAL_API void  GeocentricToGeodetic(double x, double y, double z, double& latitude, double& longitude,   double& elevation);

	// 1-2) 地理坐标==>地心坐标，输入数据为“弧度”为单位，输出数据以米为单位
	// 此函数原来的y值正负号不对，已经修正！
	BW_CAL_API void  GeodeticToGeocentric(double phi, double lambda, double elevation, double& x, double& y, double& z);
	//===========================================================================================================================================


	//-------------------------------------------------------------------------------------------------------------------------------------------
	// 测试可用，满足精度要求
	// 2-1) 地心坐标==>地理坐标，输入数据以米为单位， 输出数据以“度”为单位， 
	// 此函数原来的经度正负号不对，已经修正！
	BW_CAL_API void  GeocentricToGeodeticInDegree(double x, double y, double z,double& latitude, double& longitude, double& elevation);

	// 2-2) 地理坐标==>地心坐标，输入数据为“度”为单位，输出数据以米为单位
	// 此函数原来的y值正负号不对，已经修正！
	BW_CAL_API void  GeodeticInDegreeToGeocentric(double latitude, double longitude, double elevation,double& x, double& y, double& z);
	//===========================================================================================================================================
	

	//-------------------------------------------------------------------------------------------------------------------------------------------
	// 计算测地坐标系到局部坐标系转换时的系数 2010-12-22 （输入数据为弧度为单位）
	BW_CAL_API bool  CalculateGeodeticToUTMDiffCoeff( double lat, double longi, double height, double&latCoeff, double &longiCoeff );
	//===========================================================================================================================================

	/**
	* The function ConvertGeodeticToUTM converts geodetic (latitude and
	* longitude) coordinates to UTM projection (zone, hemisphere, easting and
	* northing) coordinates according to the current ellipsoid and UTM zone
	* override parameters.  Code taken from http://earth-info.nga.mil/GandG/geotrans/
	*
	* @param   Latitude          : Latitude in radians                 (input)
	* @param   Longitude         : Longitude in radians                (input)
	* @param   Zone              : UTM zone                            (output)
	* @param   Hemisphere        : North or South hemisphere           (output)
	* @param   Easting           : Easting (X) in meters               (output)
	* @param   Northing          : Northing (Y) in meters              (output)
	*/
	BW_CAL_API void ConvertGeodeticToUTM(double Latitude, double Longitude, unsigned& Zone, 
		char  &Hemisphere, double& Easting, double& Northing); 
	
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
   /* @param   Latitude          : Latitude in  Degree                 (input)
	* @param   Longitude         : Longitude in Degree                (input)
	* @param   Zone              : UTM zone                            (output)
	* @param   Hemisphere        : North or South hemisphere           (output)
	* @param   Easting           : Easting (X) in meters               (output)
	* @param   Northing          : Northing (Y) in meters              (output)
	*/
	BW_CAL_API void ConvertGeodeticInDegreeToUTM(double Latitude, double Longitude, unsigned& Zone, 
		char  &Hemisphere, double& Easting, double& Northing); 

	/**
	* The function ConvertUTMToGeodetic converts UTM projection (zone, easting and
	* northing) to geodetic (latitude and longitude) coordinates according to the current ellipsoid 
	* and UTM zone override parameters.
	*
	* @param   zone              : UTM zone (east west)                (input)
	* @param   easting           : Easting (X) in meters               (input)
	* @param   northing          : Northing (Y) in meters              (input)
	* @param   latitude          : Latitude in radians                 (output)
	* @param   longitude         : Longitude in radians                (output)
	*/
	BW_CAL_API void ConvertUTMToGeodetic(unsigned zone, double easting, double northing, double& latitude, double& longitude); 

	/**
	* Calculates the proper UTM zone based on the latitude and longitude.
	* 
	* @param latitude the latitude position for the zone.
	* @param longitude the longitude position for the zone.
	* @param ewZone the east west zone number.  This the normal UTM zone used in calculations.
	* @praam nsZone the north-south zone letter.
	* 如果纬度越界则返回FALSE
	*/
	BW_CAL_API bool CalculateUTMZone(double latitude, double longitude, unsigned& ewZone, char& nsZone);

	/*
	* The function ConvertGeodeticToTransverse_Mercator converts geodetic
	* (latitude and longitude) coordinates to Transverse Mercator projection
	* (easting and northing) coordinates, according to the current ellipsoid
	* and Transverse Mercator projection coordinates.  
	*
	* @param   Latitude      : Latitude in radians                         (input)
	* @param   Longitude     : Longitude in radians                        (input)
	* @param   Easting       : Easting/X in meters                         (output)
	* @param   Northing      : Northing/Y in meters                        (output)
	*/
	BW_CAL_API void ConvertGeodeticToTransverseMercator (double Latitude, double Longitude,double& Easting, double& Northing);
		
	
	/*
	* The function SetTranverseMercatorParameters receives the ellipsoid
	* parameters and Tranverse Mercator projection parameters as inputs, and
	* sets the corresponding state variables. 
	* Code taken from http://earth-info.nga.mil/GandG/geotrans/
	*
	* @param   a                 : Semi-major axis of ellipsoid, in meters					(input)
	* @param   f                 : Flattening of ellipsoid									(input)
	* @param   Scale_Factor      : Projection scale factor									(input) 
	*/
	BW_CAL_API void SetTransverseMercatorParameters(double a, double f, double Origin_Latitude,double Central_Meridian, \
										double False_Easting,	double False_Northing, double Scale_Factor);

	//* 缺省设置局部坐标系
	//* @param   Origin_Latitude   : Latitude in radians at the origin of the projection	(input)
	//* @param   Central_Meridian  : Longitude in radians at the center of the  projection	(input)                  
	//* @param   False_Easting     : Easting at the center of the projection				(input)
	//* @param   False_Northing    : Northing at the center of the projection				(input)
	BW_CAL_API void SetArsTransverseMercatorParams( double Origin_Latitude,double Central_Meridian, double False_Easting,	double False_Northing );

	double SPHTMD(double Latitude) ;         
	double SPHSN(double Latitude) ; 
	double DENOM(double Latitude) ;
	double SPHSR(double Latitude) ; 

	BW_CAL_API  double DegreesToRadians(double angle);
	BW_CAL_API  double RadiansToDegrees(double angle);
	
	// 两个LLE格式的较近点的最短水平距离（近似）
	BW_CAL_API double  ShortestHorizDisNearLLEs( BwCal::GeoPt  , BwCal::GeoPt  );
	// 两个LLE格式的较近点的最短距离（近似）
	BW_CAL_API double ShortestDistanceNearLLEs( BwCal::GeoPt  , BwCal::GeoPt  );

	// 根据两点之间的LLE值，计算姿态矢量
	BW_CAL_API Vec3 UTMCalculateGRPose( BwCal::GeoPt  , BwCal::GeoPt  );
	// 
	BW_CAL_API Vec3 CartCalculateVel( BwCal::GeoPt  , BwCal::GeoPt , double lfCuriseVel  );

	// 两个LLE点的指定方向距离 2011-07-06
	// 暂不用,返回0
	BW_CAL_API double SphericDirectionDistance( const BwCal::GeoPt lleA , const BwCal::GeoPt lleB );

	// 两个LLE点的大球距离 2011-07-06
	// 暂不用,返回0
	BW_CAL_API double SphericBigCircleDistance( const BwCal::GeoPt lleA , const BwCal::GeoPt lleB );

	// 水平坐标外推 2011-07-06
	// 使用规则：单次外推距离不能太远，距离越小推算结果越精确，远距离可通过多次推算实现
	// 适用于中低速运动推算，空间高速运动不建议使用，且没有高度变化
	// 说明：经纬度及角度均以“度”为单位，距离以"米"为单位
	// 输入参数：起始点，距离，方向角
	// 输出参数：目的点
	BW_CAL_API void PreCalulateGeoCoordinate( const GeoPt lleStart, double dis, double heading, GeoPt& lleDest );
	
	// 点关系计算 皮学贤 2011-07-09
	// 经测试，距离、方位角满足精度要求；pitch是通过二者高度差来比较的，有特殊含义，见下面注意。
	// 输入参数：
	//		1) lleStart：	起始点(纬度、经度、高度)，度、米
	//		2) lleEnd：		结束点(纬度、经度、高度)，度、米
	// 输出参数：
	//		1) heading：方向角，度，-180～180
	//		2) pitch：	俯仰角，度，-90～90
	//     注意：当二者高度相同时，pitch=0，因此，此pitch并不是以起始点的地平坐标系为参考系计算的。
	//               如果要以起始点的地平坐标系为参考系计算高低角，请使用GeodeticInDegreeToTopocentricPolar()函数或其它与站心地平系相关的函数。
	// 返回值：
	//		两点间空间距离，米
	BW_CAL_API double CalculateHeadingPitch( const GeoPt lleStart, const GeoPt lleEnd, double& heading, double& pitch );


	// 2014-10-21 新增
	// -------From HY xks-------
	
	// 计算地球上两点的最小球面距离和方位
	// 输入：LocalPoint,DTPoint
	// 输出：dis(单位-m),Angle(单位-度,0-360度,两点连线相对真北的夹角,顺时针方向)
	BW_CAL_API int CacuTotalDistance(GeoPt LocalPoint, GeoPt DTPoint, double* dis,double* Angle);
	inline  double CalcltDirct(double   fStarPtx,   double   fStarPty,   double   fEndPtx,   double   fEndPty);
	inline double IPC_LSX (GeoPt gp1, GeoPt gp2, double& dbDist, double& dbCrs = *(double*)NULL);

	// 2016-07-09 
	// //////////////////////////////////////////////////////////////////////////
	//将地球作为球面时，近似计算函数
	//通过已知的位置(经纬高度)、速度方向、运动时间，计算运动后的位置(经纬高度)
	//速度为m/s
	//pitch为俯仰角(实际上应该是速度方向与水平面的夹角，这里做近似处理)：degree(-90度～90度),在地面上运动的实体的pitch为0度
	//course为航向角(速度在水平面上的投影与真北方向的夹角)：degree(向真北为0度,顺时针方向为正，0度～360度)
	//dT为间隔时间：s
	//currentPos为当前点的大地坐标(纬度,经度,高度)
	//nextPos为运动dT时间之后的大地坐标(纬度,经度,高度)，引用传递
	//by xks
	//////////////////////////////////////////////////////////////////////////
	//目前适用于在东经0-180度、北纬0-90度范围内运动的实体,其它范围未验证
	//////////////////////////////////////////////////////////////////////////

	BW_CAL_API void MovePosCalculate(GeoPt currentPos,GeoPt & nextPos,double velocity,
		double pitch,double course,double dT);

	//通过两点的大地坐标，判断pos2是否在pos1的视野中，近似计算
	//以pos1为基准点
	//是返回1，否返回0
	//by xks
	BW_CAL_API bool IsInVisualField(GeoPt pos1,GeoPt pos2);

	//////////////////////////////////////////////////////////////////////////
	// 2017-05-18
	// 以下大地主题计算函数经测试可用，返回数值均满足精度要求

	// 地心坐标系：以地球椭球中心为原点，x指向零度经线，y指向90度经线，右手坐标系
	// 地理（大地）坐标系：纬度、经度、高度
	// 站心地平直角坐标系：站心为原点，东、北、天为x、y、z轴，右手坐标系
	// 站心地平极坐标系: r--与站心的直线距离；Az--方位角，与真北的夹角，顺时针为正，-180~180；El--高低角，向上为正，-90~90

	// (5-1) 地心坐标到大地（地理）坐标
	// pcg: deg
	// pcc: m
	BW_CAL_API void GeocentricToGeodeticInDegree(GeoPt &pcg, Vec3 pcc);

	// (5-2) 由大地坐标转换为地心坐标
	// pcc: m
	// pcg: deg
	BW_CAL_API void GeodeticInDegreeToGeocentric(Vec3 &pcc, GeoPt pcg);

	// (5-3) 由地心坐标转换为站心地平直角坐标
	// pcc: 被转换点的地心坐标, m
	// pccCenter: 站心坐标原点（地心坐标）, m
	// pct: 站心地平坐标, m
	BW_CAL_API void GeocentricToTopocentric(TopoCentric &pct, Vec3 pcc, Vec3 pccCenter);

	// (5-4) 站心地平直角坐标转换到地心坐标
	// pct: 站心地平坐标, m
	// pccCenter: 站心坐标原点（地心坐标）, m
	// pcc: 被转换点的地心坐标, m
	BW_CAL_API void TopocentricToGeocentric(Vec3 &pcc, TopoCentric pct, Vec3 pccCenter);

	// (5-5) 由大地坐标转换为站心地平直角坐标
	// pcc: 被转换点的大地坐标, deg
	// pccCenter: 站心坐标原点（大地坐标）, deg
	// pct: 站心地平坐标, m
	BW_CAL_API void GeodeticInDegreeToTopocentric(TopoCentric &pct, GeoPt pcc, GeoPt pccCenter);

	// (5-6) 由站心地平直角坐标转换为站心地平极坐标
	// pct: m
	// pctp: m, deg, 其中Az：-180~180（北偏东为正），El：-90~90
	BW_CAL_API void TopocentricToTopocentricPolar(TopocentricPolar &pctp, TopoCentric pct);

	// (5-7) 由站心地平极坐标转换为站心地平直角坐标
	// pctp: m, deg
	// pct: m
	BW_CAL_API void TopocentricPolarToTopocentric(TopoCentric &pct, TopocentricPolar pctp);

	// (5-8) 由大地坐标转换到站心地平极坐标
	// pcc: 被转换点的大地坐标, deg
	// pccCenter: 站心坐标原点（大地坐标）, deg
	// pctp: 站心地平极坐标, m, deg, 其中Az：-180~180，El：-90~90
	BW_CAL_API void GeodeticInDegreeToTopocentricPolar(TopocentricPolar &pctp, GeoPt pcc, GeoPt pccCenter);


	// (5-9) 由站心地平极坐标转换为大地坐标
	// pctp: 被转换点的站心地平极坐标, m, deg, 其中Az：-180~180，El：-90~90
	// pccCenter: 站心坐标原点（大地坐标）, deg
	// pcd: 被转换点的大地坐标, deg
	BW_CAL_API void TopocentricPloarToGeodeticInDegree(GeoPt &pcd, TopocentricPolar pctp, GeoPt pccCenter);


	//////////////////////////////////////////////////////////////////////////
	// 20170719
	/* 体轴系向站心（地轴系）转换
	// 体轴系定义：体质心为原点，（u-前, v-右, w-下），右手坐标系
	// 站心系/地轴系：体质心（站心）为原点，东、北、天为x、y、z轴，右手坐标系，同前
	// 本体姿态角定义：偏航角psai，右偏为正；俯仰角ksai，抬头为正；滚转角gama，右滚为正;
	// 输入：hpr--本体姿态，x,y,z分别对应psai, ksai, gama，单位：deg
				  BodyPos---体轴系坐标值，单位：m或m/s
		输出：ptc---站心坐标值，单位：m或m/s
*/
	BW_CAL_API void BodyCord2TopoCentric(TopoCentric &ptc , Vec3 hpr, Vec3 BodyPos);

	/* @J2000.地心惯性坐标系到PQW卫星轨道坐标系
		J2000坐标系定义：赤道平面， x-春分点，z-北极，y-， 右手系
		PQW坐标系定义： p-近地点，w-指向轨道的旋转轴，q-轨道平面内与p正交，，右手系
		输入：eci - ECI坐标(m或m/s)，i-轨道倾角（deg），O-升交点赤经（deg）, w-近地点幅角(deg)
		输出：pqw - PQW坐标（m或m/s），(x,y,z)对应(p,q,w)
	*/
	BW_CAL_API void ECI2PQW(Vec3 &pqw, Vec3 eci, double i, double O, double w);

	/* @PQW卫星轨道坐标系到J2000.地心惯性坐标系
		输入输出与前述相反，定义一致
	*/
	BW_CAL_API void PQW2ECI(Vec3 &eci, Vec3 pqw, double i, double O, double w);
	
	/* @J2000.地心惯性坐标系到ECF地心固连坐标系
		J2000坐标系定义：赤道平面， x-春分点，z-北极，y-， 右手系
		ECF定义：赤道平面，x-指向零度经线，z-北极，y-，右手系
		输入：eci - ECI坐标(m或m/s)，GST-Greenwich mean sidereal time，格林尼治平太阳时（deg）
		输出：ecf - ECF坐标（m或m/s）
	*/
	BW_CAL_API void  ECI2ECF(Vec3 &ecf, Vec3 eci, double GST);

	/* @ECF地心固连坐标系到J2000.地心惯性坐标系
		输入输出与前述相反，定义一致
	*/
	BW_CAL_API void  ECF2ECI(Vec3 &eci, Vec3 ecf, double GST);

	/* @ 获取 ECF地心固连坐标系到地面某点的ENU东北天坐标系 的转换矩阵
		@	该转换矩阵也适用于从ECI坐标系转换到赤纬、赤经所在点的ENU坐标系
		@ 可直接用于速度、矢量转换，但不能直接用于位置转换（未考虑平移）
		@	输入：phi-纬度（deg），lamda-经度（deg）
		@	输出：返回转换矩阵
	*/
	BW_CAL_API Matrix3 getM_ecf2enu(double phi, double lamda);

}

#endif //MUSE_COORDINATES_NAMESPACE
