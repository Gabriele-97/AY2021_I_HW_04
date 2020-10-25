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
    DataBufferPot[0] = 0xA0;
    DataBufferPhoto[0]= 0xA0;
    DataBufferPot[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    DataBufferPhoto[TRANSMIT_BUFFER_SIZE-1] = 0XC0;
    PacketReadyFlag = 0;
    ADC_DelSig_StartConvert();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
        
    for(;;)
    {
        if(PacketReadyFlag == 1){
            UART_PutArray(DataBufferPot, TRANSMIT_BUFFER_SIZE);
            UART_PutArray(DataBufferPhoto,TRANSMIT_BUFFER_SIZE);
            PacketReadyFlag = 0;
        }
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
