s1 = list(input())
s2 = list(input())

N = len(s1)
M = len(s2)

dp = [[0] * (M + 1) for _ in range(N + 1)]

for m in range(1, N + 1):
    for n in range(1, M + 1):
        if s1[m - 1] == s2[n - 1]:
            dp[m][n] = dp[m - 1][n - 1] + 1
        else:
            if dp[m - 1][n] > dp[m][n - 1]:
                dp[m][n] = dp[m - 1][n]
            else:
                dp[m][n] = dp[m][n - 1]

n = N
m = M

lcs = ''

while n > 0 and m > 0:
    if s1[n - 1] == s2[m - 1]:
        lcs = lcs + s1[n - 1]
        n -= 1
        m -= 1
    elif dp[n - 1][m] > dp[n][m - 1]:
        n -= 1
    else:
        m -= 1

print(lcs[::-1])
