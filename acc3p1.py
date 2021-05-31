N, K = map(int, input().split())

a = [int(input()) for _ in range(N)]

non_dist = 0

le = 0

d = {a[0]: 0}

for i, e in enumerate(a):
    d[e] = d.get(e, 0) + 1
    if len(d) >= K:
        for j in range(le, i + 1):
            d[a[j]] -= 1
            if d[a[j]] == 0:
                del d[a[j]]
            if len(d) < K:
                non_dist += 1

    else:
        non_dist += 1


print(non_dist)

