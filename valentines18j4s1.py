N, M = map(int, input().split())

opt_1 = (N + M) // 2
opt_2 = (N + M) // 2

while 1:

    opt_1 -= 1
    opt_2 += 1

    if str(opt_1) == str(opt_1)[::-1]:
        print(opt_1)
        break
    if str(opt_2) == str(opt_2)[::-1]:
        print(opt_2)
        break
