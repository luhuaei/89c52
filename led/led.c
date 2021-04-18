#include <8052.h>

void delay(int i) {
        while(i--) {
                /* spend 2ms */
                TMOD = 0x01;    /* time mode register */

                TH0 = 0xF8;     /* timer high byte */
                TL0 = 0xCC;     /* timer low byte */

                TR0 = 1;        /* the 1th timer run */
                while(!TF0);    /* the 1th timer overflow */
                TR0 = 0;        /* the 1th timer stop */
                TF0 = 0;        /*  */
        }
}

void carousel() {
        while(1) {
                for (int i=0; i < 8; i++) {
                        /*
                           0 is light, 1 is the off, ~ make the all 0 bit to 1
                        */
                        P2=~(0x01<<i);
                        delay(5000);
                };
        };
}

void main() {
        carousel();
}
