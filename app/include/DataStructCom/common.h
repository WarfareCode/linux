#ifndef	MISSILE_COMMON_H_
#define	MISSILE_COMMON_H_

#include <stdio.h>
#include <string.h>

#include <string>
using std::string;

#define     sgn(x)          ( (x) > 0 ? 1 : ( (x) < 0 ? -1 : 0 ) )
#define     sqr(x)          ( (x) * (x) )
#define     satn(x,MAG)     ( fabs(x) < MAG ? (x) : MAG * sgn(x) )

// ������ݽṹ����
typedef struct Wind
{
    double Kf;  // ����(�������)����λ���ȣ�����׼��Ϊ���׷���˳ʱ��Ϊ��
    double Vf;  // ���٣���/��
} WIND; // ��ֵ�磬������ҽ�ͧ

// ���������ṹ��
struct ENVIRONMENT
{
    double Tc;	// �¶�
    double Vf;	// ����
    double Kf;	// ����
    double Rh;	// ���ʪ��
    double Dv;	// �����ӳ�
    double Jr;	// ����ǿ��
    double Js;	// ��ѩǿ��
    
    ENVIRONMENT() //���캯��
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

// ����ģ��ö��
enum MISSILETYPE {
        MT_YJ18,           // YJ18����ѧģ��
        MT_YJ18D,          // YJ18����ѧģ��
        MT_YJ18F,          // YJ18���ٷ���ģ��
        MT_YJ82,           // YJ82����ѧģ��
        MT_YJ82D,          // YJ82����ѧģ��
        MT_YJ82S,          // YJ82��ģ��
        MT_YJ82F,          // YJ82���ٷ���ģ��
        MT_UGM84,          // Ǳ�����
        MT_AGM84C,         // �������Block1C
        MT_AGM84D,         // �������Block1D
        MT_RGM84C,         // �������Block1C
        MT_RGM84D,         // �������Block1D
        MT_MGB2,           // �۷�2
        MT_MGB3,           // �۷�3
        MT_AGM65F,         // ���������󡱣�Сţ��
        MT_UNKNOWN         // δ֪
};

enum TARGETSTATE {
    TS_NOTCAPTURED,    // Ŀ��δ������
    TS_CAPTURED        // Ŀ�걻����
};

enum MISSILESTATE {
	MS_NOTLAUNCH = 0,	// δ����
	MS_UNDERWATER = 1,      // ˮ���˶�
	MS_CONTROL = 2,		// �����Կط���
        MS_SEARCH = 7,          // ����Ŀ��
        MS_SILENT = 8,          // ��Ĭ����
	MS_GUIDANCE = 3,	// �Ե�����
	MS_OUTOFFUEL = 4,	// ȼ�Ϻľ�
	MS_ACTIVE = 5,		// ����Դ����
	MS_PASSIVE = 6,		// ����Դ����
	MS_ANTICRAFT = 11,	// �����յ�������
	MS_ARTILLERY = 12,	// �����ڻ���
	MS_INTOWATER = 13,	// ��ˮ
	MS_HIT = 21		// ����Ŀ��
};

struct MISSILEINFO
{
    string       strID;
    long         intID;
    MISSILESTATE State;
    double       Longitude;		// ����
    double       Latitude ;		// γ��
    double       ElevationAGL;	// �߶�
    double       Direction   ;	// ����
    double       Speed;			// �ٶ�
    double       Theta;			// ������
    double       Phi  ;			// ƫ����
    double       Gamma;			// �����Ƕ�
    double       Time;			// ʱ��
	
    MISSILEINFO() //���캯��
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
    long   intID;               // ��������ID
    string strID;               // �ַ���ID
    double Longitude;		// ����
    double Latitude ;		// γ��
    double Direction   ;	// ����
    double Speed;		// �ٶ�
	
    TARGETINFO() //���캯��
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

// ������·��Ϣ
struct WayPointPlaningOutput
{
    int		nWayPoint;	// ��·�����
    double	Sm;		// ��·����
    double	Jm[15];		// ����
    double	Wm[15];		// γ��
    double	Rm[15];		// ת��뾶
    double	Am[15];		// ת���
    
    // �������캯��
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
    double       Longitude;		// ����
    double       Latitude ;		// γ��
    double       ElevationAGL;	// �߶�
    
    LatLonH() //���캯��
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
    double       Theta;			// ������
    double       Phi  ;			// ƫ����
    double       Gamma;			// �����Ƕ�
    
    ATTITUDE() //���캯��
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
    double Lat;      //γ��
    double Lon;     //����
    
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
const double g0   = 9.81;			// �������ٶ� (��/��^2)
const double Rho0 = 1.2255;			// �����ܶ� (ǧ��/��^3)
//const double PI   = 3.1415926536;		// Բ����
const double R2D  = (180.0/PI);			// ���Ȼ�Ϊ�Ƕ�
const double D2R  = (PI/180.0);			// �ǶȻ�Ϊ����
const double Re   = 6378137.0;			// ����뾶 (��)

#endif	// MISSILE_COMMON_H_
