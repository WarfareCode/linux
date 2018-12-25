// Platform.h: interface for the CPlatform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Platform_H__F6933E82_2038_11D5_A51E_00055D05A3E4__INCLUDED_)
#define AFX_Platform_H__F6933E82_2038_11D5_A51E_00055D05A3E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//##ModelId=3AC98B1C0066

DECLARE_DA(double,16);
class CPlatform : public CNode  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	int OrientedtoDes();
	void DestineTo(double x,double y);
	virtual void OnInit();

	double m_longitude;//经度
	double m_latitude;//纬度
	double m_height;//高度

	double m_velocity;//速度

	double m_pitching;//俯仰角
	double m_yaw;//偏航角

	char m_dat[10];
	char* m_ph;
	DA_double m_doubleda;
	DataBlock m_block;


	//##ModelId=3AC98B1C00A0
	double m_desx;
	double m_desy;
	//##ModelId=3AC98B1C00A3 
	virtual void tick(double time);
	//##ModelId=3AC98B1C00A6
	virtual void Simulation(double lasttime);
	virtual void OnReflect(char *Para);
	bool m_hasdes;

protected:
	//##ModelId=3AC98B1C00D4
	CPlatform();
	//##ModelId=3AC98B1C00D5
	virtual ~CPlatform();
	virtual void Output();
	//##ModelId=3AC98B1C00D9
	static void ClassInit(ClassInfo *clsinfo);
};

#endif // !defined(AFX_Platform_H__F6933E82_2038_11D5_A51E_00055D05A3E4__INCLUDED_)
