// MissileArmCtrlModel.h: interface for the CMissileArmCtrlModelUser class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MISSILEARMCTRLMODE__USERMODEL_H_
#define MISSILEARMCTRLMODE__USERMODEL_H_

#define PI  3.1415926
#define DtR 0.017453292
#define RtD 57.29578049
#define MatM 340.0

#define CDBJ   6378245          //����ο����������뾶
#define JBJ    6356863          //����ο������弫�뾶
#define DXBJ   637000           //�����Ч�뾶
#define BL     0.00335233281    //����ο����������
#define PXLPF1 0.00669342749    //��������������Ȧ��һƫ����ƽ��(a^2+b^2)/a^2
#define PXLPF2 0.00673853541    //��������������Ȧ�ڶ�ƫ����ƽ��(a^2+b^2)/b^2
#define Wzz    0.004178         //��ֵ ������ת���ٶ�(��/��)

struct FireCtrlOutput //�޺�·�滮�µĻ�ؽ������
{
	double Tzk;        //�Կط���ʱ�䣨s��
	double ZdQzhxj;    //װ��ǰ�ú���ǣ���λ���ȣ�����ʱ��Ϊ��
	double ZdFyj  ;    //װ�������ǣ��ȣ�
	double ZdQxj  ;    //װ����б�ǣ��ȣ�
};

struct AutoWayPointPlaningOutput //���Զ���·�滮���
{
	int    HlNum;	                     //�ܿ��к�·��
	int    Pm[RouteNumMax];	             //������·�ĺ�·����
	double Sm[RouteNumMax];              //������·�ĺ��̣���λ��Km
	double Jm[RouteNumMax][WayPointMax]; //������·�ĺ�·������(���ȣ���λ����)
	double Wm[RouteNumMax][WayPointMax]; //������·�ĺ�·������(γ�ȣ���λ����)
	double Rm[RouteNumMax][WayPointMax]; //������·����·�㴦��ת��뾶����λ��Km
	double Am[RouteNumMax][WayPointMax]; //������·����·�㴦��ת��ǣ���λ����
	
	AutoWayPointPlaningOutput()
	{
		HlNum = 0; //�ܿ��к�·��
		memset(Pm, 0, RouteNumMax*sizeof(int));
		memset(Sm, 0, RouteNumMax*sizeof(double));
		memset(Jm, 0, RouteNumMax*WayPointMax*sizeof(double));
		memset(Wm, 0, RouteNumMax*WayPointMax*sizeof(double));
		memset(Rm, 0, RouteNumMax*WayPointMax*sizeof(double));
		memset(Am, 0, RouteNumMax*WayPointMax*sizeof(double));
	}
};       

struct FireCtrlCalcuUnderWayPointPlaning //��·�滮�µĵ�����·��ؽ������
{
	double Tzk    ;    //�Կط���ʱ�䣨s��
	double ZdQzhxj;    //װ��ǰ�ú���ǣ���λ���ȣ�����ʱ��Ϊ��
	double ZdFyj  ;    //װ�������ǣ��ȣ�
	double ZdQxj  ;    //װ����б�ǣ��ȣ�

	int    nWayPoint;	     //��·�ĺ�·����
	double Sm;               //��·�ĺ��̣���λ��Km
	double Jm[WayPointMax];  //��·������(���ȣ���λ����) 
	double Wm[WayPointMax];	 //��·������(γ�ȣ���λ����) 	
	double Rm[WayPointMax];  //����·�㴦��ת��뾶����λ��Km
	double Am[WayPointMax];  //����·�㴦��ת��ǣ���λ����
	
	FireCtrlCalcuUnderWayPointPlaning()
	{
		Tzk     = 0.0;    //�Կط���ʱ�䣨s��
		ZdQzhxj = 0.0;    //װ��ǰ�ú���ǣ���λ���ȣ�����ʱ��Ϊ��
		ZdFyj   = 0.0;    //װ�������ǣ��ȣ�
		ZdQxj   = 0.0;    //װ����б�ǣ��ȣ�		
		nWayPoint = 0;
		Sm = 0.0;
		memset(Jm, 0, WayPointMax*sizeof(double));
		memset(Wm, 0, WayPointMax*sizeof(double));
		memset(Rm, 0, WayPointMax*sizeof(double));
		memset(Am, 0, WayPointMax*sizeof(double));
	}
};

