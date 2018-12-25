// interface.h
//
//////////////////////////////////////////////////////////////////////

#ifndef INTERFACE_H
#define INTERFACE_H

#include "MyType.h"


namespace  BW_VEHICLEKINEMATIC {


#define MAX_MSG_SIZE 512

	//  system identifier define
	enum SYS_ID
	{
		ALL =  0,  //  ���з�ϵͳ
		MCS =  1,  //  �ۺϿ���ϵͳ
		MFS =  2,  //  �����з���ϵͳ
		SSS =  3,  //  �Ӿ�
		CLS =  4,  //  ����
		SWS =  5,  //  ����
		IOS =  6,  //  �ӿ�
		AES =  7,  //  �������Ǳ�
		ADJ =  8,  //  ����̨
		VTS =  9,  //  ���ذ�
		FCS = 10,  //  �ɿ�ϵͳ
		MRK = 11   //  ��ά̬��
	};

	//  control command define
	enum CMD_TYPE
	{
		NET_TEST = 0,    //  ������
		SYS_INIT = 1,    //  ��ʼ��
		SYS_START= 2,    //  ���濪ʼ
		SYS_STOP = 3,    //  ����ֹͣ
		SYS_OFF  = 4,    //  ϵͳ�ر�
		SYS_FREZ = 5,    //  ����
		SYS_UNFREZ = 6,  //  �ⶳ
		SYS_ACK  = 7     //  ϵͳ���У����ڱ�ʶ���й����з�����������
	};

	//  sys status define
	enum SYS_STATUS
	{
		SS_FAIL =  0,  //  ����
		SS_TEST =  1,  //  ������
		SS_INIT =  2,  //  ��ʼ��
		SS_START = 3,  //  ���濪ʼ	
		SS_STOP =  4,  //  ����ֹͣ
		SS_FREZ = 5,   //  ����
		SS_UNFREZ = 6  //  �ⶳ
	};

	//  Message Values
	enum MessageValues
	{
		MV_ALL = 0,
		MV_WindLoad = 1,    //  �糡����
		MV_Fuel = 2,        //  ����ȼ��
		MV_CG = 3,          //  ��������λ��
		MV_Altitude = 4,    //  ������ѹ�߶�
		MV_CAS = 5,	        //  �������
		MV_Loading = 6,     //  ����װ����
		MV_Reposition = 7,  //  ����ˮƽλ��
		MV_PromptStart = 8,  //  ������Ѹ������
		MV_FuelFreeze = 9,   //  ȼ�Ͷ���
		MV_EngineFault = 10   //  ����������
	};

	//  Vehicle Type  ��������
	enum VehicleType
	{
		Vehicle_aircraft = 0,    //  �̶���ɻ�;
		Vehicle_helicopter = 1,  //  ֱ����
		Vehicle_land = 2,        //  ½������
		Vehicle_ship = 3,        //  ˮ�潢��
		Vehicle_submarine = 4    //  Ǳͧ
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  ͨ�����ݰ�
	//
	struct CtlCmd
	{
		unsigned char  ucSourceSysId;  //  ���ͷ���ϵͳ��ʶSYS_ID
		unsigned char  ucDestSysId;    //  ���շ���ϵͳ��ʶSYS_ID
		unsigned char  ucMsgType;      //  ���͵���Ϣ����CTL_CMD
		unsigned char  ucMsgValue;     //  ��Ϣֵ
		unsigned char  ucDummy[4];     //  ����
		char cMsgBody[MAX_MSG_SIZE];   //  ��Ϣ��
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺����̨ -> �����з���
	//
	struct stMCStoMFS
	{
		char c;  //  ������̿���ָ�0 - �������У�1 - ��ʼ�� ; 2 - ���᣻ 3 - ���ã�99 - �ػ���

		int iCruiseMode;  //  ��ָ��λ��Ѳ��ģʽ��-1����½������0����ͣ������1��Բ�ι켣��2����Բ�ι켣��3��8���ι켣��4�����ã���

		int iRapidClass;  //  ���ȵȼ���0�����죻1������ʱ�䣻2�������ٶȣ�

		bool bGivenAlti;   //  ���涨�ĸ߶ȷ���

		double fGivenAlti_km;
		double fGivenTime;
		double fGivenSpeed_kmph;

		CRoute cRoute;  //  ���ߣ�����ֻ��һ���㣩
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺�����з���ϵͳ -> ����̨
	//
	struct stMFStoMCS
	{
		int iFlightMode;  //  ���н׶Ρ�0�����������1����ɹ��̣�2�������Ͽմ�����3��������4������ĩ��ִ������ս����Ѳ�ߡ���������5�����ر����Ͽգ�6����½���̣�

		double fAlti_m;  //  ��ǰ���и߶ȣ���λ���ף�
		double fGSpeed;  //  ��ǰ���٣���λ��ǧ��/Сʱ��
		double fLati_deg;   //  ��ǰγ�ȣ���λ���ȣ�
		double fLongi_deg;  //  ��ǰ���ȣ���λ���ȣ�
		double fHeading_deg;  //  ��ǰ���к��򣨵�λ���ȣ�
		double fBank_deg;    //  ��ǰ�ɻ���ת�ǣ���λ���ȣ�
		double fPitch_deg;    //  ��ǰ�ɻ������ǣ���λ���ȣ�

		double fFlyTime_min;      //  ����ʱ�䣨���ӣ�
		double fCourseDone_km;    //  ����
		double fCourseRemain_km;  //  ʣ����о��루ǧ�ף�
		double fTimeRemain_min;   //  ʣ�����ʱ�䣨���ӣ�
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺��������
	//
	struct stPerformance
	{
		int iVehicleType;  //  �������ͣ�0���̶���ɻ���1��ֱ������2��½��������3��ˮ�潢����4��Ǳͧ��10������Ѳ��������

