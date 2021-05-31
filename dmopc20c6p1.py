N = int(input())

a = list(map(int, input().split()))

s = sum(a)

for i in range(N):
    su = 0
    for j, e in enumerate(a[:-1]):
        su += e
        if abs(su - (s - su)) <= abs((su + a[j + 1]) - (s - (su + a[j + 1]))):
            break
    if i != N - 1:
        print(abs(su - s + su), end=' ')
    else:
        print(abs(su - s + su))
    a.append(a[0])
    del a[0]
