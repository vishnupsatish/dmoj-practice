N = int(input())

s = input()

d = {}


def ans():
    for c in s:
        d[c] = d.get(c, 0) + 1

    odd = 0

    # print(d)

    for k in d:
        odd += d[k] % 2 == 1

    if odd == 0:
        return 1

    return odd


print(ans())
