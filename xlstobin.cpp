// xlstobin.cpp: Cxlstobin クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "xlstobinconverter.h"
#include "xlstobin.h"

#include <stdio.h>	// for fopen, fread, fclose

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define NEWLINE FALSE	// TRUE  : new line every after data type
						// FALSE : no new line every after data type


/* Version Information
FILEVERSION 1.0.0.1 eg20080630
 - initial dialog design, code skeleton
 - created class Cxlstobin to convert an xls file to bin file

FILEVERSION 1.0.0.2 eg20080701
 -

FILEVERSION 1.0.0.3 eg20080702
 - folder dialog
 - binary file correct writtten
*/

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

Cxlstobin::Cxlstobin()
{
	Init();
}

Cxlstobin::~Cxlstobin()
{

}

void Cxlstobin::Init()
{
	xls_fileptr = NULL;	
	bin_fileptr = NULL;	

	memset( buffer, 0, MAXBUFFERSIZE);

	memset( &xlsData[0], 0, MAXBUFFERSIZE * sizeof(EXCELDATA) );
	nIndex = 0;

}

BOOL Cxlstobin::xlsOpen(const char *szFilePath)
{
	ASSERT(szFilePath);
	
	if( (xls_fileptr = fopen( szFilePath, "rt" )) != NULL )
	{
		return TRUE;
	}
	
	else
	{
		return FALSE;
	}
}

BOOL Cxlstobin::binOpen(const char *szFilePath)
{
	ASSERT(szFilePath);
	
	if( (bin_fileptr = fopen( szFilePath, "wb" )) != NULL )
	{
		return TRUE;
	}
	
	else
	{
		return FALSE;
	}
}

BOOL Cxlstobin::xlsClose()
{
	if( xls_fileptr )
	{
		if( fclose(xls_fileptr) == 0 )
		{
			//fclose returns 0 if the stream is successfully closed
			return TRUE;
		}

		else
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOL Cxlstobin::binClose()
{
	if( bin_fileptr )
	{
		if( fclose(bin_fileptr) == 0 )
		{
			//fclose returns 0 if the stream is successfully closed
			return TRUE;
		}

		else
		{
			return FALSE;
		}
	}

	return TRUE;
}



BOOL Cxlstobin::xlsRead()
{
//	if( fread( buffer, MAXBUFFERSIZE, 1, xls_fileptr) )	
	if( fgets( buffer, MAXBUFFERSIZE, xls_fileptr ) )
	{
		nIndex++;

		return TRUE;
	}

	else
		return FALSE;

}

BOOL Cxlstobin::xls_IsEOF()
{
	if( !feof(xls_fileptr) )
	{
		return TRUE;
	}

	else
	{
		return FALSE;
	}
}

BOOL Cxlstobin::binWrite()
{	
	switch( xlsData[nIndex - 1].type )
	{
		case DATA_CHAR:
		{
			char data_CHAR = (char)xlsData[nIndex - 1].value;
						
			fwrite( &data_CHAR, sizeof(char), 1, bin_fileptr);
#if NEWLINE
			fwrite("\n", sizeof(char), 1, bin_fileptr);
#endif
			TRACE("DATA_CHAR : %c [%d bytes]\r\n", (xlsData[nIndex - 1].value), sizeof(char) );
			break;
		}

		case DATA_BYTE:
		{
			BYTE data_BYTE = (BYTE)xlsData[nIndex - 1].value;
		
			fwrite( &data_BYTE, sizeof(BYTE), 1, bin_fileptr);
#if NEWLINE
			fwrite("\n", sizeof(char), 1, bin_fileptr);
#endif
			TRACE("DATA_BYTE : %c [%d bytes]\r\n", (xlsData[nIndex - 1].value), sizeof(BYTE) );
			break;
		}	
	
		case DATA_SHORT:
		{
			short data_SHORT = (short)atoi(xlsData[nIndex - 1].value);
			
			fwrite( &data_SHORT, sizeof(short), 1, bin_fileptr);
#if NEWLINE
			fwrite("\n", sizeof(char), 1, bin_fileptr);
#endif			
			TRACE("DATA_SHORT : %d [%d bytes]\r\n", atoi(xlsData[nIndex - 1].value), sizeof(short) );
			break;
		}

		case DATA_INT:
		{
			int data_INT = (int)atoi(xlsData[nIndex - 1].value);

			fwrite( &data_INT, 2, 1, bin_fileptr); //sizeof(int) is 2! 
		//	fwrite( &data_INT, sizeof(int), 1, bin_fileptr);
#if NEWLINE
			fwrite("\n", sizeof(char), 1, bin_fileptr);
#endif		
			TRACE("DATA_INT : %d [%d bytes]\r\n", atoi(xlsData[nIndex - 1].value), sizeof(int) );
			break;
		}

		case DATA_LONG:
		{
			long data_LONG = (long)atoi(xlsData[nIndex - 1].value);

			fwrite( &data_LONG, sizeof(long), 1, bin_fileptr);
#if NEWLINE
			fwrite("\n", sizeof(char), 1, bin_fileptr);
#endif	
			TRACE("DATA_LONG : %d [%d bytes]\r\n", atoi(xlsData[nIndex - 1].value), sizeof(long) );
			break;
		}

		case DATA_FLOAT:
		{
			float data_FLOAT = (float)atof(xlsData[nIndex - 1].value);	

			fwrite( &data_FLOAT, sizeof(float), 1, bin_fileptr);
#if NEWLINE
			fwrite("\n", sizeof(char), 1, bin_fileptr);
#endif
			TRACE("DATA_FLOAT : %#.3f [%d bytes]\r\n", atof(xlsData[nIndex - 1].value), sizeof(float) );
			break;
		}

		case DATA_DOUBLE:
		{
			double data_DOUBLE = (double)atof(xlsData[nIndex - 1].value);
			
			fwrite(&data_DOUBLE, sizeof(double), 1, bin_fileptr);
#if NEWLINE
			fwrite("\n", sizeof(char), 1, bin_fileptr);
#endif
			TRACE("DATA_DOUBLE : %#.6f [%d bytes]\r\n", atof(xlsData[nIndex - 1].value), sizeof(double) );
			break;
		}
		
		case DATA_STRING:
		{
		//	CString str(xlsData[nIndex - 1].value);

			fwrite(xlsData[nIndex - 1].value,  xlsData[nIndex - 1].length, 1, bin_fileptr);
#if NEWLINE
			fwrite("\n", sizeof(char), 1, bin_fileptr);
#endif		
			TRACE("DATA_STRING : %s [%d bytes]\r\n", (xlsData[nIndex - 1].value),  xlsData[nIndex - 1].length );
			break;
		}

		default: // DATA_UNKNOWN:
		{
		//	MessageBox(NULL, "Data type unknown!", "", MB_OK);	
			
			TRACE("DATA_UNKNOWN : %s [%d bytes]\r\n", (xlsData[nIndex - 1].value),  xlsData[nIndex - 1].length );
			break;
		}

	}

#if 0
	if( nSize != 0 )
	{
		fwrite( xlsData[nIndex - 1].value, nSize, 1, bin_fileptr );
		fwrite("\n", sizeof(char), 1, bin_fileptr);
	}
#endif

	return TRUE;

	
#if 0	
	if( (CString)xlsData[nIndex - 1].value == "DATA")
	{
		MessageBox(NULL, "Data!", "", MB_OK);

		fprintf( bin_fileptr, (CString)xlsData[nIndex - 1].value);

	}
#endif	
	
	
//	if( fprintf( bin_fileptr, buffer) > 0)
//		return TRUE;

//	else
//		return FALSE;

}

BOOL Cxlstobin::xlsParse()
{
	CString str(buffer);
	CString token;
	CString remain;
	int n, ntotal;
	
	ntotal = str.GetLength();
	
	str.Replace(",","\n");

	n = str.Find("\n", 0);
	token = str.Left(n);
	str = str.Right(ntotal - n - 1);
	ntotal = str.GetLength();

	strcpy(xlsData[nIndex - 1].label, token);

	n = str.Find("\n", 0);
	token = str.Left(n);
	str = str.Right( (ntotal - n) - 1);
	ntotal = str.GetLength();

	strcpy(xlsData[nIndex - 1].value, token);

	n = str.Find("\n", 0);
	token = str.Left(n);
	str = str.Right(ntotal - n - 1);

	xlsData[nIndex - 1].type = DetermineVarType(token);

	if( xlsData[nIndex - 1].type == DATA_STRING )
	{
		n = str.Find("\n", 0);
		token = str.Left(n);
		str = str.Right(ntotal - n - 1);
		
		xlsData[nIndex - 1].length = atoi(token);
	}

#if 0
	char *ptr, *p = &buffer[0];	
	
	p = ptr = strstr( p, "," );
	if( ptr == NULL ) return TRUE;

	*ptr = 0;
	strcpy(xlsData[nIndex - 1].label, p);
	p = ptr + 1;

	ptr = strstr( p, "," );
	if( ptr == NULL ) return TRUE;

	*ptr = 0;
	strcpy(xlsData[nIndex - 1].value, p);
	p = ptr + 1;

	ptr = strstr( p, "," );
	if( ptr == NULL ) return TRUE;

	*ptr = 0;
	xlsData[nIndex - 1].type = DetermineVarType(p);
	p = ptr + 1;

	if( xlsData[nIndex - 1].type == DATA_STRING )
	{
		ptr = strstr( p, "," );
//		if( ptr == NULL ) return TRUE;
	
//		*ptr = 0;
		xlsData[nIndex - 1].length = atoi(p);
		p = ptr + 1;
	}
#endif

	return TRUE;
}

DATA_TYPE Cxlstobin::DetermineVarType(const char* p)
{
	CString str(p);
	str.TrimLeft();
	str.TrimRight();
	str.MakeLower();

	if( strcmp(str, "char")        == 0 )
		return DATA_CHAR;

	else if( strcmp(str, "byte")   == 0 )
		return DATA_BYTE;

	else if( strcmp(str, "short")  == 0 )
		return DATA_SHORT;

	else if( strcmp(str, "int")    == 0 )
		return DATA_INT;

	else if( strcmp(str, "long")   == 0 )
		return DATA_LONG;

	else if( strcmp(str, "float")  == 0 )
		return DATA_FLOAT;

	else if( strcmp(str, "double") == 0 )
		return DATA_DOUBLE;	

	else if( strcmp(str, "string") == 0 )
		return DATA_STRING;

	else
		return DATA_UNKNOWN;


}
