//SeekerDisplayData.h: interface for the CSeekerDisplayData module.
//!!HDOSE_CLASS(CSeekerDisplayData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SeekerDisplayData_H)
#define AFX_SeekerDisplayData_H


//{{HDOSE_CLS_DES(CSeekerDisplayData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSeekerDisplayData /*导引头显示数据*/
{
public:
	CSeekerDisplayData();
	~CSeekerDisplayData();
public:
	
	//{{HDOSE_ATTRIBUTE(CSeekerDisplayData)
	long	m_AttributeType/*属性类型（0舰艇、1防空导弹、2箔条、3压制干扰、4其它）*/;
	double	m_Azimuth/*方位*/;
	double	m_Distance/*距离km*/;
	long	m_JammingWaveform/*干扰波形，属性类型为压制干扰时，该项才填写（0压制波形，1杂乱脉冲）*/;
	double	m_JammingPower/*干扰功率，属性类型为压制干扰时，该项才填写*/;
	double	m_RCS/*RCS*/;
	long	m_TargetNo/*目标编号（导引头范围内的实体的编号、非实体该项不填）*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CSeekerDisplayDataList;
void ReleaseSeekerDisplayDataList(CSeekerDisplayDataList* list);

#endif
