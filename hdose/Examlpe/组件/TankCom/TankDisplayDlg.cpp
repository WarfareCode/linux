// Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "TankCom.h"
#include "TankDisplayDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg dialog


CTankDisplayDlg::CTankDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTankDisplayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTankDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTankDisplayDlg, CDialog)
	//{{AFX_MSG_MAP(CDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
//	ON_WM_SHOWWINDOW()
ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg message handlers
BOOL CTankDisplayDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	BackBrush.CreateSolidBrush(RGB(0,0,0));
	penAxis.CreatePen(PS_SOLID,1,RGB(128,128,0));
	penLine.CreatePen(PS_SOLID,1,RGB(255,128,0));
	penTgt.CreatePen(PS_SOLID,1,RGB(255,0,0));

	CClientDC dc(this);
	this->GetClientRect(&clientRect);

	plotrect.left=100;
	plotrect.top=50;
	plotrect.right=600;
	plotrect.bottom=350;
	m_pEng=NULL;
	
	memoryDC0.CreateCompatibleDC(&dc);
	MemBitmap0.CreateCompatibleBitmap(&dc,clientRect.Width(),clientRect.Height());
	memoryDC0.SelectObject(&MemBitmap0);
	memoryDC0.FillRect(plotrect,&BackBrush);
	memoryDC0.SetTextColor(RGB(255, 0, 255));
	memoryDC0.SetBkMode(TRANSPARENT);

	PlotBackBmp();

	return TRUE;
}
void CTankDisplayDlg::PlotBackBmp()
{

	CClientDC dc(this);
	memoryDC0.SelectObject(&penAxis);
	memoryDC0.Rectangle(plotrect);

	
	memoryDC0.TextOut(plotrect.left-50,plotrect.top-20,"116°,26°");
	memoryDC0.TextOut(plotrect.right,plotrect.top-20,"117°,26°");
	memoryDC0.TextOut(plotrect.left-50,plotrect.bottom,"116°,25°");
	memoryDC0.TextOut(plotrect.right,plotrect.bottom,"117°,25°");
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
	

	if (m_pEng){

		POINT PTArray[10];int PTnum=0;
		CLineObj *pLineObj=(CLineObj *)m_pEng->LookupObj("CLineObj");
		if (pLineObj)
		{
			CLatLonH* pPoints=pLineObj->GetPoints();
			for (int i=0;i<pLineObj->GetPointsCount();i++)
			{
				PTnum++;
				CLatLonH m_disPoint=pPoints[i];
				PTArray[i].x=plotrect.left+((m_disPoint.m_longitude-116)*500);
				PTArray[i].y=plotrect.bottom-((m_disPoint.m_latitude-25)*300);
				CString str;
				str.Format("%0.2f°,%0.2f°",m_disPoint.m_longitude,m_disPoint.m_latitude);
				memoryDC0.TextOut(PTArray[i].x,PTArray[i].y,str);
			}
			memoryDC0.Polyline(PTArray,PTnum);
		}
	}
	dc.BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memoryDC0,0,0, SRCCOPY);
}
void CTankDisplayDlg::plotObjData(double longt,double lat)
{
	CClientDC dc(this);
	static bool bfrist=true;
	if (bfrist)
	{
		if (m_pEng==NULL) return;

		POINT PTArray[10];int PTnum=0;

		CLineObj *pLineObj=(CLineObj *)m_pEng->LookupObj("CLineObj");
		if (pLineObj)
		{
			CLatLonH* pPoints=pLineObj->GetPoints();
			for (int i=0;i<pLineObj->GetPointsCount();i++)
			{
				PTnum++;
				CLatLonH m_disPoint=pPoints[i];
				PTArray[i].x=plotrect.left+((m_disPoint.m_longitude-116)*500);
				PTArray[i].y=plotrect.bottom-((m_disPoint.m_latitude-25)*300);
				CString str;
				str.Format("%0.2f°,%0.2f°",m_disPoint.m_longitude,m_disPoint.m_latitude);
				memoryDC0.TextOut(PTArray[i].x,PTArray[i].y,str);
			}
			memoryDC0.Polyline(PTArray,PTnum);
			dc.BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memoryDC0,0,0, SRCCOPY);
			Invalidate(TRUE);
		}
		bfrist=false;
	}
	

	int x=plotrect.left+((longt-116)*500);
	int y=plotrect.bottom-((lat-25)*300);

	

	memoryDC0.SelectObject(&penTgt);

	memoryDC0.MoveTo(x-2,y-2);
	memoryDC0.LineTo(x+2,y+2);
	memoryDC0.MoveTo(x+2,y-2);
	memoryDC0.LineTo(x-2,y+2);

	dc.BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memoryDC0,0,0, SRCCOPY);


}


void CTankDisplayDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()

	PlotBackBmp();
}
void CTankDisplayDlg::OutputText(CString str)
{

	CRect r(plotrect.left,plotrect.bottom+30,plotrect.right,plotrect.bottom+130);
	memoryDC0.FillRect(r,&BackBrush);
	memoryDC0.TextOut(plotrect.left,plotrect.bottom+30,str);
	

}