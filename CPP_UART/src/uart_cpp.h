
#include "stm32f4xx.h"

#ifndef UART_H
#define UART_H


// ------------------------------------------------------------ DEFINES ------------------------------------------------------------

#define myUSART1              ( (myUART*) ((USART_TypeDef *) ((((uint32_t)0x40000000) + 0x00010000) + 0x1000)) )
#define myUSART6              ( (myUART*) ((USART_TypeDef *) ((((uint32_t)0x40000000) + 0x00010000) + 0x1400)) )




// ------------------------------------------------------------ ENUM CLASSES ------------------------------------------------------------




// ------------------------------------------------------------ UART CLASS ------------------------------------------------------------

class myUART {
	  volatile uint16_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
	  uint16_t      	RESERVED0;  /*!< Reserved, 0x02                                                */
	  volatile uint16_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
	  uint16_t      	RESERVED1;  /*!< Reserved, 0x06                                                */
	  volatile uint16_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
	  uint16_t      	RESERVED2;  /*!< Reserved, 0x0A                                                */
	  volatile uint16_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
	  uint16_t      	RESERVED3;  /*!< Reserved, 0x0E                                                */
	  volatile uint16_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
	  uint16_t      	RESERVED4;  /*!< Reserved, 0x12                                                */
	  volatile uint16_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
	  uint16_t     	 	RESERVED5;  /*!< Reserved, 0x16                                                */
	  volatile uint16_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
	  uint16_t      	RESERVED6;  /*!< Reserved, 0x1A                                                */

public:

	  void inline SendData(uint16_t Data)
	  {
	    /* Check the parameters */
	    //assert_param(IS_USART_DATA(Data));

	    /* Transmit Data */
	    DR = (Data & (uint16_t)0x01FF);
	  }



	  uint16_t inline ReceiveData()
	  {
	    /* Check the parameters */
	    //assert_param(IS_USART_ALL_PERIPH(USARTx));

	    /* Receive Data */
	    return (uint16_t)(DR & (uint16_t)0x01FF);
	  }

	  uint16_t ReceiveData()
	  {
	    /* Check the parameters */
	    //assert_param(IS_USART_ALL_PERIPH(USARTx));

	    /* Receive Data */
	    return (uint16_t)(USARTx->DR & (uint16_t)0x01FF);
	  }
};



#endif // UART_H
