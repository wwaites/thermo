#include <stdio.h>
#include "s103at.h"
#include "stdserial.h"

#define R1 26.5

// 5 = A0 * 5 / 1024 * (TR + R1) / R1
// 1024 * R1 / A0 - R1

void setup() {
    tty_init();
    pinMode(A1, INPUT);
}

void loop() {
    int reading = analogRead(A1);
    float R = 1024 * (R1 / reading) - R1;
    printf("\r\n");
    printf("Reading: %.04f\r\n", R);
    printf("Temp: %.02f\r\n", s103at_temp(R));
    delay(1000);
}
