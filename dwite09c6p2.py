from math import log2, ceil

for _ in range(5):
    n = int(input())
    if n == 0:
        print(1)
        continue
    low = pow(2, int(log2(n)))
    high = pow(2, ceil(log2(n)))
    if high - n == n - low:
        print(high)
    elif high - n > n - low:
        print(low)
    else:
        print(high)
