#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include "r_adpcm.h"
/**************************************************************************************
Common Macro Definitions
**************************************************************************************/
#define NO_SELECT       (0x00)
#define SELECT_ENCODE   (0x01)
#define SELECT_DECODE   (0x02)

/**************************************************************************************
Decode Macro Definitions
**************************************************************************************/
#define PCMDECSIZE      4         /* number to convert from ADPCM into PCM */

/* size of decoded sound data buffer
(Please make it a numerical integer double in order to convert from ADPCM into PCM) */
#define PCMBUFSIZE      (PCMDECSIZE*10)

#define PWM_SAMPLING    (0x00000140UL)

/* Output Mode */
#define SOUND_NONE      0
#define SOUND_PWM       1
#define SOUND_DA        2

/**************************************************************************************
Encode Macro Definitions
**************************************************************************************/
#define SAMPLE_CNT  (4u)                /*    No. of input samples passed for ADPCM conversion at a time     */
#define MAX_DATA_LENGTH (1500u)             /*    Max. size of ADPCM encoded data                                 */
#define ADPCM_DATA_CNT  (2u)                /*    No. of ADPCM samples received after ADPCM conversion         */


#define TRUE            (1)
#define FALSE           (0)
/******************************************************************************
Typedef definitions
******************************************************************************/
typedef enum
{
    PLAY_NONE       = 0,             /* no sound data output */
    PLAY_PLAYBACK,                   /* during sound data output */
    PLAY_END                         /* end of sound data output */
} PLAYMODE;

typedef struct                       /* decoded information structure */
{
    adpcm_env *adpcm;                /* ADPCM decoding structure */
     uint8_t  *inputaddr;            /* input adpcm address */
    int16_t   pcm_data[PCMDECSIZE];  /* decoded sound data(16bit) storage */
    volatile  PLAYMODE playmode;     /* state of playback */
    uint32_t  decno;                 /* number of sound data(decoded) */
    uint32_t  playno;                /* number of sound data(completed output) */
} DECINFO;

typedef struct                       /* ring buffer structure */
{
    uint16_t buff[PCMBUFSIZE];       /* 16bit PCM data storage */
    uint16_t *w_pos;                 /* write address of ring buffer */
    uint16_t *r_pos;                 /* read address of ring buffer */
    volatile uint16_t  empty;        /* writable size of ring buffer */
} RINGBUFFER;

/******************************************************************************
Imported global variables and functions (from other files)
******************************************************************************/
extern DECINFO    g_dec_info0;                        /* decoded information structure                            */
extern RINGBUFFER g_rbf0;                             /* ring buffer structure                                    */
extern adpcm_env  g_st_adpcm0;                        /* ADPCM decoding structure                                 */
extern uint8_t    g_ucSoundMode;                      /* Output mode */
extern uint32_t   g_readErrCntCH1;                    /* Output Error Counter                                     */
//extern int16_t    g_InputData[SAMPLE_CNT];            /* Input data storage buffer                                */
extern uint8_t    g_EncodedData[MAX_DATA_LENGTH];     /* ADPCM Encoded data storage buffer                        */
extern uint8_t    g_EncodedDataTemp[ADPCM_DATA_CNT];  /* Temporary data storage buffer                            */
extern uint32_t   g_EncodedDataLength;                /* Size of ADPCM encoded data buffer                        */
extern uint8_t    g_ConversionOver;                   /* Flag to indicate whether ADPCM data buffer is full       */
extern uint8_t    g_bADPCMEn;                         /* Flag to indicate whether ADPCM conversion is enabled     */
extern uint8_t    g_ad_select;                        /* encode or decode mode set  */


void     R_InitDecInfo(DECINFO  *info, adpcm_env  *adpcm,const uint32_t *addr, int32_t decsize);
void     R_InitRingBuffer(RINGBUFFER  *rbf);
void     R_DecodeProc(DECINFO  *info, RINGBUFFER  *rbf);
void     R_RingBufferSetData(DECINFO  *info, RINGBUFFER  *rbf, uint16_t lsize);
void     R_RingBufferPush(int16_t  *src, uint16_t  *dest, int32_t times);
void     R_SetPCMdata(void);
uint8_t  R_Convert16to8(int16_t data);
uint16_t R_Convert16to10(int16_t data);
uint16_t R_Convert16toPWM(int16_t data);
int8_t   R_decode_start(uint8_t *filename, uint8_t rate);
//extern void R_decode_main(void);
void     R_decode_stop(void);
int8_t   R_encode_main(void);
int8_t   R_encode_start(void);
int8_t   R_encode_start2(void);
int8_t   R_encode_stop(void);
void     R_StartSelect(void);
void     R_convert_to_ADPCM(void);

void     R_interrupt_encode_ad_convert(void);
void     R_interrupt_encode_timer(void);
void     R_interrupt_decode_timer(void);


#define SOUND_MODULE_INIT      decode_pwm_init
#define SOUND_MODULE_START     decode_pwm_start
#define SOUND_MODULE_STOP      decode_pwm_stop
#define SOUND_MODULE_SLEEP     decode_pwm_sleep
#define SOUND_OUTPUT_DATA_SET(value)  (GTCCRA  = value)
#define SOUND_OUTPUT_DATA_CNV  R_Convert16toPWM
#define SOUND_OUTPUT_MODULE  SOUND_PWM



#endif /* _SAMPLE_H_ */
