///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef	MISSILEARMCONTROLMODEL_USERMODEL_INTERFACE_H_
#define	MISSILEARMCONTROLMODEL_USERMODEL_INTERFACE_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

#define   RouteNumMax     8  //һ�κ�·�滮�������ĺ�·��
#define   WayPointMax     15 //һ����·��ຽ·����

enum MISSILETYPE // ����ģ��ö��
{ 
    MT_YJ18=0,         // YJ18����ѧģ��
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

struct ShipInfoStruct
{
	string ID   ;     //��ͧ��ʶID
	double Jc   ;     //��ͧ�ľ��ȣ��ȣ�
	double Wc   ;     //��ͧ��γ�ȣ��ȣ�
	double Hc   ;     //��ͧ�ĸ߶ȣ���
	double Vc   ;     //��ͧ�ĺ��٣�m/s��
	double Kc   ;     //��ͧ�ĺ��򣨶ȣ���0~360�㣩
	
	double Zyj  ;     //��ͧ����ҡ�ǣ��ȣ�����Ϊ����0~��15�㣩
	double Hyj  ;     //��ͧ�ĺ�ҡ�ǣ��ȣ�������бΪ����0~��30�㣩	
	double Gdmzj;     //��ͧ�ķ���̶ܹ���λ��(+-90��)������-90�ȣ�����+90��
	double Gdfyj;     //��ͧ�ķ���̶ܹ�������(15��)����+����-
};

struct PlaneInfoStruct
{
	string ID   ;     //�ɻ���ʶID
	double Jc   ;     //�ɻ��ľ��ȣ��ȣ�
	double Wc   ;     //�ɻ���γ�ȣ��ȣ�
	double Hc   ;     //�ɻ��ĸ߶ȣ���
	double Vc   ;     //�ɻ��ĺ��٣�m/s��
	double Kc   ;     //�ɻ��ĺ��򣨶ȣ���0~360�㣩
	
	double Zeta ;     //�ɻ��ĸ����ǣ��ȣ�
	double Gamma;     //�ɻ��Ĺ����ǣ��ȣ�	
	double Gdmzj;     //�ɻ��ķ���̶ܹ���λ��(0��)
	double Gdfyj;     //�ɻ��ķ���̶ܹ�������(0��)����+����-
	double Overload;  //�ɻ����أ�g
};

struct WayPointPlaningOutput	// ������·��Ϣ
{
	int	    nWayPoint;	        // ��·�ĺ�·���� 
	double	Sm;	                // ��·�ĺ��̣���λ��Km
	double	Jm[WayPointMax];	// ��·������(���ȣ���λ����) 
	double	Wm[WayPointMax];	// ��·������(γ�ȣ���λ����)
	double	Rm[WayPointMax];	// ����·�㴦��ת��뾶����λ��Km
	double  Am[WayPointMax]; //������·����·�㴦��ת��ǣ���λ����
	
