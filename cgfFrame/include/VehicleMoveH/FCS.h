// FCS.h: interface for the CFCS class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FCS_H
#define FCS_H

#include "BwVehicleKinematic.h"
#include "interface.h"	// Added by ClassView
#include "FMS.h"
#include "AirSpeed.h"
//#include "Filter.h"	// Added by ClassView
#include "MyType.h"


namespace  BW_VEHICLEKINEMATIC {

	class CFormationServer;
	class CFCS;
	class CFMS;

	class  BW_VEHICLEKINEMATIC_API CFCS  //  ���п���ϵͳ�ࣨ��������ϵͳ�ࣩ���Ƕ�Ĭ�ϵ�λ����
	{
	public:
		//  ��ӷ�����ָ�븳ֵ
		void set_formation( bool b, int iPositionID, CFormationServer *pFormationServer );

		//  �������
		void guide_by_fire_ctrol( double v_kmph, double alti_m, double heading_deg );

		void heli_ctrl_yaw( double _percent );  //  ֱ����ƫ�����ʿ���
		void heli_ctrl_vz( double _percent );   //  ֱ�����������ʿ���
		void heli_ctrl_vy( double _percent );   //  ֱ�����������ʿ���
		void heli_ctrl_vx( double _percent );   //  ֱ�����������ʿ���

		//  �趨Ŀ���ٶ�
		void set_AP_speed( double speed_mps );
		void set_AP_speed_i( int speed_percent );

		//  �趨Ŀ�긩����
		void set_AP_pitch( double pitch_deg );
		void set_AP_pitch_i( int pitch_percent );

		//  �趨Ŀ��߶�
		void set_AP_pitch_alti( double alti_m );
		void set_AP_pitch_alti_i( int alti_percent );

		//  �趨Ŀ���¶�
		void set_AP_bank( double bank_deg );
		void set_AP_bank_i( int bank_percent );

		//  �趨Ŀ�꺽�򡪡���ת��
		void set_AP_bank_psai( double psai_deg );
		void set_AP_bank_psai_i( int psai_percent );

		//  �趨Ŀ�꺽�򡪡�ƫ����
		void set_AP_yaw_psai( double psai_deg );
		void set_AP_yaw_psai_i( int psai_percent );

		//  �趨Ŀ�꺽�򡪡�����ת����
		void set_AP_turning_psai( double psai_deg );
		void set_AP_turning_psai_i( int psai_percent );

		//  �������к���
		void tick_FCS( double Dt, double altiG_m, double vd_mpsps, double v_mps, double altid_mps, double alti_m,
			double pitchd_degps, double pitch_deg, double bankd_degps, double bank_deg, double psaid_degps, double psai_deg );

		void SwitchAP_fire_control( bool b );  //  ��ؽ�ͨ����

		void SwitchAP_turning_psai_format( bool b );  //  ����ת����AP����ӿ��ء�������λ�ÿ���
		void SwitchAP_turning_psai_NAV( bool b );     //  ����ת����AP��ˮƽ��������
		void SwitchAP_turning_psai( bool b );         //  ����ת����AP�����򱣳ֿ���

		void SwitchAP_yaw_psai_format( bool b );  //  ƫ����AP����ӿ��ء�������λ�ÿ���
		void SwitchAP_yaw_psai_NAV( bool b );     //  ƫ����AP��ˮƽ��������
		void SwitchAP_yaw_psai( bool b );         //  ƫ����AP�����򱣳ֿ���

		void SwitchAP_bank_psai_format( bool b );  //  ��ת��AP����ӿ��ء�������λ�ÿ��ƣ�
		void SwitchAP_bank_psai_NAV( bool b );     //  ��ת��AP��ˮƽ��������
		void SwitchAP_bank_psai( bool b );         //  ��ת��AP�����򱣳ֿ���
		void SwitchAP_bank( bool b );              //  ��ת��AP���¶ȱ��ֿ���

		void SwitchAP_pitch_alti_format( bool b );  //  ������AP����ӿ��ء�������λ�ÿ���
		void SwitchAP_pitch_alti_NAV( bool b );     //  ������AP����ֱ��������
		void SwitchAP_pitch_alti( bool b );         //  ������AP���߶ȱ��ֿ���
		void SwitchAP_pitch( bool b );              //  ������AP���������ֿ���

		void SwitchAP_speed_format( bool b );  //  �ٶ���AP����ӿ��ء���ǰ��λ�ÿ���
		void SwitchAP_speed_NAV( bool b );     //  �ٶ���AP���ٶȵ�������
		void SwitchAP_speed( bool b );         //  �ٶ���AP���ٶȱ��ֿ���

		//  ����ת�����ʿ���
		void ctrl_k_turning( double _percent );

		//  ��ת�����ʿ���
		void ctrl_roll( double _percent );

		//  ������ؿ���
		void ctrl_n_side( double _percent );

		//  ������ؿ���
		void ctrl_n_normal( double _percent );

		//  ���رȿ���
		void ctrl_engine_brake( double _percent );

		//  ��ʼ��
		void ini_FCS( int iUnitID, double time0, double v_mps, double alti_m );

		//  ���乹��
		void con_FCS( stPerformance *pPerformance, CFMS *pFMS, CAirSpeed *pAS );

		CFCS();
		virtual ~CFCS();

		bool m_bFormationServerOK;  //  ��ӷ���������

		bool m_bFixed;  //  �������������ǵ�����ϵ�����̶���

		//  ���ָ��
		double m_dFC_v, m_dFC_alti, m_dFC_psai;

