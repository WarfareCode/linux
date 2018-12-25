//Azimuth3D.h: interface for the CAzimuth3D module.
//!!HDOSE_CLASS(CAzimuth3D,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Azimuth3D_H)
#define AFX_Azimuth3D_H


//{{HDOSE_CLS_DES(CAzimuth3D)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAzimuth3D /*三坐标方位向量*/
{
public:
	CAzimuth3D();
	~CAzimuth3D();
public:
	
	//{{HDOSE_ATTRIBUTE(CAzimuth3D)
	double	m_HorAzimuth/*水平方位（正北为0，0-360）*/;
	double	m_VerAzimuth/*垂直方位（水平为0，-90～90）*/;
	//}}HDOSE_ATTRIBUTE

	CAzimuth3D& operator=(CAzimuth3D val)
	{
		m_HorAzimuth = val.m_HorAzimuth;
		m_VerAzimuth = val.m_VerAzimuth;

		return *this;
	}


};
typedef List<DWORD,DWORD> CAzimuth3DList;
void ReleaseAzimuth3DList(CAzimuth3DList* list);

#endif
