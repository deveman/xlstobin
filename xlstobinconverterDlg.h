// xlstobinconverterDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_XLSTOBINCONVERTERDLG_H__6FC6273B_4CF3_4118_858C_BDCE97EEFD97__INCLUDED_)
#define AFX_XLSTOBINCONVERTERDLG_H__6FC6273B_4CF3_4118_858C_BDCE97EEFD97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CXlstobinconverterDlg �_�C�A���O

class CXlstobinconverterDlg : public CDialog
{
// �\�z
public:
	CXlstobinconverterDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CXlstobinconverterDlg)
	enum { IDD = IDD_XLSTOBINCONVERTER_DIALOG };
		// ����: ���̈ʒu�� ClassWizard �ɂ���ăf�[�^ �����o���ǉ�����܂��B
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CXlstobinconverterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_XLSTOBINCONVERTERDLG_H__6FC6273B_4CF3_4118_858C_BDCE97EEFD97__INCLUDED_)
