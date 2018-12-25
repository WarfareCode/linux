// FightingUnit.h: interface for the CFightingUnit class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FIGHTINGUNIT_H
#define FIGHTINGUNIT_H

#include "BwVehicleKinematic.h"
#include "interface.h"	// Added by ClassView
#include "Craft.h"	// Added by ClassView
#include "Environment.h"	// Added by ClassView
#include "Driver.h"	// Added by ClassView
#include "MyType.h"


namespace  BW_VEHICLEKINEMATIC {

	class CFormationServer;
	class CDriver;
	class CCraft;
	class CEnvironment;

	class  BW_VEHICLEKINEMATIC_API CFightingUnit  //  ��ս��Ԫ�ࣨ��������������������ʻԱ��
	{
	public:
		//  �ı䱾���ڱ���е�λ��
		void change_position( int iPositionID );

		//  �����ӣ���ɢ��
		bool command_format( bool b, int iPositonID, CFormationServer *pFormationServer );

		//  �������
		bool command_maneuver( int iManeuver );  //  1����ת�䣻2���Ҽ�ת�䣻3��������4���Һ����5���ﶷ��6������ﶷ��7����������8��Ծ���½���

		//  ��в����
		void warning_BeingAttacked( int iClock );

		//  �������
		void guide_by_fire_ctrol( double v_kmph, double alti_m, double heading_deg );

		//  ��ؿ���
		void Switch_fire_control( bool b);

		//  ��ѯ��ǰ�����Ƿ����
		bool IsTaskOver( );

		//  ��ѯ��ǰ���߷����Ƿ����
		bool IsRouteOver( );

		//  �趨���Լ�ʻ
		void set_self_drive( bool b );

		//  �趨�ٻ������ϡ�ս�𡢼�ʻԱʧ�ܣ�
		void set_failed( bool b );

		//  �����������
		void set_task( stPatrolPara PatrolPara );

		//  ����������
		void set_route_task( CRoute Route );

		//  �������к���
		//	void set_route( CRoute Route );

		//  ������������
		void set_base_return( double _RW_alti_m, double _RW_lati_rad, double _RW_longi_rad, double _RW_head_deg, int iLandingType );

		//  ��������������ڵ�����
		void command_attack( void );

		//  �������/����
		void command_go( bool b );

		//  ������/��½
		void command_TakeOff( bool b );

		//  ��������
		void tick_FightingUnit( double Dt, double altiG_m, double Target_alti_m, double Target_lati_rad, double Target_longi_rad );

		//  ��ʼ������
		void ini_FightingUnit( int iUnitID, double RW_alti_m, double RW_lati_deg, double RW_longi_deg, double RW_head_deg, double alti_m, double lati_deg, double longi_deg, double head_deg, double speed_kmph, double teta_deg );

		//  ���乹�캯��
		void con_FightingUnit( stPerformance stPerformance );

		CFightingUnit();
		virtual ~CFightingUnit();

		//  ������
		bool m_bFailed;  //  ʧЧ�����ϡ������ٵȣ�

		bool m_bSelfDrive;  //  ���Լ�ʻ

		//  ״̬
		bool m_bOK_ini;    //  ��ʼ�����Ѿ�����
		bool m_bOK_route;  //  �����Ѹ���
		bool m_bOK_task;   //  �������´�

		double m_dTime;  //  ������ʱ��
		double m_dStep;  //  ���㲽��

		//  ��ս��Ԫ��Ա
		//	stPatrolPara m_cPatrolPara;  //  Ѳ����������

		CDriver      m_cDriver2;      //  ����ʻԱ������ʻԱΪ�������Ա��

		CCraft       m_cCraft;        //  �������̶���ɻ���ֱ������������½�س�����ˮ�洬ֻ��Ǳͧ��

		CEnvironment m_cEnvironment;  //  ������������½�ء�����
	};


}  //  namespace end


#endif
