
#include "r_gpt.h"
#include "commands.h"
#include "r_adpcm.h"
#include "sample.h"
#include "hal_data.h"
//#include "hal_data.h"
//
unsigned long word_count[30][2] = {

    {ADDR_ONE,0x1134},{ADDR_TWO,0x1240},{ADDR_THREE,0x12A8},{ADDR_FOUR,0x1070},
    {ADDR_FIVE,0x13F0},{ADDR_SIX,0xE14},{ADDR_SEVEN,0x1524},{ADDR_EIGHT,0x1458},
    {ADDR_NINE,0x15B8},{ADDR_TEN,0x1634},{ADDR_ELEVEN,0x1B30},{ADDR_TWELVE,0x14D4},
    {ADDR_THIRTEEN,0x2014},{ADDR_FOURTEEN,0x2120},{ADDR_FIFTEEN,0x2120},{ADDR_SIXTEEN,0x2090},
    {ADDR_SEVENTEEN,0x2480},{ADDR_EIGHTEEN,0x2120},{ADDR_NINETEEN,0x2444},{ADDR_TWENTY,0x16C0},
    {ADDR_THIRTY,0x11C0},{ADDR_FOURTY,0x1498},{ADDR_FIFTY,0x1630},{ADDR_SIXTY,0x1918},
    {ADDR_SEVENTY,0x1904},{ADDR_EIGHTY,0x1128},{ADDR_NINETY,0x161C},{ADDR_HUNDREAD,0x189C},
    {ADDR_THOUSAND,0x1790}
};
uint16_t delay;

