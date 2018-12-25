//FCControllerModel.h: interface for the CFCControllerModel module.
//!!HDOSE_CLASS(CFCControllerModel,CController)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FCControllerModel_H)
#define AFX_FCControllerModel_H

//{{HDOSE_CLS_DES(CFCControllerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CFCControllerModel /*火力打击控制器*/ : public CController 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CFCControllerModel();
	virtual ~CFCControllerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CFCControllerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CFCControllerModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CFCControllerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CFCControllerModel)
	//}}HDOSE_ATTRIBUTE
};

/*
//岸导发射的导弹
extern TFCOMMONMODELCOM_API int launchedYJ62AMissileCount;
extern TFCOMMONMODELCOM_API int launchedYJ62HMissileCount;
extern TFCOMMONMODELCOM_API int launchedYJ62AGMissileCount;
extern TFCOMMONMODELCOM_API int launchedAPWMissileCount;

//飞机发射的导弹
extern TFCOMMONMODELCOM_API int totalA2ACountRed;//红方空空导弹发射数量
extern TFCOMMONMODELCOM_API int totalA2ACountBlue;//蓝方空空导弹发射数量
extern TFCOMMONMODELCOM_API int launchedYJ83KMissileCount;//YJ83K导弹发射数量
extern TFCOMMONMODELCOM_API int launchedYJ83KGMissileCount;//YJ83K改导弹发射数量
extern TFCOMMONMODELCOM_API int launchedYJ83KML8MissileCount;//YJ83KML8导弹发射数量
extern TFCOMMONMODELCOM_API int launchedYJ12MissileCount;//YJ12导弹发射数量
extern TFCOMMONMODELCOM_API int launchedYJ88MissileCount;//YJ88导弹发射数量
extern TFCOMMONMODELCOM_API int launchedYJ91MissileCount;//YJ91导弹发射数量
extern TFCOMMONMODELCOM_API int totalBlueAAMCount;

//舰艇发射的导弹
extern TFCOMMONMODELCOM_API int totalSM1Count;
extern TFCOMMONMODELCOM_API int totalSM2Count;
extern TFCOMMONMODELCOM_API int totalHKCount;
extern TFCOMMONMODELCOM_API int totalSeaSparrowCount;
extern TFCOMMONMODELCOM_API int launchedYJ83JMissileCount;

//潜艇发射的导弹
extern TFCOMMONMODELCOM_API int launchedYJ18MissileCount;
extern TFCOMMONMODELCOM_API int launchedClubMissileCount;


extern TFCOMMONMODELCOM_API int RedTorpedoEntityNum;
extern TFCOMMONMODELCOM_API int BlueTorpedoEntityNum;
extern TFCOMMONMODELCOM_API routInfo myInfo[100];
extern TFCOMMONMODELCOM_API int  infoCount; 
*/

#endif
