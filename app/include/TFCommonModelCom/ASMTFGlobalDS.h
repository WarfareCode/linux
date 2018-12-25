//AAMSeekerModel.h: interface for the CAAMSeekerModel module.
//!!HDOSE_CLASS(CAAMSeekerModel,CRadarSensorModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMTFGloabalDS_H)
#define AFX_ASMTFGloabalDS_H

#ifdef _WIN32
#define DATASTRUCTCOMPONENTDLL_API __declspec(dllimport)
#endif

#define DATASTRUCTCOMPONENTDLL_API
#include "Azimuth3D.h"

//////////////////////////////////////////////////////////////////////////
// 反舰导弹类型定义
#define YJ_83		0
#define YJ_83G		1
#define YJ_62		2
#define YJ_62G		3
#define YJ_62A		4
#define YJ_62AG	5
#define YJ_62H		6
#define YJ_82		7
#define YJ_83J		8
#define YJ_83JG	9
#define YJ_83K		10
#define YJ_83KG	11
#define YJ_12		12
#define YJ_18		13
#define YJ_88		14
#define YJ_91		15
#define Club			16
#define Muskete	17
#define MusketeG			18
#define YJ_9						19
#define YJ62A_ML8C		20
#define YJ83K_ML_8			21

#define SS_N_26				27
#define APW					28

#define AGM_84A			30
#define AGM_84D			31
#define AGM_88A			32
#define AGM_88D			33
#define BGM_109G			34
#define RGM_109B			35
#define RGM_109E			36
#define UGM_109B			37
#define UGM_109E			38
#define AGM_158C			39

#define TBASM_4b			50
#define TBM_U					51	// 战术弹道导弹，通用型（最小能量弹道）
#define AGNI_3				55	// 烈火3
#define AGNI_4				56	// 烈火4

#define DemoASM			60

#define SkySword_IIA		65
#define HsiuingFeng_2		66
#define HsiuingFeng_3		67

// 对空导弹类型定义
#define HQ_16			0
#define HHQ_7			1
#define HHQ_9			2
#define Shtil				3
#define Shtil_1			4
#define Riff				5
#define PL_12			6
#define SM_1			7
#define SM_2			8
#define SM_3			9
#define AIM_120		10
#define AAM_4			11
#define JapanA2A_2			12
#define TaiWanA2A_1		13
#define TaiWanA2A_2		14
#define Hawk			15
#define ESSM			16
#define SSM				17
#define SRAM			18
#define SM_6MR_Blk_I			19
#define HQ_10			25

#define SA_3a			41
#define SA_3b			42
#define SA_3c			43
#define SA_4a			44
#define SA_4b			45
#define SA_5b			46
#define SA_5c			47
#define SA_6a			48
#define SA_6b			49
#define SA_8a			50
#define SA_20a		51
#define SA_21a		52
#define SA_21b		53
#define SA_22			54
#define SA_23			55
#define SA_24			56
#define SA_25			57

//鱼雷型号定义
#define Yu_3				0
#define Yu_6 				1
#define Yu_7				2
#define Yu_9 				3
#define Yu_Japan			4
#define Yu_TaiWan		5
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 常量定义
#define TARGET_NUM_MAX 150 
#define ROUTE_NUM_MAX 10
const int MaxNumOfMissile = 50; //舰载导弹最多个数
const double u = 340;		// 音速340m/s
const int GroupShip_Num_Max=20; // 编队中舰艇的最大数量

//WGS-84椭球体参数
const double a=6378137.0;//长半轴
const double flattening=1/298.257223563;//扁率
const double delta=0.0000001;
const double fPI=3.1415927;

// 数据结构定义
struct statisticInfo
{
	DtEntityType entType;//类型
	int selfNo;//自身编号
	char	 selfName[32];//自身名称
	int launchPlatNo;//发射平台编号
	char launchPlatName[32];//发射平台名称//g
	int targetNo;//目标编号
	char targetName[32];//目标名称//g
	int hitTarNo;//它击中的目标编号
	char hitTarName[32];//它击中的目标名称//g
	int interceptNo;//拦截到它的导弹编号
	char interceptName[32];//拦截到它的导弹名称//g
	double selfLat;//自身纬度
	double selfLon;//自身经度
	double selfHeight;//自身高度
	double attackAngle;//反舰导弹的攻角
	double dist2Tar;//与目标的水平距离
	int	isHitTar;// 是否命中目标
	int isIntcpted; // 是否被拦截
	int isJammed; // 是否被干扰
	int JammedType;// 被干扰类型

