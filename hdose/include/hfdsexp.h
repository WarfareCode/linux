#ifndef __HFDSEXP
#define __HFDSEXP

#ifdef DSAPI_EXPORTS
#define DS_API __declspec(dllexport)
#else
#define DS_API __declspec(dllimport)
#endif



#ifndef __AFX_H__
//##ModelId=47592A6B03B0
struct __POSITION { };
//##ModelId=47592A6B03BA
typedef __POSITION* POSITION;
#define BEFORE_START_POSITION ((POSITION)-1L)

#endif

/////////////////////////////////////////////////////////////////////////////
// Array<TYPE, ARG_TYPE>
class DS_API CHString
{
public:
	CHString();
	CHString(const CHString &s);
	CHString(const char *s);
	bool operator==(const CHString &s) const;
	const CHString& operator=(char* lpsz);
	const CHString& operator=(const CHString& s);
	~CHString();
private:
	struct DATA
	{
		char* value;
		int len;
		int ref;
	} *m_pdata;
	char m_r;
};


#define X_CDECL _cdecl
#define X_DATA
#define X_FASTCALL
#define X_DATADEF
#define X_STATIC_DATA static
#define X_STATIC static
#define X_COMDAT
#define X_DOUBLE double
#define X_TRACE0
#define X_TRACE1
#define X_ASSERT(x)
#define X_AfxIsValidString(x)
#define X_VERIFY(exp)		(exp)
#define X_countof(array) (sizeof(array)/sizeof(array[0]))
#define X_ROUND(x,y) (((x)+(y-1))&~(y-1))
#define X_ROUND4(x) X_ROUND(x, 4)

// Strings

#ifndef _OLEAUTO_H_
#ifdef OLE2ANSI
	typedef LPSTR BSTR;
#else
	typedef LPWSTR BSTR;// must (semantically) match typedef in oleauto.h
#endif
#endif

struct MyStringData
{
	long nRefs;             // reference count
	int nDataLength;        // length of data (including terminator)
	int nAllocLength;       // length of allocation
	// TCHAR data[nAllocLength]

	TCHAR* data()           // TCHAR* to managed data
		{ return (TCHAR*)(this+1); }
};

class  DS_API String
{
public:
// Constructors

	// constructs empty String
	String();
	// copy constructor
	String(const String& stringSrc);
	// from a single character
	String(TCHAR ch, int nRepeat = 1);
	// from an ANSI string (converts to TCHAR)
	String(LPCSTR lpsz);
	// from a UNICODE string (converts to TCHAR)
//	String(LPCWSTR lpsz);
	// subset of characters from an ANSI string (converts to TCHAR)
	String(LPCSTR lpch, int nLength);
	// subset of characters from a UNICODE string (converts to TCHAR)
//	String(LPCWSTR lpch, int nLength);
	// from unsigned characters
	String(const unsigned char* psz);

// Attributes & Operations

	// get data length
	int GetLength() const;
	// TRUE if zero length
	BOOL IsEmpty() const;
	// clear contents to empty
	void Empty();

	// return single character at zero-based index
	TCHAR GetAt(int nIndex) const;
	// return single character at zero-based index
	TCHAR operator[](int nIndex) const;
	// set a single character at zero-based index
	void SetAt(int nIndex, TCHAR ch);
	// return pointer to const string
	operator LPCTSTR() const;

	// overloaded assignment

	// ref-counted copy from another String
	const String& operator=(const String& stringSrc);
	// set string content to single character
	const String& operator=(TCHAR ch);
#ifdef _UNICODE
	const String& operator=(char ch);
#endif
	// copy string content from ANSI string (converts to TCHAR)
	const String& operator=(LPCSTR lpsz);
	// copy string content from UNICODE string (converts to TCHAR)
	const String& operator=(LPCWSTR lpsz);
	// copy string content from unsigned chars
	const String& operator=(const unsigned char* psz);

	// string concatenation

	// concatenate from another String
	const String& operator+=(const String& string);

	// concatenate a single character
	const String& operator+=(TCHAR ch);
#ifdef _UNICODE
	// concatenate an ANSI character after converting it to TCHAR
	const String& operator+=(char ch);
#endif
	// concatenate a UNICODE character after converting it to TCHAR
	const String& operator+=(LPCTSTR lpsz);

