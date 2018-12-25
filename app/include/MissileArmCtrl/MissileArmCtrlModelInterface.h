///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef	MISSILEARMCONTROLMODEL_USERMODEL_INTERFACE_H_
#define	MISSILEARMCONTROLMODEL_USERMODEL_INTERFACE_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

#define   RouteNumMax     8  //一次航路规划最大允许的航路数
#define   WayPointMax     15 //一条航路最多航路点数

enum MISSILETYPE // 导弹模型枚举
{ 
    MT_YJ18=0,         // YJ18动力学模型
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

struct ShipInfoStruct
{
	string ID   ;     //舰艇标识ID
	double Jc   ;     //舰艇的经度（度）
	double Wc   ;     //舰艇的纬度（度）
	double Hc   ;     //舰艇的高度，米
	double Vc   ;     //舰艇的航速（m/s）
	double Kc   ;     //舰艇的航向（度）（0~360°）
	
	double Zyj  ;     //舰艇的纵摇角（度），上为正（0~±15°）
	double Hyj  ;     //舰艇的横摇角（度），右下斜为正（0~±30°）	
	double Gdmzj;     //舰艇的发射架固定方位角(+-90度)，左舷-90度，右舷+90度
	double Gdfyj;     //舰艇的发射架固定俯仰角(15°)，上+，下-
};

struct PlaneInfoStruct
{
	string ID   ;     //飞机标识ID
	double Jc   ;     //飞机的经度（度）
	double Wc   ;     //飞机的纬度（度）
	double Hc   ;     //飞机的高度，米
	double Vc   ;     //飞机的航速（m/s）
	double Kc   ;     //飞机的航向（度）（0~360°）
	
	double Zeta ;     //飞机的俯仰角（度）
	double Gamma;     //飞机的滚动角（度）	
	double Gdmzj;     //飞机的发射架固定方位角(0°)
	double Gdfyj;     //飞机的发射架固定俯仰角(0°)，上+，下-
	double Overload;  //飞机过载，g
};

struct WayPointPlaningOutput	// 单条航路信息
{
	int	    nWayPoint;	        // 航路的航路点数 
	double	Sm;	                // 航路的航程，单位：Km
	double	Jm[WayPointMax];	// 航路点坐标(经度，单位：度) 
	double	Wm[WayPointMax];	// 航路点坐标(纬度，单位：度)
	double	Rm[WayPointMax];	// 各航路点处的转弯半径，单位：Km
	double  Am[WayPointMax]; //各条航路各航路点处的转弯角，单位：度
	
	// 拷贝构造函数
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

struct MissileFundamentalInfo	// 导弹战技术性能参数
{
	int    Carrier;								 // 发射载体
	double Rmax;								 // 导弹最大射程
	double Rmin; 								 // 导弹最小射程
	double Hp; 									 // 巡航高度
	double Vdd; 								 // 巡航速度
	double PhFyj; 								 // 导弹巡航平飞时的平衡俯仰角
	double RangeGate1; 							 // 导引头搜索近界
	double AngleGate; 							 // 导引头搜索扇面
	double RangeGate2; 							 // 导引头搜索远界
};

struct RoutPlanPara				// 航路规划参数
{	
	double MinFirstWayPointToLauncherDistance;	// 第一个航路点与发射点间距
	double MinNeighborhoodWayPointDistance;		// 相邻航路点最短距离
	double MinFinalWayPointToTargetDistance;	// 最后一个航路点与目标间的最小距离
	double MaxTuringAngle;						// 航路最大转弯角
	double MinTuringRadiusLimit;				// 最小转弯半径
	double TzkMin;								// 最小自控飞行时间
};

struct FireControlConstraint	// 火控系统发射限制条件
{
	double MissileLaunchVectorLimit;			// 导弹发射扇面限制条件
	double MissileLaunchPlanePitchingLimit;		// 导弹发射时载机俯仰角限制条件
	double MissileLaunchPlaneRollingLimit;		// 导弹发射时载机滚动角限制条件
	double MissileLaunchPlaneOverloaddingLimit; // 导弹发射时载机过载限制条件
	double MissileLaunchShipRollingLimit;		// 导弹发射时载舰横摇角限制条件
	double MissileLaunchShipPitchingLimit;		// 导弹发射时载舰纵摇角限制条件
	double MissileLaunchHeighLimit;				// 导弹发射高度上限限制条件
	double MissileLaunchSpeedLimit; 			// 导弹发射速度上限限制条件
	double MissileLaunchVfmax; 					// 导弹发射最大允许风速
	double MissileLaunchHqmax; 					// 导弹发射最大允许海情等级
	double MissileLaunchTempmin; 				// 导弹发射最低温度
	double MissileLaunchTempmax; 				// 导弹发射最高温度
};

struct TargetIndicationInfo	// 目标指示信息
{
	string  TarID;          // 目标代号ID
	double	TarLongitude;	// 目标经度
	double	TarLatitude;	// 目标纬度
	float   TarElevationAGL;// 目标高度
	float	TarDirection;	// 目标航向
	float	TarSpeed;	    // 目标速度
	float   TargetJD;       // 目标机动系数
	short	CalculateMode;	// 指挥仪解算方式：0 雷达攻击，1 坐标攻击，2 前置点攻击，3 纯方位攻击，4 人工装订 
	double	SimuTime;	    // 时戳，秒

