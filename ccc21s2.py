M = int(input())
N = int(input())

choices = int(input())

grid = [[0] * M] + [[0] * N]

for _ in range(choices):
    r_or_c, num = input().split()
    num = int(num) - 1
    r_or_c = 0 if r_or_c == 'R' else 1
    grid[r_or_c][num] += 1

ans = 0

col_sum = sum([(1 - (x % 2)) for x in grid[1]])
row_sum = sum([(1 - (x % 2)) for x in grid[0]])

for elem in grid[0]:
    ans += (elem % 2) * col_sum

for elem in grid[1]:
    ans += (elem % 2) * row_sum

print(ans)
