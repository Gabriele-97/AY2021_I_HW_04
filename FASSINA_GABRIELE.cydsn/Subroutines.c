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

#include "Subroutines.h"
#include "InterruptRoutines.h"

int32 value_pot;
int32 value_photo;

/*===============================================================================================
                            FUNCTION GET DATA
    This function is used to read the ADC sampling the potentiometer and the 
    photoresistor. it gets in imput the channel of the MUX each sensor is attached to 
    and returns in output the value sampled. 
    Read32 function is used according to ADC datasheet when the sampling is done in 16 bits.
    A control is added to assure that the values sampled are inside the expected dynamics (0-65535)
    ==============================================================================================*/
    
int32_t getdata(uint8_t channel){
    int32_t value;
    AMux_Select(channel);
    value = ADC_DelSig_Read32();
    if(value > 65535) value = 65535;
    if(value <0) value = 0;
    return value;

}

/* ===================================================================================================
                                FUNCTION LED DRIVER
    This function is intended to control the light intensity of the LED. 
    The light intensity is controlled only in case the user is willing to activate the lamp
    (i.e. startflag =1) while it is switched off as soon as the user does not want to control it anymore.
    The led switches on only in case the room light is smaller than a given threshold defined a priori. 
    This value should be determined according to a specific calibration for the environment of the intended
    use and it was therefore set as a suitable value for my room light.
    The led intensity is set by the user through the potentiometer.
    The variable "intensity" is here used to rescale the 16 bit resolution of the values sampled into 
    8 bits to control the Duty Cycle of the PWM. In this way I can reduce the clock frequency reducing 
    the number of operations the CPU performs (trying to optimize the FW). 
    =================================================================================================== */

void LED_Driver(){
    if(StartFlag){
    if(value_photo <= THRESHOLD_LIGHT){
        intensity = (uint8) (value_pot*M_CALIBRAZIONE);
        PWM_WriteCompare(intensity);
        }  
    else 
        PWM_WriteCompare(OFF);
}
    else PWM_WriteCompare(OFF);

}
    
/* [] END OF FILE */
