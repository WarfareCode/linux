// Bridge.h: interface for the CBridge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRIDGE_H__C5D0E42A_2401_4DA0_B24C_220A48331EC0__INCLUDED_)
#define AFX_BRIDGE_H__C5D0E42A_2401_4DA0_B24C_220A48331EC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Item.h"

class HDOSE_API CBridge : public CItem  
{
	DECLARE_CREATE
	DECLARE_EVENTMAP;
public:

	virtual void Init(char *para){};
	virtual void Close(){};
/////////////////////////////////////////////////
	////////////////////////////////

	virtual void CreateFederation(char *federation_name, char *fed_filename){};
	virtual int JoinFederation(char *fed_name){return 0;};
	virtual void ResignFederation(){};
	virtual void DestroyFederation(){};

	///////////////////////////////
	virtual int GetInteractionClassHandle(char *name){return 0;};
	virtual int GetAttributeHandle(char *name,int clsid){return 0;};
	virtual int GetObjectClassHandle(char* str){return 0;};
	virtual int GetParameterHandle(char *name, int clsid){return 0;};

	virtual void Publish(CClasInfoList *path=0){};
	virtual void UnPublish(CClasInfoList *path=0){};
	virtual void Subscribe(CClasInfoList *path=0){};
	virtual void UnSubscribe(CClasInfoList *path=0){};

	////////////////////////////////
	virtual void UpdateAttributeValues(CObj *pObj,char *Array){};
	virtual void RequestObjectAttributeValueUpdate(CObj *pObj){};
	virtual void DeleteObjectInstance(CObj *pObj){};
	virtual void RegisterObjectInstance(CObj *pObj){};
	virtual void SendHLAEvt(CEvt *pEvt){};

	///////////////////////////////
	virtual void ExecTimePolicy(BOOL bc,BOOL br,BOOL MTRTI){};
	virtual void TimeAdvance(double lasttime=0){ASSERT(0);};
	virtual double GetLookahead(){return 0;};
	virtual double GetGrantTime(){return 0;};
	virtual double GetLogicClock(){return 0;};
	virtual void SetLookahead(double){};
	virtual void SetGrantTime(double){};
	virtual void SetLogicClock(double){};


	///////////////////////////////////////////////////////////////////
	////
	virtual void CB_Reflesh_FederationInfo(CEvt *pEvt){};
	virtual void CB_Publish(CEvt *pEvt){};
	virtual void CB_Subscribe(CEvt *pEvt){};

	virtual void CB_DiscoverObjectInstance(CEvt *pEvt){};
	virtual void CB_RemoveObjectInstance(CEvt *pEvt){};
	virtual void CB_ReflectAttributeValues(CEvt *pEvt){};
	virtual void CB_ReceiveInteraction(CEvt *pEvt){};

///////////////////////////////////////////////////////////
	////
	virtual void OnRefleshFederationInfo(char *buf,int len){};
	virtual void OnJoinGrant(DWORD fedid){};

	virtual void OnSubscribe(DWORD fedhandle,DWORD clshandle){};
	virtual void OnPublish(DWORD fedhandle,DWORD clshandle){};

	virtual void OnDiscoverObjectInstance(DWORD theObject, DWORD theObjectClass, const char* theObjectName){};
	virtual void OnRemoveObjectInstance(DWORD theObject){};

	virtual void OnReflectAttributeValues(DWORD theObject, char* theAttributes){};
	virtual void OnReceiveInteraction(DWORD theInteraction, char* theParameters){};
	virtual void OnRegisterObjInstance(DWORD fedid){};

	virtual void OnTimeAdvGrant(double time){};

};

#endif // !defined(AFX_BRIDGE_H__C5D0E42A_2401_4DA0_B24C_220A48331EC0__INCLUDED_)