	// �������캯��
	WayPointPlaningOutput()
	{
		nWayPoint = 0;
		Sm = 0.0;
		memset(Jm, 0, WayPointMax*sizeof(double));
		memset(Wm, 0, WayPointMax*sizeof(double));
		memset(Rm, 0, WayPointMax*sizeof(double));
		memset(Am, 0, WayPointMax*sizeof(double));
	}
	WayPointPlaningOutput(const WayPointPlaningOutput& sourceData)
	{
		nWayPoint = sourceData.nWayPoint;
		Sm = sourceData.Sm;
		memcpy(Jm, sourceData.Jm, WayPointMax*sizeof(double));
		memcpy(Wm, sourceData.Wm, WayPointMax*sizeof(double));
		memcpy(Rm, sourceData.Rm, WayPointMax*sizeof(double));
		memcpy(Am, sourceData.Am, WayPointMax*sizeof(double));
	}
	const WayPointPlaningOutput& operator = (const WayPointPlaningOutput& sourceData)
	{
		nWayPoint = sourceData.nWayPoint;
		Sm = sourceData.Sm;
		memcpy(Jm, sourceData.Jm, WayPointMax*sizeof(double));
		memcpy(Wm, sourceData.Wm, WayPointMax*sizeof(double));
		memcpy(Rm, sourceData.Rm, WayPointMax*sizeof(double));
		memcpy(Am, sourceData.Am, WayPointMax*sizeof(double));
		return *this;
	}
};

struct MissileFundamentalInfo	// ����ս�������ܲ���
{
	int    Carrier;								 // ��������
	double Rmax;								 // ����������
	double Rmin; 								 // ������С���
	double Hp; 									 // Ѳ���߶�
	double Vdd; 								 // Ѳ���ٶ�
	double PhFyj; 								 // ����Ѳ��ƽ��ʱ��ƽ�⸩����
	double RangeGate1; 							 // ����ͷ��������
	double AngleGate; 							 // ����ͷ��������
	double RangeGate2; 							 // ����ͷ����Զ��
};

struct RoutPlanPara				// ��·�滮����
{	
	double MinFirstWayPointToLauncherDistance;	// ��һ����·���뷢�����
	double MinNeighborhoodWayPointDistance;		// ���ں�·����̾���
	double MinFinalWayPointToTargetDistance;	// ���һ����·����Ŀ������С����
	double MaxTuringAngle;						// ��·���ת���
	double MinTuringRadiusLimit;				// ��Сת��뾶
	double TzkMin;								// ��С�Կط���ʱ��
};

struct FireControlConstraint	// ���ϵͳ������������
{
	double MissileLaunchVectorLimit;			// ��������������������
	double MissileLaunchPlanePitchingLimit;		// ��������ʱ�ػ���������������
	double MissileLaunchPlaneRollingLimit;		// ��������ʱ�ػ���������������
	double MissileLaunchPlaneOverloaddingLimit; // ��������ʱ�ػ�������������
	double MissileLaunchShipRollingLimit;		// ��������ʱ�ؽ���ҡ����������
	double MissileLaunchShipPitchingLimit;		// ��������ʱ�ؽ���ҡ����������
	double MissileLaunchHeighLimit;				// ��������߶�������������
	double MissileLaunchSpeedLimit; 			// ���������ٶ�������������
	double MissileLaunchVfmax; 					// ������������������
	double MissileLaunchHqmax; 					// �����������������ȼ�
	double MissileLaunchTempmin; 				// ������������¶�
	double MissileLaunchTempmax; 				// ������������¶�
};

struct TargetIndicationInfo	// Ŀ��ָʾ��Ϣ
{
	string  TarID;          // Ŀ�����ID
	double	TarLongitude;	// Ŀ�꾭��
	double	TarLatitude;	// Ŀ��γ��
	float   TarElevationAGL;// Ŀ��߶�
	float	TarDirection;	// Ŀ�꺽��
	float	TarSpeed;	    // Ŀ���ٶ�
	float   TargetJD;       // Ŀ�����ϵ��
	short	CalculateMode;	// ָ���ǽ��㷽ʽ��0 �״﹥����1 ���깥����2 ǰ�õ㹥����3 ����λ������4 �˹�װ�� 
	double	SimuTime;	    // ʱ������

	short PathType;         // ��·�滮���ƣ�0=�޹滮��1=�Զ��滮��2�˹��滮
	int   nNumOfMissile;    // ���ڴ����Ŀ��ĵ������������ֵΪ��RouteNumMax
	double AttackAngle;		// ��������
	double AttackDelta;		// �����н�
	WayPointPlaningOutput PathPar; //�˹��滮ʱ���ṩ��·����Ϣ
	
