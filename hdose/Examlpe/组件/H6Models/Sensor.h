#pragma once


/////////////////////////////////////
struct Track
{
	int id;
	double x;
	double y;
	double z;
};

DECLARE_ObjStream(CTrackStream,Track,128);///注意点CTrackStream必须列入Sim文件中的发布或订购的名单，否则运行会出错!!!!
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
	int m_rate;//数据率
	int m_nu;//计算器
	BOOL m_power;
	CTrackStream *m_tracks;/////注意点
	void tick(double time);
	void Detect(double time);

public:
	CSensor(void);
	virtual ~CSensor(void);

};
