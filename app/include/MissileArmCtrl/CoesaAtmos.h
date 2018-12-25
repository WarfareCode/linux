// CoesaAtmos.h: interface for the CCoesaAtmos class.
//
//////////////////////////////////////////////////////////////////////
// 1976年COESA大气模型
// 可计算85km之内的大气温度、密度及声速

#ifndef	COESA_ATMOSPHERE_H_
#define	COESA_ATMOSPHERE_H_

#define NUM1976PTS 8

class CCoesaAtmos
{
public:
    CCoesaAtmos();
    CCoesaAtmos(double Tc);
    ~CCoesaAtmos() {};
	
private:
    double Sonic;       // 声速（m/s）
    double Rho;         // 空气密度（Kg/m^3）
    double Tk;          // 温度（开氏温标）
	double pressure;    // 压强，单位：N/m^2
	
	
public:
    void Init();
    void SetTc(double Tc);              // 设置温度，单位：摄氏度
    void Update(double Altitude);       // 更新指定高度(单位：米)的大气数据
    double GetSonic(double Altitude);   // 获取指定高度(单位：米)的声速，（m/s）
    double GetRho(double Altitude);     // 获取指定高度(单位：米)的大气密度，（Kg/m^3）
    double GetTk(double Altitude);      // 获取指定高度(单位：米)的温度，（开氏温标）
	double GetPre(double Altitude);      // 获取指定高度(单位：米)的压强，单位：N/m^2
	
private:
    double temperature76[8];//NUM1976PTS
    double pressureRatio76[8];//NUM1976PTS
    double altitude76[8];//NUM1976PTS
    double tempGradient76[8];//NUM1976PTS
};

#endif	// COESA_ATMOSPHERE_H_