	friend String DS_API  operator+(const String& string1,
			const String& string2);
	friend String DS_API  operator+(const String& string, TCHAR ch);
	friend String DS_API  operator+(TCHAR ch, const String& string);
#ifdef _UNICODE
	friend String DS_API  operator+(const String& string, char ch);
	friend String DS_API  operator+(char ch, const String& string);
#endif
	friend String DS_API  operator+(const String& string, LPCTSTR lpsz);
	friend String DS_API  operator+(LPCTSTR lpsz, const String& string);

	// string comparison

	// straight character comparison
	int Compare(LPCTSTR lpsz) const;
	// compare ignoring case
	int CompareNoCase(LPCTSTR lpsz) const;
	// NLS aware comparison, case sensitive
	int Collate(LPCTSTR lpsz) const;
	// NLS aware comparison, case insensitive
	int CollateNoCase(LPCTSTR lpsz) const;

	// simple sub-string extraction

	// return nCount characters starting at zero-based nFirst
	String Mid(int nFirst, int nCount) const;
	// return all characters starting at zero-based nFirst
	String Mid(int nFirst) const;
	// return first nCount characters in string
	String Left(int nCount) const;
	// return nCount characters from end of string
	String Right(int nCount) const;

	//  characters from beginning that are also in passed string
	String SpanIncluding(LPCTSTR lpszCharSet) const;
	// characters from beginning that are not also in passed string
	String SpanExcluding(LPCTSTR lpszCharSet) const;

	// upper/lower/reverse conversion

	// NLS aware conversion to uppercase
	void MakeUpper();
	// NLS aware conversion to lowercase
	void MakeLower();
	// reverse string right-to-left
	void MakeReverse();

	// trimming whitespace (either side)

	// remove whitespace starting from right edge
	void TrimRight();
	// remove whitespace starting from left side
	void TrimLeft();

	// trimming anything (either side)
	// remove continuous occurrences of chTarget starting from right
	void TrimRight(TCHAR chTarget);
	// remove continuous occcurrences of characters in passed string,
	// starting from right
	void TrimRight(LPCTSTR lpszTargets);
	// remove continuous occurrences of chTarget starting from left
	void TrimLeft(TCHAR chTarget);
	// remove continuous occcurrences of characters in
	// passed string, starting from left
	void TrimLeft(LPCTSTR lpszTargets);

	// advanced manipulation

	// replace occurrences of chOld with chNew
	int Replace(TCHAR chOld, TCHAR chNew);
	// replace occurrences of substring lpszOld with lpszNew;
	// empty lpszNew removes instances of lpszOld
	int Replace(LPCTSTR lpszOld, LPCTSTR lpszNew);
	// remove occurrences of chRemove
	int Remove(TCHAR chRemove);
	// insert character at zero-based index; concatenates
	// if index is past end of string
	int Insert(int nIndex, TCHAR ch);
	// insert substring at zero-based index; concatenates
	// if index is past end of string
	int Insert(int nIndex, LPCTSTR pstr);
	// delete nCount characters starting at zero-based index
	int Delete(int nIndex, int nCount = 1);

	// searching

	// find character starting at left, -1 if not found
	int Find(TCHAR ch) const;
	// find character starting at right
	int ReverseFind(TCHAR ch) const;
	// find character starting at zero-based index and going right
	int Find(TCHAR ch, int nStart) const;
	// find first instance of any character in passed string
	int FindOneOf(LPCTSTR lpszCharSet) const;
	// find first instance of substring
	int Find(LPCTSTR lpszSub) const;
	// find first instance of substring starting at zero-based index
	int Find(LPCTSTR lpszSub, int nStart) const;

	// simple formatting

	// printf-like formatting using passed string
	void X_CDECL Format(LPCTSTR lpszFormat, ...);
	// printf-like formatting using referenced string resource
	// printf-like formatting using variable arguments parameter
	void FormatV(LPCTSTR lpszFormat, va_list argList);

	// formatting for localization (uses FormatMessage API)

