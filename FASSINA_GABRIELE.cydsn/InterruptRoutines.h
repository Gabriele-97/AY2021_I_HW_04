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
    
    #define TRANSMIT_BUFFER_SIZE 16
    
    
    char DataBuffer[TRANSMIT_BUFFER_SIZE];
    volatile uint8 PacketReadyFlag;
    int32_t value_pot;
    int32_t value_photo;
    uint8_t intensity;
    
    
    CY_ISR_PROTO(Custom_RX_ISR);
    CY_ISR_PROTO(Custom_ADC_ISR);
#endif
/* [] END OF FILE */
