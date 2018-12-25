// AirSpeed.h: interface for the CAirSpeed class.
//
//////////////////////////////////////////////////////////////////////

#ifndef AirSpeed_H
#define AirSpeed_H

#include "BwVehicleKinematic.h"
#include "ISA.h"

namespace  BW_VEHICLEKINEMATIC {
	class CISA;
	class BW_VEHICLEKINEMATIC_API CAirSpeed  //  空速系统类
	{
	public:
		void refresh_AS( double h, double vaxb, double vayb, double vazb );
		double get_CASfromTAS(double h, double tas);
		void con_AirSpeed( CISA *p );  //  构造

		CAirSpeed();
		virtual ~CAirSpeed();

		double H;
		double tk, tk0;     //  静温和总温
		double p, p0;       //  静压和总压
		double p_p_h0;      //  与海平面压力比
		double rou;         //  静密度
		double rou_rou_h0;  //  密度比
		double q;           //  速压
		double Dp;          //  总静压差

		double TASmps;   //  真空速（m/s）
		double TASkmph;  //  真空速（km/h）
		double Mach;     //  马赫数
		double CASmps;   //  校正空速（m/s）
		double CASkmph;  //  校正空速（km/h）

		CISA *pISA;
		//private:
	};
}  //  namespace end
#endif
