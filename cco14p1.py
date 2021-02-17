N = int(input())


def get_num(inp):
    if inp == '#':
        return 1
    return 0


grid = []

for i in range(N):
    grid.append(list(map(get_num, list(input()))))

for i, row in reversed(list(enumerate(grid[:-1]))):
    for j, elem in enumerate(row[1:-1], start=1):
        if elem == 1:
            grid[i][j] += min(grid[i + 1][j - 1], grid[i + 1][j + 1], grid[i + 1][j])

s = 0

for row in grid:
    for elem in row:
        s += elem

print(s)
