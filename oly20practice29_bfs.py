import sys
input = sys.stdin.readline

n, m, t = map(int, input().split())


adj = {}

for i in range(1, n+1):
    adj[i] = []

for _ in range(m):
    si, ei, hi = map(int, input().split())
    adj[si].append((ei, hi))

queries = []

for _ in range(t):
    ai, bi = map(int, input().split())
    queries.append((ai, bi))


for start, end in queries:
    q = [(start, 0)]
    visited = [start]
    answer = (0, float('inf'))
    while q:
        current, val = q.pop(0)
        for n, w in adj[current]:
            m = max(val, w)
            if n == end and m < answer[1]:
                answer = (n, m)
                continue
            if m < answer[1]:
                q.append((n, m))

    if answer[1] != float('inf'):
        print(answer[1])
    else:
        print(-1)

