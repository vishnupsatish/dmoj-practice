from math import gcd
from sys import stdin

input = stdin.readline

n = int(input())

def prime_fact(num):
    oth = 0
    two = 0
    five = 0
    i = 2
    while i * i <= num:
        if num % i:
            i += 1
        else:
            num //= i
            if i == 2: two += 1
            elif i == 5: five += 1
            else:
                return 1, 0, 0
    if num == 2: two += 1
    elif num == 5: five += 1
    else: oth += 1
    return oth, two, five


for _ in range(n):
    a, b = map(int, input().split())
    gcf = gcd(a, b)
    a //= gcf
    b //= gcf
    oth, t, f = prime_fact(b)
    if oth == 0:
        print(max(t, f))
    else:
        print(-1)
