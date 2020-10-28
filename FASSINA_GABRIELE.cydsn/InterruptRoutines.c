/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "InterruptRoutines.h"


uint8 ch_received;
int32 value_pot;
int32 value_photo;

CY_ISR(Custom_RX_ISR){
    
    ch_received = UART_GetChar();
    switch (ch_received){
        case 'b':
        case 'B':
            StartFlag =1;
            Pin_LED_STATO_Write(ON);    
            Timer_Start();
            break;
        
        case 's':
        case 'S':
            StartFlag = 0;
            Pin_LED_STATO_Write(OFF);
            Timer_Stop();
            break;
            
        default:
            break;            
        
    }
    
}


CY_ISR(Custom_ADC_ISR){
    if(StartFlag){
    Timer_ReadStatusRegister();
    value_pot = getdata(POTENTIOMETER_CHANNEL);
    value_photo = getdata(PHOTORESISTOR_CHANNEL);
    
    DataBuffer[1] = value_pot>>8;
    DataBuffer[2] = value_pot & 0xFF;
    DataBuffer[3] = value_photo>>8;
    DataBuffer[4] = value_photo & 0xFF;
    
    PacketReadyFlag =1;
    
}
}
/* [] END OF FILE */
