import sys
import os.path
import os

os.system("clear")
gene = raw_input("Enter gene: ")
if not os.path.exists("%s.txt"%gene):
    print "There must be a file '[gene].txt' in the current directory"
    sys.exit()

flag = 0
mut = raw_input("Enter mutation location: ")
mut_loc = int(mut)
start = mut_loc - 25
if start < 0:
    start = 0
    flag = abs(mut_loc-25)

f = open("%s.txt"%gene, "r")
f.seek(start,0)
if start == 0:
    str = "\n" + f.read(mut_loc-16) + "   " + f.read(15) + " "+ f.read(1) + " "+ f.read(10) + "  " + f.read(14) + "\n"
else:
    str = "\n" + f.read(10) + "  " + f.read(14) + " " + f.read(1) + " " + f.read(15) + "  " + f.read(10) + "\n"

print str.upper()

