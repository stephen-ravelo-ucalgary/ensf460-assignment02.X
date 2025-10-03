#include "TimeDelay.h"

uint16_t TMR2flag;

void delay_ms(uint16_t time_ms) {
    T2CONbits.T32 = 0;
    T2CONbits.TCKPS = 3;
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    T2CONbits.TSIDL = 0;
    
    IPC1bits.T2IP = 2;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;
    
    PR2 = 16 * time_ms;
    TMR2 = 0;
    
    T2CONbits.TON = 1;
    
    Idle();
    
    return;
}

void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void) {
    IFS0bits.T2IF = 0;
    T2CONbits.TON = 0;
    TMR2flag = 1;
}
