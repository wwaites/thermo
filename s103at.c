#include <avr/pgmspace.h>
#include <math.h>
#include "s103at.h"
#include <stdio.h>

// Table starts at -50, continues in 5 degree increments
// to 110 degrees...
#define TEMP_START -50.0
#define TEMP_INCR  5.0
static const int s103at_table[] PROGMEM = {
#include "s103at.x"
};

static const uint8_t nentries = sizeof(s103at_table) / sizeof(*s103at_table);


float s103at_temp(float reading) {
    int i;
    int last = 0.0;
    int logr = (int)(log(reading) * 1000);
    float temp = 0.0;
    for (i=0; i<nentries; i++) {
	int next = pgm_read_word(s103at_table+i);
	if (logr > next) {
	    float b = TEMP_START + (i-1) * TEMP_INCR;
	    float a = TEMP_INCR / (next - last);
	    temp = a * (float)(logr - last) + b;
	    break;
	}
	last = next;
    }
    return temp;
}
