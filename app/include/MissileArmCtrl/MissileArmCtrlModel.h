// MissileArmCtrlModel.h: interface for the CMissileArmCtrlModelUser class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MISSILEARMCTRLMODE__USERMODEL_H_
#define MISSILEARMCTRLMODE__USERMODEL_H_

#define PI  3.1415926
#define DtR 0.017453292
#define RtD 57.29578049
#define MatM 340.0

#define CDBJ   6378245          //地球参考椭球体赤道半径
#define JBJ    6356863          //地球参考椭球体极半径
#define DXBJ   637000           //地球等效半径
#define BL     0.00335233281    //地球参考椭球体扁率
#define PXLPF1 0.00669342749    //地球椭球体子午圈第一偏心率平方(a^2+b^2)/a^2
#define PXLPF2 0.00673853541    //地球椭球体子午圈第二偏心率平方(a^2+b^2)/b^2
#define Wzz    0.004178         //常值 地球自转角速度(度/秒)

struct FireCtrlOutput //无航路规划下的火控解算输出
{
	double Tzk;        //自控飞行时间（s）
	double ZdQzhxj;    //装订前置航向角，单位（度），逆时针为正
	double ZdFyj  ;    //装订俯仰角（度）
	double ZdQxj  ;    //装订倾斜角（度）
};

struct AutoWayPointPlaningOutput //纯自动航路规划输出
{
	int    HlNum;	                     //总可行航路数
	int    Pm[RouteNumMax];	             //各条航路的航路点数
	double Sm[RouteNumMax];              //各条航路的航程，单位：Km
	double Jm[RouteNumMax][WayPointMax]; //各条航路的航路点坐标(经度，单位：度)
	double Wm[RouteNumMax][WayPointMax]; //各条航路的航路点坐标(纬度，单位：度)
	double Rm[RouteNumMax][WayPointMax]; //各条航路各航路点处的转弯半径，单位：Km
	double Am[RouteNumMax][WayPointMax]; //各条航路各航路点处的转弯角，单位：度
	
	AutoWayPointPlaningOutput()
	{
		HlNum = 0; //总可行航路数
		memset(Pm, 0, RouteNumMax*sizeof(int));
		memset(Sm, 0, RouteNumMax*sizeof(double));
		memset(Jm, 0, RouteNumMax*WayPointMax*sizeof(double));
		memset(Wm, 0, RouteNumMax*WayPointMax*sizeof(double));
		memset(Rm, 0, RouteNumMax*WayPointMax*sizeof(double));
		memset(Am, 0, RouteNumMax*WayPointMax*sizeof(double));
	}
};       

struct FireCtrlCalcuUnderWayPointPlaning //航路规划下的单条航路火控解算输出
{
	double Tzk    ;    //自控飞行时间（s）
	double ZdQzhxj;    //装订前置航向角，单位（度），逆时针为正
	double ZdFyj  ;    //装订俯仰角（度）
	double ZdQxj  ;    //装订倾斜角（度）

	int    nWayPoint;	     //航路的航路点数
	double Sm;               //航路的航程，单位：Km
	double Jm[WayPointMax];  //航路点坐标(经度，单位：度) 
	double Wm[WayPointMax];	 //航路点坐标(纬度，单位：度) 	
	double Rm[WayPointMax];  //各航路点处的转弯半径，单位：Km
	double Am[WayPointMax];  //各航路点处的转弯角，单位：度
	
	FireCtrlCalcuUnderWayPointPlaning()
	{
		Tzk     = 0.0;    //自控飞行时间（s）
		ZdQzhxj = 0.0;    //装订前置航向角，单位（度），逆时针为正
		ZdFyj   = 0.0;    //装订俯仰角（度）
		ZdQxj   = 0.0;    //装订倾斜角（度）		
		nWayPoint = 0;
		Sm = 0.0;
		memset(Jm, 0, WayPointMax*sizeof(double));
		memset(Wm, 0, WayPointMax*sizeof(double));
		memset(Rm, 0, WayPointMax*sizeof(double));
		memset(Am, 0, WayPointMax*sizeof(double));
	}
};

