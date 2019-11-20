  /*
  ******************************************************************************
  * @file     : USB_UART_Test.cpp
  * @Copyright: ViewTool 
  * @Revision : ver 1.0
  * @Date     : 2014/12/29 11:00
  * @brief    : USB_UART_Test demo
  ******************************************************************************
  * @attention
  *
  * Copyright 2009-2014, ViewTool
  * http://www.viewtool.com/
  * All Rights Reserved
  * 
  ******************************************************************************
  */
#ifdef WINAPI
#include "stdafx.h"
#include "ControlUART.h"
#else
#include <stdio.h>
#include "stm32f10x_conf.h"
#include "vt_usart.h"
#endif
/*
GINKGO_DEVICE_INDEX: indicate which Ginkgo device being selected to access
  Ginkgo driver, DLLs and application support multiple Ginkgo devices (such as multiple I2C, SPI, or CAN adapters plug in 
  same PC to work together, so using this MACRO to identify device
  If only one Ginkgo device plug in PC, then set it to "0" always
*/
#define GINKGO_DEVICE_INDEX 0
/*
UART_CHANNEL_INDEX: indicate which UART channel to be used
  Ginkgo ii product:support totoally 2 channels, pinout please refer doc:
  http://www.viewtool.com/demo/Ginkgo/Documents/Ginkgo_series_adapter_Pin_function_definition_table.zip
  For example: 
  channel 0:
  using: 
  PA9:  UART1_TX
  PA10: UART1_RX
  channel 1:
  using: 
  PA2:  UART2_TX
  PA3:  UART2_RX
  channel 2:
  using: 
  PB10:  UART3_TX
  PB11:  UART3_RX  
*/
#define UART_CHANNEL_INDEX 0

int main(int argc, char* argv[])
{
	uint16_t Len = 0;
	uint8_t ReadBuffer[64]={0};
	uint32_t AllDataNum = 0;
	int ret,i=0;
	UART_INIT_CONFIG InitConfig;
	uint8_t WriteBuffer[64]={0};
	ret = UART_ScanDevice(1);
	if(ret <= 0){
		printf("No device connected!\r\n");
		return 0;
	}
	ret = UART_OpenDevice(UART_USBUART,0,0);
	if(ret != ERR_SUCCESS){
		printf("Open device error!\r\n");
		return 0;
	}
	InitConfig.BaudRate = 115200;
	InitConfig.Parity = 0;
	InitConfig.RS485Mode = 485;
	InitConfig.StopBits = 0;
	InitConfig.WordLength = 8;
	ret = UART_InitDevice(UART_USBUART,GINKGO_DEVICE_INDEX,UART_CHANNEL_INDEX,&InitConfig);
	if(ret != ERR_SUCCESS){
		printf("Initialize device error!\r\n");
		return 0;
	}
	for(i=0;i<sizeof(WriteBuffer);i++){
		WriteBuffer[i] = i;
	}
	ret = UART_WriteBytes(UART_USBUART,GINKGO_DEVICE_INDEX,UART_CHANNEL_INDEX,WriteBuffer,64);
	if(ret != ERR_SUCCESS){
		printf("Write data error!\r\n");
		return 0;
	}

	while(1){
		ret = UART_ReadBytes(UART_USBUART,GINKGO_DEVICE_INDEX,UART_CHANNEL_INDEX,ReadBuffer,&Len);
		if(ret == ERR_READ_NO_DATA){
//			Sleep(50);
			continue;
		}else if(ret == ERR_SUCCESS){
			if(Len > 0){
				AllDataNum += Len;
				for(i=0;i<Len;i++){
					printf("%02X ",ReadBuffer[i]);
				}
                if((AllDataNum % 8) == 0)
                {
                    printf("\r\n");  
                }
				
				Len = 0;
                if(AllDataNum == 64)
                {
                    AllDataNum = 0;
                    printf("\r\n");
                    printf("\r\n");
                }
                
				//break;
			}
//			Sleep(50);
		
		}else{
			printf("Read data error!\r\n");
			//return 0;
		}
	}
	return 0;
}

