
// MFCApp7Dlg.cpp: 实现文件
//


#include "pch.h"
#include "framework.h"
#include "MFCApp7.h"
#include "MFCApp7Dlg.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "./inc/interface_fapi_pusch.h"
#include "./inc/reflection.h"
#include "./inc/pretty_json.h"
#include "./inc/log_common_def.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMFCApp7Dlg 对话框



CMFCApp7Dlg::CMFCApp7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MFCAPP7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApp7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cdx);
}

BEGIN_MESSAGE_MAP(CMFCApp7Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApp7Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApp7Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApp7Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApp7Dlg 消息处理程序
void CMFCApp7Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	if (nType == SIZE_MINIMIZED)
	{
		// 在此处添加最小化时的处理代码
		//AfxMessageBox(_T("窗口已最小化"));
	}
}

BOOL CMFCApp7Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_cdx.AddString(_T("bin_hex"));
	m_cdx.AddString(_T("230_pusch抓数解析"));
	m_cdx.AddString(_T("230_BinLog解析"));
	m_cdx.AddString(_T("ide_hex"));
	m_cdx.AddString(_T("RTN_抓数解析0.1滚降"));
	m_cdx.AddString(_T("RTN_抓数解析0.2滚降"));
	m_cdx.AddString(_T("RTN_binLog解析"));

	m_cdx.SetCurSel(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApp7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApp7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApp7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApp7Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApp7Dlg::OnBnClickedButton1()
{
	/*先清空*/
	m_strFilePathAndName.clear(); // 清空向量
	m_strFileName.clear(); // 清空向量
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here   
	// 设置过滤器   
	//TCHAR szFilter[] = _T("日志文件(*.log)|*.log|数据文件(*.dat)|*.dat|二进制文件(*.bin)|*.bin|所有文件(*.*)|*.*||");
	TCHAR szFilter[] = _T("所有文件(*.*)|*.*|日志文件(*.log)|*.log|数据文件(*.dat)|*.dat|二进制文件(*.bin)|*.bin||");
	// 构造打开文件对话框   
	//CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, OFN_ALLOWMULTISELECT | OFN_EXPLORER, szFilter, this);

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		POSITION pos = fileDlg.GetStartPosition();
		CString filePath;
		while (pos != NULL)
		{
			filePath = fileDlg.GetNextPathName(pos);
			m_strFilePathAndName.push_back(filePath);
			m_strFileName.push_back(filePath.Right(filePath.GetLength() - filePath.ReverseFind('\\') - 1));
			// 处理每个选择的文件路径
			//AfxMessageBox(filePath);
		}
		//m_strFilePathAndName = fileDlg.GetPathName();
		//m_strFilePath = m_strFilePathAndName.Left(m_strFilePathAndName.ReverseFind('\\'));
		//m_strFileName = m_strFilePathAndName.Right(m_strFilePathAndName.GetLength() - m_strFilePathAndName.ReverseFind('\\') - 1);
		if (!filePath.IsEmpty())
		{
			m_strFilePath = filePath.Left(filePath.ReverseFind('\\'));
			SetDlgItemText(IDC_EDIT1, m_strFilePath);
		}
		
	}
}

/*映射定义*/
REFLECTION(L1BeamInfo_t, digBFIterface, rev0, beamIdx);
REFLECTION(L1BwpInfo_t, BWPSize, BWPStart);
REFLECTION(L1PuschDmrsInfo_t, ulDmrsSymbPos, puschDmrsScramblingId, puschDmrsIdentity, dmrsPorts, dmrsConfigType, nSCID, numDmrsCdmGrpsNoData, rev0);
REFLECTION(L1PuschData_t, TBSize, numCb, rvIndex, harqProcessID, newData, rev0, rev1);

REFLECTION(L1PxschAllocationTdInfo_t, SymbolBitmap);
REFLECTION(L1PxschRbg_t, rbgStart, rbgSize);
REFLECTION(L1PxschAllocationFdInfo_t, rbgNum, rev, rbg);
REFLECTION(L1PuschPduInfo_t,
	Handle, pduBitmap, RNTI, targetCodeRate, nIdPusch, qamModOrder, mcsIndex, mcsTable, nrOfLayers,
	ldpcBaseGraph, rev0, rev1,
	BeamformingInfo, BWP, DMRS,
	ResourceAllocTd, puschData,
	ResourceAllocFd);//FD 放最后
REFLECTION(PuschPduInfo_t, PDUType, PDUSize, pdu);
REFLECTION(L1FapiToPuschInterFace_t,
	sfn, slot, d_length, pdu_num, pdu_len, pusch);

//bin_log
REFLECTION(log_msg_header_t, sync_flag, msg_level, msg_type, slot, sfn, slot_offset, msg_len, msgNo);
REFLECTION(Pusch_fapi_log_t, log_msg_header, pusch_pdu_info);

//pdsch tx
REFLECTION(L1TxPowerInfo_t, pdschDmrsPowerOffsetProfileSSS, pdschDataPowerOffsetProfileSSS);
REFLECTION(L1RateMatchingInformation_t, numCsiRsForRM, rev, csiRsForRM);
REFLECTION(L1PdschPduInfo_t, RNTI, pduIndex, BWPSize, BWPStart, TBSize, targetCodeRate, qamModOrder, mcsIndex,
	mcsTable, rvIndex, ldpcBaseGraph, rev, nIdPdsch, nrOfLayers, rev1, PMidx, rev2, dlDmrsType, dlDmrsSymbPos,
	dlDmrsSubbandPos,dlDmrsScramblingId, dmrsPorts, nSCID, numDmrsCdmGrpsNoData, rev3,
	ResourceAllocFd, RateMatchingInformation, TxPowerInfo);

//pdsch tb
REFLECTION(L1DataTLV_t, Tag, rev, Length, Value);
REFLECTION(L1TxDataPduInfo_t,PDULength, PDUIndex,CWIndex,rev,numTLV,TLVs);

//pdsch para
REFLECTION(pdschparacfg_t, crc_type, mcb_num, mzc, mcb_k, mcb_kinit, nulllen, mcb_seg_bit, mencode_n, nullpos, 
	mrm_er, mrm_k0, mrm_n_cb, mscram_c_init, mscram_m_bit, mtb_bitsize, mtb_crc_len, mrm_g, mhbg_matrix_ddraddr, 
	mhbg_matrix_lenth, polar_K, polar_E, polar_N, encode_type, data_symb_num, dmrs_symb_num, rev2, dmrs_symb_pos, 
	dmrs_port_index, data_re_allnum, data_re_num_datasym, data_re_start_dataSym, data_re_start_dmrsSym, 
	dmrs_re_start);

void CMFCApp7Dlg::parse_bin_log(const CString& filePath, void* p_buffer, size_t size)
{
	std::string str;
	std::string pretty_str;
	char* p_msg;
	uint32_t slot, time_data_len, freq_data_len, freq_scale_len, crc_ind_len;
	uint32_t offset = sizeof(Pusch_fapi_log_t);
	CString strFilePath = filePath.Left(filePath.ReverseFind('.')) + _T(".json");

	size_t head = 0;
	p_msg = (char*)p_buffer;
	while (p_msg < (char*)p_buffer + size)
	{
		//print head
		to_json(*(log_msg_header_t*)p_msg, str);
		pretty_json_string(str, pretty_str);
		appendToFile(strFilePath, pretty_str);//写文件
		str.clear();
		pretty_str.clear();

		switch (((log_msg_header_t*)p_msg)->msg_type)
		{
			case MSG_LOG_PUSCH_SYM_PDU_BODY:
			{
				p_msg += sizeof(log_msg_header_t);
				to_json(*(PuschPduInfo_t*)p_msg, str);
				pretty_json_string(str, pretty_str);
				appendToFile(strFilePath, pretty_str);//写文件
				str.clear();
				pretty_str.clear();
				p_msg += sizeof(PuschPduInfo_t);
				break;
			}
			case MSG_LOG_PDSCH_UE_PROC_PDU:
			{
				p_msg += sizeof(log_msg_header_t);
				to_json(*(L1PdschPduInfo_t*)p_msg, str);
				pretty_json_string(str, pretty_str);
				appendToFile(strFilePath, pretty_str);//写文件
				str.clear();
				pretty_str.clear();
				p_msg += sizeof(L1PdschPduInfo_t);
				break;
			}
			case (411)://MSG_LOG_PDSCH_UE_TB
			{
				p_msg += sizeof(log_msg_header_t);
				to_json(*(L1TxDataPduInfo_t*)p_msg, str);
				pretty_json_string(str, pretty_str);
				appendToFile(strFilePath, pretty_str);//写文件
				str.clear();
				pretty_str.clear();
				p_msg += sizeof(L1TxDataPduInfo_t);
				break;
			}
			case (404)://MSG_LOG_PDSCH_UE_PROC
			{
				p_msg += sizeof(log_msg_header_t);
				to_json(*(pdschparacfg_t*)p_msg, str);
				pretty_json_string(str, pretty_str);
				appendToFile(strFilePath, pretty_str);//写文件
				str.clear();
				pretty_str.clear();
				p_msg += sizeof(pdschparacfg_t);
				break;
			}
			default:
				AfxMessageBox(_T("未知的消息类型"));
				break;
		}

	}

	for (int i = 0; i < size / offset; i++)
	{
		p_msg = (char*)p_buffer + offset * i;
		//fapi_info
		to_json(*(Pusch_fapi_log_t*)p_msg, str);
		pretty_json_string(str, pretty_str);
		appendToFile(strFilePath,pretty_str);//写文件
		str.clear();
		pretty_str.clear();


	}

	//std::cout << pretty_str << endl;
	return;
}

