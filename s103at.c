#include <avr/pgmspace.h>
#include "s103at.h"

// Table starts at -50, continues in 5 degree increments
// to 110 degrees...
#define TEMP_START -50.0
#define TEMP_INCR  5.0
static const float s103at_table[] PROGMEM = {
    329.5,
    247.7,
    188.5,
    144.1,
    111.3,
    86.43,
    67.77,
    53.41,
    42.47,
    33.90,
    27.28,
    22.05,
    17.96,
    14.69,
    12.09,
    10.00,
    8.313,
    6.940,
    5.827,
    4.911,
    4.160,
    3.536,
    3.020,
    2.588,
    2.228,
    1.924,
    1.668,
    1.451,
    1.266,
    1.108,
    0.9731,
    0.8572,
    0.7576
};

static const uint8_t nentries = sizeof(s103at_table) / sizeof(*s103at_table);


float s103at_temp(float measured) {
    int i;
    float temp = 0.0;
    float last = 0.0;
    for (i=0; i<nentries; i++) {
	float next = pgm_read_float(s103at_table+i);
	if (measured > next) {
	    float b = TEMP_START + (i-1) * TEMP_INCR;
	    float a = TEMP_INCR / (next - last);
	    temp = a * (measured - last) + b;
	    break;
	}
	last = next;
    }
    return temp;
}
