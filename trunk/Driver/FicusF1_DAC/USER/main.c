  /*
  ******************************************************************************
  * @file     : Ficus_DAC_Test.cpp
  * @Copyright: ViewTool 
  * @Revision : Ver 1.0
  * @Date     : 2019/10/23 
  * @brief    : Ficus_DAC_Test demo
  ******************************************************************************
  * @attention
  *
  * Copyright 2019-2020, ViewTool
  * http://www.viewtool.com/
  * All Rights Reserved
  * 
  ******************************************************************************
  */
#ifdef WINAPI
#include "stdafx.h"
#include "ControlADC.h"
#else
#include <stdio.h>
#include "stm32f10x_conf.h"
#include "vt_dac.h"
#include "func_map.h"
#endif
int main(int argc, char* argv[])
{
    int ret;
    //Scan connected device
    uint16_t DAC_Value[2]={1000,2000};
    ret = VDA_ScanDevice(1);
    if (ret <= 0)
    {
        printf("No device connect!\r\n");
        return ret;
    }
    // Open device
    ret = VDA_OpenDevice(VDA_USBDAC, 0, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Open device error!\r\n");
        return ret;
    }
    // Initialize DAC_CH0 channel
    ret = VDA_InitDAC(VDA_USBDAC, 0, VDA_DAC_CH0,DAC_Value,256,0);// Cycle can be set to 0 if each channel transfer a byte of data at a time.
    if (ret != ERR_SUCCESS)
    {
        printf("Initialize DAC Channel 0 error!\r\n");
        return ret;
    }else{
        printf("Initialize DAC Channel 0 success!\r\n");
    }
    // Set voltage values of DAC_CH0 
	ret = VDA_StartDAC(VDA_USBDAC, 0,VDA_DAC_CH0);
    if (ret != ERR_SUCCESS)
    {
        printf("Start DAC error!\r\n");
        return ret;
    }else{
        printf("DAC Channel 0 Start Output 400MV");
        printf("\r\n");
    }
	Sleep(100);
	ret = VDA_StopDAC(VDA_USBDAC, 0,VDA_DAC_CH0);
    if (ret != ERR_SUCCESS)
    {
        printf("Stop DAC error!\r\n");
        return ret;
    }else{
        printf("DAC Channel 0 Stop Output");
        printf("\r\n");
    }	
    // Initialize ADC_CH1
    ret = VDA_InitDAC(VDA_USBDAC, 0, VDA_DAC_CH1,DAC_Value,256,0);// Cycle can be set to 0 if each channel transfer a byte of data at a time.
    if (ret != ERR_SUCCESS)
    {
        printf("Initialize DAC Channel 1 error!\r\n");
        return ret;
    }else{
        printf("Initialize DAC Channel 1 success!\r\n");
    }
    // Get voltage values of ADC_CH0 & ADC_CH1(each channel transfer a byte of data at a time.)
	ret = VDA_StartDAC(VDA_USBDAC, 0, VDA_DAC_CH1);
    if (ret != ERR_SUCCESS)
    {
        printf("Start DAC data error!\r\n");
        return ret;
    }
    else
    {
        printf("DAC Channel 1 Start Output 400MV");
		printf("\r\n");
    }
	ret = VDA_StopDAC(VDA_USBDAC, 0,VDA_DAC_CH1);
    if (ret != ERR_SUCCESS)
    {
        printf("Stop DAC data error!\r\n");
        return ret;
    }
    else
    {
        printf("DAC Channel 1 Stop Output");
		printf("\r\n");
    }	
	// Initialize DAC_CH0 & ADC_CH1, each channel sampling interval is set to 1000us
    ret = VDA_InitDAC(VDA_USBDAC, 0, VDA_DAC_CH0 | VDA_DAC_CH1,DAC_Value,256,1000);// Cycle can be set to 0 if each channel transfer a byte of data at a time.
	if (ret != ERR_SUCCESS)
    {
        printf("Initialize DAC error!\r\n");
        return ret;
    }else{
        printf("Initialize DAC Channel 0 and 1 success!\r\n");
    }
	ret = VDA_StartDAC(VDA_USBDAC, 0,VDA_DAC_CH0 | VDA_DAC_CH1);
    if (ret != ERR_SUCCESS)
    {
        printf("Start DAC data error!\r\n");
        return ret;
    }else
    {
        printf("DAC Channel 0 and 1 Start Output 3000MV\r\n");
    }
	ret = VDA_StopDAC(VDA_USBDAC, 0,VDA_DAC_CH0 | VDA_DAC_CH1);
    if (ret != ERR_SUCCESS)
    {
        printf("Stop DAC data error!\r\n");
        return ret;
    }else{
        printf("DAC Channel 0 and 1 Stop Output\r\n");
    }	
    // close device
    ret = VDA_CloseDevice(VDA_USBDAC, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Close device error!\r\n");
        return ret;
    }
	return 0;
}
