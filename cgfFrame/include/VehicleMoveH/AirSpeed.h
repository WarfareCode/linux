// AirSpeed.h: interface for the CAirSpeed class.
//
//////////////////////////////////////////////////////////////////////

#ifndef AirSpeed_H
#define AirSpeed_H

#include "BwVehicleKinematic.h"
#include "ISA.h"

namespace  BW_VEHICLEKINEMATIC {
	class CISA;
	class BW_VEHICLEKINEMATIC_API CAirSpeed  //  ����ϵͳ��
	{
	public:
		void refresh_AS( double h, double vaxb, double vayb, double vazb );
		double get_CASfromTAS(double h, double tas);
		void con_AirSpeed( CISA *p );  //  ����

		CAirSpeed();
		virtual ~CAirSpeed();

		double H;
		double tk, tk0;     //  ���º�����
		double p, p0;       //  ��ѹ����ѹ
		double p_p_h0;      //  �뺣ƽ��ѹ����
		double rou;         //  ���ܶ�
		double rou_rou_h0;  //  �ܶȱ�
		double q;           //  ��ѹ
		double Dp;          //  �ܾ�ѹ��

		double TASmps;   //  ����٣�m/s��
		double TASkmph;  //  ����٣�km/h��
		double Mach;     //  �����
		double CASmps;   //  У�����٣�m/s��
		double CASkmph;  //  У�����٣�km/h��

		CISA *pISA;
		//private:
	};
}  //  namespace end
#endif
