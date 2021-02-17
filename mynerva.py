from heapq import heappop, heappush

n, m = map(int, input().split())

nodes = {}

for i in range(1, n + 1):
    nodes[i] = []

for _ in range(m):

    n1, n2, brightness = map(int, input().split())

    if n1 == n2:
        continue

    nodes[n1].append((n2, brightness))
    nodes[n2].append((n1, brightness))

animals = []

for _ in range(int(input())):
    dest, colour = input().split()
    animals.append((int(dest), colour))


def dijkstra():
    min_dist = [(float('inf'), float('inf')) for _ in range(n + 1)]
    max_dist = [(float('inf'), 0) for _ in range(n + 1)]
    level = [float('inf')] * (n + 1)

    min_dist[1] = (0, 0)

    q = [(0, 1)]

    while q:
        curr_lvl, curr = heappop(q)

        for adj, bright in nodes[curr]:
            if max_dist[adj][1] < max_dist[curr][1] + bright and max_dist[adj][0] > curr_lvl:
                max_dist[adj] = (curr_lvl + 1, max_dist[curr][1] + bright)
                level[adj] = curr_lvl + 1
                heappush(q, (curr_lvl + 1, adj))
            if min_dist[adj][1] > min_dist[curr][1] + bright and min_dist[adj][0] > curr_lvl:
                min_dist[adj] = (curr_lvl + 1, min_dist[curr][1] + bright)
                level[adj] = curr_lvl + 1
                heappush(q, (curr_lvl + 1, adj))

    return min_dist, max_dist


min_ans, max_ans = dijkstra()


for animal in animals:
    if animal[0] == 1:
        print(0, 0)
        continue
    if animal[1] == 'White':
        print(max_ans[animal[0]][0], max_ans[animal[0]][1])
    else:
        print(min_ans[animal[0]][0], min_ans[animal[0]][1])


