#ifndef NRPHYAPI_H
#define NRPHYAPI_H

#if defined(TARGET_ARMv8)
#include "nrtypes.h"

#else
typedef    char                  int8;
typedef    short                 int16;
typedef    int                   int32;
typedef    long long             int64;

typedef    unsigned char         uint8;
typedef    unsigned short        uint16;
typedef    unsigned int          uint32;
typedef    unsigned long long    uint64;
#endif

/* Type: power in 0.1dB */
typedef struct FAPI_STRUCT_ALIGN
{
    int32 power;        /* in dB*10, value: -1270~1280, */
} nrPhyApi_Power_t;

/* Protocol defined constants */

#define API_MAX_NUM_PRB                   (159)  /* Maximal number of PRBs in carrier bandwidth */
#define API_MAX_NUM_CORESET               (6)   /* Maximal number of CORESETs in carrier bandwidth */ 

#define API_MAX_NUM_TB_PER_PDU            (2)    /* Maximal number of TBs in a PDU */

#define API_MAX_BIT_LEN_PUSCH_UCI_CSI     (1706) /* Maximal bit length of PUSCH UCI CSI payload
                                                    Max Polar encoding bit sequence is 1706 bit */
#define API_MAX_BIT_LEN_PUSCH_UCI_ACK     (128)  /* max_CBG(8) x max_TB_num(2) x max_CC_num(8) = 128bit */

                                                    /* Interface specific constants */
#define API_MAX_LEN_TLV                   (4)    /* Maximal length of TLV, in bytes */
#define API_MAX_LEN_TLV_STR               (64)   /* Maximal length of string and structure in TLV */

#define API_MAX_NUM_CSI_REPORT_PER_TTI    (4)   /* Maximal report in protocol is 48*/

#define API_MAX_NUM_CSI_IND_PER_TTI       (5)    /* Maximal indication number in protocol is 48, L1 only support 5 at most*/

#define API_MAX_NUM_UL_RANK               (4)    /* Maximal number of ul rank */
#define API_MAX_NUM_PMI_METRIC            (6)    /* Maximal number of PMI metric for 1 and 2 antenna port */

#define API_MAX_NUM_TX_ANT                (4)    /* Maximal number of antenna */
#define API_MAX_NUM_RX_ANT                (4)    /* Maximal number of antenna */

#define API_MAX_ERR_NUM_PER_ERR_TYPE      (30)   /* Maximal number of error report per slot */

#define API_MAX_NUM_UE_PER_TTI            (16)   /* Maximal number of scheduled UE per TTI */

#define API_MAX_NUM_PUCCH_UE_PER_TTI      (32)   /* Maximal number of scheduled PUCCH UE per TTI */

#define API_MAX_NUM_PRACH_UE_PER_TTI      (4)   /* Maximal number of scheduled UE per TTI */

#define API_MAX_NUM_SRS_SYM               (4)    /* Maximal number of SRS symbol */

#define API_MAX_NUM_SRS_PORT              (4)    /* Maximal transmission port number of srs */

#define API_MAX_NUM_SRS_SUBBAND           (68)   /* Maximal number of subbands, 68=272/4 */

#define API_MAX_PDSCH_ZP_CSIRS_PER_TTI  (32)   /* Maximal number of PDSCH ZP CSI-RS set */


#define API_PUCCH_UCI_ACK_BYTE_LEN       (32)//FAPI_ROUNDUP1(API_PUCCH_ACK_INFO_BITS_NUM_MAX)
#define API_PUSCH_UCI_ACK_WORD_LEN       (4)  //(FAPI_ROUNDUP1(API_MAX_BIT_LEN_PUSCH_UCI_ACK) >> 2)

/* There is total 1706 bit CSI at most, now only supoort 128 bit csi payload*/
#define API_PUSCH_PUCCH_UCICSI_WORD_LEN  (4)//FAPI_ROUNDUP1(API_MAX_BIT_LEN_PUSCH_UCI_CSI) >> 2, 

/**@brief Define F1AP struct be used in all 5G NR stacks.

*/
#ifndef NUM_EROLOGIES
#define NUM_EROLOGIES 5
#endif

#ifndef NUM_UNUSED_ROOT_SEQUENCES
#define NUM_UNUSED_ROOT_SEQUENCES 3
#endif

#ifndef NUM_SSB_MASK
#define NUM_SSB_MASK 2
#endif

#ifndef NUM_SSB_BEAM_ID
#define NUM_SSB_BEAM_ID 64
#endif

#ifndef NUM_MAP
#define NUM_MAP 2
#endif

#ifndef NUM_FREQ_DOMAIN_RES
#define NUM_FREQ_DOMAIN_RES 6
#endif

#ifndef NUM_FREQ_DOMAIN_RB
#define NUM_FREQ_DOMAIN_RB 35
#endif

#ifndef NUM_DL_DCI_PAYLOAD
#define NUM_DL_DCI_PAYLOAD 20
#endif

#ifndef NUM_CORESET_FREQDOMAINRESOURCE
#define NUM_CORESET_FREQDOMAINRESOURCE 6
#endif

#ifndef NUM_PXSCH_RB_BITMAP
#define NUM_PXSCH_RB_BITMAP 20
#endif

#ifndef NUM_DL_TB_CRCCW
#define NUM_DL_TB_CRCCW 8
#endif

#ifndef NUM_PUSCH_CB_PRESENT_AND_POSITION
#define NUM_PUSCH_CB_PRESENT_AND_POSITION 16
#endif

#ifndef NUM_CB_CRC_STATUS
#define NUM_CB_CRC_STATUS 16
#endif

#ifndef NUM_HARQ_PAYLOAD
#define NUM_HARQ_PAYLOAD 216
#endif

#ifndef NUM_CSI_PART1_PAYLOAD
#define NUM_CSI_PART1_PAYLOAD 216
#endif

#ifndef NUM_PDU_EACH_TYPE
#define NUM_PDU_EACH_TYPE 5
#endif

