import sys

input = sys.stdin.readline

N, M = map(int, input().split())

dsu = [i for i in range(N + 1)]


def fd(d):
    if d != dsu[d]:
        dsu[d] = fd(dsu[d])
    return dsu[d]


edges = []

for i in range(M):
    a, b = map(int, input().split())
    edges.append((a, b, i + 1))

for i, el in enumerate(edges):
    a, b, e = el
    sa = fd(a)
    sb = fd(b)
    if sa != sb:
        print(e)
        dsu[fd(a)] = fd(b)
