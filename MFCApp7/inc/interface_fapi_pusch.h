/*
 * @file interface_fapi_pusch.h
 * @brief phy内部定义
 */
#pragma once
#include <stdint.h>

// 自定义头文件
#include "pub_l2_l1_interface.h"
#define MAX_UENUM_IN_SLOT (14)

//LOG解析自定义宏
#define FAPI_INFO_LEN       (0x1000)
#define TIME_DATA_LEN       (0x300000)
#define FREQ_DATA_LEN       (0x30000)
#define FREQ_SCALE_LEN      (0x100)
#define CRC_IND_LEN         (0x100)

#define FAPI_INFO_OFFSET      (0)
#define TIME_DATA_OFFSET      FAPI_INFO_OFFSET + FAPI_INFO_LEN
#define FREQ_DATA_OFFSET      TIME_DATA_OFFSET + TIME_DATA_LEN
#define FREQ_SCALE_OFFSET     FREQ_DATA_OFFSET + FREQ_DATA_LEN
#define CRC_IND_OFFSET        FREQ_SCALE_OFFSET + FREQ_SCALE_LEN

//时频域数大小
#define MAX_ANTE_NUM        (4)
#define SLOT2_MAX_SYMB_NUM  (6)
#define SLOT3_MAX_SYMB_NUM  (5)
#define TIME3X              (3)
#define SAMPLE_PER_SYMB     (8192+1280)
#define MAX_RE_NUM          (1600)

#define SLOT2_TIME_61D44_LEN \
MAX_ANTE_NUM * \
SLOT2_MAX_SYMB_NUM * \
SAMPLE_PER_SYMB * 3 * 4

#define SLOT3_TIME_61D44_LEN \
MAX_ANTE_NUM * \
SLOT3_MAX_SYMB_NUM * \
SAMPLE_PER_SYMB * 3 * 4

#define SLOT2_FREQ_DATA_LEN  \
MAX_ANTE_NUM * \
SLOT2_MAX_SYMB_NUM * \
MAX_RE_NUM * 4

#define SLOT3_FREQ_DATA_LEN  \
MAX_ANTE_NUM * \
SLOT3_MAX_SYMB_NUM * \
MAX_RE_NUM * 4

#define SLOT2_FREQ_SCALE_LEN  MAX_ANTE_NUM * SLOT2_MAX_SYMB_NUM * 4
#define SLOT3_FREQ_SCALE_LEN  MAX_ANTE_NUM * SLOT3_MAX_SYMB_NUM * 4

#define CRC_IND_LEN MAX_UENUM_IN_SLOT


typedef struct tr_s
{
    uint16_t PDUType;
    uint16_t PDUSize;
    L1PuschPduInfo_t pdu;
} PuschPduInfo_t;

typedef struct
{
    uint16_t sfn;
    uint16_t slot;

    uint32_t d_length;

    uint32_t pdu_num;
    uint32_t pdu_len[MAX_UENUM_IN_SLOT];
    PuschPduInfo_t pusch[MAX_UENUM_IN_SLOT];
} L1FapiToPuschInterFace_t;

typedef struct 
{
    uint32_t sync_flag:9;
    uint32_t msg_level:3;
    uint32_t msg_type:12;
    uint32_t slot:8;    

    uint32_t sfn:10;
    uint32_t slot_offset:10;
    uint32_t msg_len:9;
    uint32_t msgNo:3;

    //char buffer[];
}log_msg_header_t;

typedef struct 
{
    /* data */
    //char dd_header[12];
    log_msg_header_t log_msg_header;
    PuschPduInfo_t pusch_pdu_info;
} Pusch_fapi_log_t;


typedef struct
{
    //----------------------------------
    //BIT级相关参数:前9word输出log
    //----------------------------------
    uint8_t     crc_type;
    uint8_t     mcb_num;
    uint16_t    mzc;

    uint16_t    mcb_k;
    uint16_t    mcb_kinit;

    uint16_t    nulllen;
    uint16_t    mcb_seg_bit;

    uint16_t    mencode_n;
    uint16_t    nullpos;

    uint32_t    mrm_er[2];
    uint16_t    mrm_k0;
    uint16_t    mrm_n_cb;

    uint32_t    mscram_c_init;
    uint32_t    mscram_m_bit;
    uint32_t    mtb_bitsize;
    uint32_t    mtb_crc_len;
    uint32_t    mrm_g;
    uint32_t    mhbg_matrix_ddraddr;
    uint32_t    mhbg_matrix_lenth;

    uint16_t    polar_K;
    uint16_t    polar_E;

    uint16_t    polar_N;
    uint8_t     encode_type;
    uint8_t     data_symb_num;

    //-----------------------------------
    //符号级相关参数
    //-----------------------------------
    /*DMRS:前8word输出log*/
    uint8_t     dmrs_symb_num;//DMRS符号数目，最大4symbol
    uint8_t     rev2;
    uint8_t     dmrs_symb_pos[2];
    uint8_t     dmrs_port_index[4];

    uint32_t    data_re_allnum;

	uint16_t    data_re_num_datasym[80];
    uint16_t    data_re_start_dataSym[80];
    uint16_t    data_re_start_dmrsSym[80 * 159];
    uint16_t    dmrs_re_start[80 * 159];
} pdschparacfg_t;

