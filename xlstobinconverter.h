// xlstobinconverter.h : XLSTOBINCONVERTER �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
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

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CXlstobinconverterApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� xlstobinconverter.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CXlstobinconverterApp : public CWinApp
{
public:
	CXlstobinconverterApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CXlstobinconverterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CXlstobinconverterApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_XLSTOBINCONVERTER_H__ABC5E9C0_666A_47F7_9CCB_F273AC0EA7DC__INCLUDED_)
