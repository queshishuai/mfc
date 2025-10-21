#ifndef     LOG_COMMON_DEF_H
#define     LOG_COMMON_DEF_H
#include    <stdint.h>
#include    "type_define.h"


//此处定义消息号  各模块消息号定义在对应注释之后，并保证在注释要求的范围内1
//STRING_LOG   0
#if 0
typedef signed char		int8_t;
typedef unsigned char	uint8_t;
typedef signed short	int16_t;
typedef unsigned short	uint16_t;
typedef signed int		int32_t;
typedef unsigned int	uint32_t;
typedef unsigned long long uint64_t;
typedef signed long long   int64_t;

typedef unsigned char  bool;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
	uint16_t digBFIterface;//Logical Ant Ports
	uint16_t rev0;
	uint16_t beamIdx[4];//MAX_DL_ANT_PORTS=4
}L1BeamInfo_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint16_t BWPSize;
    uint16_t BWPStart;
    uint8_t SubcarrierSpacing;
    uint8_t CyclicPrefix;
    uint16_t rev;
}L1BwpInfo_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint16_t ulDmrsSymbPos;
    uint16_t puschDmrsScramblingId;
    uint16_t puschDmrsIdentity;
    uint16_t dmrsPorts;
    uint8_t maxLen;
    uint8_t dmrsConfigType;
    uint8_t nSCID;
    uint8_t numDmrsCdmGrpsNoData;
    uint8_t groupOrSequenceHopping;
    uint8_t rev0;
    uint16_t rev1;
}L1PuschDmrsInfo_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint16_t rbStart;
    uint16_t rbSize;
    uint16_t deltaBwp0StartFromActiveBwp;
    uint16_t initialUlBwpSize;
    uint16_t puschSecondHopPRB;
    uint16_t txDirectCurrentLocation;
    uint8_t resourceAlloc;
    uint8_t VRBtoPRBMapping;
    uint8_t puschTransType;
    uint8_t IntraSlotFrequencyHopping;
    uint8_t uplinkFrequencyShift7p5khz;
    uint8_t rev0;
    uint16_t rev1;
    uint8_t rbBitmap[36];
}L1PuschAllocationFdInfo_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint8_t StartSymbolIndex;
    uint8_t NrOfSymbols;
    uint16_t rev;
}L1PxschAllocationTdInfo_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint32_t TBSize;
    uint16_t numCb;
    uint8_t rvIndex;
    uint8_t harqProcessID;
    uint8_t newData;
    uint8_t cbCrcRequest;
    uint16_t rev;
    uint8_t cbPresentAndPosition[16];
}L1PuschData_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint16_t priority;
    uint16_t part2SizeMapIndex;
    uint8_t numPart1Params;
    uint8_t rev0;
    uint16_t rev1;
    uint16_t paramOffsets[4];
    uint8_t paramSizes[4];
}L1Part2s_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint16_t harqAckBitLength;
    uint16_t csiPart1BitLength;
    uint16_t flagCsiPart2;
    uint8_t AlphaScaling;
    uint8_t betaOffsetHarqAck;
    uint8_t betaOffsetCsi1;
    uint8_t betaOffsetCsi2;
    uint16_t numPart2s;
    L1Part2s_t Part2s;
}L1PuschUci_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint16_t PTRSPortIndex;
    uint8_t PTRSDmrsPort;
    uint8_t PTRSReOffset;
}L1PtrsPortInfo_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint8_t PTRSTimeDensity;
    uint8_t PTRSFreqDensity;
    uint8_t ulPTRSPower;
    uint8_t numPtrsPorts;
    L1PtrsPortInfo_t PtrsPorts[2];/* Max size: MAX_NUM_PUSCH_PTRS_PORT*/
}L1PuschPtrs_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint16_t lowPaprSequenceNumber;
    uint8_t lowPaprGroupNumber;
    uint8_t ulPtrsSampleDensity;
    uint8_t ulPtrsTimeDensityTransformPrecoding;
    uint8_t rev0;
    uint16_t rev1;
}L1DftsOfdm_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint32_t Handle;
    uint16_t pduBitmap;
    uint16_t RNTI;
    uint32_t tbSizeLbrmBytes;
    uint16_t targetCodeRate;
    uint16_t nIdPusch;
    uint8_t qamModOrder;
    uint8_t mcsIndex;
    uint8_t mcsTable;
    uint8_t TransformPrecoding;
    uint8_t nrOfLayers;
    uint8_t ldpcBaseGraph;
    uint16_t rev;
    L1BeamInfo_t BeamformingInfo;
    L1BwpInfo_t BWP;
    L1PuschDmrsInfo_t DMRS;
    L1PuschAllocationFdInfo_t ResourceAllocFd;
    L1PxschAllocationTdInfo_t ResourceAllocTd;
    L1PuschData_t puschData;
    L1PuschUci_t puschUci;
    L1PuschPtrs_t puschPtrs;
    L1DftsOfdm_t dftsOfdm;
}L1PuschPduInfo_t;

//MSG_LOG_PUSCH_SYM_PDU
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1PuschPduInfo_t pdu;
}PuschPduInfo_t;

#endif

//CONFIG_LOG     1~99
#define MSG_LOG_CONFIG_CELL_INFO    (1)

//FAPI_LOG     100~199
#define MSG_LOG_FAPI_SCHE_INFO      (100)

//SSB_LOG     200~299
#define MSG_LOG_SSB_CELL_INFO       (200)
#define MSG_LOG_SSB_SCH_INFO        (201)
#define MSG_LOG_SSB_CONF_INFO       (202)
#define MSG_LOG_SSB_REMAP_INFO      (203)
#define MSG_LOG_SSB_PROC_PARAM      (204)

//PDCCH_LOG     300~399
#define MSG_LOG_DCI_INFO            (300)
#define MSG_LOG_PDCCH_MAP_INFO      (301)

//PDSCH_LOG     400~499
#define MSG_LOG_PDSCH_DLCELL_CFG    (400)//debug
#define MSG_LOG_PDSCH_UE_PDU        (401)
#define MSG_LOG_PDSCH_BIT_UE_PROC   (402)
#define MSG_LOG_PDSCH_SYMB_UE_PROC  (403)
#define MSG_LOG_PDSCH_UE_PROC       (404)//infor:Cal Para
#define MSG_LOG_PDSCH_UE_PROC_PDU   (405)//infor:PDU CFG&Cal Para
#define MSG_LOG_DL_MAP_CFG          (406)
#define MSG_LOG_DL_TASK_PROC        (407)//infor:DLTask
#define MSG_LOG_DL1_TASK_PROC       (408)//infor:DL1Task
#define MSG_LOG_TXDATA_PDU          (409)//debug
#define MSG_LOG_PDSCH_UE_PROC_PDU_SIMP  (410)//infor:PDU CFG&Cal Para-简化
#define MSG_LOG_PDSCH_UE_TB         (411)//debug:TBDATA


//CSIRS_LOG     500~599
#define MSG_LOG_CSI_PROC_PARAM      (500)
#define MSG_LOG_CSI_PDU             (501)//debug

//PUSCH_LOG     700~799
#define MSG_LOG_PUSCH_SYM_INFO            (700)
#define MSG_LOG_PUSCH_SYM_PDU_HEAD        (701)
#define MSG_LOG_PUSCH_SYM_PDU_BODY        (702)
#define MSG_LOG_PUSCH_SYM_LOG_INFO        (703)

#define MSG_LOG_PUSCH_CB_INFO             (750)
#define MSG_LOG_PUSCH_UCICB_INFO          (751)

//PUCCH_LOG     800~899
#define MSG_LOG_PUCCH_F01_UCI_INFO        (800)
#define MSG_LOG_PUCCH_F234_UCI_INFO       (801)
#define MSG_LOG_PUCCH_SS_CONFIG           (802)
#define MSG_LOG_PUCCH_ULTTI_REQ           (803)
#define MSG_LOG_PUCCH_01_UCI_INDICATION   (804)
#define MSG_LOG_PUCCH_234_UCI_INDICATION  (805)
#define MSG_LOG_PUCCH_TIME_REC            (806)

//PRACH_LOG     900~999
#define MSG_LOG_Prach_CONFIGPARAM          ( 900 )
#define MSG_LOG_PRACH_TIME_OCCASION_RESULT ( 902 )
#define MSG_LOG_PRACH_REQUEST              ( 903 )
#define MSG_LOG_PRACH_REPORT_MSG           ( 904 )
#define MSG_LOG_PRACH_TIME_AGC_FACTOR      ( 905 )



//SRS_LOG       1000~1099
#define MSG_LOG_SRS_INFO         (1000)
#define MSG_LOG_SRS_FAPI_INFO    (1001)
#define MSG_LOG_SRS_PARAM_INFO   (1002)
#define MSG_LOG_SRS_IND_INFO     (1003)

#define MSG_LOG_SRS_POST_IND_INFO     (1004)


//DEOFDM        1100-1199
#define MSG_LOG_DEOFDM_INFO      (1100)

