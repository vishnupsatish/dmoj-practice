from math import ceil

N, X = map(int, input().split())


def ans():
    a = []

    if N == 1 or X == 1:
        return -1

    if X == 0 and N % 2 == 1:
        return -1
    elif X == 0:
        return ' '.join([str(i % 2) for i in range(N)])

    dist = [i for i in range(X//2, N, ceil(X//2))]

    # print(dist)

    for i in range(N):
        if i == 0:
            if i not in dist: a.append(1)
            else: a.append(0)
            continue
        if i not in dist:
            a.append(int(a[i - 1]))
        else:
            a.append(int(not a[i - 1]))

    # print(a)

    lol = 0

    for i in range(N):
        if (a[i] + a[i - 1]) % 2 == 0:
            lol += 1

    if lol != X:
        return -1

    return ' '.join(list(map(str, a)))


print(ans())
