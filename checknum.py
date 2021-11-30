from math import sqrt, ceil
from sys import stdin

# Apparently sqrt shouldn't pass

input = stdin.readline

n = int(input())

for e in range(n):
    a = int(input())
    squ = int(sqrt(a))
    req_from_squ = ceil(squ / 9)
    rem = a - squ * squ
    if (ceil(rem / 9)) > req_from_squ:
        print(ceil(rem / 9)*2)
    elif (ceil(rem / 9)) == req_from_squ:
        print(req_from_squ*2)
    else:
        print(req_from_squ*2-1)