#ifndef NUM_ULDCI_PDU_EACH_TYPE
#define NUM_ULDCI_PDU_EACH_TYPE 2
#endif

#ifndef NUM_PART1_PARAMS
#define NUM_PART1_PARAMS 4
#endif

#ifndef MAX_NUM_PART2_TYPES
#define MAX_NUM_PART2_TYPES 8
#endif

#ifndef MAX_SLOT_CFG_NUM
#define MAX_SLOT_CFG_NUM 21   /* 2DL=5+5;2UL=5+6 */
#endif

#ifndef MAX_NUM_CELLS
#define MAX_NUM_CELLS 1
#endif

#ifndef MAX_NUM_TX_ANTENNAS_1CELL
#define MAX_NUM_TX_ANTENNAS_1CELL 4
#endif

#ifndef MAX_NUM_RX_ANTENNAS_1CELL
#define MAX_NUM_RX_ANTENNAS_1CELL 4
#endif

#ifndef MAX_NUM_TX_ANTENNAS_2CELL
#define MAX_NUM_TX_ANTENNAS_2CELL 8
#endif

#ifndef MAX_NUM_RX_ANTENNAS_2CELL
#define MAX_NUM_RX_ANTENNAS_2CELL 8
#endif

#ifndef MAX_NUM_TX_ANTENNAS
#define MAX_NUM_TX_ANTENNAS MAX_NUM_TX_ANTENNAS_1CELL
#endif

#ifndef MAX_NUM_RX_ANTENNAS
#define MAX_NUM_RX_ANTENNAS MAX_NUM_RX_ANTENNAS_1CELL
#endif

#ifndef MAX_NUM_SSB_PDU_PER_SLOT
#define MAX_NUM_SSB_PDU_PER_SLOT 2
#endif

#ifndef MAX_NUM_UL_BWP
#define MAX_NUM_UL_BWP 1
#endif

#ifndef MAX_TOTAL_NUM_DL_DCI_PDU_PER_SLOT
#define MAX_TOTAL_NUM_DL_DCI_PDU_PER_SLOT 14
#endif

#ifndef MAX_TOTAL_NUM_UL_DCI_PDU_PER_SLOT
#define MAX_TOTAL_NUM_UL_DCI_PDU_PER_SLOT 28
#endif

#ifndef MAX_NUM_PDCCH_PDU_FOR_DL_PER_SLOT
#define MAX_NUM_PDCCH_PDU_FOR_DL_PER_SLOT 4
#endif

#ifndef MAX_NUM_PDCCH_PDU_FOR_UL_PER_SLOT
#define MAX_NUM_PDCCH_PDU_FOR_UL_PER_SLOT 4
#endif

#ifndef MAX_NUM_DL_DCI_PDU_PER_PDCCH_PDU
#define MAX_NUM_DL_DCI_PDU_PER_PDCCH_PDU 14
#endif

#ifndef MAX_NUM_UL_DCI_PDU_PER_PDCCH_PDU
#define MAX_NUM_UL_DCI_PDU_PER_PDCCH_PDU 14
#endif

#ifndef MAX_NUM_CSI_RS_PDU_PER_SLOT
#define MAX_NUM_CSI_RS_PDU_PER_SLOT 22
#endif

#ifndef MAX_NUM_PDSCH_PDU_PER_SLOT
#define MAX_NUM_PDSCH_PDU_PER_SLOT 14
#endif

#ifndef MAX_NUM_DL_PDU_PER_SLOT
#define MAX_NUM_DL_PDU_PER_SLOT (MAX_NUM_SSB_PDU_PER_SLOT +MAX_TOTAL_NUM_DL_DCI_PDU_PER_SLOT+MAX_NUM_CSI_RS_PDU_PER_SLOT +MAX_NUM_PDSCH_PDU_PER_SLOT)
#endif

#ifndef MAX_NUM_PUSCH_PDU_PER_SLOT
#define MAX_NUM_PUSCH_PDU_PER_SLOT 14
#endif

#ifndef MAX_NUM_ULSCH_PDU_IN_RX_DATA_INDICATION
#define MAX_NUM_ULSCH_PDU_IN_RX_DATA_INDICATION MAX_NUM_PUSCH_PDU_PER_SLOT
#endif

#ifndef MAX_NUM_ULSCH_CRC_IN_CRC_INDICATION
#define MAX_NUM_ULSCH_CRC_IN_CRC_INDICATION MAX_NUM_PUSCH_PDU_PER_SLOT
#endif

#ifndef MAX_NUM_PUSCH_UCI_PDU_IN_UCI_INDICATION
#define MAX_NUM_PUSCH_UCI_PDU_IN_UCI_INDICATION MAX_NUM_PUSCH_PDU_PER_SLOT
#endif

#ifndef MAX_NUM_PUCCH_PDU_FMT_0_1_PER_SLOT
#define MAX_NUM_PUCCH_PDU_FMT_0_1_PER_SLOT 112
#endif

#ifndef MAX_NUM_PUCCH_FMT_0_1_UCI_IN_UCI_INDICATION
#define MAX_NUM_PUCCH_FMT_0_1_UCI_IN_UCI_INDICATION MAX_NUM_PUCCH_PDU_FMT_0_1_PER_SLOT
#endif

#ifndef MAX_NUM_PUCCH_PDU_FMT_2_3_4_PER_SLOT
#define MAX_NUM_PUCCH_PDU_FMT_2_3_4_PER_SLOT 0
#endif

#ifndef MAX_NUM_PUCCH_FMT_2_3_4_UCI_IN_UCI_INDICATION
#define MAX_NUM_PUCCH_FMT_2_3_4_UCI_IN_UCI_INDICATION MAX_NUM_PUCCH_PDU_FMT_2_3_4_PER_SLOT
#endif

