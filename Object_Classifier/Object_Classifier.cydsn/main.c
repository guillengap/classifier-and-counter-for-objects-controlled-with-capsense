// AUTHOR: GUILLERMO PEREZ GUILLEN

#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
     /* Start component */  
    EZI2C_Start();  
    EZI2C_EzI2CSetBuffer1(sizeof(CapSense_dsRam), sizeof(CapSense_dsRam), (uint8 *)&CapSense_dsRam);
    
    CapSense_Start(); 
    CapSense_InitializeAllBaselines();
    CapSense_ScanAllWidgets();
    
    PWM_Start();
    int compare_var = 750;    
    
    for(;;)
    {
        PWM_WriteCompare(compare_var);
        /* Do this only when a scan is done */  
        if(CapSense_NOT_BUSY == CapSense_IsBusy())
        {
            /* Include Tuner */  
            CapSense_RunTuner();
             
            /* Process all widgets */  
            CapSense_ProcessAllWidgets();  

            /* Scan result verification */  

            /* Add any required functionality  based on scanning result */  
            if (CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID))
            {
                for (int i = 1; i <= 1600; i++){  //1600
                    LED_Write(0);    // LED on
                    Pin1_Write(1);
                    Pin2_Write(0);
                    Pin3_Write(1);                
                    Pin4_Write(0);                               
                    CyDelay(2);
                    LED_Write(1);    // LED off
                    Pin1_Write(1);
                    Pin2_Write(0);
                    Pin3_Write(0);                
                    Pin4_Write(1);
                    CyDelay(2);
                    LED_Write(0);    // LED on
                    Pin1_Write(0);
                    Pin2_Write(1);
                    Pin3_Write(0);                
                    Pin4_Write(1);                               
                    CyDelay(2);
                    LED_Write(1);    // LED off
                    Pin1_Write(0);
                    Pin2_Write(1);
                    Pin3_Write(1);                
                    Pin4_Write(0);
                    CyDelay(2);
                }
                
                compare_var = 300;
                PWM_WriteCompare(compare_var);
                CyDelay(1000);
                compare_var = 750;
                PWM_WriteCompare(compare_var);
                CyDelay(1000);
                
                for (int i = 1; i <= 1600; i++){  //1600
                    LED_Write(0);    // LED on
                    Pin1_Write(0);
                    Pin2_Write(1);
                    Pin3_Write(1);                
                    Pin4_Write(0);                               
                    CyDelay(2);
                    LED_Write(1);    // LED off
                    Pin1_Write(0);
                    Pin2_Write(1);
                    Pin3_Write(0);                
                    Pin4_Write(1);
                    CyDelay(2);
                    LED_Write(0);    // LED on
                    Pin1_Write(1);
                    Pin2_Write(0);
                    Pin3_Write(0);                
                    Pin4_Write(1);                               
                    CyDelay(2);
                    LED_Write(1);    // LED off
                    Pin1_Write(1);
                    Pin2_Write(0);
                    Pin3_Write(1);                
                    Pin4_Write(0);
                    CyDelay(2);
                }
            }
            
            else if (CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID))
            {
                for (int i = 1; i <= 1600; i++){  //1600                    
                    LED_Write(0);    // LED on
                    Pin1_Write(0);
                    Pin2_Write(1);
                    Pin3_Write(1);                
                    Pin4_Write(0);                               
                    CyDelay(2);
                    LED_Write(1);    // LED off
                    Pin1_Write(0);
                    Pin2_Write(1);
                    Pin3_Write(0);                
                    Pin4_Write(1);
                    CyDelay(2);
                    LED_Write(0);    // LED on
                    Pin1_Write(1);
                    Pin2_Write(0);
                    Pin3_Write(0);                
                    Pin4_Write(1);                               
                    CyDelay(2);
                    LED_Write(1);    // LED off
                    Pin1_Write(1);
                    Pin2_Write(0);
                    Pin3_Write(1);                
                    Pin4_Write(0);
                    CyDelay(2);
                }
                
                compare_var = 1250;
                PWM_WriteCompare(compare_var);
                CyDelay(1000);
                compare_var = 750;
                PWM_WriteCompare(compare_var);
                CyDelay(1000);
                
                for (int i = 1; i <= 1600; i++){  //1600
                    LED_Write(0);    // LED on
                    Pin1_Write(1);
                    Pin2_Write(0);
                    Pin3_Write(1);                
                    Pin4_Write(0);                               
                    CyDelay(2);
                    LED_Write(1);    // LED off
                    Pin1_Write(1);
                    Pin2_Write(0);
                    Pin3_Write(0);                
                    Pin4_Write(1);
                    CyDelay(2);
                    LED_Write(0);    // LED on
                    Pin1_Write(0);
                    Pin2_Write(1);
                    Pin3_Write(0);                
                    Pin4_Write(1);                               
                    CyDelay(2);
                    LED_Write(1);    // LED off
                    Pin1_Write(0);
                    Pin2_Write(1);
                    Pin3_Write(1);                
                    Pin4_Write(0);
                    CyDelay(2);
                }
            }                     
            else
            {
                LED_Write(1);    // LED off
                Pin1_Write(0);
                Pin2_Write(0);
                Pin3_Write(0);                
                Pin4_Write(0);
                compare_var = 750;
                PWM_WriteCompare(compare_var);                
            }  

            /* Start next scan */  
            CapSense_ScanAllWidgets();  
        } 
    }
}

/* [] END OF FILE */
