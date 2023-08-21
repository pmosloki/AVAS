#include "r_adpcm.h"
#include "sample.h"
#include "r_gpt.h"
#include "r_gpt_cfg.h"
#include "hal_data.h"
//#include "commands.h"
//#include "commands.h"

/******************************************************************************
 Exported global variables and functions (to be accessed by other files)
 ******************************************************************************/
DECINFO g_dec_info0; /* decoded information structure */
RINGBUFFER g_rbf0; /* ring buffer structure */
adpcm_env g_st_adpcm0; /* ADPCM decoding structure */
uint8_t g_ucSoundMode; /* Output mode */
uint32_t g_readErrCntCH1; /* Output Error Counter */

//volatile unsigned long ADPCM_ADDR1 = 0x1000;            /* top address of ADPCM sound data storage */
//volatile unsigned long PCM_DATA_SIZE1 = 0x00;       //0x9380;       // 0x252CA;         /* size of sound data after decode(compressed data) */

//unsigned int adpcm_stepsizeTable[] = {
//
//    5,    6,    7,    8,    9,   10,   11,   12,   14,   15,
//    17,   18,   20,   22,   25,   27,   30,   33,   37,   40,
//    44,   49,   54,   59,   65,   72,   79,   87,   95,  105,
//    116,  127,  140,  154,  170,  187,  205,  226,  248,  273,
//    301,  331,  364,  400,  440,  485,  533,  586,  645,  710,
//    781,  859,  945, 1039, 1143, 1258, 1384, 1522, 1674, 1842,
//    2026, 2228, 2451, 2697, 2966, 3263, 3589, 3948, 4343, 4777,
//    5255, 5781, 6359, 6995, 7694, 8464, 9310,10242,11266,12392,
//    13632,14995,16494,18144,19958,21954,24150,26565
//
//};
//
//unsigned char adpcm_idxT4[] = {
//
//    0xff, 0xff, 0xff, 0xff, 2, 4, 6, 8,
//    0xff, 0xff, 0xff, 0xff, 2, 4, 6, 8
//
//};

void Func2(void);

_Bool NEAR_FLAG_ACCESS_FLAG;

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_InitDecInfo
 * Include       : r_s2_driver.h
 * Declaration   : void R_InitDecInfo( DECINFO *info, adpcm_env *adpcm, const uint8_t *addr, int32_t decsize )
 * Description   : decoded information structure(DECINFO) initialization.
 * Arguments     : DECINFO       *info        ; decoded information structure
 *               : adpcm_env     *adpcm       ; ADPCM decoding structure
 *               : const uint8_t *addr        ; top address of ADPCM sound data
 *               : int32_t       decsize      ; number to convert from ADPCM into PCM
 * Return value  : none
 *""FUNC COMMENT END""*****************************************************************/
unsigned long rcvd_address = 0;
void R_InitDecInfo(DECINFO *info, adpcm_env *adpcm, const uint32_t *addr, int32_t decsize)
{

//    rcvd_address = (uint32_t *)addr;
//    if(rcvd_address >= 0x10000){
//      ES01();
//    }else{
//      ES00();
//    }
    info->adpcm = adpcm;
    info->playmode = PLAY_NONE;
    info->decno = 0;
    info->playno = 0;
    info->inputaddr = (uint8_t*) addr;
    /* initialization and the initial setting of ADPCM decoding structure */
//    R_adpcm_initDec (info->adpcm);

}

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_InitRingBuffer
 * Include       : r_s2_driver.h
 * Declaration   : void R_InitRingBuffer( RINGBUFFER *rbf )
 * Description   : Initializes setting of the ring buffer to store decoded data.
 * Arguments     : RINGBUFFER *rbf       ; ring buffer structure
 * Return value  : none
 *""FUNC COMMENT END""*****************************************************************/
void R_InitRingBuffer(RINGBUFFER *rbf)
{
    rbf->w_pos = &rbf->buff[0];
    rbf->r_pos = &rbf->buff[0];
    rbf->empty = PCMBUFSIZE - PCMDECSIZE;
}

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_DecodeProc
 * Include       : r_s2_driver.h
 * Declaration   : void R_DecodeProc( DECINFO *info, RINGBUFFER *rbf )
 * Description   : Converts ADPCM data into PCM data and stores decoded data
 *               : in a ring buffer.
 * Arguments     : DECINFO *info       ; decoded information structure
 *               : RINGBUFFER *rbf     : ring buffer structure
 * Return value  : none
 *""FUNC COMMENT END""*****************************************************************/
