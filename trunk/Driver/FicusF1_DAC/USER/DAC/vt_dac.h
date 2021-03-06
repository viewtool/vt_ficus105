


#ifndef __VT_DAC_H
#define __VT_DAC_H


// Define adapter type
#define VDA_USBDAC		(1)		//device type

// define ADC channel
#define	VDA_DAC_CH0		(1<<0)	// DAC_CH0	
#define	VDA_DAC_CH1		(1<<1)	// DAC_CH1	


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

#define SWD_Debug   0

#if SWD_Debug
#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

struct __FILE { int handle; /* Add whatever needed */ };
FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f){
  if (DEMCR & TRCENA) {
     while (ITM_Port32(0) == 0);
    ITM_Port8(0) = ch;
  }
  return(ch);
}
#else
/*
    *** USE Print()Function Need Init UART1 or UART2 or UART3 Driver
*/
#pragma import(__use_no_semihosting)             
              
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
  
int _sys_exit(int x) 
{ 
	x = x; 
    return 0;
} 

int fputc(int ch, FILE *f)
{ 	
	while((USART1->SR&0X40)==0);
	USART1->DR = (u8) ch;      
	return ch;
}
#endif
// data type of Ginkgo series interface card  
typedef  struct  _VAO_BOARD_INFO{
	uint16_t	dr_Version;			// driver version, hex
	uint16_t	in_Version;			// API version, hex
	uint8_t		adc_num;			// number of ADC channel
	char		str_hw_Name[100];	// name of HW, e.g. ,"Ginkgo-SPI-Adapter"(include '\0?��)
	char		str_fw_Version[100];// version of FW, e.g. "2.0.0" (include '\0?��)
	char		str_hw_Version[100];// version of HW, e.g. ,"2.1.0"(include '\0?��)
	char		str_Serial_Num[100];// adapter serial number
	uint16_t	Reserved[4];		// reserved
} VAO_BOARD_INFO,*PVAO_BOARD_INFO; 

extern int32_t VDA_ScanDevice(uint8_t NeedInit);
extern int32_t VDA_OpenDevice(int32_t DevType,int32_t DevIndex,int32_t Reserved);
extern int32_t VDA_CloseDevice(int32_t DevType,int32_t DevIndex);
extern int32_t VDA_ReadBoardInfo(int32_t DevType,int32_t DevIndex,PVAO_BOARD_INFO pInfo);
extern int32_t VDA_InitDAC(int32_t DevType, int32_t DevIndex,uint8_t Channel,uint16_t *pWaveData,uint16_t WaveDataNum,uint16_t Period);
extern int32_t VDA_StartDAC(int32_t DevType,int32_t DevIndex,uint8_t Channel);
extern int32_t VDA_StopDAC(int32_t DevType,int32_t DevIndex,uint8_t Channel);

#endif

