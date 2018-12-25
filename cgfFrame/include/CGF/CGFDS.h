// CGFDS.h
// Author:xks
//////////////////////////////////////////////////////////////////////////

#if !defined(__HJSIM_CGFDS__)
#define __HJSIM_CGFDS__
#pragma once

#include "HyCgf_PreDef.h"

#define MAX_SENSOR_DET_NUM	100	// 
#define MAX_WEAPON_REC_NUM	10	// 
#define MAX_RP_NUM	32						// 
#define MAX_ESR_NUM	50					// 

// 一维
HYCGF_API void Dim1_DoubleStr2DoubleList(CDoubleList& destList, String str);
HYCGF_API String DoubleList2Dim1_DoubleStr(CDoubleList& sourceList);

//
#define MAX_DOUBLEMATRIX_COL	128
HYCGF_API	void Dim2_DoubleStr2DoubleMatrix(double (*destMatrix)[MAX_DOUBLEMATRIX_COL], int& row, int& col, String str);
HYCGF_API	String DoubleMatrix2Dim2_DoubleStr(double (*destMatrix)[MAX_DOUBLEMATRIX_COL], int row, int col);

// 位置点链表定义,
typedef List<DWORD,DWORD>	GeoPtList;
HYCGF_API	void	ReleaseGeoPtList(GeoPtList* list);

// 字符串示例:"20.5,120,222.111;21.3,121.1,0.5;22.2,125.3333,7099999999;"
HYCGF_API	void	GeoPtStr2GeoPtList(GeoPtList& destList,String str);
HYCGF_API	String	GeoPtList2GeoPtStr(GeoPtList& sourceList);

//
// string extract
HYCGF_API	bool	ExtractStrItem(String& sentence,String& item,char seperate);
HYCGF_API	bool	ExtractStrItem(char* sentence,char* item,char seperate);


//
// 时间结构体定义
struct EpochTimeStruct
{
	int	EpTm_sec;
	int	EpTm_min;
	int	EpTm_hour;
	int	EpTm_mday;
	int	EpTm_mon;
	int	EpTm_year;
};

struct HYCGF_API DtEntityType 
{
	int	kind;
	int	domain;
	int	country;
	int	category;
	int	subCategory;
	int	specific;
	int	extra;

	DtEntityType()
	{
		kind = -1;
		domain = -1;
		country = -1;
		category = -1;
		subCategory = -1;
		specific = -1;
		extra = -1;
	}

	DtEntityType(int para1, int para2,int para3,int para4,
		int para5, int para6, int para7)
	{
		kind = para1;
		domain = para2;
		country = para3;
		category = para4;
		subCategory = para5;
		specific = para6;
		extra = para7;
	}

	DtEntityType operator = (DtEntityType EntType)
	{
		kind = EntType.kind;
		domain = EntType.domain;
		country = EntType.country;
		category = EntType.category;
		subCategory = EntType.subCategory;
		specific = EntType.specific;
		extra = EntType.extra;

		return *this;
	}

	bool	Parse(char* str, char sep);
	void	FormatString(char* str);
	bool	MatchAllEntityType(DtEntityType& cmpEntType);
	bool	MatchFirstNEntityType(DtEntityType& cmpEntType,long N);
	bool	MatchIndexEntityType(DtEntityType& cmpEntType,long index);

};

struct	DtWayPoint
{
	double x;
	double y;
	double z;
	double speed;
	double bCross;

	DtWayPoint()
	{
		x=0;
		y=0;
		z=0;
		speed=0;
		bCross=0;
	}
	DtWayPoint(double _x, double _y, double _z,
		double _speed, double _bcross)
	{
		x=_x;
		y=_y;
		z=_z;
		speed=_speed;
		bCross=_bcross;
	}

};

enum	ShapeType
{
	SHAPE_POINT=1,
	SHAPE_POLYLINE,
	SHAPE_POLYGON,
	SHAPE_RECTANGLE,
	SHAPE_SQUARE,
	SHAPE_CIRCLE,
	SHAPE_ELLIPSE,
	SHAPE_SECTOR,
};

enum	Enum_SideType
{
	SIDE_RED = 1,
	SIDE_BLUE,
	SIDE_OTHER
};

enum	SurvivalStateType
{
	SURVIVALSTATE_GOOD=0,
	SURVIVALSTATE_LIGHTWOUND,
	SURVIVALSTATE_SERIOUSWOUND,
	SURVIVALSTATE_DESTROYED
};

enum	RainModelType
{
	ITU_R_P618_9=1,
	Crane_1985
};

enum	AtmosAbsorptionModelType
{
	ITU_R_P676_5=1,
	Simple_Satcom,
	Two_Ray
};

enum	Enum_FrequencyBandType
{
	// International std.
	A_Band = 1001,
	B_Band = 1002,
	C_Band = 1003,
	D_Band = 1004,
	E_Band = 1005,
	F_Band = 1006,
	G_Band = 1007,
	H_Band = 1008,
	I_Band = 1009,
	J_Band = 1010,
	K_Band = 1011,
	L_Band = 1012,
	M_Band = 1013,

	// visual light
	VisualLight = 2001,
	NearIR = 2002,
	FarIR = 2003,
	Laser = 2004,

	// Radio
	ELF_Radio = 3001,
	SLF_Radio = 3002,
	ULF_Radio = 3003,
	VLF_Radio = 3004,
	LF_Radio = 3005,
	MF_Radio = 3006,
	HF_Radio = 3007,
	VHF_Radio = 3008,
	UHF_Radio = 3009,
	SHF_Radio = 3010,
	EHF_Radio = 3011,

	// acoustic wave
	VLF_Sonar = 4001,
	LF_Sonar = 4002,
	MF_Sonar = 4004,
	HF_Sonar = 4004,

	// microwave
	P_Band_MicroWave = 5001,
	L_Band_MicroWave = 5002,
	S_Band_MicroWave = 5003,
	C_Band_MicroWave = 5004,
	X_Band_MicroWave = 5005,
	Ku_Band_MicroWave = 5006,
	K_Band_MicroWave = 5007,
	Ka_Band_MicroWave = 5008,
	U_Band_MicroWave = 5009,
	E_Band_MicroWave = 5010,
	F_Band_MicroWave = 5011,
	Q_Band_MicroWave = 5012,
	V_Band_MicroWave = 5013,
	W_Band_MicroWave = 5014,
	D_Band_MicroWave = 5015,

};

#endif




