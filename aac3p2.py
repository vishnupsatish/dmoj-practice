k, n = map(int, input().split())

a = list(map(int, input().split()))

if n != 1 and 0 in a and k != 1:
    a.remove(0)
    print(min(a), '0' * (k - 2), min(a), sep='')
elif k == 1 and 0 in a:
    a.remove(0)
    print(str(min(a)) * k)
elif n == 1 and 0 in a:
    print(-1)
else:
    print(str(min(a)) * k)
