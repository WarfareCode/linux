// ISA.h: interface for the CISA class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ISA_H 
#define ISA_H

#include "BwVehicleKinematic.h"

namespace  BW_VEHICLEKINEMATIC {


	class BW_VEHICLEKINEMATIC_API CISA  
	{
	public:
		CISA();
		virtual ~CISA();

		double get_rou0();
		double get_R   (void);
		double get_k   (void);
		double get_a0  (void);
		double get_p0  (void);
		double get_p   (double h);
		double get_a   (double h);
		double get_rou (double h);
		double get_tk  (double h);

	private:
		double tk;
		double p;
		double rou;
		double a;
		double a0;

		double p20;
		double p11;
		double p0;

		double rou20;
		double rou11;
		double rou0;

		double tk11;
		double tk0;

		double coa;

		double k;  //  空气的比热容比
		double R;  //  空气的气体常数
	};


}  //  namespace end


#endif
