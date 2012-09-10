BOARD := uno
LINKFLAGSEXTRA := -Wl,-u,vfprintf -lprintf_flt -lm
include arduino.mk

semitec-103at-log.tsv: semitec-103at.tsv
	python logarithmize.py $< > $@

s103at.x: semitec-103at-log.tsv
	python mks103attable.py $< > $@

semitec-103at.png: semitec-103at-log.tsv semitec-103at.plt
	gnuplot semitec-103at.plt

semitec-103at-log.png: semitec-103at-log.tsv semitec-103at.plt
	gnuplot semitec-103at.plt

