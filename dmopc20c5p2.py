from decimal import Decimal

from math import gcd, ceil

N, M = map(int, input().split())

print(N + M - gcd(N, M))

for i in range(1, M + 1):
    end = (N * i)//M + 1 if (N * i)//M != (N * i)/M else (N * i)//M
    # print((N * i)//M + 1, end + 1)

    for j in range((N * (i - 1))//M + 1, end + 1):
        print(j, i)
