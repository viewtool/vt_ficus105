  /*
  ******************************************************************************
  * @file     : USB_GPIO_Test.cpp
  * @Copyright: ViewTool 
  * @Revision : ver 1.0
  * @Date     : 2014/12/19 11:53
  * @brief    : USB_GPIO_Test demo
  ******************************************************************************
  * @attention
  *
  * Copyright 2009-2014, ViewTool
  * http://www.viewtool.com/
  * All Rights Reserved
  * 
  ******************************************************************************
  */
  /*
    GPIO_PortA Channel 0 - 15 
    
  */
#ifdef WINAPI
#include "stdafx.h"
#include "ControlGPIO.h"
#else
#include <stdio.h>
#include "stm32f10x_conf.h"
#include "vt_gpio.h"
#endif
int main(int argc, char* argv[])
{
	// Get GPIO_4 and GPIO_5 status 
    int ret;
    // Scan connected device
    ret = VGI_ScanDevice(1);
    if (ret <= 0)
    {
        printf("No device connect!\r\n");
        return ret;
    }
    // Open device 
    ret = VGI_OpenDevice(VGI_USBGPIO, 0, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Open device error!\r\n");
        return ret;
    } 
    ret = VGI_SetOutput(VGI_USBGPIO, 0, VGI_GPIO_PORT1 | VGI_GPIO_PIN6 | VGI_GPIO_PIN7);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin output error!\r\n");
        return ret;
    }
    ret = VGI_SetOutput(VGI_USBGPIO, 0, VGI_GPIO_PORT2 | VGI_GPIO_PIN12 | VGI_GPIO_PIN13);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin output error!\r\n");
        return ret;
    }
    while(1)
    {
        // Set GPIO_7 and GPIO_8 
        ret = VGI_SetPins(VGI_USBGPIO, 0, VGI_GPIO_PORT1 | VGI_GPIO_PIN6 | VGI_GPIO_PIN7);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin high error!\r\n");
            return ret;
        }else{
            printf("Set pin high LED\r\n");
        }
        ret = VGI_SetPins(VGI_USBGPIO, 0, VGI_GPIO_PORT2 | VGI_GPIO_PIN12 | VGI_GPIO_PIN13);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin high error!\r\n");
            return ret;
        }else{
            printf("Set pin high LED\r\n");
        }        
        Sleep(100);
        // Reset GPIO_7 and GPIO_8 
        ret = VGI_ResetPins(VGI_USBGPIO, 0, VGI_GPIO_PORT1 | VGI_GPIO_PIN6 | VGI_GPIO_PIN7);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin low error!\r\n");
            return ret;
        }else{
            printf("Set pin low LED\r\n");
        }
        ret = VGI_ResetPins(VGI_USBGPIO, 0, VGI_GPIO_PORT2 | VGI_GPIO_PIN12 | VGI_GPIO_PIN13);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin low error!\r\n");
            return ret;
        }else{
            printf("Set pin low LED\r\n");
        }
        Sleep(100);
    }
    //�ر��豸
    ret = VGI_CloseDevice(VGI_USBGPIO, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Close device error!\r\n");
        return ret;
    }
	return 0;
}


