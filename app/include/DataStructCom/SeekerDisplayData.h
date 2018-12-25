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

class DATASTRUCTCOMPONENTDLL_API CSeekerDisplayData /*����ͷ��ʾ����*/
{
public:
	CSeekerDisplayData();
	~CSeekerDisplayData();
public:
	
	//{{HDOSE_ATTRIBUTE(CSeekerDisplayData)
	long	m_AttributeType/*�������ͣ�0��ͧ��1���յ�����2������3ѹ�Ƹ��š�4������*/;
	double	m_Azimuth/*��λ*/;
	double	m_Distance/*����km*/;
	long	m_JammingWaveform/*���Ų��Σ���������Ϊѹ�Ƹ���ʱ���������д��0ѹ�Ʋ��Σ�1�������壩*/;
	double	m_JammingPower/*���Ź��ʣ���������Ϊѹ�Ƹ���ʱ���������д*/;
	double	m_RCS/*RCS*/;
	long	m_TargetNo/*Ŀ���ţ�����ͷ��Χ�ڵ�ʵ��ı�š���ʵ�����*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CSeekerDisplayDataList;
void ReleaseSeekerDisplayDataList(CSeekerDisplayDataList* list);

#endif