	// format using FormatMessage API on passed string
//	void X_CDECL FormatMessage(LPCTSTR lpszFormat, ...);
	// format using FormatMessage API on referenced string resource

	// input and output
	// load from string resource
//	BOOL LoadString(UINT nID);



#ifndef _AFX_NO_BSTR_SUPPORT
	// OLE BSTR support (use for OLE automation)

	// return a BSTR initialized with this String's data
	BSTR AllocSysString() const;
	// reallocates the passed BSTR, copies content of this String to it
	BSTR SetSysString(BSTR* pbstr) const;
#endif

	// Access to string implementation buffer as "C" character array

	// get pointer to modifiable buffer at least as long as nMinBufLength
	LPTSTR GetBuffer(int nMinBufLength);
	// release buffer, setting length to nNewLength (or to first nul if -1)
	void ReleaseBuffer(int nNewLength = -1);
	// get pointer to modifiable buffer exactly as long as nNewLength
	LPTSTR GetBufferSetLength(int nNewLength);
	// release memory allocated to but unused by string
	void FreeExtra();

	// Use LockBuffer/UnlockBuffer to turn refcounting off

	// turn refcounting back on
	LPTSTR LockBuffer();
	// turn refcounting off
	void UnlockBuffer();

// Implementation
public:
	~String();
	int GetAllocLength() const;

protected:
	LPTSTR m_pchData;   // pointer to ref counted string data

	// implementation helpers
	MyStringData* GetData() const;
	void Init();
	void AllocCopy(String& dest, int nCopyLen, int nCopyIndex, int nExtraLen) const;
	void AllocBuffer(int nLen);
	void AssignCopy(int nSrcLen, LPCTSTR lpszSrcData);
	void ConcatCopy(int nSrc1Len, LPCTSTR lpszSrc1Data, int nSrc2Len, LPCTSTR lpszSrc2Data);
	void ConcatInPlace(int nSrcLen, LPCTSTR lpszSrcData);
	void CopyBeforeWrite();
	void AllocBeforeWrite(int nLen);
	void Release();
	static void PASCAL Release(MyStringData* pData);
	static int PASCAL SafeStrlen(LPCTSTR lpsz);
	static void X_FASTCALL FreeData(MyStringData* pData);
};

// Compare helpers
bool  DS_API  operator==(const String& s1, const String& s2);
bool  DS_API  operator==(const String& s1, LPCTSTR s2);
bool  DS_API  operator==(LPCTSTR s1, const String& s2);
bool  DS_API  operator!=(const String& s1, const String& s2);
bool  DS_API  operator!=(const String& s1, LPCTSTR s2);
bool  DS_API  operator!=(LPCTSTR s1, const String& s2);
bool  DS_API  operator<(const String& s1, const String& s2);
bool  DS_API  operator<(const String& s1, LPCTSTR s2);
bool  DS_API  operator<(LPCTSTR s1, const String& s2);
bool  DS_API  operator>(const String& s1, const String& s2);
bool  DS_API  operator>(const String& s1, LPCTSTR s2);
bool  DS_API  operator>(LPCTSTR s1, const String& s2);
bool  DS_API  operator<=(const String& s1, const String& s2);
bool  DS_API  operator<=(const String& s1, LPCTSTR s2);
bool  DS_API  operator<=(LPCTSTR s1, const String& s2);
bool  DS_API  operator>=(const String& s1, const String& s2);
bool  DS_API  operator>=(const String& s1, LPCTSTR s2);
bool  DS_API  operator>=(LPCTSTR s1, const String& s2);

// conversion helpers
//int X_CDECL x_wcstombsz(char* mbstr, const wchar_t* wcstr, size_t count);
//int X_CDECL x_mbstowcsz(wchar_t* wcstr, const char* mbstr, size_t count);

// Globals
extern X_DATA TCHAR ChNil;


extern LPCTSTR _PchNil;
#define EmptyString ((String&)*(String*)&_PchNil)


inline MyStringData* String::GetData() const
	{ X_ASSERT(m_pchData != NULL); return ((MyStringData*)m_pchData)-1; }

inline void String::Init()
	{ m_pchData = EmptyString.m_pchData; }
#ifndef _AFXDLL

