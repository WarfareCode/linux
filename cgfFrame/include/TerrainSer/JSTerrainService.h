//JSTerrainService.h: interface for the CJSTerrainService module.
//!!HDOSE_CLASS(CJSTerrainService,CNode)
//////////////////////////////////////////////////////////////////////

//{{HDOSE_CLS_DES(CJSTerrainService)
/*
Author:		xks
Version:	1.0
Descript:	�������ݷ�����:
	1. ����Ŀǰֻ�ܶ�ȡASTER-GDEM V2 ��׼��ʽ�ķ�Ƭtif�ļ�
	1. ���ݾ�γ����ֵ���ظ߳���ֵ;
	2. ����2������ͨ���ԣ�

*/
//}}HDOSE_CLS_DES


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_JSTerrainService_H)
#define AFX_JSTerrainService_H

#include "stdlib.h"
#include "geotiff/geotiffio.h"
#include "geotiff/xtiffio.h"
#include "geotiff/geo_normalize.h"
#include "math.h"
#include <map>
#include <string>

using namespace std;

class TERRAINSERVICECOM_API CJSTerrainService /*���η������*/ : public CNode 
{
	DECLARE_CREATE;
public:
	CJSTerrainService();
	virtual ~CJSTerrainService();
	static	void ClassInit(ClassInfo *clsinfo);

	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CJSTerrainService)
	//}}HDOSE_MEMBER_FUNCTION

public:

	//{{HDOSE_ATTRIBUTE(CJSTerrainService)
	//}}HDOSE_ATTRIBUTE

	struct  TIFFRec
	{
		TIFF* pTif; // 
		GTIF* pGtif;
		int imagePixelWidth;	// ͼ�����ؿ��
		int imagePixelHeight; //
		int stripCount; /*������*/
		int stripSize; /*ÿ�����ı�����*/
		int lat; // γ��
		int lon; // ����
	};

	map< int, map<int, TIFFRec> > TiffRecs; // ���map�������������ڲ�map�ǰ�γ��������tif��Ƭ��¼
	bool lookupTiffRecByLatLon(TIFFRec& rec, double lat, double lon); // ����γ�Ȳ��ҷ�Ƭ��¼
	string getTiffFileNameByLatLon(double lat, double lon); // ���ݾ�γ�Ȳ������ڵ�tiff��Ƭ�ļ�����
	bool loadTiffFile(const char* filename, double lat, double lon, TIFFRec &rec); // �����ļ���������tiff�ļ���Ĭ��tif�ļ�Ϊ���Թ���Ŀ¼"D:\\HJsim\\TerrainData\\"
	bool readTiffData(TIFFRec, double lat, double lon, double &alt); // �����÷�Ƭ�������������ݣ�Ȼ����ݾ�γ�Ƚ����������ٶ���
	bool readTiffData2(TIFFRec, double lat, double lon, double &alt); // ������γ�����ڵ��������ݣ�Ȼ����ݾ�γ�Ƚ����������ٶȽϿ�
	// �������뺯�����˴�ʹ������Ϊroundf��VS2013(_MSC_VER = 1800)֮���math.h�в����Դ��˺���round
	int roundf(double a)
	{
		return (a>=0)?(int)(a+0.5):(int)(a-0.5);
	}
	bool getAltByLatLon(double lat, double lon, double &alt); // ������ʹ��readTiffData���ٶȽ���
	bool getAltByLatLon2(double lat, double lon, double &alt); // ������ʹ��readTiffData2���ٶȽϿ�

	bool LOSCalc(double latA, double lonA, double altA, double latB, double lonB, double altB); // AB�������ͨ���Լ���

};

#endif
