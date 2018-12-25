//LatLonH.cpp: implementation of the CLatLonH module.
//!!HDOSE_CLASS(CLatLonH,)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LatLonH.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


void ReleaseLatLonHList(CLatLonHList* list)
{
	POSITION pos=list->GetHeadPosition();
	while(pos){
		CLatLonH* item=(CLatLonH*)list->GetNext(pos);
		delete item;
	}
	list->RemoveAll();
}



CLatLonH::CLatLonH()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CLatLonH)
	m_latitude=0;
	m_longitude=0;
	m_height=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CLatLonH::~CLatLonH()
{

}