inline String::String()
	{ m_pchData = EmptyString.m_pchData; }
#endif

inline String::String(const unsigned char* lpsz)
	{ Init(); *this = (LPCSTR)lpsz; }

inline const String& String::operator=(const unsigned char* lpsz)
	{ *this = (LPCSTR)lpsz; return *this; }
#ifdef _UNICODE

inline const String& String::operator+=(char ch)
	{ *this += (TCHAR)ch; return *this; }

inline const String& String::operator=(char ch)
	{ *this = (TCHAR)ch; return *this; }
inline String DS_API  operator+(const String& string, char ch)
	{ return string + (TCHAR)ch; }
inline String DS_API  operator+(char ch, const String& string)
	{ return (TCHAR)ch + string; }
#endif


inline int String::GetLength() const
	{ return GetData()->nDataLength; }

inline int String::GetAllocLength() const
	{ return GetData()->nAllocLength; }

inline BOOL String::IsEmpty() const
	{ return GetData()->nDataLength == 0; }

inline String::operator LPCTSTR() const
	{
	return m_pchData;
 }

inline int PASCAL String::SafeStrlen(LPCTSTR lpsz)
	{ return (lpsz == NULL) ? 0 : lstrlen(lpsz); }

// String support (windows specific)

inline int String::Compare(LPCTSTR lpsz) const
	{ X_ASSERT(X_AfxIsValidString(lpsz)); return _tcscmp(m_pchData, lpsz); }    // MBCS/Unicode aware

inline int String::CompareNoCase(LPCTSTR lpsz) const
	{ X_ASSERT(X_AfxIsValidString(lpsz)); return _tcsicmp(m_pchData, lpsz); }   // MBCS/Unicode aware
// String::Collate is often slower than Compare but is MBSC/Unicode
//  aware as well as locale-sensitive with respect to sort order.

inline int String::Collate(LPCTSTR lpsz) const
	{ X_ASSERT(X_AfxIsValidString(lpsz)); return _tcscoll(m_pchData, lpsz); }   // locale sensitive

inline int String::CollateNoCase(LPCTSTR lpsz) const
	{ X_ASSERT(X_AfxIsValidString(lpsz)); return _tcsicoll(m_pchData, lpsz); }   // locale sensitive


inline TCHAR String::GetAt(int nIndex) const
{
	X_ASSERT(nIndex >= 0);
	X_ASSERT(nIndex < GetData()->nDataLength);
	return m_pchData[nIndex];
}

inline TCHAR String::operator[](int nIndex) const
{
	// same as GetAt
	X_ASSERT(nIndex >= 0);
	X_ASSERT(nIndex < GetData()->nDataLength);
	return m_pchData[nIndex];
}
inline bool DS_API  operator==(const String& s1, const String& s2)
	{ return s1.Compare(s2) == 0; }
inline bool DS_API  operator==(const String& s1, LPCTSTR s2)
	{ return s1.Compare(s2) == 0; }
inline bool DS_API  operator==(LPCTSTR s1, const String& s2)
	{ return s2.Compare(s1) == 0; }
inline bool DS_API  operator!=(const String& s1, const String& s2)
	{ return s1.Compare(s2) != 0; }
inline bool DS_API  operator!=(const String& s1, LPCTSTR s2)
	{ return s1.Compare(s2) != 0; }
inline bool DS_API  operator!=(LPCTSTR s1, const String& s2)
	{ return s2.Compare(s1) != 0; }
inline bool DS_API  operator<(const String& s1, const String& s2)
	{ return s1.Compare(s2) < 0; }
inline bool DS_API  operator<(const String& s1, LPCTSTR s2)
	{ return s1.Compare(s2) < 0; }
inline bool DS_API  operator<(LPCTSTR s1, const String& s2)
	{ return s2.Compare(s1) > 0; }
inline bool DS_API  operator>(const String& s1, const String& s2)
	{ return s1.Compare(s2) > 0; }
inline bool DS_API  operator>(const String& s1, LPCTSTR s2)
	{ return s1.Compare(s2) > 0; }
inline bool DS_API  operator>(LPCTSTR s1, const String& s2)
	{ return s2.Compare(s1) < 0; }
