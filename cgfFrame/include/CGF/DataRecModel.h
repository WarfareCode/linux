//DataRecModel.h: interface for the CDataRecModel module.
//!!HDOSE_CLASS(CDataRecModel,CModel)
//////////////////////////////////////////////////////////////////////

/* Note: xks，20161214
此类为数据记录模型的基类，由于数据记录模型为全局对象，因此为了在想定重载后，数据记录对象清空其中的数据；
会接收到想定重载的事件，当想定重载时，清空上一次的数据。
但该事件的响应函数为虚函数，没有写入任何处理内容，子类应当重写接收后的处理内容。
*/


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DataRecModel_H)
#define AFX_DataRecModel_H

#include "Model.h"


//{{HDOSE_CLS_DES(CDataRecModel)
/*
Author:		xks
Version:	1.0
Descript:	专用于数据记录的模型父类
*/
//}}HDOSE_CLS_DES

class HYCGF_API CDataRecModel /*数据记录模型*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CDataRecModel();
	virtual ~CDataRecModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CDataRecModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CDataRecModel)
	virtual void	OnScnReloadEvt(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CDataRecModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CDataRecModel)
	//}}HDOSE_ATTRIBUTE

};

#endif
