// Driver.h: interface for the CDriver class.
//
//////////////////////////////////////////////////////////////////////

#ifndef DRIVER_H
#define DRIVER_H

#include "BwVehicleKinematic.h"
#include "Environment.h"	// Added by ClassView
#include "Craft.h"	// Added by ClassView
#include "interface.h"	// Added by ClassView


namespace  BW_VEHICLEKINEMATIC {


#define NStage 10  //  ���н׶���������
	class CEnvironment;
	class CCraft;

	class  BW_VEHICLEKINEMATIC_API CDriver  //  ��ʻԱ�ࣨ�ܹ���ʻ���̶���ɻ���ֱ������������½�س�����ˮ�潢����Ǳͧ�ȣ�
	{
	public:
		//  �趨������ɰ�ȫ�߶�
		void set_missile_safe_alti( double alti_m );

		//  �����ӣ���ɢ��
		bool command_format( bool _b);

		//  �������
		bool command_maneuver( int iManeuver );  //  1����ת�䣻2���Ҽ�ת�䣻3��������4���Һ����5���ﶷ��6������ﶷ��7����������8��Ծ���½���

		//  ��в��Ϣ
		bool warning_BeingAttacked( int iClock );

		//  �ⲿ����ı䵱ǰ�����ٶ�
		bool change_speed( bool bChangeSpeed, double speed_kmph );

		//  �ⲿ����ı䵱ǰ���и߶�
		bool change_alti(  bool bChangeAlti,  double alti_m );

		//  ��ʻ��Ȩ
		void switch_authorize( bool b );

		//  ����������
		void set_route_task( CRoute Route );

		//  �����������
		void set_task( stPatrolPara PatrolPara );

		//  �趨���صĺ��θ߶ȣ�����������ɵĻ�����ۿڣ�
		void set_alti_base( double alti_m );

		//  �����жϣ���ȼ�͵�����������ػ��ز�ͣ����
		void decide_return( void );

		//  ����׼������
		bool tick_pro_prepareG( double Dt );

		//  �����������
		bool tick_pro_standbyG( double Dt );

		//  ��ɳ���
		bool tick_pro_TakeOff( double Dt );

		// ���д�������
		bool tick_pro_standbyA( double Dt );

		//  ���߷��г���
		bool tick_pro_route( double Dt );

		//  ��������
		bool tick_pro_formating( double Dt );

		//  ��������
		bool tick_pro_maneuver( double Dt );

		//  �������
		bool tick_pro_task0( double Dt );  //  Ĭ������
		bool tick_pro_task1( double Dt );  //  �����������г���
		bool tick_pro_task2( double Dt );  //  ����κ��߷��г���
		bool tick_pro_task3( double Dt );  //  Բ�κ��߷��г���
		bool tick_pro_task4( double Dt );  //  ��Բ�κ��߷��г���
		bool tick_pro_task5( double Dt );  //  8 ���κ��߷��г���
		bool tick_pro_task_missile( double Dt );  //  ��������
		bool tick_pro_task_straight(double Dt);		// ֱ�ߺ��У�m_iStage =5��m_iTask=-3ʱ���� , ֻ����Ǳͧ����ͧ���������г��ٶ���û�б������κ�����ʱ���ã�xks,20180704

		//  ��������
		bool tick_pro_approaching( double Dt );

		//  ��½����
		bool tick_pro_landing( double Dt );
		bool tick_pro_landing_heli( double Dt );

		//  �׶μ������
		void clear_stage_check( void );

		//  �������
		void command_attack( void );

		//  �������/����
		void command_go( bool b );

		//  ������/��½
		void command_TakeOff( bool b );

		//  �������к���
		void tick_driver( double Dt, double Target_alti_m, double Target_lati_rad, double Target_longi_rad );

		//  ��ʼ������
		void ini_Driver( double alti_base );

		//  ���乹������
		void con_Driver( CEnvironment *pEnvironment, CCraft *pCraft );

		CDriver();
		virtual ~CDriver();

		//  ������ɰ�ȫ�߶�
		double m_dMissileSafeAlti;  //  ������ɰ�ȫ�߶�

		//  �б�λ�ã���֡���ݣ�
		double m_dTarget_alti_m0,    m_dTarget_alti_m1;     //  ���θ߶�
		double m_dTarget_lati_rad0,  m_dTarget_lati_rad1;   //  γ��
		double m_dTarget_longi_rad0, m_dTarget_longi_rad1;  //  ����

