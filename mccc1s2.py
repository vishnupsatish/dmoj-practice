N = int(input())

grid = [list(map(int, input().split())) for _ in range(N)]

ans = []

for i, r in enumerate(grid):
    if r[0] == 1:
        ans.append(f'R {i + 1}')
        for j, elem in enumerate(r):
            grid[i][j] = 1 - grid[i][j]

for i in range(N):
    if grid[0][i] == 1:
        ans.append(f'C {i + 1}')
        for j in range(N):
            grid[j][i] = 1 - grid[j][i]

def ans_():

    ones = 0
    for row in grid:
        ones += row.count(1)

    if not ones:
        return str(len(ans)) + '\n' + "\n".join(ans)

    return -1

print(ans_())