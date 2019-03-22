/*
===============================================================================
 Name        : lab1.c
 Author      : Harsh & Abhishek
 Version     :
 Copyright   : $(copyright)
 Description : Led Blinking in sequence
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

void delay(int seconds){
	unsigned long int i,j;

	for (j=0;j<100;j++);
	for (i=0;i<6500000;i++);
}
int main(void)
{
#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
#endif
#endif

    Chip_GPIO_WriteDirBit(LPC_GPIO, 0, 22, true);  //RED LED
    Chip_GPIO_WriteDirBit(LPC_GPIO, 3, 25, true);  //GREEN LED
    Chip_GPIO_WriteDirBit(LPC_GPIO, 3, 26, true);  //BLUE LED

    Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
    Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 1);
    Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 1);
    volatile static int i1 = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 0);
    	delay(3000000);
        Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
    	delay(3000000);

    	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 0);
    	delay(3000000);
    	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 1);
    	delay(3000000);

    	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 0);
   		delay(3000000);
   		Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 1);
   		delay(3000000);

    	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 0);
    	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 0);
    	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 0);
		delay(3000000);

    	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
    	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 1);
    	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 1);
    	delay(3000000);

    	i1++;
    }
    return 0 ;
}