#if 0
//struct define
//MAIN STRUCT DEFINE
//必须和nr_cell_info_t结构体保持一致
/*MSG_LOG_CONFIG_CELL_INFO*/
typedef struct
{
    uint32_t   state;

    int32_t handle_id;

    uint8_t queue_index;
    uint8_t cell_id;//物理层分配的id,cell_id=queue_index=inst_id=0/1
    uint16_t phyCellId;//协议栈配置的ID

    uint8_t cell_index;//协议栈配置的索引
    uint8_t FrameDuplexType;//0:FDD, 1:TDD
    uint8_t slot_format;//0:7D2U, 1:1D3U, 2:双周期, 3:FDD
    uint8_t ssym_format;//特殊时隙sym配比 0->6:4:4, 1->10:2:2

    uint8_t numTxAnt;
    uint8_t numRxAnt;
    uint8_t nrOfDlSymbol;
    uint8_t nrOfUlSymbol;

    uint8_t TddPeriod;
    uint8_t scs;
    /*Measurement Config*/
    uint8_t RssiMeasurement;
    uint8_t RsrpMeasurement;

    uint16_t dlBandwidth;
    uint16_t ulBandwidth;

    uint32_t dlFrequency;
    uint32_t ulFrequency;

    uint8_t nrOfSlot;//TDD周期内slot个数
    uint8_t nrOfSSlot;
    uint8_t rev1[2];

    uint8_t nrOfDlSlot[2];
    uint8_t nrOfUlSlot[2];

    uint16_t dlk0[5];
    uint16_t ulk0[5];

    uint16_t dlGridSize[5];
    uint16_t ulGridSize[5];

    uint32_t t_advance;//us
    uint32_t r_delay;//us

    uint32_t phaseFactor_dl[14];
    uint32_t phaseFactor_ul[14];
}log_cell_info_t;


//FAPI STRUCT DEFINE
/*MSG_LOG_FAPI_SCHE_INFO*/
typedef struct log_fapi_slot_sch_info
{
    uint16_t sfn;       //当前sfn slot
    uint16_t slot;

    //DL TTI & UL DCI & TX Data Req位置都会填写该tx sfn slot
    uint16_t tx_sfn;   //tx sfn slot
    uint16_t tx_slot;

    uint16_t rx_sfn;   //rx sfn slot
    uint16_t rx_slot;

    uint32_t start;//start offset
    uint32_t end;//end offset

    uint32_t slot_cnt;

    uint8_t cell_index;
    uint8_t dl_tti_num;//dl tti msg
    uint8_t ul_tti_num;//ul tti msg
    uint8_t ul_dci_num;//ul dci msg

    uint8_t tx_dat_num;//tx dat msg
    uint8_t pdsch_data_num;//que data count
    uint8_t ssb_num;
    uint8_t csi_rs_num;

    uint8_t pdcch_num;
    uint8_t pdsch_num;
    uint8_t dci_num;
    uint8_t srs_num;

    uint8_t prach_num;
    uint8_t pucch_num;
    uint8_t pusch_num;
    uint8_t deofdm_num;

    uint32_t dl_err_num;
    uint32_t ul_err_num;
}log_fapi_slot_sch_info_t;


//SSB STRUCT DEFINE

/*MSG_LOG_SSB_CELL_INFO*/
typedef struct log_ssb_cell_info
{
	uint32_t dlFrequency;  //unit: Khz
	uint32_t num_TXant;    //Number of transmission antennas

	uint32_t phyCellId; // physical  cell id

	uint32_t bchPayloadFlag;
    uint32_t ssPbchBlockPowerScaling;

    uint32_t Case;
    uint32_t lMax;
    uint32_t SsbMask[2]; //Bitmap for actually transmitted SSB.
    uint32_t ssbOffsetPointA;
    uint32_t ssbPeriod; //0: ms5, 1: ms10, 2: ms20, 3: ms40, 4: ms80, 5: ms160
    uint32_t ssbSubcarrierOffset;
    uint32_t subcarrierSpacing; //0: Case A 15kHz, 1: Case B 30kHz 2: Case C 30kHz, 3: Case D 120kHz 4: Case E 240kHz
    uint32_t subCarrierSpacingCommon;
}log_ssb_cell_info_t;

typedef struct log_ssb_sche_info
{
	uint32_t air_SFN;  //空口sfn
	uint16_t air_slot; //空口slot
    uint16_t pdu_num;
    uint32_t ssbBlockIndex0;
    uint32_t bchPayloadFlag0;
    uint32_t BchPayload0;
    uint32_t ssbBlockIndex1;
    uint32_t bchPayloadFlag1;
    uint32_t BchPayload1;
}log_ssb_sche_info_t;

//L1BeamInfo_t
typedef struct
{
    uint16_t digBFIterface;//Logical Ant Ports
    uint16_t rev0;
    uint16_t beamIdx[4];//MAX_DL_ANT_PORTS=4
}log_L1BeamInfo_t;//3word
typedef struct
{
    uint8_t ssbConfigIndex;
    uint8_t ssbBlockIndex;
    uint8_t bchPayloadFlag;
    uint8_t boostoffset;
    uint32_t BchPayload;
    log_L1BeamInfo_t BeamformingInfo;
}log_L1SsbPduInfo_t;
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    log_L1SsbPduInfo_t  pdu;
}log_ssb_pdu_info_t;
/*MSG_LOG_SSB_SCH_INFO*/
typedef struct
{
    uint16_t sfn;
    uint16_t slot;
    uint16_t pdu_num;
    uint16_t rev;
    log_ssb_pdu_info_t  ssb[2];
}log_interface_ssb_req_t;


//PDCCH STRUCT DEFINE

typedef struct
{
	uint16_t digBFIterface;//Logical Ant Ports
	uint16_t rev0;
	uint16_t beamIdx[4];//MAX_DL_ANT_PORTS=4
}log_BeamInfo_t;

typedef struct
{
    int16_t pdcchDmrsPowerOffsetProfileSSS;
    int16_t pdcchDataPowerOffsetProfileSSS;
}log_PdcchTxPowerInfo_t;

typedef struct log_dci_info
{
	uint16_t RNTI;
	uint16_t nIdPdcchData;
	uint16_t nRntiPdcchData;
	uint16_t nIdPdcchDmrs;
	uint8_t CceIndex;
	uint8_t AggregationLevel;
	uint16_t PayloadSizeBits;
	log_BeamInfo_t BeamformingInfo;
	log_PdcchTxPowerInfo_t TxPowerInfo;
	uint8_t Payload[20];
}log_dci_info_t;

typedef struct
{
    uint16_t CoresetBWPSize;
    uint16_t CoresetBWPStart;
    uint8_t SubcarrierSpacing;
    uint8_t CyclicPrefix;
    uint16_t rev;
}log_PdcchBwpInfo_t;

typedef struct
{
    uint16_t ShiftIndex;
    uint8_t StartSymbolIndex;
    uint8_t DurationSymbols;
    uint8_t FreqDomainResource[6];
    uint8_t CceRegMappingType;
    uint8_t RegBundleSize;
    uint8_t InterleaverSize;
    uint8_t CoreSetType;
    uint8_t precoderGranularity;
    uint8_t rev;
}log_CoresetInfo_t;


/*MSG_LOG_PDCCH_MAP_INFO*/
typedef struct
{
    uint16_t pdcchPduIndex;
    uint16_t numDlDci;
    log_PdcchBwpInfo_t BWP;
    log_CoresetInfo_t Coreset;
}log_pdcch_map_info_t;

/*MSG_LOG_DCI_INFO*/
typedef struct
{
	/**variable-size by numDlDci*/
    log_dci_info_t DlDCIs[7];/* 14个DCI */
}log_pdcch_dci_info_t;


//PDSCH STRUCT DEFINE
#define SYMB_PROC_UNIT_NUM_CORE0            (8)
#define SYMB_PROC_UNIT_NUM                  (4)
#define LOG_MAX_NUM_PDSCH_NR_Of_CODEWORD    (2)
#define LOG_NUM_PXSCH_RB_BITMAP             (36)
#define LOG_MAX_NUM_CORESET_FOR_RM          (4)
#define LOG_MAX_NUM_CSI_RS_FOR_RM           (22)
#define LOG_MAX_NUM_TXDATA_TLV              (4)
#define LOG_MAX_NUM_PDSCH_PDU_PER_SLOT      (14)
#define LOG_NUM_FREQ_DOMAIN_RES             (6)
//ssbslotcfg_t
typedef struct
{
    uint32_t    ssb_num;
    uint8_t     ssb_valid[2];
    uint8_t     symb_start[2];
} log_ssbslotcfg_t;//2 word
//ssbrmcfg_t
typedef struct
{
    uint16_t            re_start;
    uint16_t            rsv0;
    uint8_t             slot_valid[4];
    log_ssbslotcfg_t    ssbslotcfg[4];
    uint32_t    	    rsv1[2];
} log_ssbrmcfg_t;//10 word
//L1CoresetRmPattern_t
typedef struct
{
    uint16_t symbolsPattern;
    uint8_t freqDomainResources[LOG_NUM_FREQ_DOMAIN_RES];
    uint8_t coresetRmPatternID;
    uint8_t CoreSetType;
    uint16_t CoresetBWPStart;
}log_L1CoresetRmPattern_t;
//coresetrmcfg_t
typedef struct
{
    uint8_t numCoresetRmPatterns;
    uint8_t rev0[3];
    log_L1CoresetRmPattern_t coresetrmpattern[LOG_MAX_NUM_CORESET_FOR_RM];//3*4word
}log_coresetrmcfg_t;//13word

/*MSG_LOG_PDSCH_DLCELL_CFG*/
 typedef struct dlcellcfg_s
 {
    uint16_t        cell_mode;//0-7D2U,1-1D3U
    uint16_t        ru_ant_num;//2T/4T
    uint32_t        dlphasefactor[14];//下行相位补偿因子，分别对应14符号
    log_ssbrmcfg_t  ssbrmcfg;//当PDSCH对SSB速率匹配时，SSB的资源位置--Lmax=8
    log_coresetrmcfg_t coresetrmcfg;//当PDSCH做coreset速率匹配时，coreset的资源位置 3word*4
 } log_cfgfapidlcell_t;

 //TLV structure
 typedef struct
 {
     uint16_t Tag;
     uint16_t rev;
     uint32_t Length;
     uint32_t Value;
 }log_L1DataTLV_t;//3word
 //TX DATA PDU
 typedef struct
 {
     uint32_t PDULength;
     uint16_t PDUIndex;
     uint8_t CWIndex;
     uint8_t rev;
     uint32_t numTLV;
     log_L1DataTLV_t TLVs[LOG_MAX_NUM_TXDATA_TLV];
 }log_L1TxDataPduInfo_t;//15word
 /*MSG_LOG_TXDATA_PDU*/
 typedef struct
 {
     uint16_t    sfn;//空口无线帧号
     uint16_t    slot;//空口无线帧号
     uint16_t    ue_num;//PDSCH调度UE数目
     uint16_t    rev;
     char*       data_ptr;//该小区的数据首地址
     log_L1TxDataPduInfo_t   txdatcfg[7];//PDSCH Tx Data cfg--抄送前7个
 } log_cfgfapitxdat_t;

 //L1BwpInfo_t
 typedef struct
 {
     uint16_t BWPSize;
     uint16_t BWPStart;
     uint8_t SubcarrierSpacing;
     uint8_t CyclicPrefix;
     uint16_t rev;
 }log_L1BwpInfo_t;
 //L1Codeword_t
 typedef struct
 {
     uint32_t TBSize;
     uint32_t tbSizeLbrmBytes;
     uint16_t targetCodeRate;
     uint8_t qamModOrder;
     uint8_t mcsIndex;
     uint8_t mcsTable;
     uint8_t rvIndex;
     uint8_t ldpcBaseGraph;
     uint8_t rev;
 }log_L1Codeword_t;
 //L1CodewordInfo_t
 typedef struct
 {
     uint8_t NrOfCodewords;
     uint8_t rev0;
     uint16_t rev1;
     log_L1Codeword_t CodewordInfo[LOG_MAX_NUM_PDSCH_NR_Of_CODEWORD];
 }log_L1CodewordInfo_t;
 //L1TxPreCodingInfo_t
 typedef struct
 {
     uint16_t numPRGs;//max 273/2=137
     uint16_t prgSize;
     uint16_t digBFIterface;
     uint16_t rev0;
     uint16_t PMidx[2];
 }log_L1TxPreCodingInfo_t;
 //L1PdschDmrsInfo_t
 typedef struct
 {
     uint16_t dlDmrsSymbPos;
     uint16_t dlDmrsScramblingId;
     uint16_t dmrsPorts;
     uint8_t maxLen;
     uint8_t dmrsConfigType;
     uint8_t nSCID;
     uint8_t numDmrsCdmGrpsNoData;
     uint16_t rev;
 }log_L1PdschDmrsInfo_t;
 //L1PdschAllocationFdInfo_t
 typedef struct
 {
     uint16_t rbStart;
     uint16_t rbSize;
     uint16_t coresetStartPoint;
     uint16_t initialDlBwpSize;
     uint8_t resourceAlloc;
     uint8_t VRBtoPRBMapping;
     uint8_t pdschTransType;
     uint8_t rev;
     uint8_t rbBitmap[LOG_NUM_PXSCH_RB_BITMAP];
 }log_L1PdschAllocationFdInfo_t;
 //L1RateMatchingInformation_t
 typedef struct
 {
     uint16_t ssbConfigForRateMatching;
     uint8_t numCoresetRMP;
     uint8_t numCsiRsForRM;
     uint8_t coresetRMPIndex[LOG_MAX_NUM_CORESET_FOR_RM];
     uint16_t csiRsForRM[LOG_MAX_NUM_CSI_RS_FOR_RM];
 }log_L1RateMatchingInformation_t;
 //L1PxschAllocationTdInfo_t
 typedef struct
 {
     uint8_t StartSymbolIndex;
     uint8_t NrOfSymbols;
     uint16_t rev;
 }log_L1PxschAllocationTdInfo_t;
 //L1TxPowerInfo_t
 typedef struct
 {
     int16_t pdschDmrsPowerOffsetProfileSSS;
     int16_t pdschDataPowerOffsetProfileSSS;
 }log_L1TxPowerInfo_t;

/*MSG_LOG_PDSCH_UE_PDU*/
 typedef struct
 {
    //20Word
    uint16_t                        pduBitmap;
    uint16_t                        RNTI;
    uint16_t                        pduIndex;
    uint16_t                        rev;
    log_L1BwpInfo_t                 BWP;//2
    log_L1CodewordInfo_t            CodewordInfo;//9
    uint16_t                        nIdPdsch;
    uint8_t                         nrOfLayers;
    uint8_t                         refPoint;
    log_L1BeamInfo_t                BeamformingInfo;//3
    log_L1TxPreCodingInfo_t         TxPreCodingInfo;//3
    //30word
    log_L1PdschDmrsInfo_t           DMRSInfo;//3
    log_L1PdschAllocationFdInfo_t   ResourceAllocFd;//12
    log_L1RateMatchingInformation_t RateMatchingInformation;//13
    log_L1PxschAllocationTdInfo_t   ResourceAllocTd;//1
    log_L1TxPowerInfo_t             TxPowerInfo;//1
 }log_L1PdschPduInfo_t;

/*MSG_LOG_PDSCH_BIT_UE_PROC*/
  typedef struct pdschbitproc_ue_s
  {
    //word1
    uint8_t     mcrc_type;//CRC类型：0-CRC16,1-CRC24A
    uint8_t     mcb_num;//码块数目
    uint16_t    mzc;//Zc

    //word 2
    uint16_t    mcb_k;//CB块的长度K
    uint16_t    mcb_k_init;//CB块的K'
    //word 3
    uint16_t    mcb_nulllen;//CB块填充NULL的bit数目
    uint16_t    mcb_seg_bit;//CB块分割中，每个CB块分到的bit数目
    //word 4-7
    uint16_t    mencode_n;//CB块LDPC编码后的bit长度
    uint16_t    mrm_nullpos;//LDPC编码后NULL填充所在的位置

    uint32_t    mrm_er[2];//CB块速率匹配后bit数目：first and last CB Er

    uint16_t    mrm_k0;//K0
    uint16_t    mrm_n_cb;//Ncb

    //word 8-9
    uint32_t    mscramb_c_init;//加扰的Cint
    uint32_t    mscramb_m_bit;//加扰的bit数目（G,即调制映射的数据bit数目）
 }pdschbitproc_ue_t;

/*MSG_LOG_PDSCH_SYMB_UE_PROC*/
typedef struct pdschsymbproc_ue_s
{
    //word 1-8
    uint8_t     dmrs_symb_num;//max 4
    uint8_t     rev2[3];
    uint8_t     dmrs_symb_pos[4];
    uint32_t    dmrs_c_int[4];
    uint16_t    dmrs_seq_start;
    uint16_t    dmrs_seq_max;
    uint16_t    dmrs_seq_len;
    uint16_t    dmrs_map_len;
    //word 9-10
    int8_t      dmrs_delta[4];
    int8_t      dmrs_w_f[4];
    //word 11-28
    uint8_t     data_symb_num;//max 12
    uint8_t     rev3;
    uint8_t     data_symb_mask[14];//symb index=0~13
    uint16_t    map_rb_num[2];
    uint16_t    map_rb_startidx[2];
    uint16_t    map_rb_maxidx[2];
    uint8_t     map_rb_cnt[14];//每个符号占用的哪一组RB数目、RBMask、起始和结束idx
    uint8_t     map_seg_num[2];//由于多个CSI-RS速率匹配，导致的分段数目
    uint16_t    data_re_num[14];//每个符号占用的数据RE数目
    //word 29-30
    uint8_t     is_rm_ssb;
    uint8_t     is_rm_csirs;
    uint8_t     dmrscdm_inx;
    uint8_t     rev4;
    uint16_t    beta_pdschdata;
    uint16_t    beta_pdschdmrs;
}pdschsymbproc_ue_t;

