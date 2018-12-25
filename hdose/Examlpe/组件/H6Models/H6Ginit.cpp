// H6Ginit.cpp: implementation of the H6Ginit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "H6Ginit.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_CREATE_EX(H6Ginit,CEvt,ClassInit);

BEGIN_EVENTMAP(H6Ginit)
END_EVENTMAP
 
H6Ginit::H6Ginit()
{

}

H6Ginit::~H6Ginit()
{

}
void H6Ginit::ClassInit(ClassInfo *clsinfo) 
{

	AttributeRegister(H6Ginit,double,longitude);
	AttributeRegister(H6Ginit,double,latitude);
	AttributeRegister(H6Ginit,double,height);
	AttributeRegister(H6Ginit,double,velocity);
	AttributeRegister(H6Ginit,double,yaw);
	AttributeRegister(H6Ginit,double,roll);

}