		double fTimetoPrepare;  //  ����ǰ����׼��ʱ�䣨������ȷ���壬�û����Լ����壩

		//  �˶����ƺ�����
		double fAltiMax;  //  �߶����ޣ�����У�
		double fAltiMin;  //  �߶����ޣ�����У�
		double fHDMax;    //  ��������ʣ�m/min��
		double fHDMin;    //  ����½��ʣ�m/min��

		double fVMax;      //  ����ٶȣ�m/s��
		double fVMin;      //  ��С�ٶȣ�m/s��  //  ��ʱ���á�
		double fVLiftOff;  //  ����ٶȣ�m/s��  //  ���̶���
		double fVLanding;  //  �ӵ��ٶȣ�m/s��  //  ���̶���
		double fVCruise;   //  Ѳ���ٶȣ�m/s��
		double fVDefault;  //  Ĭ���ٶȣ�m/s��

		//  ��������
		double fn_engineM;  //  ������ر�
		double fn_brakeM;   //  ���ɲ�ر�

		double fn_Max;  //  ���������ض��ٸ�g��ֱ����Ϊ�㣩

		double f_pMax;  //  ����ת���ٶȣ�deg/s��
		double f_qMax;  //  ��������ٶȣ�deg/s������ʱ���ã�

		//  ֱ���������˶������������ڴ�����
		double fHeli_rMax;  //  ���ƫ�����ٶȣ�deg/s��
		double fHeli_vxMax;  //  �����������
		double fHeli_vyMax;  //  ���������
		double fHeli_vzMax;  //  ����������

		//  �Զ���������
		double fAP_pitchMax;  //  AP�����������	��
		double fAP_pitchMin;  //  AP������С������	��
		double fAP_bankMax;   //  AP��������ת��	��

		//	double fEnergyConsuming;  //  �����ͺ�   /s/ax
		double fRangeMax_km;  //  ���� ǧ��

		//  ��ʻԱ��λ���꣨�ף�
		double fEye_x;  //  ǰ��
		double fEye_y;  //  ����
		double fEye_z;  //  ����
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺Ѳ�߲��������߼����ء���ţ�1
	//
	struct	stPatrolRouteParams
	{
		//	CRoute Route;  //  ����

		bool IsCrossPoints;  //  ���㵼����־
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺Ѳ�߲����������������ţ�2
	//
	struct	stPatrolPolygonParams
	{
		//	CRoute Route;            //  ����

		bool IsCrossPoints;      //  ���㵼����־

		bool bCounterClockWise;  //  ��ʱ��ת���־

		int  NumStartPoint;      //  ��ʼ����
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺Բ������Ѳ�߲�������ţ�3
	//
	struct	stPatrolCircleParams
	{
		//	CRoute Route;            //  Ŀ���λ�ã����κ��ߣ�

		double Radius_km;        //  Ѳ�߰뾶��km

		bool bCounterClockWise;  //  ��ʱ��ת���־
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺Ѳ�߲�������Բ��������ţ�4
	//
	struct	stPatrolEllipseRarams
	{
		//	CRoute Route;  //  Ŀ���λ�ã����κ��ߣ�

		double RadiusMinorSemi_km;    //  ����뾶��km

		double RadiusMajorSemi_km;    //  ����뾶��km

		double HeadingMajorAxis_deg;  //  ���ẽ��deg

		bool bCounterClockWise;  //  ��ʱ��ת���־
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺Ѳ�߲�����8����������ţ�5
	//
	struct	stPatrolCurveEightParams
	{
		//	CRoute Route;  //  Ŀ���λ�ã����κ��ߣ�

		double RadiusMinorSemi_km;    //  ����뾶��km

		double RadiusMajorSemi_km;    //  ����뾶��km

		double HeadingMajorAxis_deg;  //  ���ẽ��deg

		bool bCounterClockWise;  //  ��ʱ��ת���־
	};

	////////////////////////////////////////////////////////////////////////
	//
	//  �ṹ�壺Ѳ������˵��
	//
	struct stPatrolPara
	{
		int PatrolMoveType;  //  Ѳ��ģʽ��0-Ĭ��ģʽ��1-����������Ѳ�ߣ�2-���������Ѳ�ߣ�3-Բ������Ѳ�ߣ�4-��Բ����Ѳ�ߣ�5-����������Ѳ�ߣ�6-���á�

		stPatrolRouteParams      PatrolAlongRoute;       //  1����������Ѳ�߲���

		stPatrolPolygonParams    PatrolAlongPolygon;     //  2�����������Ѳ�߲���

		stPatrolCircleParams     PatrolAlongCircle;      //  3��Բ������Ѳ�߲���

		stPatrolEllipseRarams    PatrolAlongEllipse;     //  4����Բ����Ѳ�߲���

		stPatrolCurveEightParams PatrolAlongCurveEight;  //  5��8��������Ѳ�߲���

		bool IsAssignPatrolVel;   //  �Ƿ�ָ��Ѳ���ٶ�

		double PatrolVel_kmph;    //  Ѳ���ٶȣ�km/h

		bool IsAssignPatrolTime;  //  �Ƿ�ָ����Ѳ��ʱ��

		double PatrolTime_min;    //  ��Ѳ��ʱ�䣬min

		CRoute Route;  //  Ѳ�ߺ��ߣ����ֻ��Ŀ���λ�ã���ɿ������κ��ߣ�

	};


}  //  namespace end


#endif