struct FireCtrlCalcuUnderAutoWayPointPlaning //�Զ���·�滮�µĶ�����·��ؽ������
{
	double Tzk[RouteNumMax]    ;    //�Կط���ʱ�䣨s��
	double ZdQzhxj[RouteNumMax];    //װ��ǰ�ú���ǣ���λ���ȣ�����ʱ��Ϊ��
	double ZdFyj[RouteNumMax]  ;    //װ�������ǣ��ȣ�
	double ZdQxj[RouteNumMax]  ;    //װ����б�ǣ��ȣ�
	
	int    HlNum;	                     //�ܿ��к�·��
	int    Pm[RouteNumMax];	             //������·�ĺ�·����
	double Sm[RouteNumMax];              //������·�ĺ��̣���λ��Km
	double Jm[RouteNumMax][WayPointMax]; //������·�ĺ�·������(���ȣ���λ����)
	double Wm[RouteNumMax][WayPointMax]; //������·�ĺ�·������(γ�ȣ���λ����)
	double Rm[RouteNumMax][WayPointMax]; //������·����·�㴦��ת��뾶����λ��Km
	double Am[RouteNumMax][WayPointMax]; //������·����·�㴦��ת��ǣ���λ����
	
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

struct ShipMissileLaunchLimit  //���ص���������������
{
	double MissileminRange;                      //������̺���������������λ��km	
	double MissilemaxRange;                      //������󺽳�������������λ��km	
	double MissileLaunchVectorLimit;             //������������������������λ����
	double MissileLaunchShipPitchingLimit;       //�ؽ�������������������λ����	
	double MissileLaunchShipRollingLimit;        //�ؽ���б��������������λ����	
	
	double MissileLaunchVfmax;                   //�����������������٣���/��
	double MissileLaunchTempmin;                 //������������¶�,��
	double MissileLaunchTempmax;                 //������������¶�,��
	int    MissileLaunchHqmax;                   //�����������������ȼ�
};

struct PlaneMissileLaunchLimit  //���ص���������������
{
	double MissileminRange; 	                 //������̺���������������λ��km
	double MissilemaxRange;                      //������󺽳�������������λ��km	
	double MissileLaunchVectorLimit;             //������������������������λ����	
	double MissileLaunchHeighLimit;              //�ػ�����߶���������	����λ��m
	double MissileLaunchSpeedLimit;              //�ػ������ٶ���������	����λ��m_/s
	double MissileLaunchPlanePitchingLimit;      //��������ʱ�ػ���������������	����λ����
	double MissileLaunchPlaneRollingLimit;       //��������ʱ�ػ���������������	����λ����
	double MissileLaunchPlaneOverloaddingLimit;  //��������ʱ�ػ�����������������λ��g
	
	double MissileLaunchVfmax;                   //�����������������٣���/��
	double MissileLaunchTempmin;                 //������������¶�,��
	double MissileLaunchTempmax;                 //������������¶�,��
};

struct ShipFireControlBindingState //���ػ�ؽ���״̬��ʶ���ݽṹ
{
	bool  MinrangeOK;       //���������ڵ�����С�������
	bool  MaxrangeOK;       //�������С�ڵ�������������
	bool  TargetInsight;    //Ŀ��λ����������ڣ���浼�����������90�㣩
	
	bool  LaunchZetaOK;     //��ͧ��ҡ���Ƿ�����Ҫ�󣨡�15�㣩
	bool  LaunchGamaOK;     //��ͧ��ҡ���Ƿ�����Ҫ�󣨡�6�㣩
	
