import sys

sys.setrecursionlimit(100000)

n, m, k = map(int, input().split())

s = input().strip()
p = [0] * (n+1)
for i in range(1, n+1):
    p[i] = i


def fd(d):
    if d != p[d]:
        p[d] = fd(p[d])
    return p[d]


for i in range(m):
    u, v = map(int, input().split())
    if s[u-1] == s[v-1]:
        p[fd(u)] = fd(v)

ans = 0
for i in range(k):
    u, v = map(int, input().split())
    if fd(u) == fd(v):
        ans += 1

print(ans)