#ifndef MAX_UCI_NUM_IN_UCI_IND
#define MAX_UCI_NUM_IN_UCI_IND (MAX_NUM_PUSCH_UCI_PDU_IN_UCI_INDICATION+MAX_NUM_PUCCH_FMT_0_1_UCI_IN_UCI_INDICATION+MAX_NUM_PUCCH_FMT_2_3_4_UCI_IN_UCI_INDICATION)
#endif

#ifndef MAX_NUM_PUCCH_PDU_PER_SLOT
#define MAX_NUM_PUCCH_PDU_PER_SLOT (MAX_NUM_PUCCH_PDU_FMT_0_1_PER_SLOT+MAX_NUM_PUCCH_PDU_FMT_2_3_4_PER_SLOT)
#endif

#ifndef MAX_NUM_SRS_PDU_PER_SLOT
#define MAX_NUM_SRS_PDU_PER_SLOT 40
#endif

#ifndef MAX_NUM_SRS_PRB
#define MAX_NUM_SRS_PRB 159
#endif

#ifndef MAX_NUM_SRS_SYMBOL
#define MAX_NUM_SRS_SYMBOL 1
#endif

#ifndef MAX_NUM_RPT_SRS_SYMBOL
#define MAX_NUM_RPT_SRS_SYMBOL 1
#endif

#ifndef MAX_NUM_PRACH_OCCASIONS_IN_FREQ_DOMAIN
#define MAX_NUM_PRACH_OCCASIONS_IN_FREQ_DOMAIN 1
#endif

#ifndef MAX_NUM_PRACH_CONFIG
#define MAX_NUM_PRACH_CONFIG 1
#endif

#ifndef MAX_NUM_PRACH_OCCASIONS_IN_TIME_DOMAIN
#define MAX_NUM_PRACH_OCCASIONS_IN_TIME_DOMAIN 1
#endif

#ifndef MAX_NUM_PRACH_PDU_PER_SLOT
#define MAX_NUM_PRACH_PDU_PER_SLOT MAX_NUM_PRACH_OCCASIONS_IN_FREQ_DOMAIN
#endif

#ifndef MAX_TOTAL_NUM_PRACH_PREAMPLES
#define MAX_TOTAL_NUM_PRACH_PREAMPLES 16
#endif

#ifndef MAX_NUM_PRACH_PDU_IN_PRACH_INDICATION
#define MAX_NUM_PRACH_PDU_IN_PRACH_INDICATION (MAX_NUM_PRACH_OCCASIONS_IN_FREQ_DOMAIN*MAX_NUM_PRACH_OCCASIONS_IN_TIME_DOMAIN)
#endif

#ifndef MAX_NUM_PREAMBLE_PER_PRACH_PDU_RPT
#define MAX_NUM_PREAMBLE_PER_PRACH_PDU_RPT MAX_TOTAL_NUM_PRACH_PREAMPLES
#endif

#ifndef MAX_NUM_PDU_IN_UL_TTI_REQ
#define MAX_NUM_PDU_IN_UL_TTI_REQ (MAX_NUM_PREAMBLE_PER_PRACH_PDU_RPT + MAX_NUM_SRS_PDU_PER_SLOT + MAX_NUM_PUCCH_PDU_PER_SLOT + MAX_NUM_PUSCH_PDU_PER_SLOT)
#endif

#ifndef MAX_NUM_TXRU
#define MAX_NUM_TXRU 4
#endif

#ifndef MAX_NUM_DIG_BEAMS
#define MAX_NUM_DIG_BEAMS 64
#endif

#ifndef MAX_NUM_LAYERS
#define MAX_NUM_LAYERS 4
#endif

#ifndef MAX_NUM_DL_GROUP_UE
#define MAX_NUM_DL_GROUP_UE 12
#endif

#ifndef MAX_NUM_UL_GROUP_UE
#define MAX_NUM_UL_GROUP_UE 6
#endif

#ifndef MAX_NUM_BUG_BFINTERFACES
#define MAX_NUM_BUG_BFINTERFACES 512
#endif

#ifndef MAX_NUM_PRGS
#define MAX_NUM_PRGS 159
#endif

#ifndef MAX_NUM_CSI_RS_FOR_RM
#define MAX_NUM_CSI_RS_FOR_RM 22
#endif

#ifndef MAX_NUM_CORESET_FOR_RM
#define MAX_NUM_CORESET_FOR_RM 4
#endif

#ifndef MAX_NUM_PDSCH_NR_Of_CODEWORD
#define MAX_NUM_PDSCH_NR_Of_CODEWORD 1
#endif

#ifndef MAX_NUM_PDCCH_DlDCI
#define MAX_NUM_PDCCH_DlDCI 14
#endif

#ifndef MAX_NUM_DL_GROUP_PER_SLOT
#define MAX_NUM_DL_GROUP_PER_SLOT 16
#endif

#ifndef MAX_NUM_RX_BEAMFORMING
#define MAX_NUM_RX_BEAMFORMING 512
#endif

#ifndef MAX_NUM_PUSCH_PTRS_PORT
#define MAX_NUM_PUSCH_PTRS_PORT 2
#endif

#ifndef MAX_NUM_GROUP_IN_UL_TTI_REQ
#define MAX_NUM_GROUP_IN_UL_TTI_REQ 16
#endif

#ifndef MAX_NUM_TXDATA_TLV
#define MAX_NUM_TXDATA_TLV 4
#endif

#ifndef MAX_NUM_PART1_PARAMS
#define MAX_NUM_PART1_PARAMS 4
#endif

//This value is 65535 in FAPI version 222.10.03
#ifndef MAX_NUM_UCIMAPS
#define MAX_NUM_UCIMAPS 255
#endif

#ifndef MAX_NUM_OF_SLOTS_INFO_PRE_CTRL_MSG
#define MAX_NUM_OF_SLOTS_INFO_PRE_CTRL_MSG 20
#endif