	bool  WindOK;           //����������ٷ�Χ�ڣ�40m/s���£�
	bool  TemperatureOK;    //���������¶ȷ�Χ�ڣ�-30�桫+60�棩
	bool  SituationOK;      //�����Ƿ���5������
}; 

struct PlaneFireControlBindingState //���ػ�ؽ���״̬��ʶ���ݽṹ
{
	bool  MinrangeOK;       //���������ڵ�����С�������
	bool  MaxrangeOK;       //�������С�ڵ�������������
	bool  TargetInsight;    //Ŀ��λ����������ڣ���浼�����������90�㣩
	bool  LaunchHighOK;     //��������߶ȷ�Χ�ڣ�300��9000�ף�
	bool  LaunchSpeedOK;    //���������ٶȷ�Χ�ڣ���300��4500��ʱ�������ٶ�Ϊ0.75��0.9Ma����4500��9000��ʱ�������ٶ�Ϊ0.65��0.9Ma��
	bool  LaunchAttitudeOK; //����������̬��Χ�ڣ��ػ�������-2�㡫+6�㣻������-10�㡫+10�㣩
	bool  LaunchOverloadOK; //����������ط�Χ�ڣ�2g��
	bool  WindOK;           //����������ٷ�Χ�ڣ�40m/s���£�
	bool  TemperatureOK;    //���������¶ȷ�Χ�ڣ�-30�桫+60�棩
}; 

class CFireCtrlOutput //��Ŀ���ؽ��㴦����
{ 
public:
	string TargetID   ;     //Ŀ�꽢ͧ��Դ��ʶ
	double TargetJt   ;     //Ŀ�꾭�ȣ��ȣ�
	double TargetWt   ;     //Ŀ��γ�ȣ��ȣ�
	float  TargetHt   ;     //Ŀ��߶ȣ��ף�
	float  TargetRmb  ;     //Ŀ����Ե�������ƽ̨�ľ���(m)
	float  TargetBmb  ;     //Ŀ�귽λ���ȣ���0~360�㣩
	float  TargetVm   ;     //Ŀ�꺽�٣�m/s��
	float  TargetKm   ;     //Ŀ�꺽�򣨶ȣ���0~360�㣩
	float  TargetJD   ;     //Ŀ�����ϵ��
	short  CalculateMode;	//ָ���ǽ��㷽ʽ��0 �״﹥����1 ���깥����2 ǰ�õ㹥����3 ����λ������4 �˹�װ�� 
	double SimuTime   ;	    //ʱ��
	
	double Tzk;             //�Կط���ʱ�䣨s��
	double ZdQzhxj;         //װ��ǰ�ú����PHIq����λ���ȣ�����ʱ��Ϊ��
	double ZdFyj  ;         //װ��������NUz���ȣ�
	double ZdQxj  ;         //װ����б��GAMMAz���ȣ�
	
	short  PathType;        //��·�滮���ƣ�0=�޹滮��1=�Զ��滮��2�˹��滮
	int    nNumOfMissile;   //���ڴ����Ŀ��ĵ�������
	string                     IdOfMissile[RouteNumMax]; //ÿö������ID��ʶ
	FireCtrlCalcuUnderWayPointPlaning path[RouteNumMax]; //ÿö�����Ĺ�����·��Ϣ
	int    StateOfMissile[RouteNumMax]; //0��������Ԥ��״̬��1�����ѷ���
	short  TarStateOfDeal;  //Ŀ�����մ���״̬��0=���ɴ����1=�ɴ����2=�����	
public:	
	CFireCtrlOutput() //���캯��
	{
		TargetID = "";
		TargetJD = 1.0;     //Ĭ��ΪĿ�겻����
		CalculateMode = 0;	//ָ���ǽ��㷽ʽ
		SimuTime = 0.0;	    //ʱ��		
		PathType = 0;       //�����к�·�滮
		nNumOfMissile=0;        
		TarStateOfDeal=0;
		for(int i=0;i<RouteNumMax;i++)
		{
			IdOfMissile[i] = "";  //ÿö������ID��ʶ
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
			StateOfMissile[i] = 0; //0��������Ԥ��״̬��1�����ѷ���
		}
	};
};

class CMissileArmCtrlModelUser : public CMissileArmCtrlModel  
{
public:
	virtual void SetEnvironmentPara(double Cf, double Vf, double Tao, int Hk); //���û������������򣬷��٣��¶ȣ������ȼ�
	virtual void SetEnvironmentPara1(double RH, double Js, double Jr, double Va, double lamd); //���û������������ʪ�ȣ���������ѩǿ�ȡ�����ǿ�ȣ�mm/h���������ܼ��ȣ�km����������ײ�����0.3---13.9
	virtual void SetCarrierType(int nType)             ; //���õ�������ƽ̨������
	virtual void SetShipInfo(ShipInfoStruct stuShip)   ; //���ý�ͧ����Ϣ
	virtual void SetPlaneInfo(PlaneInfoStruct stuPlane); //���÷ɻ�����Ϣ
	virtual void SetMissileType(MISSILETYPE type)      ; //���õ���������
	virtual void SetMissileInfo(double Vdd, double Rzd, double PhFyj, double Hp, double RangeGate1, double RangeGate2, double AngleGate); //���õ�������Ϣ
	virtual void GetMissileInfo(double& Vdd, double& Rzd, double& PhFyj, double& Hp, double& RangeGate1, double& RangeGate2, double& AngleGate); //��ȡ��������Ϣ
	virtual void SetPlanParam(MissileFundamentalInfo mis, RoutPlanPara par, FireControlConstraint con); //���ú�·�滮����
	virtual void ReceiveTargetDesignationInfo(TargetIndicationInfo TargetIndication); //����Ŀ��ָʾ��Ϣ
	virtual bool MainSimulation(); //��ģ��
	virtual void SendLaunchInfo(LaunchAntishipInfo* LaunchInfo, int& nNum); //��������������Ϣ	
	virtual void LaunchAGM65F(LaunchAGM65FInfo& LaunchInfo); //����Сţ����������Ϣ	

public:	
	CMissileArmCtrlModelUser();
	virtual ~CMissileArmCtrlModelUser();
private:
	string IDt  ;     //Ŀ�����ID
	double Jt   ;     //Ŀ�꾭�ȣ��ȣ�
	double Wt   ;     //Ŀ��γ�ȣ��ȣ�
	float  Ht   ;     //Ŀ��߶ȣ��ף�
	double Rmb  ;     //Ŀ����Ե�������ƽ̨�ľ���(m)
	double Bmb  ;     //Ŀ�귽λ���ȣ���0~360�㣩
	double Vm   ;     //Ŀ�꺽�٣�m/s��
	double Km   ;     //Ŀ�꺽�򣨶ȣ���0~360�㣩
	double JD   ;     //Ŀ�����ϵ��
	
