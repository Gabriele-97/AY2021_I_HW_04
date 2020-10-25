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

uint k=0;
uint8 ch_received;

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
    k++;
    if(k == 10){ //il sampling del photoresistor viene fatto con una frequenza più bassa del potenziometro
    value_photo = getdata(PHOTORESISTOR_CHANNEL);
    k=0;
    }
    // FAI FUNZIONE
    // RIFLETTI SUI TEMPI
    DataBufferPot[1] = value_pot >>8;
    DataBufferPot[2] = value_pot & 0xFF;
    DataBufferPhoto[1] = value_photo >>8;
    DataBufferPhoto[2] = value_photo & 0xFF;
    sprintf(DataBufferPot, "Sample pot: %ld \r\n", value_pot);
    sprintf(DataBufferPhoto, "Sample photo: %ld \r\n", value_pot);
    PacketReadyFlag =1;
    
}
}
/* [] END OF FILE */
