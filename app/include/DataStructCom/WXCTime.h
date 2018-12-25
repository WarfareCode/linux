//WXCTime.h: interface for the CWXCTime module.
//!!HDOSE_CLASS(CWXCTime,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_WXCTime_H)
#define AFX_WXCTime_H


//{{HDOSE_CLS_DES(CWXCTime)
/*
Author:		
Version:	1.0
Descript:	时间，时：分：秒
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CWXCTime /*时间*/
{
public:
	CWXCTime();
	~CWXCTime();
public:
	
	//{{HDOSE_ATTRIBUTE(CWXCTime)
	long	m_Hour/*时（0-23）*/;
	long	m_Minute/*分（0-59）*/;
	long	m_Second/*秒（0-59）*/;
	//}}HDOSE_ATTRIBUTE

	CWXCTime& operator=(CWXCTime val)
	{
		m_Hour=val.m_Hour;
		m_Minute=val.m_Minute;
		m_Second=val.m_Second;

		return *this;
	}

	CWXCTime operator+(CWXCTime val)
	{
		CWXCTime temp;
		temp.m_Hour= m_Hour+val.m_Hour;
		temp.m_Minute=m_Minute+val.m_Minute;
		temp.m_Second=m_Second+val.m_Second;

		if(temp.m_Second>=60)
		{
			temp.m_Minute+=temp.m_Second/60;
			temp.m_Second=temp.m_Second-(temp.m_Second/60)*60;
		}

		if(temp.m_Minute>=60)
		{
			temp.m_Hour+=temp.m_Minute/60;
			temp.m_Minute=temp.m_Minute-(temp.m_Minute/60)*60;
		}

		return temp;
	}
	CWXCTime& operator+=(CWXCTime val)
	{
		m_Hour+=val.m_Hour;
		m_Minute+=val.m_Minute;
		m_Second+=val.m_Second;

		if(m_Second>=60)
		{
			m_Minute+=m_Second/60;
			m_Second=m_Second-(m_Second/60)*60;
		}

		if(m_Minute>=60)
		{
			m_Hour+=m_Minute/60;
			m_Minute=m_Minute-(m_Minute/60)*60;
		}

		return *this;
	}

};
typedef List<DWORD,DWORD> CWXCTimeList;
void ReleaseWXCTimeList(CWXCTimeList* list);

#endif
