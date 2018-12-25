//Vector.h: interface for the CVector module.
//!!HDOSE_CLASS(CVector,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Vector_H)
#define AFX_Vector_H


//{{HDOSE_CLS_DES(CVector)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CVector /*三坐标向量*/
{
public:
	CVector();
	~CVector();
public:
	
	//{{HDOSE_ATTRIBUTE(CVector)
	short	m_coordType/*坐标系*/;
	double	m_x/*x分量*/;
	double	m_y/*y分量*/;
	double	m_z/*z分量*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CVectorList;
void ReleaseVectorList(CVectorList* list);

#endif