void CMFCApp7Dlg::parse_pusch_catch_log(void* p_buffer)
{
	std::string str;
	std::string pretty_str;
	char* p_fapi, * p_time_data, * p_freq_data, * p_freq_scale, * p_crc_ind;
	uint32_t slot, time_data_len, freq_data_len, freq_scale_len, crc_ind_len;

	//fapi_info
	p_fapi = (char *)p_buffer + FAPI_INFO_OFFSET;
	to_json(*(L1FapiToPuschInterFace_t*)p_fapi, str);
	pretty_json_string(str, pretty_str);
	writeFile(m_outputDirectoryPath + _T("\\para.json"), pretty_str);//写文件
	//std::cout << pretty_str << endl;

	slot = ((L1FapiToPuschInterFace_t*)p_fapi)->slot;
	if (2 == slot)
	{
		time_data_len = SLOT2_TIME_61D44_LEN;
		freq_data_len = SLOT2_FREQ_DATA_LEN;
		freq_scale_len = SLOT2_FREQ_SCALE_LEN;
		crc_ind_len = CRC_IND_LEN;
	}
	else if (3 == slot)
	{
		time_data_len = SLOT3_TIME_61D44_LEN;
		freq_data_len = SLOT3_FREQ_DATA_LEN;
		freq_scale_len = SLOT3_FREQ_SCALE_LEN;
		crc_ind_len = CRC_IND_LEN;
	}
	else
	{
		AfxMessageBox(_T("invalid slot!\n"));
		return;
	}
	//time_data
	p_time_data = (char *)p_buffer + TIME_DATA_OFFSET;
	bin2hex(m_outputDirectoryPath + _T("\\Hex_time_data.dat"), p_time_data, time_data_len);
	//freq_data
	p_freq_data = (char*)p_buffer + FREQ_DATA_OFFSET;
	bin2hex(m_outputDirectoryPath + _T("\\Hex_freq_data.dat"), p_freq_data, freq_data_len);
	//scale
	p_freq_scale = (char*)p_buffer + FREQ_SCALE_OFFSET;
	bin2hex(m_outputDirectoryPath + _T("\\Hex_freq_scale.dat"), p_freq_scale, freq_scale_len);
	//crc_ind
	p_crc_ind = (char*)p_buffer + CRC_IND_OFFSET;
	bin2hex(m_outputDirectoryPath + _T("\\Hex_crc_ind.dat"), p_crc_ind, crc_ind_len);
	return;
}

