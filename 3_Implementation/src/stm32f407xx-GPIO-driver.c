#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx.h"


/*
 *
 *
 * USER Defined API
 *
 *
 *
 */

	/*
	 * @Brief:
	 * @Parm1:
	 * @Parm2:
	 * @Parm3:
	 * @Return Value: None
	 */


	void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
	{
		//To enable the clock
		if (EnorDi == ENABLE)
		{
			if(pGPIOx == GPIOA)
			{
				GPIOA_PCLK_EN();
			}
			else if (pGPIOx == GPIOB)
			{
				GPIOB_PCLK_EN();
			}
			else if (pGPIOx == GPIOC)
			{
				GPIOC_PCLK_EN();
			}
			else if (pGPIOx == GPIOD)
			{
				GPIOD_PCLK_EN();
			}
			else if (pGPIOx == GPIOE)
			{
				GPIOE_PCLK_EN();
			}
			else if (pGPIOx == GPIOF)
			{
				GPIOF_PCLK_EN();
			}
			else if (pGPIOx == GPIOG)
			{
				GPIOG_PCLK_EN();
			}
			else if (pGPIOx == GPIOH)
			{
				GPIOH_PCLK_EN();
			}
			else if (pGPIOx == GPIOI)
			{
				GPIOI_PCLK_EN();
			}
		}
		//For disable the clock
		else
		{
			if (pGPIOx == GPIOA)
			{
				GPIOA_PCLK_DIS();
			}
			else if(pGPIOx == GPIOB)
			{
				GPIOB_PCLK_DIS();
			}
			else if(pGPIOx == GPIOC)
			{
				GPIOC_PCLK_DIS();
			}
			else if(pGPIOx == GPIOD)
			{
				GPIOD_PCLK_DIS();
			}
			else if(pGPIOx == GPIOE)
			{
				GPIOE_PCLK_DIS();
			}
			else if(pGPIOx == GPIOF)
			{
				GPIOF_PCLK_DIS();
			}
			else if(pGPIOx == GPIOG)
			{
				GPIOG_PCLK_DIS();
			}
			else if(pGPIOx == GPIOH)
			{
				GPIOH_PCLK_DIS();
			}
			else if(pGPIOx == GPIOI)
			{
				GPIOI_PCLK_DIS();
			}
		}
	}

	/*
	 * @Brief:
	 * @Parm1:
	 * @Parm2:
	 * @Parm3:
	 * @Return Value: None
	 */

	void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
	{
		//Configure the mode
		uint32_t temp =0; 		//temp. register
		//Enable the pheriperal cclock
		GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);
		//Configure the mode of GPIO pin
		{
			if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_PIN_ANALOG)
			{
			//The non interrupt mode
			temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->MODER &= ~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); 				//Clear the bits
			pGPIOHandle->pGPIOx->MODER |= temp;																	//Set the bits
			}
			else
			{
				if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
				{
					//	Configure the FTSR
					EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
					//Clear the corresponding RTSR bit
					EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
				}
				else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
				{
					//	Configure the RTSR
					EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
					//Clear the corresponding FTSR bit
					EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
				}
				else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
				{
					//Configure both FTSR and RTSR
					EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
					EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
				}

				//Cofigure the gpio port selection in SYSCFG_EXTICR
				uint8_t temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4); 			//To reach the pin
				uint8_t temp2 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4);			//to reach the pin position
				uint8_t portcode = GPIO_BASE_ADDR_TO_CODE(pGPIOHandle->pGPIOx);
				SYSCFG_PCLK_EN();
				SYSCFG->EXTICR[temp1] = portcode << (temp2 * 4);

				//Enable the exit interrupt delivery using IMR
				EXTI->IMR |= 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
			}
			uint32_t temp = 0;
			temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->MODER &= ~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); 				//Clear the bits
			pGPIOHandle->pGPIOx->MODER |= temp;																	//Set the bits
			temp = 0;

			//configure the speed

			temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));				//Clear the bits/value
			pGPIOHandle->pGPIOx->OSPEEDR |= temp;																//Set the bits
			temp = 0;

			//Configure the pull up or pull down setting
			temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));				//Clear the bits
			pGPIOHandle->pGPIOx->PUPDR |= temp;																	//Set the bits
			temp = 0;

			//Configure the output type
			temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType <<(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType);
			pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 <<(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType));				//Clear the bits
			pGPIOHandle->pGPIOx->OTYPER |= temp;																//Set the bits
			temp = 0;

			//Configure the alternating function
			//I am not sure about am i written alternating function macro correctly or not
			if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_PIN_MODE_ALTN)
			{
				uint8_t temp1 =0, temp2 =0;
				temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
				temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8;
				pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xf <<(4*temp2));
				pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode<<(4*temp2));
			}
		}
	}

	/*
	 * @Brief:
	 * @Parm1:
	 * @Parm2:
	 * @Parm3:
	 * @Return Value: None
	 */
	void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_REG_RESET();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
				}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_REG_RESET();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_REG_RESET();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_REG_RESET();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_REG_RESET();
		}
	}



	/*
	 * @Brief:
	 * @Parm1:
	 * @Parm2:
	 * @Parm3:
	 * @Return Value: None
	 */
	uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
	{
		uint8_t Value;
		Value = (uint8_t) ((pGPIOx->IDR >> PinNumber)& 0x00000001);
		return Value;
	}

	/*
	 * @Brief:
	 * @Parm1:
	 * @Parm2:
	 * @Parm3:
	 * @Return Value: None
	 */
	uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
	{
		uint16_t Value;
		Value = (uint16_t) pGPIOx->IDR;
		return Value;
	}

	/*
	 * @Brief:
	 * @Parm1:
	 * @Parm2:
	 * @Parm3:
	 * @Return Value: None
		 */
	void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
	{
		if (Value == GPIO_PIN_SET)
		{
			pGPIOx->ODR |= (1<<PinNumber);
		}
		else
		{
			pGPIOx->ODR &= ~(1<<PinNumber);
		}
	}

	/*
	 * @Brief:
	 * @Parm1:
	 * @Parm2:
	 * @Parm3:
	 * @Return Value: None
		 */
	void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value)
	{
		pGPIOx->ODR = Value;
	}

	/*
	 * @Brief:
	 * @Parm1:
	 * @Parm2:
	 * @Parm3:
	 * @Return Value: None
	 */
	void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
	{
		pGPIOx->ODR ^= (1<<PinNumber);

	}


	/*
	 * GPIO IRQ configuration NVIC side
	 */
	void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
	{
		if(EnorDi == ENABLE)
		{
			if(IRQNumber <= 31)
			{
				*NVIC_ISER0 |= (1<<IRQNumber);
			}
			else if(IRQNumber > 31 && IRQNumber < 64)
			{
				*NVIC_ISER1 |= (1<<(IRQNumber % 32));
			}
			else if(IRQNumber >= 64 && IRQNumber < 96)
			{
				*NVIC_ISER2 |= (1<<(IRQNumber % 64));
			}
		}
		else
		{
			if(IRQNumber <= 31)
			{
				*NVIC_ICER0 |= (1<<IRQNumber);
			}
				else if(IRQNumber > 31 && IRQNumber < 64)
			{
				*NVIC_ICER1 |= (1<<(IRQNumber % 32));
			}
				else if(IRQNumber >= 64 && IRQNumber < 96)
			{
				*NVIC_ICER2 |= (1<<(IRQNumber % 64));
			}
		}
	}

	/*
	 * IRQ Handling
	 */
	void GPIO_IRQHandlingConfig(uint8_t PinNumber)
	{
		//Clear the exit PR sesister
		if(EXTI->PR & (1 << PinNumber))
		{
			//clear
			{
				EXTI->PR |= (1 << PinNumber);
			}
		}
	}