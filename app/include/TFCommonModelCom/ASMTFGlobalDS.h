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
// �����������Ͷ���
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
#define TBM_U					51	// ս������������ͨ���ͣ���С����������
#define AGNI_3				55	// �һ�3
#define AGNI_4				56	// �һ�4

#define DemoASM			60

#define SkySword_IIA		65
#define HsiuingFeng_2		66
#define HsiuingFeng_3		67

// �Կյ������Ͷ���
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

//�����ͺŶ���
#define Yu_3				0
#define Yu_6 				1
#define Yu_7				2
#define Yu_9 				3
#define Yu_Japan			4
#define Yu_TaiWan		5
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// ��������
#define TARGET_NUM_MAX 150 
#define ROUTE_NUM_MAX 10
const int MaxNumOfMissile = 50; //���ص���������
const double u = 340;		// ����340m/s
const int GroupShip_Num_Max=20; // ����н�ͧ���������

//WGS-84���������
const double a=6378137.0;//������
const double flattening=1/298.257223563;//����
const double delta=0.0000001;
const double fPI=3.1415927;

// ���ݽṹ����
struct statisticInfo
{
	DtEntityType entType;//����
	int selfNo;//������
	char	 selfName[32];//��������
	int launchPlatNo;//����ƽ̨���
	char launchPlatName[32];//����ƽ̨����//g
	int targetNo;//Ŀ����
	char targetName[32];//Ŀ������//g
	int hitTarNo;//�����е�Ŀ����
	char hitTarName[32];//�����е�Ŀ������//g
	int interceptNo;//���ص����ĵ������
	char interceptName[32];//���ص����ĵ�������//g
	double selfLat;//����γ��
	double selfLon;//������
	double selfHeight;//����߶�
	double attackAngle;//���������Ĺ���
	double dist2Tar;//��Ŀ���ˮƽ����
	int	isHitTar;// �Ƿ�����Ŀ��
	int isIntcpted; // �Ƿ�����
	int isJammed; // �Ƿ񱻸���
	int JammedType;// ����������

	statisticInfo()
	{
		selfNo=0;//������
		launchPlatNo=0;//����ƽ̨���
		targetNo=0;//Ŀ����
		hitTarNo=0;//�����е�Ŀ����
		interceptNo=0;//���ص����ĵ������
		selfLat=0;//����γ��
		selfLon=0;//������
		selfHeight=0;//����߶�
		attackAngle=0;//���������Ĺ���
		dist2Tar=0;//��Ŀ���ˮƽ����
		isHitTar=0;// �Ƿ�����Ŀ��
		isIntcpted=0; // �Ƿ�����
		isJammed=0; // �Ƿ񱻸���
		JammedType=0;// ����������
	}
	statisticInfo& operator=(statisticInfo val)
	{
		entType=val.entType;//����
		selfNo=val.selfNo;//������
		strcpy(selfName,val.selfName);//��������
		launchPlatNo=val.launchPlatNo;//����ƽ̨���
		strcpy(launchPlatName,val.launchPlatName);//����ƽ̨����//g
		targetNo=val.targetNo;//Ŀ����
		strcpy(targetName,val.targetName);//Ŀ������//g
		hitTarNo=val.hitTarNo;//�����е�Ŀ����
		strcpy(hitTarName,val.hitTarName);//�����е�Ŀ������//g
		interceptNo=val.interceptNo;//���ص����ĵ������
		strcpy(interceptName,val.interceptName);//���ص����ĵ�������//g
		selfLat=val.selfLat;//����γ��
		selfLon=val.selfLon;//������
		selfHeight=val.selfHeight;//����߶�
		attackAngle=val.attackAngle;//���������Ĺ���
		dist2Tar=val.dist2Tar;//��Ŀ���ˮƽ����
		isHitTar=val.isHitTar;//������
		isIntcpted=val.isIntcpted;//����߶�
		isJammed=val.isJammed;//���������Ĺ���
		JammedType=val.JammedType;//��Ŀ���ˮƽ����

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
	long vehicleNo;//���䳵���
	double launchTime;//��һö�����ķ���ʱ��
	long remainASMCount;//��ʣ��ö������Ҫ����
	BOOL bLaunch;//�Ƿ�������䵼����1�ǣ�2��
	long targetNo;//����Ŀ����
	char targetName[32];//����Ŀ������
	long wayPtNum;//��·�����
	DtWayPoint WayPts[MAX_RP_NUM];//��·��
	int searchStrg;//�Ѳ�����
	double searchChart[14];//����ͼ
	double atkAngle;//����

	double m_totalDist;		// ��·�ܳ���km
	double m_totalFlyTime;		// �ܷ���ʱ��
	int m_ASMType;	// ����ķ�����������
	int m_ASMTrajType;	// ���������������ͣ�ָYJ12�ĵ�����1-�͡�2-�ߵ͡�3-�ߣ�
	char m_uuid[MAX_CHARLEN];// ����Ψһ��ʶ
};


struct surfData
{
	int surfNo;//��ͧ���
	GeoPt surfPos;//��ͧλ��
	double d_surf2ASM;//��ͧ����ĳö���������ľ���
	int count_intcpt1ASM;//�ý�ͧ�ѷ�������ظ�ö���������ķ��յ�������
	int setCount_intcpt1ASM;//�趨�ĸý�ͧ����ܷ��伸ö���յ�ȥ����һö��������
	// 20160308 ��������ڸý�ͧ�ķ�λ��Ϣ
	double Az; // ������λ��(��������0-360deg)
	double El;	// �����ߵͽ�
	double Az_cou; // ��λ�ǣ�����ں��򣨽������򣩶��ԣ���Ϊ������Ϊ����-180~+180deg��

	void clear()
	{
		surfNo=0;//��ͧ���
		surfPos.x=0;//��ͧλ��
		surfPos.y=0;//��ͧλ��
		surfPos.z=0;//��ͧλ��
		d_surf2ASM=0;//��ͧ����ĳö���������ľ���
		count_intcpt1ASM=0;;//�ý�ͧ�ѷ�������ظ�ö���������ķ��յ�������
		setCount_intcpt1ASM=0;//�趨�ĸý�ͧ����ܷ��伸ö���յ�ȥ����һö��������
		Az = 0.;
		El = 0.;
		Az_cou = 0.;
	}

};

struct AAMData
{
	long AAMNo;//���յ���������
	long launchPltNo;//����ƽ̨���
};

struct ASMData
{
	int ASMNo;//�����������
	int hitNo;//�������Ľ�ͧ���
	double minArriveTime;//�������ͧ�ĵ���ʱ��
	int interceptCount;//���ظ÷������ķ��յ���Ŀ
	surfData surf2ASM[10];//��Ҫ���ڼ�¼ÿö�������������ͧ��Զ����ϵ
	int surf2ASMCount;//��¼��ͧ����
	GeoPt ASMPos;//�÷���������λ��
	double ASMVel;//�÷����������ٶ�
	AAMData AAMInfo[5];//��¼���ظ÷��������ķ��յ�����Ϣ
	// 20160308
	char ASMName[32]; // ������������ 
	double Cou; // ������������
	double pitch; // ���������ĸ�����
	// 20160920
	double AsmExId;
	// 20161007
	bool isMeeting;// �Ƿ������뽢�յ������㣬��Ҫ�ȴ����سɹ�����ȷ�Ͻ��
	// 20171025
	int tarIntcptedRecIdx; // ������Ŀ�걻������������е�λ����ţ��Ա��ڼ���


	void clear()
	{
		ASMNo=0;//�����������
		hitNo=0;//�������Ľ�ͧ���
		minArriveTime=0;//�������ͧ�ĵ���ʱ��
		interceptCount=0;//���ظ÷������ķ��յ���Ŀ
		for(int j=0;j<10;j++)
		{
			surf2ASM[j].clear();
		}

		surf2ASMCount=0;//��¼��ͧ����
		ASMPos.x=0;//�÷���������λ��
		ASMPos.y=0;
		ASMPos.z=0;
		ASMVel=0;//�÷����������ٶ�
		for(int k=0;k<5;k++)
		{
			AAMInfo[k].AAMNo=0;//���յ���������
			AAMInfo[k].launchPltNo=0;//����ƽ̨���
		}

		memset(ASMName, 0, 32);

		Cou = 0.;
		pitch = 0.;
		AsmExId=0;
		isMeeting= false;
		tarIntcptedRecIdx = -1;
	}
};

// ���յ��� ��Ŀ�����¼
struct meetRecStr
{
	long aamNo;
	long motherShipNo; // ���յ�������ƽ̨���
	long tarNo;
	long useCount; // �����жϵĴ���
	double meetTime; // ����ʱ�̣���useCount����Ϊ0������£������жϳ���һ�����Զ�����������

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
// Ŀ�걻���������¼���ݽṹ
struct TarIntcptedRec 
{
	int tarNo; // Ŀ���
	int interceptAAMCount; // ��ǰ���ظ�Ŀ��ķ��յ�����
	int attackState; //����״̬��0-���䡢1-�۲�
	TarIntcptedRec()
	{
		tarNo = 0;
		interceptAAMCount = 0;
		attackState = 0;
	}
};

struct AAMLauncherRec
{
	int AAMLauncherNo;//��������
	int launchedAAMCount;//�÷�������ѷ���ĵ�������һ��װ������£�
	double launchTime;//ǰһö�����ķ���ʱ��

