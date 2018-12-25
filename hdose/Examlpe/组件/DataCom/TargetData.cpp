//TargetData.cpp: implementation of the CTargetData module.
//!!HDOSE_CLASS(CTargetData,)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TargetData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


void ReleaseTargetDataList(CTargetDataList* list)
{
	POSITION pos=list->GetHeadPosition();
	while(pos){
		CTargetData* item=(CTargetData*)list->GetNext(pos);
		delete item;
	}
	list->RemoveAll();
}



CTargetData::CTargetData()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CTargetData)
	m_TargetId=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CTargetData::~CTargetData()
{

}



