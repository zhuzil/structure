
// structureDlg.h: 头文件
//

#pragma once
#include "linklist.h"

// CstructureDlg 对话框
class CstructureDlg : public CDialogEx
{
// 构造
public:
	CstructureDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STRUCTURE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedCreatdata();
//	CButton m_eidt;
	CEdit m_edit;
	afx_msg void OnClickedQiege();
	CEdit m_eidt;
	CEdit n_eidt;
	CEdit H_edit;
	afx_msg void OnClickedCheckh();
	afx_msg void OnClickedHuanyuan();
	afx_msg void OnClickedCheckxj();

	void mydraw(mylist* head, CClientDC* dc);
	afx_msg void OnBnClickedOk();
};
