#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>

#define __vo volatile // Macro for Volatile used in typedof struct

/*
 * ARM cortex Mx Processor NVIC ISERx register address
 */

#define NVIC_ISER0				(__vo uint32_t *)0xE000E100
#define NVIC_ISER1				(__vo uint32_t *)0xE000E104
#define NVIC_ISER2				(__vo uint32_t *)0xE000E108
#define NVIC_ISER3				(__vo uint32_t *)0xE000E10C

/*
 * ARM cortex Mx Processor NVIC ICERx register address
 */

#define NVIC_ICER0				(__vo uint32_t *)0XE000E180
#define NVIC_ICER1				(__vo uint32_t *)0XE000E184
#define NVIC_ICER2				(__vo uint32_t *)0XE000E188
#define NVIC_ICER3				(__vo uint32_t *)0XE000E18C

#define IRQ_NO_EXTIO			6
/*
 *Base address of various memories present in Microcontroller
 */

#define FLASH_BASE_ADDR			0x08000000U			//Base address of Flash memory
#define SRAM1_BASE_ADDR			0x20000000U			//Base address of SRAM1
#define SRAM2_BASE_ADDR			0x2001C000U			//Base address of SRAM2
#define ROM_BASE_ADDR			0x1FFF0000U			//Base address of system memory (ROM)
#define SRAM_BASE_ADDR			SRAM1_BASE_ADDR		//Base address SRAM

/*
 * Base addresses of various bus domains such as AHBx and APBx
 */

#define PERIPH_BASE_ADDR 		0x40000000U			//Peripheral base address
#define APB1PERIPH_BASE_ADDR	PERIPH_BASE_ADDR		//
#define APB2PERIPH_BASE_ADDR	0x40010000U		//System memory base address
#define AHB1PERIPH_BASE_ADDR	0x40020000U		//System memory base address
#define AHB2PERIPH_BASE_ADDR	0x50000000U		//System memory base address

/*
 * Base addresses of various peripherals hanging on AHB1 bus
 */

#define GPIOA_BASE_ADDR			0x40020000U		//System memory base address
#define GPIOB_BASE_ADDR			0x40020400U		//System memory base address
#define GPIOC_BASE_ADDR			0x40020800U		//System memory base address
#define GPIOD_BASE_ADDR			0x40020C00U
#define GPIOE_BASE_ADDR			0x40021000U
#define GPIOF_BASE_ADDR			0x40021400U
#define GPIOG_BASE_ADDR			0x40021800U
#define GPIOH_BASE_ADDR			0x40021C00U
#define GPIOI_BASE_ADDR			0x40022000U

#define RCC_BASE_ADDR			0x40023800U		//RCC base address




/*
 * Base addresses of various  peripherals hanging on APB1 bus
 */

#define I2C1_BASE_ADDR			0x40005400U
#define I2C2_BASE_ADDR			0x40005800U
#define I2C3_BASE_ADDR			0x40005C00U
#define SPI2_BASE_ADDR			0x40003800U
#define SPI3_BASE_ADDR			0x40003C00U
#define USART2_BASE_ADDR		0x40004400U
#define USART3_BASE_ADDR		0x40004800U
#define UART4_BASE_ADDR			0x40004C00U
#define UART5_BASE_ADDR			0x40005000U






/*
 * Base addresses of various peripherals hanging on APB2 bus
 */

#define SPI1_BASE_ADDR			0x40013000U
#define USART1_BASE_ADDR		0x40011000U
#define USART6_BASE_ADDR		0x40011400U
#define EXTI_BASE_ADDR			0x40013C00U
#define SYSCFG_BASE_ADDR		0x40013800U



/*
 *Peripheral structure definition
 */

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];			/* or __vo uint32_t AFRL; __vo uint32_t AFRH;*/
}GPIO_RegDef_t;



/*
 * RCC
 */
