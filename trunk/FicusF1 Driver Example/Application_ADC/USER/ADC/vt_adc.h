

#ifndef __VT_ADC_H_
#define __VT_ADC_H_

#include <stdio.h>
#if 0
#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

struct __FILE { int handle; /* Add whatever needed */ };
FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f) {
  if (DEMCR & TRCENA) {
     while (ITM_Port32(0) == 0);
    ITM_Port8(0) = ch;
  }
  return(ch);
}
#endif
// Define adapter type
#define VAI_USBADC		(1)		//device type

// define ADC channel
#define	VAI_ADC_CH0		(1<<0)	// ADC_CH0	
#define	VAI_ADC_CH1		(1<<1)	// ADC_CH1	
#define	VAI_ADC_CH2		(1<<2)	// ADC_CH2	
#define	VAI_ADC_CH3		(1<<3)	// ADC_CH3	
#define	VAI_ADC_CH4		(1<<4)	// ADC_CH4	
#define	VAI_ADC_CH5		(1<<5)	// ADC_CH5	
#define	VAI_ADC_CH6		(1<<6)	// ADC_CH6	
#define	VAI_ADC_CH7		(1<<7)	// ADC_CH7	
#define	VAI_ADC_ALL		(0xFF)	// ADC_CH_ALL

//General Error Code
#define	ERR_SUCCESS					(0)		// no Error
#define	ERR_PARAMETER_NULL			(-1)	// void pointer 
#define	ERR_INPUT_DATA_TOO_MUCH		(-2)	// too many parameters
#define	ERR_INPUT_DATA_TOO_LESS		(-3)	// too few parameters
#define	ERR_INPUT_DATA_ILLEGALITY	(-4)	// illegal parameter
#define	ERR_USB_WRITE_DATA			(-5)	// USB write data error
#define	ERR_USB_READ_DATA			(-6)	// USB read data error
#define	ERR_READ_NO_DATA			(-7)	// no data return when request data
#define	ERR_OPEN_DEVICE				(-8)	// failed to open device
#define	ERR_CLOSE_DEVICE			(-9)	// failed to close device
#define	ERR_EXECUTE_CMD				(-10)	// the command failed to execute
#define ERR_SELECT_DEVICE			(-11)	// failed to select device
#define	ERR_DEVICE_OPENED			(-12)	// device has open
#define	ERR_DEVICE_NOTOPEN			(-13)	// device not open
#define	ERR_BUFFER_OVERFLOW			(-14)	// buffer overflow
#define	ERR_DEVICE_NOTEXIST			(-15)	// device not exist
#define	ERR_LOAD_KERNELDLL			(-16)	// failed to load KernelDLL
#define ERR_CMD_FAILED				(-17)	// failed to execute command
#define	ERR_BUFFER_CREATE			(-18)	// out of memory

//extern void VT_ReqeuestSetADCInfor(USB_OTG_CORE_HANDLE  *pdev, S_MSG *msg);
//extern void VT_RequestADCRead(USB_OTG_CORE_HANDLE  *pdev, S_MSG *msg);

// data type of Ginkgo series interface card  
typedef  struct  _VAI_BOARD_INFO{
	uint16_t	dr_Version;			// driver version, hex
	uint16_t	in_Version;			// API version, hex
	uint8_t		adc_num;			// number of ADC channel
	char		str_hw_Name[100];	// name of HW, e.g. ,"Ginkgo-SPI-Adapter"(include '\0¡¯)
	char		str_fw_Version[100];// version of FW, e.g. "2.0.0" (include '\0¡¯)
	char		str_hw_Version[100];// version of HW, e.g. ,"2.1.0"(include '\0¡¯)
	char		str_Serial_Num[100];// adapter serial number
	uint16_t	Reserved[4];		// reserved
} VAI_BOARD_INFO,*PVAI_BOARD_INFO; 

extern int32_t VAI_ScanDevice(uint8_t NeedInit);
extern int32_t VAI_OpenDevice(int32_t DevType,int32_t DevIndex,int32_t Reserved);
extern int32_t VAI_CloseDevice(int32_t DevType,int32_t DevIndex);
extern int32_t VAI_ReadBoardInfo(int32_t DevType,int32_t DevIndex,PVAI_BOARD_INFO pInfo);
extern int32_t VAI_InitADC(int32_t DevType, int32_t DevIndex, uint8_t Channel, uint16_t Period);
extern int32_t VAI_ReadDatas(int32_t DevType,int32_t DevIndex,uint16_t DataNum,uint16_t *pData);


#endif
