  /*
  ******************************************************************************
  * @file     : USB_PWM_Test.cpp
  * @Copyright: ViewTool 
  * @Revision : ver 1.0
  * @Date     : 2014/12/29 10:40
  * @brief    : USB_PWM_Test demo
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
  PWM_Channel0: GPIO_PortA_Pin0
  PWM_Channel1: GPIO_PortA_Pin1
  PWM_Channel2: GPIO_PortA_Pin2
  PWM_Channel3: GPIO_PortA_Pin3
  PWM_Channel4: GPIO_PortA_Pin6
  PWM_Channel5: GPIO_PortA_Pin7
  PWM_Channel6: GPIO_PortB_Pin8
  PWM_Channel7: GPIO_PortB_Pin9
  */
#ifdef WINAPI
#include "stdafx.h"
#include "ControlPWM.h"
#else
#include <stdio.h>
#include "stm32f10x_conf.h"
#include "vt_pwm.h"
#endif

int main(int argc, char* argv[])
{
    int ret;
	// Adjust PWM_CH0 clock frequency
	uint32_t Frequency[8] = {0};
    // Adjust PWM_CH2 duty ratio
	uint8_t Pulse[8] = {0};	
	VPI_INIT_CONFIG PWM_Config;
    // Scan connected device 
    ret = VPI_ScanDevice(1);
    if (ret <= 0)
    {
        printf("No device connect!\n");
        return ret;
    }
    // Open device
    ret = VPI_OpenDevice(VPI_USBPWM, 0, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Open device error!\n");
        return ret;
    }
    // Initialize PWM_CH0 channel
    PWM_Config.PWM_ChannelMask = VPI_PWM_CH0;
    PWM_Config.PWM_Frequency = 10000;
    PWM_Config.PWM_Mode = 0;
    PWM_Config.PWM_Polarity = 0;
    PWM_Config.PWM_Pulse = 50;
    ret = VPI_InitPWM(VPI_USBPWM,0,&PWM_Config);
    if (ret != ERR_SUCCESS)
    {
        printf("Initialize device error!\n");
        return ret;
    }
    // Star PWM_CH0 channel
    ret = VPI_StartPWM(VPI_USBPWM,0,VPI_PWM_CH0);
    if (ret != ERR_SUCCESS)
    {
        printf("Start pwm error!\n");
        return ret;
    }
    // Run 1S
    Sleep(1000);
    // Stop PWM_CH0 channel
    ret = VPI_StopPWM(VPI_USBPWM, 0, VPI_PWM_CH0);
	
    if (ret != ERR_SUCCESS)
    {
        printf("Stop pwm error!\n");
        return ret;
    }
    // Initialize all of channel
    PWM_Config.PWM_ChannelMask = VPI_PWM_ALL;
    PWM_Config.PWM_Frequency = 100000;
    PWM_Config.PWM_Mode = 0;
    PWM_Config.PWM_Polarity = 0;
    PWM_Config.PWM_Pulse = 50;
    ret = VPI_InitPWM(VPI_USBPWM, 0, &PWM_Config);
    if (ret != ERR_SUCCESS)
    {
        printf("Initialize device error!\n");
        return ret;
    }
    // Star PWM_CH0, PWM_CH2 channel
    ret = VPI_StartPWM(VPI_USBPWM, 0, VPI_PWM_CH0 | VPI_PWM_CH2);
    if (ret != ERR_SUCCESS)
    {
        printf("Start pwm error!\n");
        return ret;
    }
    // Run 1S
    Sleep(1000);
    Frequency[0] = 50000;
    ret = VPI_SetPWMPeriod(VPI_USBPWM, 0, VPI_PWM_CH0, Frequency);
	
    if (ret != ERR_SUCCESS)
    {
        printf("Set frequency error!\n");
        return ret;
    }

    Pulse[2] = 80;
    ret = VPI_SetPWMPulse(VPI_USBPWM, 0, VPI_PWM_CH2, Pulse);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pulse error!\n");
        return ret;
    }
    // Run 1s
    Sleep(1000);
    // Adjust PWM_CH0 and PWM_CH2 duty ratio
    Pulse[0] = 20;
    Pulse[2] = 80;
    ret = VPI_SetPWMPulse(VPI_USBPWM, 0, VPI_PWM_CH0|VPI_PWM_CH2, Pulse);
    if (ret != ERR_SUCCESS)
    {
        printf("Set pulse error!\n");
        return ret;
    }
    // Run 1s
    Sleep(1000);
    // Attention: PWM_CH(2n) and PWM_CH(2n+1) cannot separate set
    // Each channel duty ratio can separate set
    // Close  device
    ret = VPI_CloseDevice(VPI_USBPWM, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Close device error!\n");
        return ret;
    }
    while(1);
	return 0;
}

