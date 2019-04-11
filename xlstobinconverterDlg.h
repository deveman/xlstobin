// xlstobinconverterDlg.h : ヘッダー ファイル
//

#if !defined(AFX_XLSTOBINCONVERTERDLG_H__6FC6273B_4CF3_4118_858C_BDCE97EEFD97__INCLUDED_)
#define AFX_XLSTOBINCONVERTERDLG_H__6FC6273B_4CF3_4118_858C_BDCE97EEFD97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CXlstobinconverterDlg ダイアログ

class CXlstobinconverterDlg : public CDialog
{
// 構築
public:
	CXlstobinconverterDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CXlstobinconverterDlg)
	enum { IDD = IDD_XLSTOBINCONVERTER_DIALOG };
		// メモ: この位置に ClassWizard によってデータ メンバが追加されます。
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CXlstobinconverterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CXlstobinconverterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnOpen();
	afx_msg void OnBtnCancel();
	afx_msg void OnBtnOpenXLS();
	afx_msg void OnBtnOpenBIN();
	afx_msg void OnBtnXLSClear();
	afx_msg void OnBtnBINClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString m_sXLSFolderPath;	// xls folderpath
	CString m_sXLSFile;			// xls filename
	CString m_sXLSFilePath;     // xls filepath

	CString m_sBINFolderPath;	// bin folderpath
	CString m_sBINFile;			// bin filename
	CString m_sBINFilePath;		// bin filepath
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XLSTOBINCONVERTERDLG_H__6FC6273B_4CF3_4118_858C_BDCE97EEFD97__INCLUDED_)
