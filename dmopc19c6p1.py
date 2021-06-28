from fractions import Fraction

one = list(map(int, input().split()))
two = list(map(int, input().split()))

s1 = 0
s2 = 0
yint1 = 0
yint2 = 0

try:
    x1, y1, x2, y2 = one
    s1 = Fraction(y2 - y1, x2 - x1)
    yint1 = y2 - s1 * x2
except ZeroDivisionError:
    s1 = 'undefined'
    yint1 = one[0]

try:
    x1, y1, x2, y2 = two
    s2 = Fraction(y2 - y1, x2 - x1)
    yint2 = y2 - s2 * x2
except ZeroDivisionError:
    s2 = 'undefined'
    yint2 = two[0]

if s1 == s2 and yint1 == yint2:
    print('coincident')
elif s1 == s2:
    print('parallel')
else:
    if s1 == 'undefined':
        print(round(float(yint1), 5), round(float(yint1 * s2 + yint2), 5))
    elif s2 == 'undefined':
        print(round(float(yint2), 5), round(float(yint2 * s1 + yint1), 5))
    else:
        step1 = yint1 - yint2
        step2 = s2 - s1
        print(round(float(Fraction(step1, step2)), 5), float(round(float(s1 * Fraction(step1, step2) + yint1), 5)))