	short PathType;         // 航路规划控制：0=无规划；1=自动规划；2人工规划
	int   nNumOfMissile;    // 用于打击该目标的导弹数量，最大值为：RouteNumMax
	double AttackAngle;		// 主攻击角
	double AttackDelta;		// 攻击夹角
	WayPointPlaningOutput PathPar; //人工规划时，提供航路点信息
	
	// 拷贝构造函数
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

struct LaunchAntishipInfo //武控-》导弹，反舰导弹发射信息
{
public:
	string PtID;             //平台代号ID
	string TarID;            //目标代号ID
	float TarBmb;            //目标方位，度
	float TarRmb;            //目标距离，米
	short PathType;          //航路规划类型：0=无规划；1=自动规划；2人工规划
	WayPointPlaningOutput PathPar; //航路点信息
	MISSILETYPE MissileType; //导弹型号
	double Tzk;              //自控飞行时间，秒
	double Rzd;              //末制导雷达作用距离，米
	double ZdQzhxj;          //装订前置航向角，度
	double ZdQxj;            //装订滚动角，度
	double ZdFyj;            //装订俯仰角，度
	double Hp   ;          //导弹平飞高度 米	
	double RangeGate1;     //距离波门下限 米	
	double RangeGate2;     //距离波门上限 米	
	double AngleGate ;     //角度波门 度
	double SimuTime;         //时戳，秒
	
	// 拷贝构造函数
	LaunchAntishipInfo(){}
	LaunchAntishipInfo(const LaunchAntishipInfo& sourceData)
	{
		PtID = sourceData.PtID;
		TarID = sourceData.TarID;
		TarBmb = sourceData.TarBmb; //目标方位，度
		TarRmb = sourceData.TarRmb; //目标距离，米
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
		Hp    = sourceData.Hp;          //导弹平飞高度 米	
		RangeGate1 = sourceData.RangeGate1;    //距离波门下限 米	
		RangeGate2 = sourceData.RangeGate2;    //距离波门上限 米	
		AngleGate  = sourceData.AngleGate;     //角度波门 度
		SimuTime = sourceData.SimuTime;
	}
	const LaunchAntishipInfo& operator = (const LaunchAntishipInfo& sourceData)
	{
		PtID = sourceData.PtID;
		TarID = sourceData.TarID;
		TarBmb = sourceData.TarBmb; //目标方位，度
		TarRmb = sourceData.TarRmb; //目标距离，米
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
		Hp    = sourceData.Hp;          //导弹平飞高度 米	
		RangeGate1 = sourceData.RangeGate1;     //距离波门下限 米	
		RangeGate2 = sourceData.RangeGate2;     //距离波门上限 米	
		AngleGate  = sourceData.AngleGate ;     //角度波门 度
		SimuTime = sourceData.SimuTime;
		return *this;
	}
};

struct LaunchAGM65FInfo
{
public:
	string PtID;             //平台代号ID
	string TarID;            //目标代号ID
	float TarBmb;            //目标方位，度
	float TarRmb;            //目标距离，米
	double qh;              //前置航向角
	double qf;              //导弹俯冲角
	double Rt;              //目标斜距，米
};
/*----------------------------------------------------------*/

class MISSILEARMCTRL_API CMissileArmCtrlModel
{
public:
	virtual void SetEnvironmentPara(double Cf, double Vf, double Tao, int Hk) = 0; //设置环境参数：风向，风速，温度，海况等级
	virtual void SetEnvironmentPara1(double RH, double Js, double Jr, double Va, double lamd) = 0; //设置环境参数：相对湿度（％）、降雪强度、降雨强度（mm/h）、大气能见度（km）、红外光谱波长：0.3---13.9
	virtual void SetCarrierType(int nType)              = 0; //设置导弹发射平台的类型：0 舰载，1 机载
	virtual void SetShipInfo(ShipInfoStruct stuShip)    = 0; //设置舰艇的信息
	virtual void SetPlaneInfo(PlaneInfoStruct stuPlane) = 0; //设置飞机的信息
	virtual void SetMissileType(MISSILETYPE type)       = 0; //设置导弹的类型
	virtual void SetMissileInfo(double Vdd, double Rzd, double PhFyj, double Hp, double RangeGate1, double RangeGate2, double AngleGate) = 0; //设置导弹的信息
	virtual void GetMissileInfo(double& Vdd, double& Rzd, double& PhFyj, double& Hp, double& RangeGate1, double& RangeGate2, double& AngleGate) = 0; //获取导弹的信息
	virtual void SetPlanParam(MissileFundamentalInfo mis, RoutPlanPara par, FireControlConstraint con) = 0; //设置航路规划参数
	virtual void ReceiveTargetDesignationInfo(TargetIndicationInfo TargetIndication) = 0; //接收目标指示信息
	virtual bool MainSimulation() = 0; //主模块
	virtual void SendLaunchInfo(LaunchAntishipInfo* LaunchInfo, int& nNum) = 0; //发布导弹发射信息
	virtual void LaunchAGM65F(LaunchAGM65FInfo& LaunchInfo) = 0; //发布小牛导弹发射信息	
	virtual void GetErrorStr(char str[]) = 0;
};

/* 模型工厂类导出函数 */
class MISSILEARMCTRL_API CMissileArmCtrlModelFactory	// 工厂用于生成导弹实体或删除已创建的实体
{
public:
	static CMissileArmCtrlModel* CreateMissileArmCtrlModel();	
	static void DeleteMissileArmCtrlModel(CMissileArmCtrlModel* pEntity);
};

#endif // MISSILEARMCONTROLMODEL_USERMODEL_INTERFACE_H_
