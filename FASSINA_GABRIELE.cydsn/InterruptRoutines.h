/* ========================================
 *
 * Copyright Fassina Gabriele, 2020
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
    #include "Subroutines.h"
        
    #define BYTE_TO_SEND 4 //4 bytes are sent: 2 for each sensor
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1 //bytes + header and tail
    
    
    uint8_t DataBuffer[TRANSMIT_BUFFER_SIZE];
    volatile uint8 PacketReadyFlag;
    volatile uint8 StartFlag;
    extern int32 value_pot;
    extern int32 value_photo;
    
    
    
    CY_ISR_PROTO(Custom_RX_ISR);
    CY_ISR_PROTO(Custom_ADC_ISR);
#endif
/* [] END OF FILE */
