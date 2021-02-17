N = int(input())

ans = [(0, 0)]

temp = []

for _ in range(N):
    a, b, c = map(int, input().split())

    max_1 = 0
    max_2 = 0
    max_3 = 0

    for key in ans:
        val, taken = key
        if taken == 1:
            max_1 = max(max_1, val)
        if taken == 2:
            max_2 = max(max_2, val)
        if taken == 3:
            max_3 = max(max_3, val)

    temp.append((max(max_2, max_3) + a, 1))
    temp.append((max(max_1, max_3) + b, 2))
    temp.append((max(max_1, max_2) + c, 3))

    ans = temp
    temp = []

print(max([a[0] for a in ans]))
