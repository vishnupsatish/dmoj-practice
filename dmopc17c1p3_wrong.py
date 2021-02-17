# Ignore all below...

n, m = map(int, input().split())

nodes = {}
node_dangerous = {}

for i in range(1, n + 1):
    nodes[i] = []
    node_dangerous[i] = True


for _ in range(m):
    n1, n2, dangerous = map(int, input().split())

    if n1 == n2:
        continue

    if not dangerous:
        node_dangerous[n1] = False
        node_dangerous[n2] = False

    nodes[n1].append((n2, dangerous))
    nodes[n2].append((n1, dangerous))


def bfs():
    q = [(1, 0, 0)]  # Node, level, dangerousness so far
    ans = []  # level, dangerousness so far
    visited = [1]

    while q:
        curr_r, level, dangerous_so_far = q.pop(0)

        if curr_r == n:
            ans.append((level, dangerous_so_far))
            return ans

        for adj, dangerous_new in nodes[curr_r]:

            if node_dangerous[curr_r] is True and adj not in visited:
                q.append((adj, level + 1, dangerous_so_far + dangerous_new))
                visited.append(adj)

            elif node_dangerous[curr_r] is False and dangerous_new == 0 and adj not in visited:

                q.append((adj, level + 1, dangerous_so_far))
                visited.append(adj)


ans = bfs()

if ans is None:
    print(-1)
else:
    print(ans[0][1], ans[0][0])


#-----------------------------------------------------------------------------------------------------------------------




from heapq import heappop, heappush

n, m = map(int, input().split())


class Node:
    def __init__(self, value):
        self.value = value
        self.min_distance = float('inf')
        self.min_only_distance = float('inf')
        self.predecessor = None
        self.adjacent = []

    def __lt__(self, other):
        return self.min_distance < other.min_distance

    def __repr__(self):
        return f'Node(value={self.value}, min_distance={self.min_distance}, only_distance={self.min_only_distance})'


nodes = {}

for i in range(1, n + 1):
    nodes[i] = Node(value=i)

nodes[1].min_distance = 0
nodes[1].min_only_distance = 0


for _ in range(m):
    n1, n2, dangerous = map(int, input().split())

    if n1 == n2:
        continue

    nodes[n1].adjacent.append((nodes[n2], dangerous))

    nodes[n2].adjacent.append((nodes[n1], dangerous))


def dijkstra():
    q = []
    heappush(q, (nodes[1], 0))

    while q:
        curr_r, current_only_distance = heappop(q)

        for adj, dangerous_ in curr_r.adjacent:

            if adj.min_distance > curr_r.min_distance + dangerous_:
                adj.predecessor = curr_r
                adj.min_distance = curr_r.min_distance + dangerous_
                adj.min_only_distance = curr_r.min_only_distance + 1
                heappush(q, (adj, curr_r.min_only_distance + 1 + 1))


dijkstra()

if nodes[n].min_distance == float('inf'):
    print(-1)
else:
    print(nodes[n].min_distance, nodes[n].min_only_distance)



#-----------------------------------------------------------------------------------------------------------------------


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

    q = [1]

    while q:
        curr_r = q.pop(0)
        for adj, dangerous_ in nodes[curr_r]:


            if adj.min_distance > curr_r.min_distance + dangerous_:
                adj.predecessor = curr_r
                adj.min_distance = curr_r.min_distance + dangerous_
                adj.min_only_distance = curr_r.min_only_distance + 1
                heappush(q, (adj, curr_r.min_only_distance + 1 + 1))

            if danger_dists[adj] > danger_dists[curr_r] + dangerous_:
                danger_dists[adj] = danger_dists[curr_r] + dangerous_
                normal_dists[adj] = normal_dists[curr_r] + 1
                q.append(adj)

    return danger_dists, normal_dists



danger_dists, normal_dists = dijkstra()


print(danger_dists[n], normal_dists[n])
