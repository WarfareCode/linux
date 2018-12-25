//JSTerrainService.h: interface for the CJSTerrainService module.
//!!HDOSE_CLASS(CJSTerrainService,CNode)
//////////////////////////////////////////////////////////////////////

//{{HDOSE_CLS_DES(CJSTerrainService)
/*
Author:		xks
Version:	1.0
Descript:	地形数据服务类:
	1. 此类目前只能读取ASTER-GDEM V2 标准格式的分片tif文件
	1. 根据经纬度数值返回高程数值;
	2. 返回2个点间的通视性；

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

class TERRAINSERVICECOM_API CJSTerrainService /*地形服务对象*/ : public CNode 
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
		int imagePixelWidth;	// 图像像素宽度
		int imagePixelHeight; //
		int stripCount; /*带总数*/
		int stripSize; /*每个带的比特数*/
		int lat; // 纬度
		int lon; // 经度
	};

	map< int, map<int, TIFFRec> > TiffRecs; // 外层map按经度索引，内层map是按纬度索引的tif分片记录
	bool lookupTiffRecByLatLon(TIFFRec& rec, double lat, double lon); // 按经纬度查找分片记录
	string getTiffFileNameByLatLon(double lat, double lon); // 根据经纬度查找所在的tiff分片文件名称
	bool loadTiffFile(const char* filename, double lat, double lon, TIFFRec &rec); // 根据文件件名加载tiff文件，默认tif文件为绝对工作目录"D:\\HJsim\\TerrainData\\"
	bool readTiffData(TIFFRec, double lat, double lon, double &alt); // 读出该分片的所有条带数据，然后根据经纬度进行索引，速度慢
	bool readTiffData2(TIFFRec, double lat, double lon, double &alt); // 读出经纬度所在的条带数据，然后根据经纬度进行索引，速度较快
	// 四舍五入函数，此处使用名称为roundf。VS2013(_MSC_VER = 1800)之后的math.h中才有自带此函数round
	int roundf(double a)
	{
		return (a>=0)?(int)(a+0.5):(int)(a-0.5);
	}
	bool getAltByLatLon(double lat, double lon, double &alt); // 读数据使用readTiffData，速度较慢
	bool getAltByLatLon2(double lat, double lon, double &alt); // 读数据使用readTiffData2，速度较快

	bool LOSCalc(double latA, double lonA, double altA, double latB, double lonB, double altB); // AB两个点的通视性计算

};

#endif