#ifndef MAX_LENGTH_OF_RRU_MSG_PRE_CTRL_MSG
#define MAX_LENGTH_OF_RRU_MSG_PRE_CTRL_MSG 164
#endif

#ifndef MAX_NR_ZONE
#define MAX_NR_ZONE 4
#endif

#ifndef MAX_NR_M_IN_ZONE
#define MAX_NR_M_IN_ZONE 4
#endif

#ifndef MAX_NR_HALF_M_IN_ZONE
#define MAX_NR_HALF_M_IN_ZONE MAX_NR_M_IN_ZONE*2
#endif

#ifndef MAX_NR_SUBBAND_IN_DOWNZONE
#define MAX_NR_SUBBAND_IN_DOWNZONE 159
#endif

#ifndef MAX_NR_SUBBAND_IN_UPZONE
#define MAX_NR_SUBBAND_IN_UPZONE 119
#endif


typedef enum
{
    FAPI_PARAM_REQUEST,
    FAPI_PARAM_RESPONSE,
    FAPI_CONFIG_REQUEST,
    FAPI_CONFIG_RESPONSE,
    FAPI_START_REQUEST,
    FAPI_STOP_REQUEST,
    FAPI_STOP_INDICATION,
    FAPI_ERROR_INDICATION,
    FAPI_DL_TTI_REQUEST = 0x80,
    FAPI_UL_TTI_REQUEST,
    FAPI_SYMBOL_INDICATION,
    FAPI_UL_DCI_REQUEST,
    FAPI_TX_DATA_REQUEST,
    FAPI_RX_DATA_INDICATION,
    FAPI_CRC_INDICATION,
    FAPI_UCI_INDICATION,
    FAPI_SRS_INDICATION,
    FAPI_PRACH_INDICATION,
    SLOT_CTRL_MSG_ID = 0xA1,
    SLOT_SRS_POST_INDICATION,
    SLOT_RB_NI_INDICATION,
    TX_DATA_MSG_ID = 0xB0,
    RX_DATA_MSG_ID = 0xB1,
    L1FAPIMSGID_E_CNT
}L1FAPIMsgId_e;


typedef enum
{
    FAPI_MSG_OK,
    FAPI_MSG_INVALID_STATE,
    FAPI_MSG_INVALID_CONFIG,
    FAPI_SFN_OUT_OF_SYNC,
    FAPI_MSG_SLOT_ERR,
    FAPI_MSG_BCH_MISSING,
    FAPI_MSG_INVALID_SFN,
    FAPI_MSG_UL_DCI_ERR,
    FAPI_MSG_TX_ERR,
    L1FAPIERRORCODE_E_CNT
}L1FAPIErrorCode_e;


/**@brief L1 Msg Head*/
typedef struct
{
    uint8_t msgNum;
    uint8_t cellIndex;
    uint16_t rev;
}L1MsgHdr_t;


/**@brief L1 General Msg Head*/
typedef struct
{
    L1FAPIMsgId_e msgId;
    uint32_t msgSize;
}L1GeneralMsgHdr_t;


/**@brief PARAM request*/
typedef struct
{
    uint8_t SpectrumDetectionZone[MAX_NR_ZONE];
}L1ParamRequest_t;


/**@brief PARAM response*/
typedef struct
{
    uint8_t ErrorCode;
    uint8_t SubbandInN[MAX_NR_SUBBAND_IN_DOWNZONE];
}L1ParamResponse_t;


/**@brief Carri Configuration.*/
typedef struct
{
    uint32_t dlFrequency;
    uint32_t ulFrequency;
    uint16_t dlBandwidth;
    uint16_t ulBandwidth;
    uint16_t dlk0[NUM_EROLOGIES];
    uint16_t ulk0[NUM_EROLOGIES];
    uint16_t dlGridSize[NUM_EROLOGIES];
    uint16_t ulGridSize[NUM_EROLOGIES];
    uint16_t numTxAnt;
    uint16_t numRxAnt;
    uint8_t FrequencyShift7p5KHz;
    uint8_t rev0;
    uint16_t rev1;
}L1CarriConfigInfo_t;


/**@brief Cell Configuration.*/
typedef struct
{
    uint16_t phyCellId;
    uint8_t FrameDuplexType; // 0：FDD; 1: TDD
    uint8_t rev0;
}L1CellConfigInfo_t;


/**@brief SSB Configuration.*/
typedef struct
{
    int16_t ssPbchBlockPowerScaling;
    uint8_t bchPayloadFlag;
    uint8_t rev0;
}L1SsbConfigInfo_t;


/**@brief PRACH Configuration.*/
typedef struct
{
    uint16_t prachRootSequenceIndex;
    uint16_t Rev;
}L1PrachConfigInfo_t;

/**@brief TDD Table*/
typedef struct
{
    uint8_t TddPeriod; // 周期模式： 7：10ms周期
    uint8_t rev0;
    uint16_t rev1;
    uint8_t SlotConfig[MAX_SLOT_CFG_NUM]; /* 0: DL Symbol; 1:UL Symbol; 2:Flexible Symbol，G slot算一个符号？ */
    uint8_t rev2;
    uint16_t rev3;
}L1TddTableConfigInfo_t;


/**@brief Measurement Config*/
typedef struct
{
    uint8_t RssiMeasurement;
    uint8_t RsrpMeasurement;
    uint16_t rev;
}L1MeasurementConfigInfo_t;


/**@brief L1ConfigRequest_t*/
typedef struct
{
    L1CarriConfigInfo_t CarriConfig;
    L1CellConfigInfo_t CellConfig;
    L1SsbConfigInfo_t SSBConfig;
    L1PrachConfigInfo_t PRACHCfgInfo;
    L1TddTableConfigInfo_t TDDtableInfo;
    L1MeasurementConfigInfo_t MeasurementCfgInfo;
}L1ConfigRequest_t;