/*MSG_LOG_PDSCH_UE_PROC_PDU*/
typedef struct pdschprocpdu_ue_s
{
    //word 1
    uint32_t          ue_rnti;
    //word 2-10
    pdschbitproc_ue_t bitproc;
    //word 11-40
    pdschsymbproc_ue_t symbproc;
    //word41-90
    log_L1PdschPduInfo_t pdschpdu;
}pdschprocpdu_ue_t;

/*MSG_LOG_PDSCH_UE_PROC*/
typedef struct pdschproc_ue_s
{
    //word 1
    uint32_t          ue_rnti;
    //word 2-10
    pdschbitproc_ue_t bitproc;
    //word 11-39
    pdschsymbproc_ue_t symbproc;
}pdschproc_ue_t;

 typedef struct
 {
    //word 1-5
    uint32_t       dmrs_c_int[4];
    uint16_t       dmrs_seq_start;
    uint16_t       dmrs_seq_len;
    //word 6-7
    int8_t         dmrs_delta[4];
    int8_t         dmrs_w_f[4];
    //word 8-15
    uint16_t       data_re_num[14];//每个符号占用的数据RE数目
    uint8_t        map_seg_num[2];//由于多个CSI-RS速率匹配，导致的分段数目
    uint8_t        rsv0[2];
    //word 16-17
    uint8_t        is_rm_ssb;
    uint8_t        is_rm_csirs;
    uint8_t        dmrscdm_inx;
    uint8_t        rsv1;
    uint16_t       beta_pdschdata;
    uint16_t       beta_pdschdmrs;
 }pdschsymbproc_ue_s_t;
  //L1RateMatchingInformation_t
 typedef struct
 {
     uint16_t ssbConfigForRateMatching;
     uint8_t numCoresetRMP;
     uint8_t numCsiRsForRM;
     uint8_t coresetRMPIndex[LOG_MAX_NUM_CORESET_FOR_RM];
     uint16_t csiRsForRM[4];
 }log_L1RateMatchingInformation_s_t;
 typedef struct
 {
    //Word 1-2
    log_L1BwpInfo_t                 BWP;//2
    //Word 3-6
    log_L1Codeword_t                CodewordInfo;//4
    //Word 7-13
    uint16_t                        nIdPdsch;
    uint8_t                         nrOfLayers;
    uint8_t                         refPoint;
    log_L1BeamInfo_t                BeamformingInfo;//3
    log_L1TxPreCodingInfo_t         TxPreCodingInfo;//3
    //word 14-32
    log_L1PdschDmrsInfo_t           DMRSInfo;//3
    log_L1PdschAllocationFdInfo_t   ResourceAllocFd;//12
    log_L1RateMatchingInformation_s_t RateMatchingInformation;//4
    //Word 33-34
    log_L1PxschAllocationTdInfo_t   ResourceAllocTd;//1
    log_L1TxPowerInfo_t             TxPowerInfo;//1
 }log_L1PdschPduInfo_s_t;
 typedef struct
 {
     //word 1
     uint16_t       ue_rnti;
     uint16_t       ue_cnt;
     //word 2-10
     pdschbitproc_ue_t bitproc;
     //word 11-27
     pdschsymbproc_ue_s_t symbproc;
     //word 28-61
     log_L1PdschPduInfo_s_t pdschpdu;
 }pdschprocpdu_ue_s_t;

 /*MSG_LOG_PDSCH_UE_PROC_PDU_SIMP*/
 typedef struct
 {
     pdschprocpdu_ue_s_t pdschprocpdu_ue[2];
 }pdschprocpdu_2ue_t;

 typedef struct
 {
     uint16_t    sfn;//空口无线帧号
     uint16_t    slot;//空口无线帧号
     uint32_t    time_start; //CSIRS任务的起始时刻(偏移于时隙头的cycle数)
     uint32_t    time_end; //CSIRS任务的结束时刻(偏移于时隙头的cycle数)
     uint16_t    symb_num;//CSI-RS占用的时域符号数目，最大2个
     uint16_t    symb_start;//CSI-RS//占用的起始符号
     uint32_t    symb_mask;//CSI-RS在符号0~13上是否有，1表示有，symb_mask bit0~13分别对应符号0~13
 }log_csirs2dlmapheader_t;//3

 typedef struct
 {
     uint16_t    map_re_start;//起始RE位置
     uint16_t    map_symb_start;//起始时域符号位置
     uint32_t    map_symb_mask;//SSB在符号0~13上是否有，1表示有，map_symb_mask bit0~13分别对应符号0~13
 }log_ssb2dlmapheader_t;//2

 typedef struct
 {
     uint16_t    sfn;//空口无线帧号
     uint16_t    slot;//空口无线帧号
     uint32_t    time_start; //PDCCH任务的起始时刻(偏移于时隙头的cycle数)
     uint32_t    time_end; //PDCCH任务的结束时刻(偏移于时隙头的cycle数)
     uint32_t    symb_num;//PDCCH占用的时域符号数目，最大3个
     uint32_t    symb_mask;//PDCCH在符号0~13上是否有，1表示有，symb_mask bit0~13分别对应符号0~13
 }log_pdcch2dlmapheader_t;//3

 /*MSG_LOG_DL_MAP_CFG*/
 typedef struct
 {
     //word 1-5
     log_pdcch2dlmapheader_t    log_dlpdcchmapcfg;//PDCCH Mapcfg和处理参数
     //word 6-12
     uint32_t                   ssb_num;
     uint32_t                   time_ssb_start; //SSB任务的起始时刻(偏移于时隙头的cycle数)
     uint32_t                   time_ssb_end; //SSB任务的结束时刻(偏移于时隙头的cycle数)
     log_ssb2dlmapheader_t      log_dlssbmapcfg[2];//SSB Mapcfg和处理参数
     //word 13-17
     log_csirs2dlmapheader_t    log_dlcsirsmapcfg;//CSI-RS Mapcfg和处理参数
 }log_dlmapcfg_t;//17

/*MSG_LOG_DL_TASK_PROC*/
 typedef struct dltaskproc_s
 {
    //word 1-5
    uint16_t    sfn_cur;//当前sfn
    uint16_t    sfn_ant;//空口sfn

    uint8_t     slot_cur;//当前slot
    uint8_t     slot_ant;//空口slot
    uint8_t     buff_idx;
    uint8_t     have_dl_proc;   //有下行调度处理

    uint8_t     have_dl_pdsch_proc; //有PDSCH调度处理
    uint8_t     have_dl_pdcch_proc; //有PDCCH Map处理
    uint8_t     have_dl_ssb_proc;   //有SSB Map处理
    uint8_t     have_dl_csirs_proc; //有Csi-rs处理

    uint8_t     pdsch_ue_num;    //PDSCH UE数目
    uint8_t     pdcch_ue_num;   //PDCCH UE数目
    uint8_t     ssb_num;    //SSB数目
    uint8_t     csirs_num;  //CSI-RS数目

    uint8_t     cores_num_proc;
    uint8_t     cnt_symbproc_core0;  //Core0符号级处理的循环次数
    uint8_t     cnt_symbproc_core1;  //Core1符号级处理的循环次数
    uint8_t     ue_num_bitproc_core1;   //Core1比特级处理的UE数目
    //word 6-9
    uint32_t    cfgfapicell_addr;   //Fapi任务->DL任务，小区级消息地址
    uint32_t    cfgfapipdsch_addr;  //Fapi任务->PDSCH信道，PDSCH调度消息地址
    uint32_t    cfgfapitxdat_addr;  //Fapi任务->PDSCH信道，PDSCH Data调度消息地址
    uint32_t    cfgfapicsirspdu_addr;   //Fapi任务->CSI-RS信道，CSI-RS调度消息地址
    //word 10-37
    uint32_t    txant_addr_pre7;
    uint32_t    txant_addr_post7;
    uint32_t    txant_output_len[SYMB_PROC_UNIT_NUM_CORE0];   //每次OFDM处理完输出数据Data数目
    uint32_t    txant_start_addr[SYMB_PROC_UNIT_NUM_CORE0];   //每次OFDM输出天线数据的搬移目的地址
    uint32_t    txant_compidx_start_addr[SYMB_PROC_UNIT_NUM_CORE0];   //每次OFDM输出Cpri天线压缩因子的搬移目的地址
    uint8_t     symb_num_proc[SYMB_PROC_UNIT_NUM_CORE0];   //每次符号级处理的符号数目
    //word 38-54
    log_dlmapcfg_t dlmapcfg;//  其他DL信道的Map参数配置
    //word 55-61
    uint32_t    time_start; //任务的起始时刻(偏移于时隙头的cycle数)
    uint32_t    time_init_end;  //任务初始化结束时刻
    uint32_t    time_calproc_start; //PDSCH 参数计算处理的起始时刻(偏移与时隙头的cycle数)
    uint32_t    time_bitproc_start; //PDSCH BIT级处理的起始时刻(偏移与时隙头的cycle数)
    uint32_t    time_symbproc_start;    //DL符号级处理的起始时刻(偏移与时隙头的cycle数)
    uint32_t    time_end;   //任务的结束时刻(偏移于时隙头的cycle数)
    uint32_t    cycle_proc; //PDSCH任务处理用时：cpu cycle
    //word 62
    uint32_t    dumpflag;
}dltaskproc_t;

