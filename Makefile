BOARD := uno
LINKFLAGSEXTRA := -Wl,-u,vfprintf -lprintf_flt -lm
include arduino.mk

semitec-103at-log.tsv: semitec-103at.tsv
	python logarithmize.py $< > $@

s103at.x: semitec-103at-log.tsv
	python mks103attable.py $< > $@