struct FireCtrlCalcuUnderAutoWayPointPlaning //自动航路规划下的多条航路火控解算输出
{
	double Tzk[RouteNumMax]    ;    //自控飞行时间（s）
	double ZdQzhxj[RouteNumMax];    //装订前置航向角，单位（度），逆时针为正
	double ZdFyj[RouteNumMax]  ;    //装订俯仰角（度）
	double ZdQxj[RouteNumMax]  ;    //装订倾斜角（度）
	
	int    HlNum;	                     //总可行航路数
	int    Pm[RouteNumMax];	             //各条航路的航路点数
	double Sm[RouteNumMax];              //各条航路的航程，单位：Km
	double Jm[RouteNumMax][WayPointMax]; //各条航路的航路点坐标(经度，单位：度)
	double Wm[RouteNumMax][WayPointMax]; //各条航路的航路点坐标(纬度，单位：度)
	double Rm[RouteNumMax][WayPointMax]; //各条航路各航路点处的转弯半径，单位：Km
	double Am[RouteNumMax][WayPointMax]; //各条航路各航路点处的转弯角，单位：度
	
	FireCtrlCalcuUnderAutoWayPointPlaning()
	{
		HlNum = 0;
		memset(Tzk    , 0, RouteNumMax*sizeof(double));
		memset(ZdQzhxj, 0, RouteNumMax*sizeof(double));
		memset(ZdFyj  , 0, RouteNumMax*sizeof(double));
		memset(ZdQxj  , 0, RouteNumMax*sizeof(double));
		memset(Pm     , 0, RouteNumMax*sizeof(int));
		memset(Sm     , 0, RouteNumMax*sizeof(double));		
		memset(Jm     , 0, WayPointMax*RouteNumMax*sizeof(double));
		memset(Wm     , 0, WayPointMax*RouteNumMax*sizeof(double));
		memset(Rm     , 0, WayPointMax*RouteNumMax*sizeof(double));
		memset(Am     , 0, WayPointMax*RouteNumMax*sizeof(double));
	}
};

struct ShipMissileLaunchLimit  //舰载导弹发射限制条件
{
	double MissileminRange;                      //导弹最短航程限制条件，单位：km	
	double MissilemaxRange;                      //导弹最大航程限制条件，单位：km	
	double MissileLaunchVectorLimit;             //导弹发射扇面限制条件，单位：度
	double MissileLaunchShipPitchingLimit;       //载舰俯仰角限制条件，单位：度	
	double MissileLaunchShipRollingLimit;        //载舰倾斜角限制条件，单位：度	
	
	double MissileLaunchVfmax;                   //导弹发射最大允许风速，米/秒
	double MissileLaunchTempmin;                 //导弹发射最低温度,度
	double MissileLaunchTempmax;                 //导弹发射最高温度,度
	int    MissileLaunchHqmax;                   //导弹发射最大允许海情等级
};

struct PlaneMissileLaunchLimit  //机载导弹发射限制条件
{
	double MissileminRange; 	                 //导弹最短航程限制条件，单位：km
	double MissilemaxRange;                      //导弹最大航程限制条件，单位：km	
	double MissileLaunchVectorLimit;             //导弹发射扇面限制条件，单位：度	
	double MissileLaunchHeighLimit;              //载机发射高度限制条件	，单位：m
	double MissileLaunchSpeedLimit;              //载机发射速度限制条件	，单位：m_/s
	double MissileLaunchPlanePitchingLimit;      //导弹发射时载机俯仰角限制条件	，单位：度
	double MissileLaunchPlaneRollingLimit;       //导弹发射时载机滚动角限制条件	，单位：度
	double MissileLaunchPlaneOverloaddingLimit;  //导弹发射时载机过载限制条件，单位：g
	
	double MissileLaunchVfmax;                   //导弹发射最大允许风速，米/秒
	double MissileLaunchTempmin;                 //导弹发射最低温度,度
	double MissileLaunchTempmax;                 //导弹发射最高温度,度
};

struct ShipFireControlBindingState //舰载火控解算状态标识数据结构
{
	bool  MinrangeOK;       //射程满足大于导弹最小射程条件
	bool  MaxrangeOK;       //射程满足小于导弹最大射程条件
	bool  TargetInsight;    //目标位于射击扇面内（鱼叉导弹发射扇面±90°）
	
	bool  LaunchZetaOK;     //舰艇纵摇角是否满足要求（±15°）
	bool  LaunchGamaOK;     //舰艇横摇角是否满足要求（±6°）
	
