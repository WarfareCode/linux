#pragma once


/////////////////////////////////////
struct Track
{
	int id;
	double x;
	double y;
	double z;
};

DECLARE_ObjStream(CTrackStream,Track,128);///ע���CTrackStream��������Sim�ļ��еķ����򶩹����������������л����!!!!
/////////////////////////////
DECLARE_DA(Track,32);
//////
class CTargetIndicate:public CEvt
{
	DECLARE_CREATE
public:
	static void ClassInit(ClassInfo *clsinfo);

	int m_imp;
	DA_Track m_info;

};
///////////////////////////////
class CSensor :
	public CNode
{
	DECLARE_CREATE
	int m_rate;//������
	int m_nu;//������
	BOOL m_power;
	CTrackStream *m_tracks;/////ע���
	void tick(double time);
	void Detect(double time);

public:
	CSensor(void);
	virtual ~CSensor(void);

};
