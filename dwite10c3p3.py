memo_g = {}
memo_f = {}


def g(x):
    if x == 1:
        return 1
    elif x == 0:
        return 0

    if x in memo_g:
        return memo_g[x]

    # if x - 1 in memo_f:
    #     return memo_f[x - 1] + g(x - 2)
    # elif x - 2 in memo_g:
    #     return f(x - 1) + memo_g[x - 2]

    memo_g[x] = f(x - 1) + g(x - 2)
    return memo_g[x]


def f(x):
    if x == 1:
        return 0
    elif x == 0:
        return 1

    if x in memo_f:
        return memo_f[x]

    memo_f[x] = f(x - 2) + 2 * g(x - 1)
    return memo_f[x]


for _ in range(5):
    w = int(input())
    if w % 2 == 1:
        print(0)
        continue
    print(f(w) % 1000000)
