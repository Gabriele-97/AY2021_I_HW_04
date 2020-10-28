/* ========================================
 *
 * Copyright Gabriele Fassina, 2020
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

/* ==================================================================================================
                            UART RECEIVE INTERRUPT
    This interrupt activates when a new character is received by the UART
    the variable is saved in the ch_received and different operations are done based on the received 
    if it is b or B the lamp control is enabled and the state LED is turned on;
    if it is s or S the lamp control is disabled and the state LED is turned off 
    (also the lamp led is turned off in the driver function);
    if it is any other character, nothing occurs
    ==================================================================================================*/

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
/* ==================================================================================================
                                         ADC INTERRUPT
    This interrupt activates when the Timer dedicated to ADC gets to zero. 
    the value of the potentiometer and photoresistor are acquired in series and they are "immediately" 
    inserted in the DataBuffer so that also the values transmitted will be real time. 
    when the new values are acquired the PacketReadyFlag set to 1 enables the UART transmission
    ==================================================================================================*/

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
