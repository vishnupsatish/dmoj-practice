N = int(input())

m = 0

squ = []

for _ in range(N):
    v, p = map(int, input().split())
    m += p
    squ.append((v // 2 + 1, p))

dp = [float('inf')] * (m + 1)
dp[0] = 0

for v, p in squ:
    for i in range(m, p - 1, -1):
        dp[i] = min(dp[i], dp[i - p] + v)

print(min(dp[m // 2 + 1:]))
