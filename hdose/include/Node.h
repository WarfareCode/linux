// Node.h: interface for the CNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODE_H__8802C582_419F_418B_BFA5_ECB122C41196__INCLUDED_)
#define AFX_NODE_H__8802C582_419F_418B_BFA5_ECB122C41196__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CParaEntry;
#include "Link.h"
class HDOSE_API CNode : public CLink  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
protected:
	CNode();
	virtual ~CNode();
	String m_script;
public:
	virtual void Read(CMarkup *xml);
	virtual void Write(CMarkup *xml,BOOL into=0);
public:

};

#endif // !defined(AFX_NODE_H__8802C582_419F_418B_BFA5_ECB122C41196__INCLUDED_)
