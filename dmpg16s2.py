from fractions import Fraction
from decimal import Decimal

n, k, d = map(int, input().split())

ans = 0

for i in range(d + 1):
    cur = int(Decimal(Decimal(n) / Decimal(Decimal(k) ** Decimal(d - i))))
    ans += cur
    n -= cur * k ** (d - i)

print(ans)
