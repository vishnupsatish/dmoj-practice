R, C, K = map(int, input().split())

r1 = 1
r2 = R

c1 = 1
c2 = C

memo = {}


def query(one, two):
    if memo.get((one, two)):
        return memo.get((one, two))

    print(f'? {one} {two}')
    memo[(one, two)] = int(input())
    return memo[(one, two)]


while r1 < r2 or c1 < c2:
    rm = (r1 + r2) // 2
    cm = (c1 + c2) // 2

    if r1 < r2:
        cen = query(rm, cm)
        cenplus = query(rm + 1, cm)
        if cen < cenplus:
            r2 = rm
        else:
            r1 = rm + 1

    if c1 < c2:
        cen = query(rm, cm)
        cenplus = query(rm, cm + 1)
        if cen < cenplus:
            c2 = cm
        else:
            c1 = cm + 1

print(f'! {query(r1, c1)}')