	statisticInfo()
	{
		selfNo=0;//自身编号
		launchPlatNo=0;//发射平台编号
		targetNo=0;//目标编号
		hitTarNo=0;//它击中的目标编号
		interceptNo=0;//拦截到它的导弹编号
		selfLat=0;//自身纬度
		selfLon=0;//自身经度
		selfHeight=0;//自身高度
		attackAngle=0;//反舰导弹的攻角
		dist2Tar=0;//与目标的水平距离
		isHitTar=0;// 是否命中目标
		isIntcpted=0; // 是否被拦截
		isJammed=0; // 是否被干扰
		JammedType=0;// 被干扰类型
	}
	statisticInfo& operator=(statisticInfo val)
	{
		entType=val.entType;//类型
		selfNo=val.selfNo;//自身编号
		strcpy(selfName,val.selfName);//自身名称
		launchPlatNo=val.launchPlatNo;//发射平台编号
		strcpy(launchPlatName,val.launchPlatName);//发射平台名称//g
		targetNo=val.targetNo;//目标编号
		strcpy(targetName,val.targetName);//目标名称//g
		hitTarNo=val.hitTarNo;//它击中的目标编号
		strcpy(hitTarName,val.hitTarName);//它击中的目标名称//g
		interceptNo=val.interceptNo;//拦截到它的导弹编号
		strcpy(interceptName,val.interceptName);//拦截到它的导弹名称//g
		selfLat=val.selfLat;//自身纬度
		selfLon=val.selfLon;//自身经度
		selfHeight=val.selfHeight;//自身高度
		attackAngle=val.attackAngle;//反舰导弹的攻角
		dist2Tar=val.dist2Tar;//与目标的水平距离
		isHitTar=val.isHitTar;//自身经度
		isIntcpted=val.isIntcpted;//自身高度
		isJammed=val.isJammed;//反舰导弹的攻角
		JammedType=val.JammedType;//与目标的水平距离

		return *this;
	}
};

struct routInfo
{
	int tarNo;
	int fieldNo;
	double time;
	double attackAngle;
};


// static bool bwrite_1=true;
// static bool bwrite_2=true;

struct LaunchVehicleStateRec
{
	long vehicleNo;//发射车编号
	double launchTime;//上一枚导弹的发射时间
	long remainASMCount;//还剩几枚导弹需要发射
	BOOL bLaunch;//是否断续发射导弹，1是，2否
	long targetNo;//攻击目标编号
	char targetName[32];//攻击目标名称
	long wayPtNum;//航路点个数
	DtWayPoint WayPts[MAX_RP_NUM];//航路点
	int searchStrg;//搜捕策略
	double searchChart[14];//搜索图
	double atkAngle;//攻角

	double m_totalDist;		// 航路总长度km
	double m_totalFlyTime;		// 总飞行时间
	int m_ASMType;	// 发射的反舰导弹类型
	int m_ASMTrajType;	// 反舰导弹弹道类型（指YJ12的弹道，1-低、2-高低、3-高）
	char m_uuid[MAX_CHARLEN];// 导弹唯一标识
};


struct surfData
{
	int surfNo;//舰艇编号
	GeoPt surfPos;//舰艇位置
	double d_surf2ASM;//舰艇距离某枚反舰导弹的距离
	int count_intcpt1ASM;//该舰艇已发射的拦截该枚反舰导弹的防空导弹数量
	int setCount_intcpt1ASM;//设定的该舰艇最多能发射几枚防空弹去拦截一枚反舰导弹
	// 20160308 导弹相对于该舰艇的方位信息
	double Az; // 导弹方位角(正北方向，0-360deg)
	double El;	// 导弹高低角
	double Az_cou; // 方位角（相对于航向（舰艏方向）而言，左为负、右为正，-180~+180deg）

	void clear()
	{
		surfNo=0;//舰艇编号
		surfPos.x=0;//舰艇位置
		surfPos.y=0;//舰艇位置
		surfPos.z=0;//舰艇位置
		d_surf2ASM=0;//舰艇距离某枚反舰导弹的距离
		count_intcpt1ASM=0;;//该舰艇已发射的拦截该枚反舰导弹的防空导弹数量
		setCount_intcpt1ASM=0;//设定的该舰艇最多能发射几枚防空弹去拦截一枚反舰导弹
		Az = 0.;
		El = 0.;
		Az_cou = 0.;
	}

};

struct AAMData
{
	long AAMNo;//防空导弹自身编号
	long launchPltNo;//发射平台编号
};

