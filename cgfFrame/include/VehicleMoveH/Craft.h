// Craft.h: interface for the CCraft class.
//
//////////////////////////////////////////////////////////////////////

#ifndef Craft_h
#define Craft_h

#include "BwVehicleKinematic.h"
#include "FCS.h"	// Added by ClassView
#include "FMS.h"	// Added by ClassView
#include "AirSpeed.h"	// Added by ClassView
#include "MyType.h"	// Added by ClassView
#include "Environment.h"	// Added by ClassView
#include "interface.h"	// Added by ClassView


namespace  BW_VEHICLEKINEMATIC {


#define NE 10
	class CFormationServer;
	class CFCS;
	class CFMS;
	class CAirSpeed;
	class CEnvironment;
	class CVector3;
	class CMatrix33;

	class  BW_VEHICLEKINEMATIC_API  CCraft  //  �����ࡣ�����ڹ̶���ɻ���ֱ������������½�س�����ˮ�洬ֻ��Ǳͧ��
	{
	public:
		//  ���ñ�ӷ�����
		void set_formation( bool b, int iPositionID, CFormationServer *pFormationServer );

		//  �����������
		void cal_AirSpeed( void );

		//  ���㺣��Ӱ��
		void cal_WavePara( void );

		//  �˶�����
		void motion_limit( void );

		//  ����
		void refueling( );

		//  �������к���
		void tick_craft( double Dt, double altiG_m );

		//  ���㸨������
		void cal_ParaAux( void );

		//  ����-�������ֺ���
		void RK4( int n, int io, double h, double*y, double*doy, double*b, double*c );

		//  ΢�ַ����飨�˶�ģ�ͣ�
		void dery( int n, double*y, double*doy );

		//  �Զ����ʼ������
		void ini_Craft( int iUnitID, double alti_m, double lati_deg, double longi_deg, double head_deg, double GroundSpeed_kmph, double teta_deg );

		//  ���乹������
		void con_Craft( CEnvironment *p, stPerformance stPerformanceData );

		CCraft();
		virtual ~CCraft();

		bool m_bFormationServerOK;  //  ��ӷ���������

		bool m_bInSurface;  //  �����˶���־���ɻ���ֱ�������ڵ������˶���Ǳͧ����ˮ�����˶���½��������ˮ�潢��������ˮ�����˶����˶������������ԣ�

		//  ������ֵ���ֵ�����
		double m_y[NE], m_doy[NE], m_b[NE], m_c[NE];

		//  ��������ָ��
		double  *pTime;       //  0: ����ʱ�� ( s )
		double  *pvg;         //  1: ���� ( m/s )
		double  *pTeta;       //  2: ���������� ( rad/s )
		double  *pPsais;      //  3: ����ƫ���� ( rad/s )
		double  *pGamas;      //  4: ������ת�� ( rad/s )
		double  *pxg;         //  5: ����λ���ڵ���ϵ x ���ͶӰ ( m )
		double  *pyg;         //  6: ����λ���ڵ���ϵ y ���ͶӰ ( m )
		double  *pzg;         //  7: ����λ���ڵ���ϵ z ���ͶӰ ( m )
		double  *pLongitude;  //  8: ���� ( rad )
		double  *pLatitude;   //  9: γ�� ( rad )

		double  *pTimed;       //  0: ����ʱ��仯�� ( s/s )
		double  *pvgd;         //  1: ���ٱ仯�� ( m/s/s )
		double  *pTetad;       //  2: ���������Ǳ仯�� ( rad/s/s )
		double  *pPsaisd;      //  3: ����ƫ���Ǳ仯�� ( rad/s/s )
		double  *pGamasd;      //  4: ������ת�Ǳ仯�� ( rad/s/s )
		double  *pxgd;         //  5: ����λ���ڵ���ϵ x ���ͶӰ�仯�� ( m/s )
		double  *pygd;         //  6: ����λ���ڵ���ϵ y ���ͶӰ�仯�� ( m/s )
		double  *pzgd;         //  7: ����λ���ڵ���ϵ z ���ͶӰ�仯�� ( m/s )
		double  *pLongituded;  //  8: ���� ( rad )
		double  *pLatituded;   //  9: γ�� ( rad )