void CMFCApp7Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	size_t fileSize;
	switch (m_cdx.GetCurSel())
	{
		case 0:
		{
			for (int i=0;i < m_strFilePathAndName.size();++i)
			{
				//读取文件
				void* buffer = ReadFileToBuffer(m_strFilePathAndName[i], fileSize);
				if (buffer != nullptr)
				{
					// 处理 buffer
					CString filename = m_strFilePath + _T("\\Hex_") + m_strFileName[i].Left(m_strFileName[i].ReverseFind('.')) + _T(".dat");
					bin2hex(filename, buffer, fileSize);
					free(buffer);
					
				}
			}
			break;
		}
		case 1://pusch抓数解析
		{
			for (int i = 0; i < m_strFilePathAndName.size(); ++i)
			{//读取文件
				void* buffer = ReadFileToBuffer(m_strFilePathAndName[i], fileSize);
				if (buffer != nullptr)
				{
					// 创建文件夹
					m_outputDirectoryPath = m_strFilePath + _T("\\") + m_strFileName[i].Left(m_strFileName[i].ReverseFind('.'));
					if (createDirectory(m_outputDirectoryPath))
					{
						// 处理 buffer
						parse_pusch_catch_log(buffer);
					}
					free(buffer);
				}
			}
			break;
		}
		case 2://BinLog解析
		{
			for (int i = 0; i < m_strFilePathAndName.size(); ++i)
			{
				//读取文件
				void* buffer = ReadFileToBuffer(m_strFilePathAndName[i], fileSize);
				if (buffer != nullptr)
				{
					// 处理 buffer
					parse_bin_log(m_strFilePathAndName[i], buffer, fileSize);
					free(buffer);
				}
			}
			break;
		}
		case 3://ide_hex
		{
			for (int i = 0; i < m_strFilePathAndName.size(); ++i)
			{
				//读取文件
				void* buffer = ReadFileToBuffer(m_strFilePathAndName[i], fileSize);
				if (buffer != nullptr)
				{
					// 处理 buffer
					CString filename = m_strFilePath + _T("\\Hex_") + m_strFileName[i];
					ide2hex(filename, m_strFilePathAndName[i]);
					free(buffer);
				}
			}
			break;
		}
		case 4: //RTN_抓数解析0.1滚降
		{
		}
		case 5: //RTN_抓数解析0.2滚降
		{
			for (int i = 0; i < m_strFilePathAndName.size(); ++i)
			{//读取文件
				void* buffer = ReadFileToBuffer(m_strFilePathAndName[i], fileSize);
				if (buffer != nullptr)
				{
					// 创建文件夹
					m_outputDirectoryPath = m_strFilePath + _T("\\") + m_strFileName[i].Left(m_strFileName[i].ReverseFind('.'));
					if (createDirectory(m_outputDirectoryPath))
					{
						// 处理 buffer
						parse_rtn_catch_log(buffer);
					}
					free(buffer);
				}
			}
			break;
		}
		default:
			break;
		}
		if (0 == m_strFilePathAndName.size())
		{
			AfxMessageBox(_T("请先选择文件"));
		}
		else
		{
			AfxMessageBox(_T("解析完成！"));
			m_strFilePathAndName.clear(); // 清空向量
			m_strFileName.clear(); // 清空向量

			m_strFilePathAndName = std::vector<CString>();//释放内存
			m_strFileName = std::vector<CString>();//释放内存
			//m_fileSize.clear(); // 清空向量
		}
}

BOOL CMFCApp7Dlg::createDirectory(const CString& directoryPath)
{
	if (CreateDirectory(directoryPath, NULL) || GetLastError() == ERROR_ALREADY_EXISTS)
	{
		return TRUE;
	}
	else
	{
		AfxMessageBox(_T("无法创建文件夹"));
		return FALSE;
	}
}

void* CMFCApp7Dlg::ReadFileToBuffer(const CString& filePath, size_t& fileSize)
{
	CFile file;
	if (!file.Open(filePath, CFile::modeRead | CFile::typeBinary))
	{
		AfxMessageBox(_T("无法打开文件"));
		return nullptr;
	}

	fileSize = static_cast<size_t>(file.GetLength());
	void* buffer = malloc(fileSize);
	if (buffer == nullptr)
	{
		AfxMessageBox(_T("内存分配失败"));
		file.Close();
		return nullptr;
	}

	file.Read(buffer, fileSize);
	file.Close();

	return buffer;
}

void CMFCApp7Dlg::writeFile(const CString& filePath, const std::string& content)
{
	CFile file;
	if (!file.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText | CFile::modeNoTruncate))
	{
		AfxMessageBox(_T("无法打开文件进行写入"));
		return;
	}

	file.Write(content.c_str(), static_cast<UINT>(content.size()));
	file.Close();
}

void CMFCApp7Dlg::writeBinFile(const CString& filePath, char* buf, size_t size)
{
	CFile file;
	if (!file.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary))
	{
		AfxMessageBox(_T("无法打开文件进行写入"));
		return;
	}

	file.Write(buf, static_cast<UINT>(size));
	file.Close();
}

void CMFCApp7Dlg::appendToFile(const CString& filePath, const std::string& content)
{
	CFile file;
	if (!file.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate | CFile::typeText))
	{
		AfxMessageBox(_T("无法打开文件进行写入"));
		return;
	}

	file.SeekToEnd();
	file.Write(content.c_str(), static_cast<UINT>(content.size()));
	file.Close();
}


