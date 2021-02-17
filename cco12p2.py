from heapq import heappop, heappush

n, m = map(int, input().split())

nodes = [{} for _ in range(n + 1)]

for _ in range(m):
    a, b, l = map(int, input().split())

    nodes[a][b] = l


def mod_dijkstra():
    d1 = [float('inf')] * (n + 1)
    d2 = [float('inf')] * (n + 1)
    d1[1] = 0

    q = [1]

    while q:
        curr = heappop(q)

        for adj in nodes[curr]:
            weight = nodes[curr][adj]

            if d1[adj] > d1[curr] + weight:
                d2[adj] = d1[adj]
                d1[adj] = d1[curr] + weight
                heappush(q, adj)

            elif d2[adj] > d1[curr] + weight and d1[adj] != d1[curr] + weight:
                d2[adj] = d1[curr] + weight
                heappush(q, adj)

            if d2[adj] > d2[curr] + weight and d1[adj] != d2[curr] + weight:
                d2[adj] = d2[curr] + weight
                heappush(q, adj)

    return d2[n]


ans = mod_dijkstra()

if ans == float('inf'):
    print(-1)
else:
    print(ans)
