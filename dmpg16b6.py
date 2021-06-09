n = int(input())


def n_d(no):
    ans = 0
    no = no[::-1]
    for i in range(len(no)):
        ans += int(no[i]) * ((-2) ** i)
    return ans


def d_n(no):
    bi = ''
    while no != 0:
        if no == 1:
            bi = bi + '1'
            break
        if no % 2 == 1:
            no = no // -2 + 1
            bi = bi + '1'
        else:
            no = no // -2
            bi = bi + '0'

    return bi[::-1]


for _ in range(n):
    q, a = input().split()
    if q == 'A':
        print(n_d(a))
    else:
        if a == '0':
            print(0)
            continue
        m = d_n(int(a))
        print(m)
        # print(n_d(m) == int(a))
