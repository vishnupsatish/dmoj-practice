N, M, K = map(int, input().split())

problems = {i: (-1, -1) for i in range(1, N + 1)}

for _ in range(K):
    a, b, c = map(int, input().split())
    if c > problems[b][1]:
        problems[b] = (a, c)

print(*[problems[i][0] for i in problems])
