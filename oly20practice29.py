import sys
from heapq import heappop, heappush

input = sys.stdin.readline


class Node:

    def __init__(self, name, adjacencies=None):
        adjacencies = {} if adjacencies is None else adjacencies
        self.name = name
        self.adjacenciesList = adjacencies
        self.minDistance = 0
        self.predecessor = None
        self.visited = False

    def __lt__(self, other):
        selfPriority = self.minDistance
        otherPriority = other.minDistance
        return selfPriority < otherPriority

    def __repr__(self):
        return f'Node(name={self.name}, minDistance={self.minDistance}, predecessor={self.predecessor})'


n, m, t = map(int, input().split())

adj = {}


nodes = []

for i in range(1, n + 1):
    nodes.append(Node(name=i))

for _ in range(m):
    si, ei, hi = map(int, input().split())
    nodes[si - 1].adjacenciesList[nodes[ei - 1]] = hi


queries = []

shortest_path = [[-1 for __ in range(n+1)] for _ in range(n+1)]


for _ in range(t):
    ai, bi = map(int, input().split())
    queries.append((ai, bi))


def dijkstra(node):
    q = []

    node.minDistance = 0
    heappush(q, node)

    while q:
        current = heappop(q)

        for next_node in current.adjacenciesList:
            dist = max(current.minDistance, current.adjacenciesList[next_node])
            next_min = next_node.minDistance if next_node.minDistance != 0 else float('inf')
            if dist < next_min:
                next_node.predecessor = current
                next_node.minDistance = dist
                shortest_path[node.name][next_node.name] = dist
                heappush(q, next_node)

    for n in nodes:
        n.predecessor = None
        n.minDistance = 0


for n in nodes:
    dijkstra(n)


for n1, n2 in queries:
    print(shortest_path[n1][n2])
