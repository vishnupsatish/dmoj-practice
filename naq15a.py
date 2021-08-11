import string

digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
digits += list(string.ascii_lowercase)

n = int(input())


def ans(exp):
    ret = []
    op = exp[1]
    x = exp[0]
    y = exp[2]
    z = exp[4]
    if len(set(list(x))) == 1 and x[0] == '1' and len(set(list(y))) == 1 and y[0] == '1' and len(set(list(z))) == 1 and z[0] == '1' and eval(f'len(x) {op} len(y)') == len(z):
        ret.append('1')

    for i in range(2, 37):
        xbase10 = ybase10 = zbase10 = 0
        useless = False
        for j, dig in enumerate(x[::-1]):
            if digits.index(dig) >= i:
                useless = True
                break
            xbase10 += digits.index(dig) * (i ** j)
        if useless: continue
        for j, dig in enumerate(y[::-1]):
            if digits.index(dig) >= i:
                useless = True
                break
            ybase10 += digits.index(dig) * (i ** j)
        if useless: continue
        for j, dig in enumerate(z[::-1]):
            if digits.index(dig) >= i:
                useless = True
                break
            zbase10 += digits.index(dig) * (i ** j)
        if useless: continue

        print(xbase10, ybase10, zbase10)

        if eval(f'xbase10 {op} ybase10') == zbase10:
            if i == 36: ret.append('0')
            else: ret.append(digits[i])

    return ''.join(ret) if len(ret) != 0 else 'invalid'


for i in range(n):
    a = input().split()
    print(ans(a))