	int  m_nCarrierTyle;  //��������ƽ̨�����ͣ�0 ���أ�1 ����
	
	string IDc  ;     //��������ƽ̨�Ĵ���ID
	double Jc   ;     //��������ƽ̨�ľ��ȣ��ȣ�
	double Wc   ;     //��������ƽ̨��γ�ȣ��ȣ�
	double Hc   ;     //��������ƽ̨�ĸ߶ȣ���
	double Vc   ;     //��������ƽ̨�ĺ��٣�m/s��
	double Kc   ;     //��������ƽ̨�ĺ��򣨶ȣ���0~360�㣩
	
	double Zyj  ;     //��������ƽ̨����ҡ�ǣ��ȣ�����Ϊ����0~��15�㣩
	double Hyj  ;     //��������ƽ̨�ĺ�ҡ�ǣ��ȣ�������бΪ����0~��30�㣩	
	double Gdmzj;     //��������ƽ̨�ķ���̶ܹ���λ��(+-90��)������-90�ȣ�����+90��
	double Gdfyj;     //��������ƽ̨�ķ���̶ܹ�������(15��)����+����-
	double Overload;  //�ػ����أ�g
	
    //-------��ز���--------
	MISSILETYPE m_missileType; //���õ�������
	double m_Vdd  ;          //���������ٶȣ�m/s��
	double m_Rzd  ;          //�����Ե��״����þ���(��)
    double m_PhFyj;          //����Ѳ��ƽ��ʱ��ƽ�⸩����(2.5��)
	double m_Hp   ;          //����ƽ�ɸ߶� ��	
	double m_RangeGate1;     //���벨������ ��	
	double m_RangeGate2;     //���벨������ ��	
    double m_AngleGate ;     //�ǶȲ��� ��
	
	double TzkMin;                   //�������Ե�����ʱ����Сֵ100��
	double m_AttackAngle;			 // ��������
	double AttackClampAngle;         //�����нǣ���
	double AttackAngle[RouteNumMax]; //�����ǣ���
	
	short CalculateMode;	 //ָ���ǽ��㷽ʽ��0 �״﹥����1 ���깥����2 ǰ�õ㹥����3 ����λ������4 �˹�װ�� 
	short PathType;          //��·�滮���ͣ�0=�޹滮��1=�Զ��滮��2�˹��滮
	int   nNumOfMissile;     //���ڴ����Ŀ��ĵ������������ֵΪ��RouteNumMax
	WayPointPlaningOutput PathPar; //�˹��滮ʱ���ṩ��·����Ϣ