/*MSG_LOG_DL1_TASK_PROC*/
 typedef struct dl1taskproc_s
 {
    //word 1-3
    uint16_t    sfn_cur;//当前sfn
    uint16_t    sfn_ant;//空口sfn

    uint8_t     slot_cur;//当前slot
    uint8_t     slot_ant;//空口slot
    uint8_t     buff_idx;
    uint8_t     rev0;

    uint8_t     pdsch_ue_num;    //PDSCH UE数目
    uint8_t     ue_num_bitproc_core1;   //Core1比特级处理的UE数目
    uint16_t    rev1;
    //word 4-16
    uint32_t    txant_output_len[SYMB_PROC_UNIT_NUM];   //每次OFDM处理完输出数据Data数目
    uint32_t    txant_start_addr[SYMB_PROC_UNIT_NUM];   //每次OFDM输出天线数据的搬移目的地址
    uint32_t    txant_compidx_start_addr[SYMB_PROC_UNIT_NUM];   //每次OFDM输出Cpri天线压缩因子的搬移目的地址
    uint8_t     symb_num_proc[SYMB_PROC_UNIT_NUM];   //每次符号级处理的符号数目
    //word 17-23
    uint32_t    time_start; //任务的起始时刻(偏移于时隙头的cycle数)
    uint32_t    time_init_end;  //任务初始化结束时刻
    uint32_t    time_calproc_start; //PDSCH 参数计算处理的起始时刻(偏移与时隙头的cycle数)
    uint32_t    time_bitproc_start; //PDSCH BIT级处理的起始时刻(偏移与时隙头的cycle数)
    uint32_t    time_symbproc_start;    //DL符号级处理的起始时刻(偏移与时隙头的cycle数)
    uint32_t    time_end;   //任务的结束时刻(偏移于时隙头的cycle数)
    uint32_t    cycle_proc; //PDSCH任务处理用时：cpu cycle
    //word 24
    uint32_t    dumpflag;
}dl1taskproc_t;

/*MSG_LOG_PDSCH_UE_TB*/
 typedef struct pdschtb_s
 {
    uint32_t    RNTI;
    char        data[64];
 }pdschtb_t;

//CSIRS STRUCT DEFINE
/*MSG_LOG_CSIRS_UE_PROC*/
typedef struct csirsproc_ue_s
{
    uint32_t        mcsirs_c_init[2];
    uint8_t         mcsirs_sym;
    uint8_t         mnre_perrb;
    uint16_t        mcsirs_seq_max;
    uint16_t        mcsirs_seq_start;
    uint8_t         mportNum;
    uint8_t         mre_k;
    uint8_t         mre_hop;
    uint8_t         rev;
    uint16_t        mbeta_csirs_seq;

}csirsproc_ue_t;

/*MSG_LOG_CSI_PROC_PARAM*/
typedef struct csirs_total_ue_s
{
    uint16_t        csirs_num;
    uint16_t        dumpflag;
    csirsproc_ue_t  csirsproc[22];
}csirs_total_ue_t;

//CSI-RS PDU BWP
typedef struct
{
    uint8_t SubcarrierSpacing;
    uint8_t CyclicPrefix;
    uint16_t rev;
}log_L1CsiBwpInfo_t;//1word
//CSI Tx Power
typedef struct
{
    int16_t csiRsPowerOffsetProfileSSS;
    uint16_t rev;
}log_L1CsiTxPowerInfo_t;//1word
//CSI-RS PDU
typedef struct
{
    uint16_t csiRsPduIndex;
    uint16_t StartRB;
    uint16_t NrOfRBs;
    uint16_t FreqDomain;
    uint16_t ScrambId;
    uint8_t CSIType;
    uint8_t Row;
    uint8_t SymbL0;
    uint8_t SymbL1;
    uint8_t CDMType;
    uint8_t FreqDensity;
    log_L1BeamInfo_t BeamformingInfo;
    log_L1CsiBwpInfo_t BWP;
    log_L1CsiTxPowerInfo_t TxPowerInfo;
}log_L1CsiRsPduInfo_t;//9word
//L1CsiRsPduInfo_t
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    log_L1CsiRsPduInfo_t dlcsirs;
} log_CsirsPduInfo_t;//10word

/*MSG_LOG_CSI_PDU*/
typedef struct
{
    uint16_t	sfn;//空口无线帧号
    uint16_t 	slot;//空口无线帧号
    uint16_t	csirs_num; // CSI-RS数目，用于PDSCH速率匹配
    uint16_t 	rev;
    log_CsirsPduInfo_t	dlcsirspdu[4];//CSI-RS PDU--抄送前12个
} log_cfgfapicsirspdu_t;//35 word

//DEOFDM STRUCT DEFINE
/* MSG_LOG_DEOFDM_INFO */
typedef struct
{
	uint16_t ul_data_sfn;
	uint16_t ul_data_slot;
	uint16_t distributed_flag;   //0: integrated 1: distributed
	uint16_t deofdm_ant;
	uint16_t pucch01_flag;
	uint16_t pucch234_flag;
	uint32_t pusch_flag;
	uint32_t srs_flag;
	uint8_t flexslot_ul_symbol_num;
	uint8_t start_symCycleIndex;
	uint16_t process_symbol_num;
	uint32_t phase_compfactor[8];//phase compensate factor
	int8_t   symbol_timeagc[56];   //symbol_time_agc  factor
	uint32_t freqdata_ptr;       //freqdata_ptr
	uint32_t msgsendtime[4];
	uint32_t start_us;  //1.4Ghz cycle
	uint32_t end_us;
	uint32_t start_sfn;
	uint32_t end_sfn;
	uint32_t start_slot;
	uint32_t end_slot;
}deofdm_log_struct_t;

//MSG_LOG_PUSCH_SYM_INFO
typedef  struct ue_dmrs_info_log_s
{
    uint16_t  rnti;
	uint16_t  ue_index;
	uint8_t  nDMRSConfigType ;       //!0:type1; 1:type2
    uint8_t  nNrOfDMRSSymbols ;      //!1:single DMRS;  2:double DMRS
	uint8_t  dmrs_symbol_num;        //!dmrs symbol number;
	uint8_t  dmrs_port_num;          //!dmrs port number

	uint16_t  numofcdm_without_data;  // nor DMRS CDM groups without data
	uint16_t  dmrs_power_factor;   //!根据numofcdm_without_data,计算得到的DMRS power factor

	uint16_t  dmrs_prb_length;     //生成DMRS根序列使用的参数，相对PointA的DMRS结束PRB位置+1
 	uint16_t  dmrs_prb_start;      //生成DMRS根序列使用的参数，相对PointA的DMRS起始PRB位置

 	uint16_t  dmrs_prb_valid_length;  //!真实有效的DMRS PRB个数，目前只支持type1
    uint16_t  noise_power_factor;  //!噪声估计时使用的power调整值，是 dmrs_power_factor的倒数，Q(16.2)

	uint8_t  dmrs_symbol_index[4];  //symbol index of dmrs

	int32_t   dmrs_cinit[4];   //cinit of each dmrs symbol
	int32_t  dmrs_port_delta[2];

   	//port index for ue word 13~14
   	int32_t  dmrs_port_index[2];
	uint8_t  chest_interpo_dmrs_num[14][2];

	uint8_t  dmrs_symbol_num_in_deofdmdata[4]; //deofdm分段处理时，每个段里包含的dmrs 符号个数

	//MMSE搬移到外存的地址 word 23~26
	uint32_t mmse_ddr_addr[4] ;

    uint16_t type0_subband_num; //后续是否需要考虑载波聚合？
    uint16_t rb_num_in_subband[19]; //根据协议，最大的RBG数目为18，为了对齐和计算offset时方便多增加一个元素
}ue_dmrs_info_log_t;


