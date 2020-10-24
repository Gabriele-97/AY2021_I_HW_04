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
#ifndef _INTERRUPT_ROUTINES_H_
    // Header guard
    #define _INTERRUPT_ROUTINES_H_
    
    #include "project.h"
    #include "cytypes.h"
    #include "stdio.h"
    
    #define TRANSMIT_BUFFER_SIZE 16
    #define POTENTIOMETER_CHANNEL 0
    #define PHOTORESISTOR_CHANNEL 1
    
    char DataBuffer[TRANSMIT_BUFFER_SIZE];
    volatile uint8 PacketReadyFlag;
    
    CY_ISR_PROTO(Custom_RX_ISR);
    CY_ISR_PROTO(Custom_ADC_ISR);
#endif
/* [] END OF FILE */
