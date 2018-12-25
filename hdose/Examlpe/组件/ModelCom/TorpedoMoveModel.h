//TorpedoMoveModel.h: interface for the CTorpedoMoveModel module.
//!!HDOSE_CLASS(CTorpedoMoveModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoMoveModel_H)
#define AFX_TorpedoMoveModel_H

#include "Model.h"
#include "LatLonH.h"

//{{HDOSE_CLS_DES(CTorpedoMoveModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CTorpedoMoveModel /*鱼雷运动模型*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CTorpedoMoveModel();
	virtual ~CTorpedoMoveModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CTorpedoMoveModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CTorpedoMoveModel)
	void	OnEntityMoveOrderEvt(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CTorpedoMoveModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTorpedoMoveModel)
	//}}HDOSE_ATTRIBUTE
private:
	double RE;
	double AzimuthCalculate(CLatLonH  selfPos,CLatLonH  targetPos);//计算方位
	void MovePosCalculate(CLatLonH currentPos,CLatLonH & nextPos,double velocity,//计算下一个位置信息
		double pitch,double course,double dT);
	double SurfaceDistance(CLatLonH  selfPos,CLatLonH  targetPos);//计算两点之间的距离
};

#endif
