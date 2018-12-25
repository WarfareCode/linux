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

#define c   3.0e+8       //����	
#define DtR 0.017453292
#define RtD 57.29578049

#define CDBJ   6378245          //����ο����������뾶
#define JBJ    6356863          //����ο������弫�뾶
#define DXBJ   637000           //�����Ч�뾶
#define BL     0.00335233281    //����ο����������
#define PXLPF1 0.00669342749    //��������������Ȧ��һƫ����ƽ��(a^2+b^2)/a^2
#define PXLPF2 0.00673853541    //��������������Ȧ�ڶ�ƫ����ƽ��(a^2+b^2)/b^2
#define Wzz    0.004178         //��ֵ ������ת���ٶ�(��/��)

const int MaxNumOfMissile = 50; //���ص���������
const int MaxNumOfTarget  = 32 ; //ָ��̨���Ŀ��ָʾ����

const int RouteNumMax = 8 ; //һ�κ�·�滮�������ĺ�·��
const int WayPointMax = 15; //һ����·��ຽ·����
const int MaxNumOfTrail = 2000; //һ��������ౣ���켣����

/*-----------------------ö����������-----------------------*/

enum ATTFlag {	// ��Ӫ
	ATTNone = 4,	// δ֪
	White = 3,	// �׷�/����
	Blue = 2,	// ����
	Red = 1,	// �췽
};

/*-----------------------���Ͻṹ��������-------------------*/

/*---------------------�Զ���ṹ�壬��·�滮ģ��ʹ��-----------------------*/

struct WayPointInfo	
{
	int     nPathType;
	int	    nNumOfPt;	        
	double	Sm;	                
	double	Jm[WayPointMax];	
	double	Wm[WayPointMax];	
	double	Rm[WayPointMax];	
	double	Am[WayPointMax];	
    double  Cmil; //������������
    double  Ctar; //�췽Ŀ�꽢ͧ����
	int     NoTar;//�췽Ŀ�꽢ͧ����
	
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
