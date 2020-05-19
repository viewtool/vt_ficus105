  /*
  ******************************************************************************
  * @file     : Ficus_GPIO_Test.cpp
  * @Copyright: ViewTool 
  * @Revision : ver 1.0
  * @Date     : 2019/10/23 
  * @brief    : Ficus_GPIO_Test demo
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
#include "ControlGPIO.h"
#else
#include <stdio.h>
#include "stm32f10x_conf.h"
#include "vt_gpio.h"
#include "func_map.h"
#endif
uint32_t num[]={
J15_P1_GPIO,J15_P2_GPIO,J15_P3_GPIO,J15_P4_GPIO,
J15_P5_GPIO,J15_P6_GPIO,J15_P7_GPIO,J15_P8_GPIO,
J15_P9_GPIO,J15_P10_GPIO,J15_P11_GPIO,

J2_P1_GPIO,J2_P2_GPIO,J2_P3_GPIO,J2_P4_GPIO,
J2_P5_GPIO,J2_P6_GPIO,J2_P7_GPIO,J2_P8_GPIO,
J2_P9_GPIO,J2_P10_GPIO,J2_P11_GPIO,J2_P12_GPIO,
J2_P13_GPIO,J2_P14_GPIO,J2_P15_GPIO,J2_P16_GPIO,
J2_P17_GPIO,J2_P18_GPIO,J2_P19_GPIO,J2_P20_GPIO,

J6_P1_GPIO,J6_P2_GPIO,J1_P1_GPIO,J1_P2_GPIO,
J4_P1_GPIO,J4_P2_GPIO,

J8_P1_GPIO,J8_P2_GPIO,J8_P3_GPIO,J8_P4_GPIO,
J8_P5_GPIO,J8_P6_GPIO,J8_P7_GPIO,J8_P8_GPIO,

J18_P1_GPIO,J18_P2_GPIO,J18_P3_GPIO,J18_P4_GPIO,
J18_P5_GPIO,J18_P6_GPIO,
J7_P1_GPIO,

J50_P1_GPIO,J50_P3_GPIO,J50_P4_GPIO,J50_P5_GPIO,
J50_P6_GPIO,J50_P7_GPIO,J50_P8_GPIO,J50_P9_GPIO,
J50_P10_GPIO,J50_P11_GPIO,J50_P12_GPIO,J50_P13_GPIO,
J50_P14_GPIO,J50_P15_GPIO,J50_P16_GPIO,

J28_P1_GPIO,J28_P2_GPIO,J28_P3_GPIO,J28_P4_GPIO,
J28_P5_GPIO,J28_P6_GPIO,J33_P1_GPIO,

J5_P1_GPIO,J5_P2_GPIO,J5_P3_GPIO,J5_P4_GPIO,
J5_P5_GPIO,J5_P6_GPIO,J5_P7_GPIO,J5_P8_GPIO,

J17_P1_GPIO,J17_P2_GPIO,J17_P3_GPIO,J17_P4_GPIO,
J17_P5_GPIO,J17_P6_GPIO,J17_P7_GPIO,

J45_GPIO,J46_GPIO,J47_GPIO,J48_GPIO,

J19_P1_GPIO,J19_P2_GPIO,J19_P3_GPIO,J19_P4_GPIO,
J19_P5_GPIO,J19_P6_GPIO,J19_P7_GPIO,J19_P8_GPIO,
J19_P9_GPIO,J19_P10_GPIO,J19_P11_GPIO,J19_P12_GPIO,
J19_P13_GPIO,J19_P14_GPIO,J19_P15_GPIO,J19_P16_GPIO,

J20_P1_GPIO,J20_P2_GPIO,J20_P3_GPIO,J20_P4_GPIO,
J20_P5_GPIO,J20_P6_GPIO,J20_P7_GPIO,J20_P8_GPIO,
J20_P9_GPIO,J20_P10_GPIO,J20_P11_GPIO,J20_P12_GPIO,
J20_P13_GPIO,J20_P14_GPIO,J20_P15_GPIO,J20_P16_GPIO,
J20_P17_GPIO,J20_P18_GPIO,J20_P19_GPIO,J20_P20_GPIO,
J20_P21_GPIO,

J21_P1_GPIO ,J21_P2_GPIO ,J21_P3_GPIO ,J21_P4_GPIO,
J21_P5_GPIO ,J21_P6_GPIO ,J21_P7_GPIO ,J21_P8_GPIO,
J21_P9_GPIO ,J21_P10_GPIO,J21_P11_GPIO,J21_P12_GPIO,
J21_P13_GPIO,J21_P14_GPIO,J21_P15_GPIO,J21_P16_GPIO,
J21_P17_GPIO,J21_P18_GPIO,J21_P19_GPIO,J21_P20_GPIO,
J21_P21_GPIO,J21_P22_GPIO,

J22_P1_GPIO ,J22_P2_GPIO ,J22_P3_GPIO ,J22_P4_GPIO,
J22_P5_GPIO ,J22_P6_GPIO ,J22_P7_GPIO ,J22_P8_GPIO,
J22_P9_GPIO ,J22_P10_GPIO,J22_P11_GPIO,J22_P12_GPIO,
J22_P13_GPIO,J22_P14_GPIO,J22_P15_GPIO,J22_P16_GPIO,
J22_P17_GPIO,J22_P18_GPIO,

J14_P1_GPIO ,J14_P2_GPIO ,J14_P3_GPIO ,J14_P4_GPIO,
J14_P5_GPIO ,J14_P6_GPIO ,J14_P7_GPIO ,J14_P8_GPIO,
J14_P9_GPIO ,J14_P10_GPIO,J14_P11_GPIO,

J11_P1_GPIO ,J11_P2_GPIO ,J11_P3_GPIO ,J11_P4_GPIO,
J11_P5_GPIO ,J11_P6_GPIO ,J11_P7_GPIO ,J11_P8_GPIO,
J11_P9_GPIO ,J11_P10_GPIO,J11_P11_GPIO,J11_P12_GPIO,
J11_P13_GPIO,J11_P14_GPIO,J11_P15_GPIO,J11_P16_GPIO,
J11_P17_GPIO,J11_P18_GPIO,J11_P19_GPIO,J11_P20_GPIO,
J11_P21_GPIO,J11_P22_GPIO,J11_P23_GPIO,J11_P24_GPIO,
J11_P25_GPIO,J11_P26_GPIO,

J42_GPIO,J43_GPIO,J44_GPIO,
};
int main(int argc, char* argv[])
{
    uint16_t pin_value = 0, j = 0;
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
    for(j=0;j<sizeof(num)-1;j++)
    {
        // Set GPIOA_0 and GPIOA_1 to output 
        ret = VGI_SetOutputEx(VGI_USBGPIO, 0, num[j]);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin output error!\r\n");
            return ret;
        }
        // Set GPIOA_0 and GPIOA_1 
        ret = VGI_SetPinsEx(VGI_USBGPIO, 0,  num[j]);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin high error!\r\n");
            return ret;
        }
        // Reset GPIOA_0 and GPIOA_1 
        ret = VGI_ResetPinsEx(VGI_USBGPIO, 0, num[j]);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin low error!\r\n");
            return ret;
        }
        // Set GPIOA_4 and GPIOA_5 to input 
        ret = VGI_SetInputEx(VGI_USBGPIO, 0, num[j]);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin input error!\r\n");
            return ret;
        }
        // Read GPIOA_4 and GPIOA_5 Data 
        ret = VGI_ReadDatasEx(VGI_USBGPIO, 0,num[j], &pin_value);
        if (ret != ERR_SUCCESS)
        {
            printf("Get pin data error!\r\n");
            return ret;
        }
        else
        {
            if ((pin_value & num[j]) != 0)
            {
                printf("GPIO is high-level!\r\n");
            }
            else
            {
                printf("GPIO is low-level!\r\n");
            }
            if ((pin_value & num[j]) != 0)
            {
                printf("GPIO is high-level!\r\n");
            }
            else
            {
                printf("GPIO is low-level!\r\n");
            }
        }
        ret = VGI_SetOpenDrain(VGI_USBGPIO, 0, num[j]);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin open drain error!\r\n");
            return ret;
        }
        
        ret = VGI_SetPins(VGI_USBGPIO, 0,num[j]);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin high error!\r\n");
            return ret;
        }
        ret = VGI_ResetPins(VGI_USBGPIO, 0, num[j]);
        if (ret != ERR_SUCCESS)
        {
            printf("Set pin high error!\r\n");
            return ret;
        }
        ret = VGI_ReadDatas(VGI_USBGPIO, 0,num[j], &pin_value);
        if (ret != ERR_SUCCESS)
        {
            printf("Get pin data error!\r\n");
            return ret;
        }
        else
        {
            if ((pin_value & num[j]) != 0)
            {
                printf("GPIO is high-level!\r\n");
            }
            else
            {
                printf("GPIO is low-level!\r\n");
            }
            if ((pin_value & num[j]) != 0)
            {
                printf("GPIO is high-level!\r\n");
            }
            else
            {
                printf("GPIO is low-level!\r\n");
            }
        }    
    }
    //Close Device 
    ret = VGI_CloseDevice(VGI_USBGPIO, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Close device error!\r\n");
        return ret;
    }
	return 0;
}