		double m_dHeading;  //  �溽�� ( deg )

		double m_dvgv;  //  ��ֱ���٣�m/s
		double m_dvgh;  //  ����ˮƽ������m/s
		double m_dsH;   //  ˮƽ�溽��������m
		double m_ds;    //  ����������m

		double m_dRemainDistance_km;  //  ʣ����о���
		double m_dRemainTime;      //  ʣ�����ʱ�䣨s��

		bool m_bCraftReady;  //  �ɻ�׼����

		int m_iCrash;  //  ײ�ٱ���

		//  ���˶Դ�����Ӱ�졣2017-02-25��26��
		double m_dE_WaveSpeed;  //  ���٣���/�룩2017-07-15
		double m_dE_WaveLenth;  //  �������ף�   2017-07-15
		double m_dE_WaveOmg;    //  ��Ƶ��   ( rad/s )
		double m_dE_WaveHd;     //  �������� ( m/s )
		double m_dE_WaveH;      //  ������   ( m   )
		double m_dE_WavePitch;  //  ������   ( rad )
		double m_dE_WaveBank;   //  ��ת��   ( rad )

		//  ����������2017-09-12��
		double m_dAir_speed;  //  �Կ����ٶ�( m/s )
		double m_dAir_teta;   //  �Կ����켣��( rad )
		double m_dAir_psai;   //  �Կ���ƫ����( rad )

		//  �Ӿ������
		double m_dEye_Alti;
		double m_dEye_Lati;
		double m_dEye_Longi;
		double m_dEye_Pitch;
		double m_dEye_Gama;
		double m_dEye_Psai;

		//  ���п��Ʊ���
		double m_dnxO;  //  ��ǰ���ر�
		double m_dnyO;  //  ��ǰ�����������
		double m_dnzO;  //  ��ǰ�������

		double m_dStep;  //  ���ֲ���

		//	int m_iVehicleType;  //  ��������

		//  ������������
		//	double m_dTimeEquivalence;  //  ��������ʱ��
		double m_dEnergyRemain;  //  ʣ��������%��

		double m_dq0;  //  ��Сȼ������
		double m_dkq_n;  //  ȼ�Ͷ�����������ϵ��

		//  ���Ի�������ϵͳ
		//	CFormationServer *m_pFormationServer;  //  ��ӷ�����ָ��
		CFormationServer *m_pFormationServer;  //  ��ӷ�����ָ��

		CFMS          m_cFMS;           //  �ɹ�ϵͳ
		CFCS          m_cFCS;           //  �ɿ�ϵͳ
		CAirSpeed     m_cAS;            //  ����ϵͳ
		stPerformance m_cPerformance;   //  ���ܲ���
		CEnvironment  *m_pEnvironment;  //  ������ָ��

		//  �����ڻ�Ⱥ�е�λ�úš�2017-12-17
		int m_iPositionID;

		//  ����ʶ��š�2017-12-17
		int m_iUnitID;

	private:

		//  �������������Ϊ��ĸ�����伸�β�������
		//  ��½�ܵ�������������
		double m_dLandingHead;  //  ��½�ܵ���������ڽ������ᣩ

		double m_dxBlocks[4];  //  ����������λ�ã���½�ܵ�����ϵ��
		double m_dzBlock;      //  �������������꣨��½�ܵ�����ϵ���ԳƲ��ã�
		double m_dyBlock;      //  ��������װ�߶�

		CVector3  m_rORWLD;  //  ��½�ܵ�����ϵԭ���ں�ĸ����ϵ������
		CMatrix33 m_MC_CRW;  //  ��ĸ����ϵ����½�ܵ�ϵ������ת������

		//  ������ʼ�յ�λ�ã�����ϵ��

		//  ��ĸ�װ�ˮƽ��������
		double m_dXs[7];
		double m_dZLs[7];
		double m_dZRs[7];
	};

#undef NE

}  //  namespace end

#endif
