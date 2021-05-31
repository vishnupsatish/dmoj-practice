N = int(input())

S = list(input())

A = list(map(int, input().split()))

T = list(input())

B = list(map(int, input().split()))

dp = [[0] * (N + 1) for _ in range(N + 1)]

for i, g1 in enumerate(A):
    w1 = S[i]
    for j, g2 in enumerate(B):
        w2 = T[j]
        if (w1 == 'W' and w2 == 'L' and g1 > g2) or (w1 == 'L' and w2 == 'W' and g2 > g1):
            dp[i + 1][j + 1] = max(dp[i][j] + g1 + g2, dp[i][j + 1], dp[i + 1][j])
        else:
            dp[i + 1][j + 1] = max(dp[i][j], dp[i][j + 1], dp[i + 1][j])

print(dp[N][N])
