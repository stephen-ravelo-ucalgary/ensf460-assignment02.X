#include "IOs.h"
#include "TimeDelay.h"

int time_elapsed_ms;

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

void IOcheck() {
    while (1) {
        delay_ms(10);
        time_elapsed_ms += 10;
        check_time_elapsed();
        if(PORTBbits.RB7 == 0 && PORTBbits.RB4 == 0) {
            LATBbits.LATB9 = 1;
            delay_ms(1);
            time_elapsed_ms += 1;
            check_time_elapsed();
            LATBbits.LATB9 = 0;
            delay_ms(1);
            time_elapsed_ms += 1;
            check_time_elapsed();
        }
        else if (PORTBbits.RB7 == 0) {
            LATBbits.LATB9 = 1;
            delay_ms(250);
            time_elapsed_ms += 250;
            check_time_elapsed();
            LATBbits.LATB9 = 0;
            delay_ms(250);
            time_elapsed_ms += 250;
            check_time_elapsed();
        }
        else if (PORTBbits.RB4 == 0) {
            LATBbits.LATB9 = 1;
            delay_ms(500);
            time_elapsed_ms += 500;
            check_time_elapsed();
            delay_ms(500);
            time_elapsed_ms += 500;
            check_time_elapsed();
            LATBbits.LATB9 = 0;
            delay_ms(500);
            time_elapsed_ms += 500;
            check_time_elapsed();
            delay_ms(500);
            time_elapsed_ms += 500;
            check_time_elapsed();
        }
        else if (PORTAbits.RA4 == 0) {
            LATBbits.LATB9 = 1;
            for(int i = 0; i < 12; i++) {
                delay_ms(500);
                time_elapsed_ms += 500;
                check_time_elapsed();
            }
            LATBbits.LATB9 = 0;
            for(int i = 0; i < 12; i++) {
                delay_ms(500);
                time_elapsed_ms += 500;
                check_time_elapsed();
            }
        }
        else {
            continue;
        }
    }
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