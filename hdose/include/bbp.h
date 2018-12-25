#pragma once

//��Ϣ������󳤶�
#define MSG_SIZE (50*1024)

// �ڵ�����
#define  NUM_PROC 8

// ����������
#define  NUM_BUF  16
// �㲥������
#define  NUM_BRD  4


typedef struct _MESSAGE_DES
{
	short volatile length;				// ��Ϣ����
	char source;		        // ��Ϣ������
	char dat[MSG_SIZE];     //��Ϣ����
} MESSAGE, *PMESSAGE;

typedef struct _MESSAGE_BRD_DES
{
	short volatile length;				// ��Ϣ����
	char source;		        // ��Ϣ������
	BYTE des[32];		        // ��Ϣ�����ߡ��㲥ʱ�����32��������
	char dat[MSG_SIZE];     //��Ϣ����
} MESSAGEBRD, *PMESSAGEBRD;

typedef struct _MESSAGE_AREA
{
	char volatile sendreq;
	MESSAGE msg[NUM_BUF];	// ������
} MESSAGE_AREA, *PMESSAGE_AREA;

typedef struct _MESSAGE_BRD
{
	MESSAGEBRD brd[NUM_BRD];	//�㲥��
} MESSAGE_BRD, *PMESSAGE_BRD;

/// �����ڴ����ݲ���
typedef struct _RM_LAYOUT
{
	DWORD ProcID[NUM_PROC];
	char Node[NUM_PROC];
	MESSAGE_AREA msgArea[NUM_PROC];	// ��Ϣ������
	MESSAGE_BRD brdArea[NUM_PROC];  //�㲥��
}RM_LAYOUT, *PRM_LAYOUT;

/// ���ڵ����ݲ���
typedef void (*CloseNotityFun)(int);

class BBP
{
	CHEvent* m_rcv_evts[NUM_PROC];//��Ϊ������ʽ���գ�����Ҫ���¼�֪ͨ�Ƿ��п��õ�����
	CHMutex* m_send_mutexs[NUM_PROC];//���ͷ���Ҫ����
	int GetReq(int dest);
	char m_rank;									// ��ǰ�ڵ�ID
	PMESSAGE_AREA data;							// ��ǰ�ڵ�������
	PMESSAGE_BRD brd;						// ��ǰ�ڵ�㲥��
	BYTE m_rcvReq;
public:

	char GetRank(){return m_rank;};
	int Create(int rank=-1,CloseNotityFun pFun=0);
	int	Send( int dest, char *buf, int len);
	int	Mcast( char* dests, char *buf, int len);
	int	Recv(char *buf, int maxlen,int* source=0);
	int	RecvEx(char *buf, int maxlen);//�㲥��Ϣһ�����
	void Close();
	DWORD m_error;

};
