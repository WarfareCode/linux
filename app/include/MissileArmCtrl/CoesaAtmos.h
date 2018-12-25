// CoesaAtmos.h: interface for the CCoesaAtmos class.
//
//////////////////////////////////////////////////////////////////////
// 1976��COESA����ģ��
// �ɼ���85km֮�ڵĴ����¶ȡ��ܶȼ�����

#ifndef	COESA_ATMOSPHERE_H_
#define	COESA_ATMOSPHERE_H_

#define NUM1976PTS 8

class CCoesaAtmos
{
public:
    CCoesaAtmos();
    CCoesaAtmos(double Tc);
    ~CCoesaAtmos() {};
	
private:
    double Sonic;       // ���٣�m/s��
    double Rho;         // �����ܶȣ�Kg/m^3��
    double Tk;          // �¶ȣ������±꣩
	double pressure;    // ѹǿ����λ��N/m^2
	
	
public:
    void Init();
    void SetTc(double Tc);              // �����¶ȣ���λ�����϶�
    void Update(double Altitude);       // ����ָ���߶�(��λ����)�Ĵ�������
    double GetSonic(double Altitude);   // ��ȡָ���߶�(��λ����)�����٣���m/s��
    double GetRho(double Altitude);     // ��ȡָ���߶�(��λ����)�Ĵ����ܶȣ���Kg/m^3��
    double GetTk(double Altitude);      // ��ȡָ���߶�(��λ����)���¶ȣ��������±꣩
	double GetPre(double Altitude);      // ��ȡָ���߶�(��λ����)��ѹǿ����λ��N/m^2
	
private:
    double temperature76[8];//NUM1976PTS
    double pressureRatio76[8];//NUM1976PTS
    double altitude76[8];//NUM1976PTS
    double tempGradient76[8];//NUM1976PTS
};

#endif	// COESA_ATMOSPHERE_H_
