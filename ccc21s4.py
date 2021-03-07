N, W, D = map(int, input().split())

walkways = {}

for i in range(N):
    walkways[i + 1] = []

for _ in range(W):
    one, two = map(int, input().split())

    # Reverse graph
    walkways[two].append(one)

swaps = []

first_position = list(map(int, input().split()))

for _ in range(D):
    swaps.append(list(map(int, input().split())))

ans = [(float('inf'), i + 1) for i in range(N)]

# ans = {}
#
# for i in range(N):
#     ans[i + 1] = (float('inf'), i + 1)

visited = [N]

q = [N]

dist = {}

for i in range(N + 1):
    dist[i] = float('inf')

dist[N] = 0

while q:
    current = q.pop(0)
    for adj in walkways[current]:
        if adj not in visited:
            ans[adj - 1] = (first_position.index(adj) + dist[current] + 1, adj)
            dist[adj] = dist[current] + 1
            visited.append(adj)
            q.append(adj)

ans[N - 1] = (first_position.index(N), N)

ans.sort(key=lambda x: x[0])

for s in swaps:
    one, two = s

    old_index_1 = one - 1
    old_index_2 = two - 1

    del ans[[x[1] for x in ans].index(first_position[old_index_2])]
    del ans[[x[1] for x in ans].index(first_position[old_index_1])]

    first_position[old_index_1], first_position[old_index_2] = first_position[old_index_2], first_position[old_index_1]

    ans.append((dist[first_position[old_index_2]] + two - 1, first_position[old_index_2]))
    ans.append((dist[first_position[old_index_1]] + one - 1, first_position[old_index_1]))

    ans.sort(key=lambda x: x[0])

    print(ans[0][0])
