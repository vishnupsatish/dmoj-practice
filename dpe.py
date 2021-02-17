N, W = map(int, input().split())

ans = [float('inf')] * (100000 + 1)

ans[0] = 0

for i in range(N):
    w, v = map(int, input().split())

    for wt in reversed(range(v, 10000)):
        ans[wt] = min(ans[wt], ans[wt - v] + w)

for i in reversed(range(10000)):
    if ans[i] <= W:
        print(i)
        break
