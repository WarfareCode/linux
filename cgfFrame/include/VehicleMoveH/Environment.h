// Environment.h: interface for the CEnvironment class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "BwVehicleKinematic.h"
#include "ISA.h"	// Added by ClassView
#include "MyType.h"	// Added by ClassView


namespace  BW_VEHICLEKINEMATIC {


	//  ���ر�ʶ
	enum IDRW
	{
		ID_RW_Any,         //  ����
		ID_RW_CarrierTO,   //  ��ĸ��ɵ�
		ID_RW_CarrierLD,   //  ��ĸ�Ž���
		ID_RW_Dachang04,   //  ��04
		ID_RW_Dachang22,   //  ��22
		ID_RW_Yanliang06,  //  ����06
		ID_RW_Yanliang24,  //  ����24
	};

	class CISA;

	class  BW_VEHICLEKINEMATIC_API CEnvironment  //  ������
	{
	public:

		//  ���÷糡
		void set_WindSpeed( double w_mps );
		void set_WindHead(  double head_deg );
		void set_WindPitch( double pitch_deg );

		//  ���ú������˸ߣ�
		void set_waveClass( int iWaveClass );
		void set_waveHead( double head_deg );
		void set_waveLength( double wave_len);	//xks
		void set_waveSpeed(double wave_speed=30);		//xks

		//  ��������
		void tick_Environment( double Dt );

		//  ��ʼ��
		void ini_Environment( double time, double _RW_alti_m, double _RW_lati_deg, double _RW_longi_deg, double _RW_head_deg );

		//  ���乹��
		void con_Environment(void);

		CEnvironment();
		virtual ~CEnvironment();

		//  ���ز���
		double RW_alti;   //  ����
		double RW_lati;   //  γ��
		double RW_longi;  //  ����
		double RW_head;   //  ����

		//  ���˲���
		int m_iWaveClass;    //  �������� 0 - 9 ��
		double m_dWaveAObj;     //  ���˷��ȣ� 0m ~ 20m ��
		double m_dWaveACur;     //  ���˷��ȣ� 0m ~ 20m ��
		double m_dWavePsaiObj;  //  ����ƫ���ǣ� -Pi ~ Pi ��
		double m_dWavePsaiCur;  //  ����ƫ���ǣ� -Pi ~ Pi ��
		double	m_WaveLength;	// ���˲�����xks
		double m_WaveSpeed;		// �����ٶȣ�m/s����xks��Ĭ��30m/s,ָ���Ǻ��˱��洫���ٶȣ��������޸�

		//  �糡����
		double m_dWindPitch_deg;  //  ���������ĸ�����
		double m_dWindHead_deg;   //  ���������ĺ���
		double m_dWindSpeed_mps;  //  ����������ģ

		double m_dWindSpeed_x;  //  ������٣�m/s��
		double m_dWindSpeed_y;  //  ������٣�m/s��
		double m_dWindSpeed_z;  //  ������٣�m/s��

		//  ����ʱ��
		double m_dTimeE;

		//  ��������
		CISA  m_cAIR;  //  ��׼����

	private:
	};

}  //  namespace end

#endif