inline bool DS_API  operator<=(const String& s1, const String& s2)
	{ return s1.Compare(s2) <= 0; }
inline bool DS_API  operator<=(const String& s1, LPCTSTR s2)
	{ return s1.Compare(s2) <= 0; }
inline bool DS_API  operator<=(LPCTSTR s1, const String& s2)
	{ return s2.Compare(s1) >= 0; }
inline bool DS_API  operator>=(const String& s1, const String& s2)
	{ return s1.Compare(s2) >= 0; }
inline bool DS_API  operator>=(const String& s1, LPCTSTR s2)
	{ return s1.Compare(s2) >= 0; }
inline bool DS_API  operator>=(LPCTSTR s1, const String& s2)
	{ return s2.Compare(s1) <= 0; }

template<class TYPE, class ARG_TYPE>
class Array
{
public:
// Construction

	Array();

// Attributes

	int GetSize() const;

	int GetUpperBound() const;

	void SetSize(int nNewSize, int nGrowBy = -1);

// Operations
	// Clean up

	void FreeExtra();

	void RemoveAll();

	// Accessing elements

	TYPE GetAt(int nIndex) const;

	void SetAt(int nIndex, ARG_TYPE newElement);

	TYPE& ElementAt(int nIndex);

	// Direct Access to the element data (may return NULL)

	const TYPE* GetData() const;

	TYPE* GetData();

	// Potentially growing the array

	void SetAtGrow(int nIndex, ARG_TYPE newElement);

	int Add(ARG_TYPE newElement);

	int Append(const Array& src);

	void Copy(const Array& src);

	// overloaded operator helpers

	TYPE operator[](int nIndex) const;

	TYPE& operator[](int nIndex);

	// Operations that move elements around

	void InsertAt(int nIndex, ARG_TYPE newElement, int nCount = 1);

	void RemoveAt(int nIndex, int nCount = 1);

	void InsertAt(int nStartIndex, Array* pNewArray);

// Implementation
protected:

	TYPE* m_pData;   // the actual array of data

	int m_nSize;     // # of elements (upperBound - 1)

	int m_nMaxSize;  // max allocated

	int m_nGrowBy;   // grow amount

public:
	~Array();
#ifdef _DEBUG
	void AssertValid() const;
#endif
};
/////////////////////////////////////////////////////////////////////////////
// List<TYPE, ARG_TYPE>

//##ModelId=47592A6D0222
template<class TYPE, class ARG_TYPE>
class List
{
protected:
	struct CNode
	{
		CNode* pNext;
		CNode* pPrev;
		TYPE data;
	};
public:
// Construction
	List(int nBlockSize = 10);

// Attributes (head and tail)
	// count of elements
	int GetCount() const;
	BOOL IsEmpty() const;

	// peek at head or tail
	TYPE& GetHead();
	TYPE GetHead() const;
	TYPE& GetTail();
	TYPE GetTail() const;

// Operations
	// get head or tail (and remove it) - don't call on empty list !
	TYPE RemoveHead();
	TYPE RemoveTail();

	// add before head or after tail
	POSITION AddHead(ARG_TYPE newElement);
	POSITION AddTail(ARG_TYPE newElement);

	// add another list of elements before head or after tail
	void AddHead(List* pNewList);
	void AddTail(List* pNewList);

	// remove all elements
	void RemoveAll();

	// iteration
	POSITION GetHeadPosition() const;
	POSITION GetTailPosition() const;
	TYPE& GetNext(POSITION& rPosition); // return *Position++
	TYPE GetNext(POSITION& rPosition) const; // return *Position++
	TYPE& GetPrev(POSITION& rPosition); // return *Position--
	TYPE GetPrev(POSITION& rPosition) const; // return *Position--

	// getting/modifying an element at a given position
	TYPE& GetAt(POSITION position);
	TYPE GetAt(POSITION position) const;
	void SetAt(POSITION pos, ARG_TYPE newElement);
	void RemoveAt(POSITION position);

	// inserting before or after a given position
	POSITION InsertBefore(POSITION position, ARG_TYPE newElement);
	POSITION InsertAfter(POSITION position, ARG_TYPE newElement);

