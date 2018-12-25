//JammerChannelData.h: interface for the CJammerChannelData module.
//!!HDOSE_CLASS(CJammerChannelData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_JammerChannelData_H)
#define AFX_JammerChannelData_H



//{{HDOSE_CLS_DES(CJammerChannelData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CJammerChannelData /*������ͨ������*/
{
public:
	CJammerChannelData();
	~CJammerChannelData();
public:
	
	//{{HDOSE_ATTRIBUTE(CJammerChannelData)
	long	m_ChannelNo/*ͨ�����*/;
	bool	m_bPowerOn/*���ػ�״̬��0�ػ���1������*/;
	GeoPt	m_JammerPos/*���Ż�λ��*/;
	double	m_BeamWidth/*���Ų������*/;
	double	m_BeamAzimuth/*��������Ŀ�귽λ��*/;
	double	m_BeamPower/*���书��*/;
	long	m_BeamWaveForm/*���䲨�Σ�0ѹ�Ʋ��Σ�1�������壩*/;
	long	m_TargetNo/*����Ŀ����*/;
	long	m_ChannelState/*����ͨ��״̬��0���У�1��æ��*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CJammerChannelDataList;
void ReleaseJammerChannelDataList(CJammerChannelDataList* list);

#endif
