#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#define AUDIO_START_ADDRESS 0x6000


#define ADDR_ONE    (0x0000 + AUDIO_START_ADDRESS)
#define ADDR_TWO    (0x089E + AUDIO_START_ADDRESS)
#define ADDR_THREE  (0x11C2 + AUDIO_START_ADDRESS)
#define ADDR_FOUR   (0x1B1A + AUDIO_START_ADDRESS)
#define ADDR_FIVE   (0x235C + AUDIO_START_ADDRESS)
#define ADDR_SIX    (0x2D58 + AUDIO_START_ADDRESS)
#define ADDR_SEVEN  (0x3466 + AUDIO_START_ADDRESS)
#define ADDR_EIGHT  (0x3EFC + AUDIO_START_ADDRESS)
#define ADDR_NINE   (0x492C + AUDIO_START_ADDRESS)
#define ADDR_TEN    (0x540C + AUDIO_START_ADDRESS)

#define ADDR_ELEVEN (0x5F2D + AUDIO_START_ADDRESS)
#define ADDR_TWELVE (0x6CC5 + AUDIO_START_ADDRESS)
#define ADDR_THIRTEEN   (0x7733 + AUDIO_START_ADDRESS)
#define ADDR_FOURTEEN   (0x8741 + AUDIO_START_ADDRESS)
#define ADDR_FIFTEEN    (0x97D5 + AUDIO_START_ADDRESS)
#define ADDR_SIXTEEN    (0xA869 + AUDIO_START_ADDRESS)
#define ADDR_SEVENTEEN  (0xB8B5 + AUDIO_START_ADDRESS)
#define ADDR_EIGHTEEN   (0xD000 + AUDIO_START_ADDRESS)
#define ADDR_NINETEEN   (0xE094 + AUDIO_START_ADDRESS)
#define ADDR_TWENTY (0xF2BA + AUDIO_START_ADDRESS)

#define ADDR_THIRTY (0xFE1E + AUDIO_START_ADDRESS)
#define ADDR_FOURTY (0x106A8 + AUDIO_START_ADDRESS)
#define ADDR_FIFTY  (0x110F8 + AUDIO_START_ADDRESS)
#define ADDR_SIXTY  (0x11C14 + AUDIO_START_ADDRESS)
#define ADDR_SEVENTY    (0x128A4 + AUDIO_START_ADDRESS)
#define ADDR_EIGHTY (0x1352A + AUDIO_START_ADDRESS)
#define ADDR_NINETY (0x13E3A + AUDIO_START_ADDRESS)
#define ADDR_HUNDREAD   (0x1494C + AUDIO_START_ADDRESS)
#define ADDR_THOUSAND   (0x1559E + AUDIO_START_ADDRESS)


enum{
    ONE=1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ELEVEN,
    TWELVE,
    THIRTEEN,
    FOURTEEN,
    FIFTEEN,
    SIXTEEN,
    SEVENTEEN,
    EIGHTEEN,
    NINTEEN,
    TWENTY,
    THIRTY =30,
    FOURTY=40,
    FIFTY=50,
    SIXTY=60,
    SEVENTY=70,
    EIGHTY=80,
    NINTY=90,
    HUNDREAD,
    THOUSAND,
};

//extern void R_decode_main();
extern void R_decode_main(void);
//extern void R_decode_main(void);

#endif