/*MSG_LOG_PUSCH_SYM_INFO*/
typedef struct pusch_symproc_ueinfo_log_s
{
    uint32_t            handle;
	uint32_t            rnti;
	uint16_t            sfn;
	uint16_t            slot;

	int8_t              min_agc_cal_flag;
	int8_t              min_agc_ante_index;
	int8_t              min_agc;
	int8_t              gain_std;

	//每个符号上的数据的补偿因子 word   5~18
	int8_t              symbol_agc_comp[4][14];

 	uint16_t            ue_cell_idx; //ue_idx in this cell
 	uint8_t             ue_slot_idx;//ue_idx in this slot
 	uint8_t             mod_type;  //!2/4/6/8: qpsk,16qam,64qam,256qam

 	uint8_t             rv;
 	uint8_t             cb_total_num;  //一个UE的总的CB 个数
 	uint8_t             data_symbol_start;
 	uint8_t             data_symbol_end;

 	uint8_t             data_symb_idx; //当前处理的符号索引
 	uint8_t             pad1[3]; //保留位

 	uint8_t             data_symbol_num; //当前调度的数据符号个数（不计入导频）
 	uint8_t             harq_id;
    int16_t             TA;      //TA
    int32_t             noise_power; //噪声功率

 	int16_t             SNR;     //SNR
 	int16_t             mmse_freqcomp_flag;

 	uint16_t            sch_symbol_num; //当前UE调度得符号总数
 	uint16_t            proc_symbol_cnt; //当前UE已经处理的符号个数
 	int16_t             freqerror[2];  //当前slot的频偏记录,Q(16.0)
 	int16_t             phase_delta[2];//当前slot的符号相位差值记录,Q(16.13)

    //当前UE经过平滑之后的相位delta，如果不平滑，则这个值跟phase_delta一样 word 28
 	int16_t             phase_smooth_delta[2];

 	uint32_t            total_re_size;
 	uint32_t            ue_scramble_cinit;  //!ue scramble_cinit
 	uint32_t            ue_scramble_length;//scramble bit length
	ue_dmrs_info_log_t      ue_dmrs_info;    //!ue dmrs info
	uint8_t             dmrs_che_complete_num;
	uint8_t             ue_measure_complete_flag;
	uint8_t             Nl; //层数
    uint8_t             pusch_valid; //是否有sch传输：0-无/1-有
    uint8_t             has_processed_cb_num; //已经处理的CB块
	uint8_t             uci_bitmap;       //0-没有调度/1-有调度(bit0-ack/bit1-csi1/bit2-csi2)
    uint16_t            descramble_data_symbol_num; //完成解扰的符号个数
	uint32_t            has_descrambled_bit_len; //已经解扰的bit长度

	// 上个符号经过解码块级联之后剩下的软bit，用于下一个Cb块 word 71
	uint16_t            last_symbol_remain_softbit;
	uint16_t            rb_num;
	uint32_t            ofdm_re_size; //一个符号上的Re个数

	int32_t             rsrp; //所有天线、port、符号和re上的平均功率

	int16_t             rssi; //参考信号总功率
	uint8_t             resource_alloc; //0->type0,1->type1
	uint8_t             pad2;  //保留位，四字节对齐

	uint8_t             *rb_bitmap; //频域type0配置下的rb映射表
}pusch_symproc_ueinfo_log_t;

/*MSG_LOG_PUSCH_SYM_PDU_HEAD*/
typedef struct
{
    uint16_t sfn; //空口系统帧号
    uint16_t slot; //空口时隙号
    uint32_t d_length; //数据帧长度，包含所有字段
    uint32_t pdu_num;
    uint32_t pdu_len[14];
}L1FapiToPuschInterface_log_t;

/*MSG_LOG_PUSCH_SYM_PDU_BODY*/
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1PuschPduInfo_t pdu;
}PuschPduInfo_log_t;

/*MSG_LOG_PUSCH_SYM_LOG_INFO*/
typedef struct pusch_sym_procinfo_log_s
{
    uint8_t   sch_valid_flag;
    uint8_t   pdu_num; //调度的ue个数
    uint16_t  curr_sfn; //当前系统帧号

    int16_t   freq_offset[14];
    int16_t   ta_offset[14];

    int16_t    snr[14];
    int16_t    rsrp[14];

    uint16_t  start_slot[4];  //四次deofdm调度的起始和结束时间
    uint32_t  start_offset[4];
    uint16_t  end_slot[4];
    uint32_t  end_offset[4];
}pusch_sym_procinfo_log_t;

typedef struct uci_pdu_info_log_s
{
	uint8_t  uci_type; //0-ACK,1-CSI1,2-CSI2
	uint8_t  encode_type; //0-1bit,1-2bit,2-RM,3-Polar
	uint8_t  crc_type;    //0-无CRC，1-CRC6，2-CRC11
    uint8_t  cb_num; //当前uci类型的cb个数

	uint16_t o_len;    //UCI总长度
	uint8_t  cb_padding[2]; //每个cb的padding bit

	uint16_t cb_origin_bit[2]; //本码块的编码原始bit长度

	uint16_t cb_k;
	uint16_t cb_e;

	uint16_t cb_n;
	uint8_t  cb_crc[2];//每个cb的译码结果

	uint32_t payload[2][8]; //每个cb最多抄送8个
}uci_info_log_t; //16byte

/*MSG_LOG_PUSCH_UCICB_INFO*/
typedef struct uci_log_struct_s
{

	uint32_t  start_cycle;
	uint32_t  end_cycle;
	uint32_t  start_sfn_slot;
	uint32_t  end_sfn_slot;


	uint16_t handle;
    uint16_t rnit;

	uint32_t run_cnt;

	uint8_t  numUcis; //当前slot的PDU个数
	uint8_t  Qm;
	uint8_t  RSRP;
	uint8_t  SINR;

	uint16_t TA;
	uint16_t RSSI;

	uint8_t  uci_type_num; //UE的UCI_TYPE_NUM数
	uint8_t  pad[3];

	uci_info_log_t  uci_info[3];
}uci_task_log_t;//20+20+8 byte

typedef struct ue_pdu_info_log_s
{
    uint16_t ue_index_in_cell; //本小区的UE index
	uint8_t  rv;
	uint8_t  cb_total_num;   //一个UE的CB 总数

	uint32_t tb_size; //单位:bit.这里的tbsize 是不带CRC的

	uint16_t ldpc_lift_size; //最大384
	uint16_t  code_rate;

	uint8_t  ldpc_graph;
	uint8_t  mod_type;
	uint8_t  tb_crc_type;
	uint8_t  rsvd;
}ue_pdu_info_log_t; //16byte

typedef struct  ue_rpt_info_log_s
{
    uint32_t handle;

    uint16_t rnti;
    uint16_t TA;

    uint16_t RSSI;
    uint16_t numCb;

    uint8_t harqid;
    uint8_t TbCrcStatus;
    uint8_t RSRP;
    uint8_t SINR;

    uint16_t numTLV;
    int16_t  taCalc;

    uint8_t CbCrcStatus[88];
    uint32_t tbdata[16];

    int8_t NidB[273];
    int8_t rsvd[3];
}ue_rpt_info_log_t; //168byte


/*MSG_LOG_PUSCH_CB_INFO*/
typedef struct pusch_log_struct_s
{
	uint32_t  start_cycle;
	uint32_t  end_cycle;
	uint32_t  start_sfn_slot;
	uint32_t  end_sfn_slot;
	uint32_t  run_cnt;

	ue_pdu_info_log_t  ue_pdu_info;
	ue_rpt_info_log_t  ue_rpt_info;
}cb_task_decode_log_t; //140Byte

//PUCCH STRUCT DEFINE
// PUCCH Log Header
typedef struct
{
	int16_t   SFN;
	int8_t	  Slot;
	int8_t	  numUcis;
	uint16_t  start_slot;
	uint16_t  start_us;
}L1UciPucchHdr_t;

// Format01 Log
typedef struct
{
	uint16_t  nRNTI;
	uint16_t  RSSI;
	uint8_t   SINR;
	uint8_t   format_type;
	uint8_t   pduBitmap;
	uint8_t   DTX;
	uint8_t   Srindication;
	uint8_t   NumHarq;
	uint8_t   HarqValue[2];
}L1UciPucchFmt01_t;

// Format234 Log
typedef struct
{
	uint16_t  nRNTI;
	uint16_t  RSSI;
	uint8_t   SINR;
	uint8_t   format_type;
	uint8_t   pduBitmap;
	uint8_t   SrBitLen;
	uint16_t  HarqBitLen;
	uint16_t  CsiPart1BitLen;
	uint16_t  UciBitLen;
	uint8_t   CrcStatus;
	uint8_t   rev;
	uint8_t   uciPayload[12];
}L1UciPucchFmt234_t;

/* MSG_LOG_PUCCH_F01_UCI_INFO */
typedef struct
{
	L1UciPucchHdr_t UciHeader;
	L1UciPucchFmt01_t pucch_f01_result[32];//每条log最多40UE,40*12Byte
}L1LogPucchFmt01_t;

/* MSG_LOG_PUCCH_F234_UCI_INFO */
typedef struct
{
	L1UciPucchHdr_t UciHeader;
	L1UciPucchFmt234_t pucch_f234_result[16];//每条log最多16UE,16*28Byte
}L1LogPucchFmt234_t;

/**@brief Pucch Allocation in frequency domain*/
typedef struct
{
    uint16_t prbStart;
    uint16_t prbSize;
}log_L1PucchAllocationFdInfo_t;

/**@brief Hopping information*/
typedef struct
{
    uint16_t nIdPucchHopping;
    uint16_t InitialCyclicShift;
    uint16_t nIdPucchScrambling;
    uint16_t secondHopPRB;
    uint8_t intraSlotFrequencyHopping;
    uint8_t pucchGroupHopping;
    uint8_t ulBwpId;
    uint8_t timeDomainOccIdx;
    uint8_t preDftOccIdx;
    uint8_t preDftOccLen;
    uint16_t rev;
}log_L1PucchHoppingInfo_t;


/**@brief PUCCH PDU DMRS*/
typedef struct
{
    uint16_t nId0PucchDmrsScrambling;
    uint8_t m0PucchDmrsCyclicShift;
    uint8_t addDmrsFlag;
}log_L1PucchDMRSInfo_t;

/**@brief PUCCH PDU*/
typedef struct
{
    uint32_t Handle;
    uint16_t RNTI;
    uint8_t FormatType;
    uint8_t multiSlotTxIndicator;
    uint8_t pi2Bpsk;
    uint8_t rev0;
    uint16_t harqBitLen;
    uint16_t csiPart1BitLen;
    uint8_t srBitLen;
    uint8_t combineUciReport;
    log_L1BeamInfo_t BeamformingInfo;
    log_L1BwpInfo_t BWP;
    log_L1PucchAllocationFdInfo_t ResourceAllocFd;
    log_L1PxschAllocationTdInfo_t ResourceAllocTd;
    log_L1PucchHoppingInfo_t hoppingInfo;
    log_L1PucchDMRSInfo_t DMRS;
}log_L1PucchPduInfo_t;

typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    log_L1PucchPduInfo_t pdu;
}log_pucch_pdu_info_t;

#define LOG_MAX_NUM_PUCCH_PDU_PER_SLOT (6)

/* MSG_LOG_PUCCH_ULTTI_REQ */
typedef struct
{
    uint16_t SFN;
    uint16_t Slot;
    uint16_t nPDUs; //PDUType=1 in ULTTI.request PDUs
    uint16_t ulFlag; //0: Special slot 1: Uplink slot
    //PUCCH all format PDUs
    log_pucch_pdu_info_t pdus[LOG_MAX_NUM_PUCCH_PDU_PER_SLOT];
}log_interface_pucch_req_t;

/**@brief for ulBwpId*/
typedef struct
{
    uint16_t nIdPucchHopping;
    uint8_t pucchGroupHopping;
    uint8_t rev0;
}log_L1UlBwpIds_t;

#define LOG_MAX_NUM_UL_BWP (8)

/* MSG_LOG_PUCCH_SS_CONFIG */
typedef struct
{
    uint8_t numUlBwpIds;
    uint8_t rev0;
    uint16_t rev1;
    log_L1UlBwpIds_t UlBwpIds[LOG_MAX_NUM_UL_BWP];/* Max size: 8*/
}log_L1PucchSSConfig_t;


/**@brief Hard pdu for fmt234*/
typedef struct
{
    uint16_t HarqBitLen;
    uint8_t HarqCrc;
    uint8_t rev;
    uint8_t HarqPayload[216];
}log_L1HarqPduForFmt234_t;


/**@brief CSI part1 pdu*/
typedef struct
{
    uint16_t CsiPart1BitLen;
    uint8_t CsiPart1Crc;
    uint8_t rev;
    uint8_t CsiPart1Payload[216];
}log_L1CSIPart1Pdu_t;

/**@brief SR PDU FMT01*/
typedef struct
{
    uint8_t SRindication;
    uint8_t SRconfidenceLevel;
    uint16_t rev;
}log_L1SrPduFMT01_t;


/**@brief Hard pdu for fmt01*/
typedef struct
{
    uint8_t NumHarq;
    uint8_t HarqconfidenceLevel;
    uint8_t HarqValue[2];
}log_L1HarqPduForFm01_t;


/**@brief Sr pdu Fmt234*/
typedef struct
{
    uint8_t SrBitLen;
    uint8_t SrPayload;
    uint16_t rev;
}log_L1SrPduFMT234_t;


/**@brief UCI Inpucch Pdu Fmt01*/
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    uint32_t Handle;
    uint16_t RNTI;
    uint16_t TA;
    uint16_t RSSI;
    uint8_t SINR;
    uint8_t RSRP;
    uint8_t pduBitmap;
    uint8_t PucchFormat;
    uint16_t rev;
    /**This is included if indicated presence by the pduBitmap*/
    log_L1SrPduFMT01_t SrInfo;
    /**This is included if indicated presence by the pduBitmap*/
    log_L1HarqPduForFm01_t HARQInfo;
}log_L1UciInPucchPduFmt01_t;


/**@brief UCI Inpucch Pdu Fmt234*/
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    uint32_t Handle;
    uint16_t RNTI;
    uint16_t TA;
    uint16_t RSSI;
    uint8_t SINR;
    uint8_t RSRP;
    uint8_t PucchFormat;
    uint8_t pduBitmap;
    uint16_t rev;
    /**This is included if indicated presence by the pduBitmap*/
    log_L1SrPduFMT234_t SrInfo;
    /**This is included if indicated presence by the pduBitmap*/
    log_L1HarqPduForFmt234_t HARQInfo;
    /**This is included if indicated presence by the pduBitmap*/
    log_L1CSIPart1Pdu_t CSIPart1Info;
    /**This is included if indicated presence by the pduBitmap*/
}log_L1UciInPucchPduFmt234_t;

/* MSG_LOG_PUCCH_01_UCI_INDICATION */
typedef struct
{
    uint16_t SFN;
    uint16_t Slot;
    uint16_t numUcis;
    uint16_t rev;
    log_L1UciInPucchPduFmt01_t Pdu[4];
}log_L1UciIndicationPucchF01_t;

/* MSG_LOG_PUCCH_234_UCI_INDICATION */
typedef struct
{
    uint16_t SFN;
    uint16_t Slot;
    uint16_t numUcis;
    uint16_t rev;
    log_L1UciInPucchPduFmt234_t Pdu;
}log_L1UciIndicationPucchF234_t;

/* MSG_LOG_PUCCH_TIME_REC */
typedef struct
{
    uint16_t f01_flag;
    uint16_t air_sfn;
    uint16_t air_slot;
    uint16_t start_slot;
    uint16_t start_us;
    uint16_t end_slot;
    uint16_t end_us;
    uint16_t sfn;
}log_pucch_time_rec_t;

//SRS STRUCT DEFINE
typedef struct
{
	uint16_t  RNTI;
	uint16_t  sequenceId;
	uint16_t  frequencyShift;
	uint8_t   numAntPorts;
	uint8_t   numSymbols;

	uint8_t   numRepetitions;
	uint8_t   timeStartPosition;
	uint8_t   configIndex;
	uint8_t   bandwidthIndex;

	uint8_t   combSize;
	uint8_t   combOffset;
	uint8_t   cyclicShift;
	uint8_t   frequencyPosition;

	uint8_t   frequencyHopping;
	uint8_t   groupOrSequenceHopping;
	uint8_t   resourceType;
	int8_t    TA;

	//uint8_t   u[4];
	//uint8_t   v[4];
	uint16_t  q[4];
	//uint8_t   nsc_shift_p[2];
	uint16_t  m_src_rb;
	uint8_t   rev[2];
	//uint16_t  m_src_sc;
	//uint16_t  Nzc;
	uint16_t  k0[4];
	uint8_t   wideBandSINR[4];
	uint8_t   srs_rb_idex[4];
	uint16_t  rb_rsrp_sinr[4];
}Srs_log_Parameter_Result_t;

/* MSG_LOG_SRS_INFO */
typedef struct
{
	L1UciPucchHdr_t UciHeader;
	Srs_log_Parameter_Result_t Srs_result[8];//每条log最多8UE,56*8Byte
}L1LogSRS_t;


// SRS FAPI PDU
typedef struct
{
    uint16_t digBFIterface;//Logical Ant Ports
    uint16_t rev0;
    uint16_t beamIdx[4];//MAX_DL_ANT_PORTS=4
}L1BeamInfo_log_t;

typedef struct
{
    uint16_t BWPSize;
    uint16_t BWPStart;
    uint8_t SubcarrierSpacing;
    uint8_t CyclicPrefix;
    uint16_t rev;
}L1BwpInfo_log_t;

typedef struct
{
    uint32_t Handle;
    uint16_t RNTI;
    uint16_t sequenceId;

    uint16_t frequencyShift;
    uint16_t Tsrs;

    uint16_t Toffset;
    uint8_t numAntPorts;
    uint8_t numSymbols;

    uint8_t numRepetitions;
    uint8_t timeStartPosition;
    uint8_t configIndex;
    uint8_t bandwidthIndex;

    uint8_t combSize;
    uint8_t combOffset;
    uint8_t cyclicShift;
    uint8_t frequencyPosition;

    uint8_t frequencyHopping;
    uint8_t groupOrSequenceHopping;
    uint8_t resourceType;
    uint8_t rev0;

    uint8_t TransformPrecoding;
    uint8_t codebookSubset;
    uint8_t SRSUsage;
    uint8_t rev1;

    L1BeamInfo_log_t BeamformingInfo; //3
    L1BwpInfo_log_t BWP;   //2
}L1SrsPdu_log_t;

typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1SrsPdu_log_t pdu;
}srs_pud_info_log_t;

/* MSG_LOG_SRS_FAPI_INFO */
typedef struct
{
    uint16_t sfn; //空口系统帧号
    uint16_t slot; //空口时隙号

    uint32_t pdu_num;

    srs_pud_info_log_t srs[8];
}Log_fapi_srs_cfg_t;


typedef struct
{
    uint8_t   srs_multiplex_cal_over_flag;
    uint8_t   srs_multiplex_group_over_flag; //是否已进行复用组pdu分组计算
    uint8_t   cycleshift; //存储pdu调度的cycleshift信息,用作DEOCC复用组计算；
    uint8_t   multiplex_group_N; //复用组系数N,用于DEOCC

    uint16_t  m_srs_b;  //srs bandwidth,即RB_num
    uint16_t  M_srs_sc; //srs subcarrier

    uint8_t   u[4];
    uint8_t   v[4];

    uint8_t   port_cs[2];
    uint8_t   combOffset[2];
    uint16_t  k0[4][2];

    uint8_t   Ktc;
    uint8_t   ncs_max;
    uint8_t   start_symbol;
    uint8_t   symbol_num;

    uint8_t   symbol_flag;
    uint8_t   port_num;
    uint16_t  Nzc;

    uint32_t  Nzc_inv;    //1/Nzc
    uint32_t  pi_Nzc_inv; //pi/Nzc
    uint16_t  q[4];
    //周期性和半持续的SRS时,每个时隙的SRS传输机会是累计的,记录当前slot的nSRS基线
    uint32_t  nSRS_base;
    //本slot内最多4个SRS符号的nSRS
    uint16_t  nSRS[4];

    uint8_t   multiplex_ue_num; //时频域资源跟其他UE复用的UE个数,用于DEOCC时使用
    int8_t    min_agc;  //SRS多个符号里的最小agc因子
    int16_t   TA;       //UE的TA值,以采样点为单位

    uint32_t  deocc_noise_compensation_factor; //DEOCC将噪声功率平均,计算SNR时的补偿值

    uint16_t  prb_start[4];
}Srs_UeParam_LOG_t;

/*MSG_LOG_SRS_PARAM_INFO*/
typedef struct
{
    Srs_UeParam_LOG_t srs_param[4];
}Log_Srs_Param_Msg_t;

// SRS Indication
typedef struct
{
    uint8_t rbSINR;
    uint8_t rbRSRP;
    uint16_t rev;
}L1RbsBlock_log_t;

typedef struct
{
    uint16_t numRBs;
    uint16_t rev;
    L1RbsBlock_log_t rbSINR[100];
}L1SrsSymbolInfo_log_t;

typedef struct
{
    uint32_t Handle;
    uint16_t RNTI;
    uint16_t TA;
    uint8_t numSymbols;
    uint8_t numReportedSymbols;
    uint16_t rev;
    uint8_t wideBandSINR[4];

    L1SrsSymbolInfo_log_t symbolInfo;
}L1SrsPduInfo_log_t;

/*MSG_LOG_SRS_IND_INFO*/
typedef struct
{
    uint16_t SFN;
    uint16_t Slot;

    uint8_t numPDUs;
    uint8_t rev0;
    uint16_t rev1;

    L1SrsPduInfo_log_t pdus;
}L1SrsIndication_log_t;

typedef struct
{
    uint16_t handle;
    uint16_t rsv0;

	uint16_t nTransid;
    uint16_t nRNTI;

    uint8_t  nSymbolIndex;
    uint8_t  nRiIdx;
    int16_t  nTa;

    int16_t  nRSRP[4];
    int16_t  nPreSNR[4];
    uint8_t  nTPMI[4];

    int16_t  nPostSNR[4];
    uint8_t  nStartBlock;
    uint8_t  nNrOfBlocks;
    uint8_t  rsv1[2];
    int16_t  nBlockSNR[8];
} L1PostSRSEst_log_t;

/*MSG_LOG_SRS_POST_IND_INFO*/
typedef struct
{
    uint16_t SFN;
    uint16_t Slot;
    uint8_t nNrOfSrs;
    uint8_t rsv0[3];

    L1PostSRSEst_log_t pdus[6];
} L1PostSrsIndication_log_t;


//PRACH STRUCT DEFINE
/*MSG_LOG_Prach_CONFIGPARAM*/
typedef struct log_prach_local_database{
      uint32_t prachZeroCorrConf;
	  uint32_t prachSubCSpacing;
	  uint32_t prachConfigIndex;
	  uint32_t numPrachFdOccasions;
	  uint32_t restrictedSetConfig;
	  uint32_t prachSequenceLength;
	  uint32_t prachRootSequenceIndex;
	  uint32_t msg1_freqencystart;  //!prach 频域起始位置，相对于PointA的

	  uint32_t cp_len;               //prach cp length
	  uint32_t prach_Nu_len;         //!prach Nu length
	  uint32_t root_sequence_num;   //根序列个数
	  uint32_t prach_start_k;        //!prach 起始子载波
	  uint32_t thresholdset;
	  uint32_t prach_repeat_num;
}log_local_prach_database_t;

typedef struct log_prach_detect_result{
      uint32_t      time_occasion_index;//时机索引
	  uint32_t		valid_flag; //! 1:valid, 0:invalid
	  uint32_t		detect_preamble_num; //! max detect_num = 10
	  uint32_t		fdm_index;	//! freq domain index, 0-7
	  uint32_t		preamble_id[10]; //! preamble_id,0-63
	  uint32_t		ta[10];    //!each preamble's ta ,1ta = 32TS, [0---3846]
	  uint32_t		preamblePwr[10];  //!each preamble's power
	  uint32_t		preambleSNR[10]; //!each preamble's snr

}log_prach_detect_result_t;


typedef struct
{
    uint8_t msgNum;
    uint8_t cellIndex;
    uint16_t rev;
}log_L1MsgHdr_t;

typedef struct
{
    uint32_t msgId;
    uint32_t msgSize;
}log_L1GeneralMsgHdr_t;


typedef struct
{
    uint32_t PreamblePwr;
    uint16_t TA;
    uint8_t preambleSinr;
    uint8_t preambleIndex;
}log_L1PreambleInfo_t;

typedef struct
{
    uint16_t handle;
    uint16_t avgRssi;
    uint8_t avgSinr;
    uint8_t SymbolIndex;
    uint8_t SlotIndex;
    uint8_t raIndex;
    uint8_t numPreambles;
    uint8_t rev0;
    uint16_t rev1;
    /**variable-size by numPreamble*/
    log_L1PreambleInfo_t preamble[10];/* Max size: MAX_NUM_PREAMBLE_PER_PRACH_PDU_RPT*/
}log_L1RachPduInfo_t;

typedef struct
{
    uint16_t SFN;
    uint16_t Slot;
    uint8_t numPDUs;
    uint8_t rev0;
    uint16_t rev1;
    /**variable-size by numPDUs*/
    log_L1RachPduInfo_t pdus;/* Max size: MAX_NUM_PRACH_PDU_IN_PRACH_INDICATION*/
}log_L1RachIndication_t;

/*MSG_LOG_PRACH_REPORT_MSG*/
typedef struct log_prach_msg_report_s
{
	log_L1MsgHdr_t prach_head;
	log_L1GeneralMsgHdr_t prach_general_head;
	log_L1RachIndication_t prach_ind;
}log_prach_msg_report_t;

/*MSG_LOG_PRACH_TIME_AGC_FACTOR*/
typedef struct log_prach_time_agc_factor_s
{
	int32_t  time_agc[56];
}log_prach_time_agc_factor_t;


/*MSG_LOG_PRACH_TIME_OCCASION_RESULT*/
typedef struct log_prach_time_occasion_result{
	  //uint32_t occasion_index;
	  int32_t  time_agc[56];
	  uint32_t prach_time_start;
	  log_prach_detect_result_t detect_result;
}log_prach_time_occasion_result_t;


/*MSG_LOG_PRACH_REQUEST*/
typedef struct log_prach_request{
      uint32_t  flag_slot0;//接收buffer的第一个slot的flag
      uint32_t  flag_slot1;//接收buffer的第二个slot的flag
      uint32_t  flag_slot2;//接收buffer的第三个slot的flag
      uint32_t  have_flag;//处理中使用的falg
      uint32_t  have_long_flag;//长码flag
      uint32_t  start_sfn;
      uint32_t  end_sfn;
      uint32_t  start_slot;
      uint32_t  end_slot;
      uint32_t  start_us;
      uint32_t  end_us;

}log_prach_request_t;
#endif
#endif