//#include <iomanip> // Add this include directive at the top of the file

std::string intToHexString(int value)
{
    std::stringstream ss;
    ss << "0x" << std::setw(8) << std::setfill('0') << std::hex << value;
    return ss.str();
}
// 示例调用 intToHexString 函数
void CMFCApp7Dlg::bin2hex(CString& filename, void* p_buffer, size_t size)
{
	size_t j;
	CFile file;
	if (!file.Open(filename, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate | CFile::typeText))
	{
		AfxMessageBox(_T("无法打开文件进行写入"));
		return;
	}

	int* ptr = (int*)p_buffer;
	for (j = 0; j < size; j += 4)
	{
		std::string hexStr = intToHexString(*(ptr++));
		hexStr += ",\n";
		file.Write(hexStr.c_str(), static_cast<UINT>(hexStr.size()));
	}
	file.Close();
	return;
}

//#include <fstream> // Add this include directive at the top of the file

void CMFCApp7Dlg::ide2hex(CString& dstfilename, CString& srcfilename)
{
    std::ifstream rfile(CT2A(srcfilename.GetString())); // Ensure the correct conversion
    if (!rfile.is_open())
    {
        AfxMessageBox(_T("无法打开源文件进行读取"));
        return;
    }

    std::ofstream wfile(CT2A(dstfilename.GetString()));
    if (!wfile.is_open())
    {
        AfxMessageBox(_T("无法打开目标文件进行写入"));
        return;
    }
    std::string line;
    while(std::getline(rfile,line))
    {
        // 处理每一行数据
        wfile << "0x" << line.substr(line.size()-8) << ',' << std::endl;
    }

    rfile.close();
    wfile.close();
}

#define CATCH_BASE_OFFSET               0x100
#define CATCH_PARA_LENGTH               0x400
#define CATCH_PAYLOAD_LENGTH            0xD000
#define CATCH_DATA_LENGTH               800000

#define DDR_TX_CATCH_FLAG_ADDR          (0x6d000000)
#define DDR_TX_CATCH_BASE_ADDR          (0x6d000100)
#define DDR_TX_CATCH_PARA_ADDR          (DDR_TX_CATCH_BASE_ADDR)
#define DDR_TX_CATCH_PAYLOAD_ADDR       (DDR_TX_CATCH_PARA_ADDR + 0x400)
#define DDR_TX_CATCH_DATA_ADDR          (DDR_TX_CATCH_PAYLOAD_ADDR + 0xD000)
#define DDR_TX_CATCH_DATA_END_ADDR      (DDR_TX_CATCH_DATA_ADDR + 800000)

typedef struct
{
	uint8_t slot_type;
	uint8_t slot_index;
	uint8_t first_flag;
	uint8_t last_flag;

	uint16_t wave_id;
	uint16_t data_length;

	uint32_t data_offset;
} tx_pdu_info_t;

typedef struct
{
	uint16_t ms_cnt;
	//uint16_t rsv;
	uint8_t roll_off;//0:0.25,1:0.2,2:0.15,3:0.1
	uint8_t freqIndex;//18表示不搬频

	uint8_t sche_flag;
	uint8_t data_flag;
	uint8_t pdu_num;
	uint8_t slot_num;

	uint32_t data_base_addr;
	uint32_t slot_symb_offset[24];

	tx_pdu_info_t pdu[88];
} interface_rtn_rx_config_t;
typedef struct
{
	uint16_t ms_cnt;
	uint16_t rsv;

	uint8_t sche_flag;
	uint8_t data_flag;
	uint8_t pdu_num;
	uint8_t slot_num;

	uint32_t data_base_addr;
	uint32_t slot_symb_offset[18];

	tx_pdu_info_t pdu[88];
} interface_rtn_rx_config_rolloff02_t;

