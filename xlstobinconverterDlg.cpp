// xlstobinconverterDlg.cpp : �C���v�������e�[�V���� �t�@�C��
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
// CXlstobinconverterDlg �_�C�A���O

CXlstobinconverterDlg::CXlstobinconverterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXlstobinconverterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXlstobinconverterDlg)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ă����o�̏��������ǉ�����܂��B
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXlstobinconverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXlstobinconverterDlg)
		// ����: ���̏ꏊ�ɂ� ClassWizard �ɂ���� DDX �� DDV �̌Ăяo�����ǉ�����܂��B
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
// CXlstobinconverterDlg ���b�Z�[�W �n���h��

BOOL CXlstobinconverterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B
	//��eg20080703
	GetDlgItem(IDC_BTN_BIN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(FALSE);

	GetDlgItem(IDC_BTN_XLS_CLEAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(FALSE);
	//��eg20080703

	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

void CXlstobinconverterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
HCURSOR CXlstobinconverterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//��eg20080703
void CXlstobinconverterDlg::OnBtnOpen() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
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
		// xls,bin�̃t�@�C�������
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
//��eg20080703

void CXlstobinconverterDlg::OnBtnCancel() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	OnOK();
}

void CXlstobinconverterDlg::OnBtnOpenXLS() 
{
	CString strXLS;
	CString strBIN;
	
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	CFileDialog FileDlg(
		TRUE,	//�J��
		"csv",	//�f�t�H���g�̊g���q
		m_sXLSFile,	//�f�t�H���g�̃t�@�C����
		OFN_FILEMUSTEXIST|
		OFN_HIDEREADONLY|
		OFN_LONGNAMES,	//�t���O
		"CSV�t�@�C��	(*.csv)|*.csv|"
		"�S�Ẵt�@�C��(*.*)|*.*||",	//�t�B���^
		NULL	//�e�E�B���h�E
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
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	
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
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	SetDlgItemText(IDC_EDIT_XLS, "");
	SetDlgItemText(IDC_EDIT_BIN, "");

	GetDlgItem(IDC_BTN_XLS_CLEAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(FALSE);

	GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_BIN)->EnableWindow(FALSE);
}

void CXlstobinconverterDlg::OnBtnBINClear() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	SetDlgItemText(IDC_EDIT_BIN, "");

	GetDlgItem(IDC_BTN_BIN_CLEAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CONVERT)->EnableWindow(FALSE);

}
