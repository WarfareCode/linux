// MyType.h: interface for My Type
//
//////////////////////////////////////////////////////////////////////

#ifndef MyType_h
#define MyType_h
#include "BwVehicleKinematic.h"

namespace  BW_VEHICLEKINEMATIC {


	//  ��ά����
	class  BW_VEHICLEKINEMATIC_API CVector2  
	{
	public:

		CVector2();
		virtual ~CVector2();

		double x, y;
	};

	//  ���׷���
	class  BW_VEHICLEKINEMATIC_API CMatrix22  
	{
	public:
		CMatrix22();
		virtual ~CMatrix22();

		double m[2][2];
	};

	//  ��ά����
	class  BW_VEHICLEKINEMATIC_API CVector3  
	{
	public:
		CVector3();
		virtual ~CVector3();

		double x, y, z;
	};

	//  ���׷���
	class  BW_VEHICLEKINEMATIC_API CMatrix33  
	{
	public:
		CMatrix33();
		virtual ~CMatrix33();

		double m[3][3];
	};


	//  ��Բ�����û��˵������λΪ���ȡ��ס��롣

	class  BW_VEHICLEKINEMATIC_API CGreatCircle
	{
	public:
		void cal_ShadowInGreatCircle( double *platiS_rad, double *plongiS_rad, double *palfa_rad, double lati_rad, double longi_rad );

		double get_psai( double lati_rad, double longi_rad, double alfa_rad );

		double get_alfa( double x, double z );

		void set_GreatCircle( double lati1_rad, double longi1_rad, double lati2_rad, double longi2_rad );

		CGreatCircle();
		virtual ~CGreatCircle();

		double S;      //  ������Բ�����������Բ���棩
		double A;      //  ������ԲԲ�Ľ�

		double psai1;  //  ����ƫ����
		double psai2;  //  �յ��ƫ����

		double alfa1;  //  ����ڴ�Բ����ϵ�ļ���
		double alfa2;  //  �յ��ڴ�Բ����ϵ�ļ���

		double latiN;   //  ��Բ���γ��
		double longiN;  //  ��Բ��ľ���

		CVector3 V;  //  ��Բ������

		CMatrix33 MGC_C;  //  ��Բֱ����ϵת������
	};


	//  ��·�㡣���û��˵������λΪ���ȡ��ס��롣

	class  BW_VEHICLEKINEMATIC_API CRoutePoint
	{
	public:
		double get_alti( );
		double get_lati( );
		double get_longi( );
		double get_speed( );

		//  ���ú�·��
		void set_RoutePoint( double _lati_rad, double _longi_rad, double _alti_m, double _GS_mps, bool _bCross );

		CRoutePoint();
		virtual ~CRoutePoint();

		bool m_bCross;  //  Ҫ������־��

	private:

		double GS;     //  ����
		double lati;   //  γ��
		double longi;  //  ����
		double alti;   //  ����
	};


	//  ��Բ���ߡ����û��˵������λΪ���ȡ��ס��롣

#define NRP 32  //  ��·���������

	class  BW_VEHICLEKINEMATIC_API CRoute 
	{
	public:
		//  �����պϺ���
		bool roll_route( int iStart, bool bCounterClockWise );

		//  �ߵ�����
		void reverse_route( void );

		//  ��ú��������·������
		int get_iRPMax( );

		//  �������㣺�����к�·���ֵ��Ϊ��ǰ���ֵ
		void clear_route( double alti_m, double lati_rad, double longi_rad );

		//  �������㣺�����·�������Ϊ 0
		void clear_route( );

		//  ���뺽·�㣨ǿ�Ʋ������˳�����뷽ʽ��
		bool input_point( double lati_rad, double longi_rad, double alti_m, double GS_mps, bool bCross );

		//  ���㺽�ߡ��ӵ� i �㿪ʼ���㵽���һ�㡣
		void cal_routei_( int i, double alti_m, double lati_rad, double longi_rad, double GS_mps );

