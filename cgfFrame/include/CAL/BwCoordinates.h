
#ifndef __BW_Coordinates_H__
#define __BW_Coordinates_H__

#pragma once

#include "BwCal.h"
#include "BwMath.h"
#include "BwPt.h"

//��Դ�� Delta3D DtUtil
//�޸ģ�Ƥѧ�ͣ�2009��11��
//���ܣ�����ת���йصĳ����뺯��
//�Ժ�������ʽ��ʵ��UTM��GeoDetic��GeoCentric��������֮���ת��
// ����ο�ϵ����WGS84

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

	// ����ƽ���뾶,xks,20160709
	const double RE= 6371000;//����ƽ���뾶m
	const double E_e = 0.0818133340169312L;				// ������Բ���һƫ����e
	const double E_e_2 = 	0.0409066670084656L;		// ������Բ���һƫ����e/2
	const double w_e = 7.292115e-5;							// ����ƽ����ת���ٶȣ�rad/s
	const double GM = 398600.4405;							// ��������������km^3/(s^2)

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
	// ���Կ��ã����㾫��Ҫ��
	// 1-1) ��������==>�������꣬������������Ϊ��λ����������ԡ����ȡ�Ϊ��λ
	// �˺���ԭ���ľ��������Ų��ԣ��Ѿ�������
	BW_CAL_API void  GeocentricToGeodetic(double x, double y, double z, double& latitude, double& longitude,   double& elevation);

	// 1-2) ��������==>�������꣬��������Ϊ�����ȡ�Ϊ��λ�������������Ϊ��λ
	// �˺���ԭ����yֵ�����Ų��ԣ��Ѿ�������
	BW_CAL_API void  GeodeticToGeocentric(double phi, double lambda, double elevation, double& x, double& y, double& z);
	//===========================================================================================================================================


	//-------------------------------------------------------------------------------------------------------------------------------------------
	// ���Կ��ã����㾫��Ҫ��
	// 2-1) ��������==>�������꣬������������Ϊ��λ�� ��������ԡ��ȡ�Ϊ��λ�� 
	// �˺���ԭ���ľ��������Ų��ԣ��Ѿ�������
	BW_CAL_API void  GeocentricToGeodeticInDegree(double x, double y, double z,double& latitude, double& longitude, double& elevation);

	// 2-2) ��������==>�������꣬��������Ϊ���ȡ�Ϊ��λ�������������Ϊ��λ
	// �˺���ԭ����yֵ�����Ų��ԣ��Ѿ�������
	BW_CAL_API void  GeodeticInDegreeToGeocentric(double latitude, double longitude, double elevation,double& x, double& y, double& z);
	//===========================================================================================================================================
	

	//-------------------------------------------------------------------------------------------------------------------------------------------
	// ����������ϵ���ֲ�����ϵת��ʱ��ϵ�� 2010-12-22 ����������Ϊ����Ϊ��λ��
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
	* ���γ��Խ���򷵻�FALSE
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

	//* ȱʡ���þֲ�����ϵ
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
	
	// ����LLE��ʽ�ĽϽ�������ˮƽ���루���ƣ�
	BW_CAL_API double  ShortestHorizDisNearLLEs( BwCal::GeoPt  , BwCal::GeoPt  );
	// ����LLE��ʽ�ĽϽ������̾��루���ƣ�
	BW_CAL_API double ShortestDistanceNearLLEs( BwCal::GeoPt  , BwCal::GeoPt  );

	// ��������֮���LLEֵ��������̬ʸ��
	BW_CAL_API Vec3 UTMCalculateGRPose( BwCal::GeoPt  , BwCal::GeoPt  );
	// 
	BW_CAL_API Vec3 CartCalculateVel( BwCal::GeoPt  , BwCal::GeoPt , double lfCuriseVel  );

	// ����LLE���ָ��������� 2011-07-06
	// �ݲ���,����0
	BW_CAL_API double SphericDirectionDistance( const BwCal::GeoPt lleA , const BwCal::GeoPt lleB );

	// ����LLE��Ĵ������ 2011-07-06
	// �ݲ���,����0
	BW_CAL_API double SphericBigCircleDistance( const BwCal::GeoPt lleA , const BwCal::GeoPt lleB );

	// ˮƽ�������� 2011-07-06
	// ʹ�ù��򣺵������ƾ��벻��̫Զ������ԽС������Խ��ȷ��Զ�����ͨ���������ʵ��
	// �������е����˶����㣬�ռ�����˶�������ʹ�ã���û�и߶ȱ仯
	// ˵������γ�ȼ��ǶȾ��ԡ��ȡ�Ϊ��λ��������"��"Ϊ��λ
	// �����������ʼ�㣬���룬�����
	// ���������Ŀ�ĵ�
	BW_CAL_API void PreCalulateGeoCoordinate( const GeoPt lleStart, double dis, double heading, GeoPt& lleDest );
	
	// ���ϵ���� Ƥѧ�� 2011-07-09
	// �����ԣ����롢��λ�����㾫��Ҫ��pitch��ͨ�����߸߶Ȳ����Ƚϵģ������⺬�壬������ע�⡣
	// ���������
	//		1) lleStart��	��ʼ��(γ�ȡ����ȡ��߶�)���ȡ���
	//		2) lleEnd��		������(γ�ȡ����ȡ��߶�)���ȡ���
	// ���������
	//		1) heading������ǣ��ȣ�-180��180
	//		2) pitch��	�����ǣ��ȣ�-90��90
	//     ע�⣺�����߸߶���ͬʱ��pitch=0����ˣ���pitch����������ʼ��ĵ�ƽ����ϵΪ�ο�ϵ����ġ�
	//               ���Ҫ����ʼ��ĵ�ƽ����ϵΪ�ο�ϵ����ߵͽǣ���ʹ��GeodeticInDegreeToTopocentricPolar()������������վ�ĵ�ƽϵ��صĺ�����
	// ����ֵ��
	//		�����ռ���룬��
	BW_CAL_API double CalculateHeadingPitch( const GeoPt lleStart, const GeoPt lleEnd, double& heading, double& pitch );


	// 2014-10-21 ����
	// -------From HY xks-------
	
	// ����������������С�������ͷ�λ
	// ���룺LocalPoint,DTPoint
	// �����dis(��λ-m),Angle(��λ-��,0-360��,������������汱�ļн�,˳ʱ�뷽��)
	BW_CAL_API int CacuTotalDistance(GeoPt LocalPoint, GeoPt DTPoint, double* dis,double* Angle);
	inline  double CalcltDirct(double   fStarPtx,   double   fStarPty,   double   fEndPtx,   double   fEndPty);
	inline double IPC_LSX (GeoPt gp1, GeoPt gp2, double& dbDist, double& dbCrs = *(double*)NULL);

	// 2016-07-09 
	// //////////////////////////////////////////////////////////////////////////
	//��������Ϊ����ʱ�����Ƽ��㺯��
	//ͨ����֪��λ��(��γ�߶�)���ٶȷ����˶�ʱ�䣬�����˶����λ��(��γ�߶�)
	//�ٶ�Ϊm/s
	//pitchΪ������(ʵ����Ӧ�����ٶȷ�����ˮƽ��ļнǣ����������ƴ���)��degree(-90�ȡ�90��),�ڵ������˶���ʵ���pitchΪ0��
	//courseΪ�����(�ٶ���ˮƽ���ϵ�ͶӰ���汱����ļн�)��degree(���汱Ϊ0��,˳ʱ�뷽��Ϊ����0�ȡ�360��)
	//dTΪ���ʱ�䣺s
	//currentPosΪ��ǰ��Ĵ������(γ��,����,�߶�)
	//nextPosΪ�˶�dTʱ��֮��Ĵ������(γ��,����,�߶�)�����ô���
	//by xks
	//////////////////////////////////////////////////////////////////////////
	//Ŀǰ�������ڶ���0-180�ȡ���γ0-90�ȷ�Χ���˶���ʵ��,������Χδ��֤
	//////////////////////////////////////////////////////////////////////////

	BW_CAL_API void MovePosCalculate(GeoPt currentPos,GeoPt & nextPos,double velocity,
		double pitch,double course,double dT);

	//ͨ������Ĵ�����꣬�ж�pos2�Ƿ���pos1����Ұ�У����Ƽ���
	//��pos1Ϊ��׼��
	//�Ƿ���1���񷵻�0
	//by xks
	BW_CAL_API bool IsInVisualField(GeoPt pos1,GeoPt pos2);

	//////////////////////////////////////////////////////////////////////////
	// 2017-05-18
	// ���´��������㺯�������Կ��ã�������ֵ�����㾫��Ҫ��

	// ��������ϵ���Ե�����������Ϊԭ�㣬xָ����Ⱦ��ߣ�yָ��90�Ⱦ��ߣ���������ϵ
	// ������أ�����ϵ��γ�ȡ����ȡ��߶�
	// վ�ĵ�ƽֱ������ϵ��վ��Ϊԭ�㣬����������Ϊx��y��z�ᣬ��������ϵ
	// վ�ĵ�ƽ������ϵ: r--��վ�ĵ�ֱ�߾��룻Az--��λ�ǣ����汱�ļнǣ�˳ʱ��Ϊ����-180~180��El--�ߵͽǣ�����Ϊ����-90~90

	// (5-1) �������굽��أ���������
	// pcg: deg
	// pcc: m
	BW_CAL_API void GeocentricToGeodeticInDegree(GeoPt &pcg, Vec3 pcc);

	// (5-2) �ɴ������ת��Ϊ��������
	// pcc: m
	// pcg: deg
	BW_CAL_API void GeodeticInDegreeToGeocentric(Vec3 &pcc, GeoPt pcg);

	// (5-3) �ɵ�������ת��Ϊվ�ĵ�ƽֱ������
	// pcc: ��ת����ĵ�������, m
	// pccCenter: վ������ԭ�㣨�������꣩, m
	// pct: վ�ĵ�ƽ����, m
	BW_CAL_API void GeocentricToTopocentric(TopoCentric &pct, Vec3 pcc, Vec3 pccCenter);

	// (5-4) վ�ĵ�ƽֱ������ת������������
	// pct: վ�ĵ�ƽ����, m
	// pccCenter: վ������ԭ�㣨�������꣩, m
	// pcc: ��ת����ĵ�������, m
	BW_CAL_API void TopocentricToGeocentric(Vec3 &pcc, TopoCentric pct, Vec3 pccCenter);

	// (5-5) �ɴ������ת��Ϊվ�ĵ�ƽֱ������
	// pcc: ��ת����Ĵ������, deg
	// pccCenter: վ������ԭ�㣨������꣩, deg
	// pct: վ�ĵ�ƽ����, m
	BW_CAL_API void GeodeticInDegreeToTopocentric(TopoCentric &pct, GeoPt pcc, GeoPt pccCenter);

	// (5-6) ��վ�ĵ�ƽֱ������ת��Ϊվ�ĵ�ƽ������
	// pct: m
	// pctp: m, deg, ����Az��-180~180����ƫ��Ϊ������El��-90~90
	BW_CAL_API void TopocentricToTopocentricPolar(TopocentricPolar &pctp, TopoCentric pct);

	// (5-7) ��վ�ĵ�ƽ������ת��Ϊվ�ĵ�ƽֱ������
	// pctp: m, deg
	// pct: m
	BW_CAL_API void TopocentricPolarToTopocentric(TopoCentric &pct, TopocentricPolar pctp);

	// (5-8) �ɴ������ת����վ�ĵ�ƽ������
	// pcc: ��ת����Ĵ������, deg
	// pccCenter: վ������ԭ�㣨������꣩, deg
	// pctp: վ�ĵ�ƽ������, m, deg, ����Az��-180~180��El��-90~90
	BW_CAL_API void GeodeticInDegreeToTopocentricPolar(TopocentricPolar &pctp, GeoPt pcc, GeoPt pccCenter);


	// (5-9) ��վ�ĵ�ƽ������ת��Ϊ�������
	// pctp: ��ת�����վ�ĵ�ƽ������, m, deg, ����Az��-180~180��El��-90~90
	// pccCenter: վ������ԭ�㣨������꣩, deg
	// pcd: ��ת����Ĵ������, deg
	BW_CAL_API void TopocentricPloarToGeodeticInDegree(GeoPt &pcd, TopocentricPolar pctp, GeoPt pccCenter);


	//////////////////////////////////////////////////////////////////////////
	// 20170719
	/* ����ϵ��վ�ģ�����ϵ��ת��
	// ����ϵ���壺������Ϊԭ�㣬��u-ǰ, v-��, w-�£�����������ϵ
	// վ��ϵ/����ϵ�������ģ�վ�ģ�Ϊԭ�㣬����������Ϊx��y��z�ᣬ��������ϵ��ͬǰ
	// ������̬�Ƕ��壺ƫ����psai����ƫΪ����������ksai��̧ͷΪ������ת��gama���ҹ�Ϊ��;
	// ���룺hpr--������̬��x,y,z�ֱ��Ӧpsai, ksai, gama����λ��deg
				  BodyPos---����ϵ����ֵ����λ��m��m/s
		�����ptc---վ������ֵ����λ��m��m/s
*/
	BW_CAL_API void BodyCord2TopoCentric(TopoCentric &ptc , Vec3 hpr, Vec3 BodyPos);

	/* @J2000.���Ĺ�������ϵ��PQW���ǹ������ϵ
		J2000����ϵ���壺���ƽ�棬 x-���ֵ㣬z-������y-�� ����ϵ
		PQW����ϵ���壺 p-���ص㣬w-ָ��������ת�ᣬq-���ƽ������p������������ϵ
		���룺eci - ECI����(m��m/s)��i-�����ǣ�deg����O-������ྭ��deg��, w-���ص����(deg)
		�����pqw - PQW���꣨m��m/s����(x,y,z)��Ӧ(p,q,w)
	*/
	BW_CAL_API void ECI2PQW(Vec3 &pqw, Vec3 eci, double i, double O, double w);

	/* @PQW���ǹ������ϵ��J2000.���Ĺ�������ϵ
		���������ǰ���෴������һ��
	*/
	BW_CAL_API void PQW2ECI(Vec3 &eci, Vec3 pqw, double i, double O, double w);
	
	/* @J2000.���Ĺ�������ϵ��ECF���Ĺ�������ϵ
		J2000����ϵ���壺���ƽ�棬 x-���ֵ㣬z-������y-�� ����ϵ
		ECF���壺���ƽ�棬x-ָ����Ⱦ��ߣ�z-������y-������ϵ
		���룺eci - ECI����(m��m/s)��GST-Greenwich mean sidereal time����������ƽ̫��ʱ��deg��
		�����ecf - ECF���꣨m��m/s��
	*/
	BW_CAL_API void  ECI2ECF(Vec3 &ecf, Vec3 eci, double GST);

	/* @ECF���Ĺ�������ϵ��J2000.���Ĺ�������ϵ
		���������ǰ���෴������һ��
	*/
	BW_CAL_API void  ECF2ECI(Vec3 &eci, Vec3 ecf, double GST);

	/* @ ��ȡ ECF���Ĺ�������ϵ������ĳ���ENU����������ϵ ��ת������
		@	��ת������Ҳ�����ڴ�ECI����ϵת������γ���ྭ���ڵ��ENU����ϵ
		@ ��ֱ�������ٶȡ�ʸ��ת����������ֱ������λ��ת����δ����ƽ�ƣ�
		@	���룺phi-γ�ȣ�deg����lamda-���ȣ�deg��
		@	���������ת������
	*/
	BW_CAL_API Matrix3 getM_ecf2enu(double phi, double lamda);

}

#endif //MUSE_COORDINATES_NAMESPACE
