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

#ifndef __SUBROUTINES_H__
    #define __SUBROUTINES_H__
    
    #include "project.h"
    #define POTENTIOMETER_CHANNEL 0
    #define PHOTORESISTOR_CHANNEL 1
    #define THRESHOLD_LIGHT 1000 //numero messo a caso, bisogna capire quanto sia
    #define ON 1
    #define OFF 0
    
    
    int32_t getdata(uint8_t channel);
    
    void LED_Driver();
    
#endif

/* [] END OF FILE */