		//  ���㺽�ߡ��ӵ� 1 �㿪ʼ���㵽���һ�㡣
		void cal_route1_( );

		CRoute();
		virtual ~CRoute();

		double m_dRouteRad;  //  ������ת��

		int m_i0;  //  �������

		double RangeDelta[NRP-1];  //  ����·��֮��ľ��루��Բ������
		double RangeRemain[NRP];   //  ����·���ʣ�����

		CGreatCircle GC[NRP-1];  //  �����ζ�Ӧ�Ĵ�Բ

		CRoutePoint RP[NRP];  //  ��·��

	private:
		int m_iRPMax;  //  ���·�����
	};


	//  ���ߺ��ߡ����û��˵������λΪ���ȡ��ס��롣2016-07-07��

	class  BW_VEHICLEKINEMATIC_API CRouteCurve
	{
	public:
		//  ������ĳλ�õļ���
		double get_r( double A_deg );

		//  ������ĳλ�õ����ʰ뾶
		double get_rou( double A_deg );

		//  ������ĳλ�õĺ���
		double get_psai( double A_deg );

		//  ��������
		void create_curve( double _a, double _b, double psai0_rad, int iType, bool bCounterClockWise );

		CRouteCurve();
		virtual ~CRouteCurve();

		//  �����ĵ�Ϊԭ��ĵ���ϵ���꣨��ͼ����ʾ�ã��������ã�
		double xs[37];
		double zs[37];

	private:

		bool m_bCounterClockWise;  //  ��ʱ������ֻ�����ڷ�����ߣ�

		int m_iType;  //  �������͡�0��Բ��1����Բ��3��8����

		double a;  //  ����뾶
		double b;  //  ����뾶
		double psai0;  //  ���ẽ��

		//  ���ߺ�������
		double As[37];    //  ���ǣ���
		double rs[37];    //  ���뾶
		double psais[37];  //  ���غ���
		double rous[37];   //  �������ʰ뾶
	};

	//#undef NRP


#define NPos 6

	class BW_VEHICLEKINEMATIC_API CFormationServer  //  ��ӷ�������2017-12-15
	{
	public:

		//  �趨����λ�ò���
		bool set_pos( int iPos, double x_m, double y_m, double z_m );

		//  ˢ�¡�
		void refresh( int iPos, double longi_rad, double lati_rad, double alti_m, double v_mps, double teta_rad, double psais_rad, double gamas_rad, CVector3 v_rg_m, CVector3 v_vg_mps, CVector3 v_omg_radps );

		CFormationServer();
		virtual ~CFormationServer();

		//  ����Աʵ��λ��
		double f_longi_rad[NPos];
		double f_lati_rad[NPos];
		double f_alti_m[NPos];

		//  ����ԱĿ��λ�ã����ڱ��Ч�����ԣ���2018-03-17
		double f_obj_longi_rad[NPos];
		double f_obj_lati_rad[NPos];
		double f_obj_alti_m[NPos];

		double f_vg_obj[NPos];  //  �Ż�Ŀ���ٶ�

		CVector3 v_delta_rNow[NPos];  //  �Ż������վλ��λ��ƫ��
		CVector3 v_delta_vNow[NPos];  //  �Ż�����ڳ������ٶ�
		CVector3 v_r_0_Now[NPos];     //  �Ż�����ڳ�����λ��ƫ��

		//  �����˶�����
		double f_alti0;
		double f_vg0;
		double f_teta0;
		double f_psais0;
		double f_gamas0;

		//  �������ٶ�ͶӰ�ڳ����ٶ���ϵ
		CVector3 v_omg0;

		//  �����ٶ�ͶӰ�ڵ���ϵ
		CVector3 v_vg0;

		//  ��������
		//	CVector3 v_rg0;

		//  ��������ת�����󣺵���ϵ -> �ٶ���ϵ
		CMatrix33 MVG0, MGV0;

		//  �Ż��ڳ����ο�ϵ��Ŀ��λ��
		CVector3 v_delta_r_obj[NPos];

	};

#undef NPos


}  //  namespace end


#endif
