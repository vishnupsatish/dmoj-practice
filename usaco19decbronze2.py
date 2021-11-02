n = int(input())

s = input()

for le in range(1, n):
    su = {}
    for left in range(n - le + 1):
        right = left + le
        su[s[left:right]] = su.get(s[left:right], 0) + 1

    al = [su[k] for k in su]
    if max(al) == 1: break

print(le)
