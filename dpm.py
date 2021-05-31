N, K = map(int, input().split())

m = 1000000007

cand = list(map(int, input().split()))
cand.insert(0, 0)

psa = []

dp = [[0] * (K + 2) for _ in range(N + 1)]

dp[0][0] = 1

for i in range(1, N + 1):
    psa = [dp[i - 1][0]]
    for j in range(1, K + 1):
        psa.append((psa[j - 1] + dp[i - 1][j]) % m)
    for j in range(K + 1):
        if j <= cand[i]:
            dp[i][j] = psa[j]
        else:
            rm = j - cand[i] - 1
            dp[i][j] = (psa[j] - psa[rm]) % m

print(dp[N][K])
