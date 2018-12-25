// Model.h: interface for the CModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL_H__89FCA3AE_0D14_4227_A12C_920E78B09C39__INCLUDED_)
#define AFX_MODEL_H__89FCA3AE_0D14_4227_A12C_920E78B09C39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Node.h"



class CStateRepository;
class  MODELCOM_API CModel : public CNode  
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

	CNode*		GetEntity();
    CStateRepository*	GetStateRepository();
	virtual void SendEntityEvt(CEvt *pEvt);	// 20160828,xks

public:
    // The buffer referenced by pointer pBuffer is newed by user, the buffer should
    // be valid (not released) after the function is invoked, and the buffer would
    // be released by HDOSE.
    virtual void CompressCustomizeData(__out BYTE * & pBuffer, __out int & size);

    // The buffer referenced by pointer pBuffer is newed by HDOSE, and also should
    // be released by HDOSE.
    virtual void RecoverCustomizeData(__in const BYTE * pBuffer, __in const int size);

public:
    bool m_bInitPermit;
    long m_oldId;

};

#endif // !defined(AFX_MODEL_H__89FCA3AE_0D14_4227_A12C_920E78B09C39__INCLUDED_)
