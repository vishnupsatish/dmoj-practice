s1 = input()

s2 = 'abcdefghijklmnopqrstuvwxyz'

N = len(s1)
M = len(s2)

dp = [[0] * (M + 1) for _ in range(N + 1)]

for m in range(1, N + 1):
    for n in range(1, M + 1):
        if s1[m - 1] == s2[n - 1]:
            dp[m][n] = dp[m - 1][n - 1] + 1
        else:
            dp[m][n] = max(dp[m - 1][n], dp[m][n - 1])

print(26 - dp[N][M])
