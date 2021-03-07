N = int(input())

rows = []
columns = []

grid = []

for _ in range(N):
    grid.append(list(input()))


def toggle_column(num):
    for i in range(N):
        grid[i][num] = 'R' if grid[i][num] == 'L' else 'L'


def toggle_row(num):
    grid[num] = ['L' if a == 'R' else 'R' for a in grid[num]]


for i, elem in enumerate(grid[0]):
    if elem == 'R':
        toggle_column(i)

for i in range(N):
    if grid[i][0] == 'R':
        toggle_row(i)


def final_answer():
    no_zero = True
    for row in grid:
        if 'R' in row:
            no_zero = False
            break

    for row in grid[1:]:
        if 'L' in row[1:]:
            break
    else:
        return '1 1'

    if no_zero:
        return '-1'

    for i in range(N):
        if 'L' not in [grid[j][i] for j in range(N)]:
            return f'{1} {i + 1}'

    for i, row in enumerate(grid):
        if 'L' not in row[1:]:
            return f'{i + 1} {1}'

    ans = 0
    ones = 0

    for i, row in enumerate(grid):
        ones += row.count('R')
        if row.count('R') == 1:
            ans = f'{i + 1} {row.index("R") + 1}'

    if ones == 1:
        return ans

    return -1


print(final_answer())
