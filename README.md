Semitec 103AT-II
================

The 103AT-II is a [thermisistor] made by [ATC Semitec]. It
can be read with a simple voltage divider circuit:

![Sensor Circuit](https://github.com/wwaites/thermo/blob/master/thermo-sensor.png?raw=true)

The example application has this hooked onto analogue input
port A1 on an [Arduino] board and simply reads the temperature
every second and writes it out the serial port.

The calibration [values] are extracted from the [datasheet].

[ATC Semitec]: http://www.atcsemitec.co.uk/
[thermisistor]: http://www.atcsemitec.co.uk/at_thermistors.html
[values]: semitec-103at.tsv
[datasheet]: http://www.atcsemitec.co.uk/pdfdocs/103at-11_thermistors.pdf
