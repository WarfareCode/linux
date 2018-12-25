// Environment.h: interface for the CEnvironment class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "BwVehicleKinematic.h"
#include "ISA.h"	// Added by ClassView
#include "MyType.h"	// Added by ClassView


namespace  BW_VEHICLEKINEMATIC {


	//  基地标识
	enum IDRW
	{
		ID_RW_Any,         //  任意
		ID_RW_CarrierTO,   //  航母起飞点
		ID_RW_CarrierLD,   //  航母着舰点
		ID_RW_Dachang04,   //  大场04
		ID_RW_Dachang22,   //  大场22
		ID_RW_Yanliang06,  //  阎良06
		ID_RW_Yanliang24,  //  阎良24
	};

	class CISA;

	class  BW_VEHICLEKINEMATIC_API CEnvironment  //  环境类
	{
	public:

		//  设置风场
		void set_WindSpeed( double w_mps );
		void set_WindHead(  double head_deg );
		void set_WindPitch( double pitch_deg );

		//  设置海况（浪高）
		void set_waveClass( int iWaveClass );
		void set_waveHead( double head_deg );
		void set_waveLength( double wave_len);	//xks
		void set_waveSpeed(double wave_speed=30);		//xks

		//  单步运行
		void tick_Environment( double Dt );

		//  初始化
		void ini_Environment( double time, double _RW_alti_m, double _RW_lati_deg, double _RW_longi_deg, double _RW_head_deg );

		//  补充构造
		void con_Environment(void);

		CEnvironment();
		virtual ~CEnvironment();

		//  基地参数
		double RW_alti;   //  海拔
		double RW_lati;   //  纬度
		double RW_longi;  //  经度
		double RW_head;   //  航向

		//  海浪参数
		int m_iWaveClass;    //  海况级别（ 0 - 9 ）
		double m_dWaveAObj;     //  海浪幅度（ 0m ~ 20m ）
		double m_dWaveACur;     //  海浪幅度（ 0m ~ 20m ）
		double m_dWavePsaiObj;  //  风浪偏航角（ -Pi ~ Pi ）
		double m_dWavePsaiCur;  //  风浪偏航角（ -Pi ~ Pi ）
		double	m_WaveLength;	// 风浪波长，xks
		double m_WaveSpeed;		// 风浪速度（m/s），xks，默认30m/s,指的是海浪表面传播速度，不建议修改

		//  风场参数
		double m_dWindPitch_deg;  //  风速向量的俯仰角
		double m_dWindHead_deg;   //  风速向量的航向
		double m_dWindSpeed_mps;  //  风速向量的模

		double m_dWindSpeed_x;  //  北向风速（m/s）
		double m_dWindSpeed_y;  //  天向风速（m/s）
		double m_dWindSpeed_z;  //  东向风速（m/s）

		//  运行时间
		double m_dTimeE;

		//  空气环境
		CISA  m_cAIR;  //  标准大气

	private:
	};

}  //  namespace end

#endif
