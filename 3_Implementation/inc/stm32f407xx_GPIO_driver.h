#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*
 * Structure for GPIO configuration
 */
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;

/*
 * Handle structure for GPIO pin
 */
typedef struct
{
	GPIO_RegDef_t *pGPIOx;						//Base address of GPIOx
	GPIO_PinConfig_t GPIO_PinConfig;			//Pin configuration
}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO Pin number macros
 */

#define GPIO_PIN_NO_0			0
#define GPIO_PIN_NO_1			1
#define GPIO_PIN_NO_2			2
#define GPIO_PIN_NO_3			3
#define GPIO_PIN_NO_4			4
#define GPIO_PIN_NO_5			5
#define GPIO_PIN_NO_6			6
#define GPIO_PIN_NO_7			7
#define GPIO_PIN_NO_8			8
#define GPIO_PIN_NO_9			9
#define GPIO_PIN_NO_10			10
#define GPIO_PIN_NO_11			11
#define GPIO_PIN_NO_12			12
#define GPIO_PIN_NO_13			13
#define GPIO_PIN_NO_14			14
#define GPIO_PIN_NO_15			15

/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */

#define GPIO_PIN_IN				0				//	00: Input (reset state)
#define GPIO_PIN_OUT			1				//	01: General purpose output mode
#define GPIO_PIN_ALT			2				//	10: Alternate function mode
#define GPIO_PIN_ANALOG			3				//	11: Analog mode

#define GPIO_MODE_IT_FT  		4				//Falling Triggering
#define GPIO_MODE_IT_RT  		5				//Rising
#define GPIO_MODE_IT_RFT  		6				//Both fall and rise

/*
 * GPIO_PinSpeed macros
 */

#define GPIO_PIN_SPPED_LOW		0				//	00:Low speed
#define GPIO_PIN_SPPED_MED		1				//	01:Medium speed
#define GPIO_PIN_SPPED_HIGH		2				//	10:High speed
#define GPIO_PIN_SPPED_VHIGH	3				//	11:Very high speed

/*
 * GPIO_PinPuPdControl macros
 */

#define GPIO_PIN_NO_PUPD		0				//	00: No pull-up, pull-down
#define GPIO_PIN_PUP			1				//	01: Pull-up
#define GPIO_PIN_PDOWN			2				//	10: Pull-down
#define GPIO_PIN_REVERSE		3				//	11: Reserved


/*
 * GPIO_PinOPType macros (output type)
 */

#define GPIO_PIN_OP_TYPE_PP		0  				//Output push-pull (reset state)
#define GPIO_PIN_OP_TYPE_OD		1				//Output open-drain


/*
 * GPIO_PinAltFunMode macros
 */
#define GPIO_PIN_MODE_ALTN 		0


/*
 *
 *
 * USER Defined API
 *
 *
 *
 */

	/*
	 * Initialization and Deinitialization
	 */

	void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
	void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

	/*
	 * Peripheral clock control
	 */

	void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

	/*
	 * Data read and write
	 */

	uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
	uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
	void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
	void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value);
	void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


	/*
	 * IRQ configuration and ISR Handling
	 */

	void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);			//MCU specific(NVIC engine)
	void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);		//if we are working on multiple interrupts we can use this
	void GPIO_IRQHandlingConfig(uint8_t PinNumber);

























#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */