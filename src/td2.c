/*
===============================================================================
 Name        : TDII.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void)
{

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    Chip_GPIO_SetPinDIR(LPC_GPIO, 0, 26, 1);
    Chip_GPIO_SetPinDIR(LPC_GPIO, 2,  0, 1);
    Chip_GPIO_SetPinDIR(LPC_GPIO, 2,  1, 1);

    Chip_GPIO_SetPinState(LPC_GPIO, 0, 26, 0);
    Chip_GPIO_SetPinState(LPC_GPIO, 2,  0, 0);
    Chip_GPIO_SetPinState(LPC_GPIO, 2,  1, 0);

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    int j = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1)
    {


        Chip_GPIO_SetPinState(LPC_GPIO, 0, 26, 1);
        Chip_GPIO_SetPinState(LPC_GPIO, 2,  0, 1);
        Chip_GPIO_SetPinState(LPC_GPIO, 2,  1, 1);

        for(j=0; j<1000; j++)
        for(i=0; i<10000; i++);


        Chip_GPIO_SetPinState(LPC_GPIO, 0, 26, 0);
        Chip_GPIO_SetPinState(LPC_GPIO, 2,  0, 0);
        Chip_GPIO_SetPinState(LPC_GPIO, 2,  1, 0);

        for(j=0; j<1000; j++)
        for(i=0; i<10000; i++);
    }
    return 0 ;
}