	bool  WindOK;           //在允许发射风速范围内（40m/s以下）
	bool  TemperatureOK;    //在允许发射温度范围内（-30℃～+60℃）
	bool  SituationOK;      //海情是否在5级以下
}; 

struct PlaneFireControlBindingState //机载火控解算状态标识数据结构
{
	bool  MinrangeOK;       //射程满足大于导弹最小射程条件
	bool  MaxrangeOK;       //射程满足小于导弹最大射程条件
	bool  TargetInsight;    //目标位于射击扇面内（鱼叉导弹发射扇面±90°）
	bool  LaunchHighOK;     //在允许发射高度范围内（300～9000米）
	bool  LaunchSpeedOK;    //在允许发射速度范围内（在300～4500米时，发射速度为0.75～0.9Ma；在4500～9000米时，发射速度为0.65～0.9Ma）
	bool  LaunchAttitudeOK; //在允许发射姿态范围内（载机俯仰角-2°～+6°；滚动角-10°～+10°）
	bool  LaunchOverloadOK; //在允许发射过载范围内（2g）
	bool  WindOK;           //在允许发射风速范围内（40m/s以下）
	bool  TemperatureOK;    //在允许发射温度范围内（-30℃～+60℃）
}; 

class CFireCtrlOutput //单目标火控解算处理结果
{ 
public:
	string TargetID   ;     //目标舰艇资源标识
	double TargetJt   ;     //目标经度（度）
	double TargetWt   ;     //目标纬度（度）
	float  TargetHt   ;     //目标高度（米）
	float  TargetRmb  ;     //目标相对导弹发射平台的距离(m)
	float  TargetBmb  ;     //目标方位（度）（0~360°）
	float  TargetVm   ;     //目标航速（m/s）
	float  TargetKm   ;     //目标航向（度）（0~360°）
	float  TargetJD   ;     //目标机动系数
	short  CalculateMode;	//指挥仪解算方式：0 雷达攻击，1 坐标攻击，2 前置点攻击，3 纯方位攻击，4 人工装订 
	double SimuTime   ;	    //时戳
	
	double Tzk;             //自控飞行时间（s）
	double ZdQzhxj;         //装订前置航向角PHIq，单位（度），逆时针为正
	double ZdFyj  ;         //装订俯仰角NUz（度）
	double ZdQxj  ;         //装订倾斜角GAMMAz（度）
	
	short  PathType;        //航路规划控制：0=无规划；1=自动规划；2人工规划
	int    nNumOfMissile;   //用于打击该目标的导弹数量
	string                     IdOfMissile[RouteNumMax]; //每枚导弹的ID标识
	FireCtrlCalcuUnderWayPointPlaning path[RouteNumMax]; //每枚导弹的攻击航路信息
	int    StateOfMissile[RouteNumMax]; //0导弹处于预备状态，1导弹已发射
	short  TarStateOfDeal;  //目标最终处理状态，0=不可打击；1=可打击；2=打击中	
public:	
	CFireCtrlOutput() //构造函数
	{
		TargetID = "";
		TargetJD = 1.0;     //默认为目标不机动
		CalculateMode = 0;	//指挥仪解算方式
		SimuTime = 0.0;	    //时戳		
		PathType = 0;       //不进行航路规划
		nNumOfMissile=0;        
		TarStateOfDeal=0;
		for(int i=0;i<RouteNumMax;i++)
		{
			IdOfMissile[i] = "";  //每枚导弹的ID标识
			path[i].nWayPoint = 0;
			path[i].Sm = 0.0;
			path[i].Tzk = 0.0;
			path[i].ZdFyj = 0.0;
			path[i].ZdQxj = 0.0;
			path[i].ZdQzhxj = 0.0;
			for(int j = 0; j<WayPointMax; j++)
			{
				path[i].Jm[j] = 0.0;
				path[i].Wm[j] = 0.0;
				path[i].Rm[j] = 0.0;
				path[i].Am[j] = 0.0;
			}
			StateOfMissile[i] = 0; //0导弹处于预备状态，1导弹已发射
		}
	};
};

