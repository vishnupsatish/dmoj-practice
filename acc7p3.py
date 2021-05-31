N, M = map(int, input().split())

f = list(map(int, input().split()))

edges = []

for _ in range(M):
    a, b = map(int, input().split())
    edges.append((a, b, 0))

for i, a in enumerate(f[:-1]):
    i += 1
    j = i + 1
    edges.append((i, j, abs(f[i - 1] - f[j - 1])))

dsu = [i for i in range(N + 1)]


def fd(d):
    if d != dsu[d]:
        dsu[d] = fd(dsu[d])
    return dsu[d]


ans = 0

edges.sort(key=lambda x: x[2])

for a, b, e in edges:
    sa = fd(a)
    sb = fd(b)
    if sa != sb:
        ans += e
        dsu[fd(a)] = fd(b)

print(ans)
