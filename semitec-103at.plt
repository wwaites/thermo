set terminal png
set output "semitec-103at.png"
set ylabel "R (kΩ)"
set xlabel "T (°C)"
plot "semitec-103at-log.tsv" using 1:2 with lines \
    title "Resistance vs. Temperature"
set output "semitec-103at-log.png"
set ylabel "ln(R) (kΩ)"
plot "semitec-103at-log.tsv" using 1:3 with lines \
    title "Resistance vs. Temperature"