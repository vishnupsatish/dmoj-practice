N = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

dp = [[0] * 3 for _ in range(N)]

dp[0][0] = b[0]
dp[0][1] = max(a[0], b[0])
dp[0][2] = max(a[0], b[0])

for i, ae in enumerate(a[1:], start=1):
    be = b[i]

    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + be

    dp[i][1] = dp[i - 1][0] + ae
    dp[i][2] = dp[i - 1][1] + ae

print(max(dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]))
