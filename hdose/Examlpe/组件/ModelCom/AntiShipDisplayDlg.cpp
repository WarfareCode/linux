// AntiShipDisplayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ModelCom.h"
#include "AntiShipDisplayDlg.h"
#include "LineObj.h"
#include "SubmarineStateRep.h"
#include "ShipStateRep.h"
#include "TorpedoStateRep.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAntiShipDisplayDlg dialog


CAntiShipDisplayDlg::CAntiShipDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAntiShipDisplayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAntiShipDisplayDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAntiShipDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAntiShipDisplayDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAntiShipDisplayDlg, CDialog)
	//{{AFX_MSG_MAP(CAntiShipDisplayDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAntiShipDisplayDlg message handlers
BOOL CAntiShipDisplayDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_pEng=NULL;

	BackBrush.CreateSolidBrush(RGB(0,0,0));
	penAxis.CreatePen(PS_SOLID,1,RGB(128,128,0));
	penText.CreatePen(PS_SOLID,1,RGB(255,255,255));

	penTor.CreatePen(PS_SOLID,1,RGB(255,0,0));//红
	penSub.CreatePen(PS_SOLID,2,RGB(0,255,0));//绿
	penShip.CreatePen(PS_SOLID,2,RGB(0,0,255));//蓝

	CClientDC dc(this);
	this->GetClientRect(&clientRect);

	plotrect.left=100;
	plotrect.top=50;
	plotrect.right=600;
	plotrect.bottom=350;

	memoryDC0.CreateCompatibleDC(&dc);
	MemBitmap0.CreateCompatibleBitmap(&dc,clientRect.Width(),clientRect.Height());
	memoryDC0.SelectObject(&MemBitmap0);
	memoryDC0.FillRect(plotrect,&BackBrush);
	memoryDC0.SetTextColor(RGB(255, 0, 255));
	memoryDC0.SetBkMode(TRANSPARENT);
	PlotBackBmp();

	return TRUE;
}

void CAntiShipDisplayDlg::PlotBackBmp()
{
	memoryDC0.SelectObject(&penAxis);
	memoryDC0.Rectangle(plotrect);
	int num=5;
	double dx=plotrect.Width()/num;
	double dy=plotrect.Height()/num;

	for (int i=1;i<num;i++)
	{
		memoryDC0.MoveTo(plotrect.left+dx*i,plotrect.top);
		memoryDC0.LineTo(plotrect.left+dx*i,plotrect.top+plotrect.Height());

	}

	for (int i=1;i<num;i++)
	{
		memoryDC0.MoveTo(plotrect.left,plotrect.top+dy*i);
		memoryDC0.LineTo(plotrect.left+plotrect.Width(),plotrect.top+dy*i);
	}

	memoryDC0.SelectObject(&penText);
	memoryDC0.TextOut(plotrect.left-50,plotrect.top-20,"116°,26°");
	memoryDC0.TextOut(plotrect.right,plotrect.top-20,"117°,26°");
	memoryDC0.TextOut(plotrect.left-50,plotrect.bottom,"116°,25°");
	memoryDC0.TextOut(plotrect.right,plotrect.bottom,"117°,25°");

}
void CAntiShipDisplayDlg::UpdataShipPos(char *Name,double longt,double lat)
{
	CClientDC dc(this);
	dc.SelectObject(&penShip);

	int x=plotrect.left+((longt-116)*500);
	int y=plotrect.bottom-((lat-25)*300);
	dc.Ellipse(x-3,y-3,x+3,y+3);
	dc.TextOut(x+10,y+10,Name);

}
void CAntiShipDisplayDlg::UpdataSubPos(char *Name,double longt,double lat)
{
	CClientDC dc(this);
	dc.SelectObject(&penSub);

	int x=plotrect.left+((longt-116)*500);
	int y=plotrect.bottom-((lat-25)*300);

	dc.Ellipse(x-3,y-3,x+3,y+3);

	dc.TextOut(x+10,y+10,Name);
}
void CAntiShipDisplayDlg::UpdataTorpedoPos(char *Name,double longt,double lat)
{
	CClientDC dc(this);
	dc.SelectObject(&penTor);

	int x=plotrect.left+((longt-116)*500);
	int y=plotrect.bottom-((lat-25)*300);

	dc.MoveTo(x-2,y-2);
	dc.LineTo(x+2,y+2);
	dc.MoveTo(x+2,y-2);
	dc.LineTo(x-2,y+2);

}
void CAntiShipDisplayDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	dc.BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memoryDC0,0,0, SRCCOPY);
	
}
void CAntiShipDisplayDlg::tick()
{
	CObjList* pList=m_pEng->LookupObjFromClass("CSubmarineStateRep");
	POSITION pos=pList->GetHeadPosition();
	while(pos)
	{
		CSubmarineStateRep *pSubSR=(CSubmarineStateRep *)(pList->GetNext(pos));
		UpdataSubPos(pSubSR->m_parent->GetName(),pSubSR->m_Pos.m_longitude,pSubSR->m_Pos.m_latitude);
	}

	pList=m_pEng->LookupObjFromClass("CShipStateRep");
	pos=pList->GetHeadPosition();
	while(pos)
	{
		CShipStateRep *pShipSR=(CShipStateRep *)(pList->GetNext(pos));
		UpdataShipPos(pShipSR->m_parent->GetName(),pShipSR->m_Pos.m_longitude,pShipSR->m_Pos.m_latitude);
	}

	pList=m_pEng->LookupObjFromClass("CTorpedoStateRep");
	pos=pList->GetHeadPosition();
	while(pos)
	{
		CTorpedoStateRep *pTPDSR=(CTorpedoStateRep *)(pList->GetNext(pos));
		UpdataTorpedoPos(pTPDSR->m_parent->GetName(),pTPDSR->m_Pos.m_longitude,pTPDSR->m_Pos.m_latitude);
	}
	
}
void CAntiShipDisplayDlg::OutputText(CString str)
{

	CRect r(plotrect.left,plotrect.bottom+30,plotrect.right,plotrect.bottom+130);
	memoryDC0.FillRect(r,&BackBrush);
	memoryDC0.TextOut(plotrect.left,plotrect.bottom+30,str);
	Invalidate(TRUE);

}