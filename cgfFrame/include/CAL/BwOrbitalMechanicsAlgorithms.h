#ifndef __BW_OrbitalMechanicsAlgorithms_H__
#define __BW_OrbitalMechanicsAlgorithms_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
///////////////////

#include "BwCal.h"
#include "BwVec3.h"
#include "BwMatrix3.h"

namespace BwCal
{

	class BW_CAL_API COrbitalMechanicsAlgorithms
	{
	public:
		COrbitalMechanicsAlgorithms(void){}
		~COrbitalMechanicsAlgorithms(void){}

		//--------------------------------------------------------------------------------------------------------------------------------
		// 轨道动力学相关算法

		// 	% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// 		function [r, v] = sv_from_coe(coe)
		// 		% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// 		% This function computes the state vector (r,v) from the
		// 		% classical orbital elements (coe).
		// 		输入：
		//			coe= [a, e, RA, incl, w, TA]--单位：km, 1, rad, rad, rad, rad
		//			输出：
		// 		% r - position vector in the geocentric equatorial frame
		// 		% (km)
		// 		% v - velocity vector in the geocentric equatorial frame
		// 		% (km/s)
		// 		% ------------------------------------------------------------
		static bool sv_from_coe(double coe[] ,Vec3& r,Vec3& v);

		//% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//	function coe = coe_from_sv(R,V)
		//	% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//	% This function computes the classical orbital elements (coe)
		//	% from the state vector (R,V) using Algorithm 4.1.
		//	%Input: 
		//	% R - position vector in the geocentric equatorial frame, km
		//	% V - velocity vector in the geocentric equatorial frame, km/s
		//	% Output: 
		// % [a e RA incl w TA]----单位：km, 1, rad, rad, rad, rad
		//	% User M-functions required: None
		//	% ------------------------------------------------------------
		static bool coe_from_sv(Vec3 R,Vec3 V,double coe[]);

		// % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// 	% 已知：ECI坐标系下，任意二体运动对象的速度矢量v0、位置矢量r0、积分步长h，
		// 	%   利用4阶龙格库塔积分下一时刻的速度和位置矢量
		//		% 适用于二体运动规律
		// 	% 积分公式：dv=-mu*r/r^3; dr=v;
		//		% v0：当前速度矢量
		// 	% r0：当前位置矢量
		// 	% h：积分步长
		// 	% vt：下一时刻速度矢量
		// 	% rt：下一时刻位置矢量
		//	% ------------------------------------------------------------
		static bool RG4_TwoBody(Vec3 v0,Vec3 r0,double h,Vec3& vt,Vec3& rt);

		// % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// 	% ...
		// 	% This function computes the Julian day number at 0 UT for any
		// 	% year between 1900 and 2100 using Equation 5.48.
		// 	%
		// 	% j0 - Julian day at 0 hr UT (Universal Time)
		// 	% year - range: 1901 - 2099
		// 	% month - range: 1 - 12
		// 	% day - range: 1 - 31
		// 	%
		// 	% User M-functions required: none
		// 	% ------------------------------------------------------------
		static bool J0(int year, int month, int day,double &j0);

		// % This function reduces an angle to the range
		// 	% 0 - 360 degrees.
		// 	%
		// 	% x - The angle (degrees) to be reduced
		// 	% y - The reduced value
		// 	%
		// 	% ------------------------------------------------------------
		static double zeroTo360(double x);

		// % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// % This function calculates the local sidereal time.
		// 
		// % output:lst - local sidereal time (degrees)
		//	% y - year - range: 1901 - 2099
		//	% m - month - range: 1 - 12
		//	% d - day range: 1 - 31
		//	% ut - Universal Time (hours) (0 - 23)
		//	% utm - Universal Time (minutes) (0 - 60)
		//	% uts - Universal Time (seconds) (0 - 60)
		// % EL - east longitude of the site (west longitude is
		//	% negative):
		//	% ELd - east longitude (degrees) (0 - 360)
		//	% ELm - east longitude (minutes) (0 - 60)
		//	% ELs - east longitude (seconds) (0 - 60)
		// % User unction required: J0,zeroTo360
		// % ------------------------------------------------------------
		static double LST(int y,int m,int d,double uth,double utm,double uts,double ELd,double ELm,double ELs);

		// % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// % This function calculates the greenwich sidereal time.
		// 
		// % output: gst - greenwich sidereal time (degrees)
		//	% y - year - range: 1901 - 2099
		//	% m - month - range: 1 - 12
		//	% d - day range: 1 - 31
		//	% ut - Universal Time (hours) (0 - 23)
		//	% utm - Universal Time (minutes) (0 - 60)
		//	% uts - Universal Time (seconds) (0 - 60)
		static double GST(int y,int m,int d,double uth,double utm,double uts);

		// % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// function c = stumpC(z)
		// % ~~~~~~~~~~~~~~~~~~~~~~
		// %
		// % This function evaluates the Stumpff function C(z) according
		// % to Equation 3.50.
		// %
		// % z - input argument
		// % c - value of C(z)
		// %
		// % User M-functions required: none
		// % ------------------------------------------------------------
		static double stumpC(double z);

		// % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// function s = stumpS(z)
		// % ~~~~~~~~~~~~~~~~~~~~
		// %
		// % This function evaluates the Stumpff function S(z) according
		// % to Equation 3.49.
		// %
		// % z - input argument
		// % s - value of S(z)
		// %
		// % User M-functions required: none
		// % ------------------------------------------------------------
		static double stumpS(double z);

		// % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// 	% This function solves Lambert's problem.
		// 	% R1, R2 - initial and final position vectors (km)
		// 	% t - the time of flight from R1 to R2,  (a constant) (s)
		// 	% V1, V2 - initial and final velocity vectors (km/s)
		// 	% string - 'pro' if the orbit is prograde--顺行轨道
		// 	% 'retro' if the orbit is retrograde--逆行轨道
		// 	% User M-functions required: stumpC and stumpS
		// 	% -----------------------------------------------------------
		static bool lambert(Vec3 R1, Vec3 R2, double t, char* string, Vec3 &V1, Vec3 &V2);

		//--------------------------------------------------------------------------------------------------------------------------------
	};

}

#endif