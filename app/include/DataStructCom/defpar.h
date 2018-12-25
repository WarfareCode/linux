///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef	DEFPAR_H_
#define	DEFPAR_H_

#include <string>
#include <vector>
#include "Common.h"

using std::string;
using std::vector;

#define WM_RECEIVE_PATHINFO    WM_USER+50
#define WM_SHOW_PATHPLANINGWND WM_USER+51
#define WM_SET_ENVIRENMENT     WM_USER+52

#define c   3.0e+8       //光速	
#define DtR 0.017453292
#define RtD 57.29578049

#define CDBJ   6378245          //地球参考椭球体赤道半径
#define JBJ    6356863          //地球参考椭球体极半径
#define DXBJ   637000           //地球等效半径
#define BL     0.00335233281    //地球参考椭球体扁率
#define PXLPF1 0.00669342749    //地球椭球体子午圈第一偏心率平方(a^2+b^2)/a^2
#define PXLPF2 0.00673853541    //地球椭球体子午圈第二偏心率平方(a^2+b^2)/b^2
#define Wzz    0.004178         //常值 地球自转角速度(度/秒)

const int MaxNumOfMissile = 50; //舰载导弹最多个数
const int MaxNumOfTarget  = 32 ; //指控台最多目标指示个数

const int RouteNumMax = 8 ; //一次航路规划最大允许的航路数
const int WayPointMax = 15; //一条航路最多航路点数
const int MaxNumOfTrail = 2000; //一条导弹最多保留轨迹点数

/*-----------------------枚举数据类型-----------------------*/

enum ATTFlag {	// 阵营
	ATTNone = 4,	// 未知
	White = 3,	// 白方/中立
	Blue = 2,	// 蓝方
	Red = 1,	// 红方
};

/*-----------------------复合结构数据类型-------------------*/

/*---------------------自定义结构体，航路规划模块使用-----------------------*/

struct WayPointInfo	
{
	int     nPathType;
	int	    nNumOfPt;	        
	double	Sm;	                
	double	Jm[WayPointMax];	
	double	Wm[WayPointMax];	
	double	Rm[WayPointMax];	
	double	Am[WayPointMax];	
    double  Cmil; //蓝方导弹航向
    double  Ctar; //红方目标舰艇航向
	int     NoTar;//红方目标舰艇批号
	
	WayPointInfo()
	{
		nPathType = 0;
		nNumOfPt = 0;
		Sm = 0.0;
		for (int i=0; i<WayPointMax; i++)
		{
			Jm[i] = 0.0; Wm[i] = 0.0; Rm[i] = 0.0; Am[i] = 0.0;
		}
		Cmil = 0.0;
		Ctar = 0.0;
		NoTar = 0;
	}
	WayPointInfo(const WayPointInfo& sourceData)
	{
		nPathType = sourceData.nPathType;
		nNumOfPt = sourceData.nNumOfPt;
		Sm = sourceData.Sm;
		memcpy(Jm, sourceData.Jm, WayPointMax*sizeof(double));
		memcpy(Wm, sourceData.Wm, WayPointMax*sizeof(double));
		memcpy(Rm, sourceData.Rm, WayPointMax*sizeof(double));
		memcpy(Am, sourceData.Am, WayPointMax*sizeof(double));
		Cmil = sourceData.Cmil;
		Ctar = sourceData.Ctar;
		NoTar = sourceData.NoTar;
	}
	const WayPointInfo& operator = (const WayPointInfo& sourceData)
	{
		nPathType = sourceData.nPathType;
		nNumOfPt = sourceData.nNumOfPt;
		Sm = sourceData.Sm;
		memcpy(Jm, sourceData.Jm, WayPointMax*sizeof(double));
		memcpy(Wm, sourceData.Wm, WayPointMax*sizeof(double));
		memcpy(Rm, sourceData.Rm, WayPointMax*sizeof(double));
		memcpy(Am, sourceData.Am, WayPointMax*sizeof(double));
		Cmil = sourceData.Cmil;
		Ctar = sourceData.Ctar;
		NoTar = sourceData.NoTar;
		return *this;
	}
};

struct JWHCoordinate
{
	double Longitude;
	double Latitude;
	float  Height;
	
	JWHCoordinate(){}
	JWHCoordinate(const JWHCoordinate& sourceData)
	{
		Longitude = sourceData.Longitude;
		Latitude = sourceData.Latitude;
		Height = sourceData.Height;
	}
	const JWHCoordinate& operator = (const JWHCoordinate& sourceData)
	{
		Longitude = sourceData.Longitude;
		Latitude = sourceData.Latitude;
		Height = sourceData.Height;
		return *this;
	}
};

#endif //DEFPAR_H_
