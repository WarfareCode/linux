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
	double m_t;//t����ʱ��;

	double m_nx,m_ny,m_nz;//�ֱ�Ϊ�������,������غ��������

	double m_z,m_r,m_v;//m_z�����߶�,m_r����ľ���,m_v�ٶ�

	double m_pitching,m_yaw;//pitching������,yawƫ����

	double m_longitude,m_latitude;//����,γ��

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
