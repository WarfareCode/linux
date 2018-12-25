// FMS.h: interface for the CFMS class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FMS_H
#define FMS_H

#include "BwVehicleKinematic.h"
#include "MyType.h"	// Added by ClassView
#include "interface.h"	// Added by ClassView


namespace  BW_VEHICLEKINEMATIC {


	class  BW_VEHICLEKINEMATIC_API CFMS  //  ���й���ϵͳ�ࣨ�������ɹܣ�
	{
	public:
		//  ��ʼ���ߵ���
		void start_curve( bool b );

		//  �޸����ߺ��ߣ�iType��0-Բ�Σ�1-��Բ��8-8���Σ�
		void recreate_curve_route( double _a_m, double _b_m, double psai_rad, int iType, bool bCounterClockWise );

		//  ��·�㵽���ж�
		void ArriveDecide( );

		//  ��õ�ָ����·��ľ���
		double get_DistanceToPoint( int iRoute, int iPoint, double lati_rad, double longi_rad);

		//  ��������
		void tick_FMS( double Dt, double omgyg_rad, double alti_m, double lati_rad, double longi_rad, double psai_rad, double pitch_rad, double gama_rad, double TAS_mps, double GS_mps, double teta_rad, double vx_mps, double vy_mps, double vz_mps );

		//  �������У����ߺ���
		void tick_RouteCurve( double Dt, double vx_mps, double vy_mps, double vz_mps );

		//  �������У���Բ����
		void tick_Route( double Dt, double teta_rad );

		//  �Ե�ǰλ��Ϊ���
		void start( );

		//  ���غ���
		void load_route( int iRouteType );

		//  ָ����½����
		void set_landing_route( double _RW_alti_m, double _RW_lati_rad, double _RW_longi_rad, double _RW_head_deg, int iLandingType );

		//  ��ʼ������
		void ini_FMS( double _RW_alti_m, double _RW_lati_rad, double _RW_longi_rad, double _RW_head_deg, double P0_alti_m, double P0_lati_rad, double P0_longi_rad, double P0_GS_mps, double P0_head_deg );

		//  ���乹�캯��
		void con_FMS( stPerformance *pPerformance );

		CFMS();
		virtual ~CFMS();

		//  ��ʼ
		bool m_bStart;  //  ��ʼ����
		bool m_bStartCurve;  //  ��ʼ���ߵ���ģʽ������Ϊ��Բ����ģʽ��

		//  ���򵼺�����
		int    m_iRapidClass;  //  ���ȵȼ���0�����죻1��ָ��ʱ�䣻2��ָ���ٶȣ�2016-05-14

		double V_dAltiPlan;  //  �ƻ��߶�
		double V_dGSPlan;    //  �ƻ��ٶ�
		double V_dDAlti;     //  �߶�ƫ��

		//  ˮƽ���������������ڴ�Բ���� �� ���ߵ�����
		double H_dGamaBase;  //  ��׼�¶�
		double H_dPsaiC;     //  Ӧ�ɺ���
		double H_dDPsai;     //  �����ƫ��
		double H_dDz;        //  ��ƫ��

		//  ��Բ����������
		int    C_iP0;       //  ����ɺ�·�����
		int    C_iTurning;  //  ˮƽת�䣨-2�������ͷ��-1����ת�䣻0����ת�䣻1����ת�䣻2�����ҵ�ͷ��
		double C_dRadius;   //  ��ǰĿ��Բ�뾶
		double C_dDPsaiC;   //  ��ת���

		//  ���ߵ�����״̬
		bool RC_bCounterClockWise;  //  ��ʱ���־
		double RC_latiC;
		double RC_longiC;
		double RC_psai0;  //  ����ƫ����
		double RC_xg;  //  x ������
		double RC_zg;  //  z ������

		//  ��Բ���߷���״̬
		bool   R_bEnd;          //  ���߸������
		double R_dRangeRemain;  //  ������ʣ�����
		double R_dTimeRemain;   //  ������ʣ��ʱ��
		double R_dDistance0;    //  ����һĿ����ˮƽ����
		double R_dDistance1;    //  ����һĿ����ˮƽ����
		double R_dDistanceS0;   //  ͶӰ����һĿ���ľ���
		double R_dDistanceS1;   //  ͶӰ����һĿ���ľ���
		double R_dAlfa;         //  �ڱ����δ�Բ������ϵ�ļ���
		//	double R_dTime0;      //  ����һĿ����ʱ��
		double R_dTime1;      //  ����һĿ����ʱ��
		double R_dRou;        //  ת�����ʰ뾶
		double R_dPsaiC;      //  ��ǰ���ߵĺ���
		double R_dDPsai;      //  ƫ���ǲ�
		double R_dDz;         //  ��ƫ��

		//  �ɻ�״̬���ף��룬���ȣ�
		double m_dTrip;     //  �г�
		double m_dTimeFly;  //  ����ʱ��
		double m_dAlti;     //  ��ǰ���θ߶�
		double m_dLati;     //  ��ǰγ��
		double m_dLongi;    //  ��ǰ����
		double m_dPsai;     //  ��ǰƫ����
		double m_dPitch;    //  ��ǰ������
		double m_dGama;     //  ��ǰ�¶�
		double m_dTAS;      //  ��ǰ�����
		double m_dGS;       //  ��ǰ����
		double m_dTeta;     //  ��ǰ�켣��

		double m_dRadiusBase_km;  //  ����ذ뾶

		//  �������ú���
		CRouteCurve RCurve;  //  ���ߺ��ߣ���Ĭ��ֵ��

		//  ��Բ����
		CRoute R;      //  ��ǰ���ú���
		CRoute RObj;   //  Ŀ�꺽�ߣ������ã��ɱ༭��
		CRoute RBase;  //  ���غ��ߣ�Ĭ�Ϻ��ߣ�

		//	CRoute RBaseC;  //  �����к���
		//	CRoute RBaseL;  //  ��������
		//	CRoute RBaseR;  //  �����Һ���

		//  ���ز���
		int RW_LandingType;
		double RW_alti_m;
		double RW_lati_rad;
		double RW_longi_rad;
		double RW_head_deg;

		//  ��������ָ��
		stPerformance *m_pPer;

	private:

		double m_dBankPlan;  //  �ƻ�ת���¶�
	};


}  //  namespace end


#endif
