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

class TFCOMMONMODELCOM_API CFCControllerModel /*�������������*/ : public CController 
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
//��������ĵ���
extern TFCOMMONMODELCOM_API int launchedYJ62AMissileCount;
extern TFCOMMONMODELCOM_API int launchedYJ62HMissileCount;
extern TFCOMMONMODELCOM_API int launchedYJ62AGMissileCount;
extern TFCOMMONMODELCOM_API int launchedAPWMissileCount;

//�ɻ�����ĵ���
extern TFCOMMONMODELCOM_API int totalA2ACountRed;//�췽�տյ�����������
extern TFCOMMONMODELCOM_API int totalA2ACountBlue;//�����տյ�����������
extern TFCOMMONMODELCOM_API int launchedYJ83KMissileCount;//YJ83K������������
extern TFCOMMONMODELCOM_API int launchedYJ83KGMissileCount;//YJ83K�ĵ�����������
extern TFCOMMONMODELCOM_API int launchedYJ83KML8MissileCount;//YJ83KML8������������
extern TFCOMMONMODELCOM_API int launchedYJ12MissileCount;//YJ12������������
extern TFCOMMONMODELCOM_API int launchedYJ88MissileCount;//YJ88������������
extern TFCOMMONMODELCOM_API int launchedYJ91MissileCount;//YJ91������������
extern TFCOMMONMODELCOM_API int totalBlueAAMCount;

//��ͧ����ĵ���
extern TFCOMMONMODELCOM_API int totalSM1Count;
extern TFCOMMONMODELCOM_API int totalSM2Count;
extern TFCOMMONMODELCOM_API int totalHKCount;
extern TFCOMMONMODELCOM_API int totalSeaSparrowCount;
extern TFCOMMONMODELCOM_API int launchedYJ83JMissileCount;

//Ǳͧ����ĵ���
extern TFCOMMONMODELCOM_API int launchedYJ18MissileCount;
extern TFCOMMONMODELCOM_API int launchedClubMissileCount;


extern TFCOMMONMODELCOM_API int RedTorpedoEntityNum;
extern TFCOMMONMODELCOM_API int BlueTorpedoEntityNum;
extern TFCOMMONMODELCOM_API routInfo myInfo[100];
extern TFCOMMONMODELCOM_API int  infoCount; 
*/

#endif
