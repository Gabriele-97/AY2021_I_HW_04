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
#include "InterruptRoutines.h"

int32_t getdata(uint8_t channel){
    int32_t value;
    AMux_FastSelect(channel);
    value = ADC_DelSig_Read32();
    return value;

}

void LED_Driver(){
    if (value_pot >= THRESHOLD_LIGHT)
        Pin_LED_Write(OFF);
        
    else{
        Pin_LED_Write(ON);
        intensity =floor(M_CALIBRAZIONE*value_pot); //uso la funzione floor per arrotondare
        PWM_WriteCompare(intensity);
        }     
}


/* [] END OF FILE */
