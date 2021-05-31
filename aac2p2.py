N = int(input())

a = list(map(int, input().split()))


def ans():
    if N == 2:
        return (a[0] % 2 == a[1] % 2) + 1

    d = {}

    for e in a:
        d[e] = d.get(e, 0) + 1

    # ans = 0

    for i, e1 in enumerate(a):
        for j, e2 in enumerate(a[i + 1:], start=i + 1):
            if e1 % 2 == e2 % 2 and d.get((e1 + e2) // 2, False):
                return 3

    return 2


print(ans())
