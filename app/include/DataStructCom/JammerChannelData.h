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

class DATASTRUCTCOMPONENTDLL_API CJammerChannelData /*干扰器通道参数*/
{
public:
	CJammerChannelData();
	~CJammerChannelData();
public:
	
	//{{HDOSE_ATTRIBUTE(CJammerChannelData)
	long	m_ChannelNo/*通道编号*/;
	bool	m_bPowerOn/*开关机状态（0关机、1开机）*/;
	GeoPt	m_JammerPos/*干扰机位置*/;
	double	m_BeamWidth/*干扰波束宽度*/;
	double	m_BeamAzimuth/*波束朝向（目标方位）*/;
	double	m_BeamPower/*发射功率*/;
	long	m_BeamWaveForm/*发射波形（0压制波形，1杂乱脉冲）*/;
	long	m_TargetNo/*干扰目标编号*/;
	long	m_ChannelState/*干扰通道状态（0空闲，1繁忙）*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CJammerChannelDataList;
void ReleaseJammerChannelDataList(CJammerChannelDataList* list);

#endif