	// �������캯��
	TargetIndicationInfo()
	{
		TarID = "";
		TarLongitude = 0.0;
		TarLatitude = 0.0;
		TarElevationAGL = 0.0;
		TarDirection = 0.0;
		TarSpeed = 0.0;
		TargetJD = 1.0;
		CalculateMode = 1;
		SimuTime = 0.0;	
		PathType = 1;
		nNumOfMissile = 0;
		AttackAngle = 0.0;
		AttackDelta = 5.0;
	}
	TargetIndicationInfo(const TargetIndicationInfo& sourceData)
	{
		TarID = sourceData.TarID;
		TarLongitude = sourceData.TarLongitude;
		TarLatitude = sourceData.TarLatitude;
		TarElevationAGL = sourceData.TarElevationAGL;
		TarDirection = sourceData.TarDirection;
		TarSpeed = sourceData.TarSpeed;
		TargetJD = sourceData.TargetJD;
		CalculateMode = sourceData.CalculateMode;
		SimuTime = sourceData.SimuTime;
		PathType = sourceData.PathType;
		nNumOfMissile = sourceData.nNumOfMissile;
		PathPar = sourceData.PathPar;
		AttackAngle = sourceData.AttackAngle;
		AttackDelta = sourceData.AttackDelta;
	}
	const TargetIndicationInfo& operator = (const TargetIndicationInfo& sourceData)
	{
		TarID = sourceData.TarID;
		TarLongitude = sourceData.TarLongitude;
		TarLatitude = sourceData.TarLatitude;
		TarElevationAGL = sourceData.TarElevationAGL;
		TarDirection = sourceData.TarDirection;
		TarSpeed = sourceData.TarSpeed;
		TargetJD = sourceData.TargetJD;
		CalculateMode = sourceData.CalculateMode;
		SimuTime = sourceData.SimuTime;
		PathType = sourceData.PathType;
		nNumOfMissile = sourceData.nNumOfMissile;
		PathPar = sourceData.PathPar;
		AttackAngle = sourceData.AttackAngle;
		AttackDelta = sourceData.AttackDelta;
		return *this;
	}
};

struct LaunchAntishipInfo //���-����������������������Ϣ
{
public:
	string PtID;             //ƽ̨����ID
	string TarID;            //Ŀ�����ID
	float TarBmb;            //Ŀ�귽λ����
	float TarRmb;            //Ŀ����룬��
	short PathType;          //��·�滮���ͣ�0=�޹滮��1=�Զ��滮��2�˹��滮
	WayPointPlaningOutput PathPar; //��·����Ϣ
	MISSILETYPE MissileType; //�����ͺ�
	double Tzk;              //�Կط���ʱ�䣬��
	double Rzd;              //ĩ�Ƶ��״����þ��룬��
	double ZdQzhxj;          //װ��ǰ�ú���ǣ���
	double ZdQxj;            //װ�������ǣ���
	double ZdFyj;            //װ�������ǣ���
	double Hp   ;          //����ƽ�ɸ߶� ��	
	double RangeGate1;     //���벨������ ��	
	double RangeGate2;     //���벨������ ��	
	double AngleGate ;     //�ǶȲ��� ��
	double SimuTime;         //ʱ������
	
