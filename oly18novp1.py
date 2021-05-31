N = int(input())

a = []

for _ in range(N):
    a.append((tuple(map(int, input().split()))))

a.sort(key=lambda x: x[1])

ans = 1
p = a[0][1]

for l, r in a[1:]:
    if l >= p:
        ans += 1
        p = r

print(ans)
