n, m = map(int, input().split())

nodes = {}

for i in range(1, n + 1):
    nodes[i] = []

for _ in range(m):
    n1, n2, brightness = map(int, input().split())
    nodes[n1].append((n2, brightness))
    nodes[n2].append((n1, brightness))

animals = []

for _ in range(int(input())):
    dest, colour = input().split()
    animals.append((int(dest), colour))


def bfs():
    q = [(1, 0, 0)]
    visited = {1: -1}
    min_ans = {1: (0, 0)}
    max_ans = {1: (0, 0)}
    for i in range(2, n + 1):
        visited[i] = 0
        min_ans[i] = (0, float('inf'))
        max_ans[i] = (0, 0)

    while q:
        current, level, current_brightness = q.pop(0)
        for adj, new_brightness in nodes[current]:
            if visited[adj] == 0 or visited[adj] == level + 1:
                if max_ans[adj][1] < new_brightness + current_brightness:
                    max_ans[adj] = (level + 1, new_brightness + current_brightness)
                if min_ans[adj][1] > new_brightness + current_brightness:
                    min_ans[adj] = (level + 1, new_brightness + current_brightness)

                q.append((adj, level + 1, new_brightness + current_brightness))
                visited[adj] = level + 1

    return min_ans, max_ans


min_ans, max_ans = bfs()

for animal in animals:
    if animal[1] == 'White':
        print(max_ans[animal[0]][0], max_ans[animal[0]][1])
    else:
        print(min_ans[animal[0]][0], min_ans[animal[0]][1])