void R_DecodeProc(DECINFO *info, RINGBUFFER *rbf)
{
    if (rbf->empty >= PCMDECSIZE)
    {
        /* decode for sound data size */
//        R_adpcm_refreshDec (info->inputaddr, info->pcm_data, info->adpcm); // used in asm

        if (NEAR_FLAG_ACCESS_FLAG == FALSE)
//            R_adpcm_decode (4, info->adpcm);
//        else
//            R_adpcm_decode_64 (4, info->adpcm);

        info->inputaddr = info->inputaddr + 2; // (PCMDECSIZE / 2);    // used asm
        if (info->inputaddr > 65536)
        {
            NEAR_FLAG_ACCESS_FLAG = FALSE;

        }
        else
        {

            NEAR_FLAG_ACCESS_FLAG = TRUE;
//            ES01 ();
        }
        R_RingBufferSetData (info, rbf, PCMDECSIZE);

    }
}

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_RingBufferSetData
 * Include       : r_s2_driver.h
 * Declaration   : void R_RingBufferSetData( DECINFO *info, RINGBUFFER *rbf ,uint16_t size)
 * Description   : Check state of the ring buffer before writing data.
 * Arguments     : DECINFO *info       ; decoded information structure
 *               : RINGBUFFER *rbf     : ring buffer structure
 *               : uint16_t size       : ring buffer set size (Unit: 2byte)
 * Return value  : none
 *""FUNC COMMENT END""*****************************************************************/

void R_RingBufferSetData(DECINFO *info, RINGBUFFER *rbf, uint16_t size)
{
    uint8_t push = 0;
    uint16_t lsize;
    uint16_t work;

    work = &rbf->buff[PCMBUFSIZE] - rbf->w_pos;
    lsize = size >> 1; /* size/2 */

    if (rbf->r_pos < rbf->w_pos)
    {
        if (rbf->w_pos + size < &rbf->buff[PCMBUFSIZE])
        {
            /*                              w                 */
            /*               r              [============]    */
            /* --------------+--------------+---------------- */
            /* space available between write position and end of buffer */
            push = 1;
        }
        else if (size < (&rbf->buff[PCMBUFSIZE] - rbf->w_pos) + (rbf->r_pos - &rbf->buff[0]))
        {
            /*                                       w        */
            /* =====]        r                       [======= */
            /* --------------+-----------------------+------- */
            /* write position is at end of buffer, space available at top */
            push = 2;
        }
    }
    else if (rbf->r_pos > rbf->w_pos)
    {
        if ((rbf->w_pos + size) < rbf->r_pos)
        {
            /*               w                                */
            /*               [============] r                 */
            /* --------------+--------------+---------------- */
            /* space available between write position and read position */
            push = 3;
        }
    }
    else
    {
        if (rbf->empty > size)
        {
            if ((rbf->w_pos + size) < &rbf->buff[PCMBUFSIZE])
            {
                /*               r                                */
                /*               w                                */
                /*               [============]                   */
                /* --------------+------------------------------- */
                /* space available between write position and end of buffer */

                push = 4;
            }
            else
            {
                /*                                        r       */
                /*                                        w       */
                /* ======]                                [====== */
                /* ---------------------------------------+------ */
                /* write position is at end of buffer, space available at top */
                push = 5;
            }
        }
    }

    if (push)
    {
        if ((1 == push) || (3 == push) || (4 == push))
        {
            R_RingBufferPush (info->pcm_data, rbf->w_pos, size);
            rbf->w_pos += size;
            rbf->empty -= size;
            info->decno += size;
            if (rbf->w_pos >= &rbf->buff[PCMBUFSIZE])
            {
                rbf->w_pos = &rbf->buff[0];
            }
        }
        else
        {
            work = (&rbf->buff[PCMBUFSIZE] - rbf->w_pos);
            R_RingBufferPush (info->pcm_data, rbf->w_pos, work);
            rbf->w_pos = &rbf->buff[0];
            R_RingBufferPush (info->pcm_data + work, rbf->w_pos, (size - work));
            rbf->w_pos = rbf->w_pos + (size - work);
            rbf->empty -= size;
            info->decno += size;
        }
    }
}

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_RingBufferPush
 * Include       : r_s2_driver.h
 * Declaration   : void R_RingBufferPush( int16_t *src, uint16_t *dest, int32_t times )
 * Description   : Convert data length.Push data to ring buffer.
 * Arguments     : int16_t  *src   ; source address
 *               : uint16_t *dest  ; destination address
 *               : int32_
 *""FUNC COMMENT END""***t  times  ; number of data items
 * Return value  : none**************************************************************/
