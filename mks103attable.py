import fileinput
from sys import argv

def logs(filename):
    for line in fileinput.input(filename):
        _, _, l = line.strip().split("\t")
        yield int(float(l) * 1000)

print ",\n".join("\t%s" % l for l in logs(argv[1]))