		double m_dTarget_distance_m0;  //  �б����
		double m_dTarget_distance_m1;  //  �б����
		double m_dTarget_distance_min_m1;  //  �б���С����
		double m_dTarget_speed_mps;    //  �б�����ٶ�

		double m_dTarget_pitch_deg0;       //  �б긩����
		double m_dTarget_pitch_deg1;       //  �б긩����
		double m_dTarget_pitching_degps;  //  �б긩��������

		double m_dTarget_psai_deg0;      //  �б�ƫ����
		double m_dTarget_psai_deg1;      //  �б�ƫ����
		double m_dTarget_yawing_degps;  //  �б�ƫ��������
		double m_dTarget_Dpsai_deg;      //  �б�ƫ����

		//  ��������ֵ
		bool m_bAttack;

		//  ��Ⱥ����
		bool m_bCMDFormat;  //  ��ӣ���ɢ������

		//  �����������ս��Ϣ
		bool m_bTakeOff;  //  ��ɣ����⣬���ۣ�������½�����⣬���ۣ�
		bool m_bGo;       //  ������ս�����򣺷��أ�

		int m_iTask;  //  Ѳ���˶����͡�0��Ĭ��Բ�ι켣��1������������Ѳ�ߣ�2������κ���Ѳ�ߣ�
		//                3��Բ�κ���Ѳ�ߣ�4����Բ����Ѳ�ߣ�  5�������κ���Ѳ�ߣ�6�����ã�10��������

		bool m_bBeingAttacked;  //  ������״̬
		int m_iAttackedClock;   //  �����������ӱ�ָ�룩

		bool m_bCMDManeuver;  //  ����ָ��
		int m_iManeuver;      //  ����������1����ת�䣻2���Ҽ�ת�䣻3��������4���Һ����5���ﶷ��6������ﶷ��7����������8��Ծ���½���

		bool m_bSetSpeed;  //  ָ���ٶ�
		bool m_bSetAlti;   //  ָ���θ߶�

		double m_dCMDSpeed;  //  ָ������ٶ�
		double m_dCMDAlti;   //  ָ����и߶�

		//  ���ҿ���
		bool m_bFormating;         //  ִ�б�ӷ���
		bool m_bManeuveringReady;  //  ����׼����
		bool m_bManeuvering;  //  �������л���
		bool m_bOK;  //  �������
		bool m_bNewTask;              //  �������־
		bool m_bAuthorized;           //  ��Ȩ��ʻ
		bool m_bDecideParking;        //  ��������
		bool m_bStage_check[NStage];  //  �׶μ��

		int m_iStage;  //  ���н׶Ρ�0������׼����1�����ڴ�����2�����/��ۣ�3���Ͽ�/���������4��������
		//            5��ִ������6��������7����������/���ۣ�8������/���ۣ�9����½/ͣ��

		int m_iStageManeuver;  //  ���ӻ����Ľ׶Ρ�

		//  ״̬��
		double m_dBank;   //  ��ת�ǣ����޷����ɷ�ӳȦ��
		double m_dPitch;  //  �����ǣ����޷����ɷ�ӳȦ��
		double m_dPsai;   //  ƫ���ǣ����޷����ɷ�ӳȦ��
		double m_dH0;     //  ������ʼ�߶�
		double m_dV0;     //  ������ʼ�ٶ�
		double m_dT0;     //  ������ʱ

		double m_dTimePatrol;  //  Ѳ��ʱ��

		double m_dTimes[NStage];  //  ���׶�ʱ��
		double m_dTimeRun;  //  ��ʻ��ʱ��
		double m_dTime;     //  ����ʻֵ����ʱ��

		bool m_bLiftOff;  //  �ɻ���أ���Ǳˮͧ�³�����־

		//  �й�����ϵͳ
		stPatrolPara  m_cPatrolPara;   //  Ѳ���������ݰ�

		CCraft       *m_pCraft;        //  ��������������ָ��
		CEnvironment *m_pEnvironment;  //  ����ָ��

	private:
		double m_dAlti_base;  //  ���صĺ��θ߶ȣ����ڷ�������Ϊ��������ˮ�潢����ǱͧΪ�㣩

	};

#undef NStage


}  //  namespace end


#endif