struct ASMData
{
	int ASMNo;//反舰导弹编号
	int hitNo;//所攻击的舰艇编号
	double minArriveTime;//距最近舰艇的到达时间
	int interceptCount;//拦截该反舰弹的防空弹数目
	surfData surf2ASM[10];//主要用于记录每枚反舰弹与各个舰艇的远近关系
	int surf2ASMCount;//记录舰艇数量
	GeoPt ASMPos;//该反舰导弹的位置
	double ASMVel;//该反舰导弹的速度
	AAMData AAMInfo[5];//记录拦截该反舰导弹的防空导弹信息
	// 20160308
	char ASMName[32]; // 反舰导弹名称 
	double Cou; // 反舰导弹航向
	double pitch; // 反舰导弹的俯仰角
	// 20160920
	double AsmExId;
	// 20161007
	bool isMeeting;// 是否正在与舰空导弹交汇，需要等待拦截成功与否的确认结果
	// 20171025
	int tarIntcptedRecIdx; // 记下在目标被拦截情况数组中的位置序号，以便于检索


	void clear()
	{
		ASMNo=0;//反舰导弹编号
		hitNo=0;//所攻击的舰艇编号
		minArriveTime=0;//距最近舰艇的到达时间
		interceptCount=0;//拦截该反舰弹的防空弹数目
		for(int j=0;j<10;j++)
		{
			surf2ASM[j].clear();
		}

		surf2ASMCount=0;//记录舰艇数量
		ASMPos.x=0;//该反舰导弹的位置
		ASMPos.y=0;
		ASMPos.z=0;
		ASMVel=0;//该反舰导弹的速度
		for(int k=0;k<5;k++)
		{
			AAMInfo[k].AAMNo=0;//防空导弹自身编号
			AAMInfo[k].launchPltNo=0;//发射平台编号
		}

		memset(ASMName, 0, 32);

		Cou = 0.;
		pitch = 0.;
		AsmExId=0;
		isMeeting= false;
		tarIntcptedRecIdx = -1;
	}
};

// 防空导弹 弹目交汇记录
struct meetRecStr
{
	long aamNo;
	long motherShipNo; // 防空导弹发射平台编号
	long tarNo;
	long useCount; // 用于判断的次数
	double meetTime; // 交汇时刻，在useCount可能为0的情况下，用于判断超过一定后，自动将数据清零

	meetRecStr()
	{
		aamNo = 0;
		motherShipNo = 0;
		tarNo = 0;
		useCount = 0;
		meetTime = 0.0;
	}
};

// *************20171025 **************
// 目标被拦截情况记录数据结构
struct TarIntcptedRec 
{
	int tarNo; // 目标号
	int interceptAAMCount; // 当前拦截该目标的防空弹数量
	int attackState; //攻击状态，0-发射、1-观察
	TarIntcptedRec()
	{
		tarNo = 0;
		interceptAAMCount = 0;
		attackState = 0;
	}
};

struct AAMLauncherRec
{
	int AAMLauncherNo;//发射架序号
	int launchedAAMCount;//该发射架上已发射的导弹数（一次装填情况下）
	double launchTime;//前一枚导弹的发射时间

	AAMLauncherRec()
	{
		AAMLauncherNo = 0;
		launchedAAMCount = 0;
		launchTime = 0;
	}
};

struct trackData
{
	long	m_TargetNo/*目标编号*/;
	char	m_TargetName[32]/*目标名称*/; //新增20151027
	long	m_TargetAttributeType/*属性类型（0舰艇、1防空导弹、2岸导阵地、3飞机、4反舰导弹、5箔条、6指挥所、7卫星、…、11压制干扰）*/;
	DtEntityType m_TargetType; // 目标对象类型，20160627
	double	m_TargetDistance/*目标距离m*/;
	GeoPt	m_TargetPosition/*目标位置*/;
	CAzimuth3D	m_TargetAzimuth/*目标方位（以自身为原点）*/;
	double	m_TargetVelocity/*目标航速m/s*/;
	double	m_TargetCourse/*目标航向*/;
	double m_TargetPitch/*目标航迹倾角*/;
	long	m_TargetExId; //扩展Id
	double	m_lastTime;
	double	m_curTime;
	long	m_contDetectedCount;// 连续被探测到的次数
	double	m_contDetectedTime; // 连续被探测到的累积时间
	bool	m_isTracked;// 是否正在被跟踪
	int m_Side;

	trackData()
	{
		m_TargetNo = 0;
		memset(m_TargetName,0,32);
		m_TargetAttributeType=0;
		m_TargetDistance=0;
		m_TargetVelocity=0;
		m_TargetCourse=0;
		m_TargetPitch = 0;
		m_TargetExId=0;
		m_lastTime = 0;
		m_curTime = 0;
		m_contDetectedCount = 0;
		m_contDetectedTime = 0;
		m_isTracked = false;
		m_Side = 0;
	}

