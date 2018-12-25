// Model.h: interface for the CModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL_H__89FCA3AE_0D14_4227_A12C_920E78B09C39__INCLUDED_)
#define AFX_MODEL_H__89FCA3AE_0D14_4227_A12C_920E78B09C39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CGFDS.h"

class CStateRepository;
class CModelSR;

class HYCGF_API CModel : public CNode  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
	static void ClassInit(ClassInfo *clsinfo);
public:
	CModel();
	virtual ~CModel();

	virtual void OnInit();
    virtual	void	tick(double lasttime);
    virtual	void	Simulation(double lasttime);

	// 得到实体对象
	CNode*	GetEntity()
	{
		return (CNode*)m_parent;
	}

	// 取得所属实体的状态池对象
    virtual CStateRepository*	GetStateRepository()
	{
		return (CStateRepository *)((CNode*)m_parent)->m_pSr;
	}

	// 发送实体内部事件，20160828,xks
	virtual void SendEntityEvt(CEvt *pEvt)	
	{
		pEvt->m_scope = 0;
		pEvt->m_sourceid = m_id;
		pEvt->Send();
	}

	// 获得本模型的状态池对象，20161129
	virtual CModelSR* GetModelSR()
	{
		CModelSR* pobj = NULL;
		POSITION pos=m_agtlist.GetHeadPosition();
		while (pos)
		{
			CObj* pItem=(CObj*)m_agtlist.GetNext(pos);
			if(pItem->IsDrivedFrom("CModelSR"))
			{
				pobj = (CModelSR*)pItem;
				return pobj;	// 找到对象，返回
			}
		}
		return pobj;	// 未找到对象，返回NULL
	}

public:
    bool m_bInitPermit;
    long m_oldId;

};

#endif // !defined(AFX_MODEL_H__89FCA3AE_0D14_4227_A12C_920E78B09C39__INCLUDED_)
