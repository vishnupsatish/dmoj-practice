N, W = map(int, input().split())

ans = [0] * (W + 1)

for i in range(N):
    w, v = map(int, input().split())

    for wt in reversed(range(w, W + 1)):
        ans[wt] = max(ans[wt], ans[wt - w] + v)

print(ans[W])
