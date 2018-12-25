

#pragma once
#pragma warning(disable: 4251)
#pragma warning(disable: 4996)

//////////////////////////////////////////////
template <class StructType>
class CSharedMemory
{
private:
	CMemFileMap* m_pMap;
	char   m_hSharedName[MAX_PATH];
	DWORD  m_dwMaxDataSize;
	StructType *m_pvData;

public:
	CSharedMemory(void);
	CSharedMemory(char *Name,DWORD size=0);
	~CSharedMemory(void);

	VOID Release();
	BOOL Acquire(char *Name,DWORD size=0);
	StructType *GetMemory();

	StructType *operator->();
};


template <class StructType>
CSharedMemory<StructType>::CSharedMemory(void)
{
	m_pMap = NULL;
}

template <class StructType>
CSharedMemory<StructType>::CSharedMemory(char *Name,DWORD size)
{
	m_pMap = NULL;
	Acquire(Name,size);
}
template <class StructType>
CSharedMemory<StructType>::~CSharedMemory(void)
{
	Release();
}


template <class StructType>
BOOL CSharedMemory<StructType>::Acquire(char *Name,DWORD size)
{
	m_dwMaxDataSize = 0;
	if(size==0)
		size=sizeof(StructType);

	m_dwMaxDataSize = size;
	strcpy(m_hSharedName, Name);
	m_pMap=new CMemFileMap();
	m_pvData = (StructType *)m_pMap->CreateMemMap(size,Name);

	if (m_pvData == NULL)
	{
		return FALSE;
	}

	return TRUE;
}

template <class StructType>
VOID CSharedMemory<StructType>::Release()
{
	if (m_pvData)
	{
		delete m_pMap;
		m_pMap=NULL;
		m_pvData = NULL;
	}

}

template <class StructType>
StructType *CSharedMemory<StructType>::operator->()
{
	return m_pvData;
}

template <class StructType>
StructType *CSharedMemory<StructType>::GetMemory()
{
	return m_pvData;
}
