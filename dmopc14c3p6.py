N, T = map(int, input().split())

dp = [0] * (T + 1)

for _ in range(N):
    l = list(map(int, input().split()))
    poor, avg, good = l[:2], l[2:4], l[4:]

    for j in reversed(range(poor[0], T + 1)):
        if j >= poor[0]:
            dp[j] = max(dp[j], dp[j - poor[0]] + poor[1])
        if j >= avg[0]:
            dp[j] = max(dp[j], dp[j - avg[0]] + avg[1])
        if j >= good[0]:
            dp[j] = max(dp[j], dp[j - good[0]] + good[1])

print(max(dp))
