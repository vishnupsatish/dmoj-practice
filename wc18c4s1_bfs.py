N, M, K = list(map(int, input().split()))

races = input()

g = [[] for _ in range(M)]

friends = [[] for _ in range(K)]

for i in range(M):
    p1, p2 = list(map(int, input().split()))
    if races[p1 - 1] == races[p2 - 1]:
        g[p1 - 1].append(p2 - 1)
        g[p2 - 1].append(p1 - 1)

for i in range(K):
    f, d = list(map(int, input().split()))
    friends[i] = (f - 1, d - 1)


def get_adjacent_nodes(node):
    return g[node]


def bfs(friend):
    visited = [friend[0]]
    q = [friend[0]]
    while q:
        current_node = q.pop()
        if current_node == friend[1]:
            return True
        for node in get_adjacent_nodes(current_node):
            if node not in visited:
                q.append(node)
                visited.append(node)
    else:
        return False


ans = 0

for f in friends:
    if bfs(f):
        ans += 1

print(ans)