	trackData& operator=(trackData val)
	{
		m_TargetNo = val.m_TargetNo/*目标编号*/;
		strcpy(m_TargetName , val.m_TargetName) /*目标名称*/; //新增20151027
		m_TargetAttributeType = val.m_TargetAttributeType/*属性类型（0舰艇、1防空导弹、2岸导阵地、3飞机、4反舰导弹、5箔条、6指挥所、7卫星、…、11压制干扰）*/;
		m_TargetType= val.m_TargetType; // 目标对象类型，20160627
		m_TargetDistance= val.m_TargetDistance/*目标距离km*/;
		m_TargetPosition= val.m_TargetPosition/*目标位置*/;
		m_TargetAzimuth= val.m_TargetAzimuth/*目标方位（以自身为原点）*/;
		m_TargetVelocity= val.m_TargetVelocity/*目标航速m/s*/;
		m_TargetCourse= val.m_TargetCourse/*目标航向*/;
		m_TargetPitch = val.m_TargetPitch;
		m_TargetExId = val.m_TargetExId;
		m_lastTime= val.m_lastTime;
		m_curTime= val.m_curTime; 
		m_contDetectedCount= val.m_contDetectedCount;
		m_contDetectedTime= val.m_contDetectedTime;
		m_isTracked = val.m_isTracked;
		m_Side = val.m_Side;

		return *this;
	}

	// 只拷贝除了探测时间、次数、是否被跟踪等以外的其它数据
	trackData& copyParts(trackData val)
	{
		m_TargetNo = val.m_TargetNo/*目标编号*/;
		strcpy(m_TargetName , val.m_TargetName) /*目标名称*/; //新增20151027
		m_TargetAttributeType = val.m_TargetAttributeType/*属性类型（0舰艇、1防空导弹、2岸导阵地、3飞机、4反舰导弹、5箔条、6指挥所、7卫星、…、11压制干扰）*/;
		m_TargetType= val.m_TargetType; // 目标对象类型，20160627
		m_TargetDistance= val.m_TargetDistance/*目标距离km*/;
		m_TargetPosition= val.m_TargetPosition/*目标位置*/;
		m_TargetAzimuth= val.m_TargetAzimuth/*目标方位（以自身为原点）*/;
		m_TargetVelocity= val.m_TargetVelocity/*目标航速m/s*/;
		m_TargetCourse= val.m_TargetCourse/*目标航向*/;
		m_TargetExId = val.m_TargetExId;
// 		m_lastTime= val.m_lastTime;
// 		m_curTime= val.m_curTime; 
// 		m_contDetectedCount= val.m_contDetectedCount;
// 		m_contDetectedTime= val.m_contDetectedTime;
//		m_isTracked = val.m_isTracked;
		m_Side = val.m_Side;

		return *this;
	}

};

// 舰空导弹初始发射参数结构体
struct  SAMInitLaunchParam
{
	double InitPitch;				// 初始发射仰角，非垂直发射的导弹应该是瞄准目标发射的，后续要修改
	double InitSegTime;		// 弹道初始段时间
	double InitSegHeight;		// 初始段高度
	double StartGuideTime;	// 2.0s后才能接收制导指令
	bool IsEnterCruiseSeg;	// 是否需要进入巡航段
	SAMInitLaunchParam()
	{
		InitPitch = 0;
		InitSegTime = 0;	
		InitSegHeight = 0;
		StartGuideTime = 0;
		IsEnterCruiseSeg = false;
	}
	void SetValue(double InitPitch1, double InitSegTime1, double InitSegHeight1, double StartGuideTime1, bool IsEnterCruiseSeg1)
	{
		InitPitch = InitPitch1;
		InitSegTime = InitSegTime1;	
		InitSegHeight = InitSegHeight1;
		StartGuideTime = StartGuideTime1;
		IsEnterCruiseSeg = IsEnterCruiseSeg1;
	}
};

struct myirradiatorRec
{
	int	m_IrradiatorNo/*火力通道编号*/;
	int	m_AAMNo/*所对应的防空弹编号*/;
	int	m_AAMType/*防空弹类型（用于判断是主动、半主动）*/;
	int	m_TarNo/*目标编号*/;
	int moveStep/*对应防空导弹的运动阶段, 0主动段、1中制导段、2末制导段、3主动寻的段*/;
	double m_createTime;/*创建时间*/

	myirradiatorRec()
	{
		m_IrradiatorNo=0;
		m_AAMNo=0;
		m_AAMType=0;
		m_TarNo=0;
		moveStep=-1;
		m_createTime = 0.0;
	}
};

struct IrradiatorResStr 
{
	int irrNo;
	bool isRec;
	double AAMMissTime;

	IrradiatorResStr()
	{
		irrNo=0;
		isRec=false;
		AAMMissTime=0.0;
	}
};

// 每个目标的拦截情况记录数据结构
struct tarIntcptSr 
{
	int tarNo;
	int intcptAAMCount; // 还有几枚在拦截该目标
	bool isIntcpted; // 是否正在被拦截
	tarIntcptSr()
	{
		tarNo = 0;
		intcptAAMCount=0;
		isIntcpted = 0;
	}
};

#endif
