#ifndef __CPlaMove_H
#define __CPlaMove_H

//#include "CModel.h"

struct CdoublePoint
{
	double x;
	double y;
	CdoublePoint()
	{
	};
	CdoublePoint(CdoublePoint &p)
	{
		x=p.x;
		y=p.y;
	};

	int compare(CdoublePoint &p,double r=0.00004)
	{
		if((fabs(p.x-x)<r)&&(fabs(p.y-y)<r))
			return 0;
		return 1;
	}
	CdoublePoint(double x1,double y1)
	{
		x=x1;
		y=y1;
	}
};


class CPlaMove:public CNode
{
	DECLARE_CREATE

private:
	double DT;
	double m_t;//t飞行时间;

	double m_nx,m_ny,m_nz;//分别为切向过载,横向过载和纵向过载

	double m_z,m_r,m_v;//m_z距地面高度,m_r距地心距离,m_v速度

	double m_pitching,m_yaw;//pitching俯仰角,yaw偏航角

	double m_longitude,m_latitude;//经度,纬度

public:
	CPlaMove();

	void OnInit();
	double getlongitude();
	double getlatitude();
	double getpitching();
	double getyaw();
	double getz();
	double getv();
	double gettime();
	void fly(double nx,double ny,double nz);
	void tick(double time);
};



#endif
