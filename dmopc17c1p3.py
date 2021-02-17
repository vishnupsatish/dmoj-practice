from heapq import heappop, heappush

n, m = map(int, input().split())

nodes = {}

for i in range(1, n + 1):
    nodes[i] = []

for _ in range(m):
    n1, n2, dangerous = map(int, input().split())

    if n1 == n2:
        continue

    nodes[n1].append((n2, dangerous))
    nodes[n2].append((n1, dangerous))


def dijkstra():
    danger_dists = [float('inf')] * (len(nodes) + 1)
    normal_dists = [float('inf')] * (len(nodes) + 1)
    danger_dists[1] = 0
    normal_dists[1] = 0

    q = [(danger_dists[0], normal_dists[0], 1)]

    while q:
        danger, normal, curr_r = heappop(q)

        for adj, dangerous_ in nodes[curr_r]:

            if danger_dists[adj] > danger_dists[curr_r] + dangerous_ or (danger_dists[adj] == danger_dists[curr_r] + dangerous_ and normal_dists[adj] > normal_dists[curr_r] + 1):
                # adj.predecessor = curr_r
                danger_dists[adj] = danger_dists[curr_r] + dangerous_
                normal_dists[adj] = normal_dists[curr_r] + 1
                heappush(q, (danger_dists[curr_r] + dangerous_, normal_dists[curr_r] + 1, adj))

    return danger_dists, normal_dists


danger_dists, normal_dists = dijkstra()

if danger_dists[n] == float('inf'):
    print(-1)
else:
    print(danger_dists[n], normal_dists[n])
