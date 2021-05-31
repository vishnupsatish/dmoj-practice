N = int(input())

b = list(map(int, input().split()))

dp = [[False] * (N + 1) for _ in range(N + 1)]

for i in range(N):
    dp[i][i] = True

for i in range(N):
    for j in range(i, N):
        if j - i == 1 or j - i == 2:
            if b[i] == b[j]:
                dp[i][j] = True

        # if j - i == 2:
        #     print(i, j)
        #     if b[i] == b[j]:
        #         dp[i][j] = True

print(dp[0][2])
