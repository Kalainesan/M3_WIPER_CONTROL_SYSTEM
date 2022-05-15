#include "stm32f407xx.h"

#include <stdint.h>
#include <unistd.h>

#define BUTN_PRESSED	ENABLE


void delay1(void)
{
	for (uint32_t i=0; i<0x5555555; i++);
}

void delay2(void)
{
	for (uint32_t i=0; i<0x2222222; i++);

}

void delay3(void)
{
	for (uint32_t i=0; i<0xFFFFFF; i++);
}

void wiper1(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay1();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay1();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay1();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay1();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay1();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay1();
}

void wiper2(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay2();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay2();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay2();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay2();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay2();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay2();
}

void wiper3(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay3();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay3();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay3();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay3();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay3();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay3();
}



int main(void)
{
	GPIO_Handle_t  BlueLed, GreenLed, OrangeLed, RedLed, GpioButn; 			//create handle for led
	//Blue LED
	BlueLed.pGPIOx = GPIOD;				// telling that the handle belongs to GPIOD
	BlueLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	BlueLed.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_OUT;
	BlueLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_PIN_SPPED_HIGH;
	BlueLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_PIN_OP_TYPE_PP;
	BlueLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

	//GREEn LED
	GreenLed.pGPIOx = GPIOD;				// telling that the handle belongs to GPIOD
	GreenLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GreenLed.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_OUT;
	GreenLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_PIN_SPPED_HIGH;
	GreenLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_PIN_OP_TYPE_PP;
	GreenLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

	//OrangeLed LED
	OrangeLed.pGPIOx = GPIOD;				// telling that the handle belongs to GPIOD
	OrangeLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	OrangeLed.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_OUT;
	OrangeLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_PIN_SPPED_HIGH;
	OrangeLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_PIN_OP_TYPE_PP;
	OrangeLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

	//REd LED
	RedLed.pGPIOx = GPIOD;				// telling that the handle belongs to GPIOD
	RedLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	RedLed.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_OUT;
	RedLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_PIN_SPPED_HIGH;
	RedLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_PIN_OP_TYPE_PP;
	RedLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&BlueLed);
	GPIO_Init(&GreenLed);
	GPIO_Init(&OrangeLed);
	GPIO_Init(&RedLed);

	GpioButn.pGPIOx = GPIOA;				// telling that the handle belongs to GPIOA
	GpioButn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioButn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioButn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_PIN_SPPED_HIGH;
	GpioButn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioButn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BUTN_PRESSED)
		{
			delay1();
			delay1();
			delay1();
			GPIO_WriteToOutputPin(GPIOD, 14, ENABLE);
			delay1();
			delay1();
			if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BUTN_PRESSED)
			{
				while(1)
				{
					wiper1();
					if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BUTN_PRESSED)
					{
						while(1)
						{
							wiper2();
							if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BUTN_PRESSED)
							{
								while(1)
								{
									wiper3();
									if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BUTN_PRESSED)
									{
										while(1)
										{
											GPIO_WriteToOutputPin(GPIOD, 12, DISABLE);
											GPIO_WriteToOutputPin(GPIOD, 13, DISABLE);
											GPIO_WriteToOutputPin(GPIOD, 15, DISABLE);
											delay1();
											delay1();
											if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BUTN_PRESSED)
											{
												while(1)
												{
													GPIO_WriteToOutputPin(GPIOD, 14, DISABLE);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}