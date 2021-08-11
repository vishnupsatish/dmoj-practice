from fractions import Fraction
import sys

input = sys.stdin.readline

t = int(input())

while t:
    r1, r2, r3 = map(int, input().split())

    denominator = (r2 - r3) * (r2 - r3)

    numerator = 0

    numerator += max(0, (r1 - r3) * (r1 - r3))
    numerator += max(0, ((r2 - r3) * (r2 - r3)) - ((r1 + r3) * (r1 + r3)))

    print(float(Fraction(numerator, denominator)))

    t-=1
