N = int(input())

l = []

d = {}

for i in range(N):
    a = tuple(map(int, input().split()))
    l.append(a)
    d[a] = True


ans = 0

for i, e1 in enumerate(l):
    x1, y1 = e1
    for j, e2 in enumerate(l[i + 1:], start=i + 1):
        x2, y2 = e2
        if d.get((x1, y2)) and d.get((x2, y1)):
            ans = max(ans, abs(y2 - y1) * abs(x2 - x1))

print(ans)
