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
    value_pot = getdata(POTENTIOMETER_CHANNEL);
    k++;
    if(k == 10){ //il sampling del photoresistor viene fatto con una frequenza più bassa del potenziometro
    value_photo = getdata(PHOTORESISTOR_CHANNEL);
    k=0;
    }
}
/* [] END OF FILE */