		//  �ٶ���ĸ���AP����
		bool m_bAP_speed;         //  �ٶȱ���
		bool m_bAP_speed_NAV;     //  �ٶȵ���
		bool m_bAP_speed_format;  //  ��ӡ�������λ��

		//  ������ĸ���AP����
		bool m_bAP_pitch;              //  �����Ǳ���
		bool m_bAP_pitch_alti;         //  �߶ȱ���
		bool m_bAP_pitch_alti_NAV;     //  ��ֱ����
		bool m_bAP_pitch_alti_format;  //  ��ӡ�������λ��

		//  ��ת��ĸ���AP����
		bool m_bAP_bank;              //  �¶ȱ���
		bool m_bAP_bank_psai;         //  ���򱣳�
		bool m_bAP_bank_psai_NAV;     //  ˮƽ����
		bool m_bAP_bank_psai_format;  //  ��ӡ�������λ��

		//  ƫ����ĸ���AP���أ���Ҫ����X�ε�����
		bool m_bAP_yaw_psai;         //  ���򱣳�
		bool m_bAP_yaw_psai_NAV;     //  ˮƽ����
		bool m_bAP_yaw_psai_format;  //  ��ӡ�������λ��

		//  ����ת����ĸ���AP���أ�����½���������˶����ɻ����滬�У�
		bool m_bAP_turning_psai;         //  ���򱣳�
		bool m_bAP_turning_psai_NAV;     //  ˮƽ����
		bool m_bAP_turning_psai_format;  //  ��ӡ�������λ��

		bool m_bAP_fire_control;   //  ��ؽ�ͨ

		//  ����AP����Ŀ��;
		int m_iAPObj_speed;      //  �����ٶȣ�0��100��

		int m_iAPObj_pitch;       //  ���͸����ǣ�-100��100��
		int m_iAPObj_pitch_alti;  //  ���͸߶ȣ�-100��100��

		int m_iAPObj_bank;       //  ����Ŀ���ת�ǣ�-100��100��
		int m_iAPObj_bank_psai;  //  ����Ŀ��ƫ���ǣ�-100��100��

		int m_iAPObj_yaw_psai;   //  ����Ŀ��ƫ���ǣ�-100��100��

		int m_iAPObj_turning_psai;   //  ����Ŀ��ƫ���ǣ�-100��100��

		//  ����ֱ�ӿ�������-100��100��
		int m_iCMD_engine_brake;   //  ������ɲ����
		int m_iCMD_n_normal;       //  �������������ֱ�������ã�
		int m_iCMD_n_side;         //  �������
		int m_iCMD_RollRate;       //  ��ת����
		int m_iCMD_k_turning;      //  ����ת�����ʣ�ͨ��������ת�䣩

		//  ����ֱ�ӿ���������ֱ����ģʽ
		int m_iCMD_YawRate;  //  ƫ�����ʣ�-100��100��
		int m_iCMD_vx;       //  ǰ���˶��ٶȣ�-100��100��
		int m_iCMD_vy;       //  �����˶��ٶȣ�-100��100��
		int m_iCMD_vz;       //  �����˶��ٶȣ�-100��100��

		//  AP����Ŀ��
		double m_dAPObj_speed;  //  Ŀ���ٶ�

		double m_dAPObj_pitch;       //  Ŀ�긩����
		double m_dAPObj_pitch_alti;  //  Ŀ��߶�

		double m_dAltiG0, m_dAltiG1;  //  ǰ����֡�����ڵ���ͶӰ��ĺ��θ߶ȣ����θ߶ȣ�
		double m_dHdG_i, m_dHdG;  //  ��������ٶȣ��˲�ǰ��
		double m_dHR;  //  �״�߶�

		double m_dAPObj_bank;       //  Ŀ���ת��
		double m_dAPObj_bank_psai;  //  Ŀ��ƫ���ǣ���ת�ᣩ

		double m_dAPObj_yaw_psai;  //  Ŀ��ƫ���ǣ�ƫ���ᣩ

		double m_dAPObj_turning_psai;  //  Ŀ��ƫ���ǣ�����ת���ᣩ

		//  ֱ�ӷ��п���
		double m_dCMD_engine_brake;  //  ������ɲ����
		double m_dCMD_n_normal;      //  �������������ֱ�������ã�
		double m_dCMD_n_side;        //  �������
		double m_dCMD_RollRate;      //  ��ת����
		double m_dCMD_k_turning;     //  ˮƽת�����ʣ�ͨ��������ʵʩ����ת�䣩

		//  ���ٿ��ƣ�ֱ����ģʽ������ģʽ��
		double m_dCMD_YawRate;  //  ƫ������
		double m_dCMD_vx;       //  ǰ���˶�����
		double m_dCMD_vy;       //  �����˶�����
		double m_dCMD_vz;       //  �����˶�����

		//  ��ƫ���ǰ��֡������
		double m_dDz0, m_dDz1, m_dDzd;

		//  ʱ��
		double m_dTime;
		double m_dT_defix;  //  �����ʱ

		//  �����ڻ�Ⱥ�е�λ�ú�
		int m_iPositionID;

		//  ����ʶ���
		int m_iUnitID;

		//  ���ϵͳ
		CFormationServer *m_pFormationServer;  //  ��ӷ�����ָ��

		CFMS          *m_pFMS;  //  �ɹ�ϵͳָ��
		CAirSpeed     *m_pAS;   //  ����ϵͳָ��

		stPerformance *m_pPer;  //  �������ݰ�ָ��

	private:

		double m_dTFilter_HdG;  //  ��������˲���ʱ�䳣��

	};


}  //  namespace end


#endif
