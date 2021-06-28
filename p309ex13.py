def to_base10(k, num):
    ans = 0
    num = str(num)
    for i in range(len(num)):
        ans += int(num[len(num) - i - 1]) * k ** i
    return ans


def to_basek(k, num):
    ans = ''
    while num != 0:
        ans += str(num % k)
        num //= k
    return ans[::-1]


t = int(input())

for i in range(t):
    base1 = int(input())
    num1 = int(input())
    base2 = int(input())
    num2 = int(input())
    operation = input()
    endbase = int(input())
    num1 = to_base10(base1, num1)
    num2 = to_base10(base2, num2)
    if operation == '+': print(to_basek(endbase, num1 + num2))
    if operation == '-': print(to_basek(endbase, num1 - num2))
    if operation == '*': print(to_basek(endbase, num1 * num2))
    if operation == '/': print(to_basek(endbase, num1 // num2))
    if i != t - 1: input()
