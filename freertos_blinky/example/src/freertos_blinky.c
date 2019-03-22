/*
 * @brief FreeRTOS Blinky example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 *
 *
 *
 * Edited by Harsh Dadwal(731805) and Abhishek Parikhh (732182)
 * GitHub Repository for images  https://github.com/harshdadwal/MCUX/tree/master/FreeRTOS%20Blinky%20IMG
 * GitHub Repository for code    https://github.com/harshdadwal/MCUX/blob/master/freertos_blinky/example/src/freertos_blinky.c
 *
 *
 *
 */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, false);
	Board_LED_Set(1, false);
	Board_LED_Set(2, false);
}
void Delay(){
	unsigned long int a1,b1;
	for (b1=0;b1<100;b1++) for (a1=0;a1<25000;a1++);
}

/* LED1 toggle thread */
static void vLEDTask1(void *pvParameters) {


	while (1) {
		Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 0);
		Delay();
		Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
	    Delay();
    	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 0);
		Delay();
		Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 1);
		Delay();
		Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 0);
		Delay();
		Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 1);
		Delay();
	}
}


/* UART (or output) thread */
static void vUARTTask(void *pvParameters) {
	int tickCnt = 0;

	while (1) {
		DEBUGOUT("Tick: %d\r\n", tickCnt);
		tickCnt++;

		/* About a 1s delay here */
		vTaskDelay(configTICK_RATE_HZ);
	}
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	prvSetupHardware();

	/* LED1 toggle thread */
	xTaskCreate(vLEDTask1, (signed char *) "vTaskLed1",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* UART output thread, simply counts seconds */
	xTaskCreate(vUARTTask, (signed char *) "vTaskUart",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
