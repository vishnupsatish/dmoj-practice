T = int(input())

N = int(input())

comps = {i: [] for i in range(1, T + 1)}

for _ in range(N):
    c, v, t = map(int, input().split())
    comps[t].append((c, v))

W = int(input())

dp = [(0, 0)] * (W + 1)

for k in comps:
    for wt in reversed(range(0, W + 1)): # Reverse to avoid adding two of the same type
        for c, v in comps[k]:
            if wt + c <= W:
                if dp[wt][0] + v > dp[wt + c][0]:
                    dp[wt + c] = (dp[wt][0] + v, k)

        print(dp)


if dp[-1][1] != T:
    print(-1)
else:
    print(dp[-1][0])
