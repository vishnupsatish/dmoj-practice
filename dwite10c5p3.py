import sys

input = sys.stdin.readline

for _ in range(5):
    N = int(input())
    weights = [int(input()) for _ in range(N)]

    s = sum(weights)

    dp = [float('-inf')] * (s // 2 + 1)
    dp[0] = True
    for w in weights:
        for i in range(s // 2, w - 1, -1):
            if dp[i - w] == float('-inf'):
                continue
            dp[i] = True

    print(abs((s - (len(dp) - dp[::-1].index(True) - 1)) - (len(dp) - dp[::-1].index(True) - 1)))
