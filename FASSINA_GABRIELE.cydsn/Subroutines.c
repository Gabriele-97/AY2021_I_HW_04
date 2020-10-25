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

#include "Subroutines.h"


int32_t getdata(uint8_t channel){
    int32_t value;
    
    AMux_FastSelect(channel);
    value = ADC_DelSig_Read32();
    return value;

}

/* [] END OF FILE */
