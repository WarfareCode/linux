

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LineObj.h"
#include "TankDisplayDlg.h"


class  __declspec(dllexport) CTank:	public CNode  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	

	CTank(void);
	virtual ~CTank();
	static void ClassInit(ClassInfo *clsinfo);
	virtual void OnInit();
	virtual void OnSetParameter(char *name,char *value);

	virtual void tick(double time);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double GetLatitude(){return m_latitude;}
	double GetLongitude(){return m_longitude;}

	void SetLatitude(double	val){m_latitude=val;}
	void SetLongitude(double val){m_longitude=val;}


protected:
	double RE;
	CTankDisplayDlg m_dlg;
	
	double m_latitude;
	double m_longitude;
	double m_velocity;
	double m_heading;
	


	int m_pointIndex;//当前的目的点是Lineobj中的哪个点
	CLatLonH m_disPoint;//下一时刻目的点
	bool m_bmoveToDisPoint;//判断是否到达目的点

	double AzimuthCalculate(CLatLonH  selfPos,CLatLonH  targetPos);//计算方位
	void MovePosCalculate(CLatLonH currentPos,CLatLonH & nextPos,double velocity,//计算下一个位置信息
		double pitch,double course,double dT);
	double SurfaceDistance(CLatLonH  selfPos,CLatLonH  targetPos);//计算两点之间的距离

};

