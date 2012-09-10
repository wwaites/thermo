import fileinput
from sys import argv
from math import log, e

for line in fileinput.input(argv[1]):
    temp, res = line.strip().split("\t")
    print "%s\t%s\t%.04f" % (temp, res, log(float(res), e))