/**@brief Slot Ctrl Pdu Info*/
typedef struct
{
    uint8_t TxRxInfo[MAX_NUM_OF_SLOTS_INFO_PRE_CTRL_MSG];/*0:Tx 1:Rx 2:S 特殊Slot 特殊slot的配置参照NR小区配置*/
    uint16_t toRRUMsgLength;/*send to RRU msg len*/
    uint16_t rev;
    uint16_t toRRUMsg[MAX_LENGTH_OF_RRU_MSG_PRE_CTRL_MSG];/*RRU msg Payload*/
}L1SlotCtrlPduInfo_t;

/**@brief CTRL PDU*/
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1SlotCtrlPduInfo_t SlotCtrlPdu;
}L1CtrlPduInfo_t;

/**@brief UE*/
typedef struct
{
    uint8_t PduIdx;
    uint8_t rev0;
    uint16_t rev1;
}L1GroupUeInfo_t;


/**@brief group*/
typedef struct
{
    uint8_t nUe;
    uint8_t rev0;
    uint16_t rev1;
    /**variable-size by nUe*/
    L1GroupUeInfo_t Ues[MAX_NUM_DL_GROUP_UE];/* Max size: MAX_NUM_DL_GROUP_UE*/
}L1DlGroupInfo_t;


/**@brief BWP*/
typedef struct
{
    uint16_t BWPSize;
    uint16_t BWPStart;
}L1BwpInfo_t;


/**@brief Tx Power info*/
typedef struct
{
    int16_t pdcchDmrsPowerOffsetProfileSSS;
    int16_t pdcchDataPowerOffsetProfileSSS;
}L1PdcchTxPowerInfo_t;

/**@brief Beam info*/
typedef struct
{
    uint16_t digBFIterface;//Logical Ant Ports
    uint16_t rev0;
    uint16_t beamIdx[4];//MAX_DL_ANT_PORTS=4
}L1BeamInfo_t;

/**@brief DL DCI PDU*/
typedef struct
{
    uint16_t RNTI;
    uint16_t nIdPdcchData;

    uint16_t nRntiPdcchData;
    uint16_t nIdPdcchDmrs;

    uint8_t AggregationLevel;
    uint8_t SubbandStart;
    uint16_t pcid;

    uint16_t SubbandLength;
    uint16_t PayloadSizeBits;
    //L1BeamInfo_t BeamformingInfo;
    L1PdcchTxPowerInfo_t TxPowerInfo;
    uint8_t Payload[NUM_DL_DCI_PAYLOAD];
}L1DlDciInfo_t;


/**@brief PDSCH DMRS*/
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
}L1PdschDmrsInfo_t;


/**@brief Pdsch Allocation in frequency domain.*/
typedef struct
{
    uint8_t rbgStart;
    uint8_t rbgSize;
}L1PxschRbg_t;


typedef struct
{
    uint16_t rbgNum;
    uint16_t rev;
    //L1PxschRbg_t rbg[80];
    uint8_t rbg[80 * 2];
}L1PxschAllocationFdInfo_t;


/**@brief Resource Allocation in time domain*/
typedef struct
{
    uint8_t SymbolBitmap[4];
}L1PxschAllocationTdInfo_t;

/**@brief PDSCH Tx Power*/
typedef struct
{
    int16_t pdschDmrsPowerOffsetProfileSSS;
    int16_t pdschDataPowerOffsetProfileSSS;
}L1TxPowerInfo_t;


/**@brief CSI Tx Power*/
typedef struct
{
    int16_t csiRsPowerOffsetProfileSSS;
    uint16_t rev;
}L1CsiTxPowerInfo_t;


typedef struct
{
    L1DlDciInfo_t DlDCIInfos;

    uint16_t DciSubbandBitmap[10];
}L1DlDci;

/**@brief PDCCH PDU*/
typedef struct
{
    uint16_t pdcchPduIndex;
    uint16_t numDlDci;
    /**variable-size by numDlDci*/
    L1DlDci DlDCIs[MAX_NUM_PDCCH_DlDCI];/* Max size: MAX_NUM_PDCCH_DlDCI*/
}L1PdcchPduInfo_t;

/**@brief Rate Matching references*/
typedef struct
{
    uint8_t numCsiRsForRM;
    uint8_t rev;
    uint16_t csiRsForRM;
}L1RateMatchingInformation_t;


/**@brief PDSCH PDU*/
typedef struct
{
    uint16_t RNTI;
    uint16_t pduIndex;
    uint16_t BWPSize;
    uint16_t BWPStart;

    //codeword
    uint32_t TBSize;

    uint16_t targetCodeRate;
    uint8_t qamModOrder;
    uint8_t mcsIndex;

    uint8_t mcsTable;
    uint8_t rvIndex;
    uint8_t ldpcBaseGraph;
    uint8_t rev;
    //codeword end

    uint16_t nIdPdsch;
    uint8_t nrOfLayers;
    uint8_t rev1;
    uint16_t PMidx;
    uint16_t rev2;

    //DMRS start
    uint8_t dlDmrsType;
    uint8_t dlDmrsSymbPos;
    uint16_t dlDmrsSubbandPos;

    uint16_t dlDmrsScramblingId;
    uint16_t dmrsPorts;

    uint8_t nSCID;
    uint8_t numDmrsCdmGrpsNoData;
    uint16_t rev3;
    //DMRS end

    L1PxschAllocationFdInfo_t ResourceAllocFd;
    L1RateMatchingInformation_t RateMatchingInformation;
    L1TxPowerInfo_t TxPowerInfo;
}L1PdschPduInfo_t;


/**@brief CSI-RS PDU BWP*/
typedef struct
{
    uint8_t SubcarrierSpacing;
    uint8_t CyclicPrefix;
    uint16_t rev;
}L1CsiBwpInfo_t;