REFLECTION(tx_pdu_info_t, slot_type, slot_index, first_flag, last_flag, wave_id, data_length, data_offset);
REFLECTION(interface_rtn_rx_config_t, ms_cnt, roll_off, freqIndex, sche_flag, data_flag, pdu_num, slot_num, data_base_addr, slot_symb_offset, pdu);
REFLECTION(interface_rtn_rx_config_rolloff02_t, ms_cnt, rsv, sche_flag, data_flag, pdu_num, slot_num, data_base_addr, slot_symb_offset, pdu);
void CMFCApp7Dlg::RTN_para_print(void* p_buffer)
{
	std::string str;
	interface_rtn_rx_config_t* p_rtn_para = (interface_rtn_rx_config_t*)p_buffer;
	interface_rtn_rx_config_rolloff02_t* p_rtn_para_rolloff02 = (interface_rtn_rx_config_rolloff02_t*)p_buffer;
	if (4 == m_cdx.GetCurSel())
	{
		to_json(*p_rtn_para, str);
	}
	else if (5 == m_cdx.GetCurSel())
	{
		to_json(*p_rtn_para_rolloff02, str);
	}
	else
	{
		AfxMessageBox(_T("参数错误"));
	}
	
	std::string pretty_str;
	pretty_json_string(str, pretty_str);
	writeFile(m_outputDirectoryPath + _T("\\para_parse.json"), pretty_str);//写文件

	return;
}

void CMFCApp7Dlg::RTN_payload_print(void* p_buffer)
{
	int i, j, k;
	if (4 == m_cdx.GetCurSel())
	{
		interface_rtn_rx_config_t* p_rtn_para = (interface_rtn_rx_config_t*)((char*)p_buffer - (DDR_TX_CATCH_PAYLOAD_ADDR - DDR_TX_CATCH_PARA_ADDR));
		char* p_payload = (char*)p_buffer;
		uint32 last_valid_pdu_index = 0;
		size_t size;

		if(0 != p_rtn_para->pdu_num)
		{
			for (i = 0; i < p_rtn_para->pdu_num; ++i)
			{
				if (0 != p_rtn_para->pdu[i].data_length)
				{
					last_valid_pdu_index = i;
				}
			}
			size = p_rtn_para->pdu[last_valid_pdu_index].data_offset + p_rtn_para->pdu[last_valid_pdu_index].data_length;
			writeBinFile(m_outputDirectoryPath + _T("\\") + _T("pdu_payload.bin"),(char *)p_buffer,size);//写文件

			std::string path = CT2A(m_outputDirectoryPath);
			std::string write_file_name_hex = path + "\\pdu_payload_hex.dat";
			std::ofstream os;
			os.open(write_file_name_hex, std::ios::out);
			if (!os)
			{
				std::cout << write_file_name_hex << "file open err!\n";
			}
			int* ptr = (int*)((char*)(p_buffer)+16);
			for (j = 0; j < size; j += 4)
			{
				os << "0x";
				os << std::setw(8) << std::setfill('0') << std::hex << *(ptr++) << ',' << std::endl;
			}
			os.close();
		}
		

		for (i = 0; i < p_rtn_para->pdu_num; ++i)
		{
			if ((p_rtn_para->pdu[i].wave_id == 0) || (0 == p_rtn_para->pdu[i].data_length))
			{
				continue;
			}
			std::string str;
			for (j = p_rtn_para->pdu[i].data_offset; j < p_rtn_para->pdu[i].data_offset + p_rtn_para->pdu[i].data_length; ++j)
			{
				for (k = 0; k < 8; ++k)
				{
					str += std::to_string((p_payload[j + 16] >> k) & 1);
					str.append("\n");
				}
			}

			writeFile(m_outputDirectoryPath + _T("\\") + _T("pdu_") + CString(std::to_wstring(i).c_str()) + _T("_payload.dat"), str);//写文件

			std::string path = CT2A(m_outputDirectoryPath);
			std::string write_file_name_hex = path + "\\pdu_" + std::to_string(i) + "_payload_hex.dat";
			std::ofstream os;
			os.open(write_file_name_hex, std::ios::out);
			if (!os)
			{
				std::cout << write_file_name_hex << "file open err!\n";
			}
			int* ptr = (int*)&p_payload[16 + p_rtn_para->pdu[i].data_offset];
			for (j = p_rtn_para->pdu[i].data_offset; j < p_rtn_para->pdu[i].data_offset + p_rtn_para->pdu[i].data_length; j += 4)
			{
				os << "0x";
				os << std::setw(8) << std::setfill('0') << std::hex << *(ptr++) << ',' << std::endl;
			}
			os.close();
		}
	}
	else if (5 == m_cdx.GetCurSel())
	{
		interface_rtn_rx_config_rolloff02_t* p_rtn_para = (interface_rtn_rx_config_rolloff02_t*)((char*)p_buffer - (DDR_TX_CATCH_PAYLOAD_ADDR - DDR_TX_CATCH_PARA_ADDR));
		char* p_payload = (char*)p_buffer;
		uint32 last_valid_pdu_index = 0;
		size_t size;

		if (0 != p_rtn_para->pdu_num)
		{
			for (i = 0; i < p_rtn_para->pdu_num; ++i)
			{
				if (0 != p_rtn_para->pdu[i].data_length)
				{
					last_valid_pdu_index = i;
				}
			}
			size = p_rtn_para->pdu[last_valid_pdu_index].data_offset + p_rtn_para->pdu[last_valid_pdu_index].data_length;
			writeBinFile(m_outputDirectoryPath + _T("\\") + _T("pdu_payload.bin"), (char*)(p_buffer)+16, size);//写文件

			std::string path = CT2A(m_outputDirectoryPath);
			std::string write_file_name_hex = path + "\\pdu_payload_hex.dat";
			std::ofstream os;
			os.open(write_file_name_hex, std::ios::out);
			if (!os)
			{
				std::cout << write_file_name_hex << "file open err!\n";
			}
			int* ptr = (int*)((char*)(p_buffer)+16);
			for (j = 0; j<size; j += 4)
			{
				os << "0x";
				os << std::setw(8) << std::setfill('0') << std::hex << *(ptr++) << ',' << std::endl;
			}
			os.close();
		}

		for (i = 0; i < p_rtn_para->pdu_num; ++i)
		{
			if ((p_rtn_para->pdu[i].wave_id == 0) || (0 == p_rtn_para->pdu[i].data_length))
			{
				continue;
			}
			std::string str;
			for (j = p_rtn_para->pdu[i].data_offset; j < p_rtn_para->pdu[i].data_offset + p_rtn_para->pdu[i].data_length; ++j)
			{
				for (k = 0; k < 8; ++k)
				{
					str += std::to_string((p_payload[j + 16] >> k) & 1);
					str.append("\n");
				}
			}

			writeFile(m_outputDirectoryPath + _T("\\") + _T("pdu_") + CString(std::to_wstring(i).c_str()) + _T("_payload.dat"), str);//写文件

			std::string path = CT2A(m_outputDirectoryPath);
			std::string write_file_name_hex = path + "\\pdu_" + std::to_string(i) + "_payload_hex.dat";
			std::ofstream os;
			os.open(write_file_name_hex, std::ios::out);
			if (!os)
			{
				std::cout << write_file_name_hex << "file open err!\n";
			}
			int* ptr = (int*)&p_payload[16 + p_rtn_para->pdu[i].data_offset];
			for (j = p_rtn_para->pdu[i].data_offset; j < p_rtn_para->pdu[i].data_offset + p_rtn_para->pdu[i].data_length; j += 4)
			{
				os << "0x";
				os << std::setw(8) << std::setfill('0') << std::hex << *(ptr++) << ',' << std::endl;
			}
			os.close();
		}
	}
	

	return;
}