void R_RingBufferPush(int16_t *src, uint16_t *dest, int32_t times)
{
    int32_t i;

    for (i = 0; i < times; i++)
    {
        *dest++ = SOUND_OUTPUT_DATA_CNV (*src++);
    }

}

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_Convert16toPWM
 * Include       : r_s2_driver.h
 * Declaration   : uint16_t R_Convert16toPWM( int16_t data )
 * Description   : Convert PCM data(16bits) into output PWM data(16bits).
 * Arguments     : int16_t  data   ; PCM data(16bits)
 * Return value  : uint16_t        ; output PWM data(16bits)
 *""FUNC COMMENT END""*****************************************************************/
uint16_t R_Convert16toPWM(int16_t data)
{
    return (uint16_t) (((int32_t) (data + 32768) * PWM_SAMPLING) >> 16);
}

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_Convert16to10
 * Include       : r_sample.h
 * Declaration   : uint16_t R_Convert16to10( int16_t data )
 * Description   : Convert PCM data(16bits) into  D/A output data(10bits).
 * Arguments     : int16_t  data   ; PCM data(16bits)
 * Return value  : uint16_t        ; D/A output data(10bits)
 *""FUNC COMMENT END""*****************************************************************/
uint16_t R_Convert16to10(int16_t data)
{
    return (uint16_t) (((data + 0x20) >> 6) + 512);
}

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_Convert16to8
 * Include       : r_sample.h
 * Declaration   : uint8_t R_Convert16to8( int16_t data )
 * Description   : Convert PCM data(16bits) into  D/A output data(10bits).
 * Arguments     : int16_t  data   ; PCM data(16bits)
 * Return value  : uint8_t        ; D/A output data(8bits)
 *""FUNC COMMENT END""*****************************************************************/
uint8_t R_Convert16to8(int16_t data)
{
    return (uint8_t) (((data + 0x80) >> 8) + 128);
}

/*""FUNC COMMENT""*********************************************************************
 * Function Name : R_SetPCMdata
 * Include       : r_s2_driver.h
 * Declaration   : void R_SetPCMdata( void )
 * Description   : read sound data(PCM) from ring buffer.
 *               : send sound data(PCM) to DA/PWM output.
 * Arguments     : none
 * Return value  : none
 *""FUNC COMMENT END""*****************************************************************/
void R_SetPCMdata(void)
{
    uint8_t pop = 0; /* 0 : no output */ // used in asm

    if (g_rbf0.empty < PCMBUFSIZE)
    {
        /* send sound data(PCM) to DA output every sampling period */
        if (g_rbf0.r_pos < g_rbf0.w_pos)
        {
            pop = 1;
        }
        else if (g_rbf0.r_pos > g_rbf0.w_pos)
        {
            /* read position is not at end of buffer */
            pop = 2;
        }
        else if (g_rbf0.empty == 0)
        {
            /* read position is not at end of buffer */
            pop = 3;
        }
        else
        {
            /* no data in buffer(read position == write position) */
            g_readErrCntCH1++;
        }

        if (pop)
        {
            /* set PCM data to PWM data reg. */
         //  SOUND_OUTPUT_DATA_SET(g_rbf0.r_pos);
            R_GPT_PeriodSet(&g_timer1_ctrl,*g_rbf0.r_pos);
//            uint32_t GTCCRA;
//            GTCCRA = g_rbf0.r_pos;
            g_rbf0.r_pos++;
            if (g_rbf0.r_pos >= &g_rbf0.buff[PCMBUFSIZE])
            {
                g_rbf0.r_pos = &g_rbf0.buff[0];
            }
            g_rbf0.empty++;
            g_dec_info0.playno++;
        }
    }
}

///*""FUNC COMMENT""*********************************************************************
//* Function Name : R_interrupt_decode_timer
//* Include       : r_s2_driver.h
//* Declaration   : void R_interrupt_decode_timer(void)
//* Description   : Timer interrupt function for decoder.
//* Arguments     : none
//* Return value  : none
//*""FUNC COMMENT END""*****************************************************************/
//void R_interrupt_decode_timer(void)
//{
//    if (g_dec_info0.playno >= PCM_DATA_SIZE1)
//    {
//        /* Audio output is completed */
//        g_dec_info0.playmode = PLAY_END;
//    R_TAU0_Channel0_Stop();
//    R_TAU0_Channel2_Stop();
//    }
//    else
//    {
//        /* PCM data(decoded data) --> DA/PWM output */
//        R_SetPCMdata();
//    }
//}
//
//
//
//#pragma inline_asm Func2
//void Func2(void)
//{
//        mov     ES, #01             ;RC
//}
