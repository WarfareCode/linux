

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
	


	int m_pointIndex;//��ǰ��Ŀ�ĵ���Lineobj�е��ĸ���
	CLatLonH m_disPoint;//��һʱ��Ŀ�ĵ�
	bool m_bmoveToDisPoint;//�ж��Ƿ񵽴�Ŀ�ĵ�

	double AzimuthCalculate(CLatLonH  selfPos,CLatLonH  targetPos);//���㷽λ
	void MovePosCalculate(CLatLonH currentPos,CLatLonH & nextPos,double velocity,//������һ��λ����Ϣ
		double pitch,double course,double dT);
	double SurfaceDistance(CLatLonH  selfPos,CLatLonH  targetPos);//��������֮��ľ���

};

