t = int(input())

for _ in range(t):
    n, k, w = map(int, input().split())
    psa = [0] * (n + 1)
    dp = [[0] * (n + 1) for __ in range(k + 1)]
    for i in range(1, n + 1):
        psa[i] = psa[i - 1] + int(input())

    for i in range(1, k + 1):
        for j in range(1, n + 1):
            if j <= w:
                dp[i][j] = psa[j]
            else:
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-w] + psa[j] - psa[j-w])
    print(dp[k][n])