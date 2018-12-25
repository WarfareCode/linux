// Actuator.h: interface for the CActuator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTUATOR_H__A2A10F84_CB7B_4C52_B341_346B9A58EBA8__INCLUDED_)
#define AFX_ACTUATOR_H__A2A10F84_CB7B_4C52_B341_346B9A58EBA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Model.h"

class HYCGF_API CActuator : public CModel  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
	static void ClassInit(ClassInfo *clsinfo);
public:
	CActuator();
	virtual ~CActuator();

};

#endif // !defined(AFX_ACTUATOR_H__A2A10F84_CB7B_4C52_B341_346B9A58EBA8__INCLUDED_)
