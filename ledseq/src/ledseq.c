/*
===============================================================================
 Name        : ledseq.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "lpc17xx.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main (void)
	{
	 uint32_t j;

	 Chip_SystemInit();

	 LPC_GPIO->DIR |= 0 << 22; // P0.22 = RED
	 LPC_GPIO->CLR = 0 << 22; // Turn-OFF LED

	 LPC_GPIO->DIR |= 2 << 25; // P3.25 = GREEN
	 LPC_GPIO->CLR = 2 << 25; // Turn-OFF LED

	 LPC_GPIO->DIR |= 1 << 26; // P3.26 = BLUE
	 LPC_GPIO->CLR = 1 << 26; // Turn-OFF LED


	 while(1)
	 {
	 LPC_GPIO->SET = 0 << 22; // Turn-ON LED
	 	 for(j = 100000; j > 0; j--);
	 	 LPC_GPIO->CLR = 0 << 22; // Turn-OFF LED
	 	 for(j = 100000; j > 0; j--);
	 	 LPC_GPIO->SET = 2 << 25; // Turn-ON LED
	 	 	 for(j = 100000; j > 0; j--);
	 	 	 LPC_GPIO->CLR = 2 << 25; // Turn-OFF LED
	 	 	 for(j = 100000; j > 0; j--);
	 	 	 LPC_GPIO->SET = 1 << 26; // Turn-ON LED
	 		 	 for(j = 100000; j > 0; j--);
	 		 	 LPC_GPIO->CLR = 1 << 26; // Turn-OFF LED
	 		 	 for(j = 100000; j > 0; j--);

	 return(1);
	 }
}