	//��ؽ���������Ŀ���Ҳ����һ����·�㣬��0��1��2��������
	ShipFireControlBindingState           ShipFireCtrlState;    //���ػ�ؽ���״̬��ʶ		
	PlaneFireControlBindingState          PlaneFireCtrlState;   //���ػ�ؽ���״̬��ʶ
	CFireCtrlOutput                       m_FireCtrlpar;        //Ŀ��ָʾ��Ϣ����ؽ�������Ϣ
	FireCtrlOutput                        FireCtrlCalOutput;    //�����к�·�滮ʱ�Ļ�ؽ������
	FireCtrlCalcuUnderAutoWayPointPlaning FireCtrlCalUnderAWPP; //�Զ���·�滮�µĻ�ؽ������
	FireCtrlCalcuUnderWayPointPlaning     FireCtrlCalUnderWPP;  //�˹���·�滮�Ļ�ؽ������
    LaunchAntishipInfo                    Linfo[RouteNumMax];   //����������Ϣ
public:
	//��������
	double m_Cf;  //���򣬶�
	double m_Vf;  //���٣���/��
	double m_Tao; //�¶ȣ����϶�
	int    m_Hk;  //��������
	
	double m_RH; //���ʪ�ȣ�����
	double m_Js; //��ѩǿ��
	double m_Jr; //����ǿ�ȣ���λmm/h��
	double m_Va; //�����ܼ���
	double lamda; //������ײ�����0.3---13.9
	
	//������������
	ShipMissileLaunchLimit  ShipLaunchLimit;  //���ط�����������
	PlaneMissileLaunchLimit PlaneLaunchLimit; //���ط�����������
	
	//��·�滮��������	
	double SailMax ;                           //һ����·����󺽳̣���λ��Km
	double MaxTuringAngle;                     //������·���ת���(��)
	double MinNeighborhoodWayPointDistance;    //���ں�·����̾���(km)
	double MinFinalWayPointToTargetDistance;   //���һ����·����Ŀ������С������������(km)
	double MinFirstWayPointToLauncherDistance; //��һ����·���뷢�����Ҫ��(km)
	double MinTuringRadiusLimit;               //��Сת��뾶��km	
private:
	bool AGM65FFireCtrl(double Hplane, double Vplane, double Rt); //��������߶ȣ���λ��km���ػ��ٶȣ���λ��m/s��Ŀ����룬��
	bool ShipFireCtrlCalcu(CFireCtrlOutput* pTarget);  //���ػ�ؽ���
	bool PlaneFireCtrlCalcu(CFireCtrlOutput* pTarget); //���ػ�ؽ���
	bool IsShipSatisfyTheNeeds(
		double Rt,double Bt,
		double Kc,double GDMzj,
		double Zyj,double Hyj,
		double Vf,double Tao,int Hk,
		ShipMissileLaunchLimit LaunchLimit,
		ShipFireControlBindingState& FireCtrlState);  //���ػ�ؽ���״̬��ʶ���ݽṹ
	bool IsPlaneSatisfyTheNeeds(		
		double Rt,double Bt,
		double Vc,double Kc,double Hc,
		double Zeta,double Gama,
		double Overload,
		double Vf,double Tao,		
		PlaneMissileLaunchLimit LaunchLimit,
		PlaneFireControlBindingState& FireCtrlState); //���ػ�ؽ���״̬��ʶ���ݽṹ
	bool FireCtrlCalcu(short PathType, int nCarrierStyle, int nShootingMode, 
		int nNumOfMissile, CFireCtrlOutput* pTarget); //��ؽ���ģ��	
    //�����к�·�滮ʱ�Ļ�ؽ���ģ��
	bool ShipFireCtrlCalcu(double Rmb,double Bmb,double Vm,double Km,double JD,
		double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,
		FireCtrlOutput& output);                            //���ػ�ؽ��㣺���У�Wc �ؽ�γ��(��)��Vdd �����ٶ�(m/s)
	bool ShipFireCtrlCalcuByB(double Bmb,
		double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,
		FireCtrlOutput& output);                            //���ش���λ������ؽ���	
	bool PlaneFireCtrlCalcu(double Rmb,double Bmb,double Vm,double Km,double JD,
		double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,
		double Vdd,
		FireCtrlOutput& output);                            //���ػ�ؽ��㣺���У�Wc �ػ�γ��(��)��Vdd �����ٶ�(m/s)
	void CalcuPoseAngle(double Zyj,double Hyj,
		double Gdmzj,double Gdfyj,
		double& Qzmzj,double& Fyj,double& Qxj); //���㵼����̬��
	//�Զ���·�滮�µĶ�����·��ؽ���
	bool ShipFireCtrlCalcuUnderAutoWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,
		int nNum,double* AttackAngle,
		FireCtrlCalcuUnderAutoWayPointPlaning& output); //�Զ���·�滮�µĽ��ض�����·��ؽ���
	bool ShipFireCtrlCalcuByBUnderAutoWayPointPlaning(
		double Bmb,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,
		int nNum,double* AttackAngle,
		FireCtrlCalcuUnderAutoWayPointPlaning& output); //�Զ���·�滮�µĽ��ض�����·����λ������ؽ���		
	bool PlaneFireCtrlCalcuUnderAutoWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,
		double Vdd,
		int nNum,double* AttackAngle,
		FireCtrlCalcuUnderAutoWayPointPlaning& output); //�Զ���·�滮�µĻ��ض�����·��ؽ���
	//�Զ���·�滮�µĵ�����·��ؽ���ģ��
	bool ShipFireCtrlCalcuUnderWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,double AttackAngle,
		FireCtrlCalcuUnderWayPointPlaning& output); //�Զ���·�滮�µĽ��ص�����·��ؽ���
	bool ShipFireCtrlCalcuByBUnderWayPointPlaning(
		double Bmb,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,double AttackAngle,
		FireCtrlCalcuUnderWayPointPlaning& output); //�Զ���·�滮�µĽ��ص�����·����λ������ؽ���
	bool PlaneFireCtrlCalcuUnderWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,
		double Vdd,double AttackAngle,
		FireCtrlCalcuUnderWayPointPlaning& output); //�Զ���·�滮�µĻ��ص�����·��ؽ���
	//�˹���·�滮�µĻ�ؽ���
	bool ShipFireCtrlCalcuUnderWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,double Gdmzj,double Gdfyj,
		double Vdd,int nWayPoint,double* Jm,double* Wm,
		FireCtrlCalcuUnderWayPointPlaning& output); //�˹���·�滮�µĽ��ػ�ؽ���	
	bool PlaneFireCtrlCalcuUnderWayPointPlaning(
		double Jt,double Wt,double Vm,double Km,double JD,
		double Jc,double Wc,double Vc,double Kc,double Zyj,double Hyj,
		double PhFyj,double Rzd,
		double Vdd,int nWayPoint,double* Jm,double* Wm,
		FireCtrlCalcuUnderWayPointPlaning& output); //�˹���·�滮�µĻ��ػ�ؽ���
	//��·�滮ģ��
	bool AutoWayPointPlaning(double Jc,double Wc,
		double Jt,double Wt,
		int nNum,double* AttackAngle,
		AutoWayPointPlaningOutput& output);                //������·�Զ���·�滮ģ�飬������ع���
	bool AutoWayPointPlaning(double Jc,double Wc,
		double Jt,double Wt,
		double AttackAngle,
		WayPointPlaningOutput& output);                    //������·�Զ���·�滮ģ�飬������ع���
	bool ManualWayPointPlaning(double Jc,double Wc,
		double Jt,double Wt,
		int nWayPoint,double* Jm,double* Wm,
		WayPointPlaningOutput& output);                    //�˹�װ����·�滮ģ�飬������ع���
