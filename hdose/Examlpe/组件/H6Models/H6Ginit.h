// H6Ginit.h: interface for the H6Ginit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_H6GINIT_H__704E32ED_C7BA_42A2_A935_8B54F46ECCA4__INCLUDED_)
#define AFX_H6GINIT_H__704E32ED_C7BA_42A2_A935_8B54F46ECCA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class H6Ginit : public CEvt  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;

public:
	H6Ginit();
	virtual ~H6Ginit();
	static void ClassInit(ClassInfo *clsinfo);

	double m_longitude;//经度
	double m_latitude;//纬度
	double m_height;//高度

	double m_velocity;//速度

	double m_yaw;//俯仰角
	double m_roll;//偏航角


};

#endif // !defined(AFX_H6GINIT_H__704E32ED_C7BA_42A2_A935_8B54F46ECCA4__INCLUDED_)
