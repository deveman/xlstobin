// xlstobin.h: Cxlstobin クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSTOBIN_H__3067640B_A601_4428_828A_F8973F20B900__INCLUDED_)
#define AFX_XLSTOBIN_H__3067640B_A601_4428_828A_F8973F20B900__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAXBUFFERSIZE	1024

enum DATA_TYPE 
{
	DATA_CHAR = 1,
	DATA_BYTE,
	DATA_SHORT,
	DATA_INT,
	DATA_LONG,	
	DATA_FLOAT,
	DATA_DOUBLE,
	DATA_STRING,	 
	DATA_UNKNOWN
};



typedef struct tagEXCELDATA
{
	char label[32];
	char value[32];
	DATA_TYPE type;

	int length;

} EXCELDATA;


class Cxlstobin  
{
public:
	BOOL xlsParse();
	BOOL binWrite();
	BOOL xls_IsEOF();
	BOOL xlsRead();
	Cxlstobin();
	virtual ~Cxlstobin();

	void Init();

// xls
	BOOL xlsOpen(const char *szFilePath);
	BOOL xlsClose();	
	
// bin
	BOOL binOpen(const char *szFilePath);
	BOOL binClose();
	
private:
	DATA_TYPE DetermineVarType(const char* p);
	FILE *xls_fileptr;
	FILE *bin_fileptr;

	CString xlsFilePath;
	CString binFilePath;

	char buffer[MAXBUFFERSIZE];

	EXCELDATA xlsData[MAXBUFFERSIZE];
	unsigned int nIndex;
};

#endif // !defined(AFX_XLSTOBIN_H__3067640B_A601_4428_828A_F8973F20B900__INCLUDED_)
