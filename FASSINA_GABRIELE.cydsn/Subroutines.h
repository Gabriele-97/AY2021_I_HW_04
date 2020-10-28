/* ========================================
 *
 * Copyright Gabriele Fassina, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef __SUBROUTINES_H__
    #define __SUBROUTINES_H__
    
    #include "project.h"
    #define POTENTIOMETER_CHANNEL 0 //channel of AMUX to which the potentiometer is connected
    #define PHOTORESISTOR_CHANNEL 1 //channel of AMUX to which the photoresistor is connected
    #define THRESHOLD_LIGHT 35000 //max "light intensity" (in digit) to let the lamp ON
    #define ON 1
    #define OFF 0
    #define PWM_MAX 255 //max period of PWM
    #define SAMPLE_MAX 65535 //max number of samples got by ADC
    #define M_CALIBRAZIONE PWM_MAX/SAMPLE_MAX //conversion factor from samples to PWM compare values
    
    uint8 intensity;
    
    int32_t getdata(uint8_t channel);
    void LED_Driver();
    
    
        
    
#endif

/* [] END OF FILE */
