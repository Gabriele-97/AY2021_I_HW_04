/* ========================================
 *
 * Copyright GABRIELE FASSINA, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "InterruptRoutines.h"
#include "Subroutines.h"

int main(void)
{
    /*===============================================================================
                    FUNCTION ACTIVATION AND INITIALIZATIONS
    in this first part of the main, peripherals are activated (ADC, UART and PWM), 
    Interrupts are started and the header and tail of the data buffer 
    (needed to transmit the information via control panel) are set 
    ==================================================================================*/ 
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_DelSig_Start(); 
    UART_Start(); 
    PWM_Start();
    isr_ADC_StartEx(Custom_ADC_ISR);
    isr_Rx_StartEx(Custom_RX_ISR);
    DataBuffer[0] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    PacketReadyFlag = 0;
    
    /*===============================================================================
                                            MAIN BODY
    The infinite cycle for just performs the LED driving through the specific function implemented
    and it sends the values of the potentiometer and of the photoresistor that have been put
    in the DataBuffer when new values are received. 
    RMK: the control on packetreadyflag means that nothing will be communicated 
    when the sampling system is not enabled because this flag will never become 1 anymore. 
    ==================================================================================*/ 
       
    for(;;)
    {
        LED_Driver(); 
        if(PacketReadyFlag == 1){
            UART_PutArray(DataBuffer, TRANSMIT_BUFFER_SIZE);
            PacketReadyFlag = 0;
        } 
        
    }
}

/* [] END OF FILE */
