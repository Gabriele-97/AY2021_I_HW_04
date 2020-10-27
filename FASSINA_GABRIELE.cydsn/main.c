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
#include "project.h"
#include "InterruptRoutines.h"
#include "Subroutines.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_DelSig_Start();
    UART_Start();
    isr_ADC_StartEx(Custom_ADC_ISR);
    isr_Rx_StartEx(Custom_RX_ISR);
    DataBuffer[0] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    PacketReadyFlag = 0;
    ADC_DelSig_StartConvert();
    PWM_Start();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
        
    for(;;)
    {
        LED_Driver();
        if(PacketReadyFlag == 1){
            UART_PutArray(DataBuffer, TRANSMIT_BUFFER_SIZE);
            PacketReadyFlag = 0;
        }
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
