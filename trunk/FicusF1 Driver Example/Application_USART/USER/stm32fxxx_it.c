/**
  ******************************************************************************
  * @file    stm32fxxx_it.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    19-March-2012
  * @brief   Main Interrupt Service Routines.
  *          This file provides all exceptions handler and peripherals interrupt
  *          service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32fxxx_it.h"
#include <string.h>

/******************************************************************************/
/*             Cortex-M Processor Exceptions Handlers                         */
/******************************************************************************/
extern void _I2C1_EV_IRQHandler(void);
extern void _I2C2_EV_IRQHandler(void);
extern void _CAN1_RX0_IRQHandler(void);
extern void _CAN1_RX1_IRQHandler(void);
extern void _CAN2_RX0_IRQHandler(void);
extern void _CAN2_RX1_IRQHandler(void);
extern void _TIM2_IRQHandler(void);
extern void _TIM3_IRQHandler(void);
extern void _TIM4_IRQHandler(void);
extern void _TIM5_IRQHandler(void);
extern void _TIM6_IRQHandler(void);
extern void _DMA1_Channel1_IRQHandler(void);
extern void _DMA1_Channel3_IRQHandler(void);
extern void _USART1_IRQHandler(void);
extern void _USART2_IRQHandler(void);
extern void _USART3_IRQHandler(void);

void I2C1_EV_IRQHandler(void)
{
    _I2C1_EV_IRQHandler();
}

void I2C2_EV_IRQHandler(void)
{
    _I2C2_EV_IRQHandler();
}

void CAN1_RX0_IRQHandler(void)
{
    _CAN1_RX0_IRQHandler();
}

void CAN1_RX1_IRQHandler(void)
{
    _CAN1_RX1_IRQHandler();
}

void CAN2_RX0_IRQHandler(void)
{
    _CAN2_RX0_IRQHandler();
}

void CAN2_RX1_IRQHandler(void)
{
    _CAN2_RX1_IRQHandler();
}

void TIM2_IRQHandler(void)
{
    _TIM2_IRQHandler();
}
void TIM3_IRQHandler(void)
{
    _TIM3_IRQHandler();
}

void TIM4_IRQHandler(void)
{
    _TIM4_IRQHandler();
}

void TIM5_IRQHandler(void)
{
    _TIM5_IRQHandler();
}

void TIM6_IRQHandler(void)
{
    _TIM6_IRQHandler();
}

void DMA1_Channel1_IRQHandler(void)
{
   _DMA1_Channel1_IRQHandler();
}
void DMA1_Channel3_IRQHandler(void)
{
   _DMA1_Channel3_IRQHandler();
}
void USART1_IRQHandler(void)
{
    _USART1_IRQHandler();
}
void USART2_IRQHandler(void)
{
    _USART2_IRQHandler();
}
void USART3_IRQHandler(void)
{
    _USART3_IRQHandler();
}
/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
   
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
