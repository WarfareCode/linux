//IrradiatorData.h: interface for the CIrradiatorData module.
//!!HDOSE_CLASS(CIrradiatorData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_IrradiatorData_H)
#define AFX_IrradiatorData_H


//{{HDOSE_CLS_DES(CIrradiatorData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CIrradiatorData /*’’…‰∆˜≤Œ ˝*/
{
public:
	CIrradiatorData();
	~CIrradiatorData();
public:
	
	//{{HDOSE_ATTRIBUTE(CIrradiatorData)
	char 	m_IrradiatorNo/*’’…‰∆˜±‡∫≈*/;
	char 	m_IrradiatorState/*’’…‰∆˜◊¥Ã¨£®ø’œ– 0°¢∑±√¶ 1 °¢Œﬁ–ß 2£©*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CIrradiatorDataList;
void ReleaseIrradiatorDataList(CIrradiatorDataList* list);

#endif