class CMissileArmCtrlModelUser : public CMissileArmCtrlModel  
{
public:
	virtual void SetEnvironmentPara(double Cf, double Vf, double Tao, int Hk); //设置环境参数：风向，风速，温度，海况等级
	virtual void SetEnvironmentPara1(double RH, double Js, double Jr, double Va, double lamd); //设置环境参数：相对湿度（％）、降雪强度、降雨强度（mm/h）、大气能见度（km）、红外光谱波长：0.3---13.9
	virtual void SetCarrierType(int nType)             ; //设置导弹发射平台的类型
	virtual void SetShipInfo(ShipInfoStruct stuShip)   ; //设置舰艇的信息
	virtual void SetPlaneInfo(PlaneInfoStruct stuPlane); //设置飞机的信息
	virtual void SetMissileType(MISSILETYPE type)      ; //设置导弹的类型
	virtual void SetMissileInfo(double Vdd, double Rzd, double PhFyj, double Hp, double RangeGate1, double RangeGate2, double AngleGate); //设置导弹的信息
	virtual void GetMissileInfo(double& Vdd, double& Rzd, double& PhFyj, double& Hp, double& RangeGate1, double& RangeGate2, double& AngleGate); //获取导弹的信息
	virtual void SetPlanParam(MissileFundamentalInfo mis, RoutPlanPara par, FireControlConstraint con); //设置航路规划参数
	virtual void ReceiveTargetDesignationInfo(TargetIndicationInfo TargetIndication); //接收目标指示信息
	virtual bool MainSimulation(); //主模块
	virtual void SendLaunchInfo(LaunchAntishipInfo* LaunchInfo, int& nNum); //发布导弹发射信息	
	virtual void LaunchAGM65F(LaunchAGM65FInfo& LaunchInfo); //发布小牛导弹发射信息	

public:	
	CMissileArmCtrlModelUser();
	virtual ~CMissileArmCtrlModelUser();
private:
	string IDt  ;     //目标代号ID
	double Jt   ;     //目标经度（度）
	double Wt   ;     //目标纬度（度）
	float  Ht   ;     //目标高度（米）
	double Rmb  ;     //目标相对导弹发射平台的距离(m)
	double Bmb  ;     //目标方位（度）（0~360°）
	double Vm   ;     //目标航速（m/s）
	double Km   ;     //目标航向（度）（0~360°）
	double JD   ;     //目标机动系数
	
	int  m_nCarrierTyle;  //导弹发射平台的类型：0 舰载，1 机载
	
	string IDc  ;     //导弹发射平台的代号ID
	double Jc   ;     //导弹发射平台的经度（度）
	double Wc   ;     //导弹发射平台的纬度（度）
	double Hc   ;     //导弹发射平台的高度，米
	double Vc   ;     //导弹发射平台的航速（m/s）
	double Kc   ;     //导弹发射平台的航向（度）（0~360°）
	
	double Zyj  ;     //导弹发射平台的纵摇角（度），上为正（0~±15°）
	double Hyj  ;     //导弹发射平台的横摇角（度），右下斜为正（0~±30°）	
	double Gdmzj;     //导弹发射平台的发射架固定方位角(+-90度)，左舷-90度，右舷+90度
	double Gdfyj;     //导弹发射平台的发射架固定俯仰角(15°)，上+，下-
	double Overload;  //载机过载，g
	
    //-------武控参数--------
	MISSILETYPE m_missileType; //设置导弹类型
	double m_Vdd  ;          //导弹飞行速度（m/s）
	double m_Rzd  ;          //导弹自导雷达作用距离(米)
    double m_PhFyj;          //导弹巡航平飞时的平衡俯仰角(2.5度)
	double m_Hp   ;          //导弹平飞高度 米	
	double m_RangeGate1;     //距离波门下限 米	
	double m_RangeGate2;     //距离波门上限 米	
    double m_AngleGate ;     //角度波门 度
	
	double TzkMin;                   //反舰弹自导开机时间最小值100秒
	double m_AttackAngle;			 // 主攻击角
	double AttackClampAngle;         //攻击夹角，度
	double AttackAngle[RouteNumMax]; //攻击角，度
	
	short CalculateMode;	 //指挥仪解算方式：0 雷达攻击，1 坐标攻击，2 前置点攻击，3 纯方位攻击，4 人工装订 
	short PathType;          //航路规划类型：0=无规划；1=自动规划；2人工规划
	int   nNumOfMissile;     //用于打击该目标的导弹数量，最大值为：RouteNumMax
	WayPointPlaningOutput PathPar; //人工规划时，提供航路点信息

