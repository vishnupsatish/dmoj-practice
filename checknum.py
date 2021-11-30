from math import sqrt, ceil
from sys import stdin

input = stdin.readline

n = int(input())

for e in range(n):
    a = int(input())

    l = 0
    r = 1000000003
    
    # Binary search for sqrt
    while l < r:
        mid = (l + r) // 2
        if mid * mid > a:
            r = mid
        else:
            l = mid + 1
    squ = l-1

    req_from_squ = ceil(squ / 9)
    rem = a - squ * squ
    if (ceil(rem / 9)) > req_from_squ:
        print(ceil(rem / 9)*2)
    elif (ceil(rem / 9)) == req_from_squ:
        print(req_from_squ*2)
    else:
        print(req_from_squ*2-1)