	// �������캯��
	LaunchAntishipInfo(){}
	LaunchAntishipInfo(const LaunchAntishipInfo& sourceData)
	{
		PtID = sourceData.PtID;
		TarID = sourceData.TarID;
		TarBmb = sourceData.TarBmb; //Ŀ�귽λ����
		TarRmb = sourceData.TarRmb; //Ŀ����룬��
		PathType = sourceData.PathType;
		PathPar.Sm = sourceData.PathPar.Sm;	
		PathPar.nWayPoint = sourceData.PathPar.nWayPoint;
		for (int i=0; i<PathPar.nWayPoint; i++)
		{
			PathPar.Jm[i]=sourceData.PathPar.Jm[i];
			PathPar.Wm[i]=sourceData.PathPar.Wm[i];
			PathPar.Rm[i]=sourceData.PathPar.Rm[i];
			PathPar.Am[i]=sourceData.PathPar.Am[i];
		}
		MissileType = sourceData.MissileType;
		Tzk = sourceData.Tzk;
		Rzd = sourceData.Rzd;
		ZdQzhxj = sourceData.ZdQzhxj;
		ZdQxj = sourceData.ZdQxj;
		ZdFyj = sourceData.ZdFyj;
		Hp    = sourceData.Hp;          //����ƽ�ɸ߶� ��	
		RangeGate1 = sourceData.RangeGate1;    //���벨������ ��	
		RangeGate2 = sourceData.RangeGate2;    //���벨������ ��	
		AngleGate  = sourceData.AngleGate;     //�ǶȲ��� ��
		SimuTime = sourceData.SimuTime;
	}
	const LaunchAntishipInfo& operator = (const LaunchAntishipInfo& sourceData)
	{
		PtID = sourceData.PtID;
		TarID = sourceData.TarID;
		TarBmb = sourceData.TarBmb; //Ŀ�귽λ����
		TarRmb = sourceData.TarRmb; //Ŀ����룬��
		PathType = sourceData.PathType;
		PathPar.Sm = sourceData.PathPar.Sm;	
		PathPar.nWayPoint = sourceData.PathPar.nWayPoint;
		for (int i=0; i<PathPar.nWayPoint; i++)
		{
			PathPar.Jm[i]=sourceData.PathPar.Jm[i];
			PathPar.Wm[i]=sourceData.PathPar.Wm[i];
			PathPar.Rm[i]=sourceData.PathPar.Rm[i];
			PathPar.Am[i]=sourceData.PathPar.Am[i];
		}
		MissileType = sourceData.MissileType;
		Tzk = sourceData.Tzk;
		Rzd = sourceData.Rzd;
		ZdQzhxj = sourceData.ZdQzhxj;
		ZdQxj = sourceData.ZdQxj;
		ZdFyj = sourceData.ZdFyj;
		Hp    = sourceData.Hp;          //����ƽ�ɸ߶� ��	
		RangeGate1 = sourceData.RangeGate1;     //���벨������ ��	
		RangeGate2 = sourceData.RangeGate2;     //���벨������ ��	
		AngleGate  = sourceData.AngleGate ;     //�ǶȲ��� ��
		SimuTime = sourceData.SimuTime;
		return *this;
	}
};

struct LaunchAGM65FInfo
{
public:
	string PtID;             //ƽ̨����ID
	string TarID;            //Ŀ�����ID
	float TarBmb;            //Ŀ�귽λ����
	float TarRmb;            //Ŀ����룬��
	double qh;              //ǰ�ú����
	double qf;              //���������
	double Rt;              //Ŀ��б�࣬��
};
/*----------------------------------------------------------*/

class MISSILEARMCTRL_API CMissileArmCtrlModel
{
public:
	virtual void SetEnvironmentPara(double Cf, double Vf, double Tao, int Hk) = 0; //���û������������򣬷��٣��¶ȣ������ȼ�
	virtual void SetEnvironmentPara1(double RH, double Js, double Jr, double Va, double lamd) = 0; //���û������������ʪ�ȣ���������ѩǿ�ȡ�����ǿ�ȣ�mm/h���������ܼ��ȣ�km����������ײ�����0.3---13.9
	virtual void SetCarrierType(int nType)              = 0; //���õ�������ƽ̨�����ͣ�0 ���أ�1 ����
	virtual void SetShipInfo(ShipInfoStruct stuShip)    = 0; //���ý�ͧ����Ϣ
	virtual void SetPlaneInfo(PlaneInfoStruct stuPlane) = 0; //���÷ɻ�����Ϣ
	virtual void SetMissileType(MISSILETYPE type)       = 0; //���õ���������
	virtual void SetMissileInfo(double Vdd, double Rzd, double PhFyj, double Hp, double RangeGate1, double RangeGate2, double AngleGate) = 0; //���õ�������Ϣ
	virtual void GetMissileInfo(double& Vdd, double& Rzd, double& PhFyj, double& Hp, double& RangeGate1, double& RangeGate2, double& AngleGate) = 0; //��ȡ��������Ϣ
	virtual void SetPlanParam(MissileFundamentalInfo mis, RoutPlanPara par, FireControlConstraint con) = 0; //���ú�·�滮����
	virtual void ReceiveTargetDesignationInfo(TargetIndicationInfo TargetIndication) = 0; //����Ŀ��ָʾ��Ϣ
	virtual bool MainSimulation() = 0; //��ģ��
	virtual void SendLaunchInfo(LaunchAntishipInfo* LaunchInfo, int& nNum) = 0; //��������������Ϣ
	virtual void LaunchAGM65F(LaunchAGM65FInfo& LaunchInfo) = 0; //����Сţ����������Ϣ	
	virtual void GetErrorStr(char str[]) = 0;
};

/* ģ�͹����ർ������ */
class MISSILEARMCTRL_API CMissileArmCtrlModelFactory	// �����������ɵ���ʵ���ɾ���Ѵ�����ʵ��
{
public:
	static CMissileArmCtrlModel* CreateMissileArmCtrlModel();	
	static void DeleteMissileArmCtrlModel(CMissileArmCtrlModel* pEntity);
};

#endif // MISSILEARMCONTROLMODEL_USERMODEL_INTERFACE_H_
