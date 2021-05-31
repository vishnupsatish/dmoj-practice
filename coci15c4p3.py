N = int(input())

arr = [list(map(int, input().split())) for _ in range(N)]

for r in arr:
    lol = 0
    for e in r:
        lol |= e
    print(lol, end=' ')
