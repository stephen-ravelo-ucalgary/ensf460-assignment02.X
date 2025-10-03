#include "IOs.h"
#include "TimeDelay.h"

uint16_t time_elapsed_ms;

void IOinit() {
    TRISBbits.TRISB9 = 0;
    TRISAbits.TRISA6 = 0;
    TRISBbits.TRISB7 = 1;
    TRISBbits.TRISB4 = 1;
    TRISAbits.TRISA4 = 1;
    CNPU2bits.CN23PUE = 1;
    CNPU1bits.CN1PUE = 1;
    CNPU1bits.CN0PUE = 1;
    LATAbits.LATA6 = 1;
}

void IOcheck() 
{
    if (time_elapsed_ms % 1000 == 0)
    {
        LATAbits.LATA6 = 0;
    }
    else if (time_elapsed_ms % 500 == 0)
    {
        LATAbits.LATA6 = 1;
    }
    
    if(PORTBbits.RB7 == 0 && PORTBbits.RB4 == 0) 
    {
    }
    else if (PORTBbits.RB7 == 0) 
    {
        if (time_elapsed_ms % 500 == 0)
        {
            LATBbits.LATB9 = 0;
        }
        else if (time_elapsed_ms % 250 == 0)
        {
            LATBbits.LATB9 = 1;
        }
    }
    else if (PORTBbits.RB4 == 0) {
        if (time_elapsed_ms % 2000 == 0)
        {
            LATBbits.LATB9 = 0;
        }
        else if (time_elapsed_ms % 1000 == 0)
        {
            LATBbits.LATB9 = 1;
        }
    }
    else if (PORTAbits.RA4 == 0) {
        if (time_elapsed_ms % 12000 == 0)
        {
            LATBbits.LATB9 = 0;
        }
        else if (time_elapsed_ms % 6000 == 0)
        {
            LATBbits.LATB9 = 1;
        }
    }
    else
    {
        LATBbits.LATB9 = 0;
    }
    
    delay_ms(1);
    time_elapsed_ms += 1;

    if (time_elapsed_ms >= 12000)
        time_elapsed_ms = 0;
    
    return;
}

void check_time_elapsed() {
    if(time_elapsed_ms >= 500) {
        if(LATAbits.LATA6 == 1) {
            LATAbits.LATA6 = 0;
        }
        else {
            LATAbits.LATA6 = 1;
        }
        time_elapsed_ms = 0;
        
    }
    return;
}