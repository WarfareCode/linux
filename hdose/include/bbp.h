#pragma once

//消息报文最大长度
#define MSG_SIZE (50*1024)

// 节点数量
#define  NUM_PROC 8

// 缓冲区数量
#define  NUM_BUF  16
// 广播区数量
#define  NUM_BRD  4


typedef struct _MESSAGE_DES
{
	short volatile length;				// 消息长度
	char source;		        // 消息发送者
	char dat[MSG_SIZE];     //消息内容
} MESSAGE, *PMESSAGE;

typedef struct _MESSAGE_BRD_DES
{
	short volatile length;				// 消息长度
	char source;		        // 消息发送者
	BYTE des[32];		        // 消息接收者。广播时，最多32个接收者
	char dat[MSG_SIZE];     //消息内容
} MESSAGEBRD, *PMESSAGEBRD;

typedef struct _MESSAGE_AREA
{
	char volatile sendreq;
	MESSAGE msg[NUM_BUF];	// 数据区
} MESSAGE_AREA, *PMESSAGE_AREA;

typedef struct _MESSAGE_BRD
{
	MESSAGEBRD brd[NUM_BRD];	//广播区
} MESSAGE_BRD, *PMESSAGE_BRD;

/// 反射内存数据布局
typedef struct _RM_LAYOUT
{
	DWORD ProcID[NUM_PROC];
	char Node[NUM_PROC];
	MESSAGE_AREA msgArea[NUM_PROC];	// 消息数据区
	MESSAGE_BRD brdArea[NUM_PROC];  //广播区
}RM_LAYOUT, *PRM_LAYOUT;

/// 单节点数据布局
typedef void (*CloseNotityFun)(int);

class BBP
{
	CHEvent* m_rcv_evts[NUM_PROC];//因为是阻塞式接收，所以要用事件通知是否有可用的数据
	CHMutex* m_send_mutexs[NUM_PROC];//发送方需要互斥
	int GetReq(int dest);
	char m_rank;									// 当前节点ID
	PMESSAGE_AREA data;							// 当前节点数据区
	PMESSAGE_BRD brd;						// 当前节点广播区
	BYTE m_rcvReq;
public:

	char GetRank(){return m_rank;};
	int Create(int rank=-1,CloseNotityFun pFun=0);
	int	Send( int dest, char *buf, int len);
	int	Mcast( char* dests, char *buf, int len);
	int	Recv(char *buf, int maxlen,int* source=0);
	int	RecvEx(char *buf, int maxlen);//广播消息一起接收
	void Close();
	DWORD m_error;

};