	//火控解算结果，将目标点也算作一个航路点，即0、1、2、。。。
	ShipFireControlBindingState           ShipFireCtrlState;    //舰载火控解算状态标识		
	PlaneFireControlBindingState          PlaneFireCtrlState;   //机载火控解算状态标识
	CFireCtrlOutput                       m_FireCtrlpar;        //目标指示信息和武控解算结果信息
	FireCtrlOutput                        FireCtrlCalOutput;    //不进行航路规划时的火控解算输出
	FireCtrlCalcuUnderAutoWayPointPlaning FireCtrlCalUnderAWPP; //自动航路规划下的火控解算输出
	FireCtrlCalcuUnderWayPointPlaning     FireCtrlCalUnderWPP;  //人工航路规划的火控解算输出
    LaunchAntishipInfo                    Linfo[RouteNumMax];   //导弹发射信息
public:
	//环境参数
	double m_Cf;  //风向，度
	double m_Vf;  //风速，米/秒
	double m_Tao; //温度，摄氏度
	int    m_Hk;  //海况，级
	
	double m_RH; //相对湿度（％）
	double m_Js; //降雪强度
	double m_Jr; //降雨强度（单位mm/h）
	double m_Va; //大气能见度
	double lamda; //红外光谱波长：0.3---13.9
	
	//发射限制条件
	ShipMissileLaunchLimit  ShipLaunchLimit;  //舰载发射限制条件
	PlaneMissileLaunchLimit PlaneLaunchLimit; //机载发射限制条件
	
