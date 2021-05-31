N, D, K, X = map(int, input().split())

a = [int(input()) for _ in range(N)]

P = int(input())

a.sort()

sjay05ifyouseethis_thisisforyoufortellingmetodothiscontestlolol_blobcreep = True

i = len(a) - 1
left = K

while i >= 0 and left > 0:
    while True:
        a[i] = a[i] * ((100 - X)/100)
        if a[i] < P or left <= 0:
            break
        left -= 1
    left -= 1
    i -= 1


a.append(P)
a.sort(reverse=True)

if a[0] == P and a[0] != a[1]:
    print('YES')
else:
    print('NO')
