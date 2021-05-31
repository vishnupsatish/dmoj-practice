from sys import stdin, stdout

input = stdin.readline

n, k = map(int, input().split())

prev = input()[:-1]


def get(b, shift):
    new = ''
    for j in range(n):
        new = new + str(int(b[(j - shift) % n]) ^ int(b[(j + shift) % n]))

    return new


for i in range(60, -1, -1):
    if (k >> i) & 1:
        print(i)
        prev = get(prev, 1 << i)

print(prev + '\n')
