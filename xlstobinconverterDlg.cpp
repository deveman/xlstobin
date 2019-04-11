// xlstobinconverterDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "xlstobinconverter.h"
#include "xlstobinconverterDlg.h"

#include "xlstobin.h"	//eg20080630

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXlstobinconverterDlg ダイアログ

CXlstobinconverterDlg::CXlstobinconverterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXlstobinconverterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXlstobinconverterDlg)
		// メモ: この位置に ClassWizard によってメンバの初期化が追加されます。
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXlstobinconverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXlstobinconverterDlg)
		// メモ: この場所には ClassWizard によって DDX と DDV の呼び出しが追加されます。
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CXlstobinconverterDlg, CDialog)
	//{{AFX_MSG_MAP(CXlstobinconverterDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CONVERT, OnBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	ON_BN_CLICKED(IDC_BTN_XLS, OnBtnOpenXLS)
	ON_BN_CLICKED(IDC_BTN_BIN, OnBtnOpenBIN)
	ON_BN_CLICKED(IDC_BTN_XLS_CLEAR, OnBtnXLSClear)
	ON_BN_CLICKED(IDC_BTN_BIN_CLEAR, OnBtnBINClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXlstobinconverterDlg メッセージ ハンドラ

BOOL CXlstobinconverterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定
	
	// TODO: 特別な初期化を行う時はこの場所に追加してください。
	//↓eg20080703
	GetDlgItem(IDC_BTN_BIN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(FALSE);

	GetDlgItem(IDC_BTN_XLS_CLEAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(FALSE);
	//↑eg20080703

	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
}

// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。

void CXlstobinconverterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
HCURSOR CXlstobinconverterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//↓eg20080703
void CXlstobinconverterDlg::OnBtnOpen() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	Cxlstobin xlstobin;

	GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_XLS)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_BIN)->EnableWindow(FALSE);

	GetDlgItemText(IDC_EDIT_XLS, m_sXLSFilePath);
	GetDlgItemText(IDC_EDIT_BIN, m_sBINFolderPath);

	if( m_sXLSFilePath.IsEmpty() )
	{
		GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_XLS)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_BIN)->EnableWindow(TRUE);

		GetDlgItem(IDC_BTN_XLS_CLEAR)->EnableWindow(FALSE);
	
		return;
	}

	if( m_sBINFolderPath.IsEmpty() )
	{
		GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_XLS)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_BIN)->EnableWindow(TRUE);
	
		GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(FALSE);

		return;
	}

	char backslash = '\\';
	char dot = '.';

	unsigned int nBackslash = 0;
	unsigned int ndot = 0;


	nBackslash = m_sXLSFilePath.ReverseFind(backslash) + 1;
	nBackslash = m_sXLSFilePath.GetLength() - nBackslash;
	m_sXLSFile = m_sXLSFilePath.Right(nBackslash);

	ndot = m_sXLSFile.Find(dot);
	m_sBINFile = m_sXLSFile.Left(ndot) + ".bin";
	m_sBINFilePath = m_sBINFolderPath + "\\" + m_sBINFile;





	if( (xlstobin.xlsOpen(m_sXLSFilePath) == TRUE) && (xlstobin.binOpen(m_sBINFilePath)) )
	{
		while( xlstobin.xls_IsEOF() )
		{
			if( xlstobin.xlsRead() == TRUE )
			{
				xlstobin.xlsParse();

				xlstobin.binWrite();
			}
		}

		// close xls and bin files 
		// xls,binのファイルを閉じる
		xlstobin.xlsClose();
		xlstobin.binClose();
	}

	else
	{
		MessageBox("Error opening files!");

	}

	GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_XLS)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_BIN)->EnableWindow(TRUE);


}
//↑eg20080703

void CXlstobinconverterDlg::OnBtnCancel() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	OnOK();
}

void CXlstobinconverterDlg::OnBtnOpenXLS() 
{
	CString strXLS;
	CString strBIN;
	
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CFileDialog FileDlg(
		TRUE,	//開く
		"csv",	//デフォルトの拡張子
		m_sXLSFile,	//デフォルトのファイル名
		OFN_FILEMUSTEXIST|
		OFN_HIDEREADONLY|
		OFN_LONGNAMES,	//フラグ
		"CSVファイル	(*.csv)|*.csv|"
		"全てのファイル(*.*)|*.*||",	//フィルタ
		NULL	//親ウィンドウ
		);

	if( FileDlg.DoModal() == IDOK )
	{
		strXLS = FileDlg.GetPathName();

		char backslash = '\\';
		unsigned int nbackslash = strXLS.ReverseFind(backslash);
		strBIN = strXLS.Left(nbackslash);

		SetDlgItemText(IDC_EDIT_XLS, strXLS);
		SetDlgItemText(IDC_EDIT_BIN, strBIN);

		GetDlgItem(IDC_BTN_BIN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(TRUE);

		GetDlgItem(IDC_BTN_XLS_CLEAR)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(TRUE);

	}

}

void CXlstobinconverterDlg::OnBtnOpenBIN() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	
	CFolderDialog FolderDlg;
	CString strBIN;
	
	if( FolderDlg.DoModal() == IDOK )
	{
		strBIN = FolderDlg.GetFolderPath();
		SetDlgItemText(IDC_EDIT_BIN, strBIN);

		GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(TRUE);
	}
	
}

void CXlstobinconverterDlg::OnBtnXLSClear() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	SetDlgItemText(IDC_EDIT_XLS, "");
	SetDlgItemText(IDC_EDIT_BIN, "");

	GetDlgItem(IDC_BTN_XLS_CLEAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(FALSE);

	GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_BIN)->EnableWindow(FALSE);
}

void CXlstobinconverterDlg::OnBtnBINClear() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	SetDlgItemText(IDC_EDIT_BIN, "");

	GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(FALSE);

}