/**@brief CSI-RS PDU*/
typedef struct
{
    uint16_t csiRsPduIndex;
    uint16_t StartRB;

    uint16_t NrOfRBs;
    uint16_t FreqDomain;

    uint16_t ScrambId;
    uint8_t  SymbL0;
    uint8_t  CDMType;
    L1CsiTxPowerInfo_t TxPowerInfo;

    uint16  portNum;
    uint16  cellId;
    uint32_t rbBitmap[5];
}L1CsiRsPduInfo_t;

/**@brief SSB PDU*/
typedef struct
{
    uint8_t  ssbSubbandIndex[MAX_NR_M_IN_ZONE];

    uint32_t freqDomainBitMap[MAX_NR_M_IN_ZONE];

    uint8_t  bchPayloadMajor[MAX_NR_M_IN_ZONE][5]; /* 接口再确定一下 */

    uint8_t  bchPayload[21];
    uint8_t rev0;
    uint16_t rev1;
    L1BeamInfo_t BeamformingInfo;
}L1SsbPduInfo_t;


typedef struct
{
    /**This is included if indicated presence by the PDUType*/
    L1PdcchPduInfo_t PdcchPdu[1];
    /**This is included if indicated presence by the PDUType*/
    L1PdschPduInfo_t PdschPdu[1];
    /**This is included if indicated presence by the PDUType*/
    L1CsiRsPduInfo_t CsiRsPdu[1];
    /**This is included if indicated presence by the PDUType*/
    L1SsbPduInfo_t SsbPdu[1];
}L1DlPduConfiguration_t;


/**@brief DL TTI PDU*/
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1DlPduConfiguration_t DlPDUConfig;
}L1DlPduInfo_t;


/**@brief This message can be sent by the L2/L3 when the PHY is in the RUNNING state.*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;

    uint16_t nPDUs;
    uint8_t nDlTypes;
    uint8_t nGroup;

    uint16_t nPDUsOfEachType[NUM_PDU_EACH_TYPE];
    uint16_t rev;
    /**variable-size by nPDUs*/
    //L1DlPduInfo_t pdus[];/*Max size: MAX_NUM_TXRU*/
    /**variable-size by nGroup*/
    //L1DlGroupInfo_t groups[MAX_NUM_DL_GROUP_PER_SLOT];
}L1DLTTIReq_t;


/**@brief UL DCI PDU*/
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1PdcchPduInfo_t PdcchPduConfig;
}L1UlDciPduCfg_t;


/**@brief UL DCI*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;
    uint16_t numPDUs;
    uint8_t nDlTypes;
    uint8_t rev;
    uint16_t nPDUsOfEachType[NUM_ULDCI_PDU_EACH_TYPE];
    /**variable-size by numPDUs*/
    //L1UlDciPduCfg_t UldciPdu[];/* Max size: MAX_NUM_PDCCH_PDU_FOR_UL_PER_SLOT*/
}L1ULDCI_t;


/**@brief group*/
typedef struct
{
    uint8_t nUe;
    uint8_t rev0;
    uint16_t rev1;
    /**variable-size by nUe*/
    L1GroupUeInfo_t Ues[MAX_NUM_UL_GROUP_UE];/* Max size: MAX_NUM_UL_GROUP_UE*/
}L1UlGroupInfo_t;


/**@brief PUSCH DMRS*/
typedef struct
{
    uint16_t ulDmrsSymbPos;
    uint16_t puschDmrsScramblingId;
    uint16_t puschDmrsIdentity;
    uint16_t dmrsPorts;

    uint8_t dmrsConfigType;
    uint8_t nSCID;
    uint8_t numDmrsCdmGrpsNoData;
    uint8_t rev0;
}L1PuschDmrsInfo_t;

/**@brief Optional puschData information*/
typedef struct
{
    uint32_t TBSize;

    uint16_t numCb;
    uint8_t rvIndex;
    uint8_t harqProcessID;

    uint8_t newData;
    uint8_t rev0;
    uint16_t rev1;
}L1PuschData_t;


/**@brief Optional puschUci information*/
typedef struct
{
    uint16_t harqAckBitLength;
    uint16_t csiPart1BitLength;

    uint8_t  betaOffsetHarqAck;
    uint8_t  rev0;
    uint16_t rev1;
}L1PuschUci_t;


/**@brief Pucch Allocation in frequency domain*/
typedef struct
{
    uint16_t subbandIdex;
    uint16_t rev;
}L1PucchAllocationFdInfo_t;

typedef struct
{
    uint8_t startSymbolIndex;
    uint8_t NrOfSymbols;
    uint16_t rev;
}L1PucchAllocationTdInfo_t;


/**@brief Hopping information*/
/*typedef struct
{
    uint16_t nIdPucchHopping;
    uint16_t InitialCyclicShift;

    uint16_t secondHopPRB;
    uint8_t intraSlotFrequencyHopping;
    uint8_t pucchGroupHopping;
    uint8_t ulBwpId;

    uint8_t rev0;
    uint16_t rev1;
}L1PucchHoppingInfo_t;*/

/**@brief PRACH PDU.*/
typedef struct
{
    uint32_t Handle;

    uint16_t physCellID;
    uint16_t PrachRootSequenceIndex;

    uint16_t numCs;
    uint8_t PrachSubbandIndex[MAX_NR_M_IN_ZONE];

    uint8_t startPreambleIndex;
    uint8_t numPreambleIndices;

    L1BeamInfo_t BeamformingInfo;
}L1PrachPdu_t;


/**@brief PUSCH PDU*/
typedef struct
{
    uint32_t Handle;

    uint16_t pduBitmap;
    uint16_t RNTI;

    uint16_t targetCodeRate;
    uint16_t nIdPusch;

    uint8_t qamModOrder;
    uint8_t mcsIndex;
    uint8_t mcsTable;
    uint8_t nrOfLayers;

    uint8_t ldpcBaseGraph;
    uint8_t rev0;
    uint16_t rev1;

    L1BeamInfo_t BeamformingInfo;
    L1BwpInfo_t BWP;
    L1PuschDmrsInfo_t DMRS;
    L1PxschAllocationFdInfo_t ResourceAllocFd;
    L1PxschAllocationTdInfo_t ResourceAllocTd;
    /**This is included if indicated presence by the pduBitmap*/
    L1PuschData_t puschData;
    /**This is included if indicated presence by the pduBitmap*/
    L1PuschUci_t puschUci;
}L1PuschPduInfo_t;