void CMFCApp7Dlg::RTN_data_print(void* p_buffer)
{
	int i;
	std::string str;
	int* ptr = (int*)((char*)p_buffer);

	std::string path = CT2A(m_outputDirectoryPath);
	std::string write_file_name = path + "\\data.log";
	std::ofstream os;
	os.open(write_file_name, std::ios::out);
	if (!os)
	{
		std::cout << write_file_name << " file open err!\n";
		return;
	}
	os << str;

	for (i = 0; i < 800000 / 4; ++i)
	{
		os << "0x";
		os << std::setw(8) << std::setfill('0') << std::hex << *(ptr++) << ',' << std::endl;
	}
	os.close();

	return;
}

void CMFCApp7Dlg::parse_rtn_catch_log(void* p_buffer)
{
	char* p_buffer1 = (char *)p_buffer;
	p_buffer1 += (DDR_TX_CATCH_BASE_ADDR - DDR_TX_CATCH_FLAG_ADDR);//0x100
	RTN_para_print(p_buffer1);
	p_buffer1 += (DDR_TX_CATCH_PAYLOAD_ADDR - DDR_TX_CATCH_BASE_ADDR);//0x400
	RTN_payload_print(p_buffer1);
	p_buffer1 += (DDR_TX_CATCH_DATA_ADDR - DDR_TX_CATCH_PAYLOAD_ADDR);//0xd000
	RTN_data_print(p_buffer1);
}