typedef struct
{
	__vo uint32_t 	CR;
	__vo uint32_t 	PLLCFGR;
	__vo uint32_t 	CFGR;
	__vo uint32_t 	CIR;
	__vo uint32_t 	AHB1RSTR;
	__vo uint32_t 	AHB2RSTR;
	__vo uint32_t 	AHB3RSTR;
	uint32_t 		RESERVED0;
	__vo uint32_t 	APB1RSTR;
	__vo uint32_t 	APB2RSTR;
	uint32_t 		RESERVED1[2];
	__vo uint32_t 	AHB1ENR;
	__vo uint32_t 	AHB2ENR;
	__vo uint32_t 	AHB3ENR;
	uint32_t 		RESERVED2;
	__vo uint32_t 	APB1ENR;
	__vo uint32_t 	APB2ENR;
	uint32_t 		RESERVED3[2];
	__vo uint32_t 	AHB1LPENR;
	__vo uint32_t 	AHB2LPENR;
	__vo uint32_t 	AHB3LPENR;
	__vo uint32_t 	RESERVED6;
	__vo uint32_t 	APB1LPENR;
	__vo uint32_t 	APB2LPENR;
	uint32_t 		RESERVED4[2];
	__vo uint32_t 	BDCR;
	__vo uint32_t 	CSR;
	uint32_t 		RESERVED5[2];
	__vo uint32_t 	SSCGR;
	__vo uint32_t 	PLLI2SCFGR;

}RCC_RegDef_t;

/*
 * peripheral register defination structure for EXTI(12.3.7 EXTI register map)
 */

typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef_t;


/*
 * Peripheral register defination structure for SYSCFG (9.2.8 SYSCFG register maps)
 */

typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	uint32_t	  RESERVED1[2];
	__vo uint32_t CMPCR;
	uint32_t	  RESERVED2[2];
	__vo uint32_t CFGR;

}SYSCFG_RegDef_t;



/*
 * Peripheral definitions
 */

//GPIO_RegDef_t *pGPIOA = (GPIO_RegDef_t) AHB1PERIPH_BASE_ADDR;
					//or
#define GPIOA					((GPIO_RegDef_t *) GPIOA_BASE_ADDR) 	//Macro for base address GPIOA
#define GPIOB					((GPIO_RegDef_t *) GPIOB_BASE_ADDR)	//Macro for base address GPIOA
#define GPIOC					((GPIO_RegDef_t *) GPIOC_BASE_ADDR)	//Macro for base address GPIOA
#define GPIOD					((GPIO_RegDef_t *) GPIOD_BASE_ADDR)	//Macro for base address GPIOA
#define GPIOE					((GPIO_RegDef_t *) GPIOE_BASE_ADDR)	//Macro for base address GPIOA
#define GPIOF					((GPIO_RegDef_t *) GPIOF_BASE_ADDR)	//Macro for base address GPIOA
#define GPIOG					((GPIO_RegDef_t *) GPIOG_BASE_ADDR)	//Macro for base address GPIOA
#define GPIOH					((GPIO_RegDef_t *) GPIOH_BASE_ADDR)	//Macro for base address GPIOA
#define GPIOI					((GPIO_RegDef_t *) GPIOI_BASE_ADDR)	//Macro for base address GPIOA

#define RCC						((RCC_RegDef_t *) RCC_BASE_ADDR)		//Macro for RCC base address
#define EXTI					((EXTI_RegDef_t *)EXTI_BASE_ADDR)		//Macro for EXTI base address
#define SYSCFG					((SYSCFG_RegDef_t *)SYSCFG_BASE_ADDR)	//Macro for SYSCFG base address


/*
 * Macros to enable RCC clock for GPIOx
 */

#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |=(1<<0)) //set
#define GPIOB_PCLK_EN()			(RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN()			(RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN()			(RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN()			(RCC->AHB1ENR |=(1<<4))
#define GPIOF_PCLK_EN()			(RCC->AHB1ENR |=(1<<5))
#define GPIOG_PCLK_EN()			(RCC->AHB1ENR |=(1<<6))
#define GPIOH_PCLK_EN()			(RCC->AHB1ENR |=(1<<7))
#define GPIOI_PCLK_EN()			(RCC->AHB1ENR |=(1<<8))

/*
 * Macros to disable RCC clocks for GPIOx
 */

#define GPIOA_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<0))	//Reset
#define GPIOB_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<1))
#define GPIOC_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<2))
#define GPIOD_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<3))
#define GPIOE_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<4))
#define GPIOF_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<5))
#define GPIOG_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<6))
#define GPIOH_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<7))
#define GPIOI_PCLK_DIS()		(RCC->AHB1ENR &=~(1<<8))


//clock enable and disable of I2C,SPI,UART

/*
 * Clock enable macros for I2Cx peripheral
 */