/**@brief PUCCH PDU*/
typedef struct
{
    uint32_t Handle;

    uint16_t RNTI;
    uint8_t harqBitLen;
    uint8_t cellId;

    uint8_t  srBitLen;
    uint8_t combineUciReport;
    uint8_t Npucch;
    uint8_t Npucch_shift;

    L1BwpInfo_t BWP;
    L1PucchAllocationFdInfo_t ResourceAllocFd;
    L1PucchAllocationTdInfo_t ResourceAllocTd;
    //L1PucchHoppingInfo_t hoppingInfo;
}L1PucchPduInfo_t;


/**@brief SRS PDU*/
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

    uint8_t timeStartPosition;
    uint8_t subbandLength;
    uint8_t srsRootSequenceIndex;
    uint8_t rev;

    uint8_t rbBitmap[4];  //at most 4 RBs per srs
}L1SrsPdu_t;


typedef struct
{
    /**This is included if indicated presence by the PDUType*/
    L1PrachPdu_t PrachPdu[1];
    /**This is included if indicated presence by the PDUType*/
    L1PuschPduInfo_t PushPdu[1];
    /**This is included if indicated presence by the PDUType*/
    L1PucchPduInfo_t PucchPdu[1];
    /**This is included if indicated presence by the PDUType*/
    L1SrsPdu_t SrsPdu[1];
}L1UlPduConfiguration_t;


/**@brief UL TTI PDU*/
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1UlPduConfiguration_t UlPDUConfig;
}L1UlPduInfo_t;


/**@brief The PDUs included in this structure have no ordering requirements*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;
    uint16_t nPDUs;
    uint8_t nUlTypes;
    uint8_t nGroup;
    uint16_t nPDUsOfEachType[NUM_PDU_EACH_TYPE];
    uint16_t rev;
    /**variable-size by nPDUs*/
    //L1UlPduInfo_t pdus[];/* Max size: MAX_NUM_PDU_IN_UL_TTI_REQ*/
    /**variable-size by nGroup*/
    //L1UlGroupInfo_t groups[MAX_NUM_GROUP_IN_UL_TTI_REQ];
}L1ULTTI_t;


/**@brief TLV structure*/
typedef struct
{
    uint16_t Tag;
    uint16_t rev;
    uint32_t Length;
    uint32_t Value;
}L1DataTLV_t;


/**@brief TX DATA PDU*/
typedef struct
{
    uint32_t PDULength;
    uint16_t PDUIndex;
    uint8_t CWIndex;
    uint8_t rev;
    uint32_t numTLV;
    /**variable-size by numTLV*/
    L1DataTLV_t TLVs[MAX_NUM_TXDATA_TLV];/* Max size: MAX_NUM_TXDATA_TLV*/
}L1TxDataPduInfo_t;

/**@brief TX DATA*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;
    uint16_t numPDUs;
    uint16_t rev;
    /**variable-size by numPDUs*/
    L1TxDataPduInfo_t pdus[MAX_NUM_PDSCH_PDU_PER_SLOT];/* Max size: MAX_NUM_PDSCH_PDU_PER_SLOT*/
}L1TXDATAREQ_t;

/**@brief TX DATA*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;
    //char data[];
}L1TXDATA_t;


/**@brief Config response*/
typedef struct
{
    uint8_t ErrorCode;
    uint8_t NumberInvalid;
    uint8_t NumberTLVsIDLE;
    uint8_t NumberTLVsRUNNING;
    uint8_t NumberMissTLVs;
    uint8_t rev0;
    uint16_t rev1;
}L1ConfigResponse_t;


/**@brief Start request*/
typedef struct
{
}L1StartRequest_t;


/**@brief Start response*/
typedef struct
{
    uint8_t ErrorCode;
    uint8_t rev0;
    uint16_t rev1;
}L1StartResponse_t;


/**@brief Stop request*/
typedef struct
{
    uint8_t StopReason;
    uint8_t rev0;
    uint16_t rev1;
}L1StopRequest_t;


/**@brief Stop indication*/
typedef struct
{
    uint8_t ErrorCode;
    uint8_t rev0;
    uint16_t rev1;
}L1StopIndication_t;


/**@brief Error indication*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;

    uint8_t MessageId;
    uint8_t ErrorCode;
    uint8_t NumTLVs;
    uint8_t rev;
    uint16_t ExpectedSFN;
    uint16_t ExpectedSlot;
    /**variable-size by NumTLVs */
    //uint32_t TLV[];/* Max size: 3*/
}L1ErrorIndication_t;


/**@brief Slot indication*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;
    uint32_t sysTime;
}L1SymbolIndication_t;


/**@brief RX DATA*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;
    char data[];
}L1RXDATA_t;

/**@brief Rxdata Indication Pdu*/
typedef struct
{
    uint32_t Handle;
    uint16_t RNTI;
    uint8_t HarqID;
    uint8_t rev;
    uint32_t numTLV;
    /**variable-size by numTLV*/
    //L1DataTLV_t TLVs[];/* Max size: MAX_NUM_TXDATA_TLV*/
}L1RxDataPduInfo_t;


/**@brief Rx data indication*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;

    uint16_t numPDUs;
    uint16_t rev;
    /**variable-size by numPDUs*/
    //L1RxDataPduInfo_t pdus[];/* Max size: MAX_NUM_ULSCH_PDU_IN_RX_DATA_INDICATION*/
}L1RxdataIndication_t;