	AAMLauncherRec()
	{
		AAMLauncherNo = 0;
		launchedAAMCount = 0;
		launchTime = 0;
	}
};

struct trackData
{
	long	m_TargetNo/*Ŀ����*/;
	char	m_TargetName[32]/*Ŀ������*/; //����20151027
	long	m_TargetAttributeType/*�������ͣ�0��ͧ��1���յ�����2������ء�3�ɻ���4����������5������6ָ������7���ǡ�����11ѹ�Ƹ��ţ�*/;
	DtEntityType m_TargetType; // Ŀ��������ͣ�20160627
	double	m_TargetDistance/*Ŀ�����m*/;
	GeoPt	m_TargetPosition/*Ŀ��λ��*/;
	CAzimuth3D	m_TargetAzimuth/*Ŀ�귽λ��������Ϊԭ�㣩*/;
	double	m_TargetVelocity/*Ŀ�꺽��m/s*/;
	double	m_TargetCourse/*Ŀ�꺽��*/;
	double m_TargetPitch/*Ŀ�꺽�����*/;
	long	m_TargetExId; //��չId
	double	m_lastTime;
	double	m_curTime;
	long	m_contDetectedCount;// ������̽�⵽�Ĵ���
	double	m_contDetectedTime; // ������̽�⵽���ۻ�ʱ��
	bool	m_isTracked;// �Ƿ����ڱ�����
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
		m_TargetNo = val.m_TargetNo/*Ŀ����*/;
		strcpy(m_TargetName , val.m_TargetName) /*Ŀ������*/; //����20151027
		m_TargetAttributeType = val.m_TargetAttributeType/*�������ͣ�0��ͧ��1���յ�����2������ء�3�ɻ���4����������5������6ָ������7���ǡ�����11ѹ�Ƹ��ţ�*/;
		m_TargetType= val.m_TargetType; // Ŀ��������ͣ�20160627
		m_TargetDistance= val.m_TargetDistance/*Ŀ�����km*/;
		m_TargetPosition= val.m_TargetPosition/*Ŀ��λ��*/;
		m_TargetAzimuth= val.m_TargetAzimuth/*Ŀ�귽λ��������Ϊԭ�㣩*/;
		m_TargetVelocity= val.m_TargetVelocity/*Ŀ�꺽��m/s*/;
		m_TargetCourse= val.m_TargetCourse/*Ŀ�꺽��*/;
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

	// ֻ��������̽��ʱ�䡢�������Ƿ񱻸��ٵ��������������
	trackData& copyParts(trackData val)
	{
		m_TargetNo = val.m_TargetNo/*Ŀ����*/;
		strcpy(m_TargetName , val.m_TargetName) /*Ŀ������*/; //����20151027
		m_TargetAttributeType = val.m_TargetAttributeType/*�������ͣ�0��ͧ��1���յ�����2������ء�3�ɻ���4����������5������6ָ������7���ǡ�����11ѹ�Ƹ��ţ�*/;
		m_TargetType= val.m_TargetType; // Ŀ��������ͣ�20160627
		m_TargetDistance= val.m_TargetDistance/*Ŀ�����km*/;
		m_TargetPosition= val.m_TargetPosition/*Ŀ��λ��*/;
		m_TargetAzimuth= val.m_TargetAzimuth/*Ŀ�귽λ��������Ϊԭ�㣩*/;
		m_TargetVelocity= val.m_TargetVelocity/*Ŀ�꺽��m/s*/;
		m_TargetCourse= val.m_TargetCourse/*Ŀ�꺽��*/;
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

// ���յ�����ʼ��������ṹ��
struct  SAMInitLaunchParam
{
	double InitPitch;				// ��ʼ�������ǣ��Ǵ�ֱ����ĵ���Ӧ������׼Ŀ�귢��ģ�����Ҫ�޸�
	double InitSegTime;		// ������ʼ��ʱ��
	double InitSegHeight;		// ��ʼ�θ߶�
	double StartGuideTime;	// 2.0s����ܽ����Ƶ�ָ��
	bool IsEnterCruiseSeg;	// �Ƿ���Ҫ����Ѳ����
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
	int	m_IrradiatorNo/*����ͨ�����*/;
	int	m_AAMNo/*����Ӧ�ķ��յ����*/;
	int	m_AAMType/*���յ����ͣ������ж�����������������*/;
	int	m_TarNo/*Ŀ����*/;
	int moveStep/*��Ӧ���յ������˶��׶�, 0�����Ρ�1���Ƶ��Ρ�2ĩ�Ƶ��Ρ�3����Ѱ�Ķ�*/;
	double m_createTime;/*����ʱ��*/

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

// ÿ��Ŀ������������¼���ݽṹ
struct tarIntcptSr 
{
	int tarNo;
	int intcptAAMCount; // ���м�ö�����ظ�Ŀ��
	bool isIntcpted; // �Ƿ����ڱ�����
	tarIntcptSr()
	{
		tarNo = 0;
		intcptAAMCount=0;
		isIntcpted = 0;
	}
};

#endif
