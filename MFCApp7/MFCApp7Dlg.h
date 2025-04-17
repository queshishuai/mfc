
// MFCApp7Dlg.h: 头文件
//

#pragma once
#include <string>
#include <vector>

// CMFCApp7Dlg 对话框
class CMFCApp7Dlg : public CDialog
{
// 构造
public:
	CMFCApp7Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	void OnSize(UINT nType, int cx, int cy);

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cdx;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	BOOL createDirectory(const CString& directoryPath);
	void* ReadFileToBuffer(const CString& filePath, size_t& fileSize);
	void writeFile(const CString& filePath, const std::string& content);
	void writeBinFile(const CString& filePath, char* buf, size_t size);
	void appendToFile(const CString& filePath, const std::string& content);
	std::vector<CString> m_strFilePathAndName;//文件名包含路径
	CString m_strFilePath;//文件路径
	std::vector<CString> m_strFileName;//文件名
	//std::vector<size_t>  m_fileSize;//文件大小
	CString m_outputDirectoryPath;//输出文件夹路径
	void parse_bin_log(const CString& filePath, void* p_buffer, size_t size);
	void parse_pusch_catch_log(void* p_buffer);
	void bin2hex(CString& filename, void* p_buffer, size_t size);
	void ide2hex(CString& dstfilename, CString& srcfilename);

	//rtn 抓数解析
	void RTN_para_print(void* p_buffer);
	void RTN_payload_print(void* p_buffer);
	void RTN_data_print(void* p_buffer);
	void parse_rtn_catch_log(void* p_buffer);
};
