N = int(input())

stones = list(map(int, input().split()))

d = {}

for i, f in enumerate(stones[:-2]):
    if d.get((i - 2, i), None) is None:
        d[(i, i + 1)] = (d.get((i - 1, i), 0)) + abs(stones[i + 1] - f)
        d[(i, i + 2)] = (d.get((i - 1, i), 0)) + abs(stones[i + 2] - f)
    else:
        d[(i, i + 1)] = min(d.get((i - 1, i), 0), d.get((i - 2, i), 0)) + abs(stones[i + 1] - f)
        d[(i, i + 2)] = min(d.get((i - 1, i), 0), d.get((i - 2, i), 0)) + abs(stones[i + 2] - f)

d[(N - 2, N - 1)] = min(d.get((N - 3, N - 2), 0), d.get((N - 4, N - 2), 0)) + abs(stones[N - 2] - stones[N - 1])

print(min(d[(N - 2, N - 1)], d.get((N - 3, N - 1), float('inf'))))
