M = int(input())

K = int(input())

people = [(input(), int(input())) for i in range(K)]

ans = [float('inf'), 0]


def group(rem, score, grp):
    global ans
    if not rem:
        if ans[0] > score:
            ans = [score, grp]
        return score, grp

    if len(rem) == 1:
        group([], score + rem[0][1], grp + [rem[0]])

    for i in range(1, M + 1):
        group(rem[i:], score + max([a[1] for a in rem[:i]]), grp + [rem[:i]])


group(people, 0, [])

print(f'Total Time: {ans[0]}')

for p in ans[1]:
    print(' '.join([e[0] for e in p]))