	//航路规划限制条件	
	double SailMax ;                           //一条航路的最大航程，单位：Km
	double MaxTuringAngle;                     //导弹航路最大转弯角(度)
	double MinNeighborhoodWayPointDistance;    //相邻航路点最短距离(km)
	double MinFinalWayPointToTargetDistance;   //最后一个航路点与目标间的最小距离限制条件(km)
	double MinFirstWayPointToLauncherDistance; //第一个航路点与发射点间距要求(km)
	double MinTuringRadiusLimit;               //最小转弯半径，km	
private:
	bool AGM65FFireCtrl(double Hplane, double Vplane, double Rt); //导弹发射高度，单位：km；载机速度，单位：m/s；目标距离，米
	bool ShipFireCtrlCalcu(CFireCtrlOutput* pTarget);  //舰载火控解算
	bool PlaneFireCtrlCalcu(CFireCtrlOutput* pTarget); //机载火控解算
	bool IsShipSatisfyTheNeeds(
		double Rt,double Bt,
		double Kc,double GDMzj,
		double Zyj,double Hyj,
		double Vf,double Tao,int Hk,
		ShipMissileLaunchLimit LaunchLimit,
		ShipFireControlBindingState& FireCtrlState);  //舰载火控解算状态标识数据结构
	bool IsPlaneSatisfyTheNeeds(		
		double Rt,double Bt,
		double Vc,double Kc,double Hc,
		double Zeta,double Gama,
		double Overload,
		double Vf,double Tao,		
		PlaneMissileLaunchLimit LaunchLimit,
		PlaneFireControlBindingState& FireCtrlState); //机载火控解算状态标识数据结构
	bool FireCtrlCalcu(short PathType, int nCarrierStyle, int nShootingMode, 
		int nNumOfMissile, CFireCtrlOutput* pTarget); //火控解算模块	
    //不进行航路规划时的火控解算模块
	bool ShipFireCtrlCalcu(double Rmb,double Bmb,double Vm,double Km,double JD,
		double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,
		FireCtrlOutput& output);                            //舰载火控解算：其中，Wc 载舰纬度(度)，Vdd 导弹速度(m/s)
	bool ShipFireCtrlCalcuByB(double Bmb,
		double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,
		FireCtrlOutput& output);                            //舰载纯方位攻击火控解算	
	bool PlaneFireCtrlCalcu(double Rmb,double Bmb,double Vm,double Km,double JD,
		double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,
		double Vdd,
		FireCtrlOutput& output);                            //机载火控解算：其中，Wc 载机纬度(度)，Vdd 导弹速度(m/s)
	void CalcuPoseAngle(double Zyj,double Hyj,
		double Gdmzj,double Gdfyj,
		double& Qzmzj,double& Fyj,double& Qxj); //解算导弹姿态角
	//自动航路规划下的多条航路火控解算
	bool ShipFireCtrlCalcuUnderAutoWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,
		int nNum,double* AttackAngle,
		FireCtrlCalcuUnderAutoWayPointPlaning& output); //自动航路规划下的舰载多条航路火控解算
	bool ShipFireCtrlCalcuByBUnderAutoWayPointPlaning(
		double Bmb,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,
		int nNum,double* AttackAngle,
		FireCtrlCalcuUnderAutoWayPointPlaning& output); //自动航路规划下的舰载多条航路纯方位攻击火控解算		
	bool PlaneFireCtrlCalcuUnderAutoWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,
		double Vdd,
		int nNum,double* AttackAngle,
		FireCtrlCalcuUnderAutoWayPointPlaning& output); //自动航路规划下的机载多条航路火控解算
	//自动航路规划下的单条航路火控解算模块
	bool ShipFireCtrlCalcuUnderWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,double AttackAngle,
		FireCtrlCalcuUnderWayPointPlaning& output); //自动航路规划下的舰载单条航路火控解算
	bool ShipFireCtrlCalcuByBUnderWayPointPlaning(
		double Bmb,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,double AttackAngle,
		FireCtrlCalcuUnderWayPointPlaning& output); //自动航路规划下的舰载单条航路纯方位攻击火控解算
	bool PlaneFireCtrlCalcuUnderWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,
		double Vdd,double AttackAngle,
		FireCtrlCalcuUnderWayPointPlaning& output); //自动航路规划下的机载单条航路火控解算
	//人工航路规划下的火控解算
	bool ShipFireCtrlCalcuUnderWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,int nWayPoint,double* Jm,double* Wm,
		FireCtrlCalcuUnderWayPointPlaning& output); //人工航路规划下的舰载火控解算	
	bool PlaneFireCtrlCalcuUnderWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,
		double Vdd,int nWayPoint,double* Jm,double* Wm,
		FireCtrlCalcuUnderWayPointPlaning& output); //人工航路规划下的机载火控解算
	//航路规划模块
	bool AutoWayPointPlaning(double Jc,double Wc,
		double Jt,double Wt,
		int nNum,double* AttackAngle,
		AutoWayPointPlaningOutput& output);                //多条航路自动航路规划模块，不带火控功能
	bool AutoWayPointPlaning(double Jc,double Wc,
		double Jt,double Wt,
		double AttackAngle,
		WayPointPlaningOutput& output);                    //单条航路自动航路规划模块，不带火控功能
	bool ManualWayPointPlaning(double Jc,double Wc,
		double Jt,double Wt,
		int nWayPoint,double* Jm,double* Wm,
		WayPointPlaningOutput& output);                    //人工装订航路规划模块，不带火控功能
public:	
	double interp1(int n, double x, double* X0, double* F); //不等距单变元线性插值，X0[n]、F[n]
	double f180(double Angle);/*单位为度*/
	double f360(double Angle);/*单位为度*/
	int    Sign(double n);
	double ToAngle(double F0, double Ft); //解算方位线Ft相对于FO的舷角，单位(度),-180--+180度
	double Clamp(double F0, double Ft);   //解算FO、Ft之间的夹角，单位(度)，0--+180度
	double GetCurvatureRadiusOfLatitude(double Fai /*单位为度*/); //获得当前点纬度圈的曲率半径
	double GetCurvatureRadiusOfLongitude(double Fai /*单位为度*/);//获得当前点经度圈的曲率半径
	void   GetDetJWFromBD(double J0,double W0,double B,double D,double& DetJ,double& DetW); //已知方位(度)和距离(米)，解算经度差和纬度差，单位：度
	void   GetBDFromDetJW(double J0,double W0,double Jt,double Wt,double& B,double& D);//已知两点的经度和纬度，解算方位和距离，单位：度、米
//	void PutInSort(LaunchAntishipInfo* LaunchInfo, int nNum);
	string strError; //错误信息字符串
public:
	virtual void GetErrorStr(char str[])
	{
		strcpy(str, strError.c_str());
	};	
};

#endif //MISSILEARMCTRLMODE__USERMODEL_H_