/**@brief CRC Info*/
typedef struct
{
    uint32_t Handle;
    uint16_t RNTI;
    uint8_t HarqID;
    uint8_t TbCrcStatus;
    uint32_t TA;
    uint16_t RSSI;
    uint8_t RSRP;
    uint8_t SINR;
}L1CrcInfo_t;


/**@brief CRC indication*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;
    uint16_t numCRCs;
    uint16_t rev;
    /**variable-size by numCRCs*/
    //L1CrcInfo_t CRCs[];/* Max size: MAX_NUM_ULSCH_CRC_IN_CRC_INDICATION*/
}L1CrcIndication_t;


/**@brief UCI INFO pdu*/
typedef struct
{
    uint16_t CsiBitLen;
    uint8_t CsiCrc;
    uint8_t rev;
    /**variable-size by UciBitLen*/
    uint8_t uciPayload[216];/* Max size: 64*/
}L1CsiInfo_t;


/**@brief SR PDU FMT01*/
typedef struct
{
    uint8_t SRindication;
    uint8_t SRconfidenceLevel;
    uint16_t rev;
}L1SrPdu_t;


/**@brief Hard pdu for fmt01*/
typedef struct
{
    uint16_t HarqBitLen;
    uint8_t HarqValue;
    uint8_t rev;
}L1HarqPduForPusch;

/**@brief Hard pdu for fmt01*/
typedef struct
{
    uint8_t NumHarq;
    uint8_t HarqconfidenceLevel;
    uint8_t HarqValue;
    uint8_t rev;
}L1HarqPduForPucch;


/**@brief UCI inpusch pdu*/
typedef struct
{
    uint32_t Handle;

    uint16_t RNTI;
    uint16_t TA;

    uint16_t RSSI;
    uint8_t SINR;
    //uint8_t UlSinrMetric;
    uint8_t RSRP;

    uint8_t pduBitmap;
    uint8_t rev0;
    uint16_t rev1;
    /**This is included if indicated presence by the pduBitmap*/
    L1HarqPduForPusch HARQInfo;
    L1CsiInfo_t    CsiInfo;
}L1UciInPuschPdu_t;


/**@brief UCI Inpucch Pdu Fmt01*/
typedef struct
{
    uint32_t Handle;
    uint16_t RNTI;
    uint16_t TA;
    uint16_t RSSI;
    uint8_t SINR;
    uint8_t RSRP;

    uint8_t pduBitmap;
    uint8_t rev0; //PucchFormat;
    uint16_t rev1;
    /**This is included if indicated presence by the pduBitmap*/
    L1SrPdu_t SrInfo;
    /**This is included if indicated presence by the pduBitmap*/
    L1HarqPduForPucch HARQInfo;
}L1UciInPucchPduFmt01_t;


typedef struct
{
    /**This is included if indicated presence by the PDUType*/
    L1UciInPuschPdu_t uciInPuschPdu[1];
    /**This is included if indicated presence by the PDUType*/
    L1UciInPucchPduFmt01_t uciInPucchPduFmt01[1];
}L1UciPduInfo_t;


/**@brief UCI Info*/
typedef struct
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1UciPduInfo_t Pdu;
}L1UciInfo_t;


/**@brief UCI indication*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;

    uint16_t numUcis;
    uint16_t rev;
    /**variable-size by numUcis*/
    //L1UciInfo_t pdus[];/* Max size: MAX_UCI_NUM_IN_UCI_IND*/
}L1UciIndication_t;


/**@brief For each resource block*/
typedef struct
{
    uint8_t rbSINR;
    uint8_t rbRSRP;
    uint16_t rev;
}L1RbsBlock_t;


/**@brief SRS Symbol*/
typedef struct
{
    uint16_t numRBs;
    uint16_t rev;
    //L1RbsBlock_t rbSINR[];/* Max size: MAX_NUM_SRS_PRB*/
}L1SrsSymbolInfo_t;


/**@brief Srs Pdu*/
typedef struct
{
    uint32_t Handle;
    uint16_t RNTI;
    uint16_t TA;

    uint8_t wideBandSINR;
    uint8_t doubleLayerWideBandSINR;
    uint16_t Rev;

    /**variable-size by numSymbols*/
    //L1SrsSymbolInfo_t symbolInfo[];/* Max size: MAX_NUM_RPT_SRS_SYMBOL*/
}L1SrsPduInfo_t;


/**@brief SRS indication*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;

    uint8_t numPDUs;
    uint8_t rev0;
    uint16_t rev1;
    /**variable-size by numPDUs*/
    //L1SrsPduInfo_t pdus[];/* Max size: MAX_NUM_SRS_PDU_PER_SLOT*/
}L1SrsIndication_t;


/**@brief Preamble*/
typedef struct
{
    uint32_t PreamblePwr;
    uint16_t TA;
    uint8_t preambleSinr;
    uint8_t preambleIndex;
}L1PreambleInfo_t;


/**@brief Rach Pdu*/
typedef struct
{
    uint16_t handle;
    uint16_t avgRssi;
    uint8_t avgSinr;
    uint8_t SlotIndex;
    uint8_t raIndex;
    uint8_t numPreambles;

    /**variable-size by numPreamble*/
    //L1PreambleInfo_t preamble[];/* Max size: MAX_NUM_PREAMBLE_PER_PRACH_PDU_RPT*/
}L1RachPduInfo_t;


/**@brief Rach Indication*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;

    uint8_t numPDUs;
    uint8_t rev0;
    uint16_t rev1;
    /**variable-size by numPDUs*/
    //L1RachPduInfo_t pdus[];/* Max size: MAX_NUM_PRACH_PDU_IN_PRACH_INDICATION*/
}L1RachIndication_t;


/**@brief Slot Ni Indication*/
typedef struct
{
    uint16_t SFN;
    uint8_t Slot;
    uint8_t Symbol;
    uint8_t SubbandInN[MAX_NR_SUBBAND_IN_DOWNZONE]; //
    uint8_t rev;
}L1SlotRbNiIndication_t;

#endif // NRPHYAPI_H
