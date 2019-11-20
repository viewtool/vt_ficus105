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
    uint16_t pin_value = 0;
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
    // Set GPIO_7 and GPIO_8 to output 
    ret = VGI_SetOutput(VGI_USBGPIO, 0, VGI_GPIO_PIN7 | VGI_GPIO_PIN8);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin output error!\r\n");
        return ret;
    }
    // Set GPIO_7 and GPIO_8 
    ret = VGI_SetPins(VGI_USBGPIO, 0, VGI_GPIO_PIN7 | VGI_GPIO_PIN8);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin high error!\r\n");
        return ret;
    }
    // Reset GPIO_7 and GPIO_8 
    ret = VGI_ResetPins(VGI_USBGPIO, 0, VGI_GPIO_PIN7 | VGI_GPIO_PIN8);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin low error!\r\n");
        return ret;
    }
    // Set GPIO_4 and GPIO_5 to input 
    ret = VGI_SetInput(VGI_USBGPIO, 0, VGI_GPIO_PIN4 | VGI_GPIO_PIN5);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin input error!\r\n");
        return ret;
    }
    ret = VGI_ReadDatas(VGI_USBGPIO, 0, VGI_GPIO_PIN4 | VGI_GPIO_PIN5, &pin_value);
    if (ret != ERR_SUCCESS)
    {
        printf("Get pin data error!\r\n");
        return ret;
    }
    else
    {
        if ((pin_value & VGI_GPIO_PIN4) != 0)
        {
            printf("GPIO_4 is high-level!\r\n");
        }
        else
        {
            printf("GPIO_4 is low-level!\r\n");
        }
        if ((pin_value & VGI_GPIO_PIN5) != 0)
        {
            printf("GPIO_5 is high-level!\r\n");
        }
        else
        {
            printf("GPIO_5 is low-level!\r\n");
        }
    }
    //��GPIO_4��GPIO_5�������óɿ�©ģʽ������������裬�ɵ�˫��ڣ�
    ret = VGI_SetOpenDrain(VGI_USBGPIO, 0, VGI_GPIO_PIN4 | VGI_GPIO_PIN5);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin open drain error!\r\n");
        return ret;
    }
    //��GPIO_4��GPIO_5����ߵ�ƽ
    ret = VGI_SetPins(VGI_USBGPIO, 0, VGI_GPIO_PIN4 | VGI_GPIO_PIN5);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin high error!\r\n");
        return ret;
    }
    //��GPIO_4��GPIO_5����͵�ƽ
    ret = VGI_ResetPins(VGI_USBGPIO, 0, VGI_GPIO_PIN4 | VGI_GPIO_PIN5);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pin high error!\r\n");
        return ret;
    }
    //��ȡGPIO_4��GPIO_5����״̬
    ret = VGI_ReadDatas(VGI_USBGPIO, 0, VGI_GPIO_PIN4 | VGI_GPIO_PIN5, &pin_value);
    if (ret != ERR_SUCCESS)
    {
        printf("Get pin data error!\r\n");
        return ret;
    }
    else
    {
        if ((pin_value & VGI_GPIO_PIN4) != 0)
        {
            printf("GPIO_4 is high-level!\r\n");
        }
        else
        {
            printf("GPIO_4 is low-level!\r\n");
        }
        if ((pin_value & VGI_GPIO_PIN5) != 0)
        {
            printf("GPIO_5 is high-level!\r\n");
        }
        else
        {
            printf("GPIO_5 is low-level!\r\n");
        }
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


