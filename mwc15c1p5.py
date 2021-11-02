# Idea: cheese using pow() in Python, then mod again

a = input().lower()
b = input().lower()

acomp = 0
bcomp = 0

for i, c in enumerate(a):
    no = ord(c) - 96
    acomp += pow(no, i + 1, 10)
    acomp %= 10

for i, c in enumerate(b):
    no = ord(c) - 96
    bcomp += pow(no, i + 1, 10)
    bcomp %= 10

acomp = acomp if acomp != 0 else 10
bcomp = bcomp if bcomp != 0 else 10

print(acomp + bcomp)
