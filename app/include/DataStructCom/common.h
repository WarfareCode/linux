#ifndef	MISSILE_COMMON_H_
#define	MISSILE_COMMON_H_

#include <stdio.h>
#include <string.h>

#include <string>
using std::string;

#define     sgn(x)          ( (x) > 0 ? 1 : ( (x) < 0 ? -1 : 0 ) )
#define     sqr(x)          ( (x) * (x) )
#define     satn(x,MAG)     ( fabs(x) < MAG ? (x) : MAG * sgn(x) )

// 相关数据结构定义
typedef struct Wind
{
    double Kf;  // 风向(风的来向)，单位（度），基准线为舰首方向，顺时针为正
    double Vf;  // 风速，米/秒
} WIND; // 常值风，相对于我舰艇

// 环境参数结构体
struct ENVIRONMENT
{
    double Tc;	// 温度
    double Vf;	// 风速
    double Kf;	// 风向
    double Rh;	// 相对湿度
    double Dv;	// 气象视程
    double Jr;	// 降雨强度
    double Js;	// 降雪强度
    
    ENVIRONMENT() //构造函数
    {
        Tc = 15.0;
        Vf = 0.0;
        Kf = 0.0;
        Rh = 0.8;
        Dv = 10.0;
        Jr = 0.0;
        Js = 0.0;
    }
    ENVIRONMENT(const ENVIRONMENT& sourceData)
    {
        Tc = sourceData.Tc;
        Vf = sourceData.Vf;
        Kf = sourceData.Kf;
        Rh = sourceData.Rh;
        Dv = sourceData.Dv;
        Jr = sourceData.Jr;
        Js = sourceData.Js;
    }
    const ENVIRONMENT& operator = (const ENVIRONMENT& sourceData)
    {
        Tc = sourceData.Tc;
        Vf = sourceData.Vf;
        Kf = sourceData.Kf;
        Rh = sourceData.Rh;
        Dv = sourceData.Dv;
        Jr = sourceData.Jr;
        Js = sourceData.Js;
        return *this;
    }
};

// 导弹模型枚举
enum MISSILETYPE {
        MT_YJ18,           // YJ18动力学模型
        MT_YJ18D,          // YJ18动力学模型
        MT_YJ18F,          // YJ18快速仿真模型
        MT_YJ82,           // YJ82动力学模型
        MT_YJ82D,          // YJ82动力学模型
        MT_YJ82S,          // YJ82简化模型
        MT_YJ82F,          // YJ82快速仿真模型
        MT_UGM84,          // 潜射鱼叉
        MT_AGM84C,         // 机载鱼叉Block1C
        MT_AGM84D,         // 机载鱼叉Block1D
        MT_RGM84C,         // 舰载鱼叉Block1C
        MT_RGM84D,         // 舰载鱼叉Block1D
        MT_MGB2,           // 雄风2
        MT_MGB3,           // 雄风3
        MT_AGM65F,         // 海军“幼畜”（小牛）
        MT_UNKNOWN         // 未知
};

enum TARGETSTATE {
    TS_NOTCAPTURED,    // 目标未被捕获
    TS_CAPTURED        // 目标被捕获
};

enum MISSILESTATE {
	MS_NOTLAUNCH = 0,	// 未发射
	MS_UNDERWATER = 1,      // 水下运动
	MS_CONTROL = 2,		// 空中自控飞行
        MS_SEARCH = 7,          // 搜索目标
        MS_SILENT = 8,          // 静默导引
	MS_GUIDANCE = 3,	// 自导飞行
	MS_OUTOFFUEL = 4,	// 燃料耗尽
	MS_ACTIVE = 5,		// 被有源干扰
	MS_PASSIVE = 6,		// 被无源干扰
	MS_ANTICRAFT = 11,	// 被防空导弹击毁
	MS_ARTILLERY = 12,	// 被舰炮击毁
	MS_INTOWATER = 13,	// 入水
	MS_HIT = 21		// 命中目标
};

struct MISSILEINFO
{
    string       strID;
    long         intID;
    MISSILESTATE State;
    double       Longitude;		// 经度
    double       Latitude ;		// 纬度
    double       ElevationAGL;	// 高度
    double       Direction   ;	// 航向
    double       Speed;			// 速度
    double       Theta;			// 俯仰角
    double       Phi  ;			// 偏航角
    double       Gamma;			// 滚动角度
    double       Time;			// 时间
	
    MISSILEINFO() //构造函数
    {
        strID        = "";
        intID        = 0;
        State        = MS_NOTLAUNCH;
        Speed        = 0.0;
        Longitude    = 0.0;
        Latitude     = 0.0;
        ElevationAGL = 0.0;
        Direction    = 0.0;
        Theta        = 0.0;
        Phi          = 0.0;
        Gamma        = 0.0;
        Time         = 0.0;
    }
    MISSILEINFO(const MISSILEINFO& sourceData)
    {
        strID        = sourceData.strID;
        intID        = sourceData.intID;
        State        = sourceData.State;
        Speed        = sourceData.Speed;
        Longitude    = sourceData.Longitude;
        Latitude     = sourceData.Latitude;
        ElevationAGL = sourceData.ElevationAGL;
        Direction    = sourceData.Direction;
        Theta        = sourceData.Theta;
        Phi          = sourceData.Phi;
        Gamma        = sourceData.Gamma;
        Time         = sourceData.Time;
    }
    const MISSILEINFO& operator = (const MISSILEINFO& sourceData)
    {
        strID        = sourceData.strID;
        intID        = sourceData.intID;
        State        = sourceData.State;
        Speed        = sourceData.Speed;
        Longitude    = sourceData.Longitude;
        Latitude     = sourceData.Latitude;
        ElevationAGL = sourceData.ElevationAGL;
        Direction    = sourceData.Direction;
        Theta        = sourceData.Theta;
        Phi          = sourceData.Phi;
        Gamma        = sourceData.Gamma;
        Time         = sourceData.Time;
        return *this;
    }
};