	// helper functions (note: O(n) speed)
	POSITION Find(ARG_TYPE searchValue, POSITION startAfter = NULL) const;
		// defaults to starting at the HEAD, return NULL if not found
	POSITION FindIndex(int nIndex) const;
		// get the 'nIndex'th element (may return NULL)

// Implementation
protected:
	CNode* m_pNodeHead;
	CNode* m_pNodeTail;
	int m_nCount;
	CNode* m_pNodeFree;
	struct __CPlex* m_pBlocks;
	int m_nBlockSize;

	CNode* NewNode(CNode*, CNode*);
	void FreeNode(CNode*);

public:
	~List();
#ifdef _DEBUG
	void AssertValid() const;
#endif
};
/////////////////////////////////////////////////////////////////////////////
// Map<KEY, ARG_KEY, VALUE, ARG_VALUE>

//##ModelId=47592A6D034B
template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>
class Map
{
protected:
	// Association
	struct CAssoc
	{
		CAssoc* pNext;
		UINT nHashValue;  // needed for efficient iteration
		KEY key;
		VALUE value;
	};
public:
// Construction
	Map(int nBlockSize = 10);

// Attributes
	// number of elements
	int GetCount() const;
	BOOL IsEmpty() const;

	// Lookup
	BOOL Lookup(ARG_KEY key, VALUE& rValue) const;

// Operations
	// Lookup and add if not there
	VALUE& operator[](ARG_KEY key);

	// add a new (key, value) pair
	void SetAt(ARG_KEY key, ARG_VALUE newValue);

	// removing existing (key, ?) pair
	BOOL RemoveKey(ARG_KEY key);
	void RemoveAll();

	// iterating all (key, value) pairs
	POSITION GetStartPosition() const;
	void GetNextAssoc(POSITION& rNextPosition, KEY& rKey, VALUE& rValue) const;

	// advanced features for derived classes
	UINT GetHashTableSize() const;
	void InitHashTable(UINT hashSize, BOOL bAllocNow = TRUE);

// Implementation
protected:
	CAssoc** m_pHashTable;
	UINT m_nHashTableSize;
	int m_nCount;
	CAssoc* m_pFreeList;
	struct __CPlex* m_pBlocks;
	int m_nBlockSize;

	CAssoc* NewAssoc();
	void FreeAssoc(CAssoc*);
	CAssoc* GetAssocAt(ARG_KEY, UINT&) const;

public:
	~Map();
#ifdef _DEBUG
	void AssertValid() const;
#endif
};

template <class Type>
class CQueue:public  List<Type,Type>
{
private:
	int m_maxlen;
	Type m_base;
public:
	CQueue();
	CQueue(int len,Type base=0);
	void Create(int len,Type base);
	Type Pop();
	bool Push(Type value);
};

class CObj;
class CEventMAP;
class ClassInfo;

struct Parameter;
struct AttributeInfo;
struct AggregateObject;



	typedef Array<AttributeInfo*,AttributeInfo*> CAttributeInfos;

	typedef Array<unsigned long,unsigned long > CULongArray;

	typedef Array<LPVOID,LPVOID > CLPArray;

	typedef Array<int,int> CIntArray;

	typedef Array<float,float> CFloatArray;

	typedef Array<double,double> CDoubleArray;

	typedef List<int,int> CIntList;

	typedef List<float,float> CFloatList;

	typedef List<double,double> CDoubleList;

	typedef List<CObj*,CObj*> CObjList;

	typedef List<ClassInfo*,ClassInfo*> CClasInfoList;

	typedef List<Parameter*,Parameter*> CParaSet;

	typedef List<AggregateObject*,AggregateObject*> CAgtList;

	typedef Map<char*,char *,CEventMAP*,CEventMAP*> CEventAllMap;

	typedef Map<DWORD,DWORD,DWORD,DWORD> CDWORDMap;

	typedef Map<int, int, CParaSet*,CParaSet*> CParaSetMap;

	typedef Map<int, int, CObj*,CObj*> CWordtoHobjMap;

	typedef Map<CHString, CHString&, unsigned int,unsigned int&> CStringtoWordMap;

#endif
