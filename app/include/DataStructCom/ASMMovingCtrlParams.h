//ASMMovingCtrlParams.h: interface for the CASMMovingCtrlParams module.
//!!HDOSE_CLASS(CASMMovingCtrlParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMMovingCtrlParams_H)
#define AFX_ASMMovingCtrlParams_H



//{{HDOSE_CLS_DES(CASMMovingCtrlParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CASMMovingCtrlParams /*���������˶����Ʋ���*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CASMMovingCtrlParams();
	virtual ~CASMMovingCtrlParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPostion(GeoPt val){m_Postion=val;}
	GeoPt	GetPostion(){return m_Postion;}
	void	SetCourse(double val){m_Course=val;}
	double	GetCourse(){return m_Course;}
	void	SetPitch(double val){m_Pitch=val;}
	double	GetPitch(){return m_Pitch;}
	void	SetRoll(double val){m_Roll=val;}
	double	GetRoll(){return m_Roll;}
	void	SetMoveOrderType(long val){m_MoveOrderType=val;}
	long	GetMoveOrderType(){return m_MoveOrderType;}

	//{{HDOSE_MEMBER_FUNCTION(CASMMovingCtrlParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CASMMovingCtrlParams)
	GeoPt	m_Postion/*λ��*/;
	double	m_Course/*�����*/;
	double	m_Pitch/*������*/;
	double	m_Roll/*��ת��*/;
	long	m_MoveOrderType/*�����˶�ָ�-1�غ�·�˶���0��ս����1��ս�أ�2��ս��3���壩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
