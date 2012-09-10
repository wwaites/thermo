Semitec 103AT-II
================

The 103AT-II is a [thermisistor] made by [ATC Semitec]. It
can be read with a simple voltage divider circuit:

![Sensor Circuit](https://github.com/wwaites/thermo/blob/master/thermo-sensor.png?raw=true)

The example application has this hooked onto analogue input
port A1 on an [Arduino] board and simply reads the temperature
every second and writes it out the serial port.

The value of R1 is chosen so that the voltage read on the 
analogue pin should vary from about 2 and 4 V
when the temperature is between -10 and 40 °C.

The calibration [values] are extracted from the [datasheet].
The resistance versus temperature relationship is approximately
logarithmic.

![Resistance vs. Temperature](https://github.com/wwaites/thermo/blob/master/semitec-103at.png?raw=true)
![Log-Resistance vs. Temperature](https://github.com/wwaites/thermo/blob/master/semitec-103at-log.png?raw=true)

The software routine in the library, 

    float s103at_temp(float resistance);

takes the natural logarithm of the parameter and then does
linear interpolation against a pre-computed table of logarithms
of expected resistances. The table is stored as 16 bit words
(multiplied by 1000) to save on program space for the table
-- 66 bytes in place of 132.


[ATC Semitec]: http://www.atcsemitec.co.uk/
[thermisistor]: http://www.atcsemitec.co.uk/at_thermistors.html
[values]: semitec-103at.tsv
[datasheet]: http://www.atcsemitec.co.uk/pdfdocs/103at-11_thermistors.pdf
