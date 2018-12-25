//FakeTargetData.h: interface for the CFakeTargetData module.
//!!HDOSE_CLASS(CFakeTargetData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FakeTargetData_H)
#define AFX_FakeTargetData_H


//{{HDOSE_CLS_DES(CFakeTargetData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CFakeTargetData /*��Դ��Ŀ������*/
{
public:
	CFakeTargetData();
	~CFakeTargetData();
public:
	
	//{{HDOSE_ATTRIBUTE(CFakeTargetData)
	double	m_DelayDist/*�ӳپ���(m)*/;
	double	m_EchoPower/*���书�ʣ����Ż������ü�Ŀ��ʱ�ķ��书�ʣ�*/;
	double	m_Speed/*�ٶ�(m/s)*/;
	long	m_Polarity/*������0ˮƽ��1��ֱ��2б������3Բ������4������*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CFakeTargetDataList;
void ReleaseFakeTargetDataList(CFakeTargetDataList* list);

#endif