struct TARGETINFO
{
    long   intID;               // 整数类型ID
    string strID;               // 字符串ID
    double Longitude;		// 经度
    double Latitude ;		// 纬度
    double Direction   ;	// 航向
    double Speed;		// 速度
	
    TARGETINFO() //构造函数
    {
        intID        = 0;
        strID        = "";
        Longitude    = 0.0;
        Latitude     = 0.0;
        Direction    = 0.0;
    }
    TARGETINFO(const TARGETINFO& sourceData)
    {
        intID        = sourceData.intID;
        strID        = sourceData.strID;
        Speed        = sourceData.Speed;
        Longitude    = sourceData.Longitude;
        Latitude     = sourceData.Latitude;
        Direction    = sourceData.Direction;
    }
    const TARGETINFO& operator = (const TARGETINFO& sourceData)
    {
        intID        = sourceData.intID;
        strID        = sourceData.strID;
        Speed        = sourceData.Speed;
        Longitude    = sourceData.Longitude;
        Latitude     = sourceData.Latitude;
        Direction    = sourceData.Direction;
        return *this;
    }
};

// 单条航路信息
struct WayPointPlaningOutput
{
    int		nWayPoint;	// 航路点个数
    double	Sm;		// 航路长度
    double	Jm[15];		// 经度
    double	Wm[15];		// 纬度
    double	Rm[15];		// 转弯半径
    double	Am[15];		// 转弯角
    
    // 拷贝构造函数
    WayPointPlaningOutput(){}
    WayPointPlaningOutput(const WayPointPlaningOutput& sourceData)
    {
        nWayPoint = sourceData.nWayPoint;
        Sm = sourceData.Sm;
        memcpy(Jm, sourceData.Jm, 15*sizeof(double));
        memcpy(Wm, sourceData.Wm, 15*sizeof(double));
        memcpy(Rm, sourceData.Rm, 15*sizeof(double));
        memcpy(Am, sourceData.Rm, 15*sizeof(double));
    }
    const WayPointPlaningOutput& operator = (const WayPointPlaningOutput& sourceData)
    {
        nWayPoint = sourceData.nWayPoint;
        Sm = sourceData.Sm;
        memcpy(Jm, sourceData.Jm, 15*sizeof(double));
        memcpy(Wm, sourceData.Wm, 15*sizeof(double));
        memcpy(Rm, sourceData.Rm, 15*sizeof(double));
        memcpy(Am, sourceData.Rm, 15*sizeof(double));
        return *this;
    }
};


struct LatLonH
{
    double       Longitude;		// 经度
    double       Latitude ;		// 纬度
    double       ElevationAGL;	// 高度
    
    LatLonH() //构造函数
    {
        Longitude    = 0.0;
        Latitude     = 0.0;
        ElevationAGL = 0.0;
    }
    LatLonH(const LatLonH& sourceData)
    {
        Longitude    = sourceData.Longitude;
        Latitude     = sourceData.Latitude;
        ElevationAGL = sourceData.ElevationAGL;
    }
    const LatLonH& operator = (const LatLonH& sourceData)
    {
        Longitude    = sourceData.Longitude;
        Latitude     = sourceData.Latitude;
        ElevationAGL = sourceData.ElevationAGL;
        return *this;
    }
};

struct ATTITUDE
{
    double       Theta;			// 俯仰角
    double       Phi  ;			// 偏航角
    double       Gamma;			// 滚动角度
    
    ATTITUDE() //构造函数
    {
        Theta = 0.0;
        Phi   = 0.0;
        Gamma = 0.0;
    }
    ATTITUDE(const ATTITUDE& sourceData)
    {
        Theta = sourceData.Theta;
        Phi   = sourceData.Phi;
        Gamma = sourceData.Gamma;
    }
    const ATTITUDE& operator = (const ATTITUDE& sourceData)
    {
        Theta = sourceData.Theta;
        Phi   = sourceData.Phi;
        Gamma = sourceData.Gamma;
        return *this;
    }
};

struct Latlon
{
    double Lat;      //纬度
    double Lon;     //经度
    
    const Latlon& operator = (const Latlon& sourceData)
    {
        Lat = sourceData.Lat;
        Lon = sourceData.Lon;
        return *this;
    }
};


//double max(double value1, double value2);
double filter(double,double);
FILE*  SafeOpen(char *,const char *);
char*  form(char *,const char *,unsigned);

double f180( double ang );
double f360( double ang );
Latlon Reckon(Latlon start, double distance, double azimuth);
void Reckon(double sLat, double sLon, double distance, double azimuth, double &dLat, double &dLon);
Latlon XZ2LatLon(Latlon start, double Kb, double x, double z);
void DistAz(Latlon start, Latlon dest, double &distance, double &azimuth);
void LatLon2XZ(Latlon start, Latlon dest, double Kb, double &x, double &z);

// constants definition
const double g0   = 9.81;			// 重力加速度 (米/秒^2)
const double Rho0 = 1.2255;			// 空气密度 (千克/米^3)
//const double PI   = 3.1415926536;		// 圆周率
const double R2D  = (180.0/PI);			// 弧度化为角度
const double D2R  = (PI/180.0);			// 角度化为弧度
const double Re   = 6378137.0;			// 地球半径 (米)

#endif	// MISSILE_COMMON_H_
