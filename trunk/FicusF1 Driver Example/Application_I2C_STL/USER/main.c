  /*
  ******************************************************************************
  * @file     : USB_I2C_AT24C02_SCTL.cpp
  * @Copyright: ViewTool 
  * @Revision : ver 1.0
  * @Date     : 2014/12/19 11:00
  * @brief    : USB_I2C_AT24C02_SCTL demo
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
  Software Connection  (This is for your reference only)
  AT24C02        Ginkgo USB-I2C Adapter
  I2C_SCL0  GPIO_PortB_Pin5
  I2C_SDA0  GPIO_PortB_Pin6
  I2C_SCL1  GPIO_PortB_Pin7
  I2C_SDA1  GPIO_PortB_Pin8
  I2C_SCL2  GPIO_PortB_Pin9
  I2C_SDA2  GPIO_PortB_Pin10
  I2C_SCL3  GPIO_PortB_Pin11
  I2C_SDA3  GPIO_PortB_Pin12
  I2C_SCL4  GPIO_PortA_Pin0
  I2C_SDA4  GPIO_PortA_Pin1
  I2C_SCL5  GPIO_PortA_Pin2
  I2C_SDA5  GPIO_PortA_Pin3
  I2C_SCL6  GPIO_PortA_Pin4
  I2C_SDA6  GPIO_PortA_Pin5
  I2C_SCL7  GPIO_PortA_Pin6
  I2C_SDA7  GPIO_PortA_Pin7
  */

#ifdef WINAPI
#include "stdafx.h"
#include "ControlI2C.h"
#else
#include "stm32f10x_conf.h"
#include "vt_i2c.h"
#endif
int main(int argc, char* argv[])
{
	int ret = 0,i;
    uint8_t I2C_Index = 7;
	VII_INIT_CONFIG I2C_Config;
	VII_TIME_CONFIG I2C_TimeConfig;
	uint8_t write_buffer[8]={0};
	uint8_t	read_buffer[8]={0};
	//Scan device
	ret = VII_ScanDevice(1);
	if(ret <= 0)
	{
		printf("No device connect!\r\n");
		return ret;
	}
    //Open device
    ret = VII_OpenDevice(VII_USBI2C, 0, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Open device error!\r\n");
        return ret;
    }
    //Initializes the device
    I2C_Config.AddrType = VII_ADDR_7BIT;
    I2C_Config.ClockSpeed = 400000;
    I2C_Config.ControlMode = VII_SCTL_MODE;
    I2C_Config.MasterMode = VII_MASTER;
    I2C_Config.SubAddrWidth = VII_SUB_ADDR_1BYTE;
    ret = VII_InitI2C(VII_USBI2C, 0,I2C_Index, &I2C_Config);
    if (ret != ERR_SUCCESS)
    {
        printf("Initialize device error!\r\n");
        return ret;
    }
    //Config timing,Unit of time for microseconds
    I2C_TimeConfig.tSU_STA = 5;
    I2C_TimeConfig.tHD_STA = 4;
    I2C_TimeConfig.tLOW = 5; 
    I2C_TimeConfig.tHIGH = 5;
    I2C_TimeConfig.tSU_DAT = 1;
    I2C_TimeConfig.tSU_STO = 4;
    I2C_TimeConfig.tBuf = 5;  
    ret = VII_TimeConfig(VII_USBI2C, 0, I2C_Index, &I2C_TimeConfig);
    if (ret != ERR_SUCCESS)
    {
        printf("Set time error!\r\n");
        return ret;
    }
	//Write 8 byte data to 0x00
	for (i = 0; i < 8; i++)
    {
        write_buffer[i] = i;
    }
    ret = VII_WriteBytes(VII_USBI2C, 0, I2C_Index, 0xA0, 0x00, write_buffer, 8);
    if (ret != ERR_SUCCESS)
    {
        printf("Write data error!\r\n");
        return ret;
    }
    //Delay
    Sleep(10);
	//Read 8 byte data from 0x00
    ret = VII_ReadBytes(VII_USBI2C, 0, I2C_Index, 0xA0, 0x00, read_buffer, 8);
    if (ret != ERR_SUCCESS)
    {
        printf("Read data error!\r\n");
        return ret;
    }
	else
	{
		printf("Read Data:\r\n");
		for(i=0;i<8;i++)
		{
			printf("%02X ",read_buffer[i]);
		}	
		printf("\r\n");
		Sleep(1);
	}
	return 0;
}

