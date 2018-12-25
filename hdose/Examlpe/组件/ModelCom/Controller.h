// Controller.h: interface for the CController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLLER_H__5E260067_E4C0_4897_838C_407E2CF58588__INCLUDED_)
#define AFX_CONTROLLER_H__5E260067_E4C0_4897_838C_407E2CF58588__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Model.h"

class MODELCOM_API CController : public CModel  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
	static void ClassInit(ClassInfo *clsinfo);
public:
	CController();
	virtual ~CController();

};

#endif // !defined(AFX_CONTROLLER_H__5E260067_E4C0_4897_838C_407E2CF58588__INCLUDED_)
