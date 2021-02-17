R, C = tuple(map(int, input().split()))

K = int(input())

grid = [[0] * (C + 1) for _ in range(R + 1)]

grid[1][1] = 1

cats = [list(map(int, input().split())) for _ in range(K)]

for i in range(1, R + 1):
    start = 1
    if i == 1:
        start = 2
    for j in range(start, C + 1):
        if [i, j] in cats:
            continue
        grid[i][j] = grid[i - 1][j] + grid[i][j - 1]

print(grid[R][C])