public:	
	double interp1(int n, double x, double* X0, double* F); //���Ⱦ൥��Ԫ���Բ�ֵ��X0[n]��F[n]
	double f180(double Angle);/*��λΪ��*/
	double f360(double Angle);/*��λΪ��*/
	int    Sign(double n);
	double ToAngle(double F0, double Ft); //���㷽λ��Ft�����FO���Ͻǣ���λ(��),-180--+180��
	double Clamp(double F0, double Ft);   //����FO��Ft֮��ļнǣ���λ(��)��0--+180��
	double GetCurvatureRadiusOfLatitude(double Fai /*��λΪ��*/); //��õ�ǰ��γ��Ȧ�����ʰ뾶
	double GetCurvatureRadiusOfLongitude(double Fai /*��λΪ��*/);//��õ�ǰ�㾭��Ȧ�����ʰ뾶
	void   GetDetJWFromBD(double J0,double W0,double B,double D,double& DetJ,double& DetW); //��֪��λ(��)�;���(��)�����㾭�Ȳ��γ�Ȳ��λ����
	void   GetBDFromDetJW(double J0,double W0,double Jt,double Wt,double& B,double& D);//��֪����ľ��Ⱥ�γ�ȣ����㷽λ�;��룬��λ���ȡ���
//	void PutInSort(LaunchAntishipInfo* LaunchInfo, int nNum);
	string strError; //������Ϣ�ַ���
public:
	virtual void GetErrorStr(char str[])
	{
		strcpy(str, strError.c_str());
	};	
};

#endif //MISSILEARMCTRLMODE__USERMODEL_H_
