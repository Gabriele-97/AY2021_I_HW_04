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
int32_t value_pot;
int32_t value_photo;
uint k=0;

CY_ISR(Custom_RX_ISR){
    
}


CY_ISR(Custom_ADC_ISR){
    Timer_ReadStatusRegister();
    AMux_FastSelect(POTENTIOMETER_CHANNEL);
    value_pot = ADC_DelSig_Read32();
    k++;
    if(k == 10){ //il sampling del photoresistor viene fatto con una frequenza più bassa del potenziometro
    AMux_FastSelect(PHOTORESISTOR_CHANNEL);
    value_photo = ADC_DelSig_Read32();
    k=0;
    }
}
/* [] END OF FILE */
