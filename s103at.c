#include <avr/pgmspace.h>
#include <math.h>
#include "s103at.h"

// Table starts at -50, continues in 5 degree increments
// to 110 degrees...
#define TEMP_START -50.0
#define TEMP_INCR  5.0
static const float s103at_table[] PROGMEM = {
#include "s103at.x"
};

static const uint8_t nentries = sizeof(s103at_table) / sizeof(*s103at_table);


float s103at_temp(float reading) {
    int i;
    float temp = 0.0;
    float last = 0.0;
    float logr = log(reading);
    for (i=0; i<nentries; i++) {
	float next = pgm_read_float(s103at_table+i);
	if (logr > next) {
	    float b = TEMP_START + (i-1) * TEMP_INCR;
	    float a = TEMP_INCR / (next - last);
	    temp = a * (logr - last) + b;
	    break;
	}
	last = next;
    }
    return temp;
}
