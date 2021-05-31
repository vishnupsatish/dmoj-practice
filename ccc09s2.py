grid = []

R, L = int(input()), int(input())

for _ in range(R):
    grid.append(eval(f'0b{input().replace(" ", "")}'))

prev = {grid[0]}


for i, ele in enumerate(grid[1:]):
    ans = {ele}
    for e in prev:
        xor = e ^ ele
        ans.add(xor)

    print(ans, prev)

    prev = set(ans)


print(len(ans))
