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
    #include "Subroutines.h"
    #include "math.h"
    
    #define BYTE_TO_SEND 2
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1
    
    
    char DataBufferPot[TRANSMIT_BUFFER_SIZE];
    char DataBufferPhoto[TRANSMIT_BUFFER_SIZE];
    volatile uint8 PacketReadyFlag;
    volatile uint8 StartFlag;
    int32 value_pot;
    int32 value_photo;
    uint8_t intensity;
    
    
    CY_ISR_PROTO(Custom_RX_ISR);
    CY_ISR_PROTO(Custom_ADC_ISR);
#endif
/* [] END OF FILE */
