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

int32 value_pot;
int32 value_photo;

int32_t getdata(uint8_t channel){
    int32_t value;
    ADC_DelSig_StartConvert(); //fai una prova senza questi start e stop e vedi che succede
    AMux_Select(channel);
    value = ADC_DelSig_Read32();
    if(value > 65535) value = 65535;
    if(value <0) value = 0;
    ADC_DelSig_StopConvert();
    return value;

}

void LED_Driver(){
    
    if(value_photo <= THRESHOLD_LIGHT){
        PWM_WriteCompare(value_pot);
        }  
    else 
        PWM_WriteCompare(OFF);
}


/* [] END OF FILE */