unsigned long APCM_DATA_SIZE;
extern unsigned long PCM_DATA_SIZE1;
unsigned long PCM_DATA_SIZE1;
extern unsigned long ADPCM_ADDR1;
extern unsigned long voice_command;
void Func1(void);
void Delay_Ms(void);
void Speaker_output(void);
//void ES00(void);
//void ES01(void);
//extern void R_decode_main(void);
void R_decode_main(void)
{
    /* decode initialization(4bytes each) */
//  Func1();
   // ES00();
    PCM_DATA_SIZE1 = 0;
//  voice_command = NINTEEN;
    switch(voice_command)
    {

case ONE:
       // ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0,(const uint8_t *)word_count[0][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[0][1];
        Speaker_output();

        voice_command = TWO;
        break;
case TWO:
       // ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[1][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[1][1];
        Speaker_output();

        voice_command = THREE;
        break;
case THREE:
       // ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[2][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[2][1];
        Speaker_output();

        voice_command = FOUR;
        break;
case FOUR:
       // ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[3][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[3][1];
        Speaker_output();

        voice_command = FIVE;
        break;
case FIVE:
       // ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[4][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[4][1];
        Speaker_output();

        voice_command = SIX;
        break;
case SIX:
       // ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[5][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[5][1];
        Speaker_output();

        voice_command = SEVEN;
        break;
case SEVEN:
      //  ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[6][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[6][1];
        Speaker_output();

        voice_command = EIGHT;
        break;
case EIGHT:
      //  ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[7][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[7][1];
        Speaker_output();

        voice_command = NINE;
        break;
case NINE:

     //   ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[8][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[8][1];
        Speaker_output();

        voice_command = TEN;
        break;
case TEN:
      //  ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[9][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[9][1];
        Speaker_output();

        voice_command = ELEVEN;
        break;
case ELEVEN:
     //   ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[10][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[10][1];
        Speaker_output();

        voice_command = TWELVE;
        break;
case TWELVE:
      //  ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[11][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[11][1];
        Speaker_output();

        voice_command = THIRTEEN;
        break;
case THIRTEEN:
      //  ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[12][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[12][1];
        Speaker_output();

        voice_command = FOURTEEN;
        break;
case FOURTEEN:
      //  ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[13][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[13][1];
        Speaker_output();

        voice_command = FIFTEEN;
        break;
case FIFTEEN:
      //  ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[14][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[14][1];
        Speaker_output();

        voice_command = SIXTEEN;
        break;
case SIXTEEN:
      //  ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[15][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[15][1];
        Speaker_output();

        voice_command = SEVENTEEN;
        break;
case SEVENTEEN:
//        ES00();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[16][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[16][1];
        Speaker_output();

        voice_command = EIGHTEEN;
        break;
case EIGHTEEN:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0,( const uint8_t *)word_count[17][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[17][1];
        Speaker_output();
        voice_command = NINTEEN;
        break;
case NINTEEN:

//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, ( const uint8_t *)word_count[18][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[18][1];
        Speaker_output();

        voice_command = TWENTY;
        break;
case TWENTY:

//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[19][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[19][1];
        Speaker_output();

        voice_command = THIRTY;
        break;
case THIRTY:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[20][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[20][1];
        Speaker_output();

        voice_command = FOURTY;
        break;
case FOURTY:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[21][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[21][1];
        Speaker_output();

        voice_command = FIFTY;
        break;
case FIFTY:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[22][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[22][1];
        Speaker_output();

        voice_command = SIXTY;
        break;
case SIXTY:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[23][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[23][1];
        Speaker_output();

        voice_command = SEVENTY;
        break;
case SEVENTY:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[24][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[24][1];
        Speaker_output();

        voice_command = EIGHTY;
        break;
case EIGHTY:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[25][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[25][1];
        Speaker_output();

        voice_command = NINTY;
        break;
case NINTY:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[26][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[26][1];
        Speaker_output();

        voice_command = HUNDREAD;
        break;
case HUNDREAD:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[27][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[27][1];
        Speaker_output();

        voice_command = THOUSAND;
        break;
case THOUSAND:
//        ES01();
        R_InitDecInfo(&g_dec_info0, &g_st_adpcm0, (const uint8_t *)word_count[28][0], PCMDECSIZE);
        PCM_DATA_SIZE1 = word_count[28][1];
        Speaker_output();

        voice_command = ONE;
        break;

    default :
//        __nop();
//        __nop();
//        __nop();
        break;
    }
}


void Speaker_output(void)
{

    R_InitRingBuffer(&g_rbf0);

    /* decodeF get PCM data 4bytes(initial) */
    R_DecodeProc(&g_dec_info0, &g_rbf0);
    g_dec_info0.playmode = PLAY_PLAYBACK;

    /* enable timer interrupt for audio outputs */
  //  R_TAU0_Channel0_Start();
   // R_TAU0_Channel2_Start();

     R_GPT_Start(&g_timer0_ctrl);
     R_GPT_Start (&g_timer1_ctrl);




//  Delay_Ms();
//  Delay_Ms();
//  Delay_Ms();
    /* decode for sound data size */
    //P0_bit.no4 =1;
    //P0_bit.no6 =1;
     R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_06, BSP_IO_LEVEL_HIGH);



    while (g_dec_info0.decno < PCM_DATA_SIZE1)
    {
        /* decode and update decode information */
        R_DecodeProc(&g_dec_info0, &g_rbf0);
    }
   // P0_bit.no4 =0;
    //P0_bit.no6 =0;
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_06, BSP_IO_LEVEL_LOW);


    /* When finished decoding all data, wait till an audio output is available */
    while (g_dec_info0.playmode != PLAY_END) {}

//    R_TAU0_Channel0_Stop();
//    R_TAU0_Channel2_Stop();
//    R_GPT_Stop ();
    R_GPT_Stop (&g_timer0_ctrl);
    R_GPT_Stop (&g_timer1_ctrl);
}

void Delay_Ms(void)
{
        for(delay=0;delay<40000;delay++);
        for(delay=0;delay<40000;delay++);
        for(delay=0;delay<40000;delay++);
        for(delay=0;delay<40000;delay++);
        for(delay=0;delay<40000;delay++);

}

//#pragma inline_asm ES00
//void ES00(void)
//{
//        mov     ES, #00             ;RC
//}
//
//#pragma inline_asm ES01
//void ES01(void)
//{
//        mov     ES, #01             ;RC
//}