#define I2C1_PCLK_EN()			(RCC->AHB1ENR |=(1<<21))
#define I2C2_PCLK_EN()			(RCC->AHB1ENR |=(1<<22))
#define I2C3_PCLK_EN()			(RCC->AHB1ENR |=(1<<23))
/*
 * Clock disable macros for I2Cx peripheral
 */

#define I2C1_PCLK_DIS()			(RCC->AHB1ENR &=~(1<<21))
#define I2C2_PCLK_DIS()			(RCC->AHB1ENR &=~(1<<22))
#define I2C3_PCLK_DIS()			(RCC->AHB1ENR &=~(1<<23))

/*
 * Clock Enable macros for SPIx peripheral
 */
#define SPI1_PCLK_EN()			(RCC->APB2ENR |=(1<<12))
#define SPI2_PCLK_EN()			(RCC->APB1ENR |=(1<<14))
#define SPI3_PCLK_EN()			(RCC->APB1ENR |=(1<<15))

/*
 * Clock Disable macros for SPIx peripheral
 */
#define SPI1_PCLK_DIS()			(RCC->APB2ENR &=~(1<<12))
#define SPI2_PCLK_DIS()			(RCC->APB1ENR &=~(1<<14))
#define SPI3_PCLK_DIS()			(RCC->APB1ENR &=~(1<<15))


/*
 * Clock Enable macros for USARTxx peripheral
 */
#define USART1_PCLK_EN()		(RCC->APB2ENR |=(1<<4))
#define USART2_PCLK_EN()		(RCC->APB1ENR |=(1<<17))
#define USART3_PCLK_EN()		(RCC->APB1ENR |=(1<<18))
#define UART4_PCLK_EN()			(RCC->APB1ENR |=(1<<19))
#define UART5_PCLK_EN()			(RCC->APB1ENR |=(1<<20))

/*
 * Clock Disable macros for USARTxx peripheral
 */
#define USART1_PCLK_DIS()		(RCC->APB2ENR &=~(1<<4))
#define USART2_PCLK_DIS()		(RCC->APB1ENR &=~(1<<17))
#define USART3_PCLK_DIS()		(RCC->APB1ENR &= ~(1<<18))
#define UART4_PCLK_DIS()		(RCC->APB1ENR &=~(1<<19))
#define UART5_PCLK_DIS()		(RCC->APB1ENR &=~(1<<20))


/*
 * Clock enable macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN()		(RCC->APB2ENR |=(1<<14))

/*
 * Clock disable macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_DIS()		(RCC->APB2ENR &=~(1<<14))


/*******GPIOs resetting******/
#define GPIOA_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<0));		(RCC->AHB1RSTR &=~(1<<0)); } while(0)
#define GPIOB_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<1));		(RCC->AHB1RSTR &=~(1<<1)); } while(0)
#define GPIOC_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<2));		(RCC->AHB1RSTR &=~(1<<2)); } while(0)
#define GPIOD_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<3));		(RCC->AHB1RSTR &=~(1<<3)); } while(0)
#define GPIOE_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<4));		(RCC->AHB1RSTR &=~(1<<4)); } while(0)
#define GPIOF_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<5));		(RCC->AHB1RSTR &=~(1<<5)); } while(0)
#define GPIOG_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<6));		(RCC->AHB1RSTR &=~(1<<6)); } while(0)
#define GPIOH_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<7));		(RCC->AHB1RSTR &=~(1<<7)); } while(0)
#define GPIOI_REG_RESET()		do { (RCC->AHB1RSTR |=(1<<8));		(RCC->AHB1RSTR &=~(1<<8)); } while(0)


/********SOME GENERIC MACROS***/
#define ENABLE					1
#define DISABLE					0
#define SET						1
#define RESET					0
#define GPIO_PIN_SET 			SET
#define GPIO_PIN_RESET			RESET


/*
 * Returns port code for given GPIOx base address
 */
/*
 * this macro return the code between(0-7) for given base adddress
 */
#define GPIO_BASE_ADDR_TO_CODE(x)		(	(x == GPIOA)?0:\
											(x == GPIOB)?1:\
											(x == GPIOC)?2:\
											(x == GPIOD)?3:\
											(x == GPIOE)?4:\
											(x == GPIOF)?5:\
											(x == GPIOG)?6:\
											(x == GPIOH)?7:\
											(x == GPIOI)?8:0)



/*
 * Reference for main file
 */
#include "stm32f407xx_gpio_driver.h"


#endif /* INC_STM32F407XX_H_ */