// xlstobinconverter.h : XLSTOBINCONVERTER アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_XLSTOBINCONVERTER_H__ABC5E9C0_666A_47F7_9CCB_F273AC0EA7DC__INCLUDED_)
#define AFX_XLSTOBINCONVERTER_H__ABC5E9C0_666A_47F7_9CCB_F273AC0EA7DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#ifndef __FOLDERDLG_H__
    #include "src\FolderDlg.h"
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CXlstobinconverterApp:
// このクラスの動作の定義に関しては xlstobinconverter.cpp ファイルを参照してください。
//

class CXlstobinconverterApp : public CWinApp
{
public:
	CXlstobinconverterApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CXlstobinconverterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CXlstobinconverterApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XLSTOBINCONVERTER_H__ABC5E9C0_666A_47F7_9CCB_F273AC0EA7DC__INCLUDED_)
