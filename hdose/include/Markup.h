// Markup.h: interface for the CMarkup class.
// 封装XML操作的类,不依赖于其他的XML操作组件

// Markup Release 6.1 Lite
// Copyright (C) 1999-2001 First Objective Software, Inc. All rights reserved
// This entire notice must be retained in this source code
// Redistributing this source code requires written permission
// This software is provided "as is", with no warranty.
// Latest fixes enhancements and documentation at www.firstobject.com

#if !defined(AFX_MARKUP_H__948A2705_9E68_11D2_A0BF_00105A27C570__INCLUDED_)
#define AFX_MARKUP_H__948A2705_9E68_11D2_A0BF_00105A27C570__INCLUDED_

//#if _MSC_VER > 1000
//#pragma once
//#endif // _MSC_VER > 1000

//#include <afxtempl.h>//??
class String;
class DS_API CMarkup
{
public:
	CMarkup();
	CMarkup( LPCTSTR szDoc ) { SetDoc( szDoc ); };
	CMarkup( const CMarkup& markup ) { *this = markup; };
	void operator=( const CMarkup& markup );
	virtual ~CMarkup();

	// Navigate

	//--new added--//
	bool GotoElem(int iPos); //将类中当前的m_iPos、m_iPosChild分别设为iPos、0 //qq added 
	
	bool SetDoc( LPCTSTR szDoc );
	bool IsWellFormed();
	bool FindElem( LPCTSTR szName=NULL );
	bool FindChildElem( LPCTSTR szName=NULL );
	bool IntoElem();
	bool OutOfElem();
	void ResetChildPos() { m_iPosChild = 0; };
	void ResetPos();
	String GetTagName() const { return x_GetTagName(m_iPos); };
	String GetChildTagName() const { return x_GetTagName(m_iPosChild); };
	String GetData() const { return x_GetData(m_iPos); }; 
	String GetChildData() const { return x_GetData(m_iPosChild); };
	String GetAttrib( LPCTSTR szAttrib ) const { return x_GetAttrib(m_iPos,szAttrib); };
	String GetChildAttrib( LPCTSTR szAttrib ) const { return x_GetAttrib(m_iPosChild,szAttrib); };
	bool GetOffsets( int& nStart, int& nEnd ) const;
	String GetError() const { return *m_csError; };

	// Create 
	LPCTSTR GetDoc() const { return m_csDoc; };
	bool AddElem( LPCTSTR szName, LPCTSTR szData=NULL );
	bool AddChildElem( LPCTSTR szName, LPCTSTR szData=NULL );
	bool AddAttrib( LPCTSTR szAttrib, LPCTSTR szValue );
	bool AddChildAttrib( LPCTSTR szAttrib, LPCTSTR szValue );

	//delete or change value
	//--new added--//
	bool DeleteElem();//删除当前m_iPos代表的element
	bool DeleteChildElem();
	bool SetAttrib(LPCTSTR szAttrib,LPCTSTR szValue);//设置当前elem中的名字为szAttrib的Atttib值
	bool SetChildAttrib( LPCTSTR szAttrib,LPCTSTR szValue);
	bool GoPrevChildElem();
protected:
	String m_csDoc;
	int m_nLevel;
	String m_csError;
	struct ElemPos
	{
		ElemPos() { Clear(); };
		ElemPos( const ElemPos& pos ) { *this = pos; };
		bool IsEmptyElement() const { return (nStartR == nEndL + 1); };
		void Clear()
		{
			nStartL=0; nStartR=0; nEndL=0; nEndR=0; nNext=0;
			iElemParent=0; iElemChild=0; iElemNext=0;iElemPrev=0;
		};
		int nStartL; //positon of left angle bracket of start tag
		int nStartR; //right angle bracket of start tag
		int nEndL;   //left angle bracket of end tag
		int nEndR;   //right angle bracket of end tag
		int nNext;   //point to the next < after this element
		int iElemParent;
		int iElemChild;
		int iElemNext;
		int iElemPrev;
	};

	CLPArray m_aPos;
	int m_iPos;
	int m_iPosChild;
	int m_iPosFree;

	int x_GetFreePos();
	int x_ReleasePos();

	struct TokenPos
	{
		TokenPos() { Clear(); };
		bool IsValid() const { return (nL <= nR); };
		void Clear() { nL=0; nR=-1; bIsString=false; };
		int nL;  //positon of the left of tag token,ie. <?xml version="1.0"?>中的?号
		int nR;
		int nNext; // nNext points to one past last char of token
		bool bIsString;
	};

	int x_ParseElem( int iPos );
	int x_ParseError( LPCTSTR szError, LPCTSTR szTag = NULL );
	bool x_FindChar( int&n, _TCHAR c ) const;
	bool x_FindToken( TokenPos& token ) const;
	String x_GetToken( const TokenPos& token ) const;
	String x_GetTagName( int iPos ) const;
	String x_GetData( int iPos ) const;
	String x_GetAttrib( int iPos, LPCTSTR szAttrib ) const;
	
	int x_Delete(int iPosParent,int iPos );//--new added function--//
	int x_SetAttrib( int iPos, LPCTSTR szAttrib,LPCTSTR szValue);//--new added function--//
	
	int x_Add( int iPosParent, int iPosBefore, LPCTSTR szName, LPCTSTR szValue );
	
	bool x_FindAttrib( TokenPos& token, LPCTSTR szAttrib=NULL ) const;
	int x_AddAttrib( int iPos, LPCTSTR szAttrib, LPCTSTR szValue );
	bool x_SetData( int iPos, LPCTSTR szData, int nCDATA );
	void x_DocChange( int nLeft, int nReplace, const LPCTSTR& csInsert,int len );
	void x_PosInsert( int iPos, int nInsertLength );
	void x_Adjust( int iPos, int nShift );
	String x_TextToDoc( LPCTSTR szText, bool bAttrib = false ) const;
	String x_TextFromDoc( int nLeft, int nRight ) const;
};
DS_API char ReadXml(char *xml_file,CMarkup &xml,char *var=0,char* value=0);
DS_API void WriteXml(char *xml_file,CMarkup &xml);

#endif // !defined(AFX_MARKUP_H__948A2705_9E68_11D2_A0BF_00105A27C570__INCLUDED_)
