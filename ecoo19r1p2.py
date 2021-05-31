for _ in range(10):
    ax = {}
    amt = {}
    R, T, A = input().split()
    first = A[0]
    last = A[-1]
    R, T = map(int, [R, T])
    for _ in range(R):
        a, b = input().split()
        ax[a] = b
        amt[a] = amt.get(a, 0)

    for lol in A:
        amt[lol] = amt.get(lol, 0) + 1

    for _ in range(T):
        first = ax[first][0]
        last = ax[last][-1]

        new_amt = {a: 0 for a in amt}

        for a in ax:
            for e in ax[a]:
                new_amt[e] += amt.get(a, 0)

        amt = new_amt

    print(first + last, sum([amt[l] for l in amt]))
