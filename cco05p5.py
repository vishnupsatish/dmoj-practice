n = int(input())

ans = 0

s = []

pos = 1

for i in range(n):
    l, r = map(int, input().split())
    s.append((l, r))

# pos = s[0][1]
# ans += s[0][1]

for l, r in s[:-1]:
    if pos >= r:
        ans += pos - l
        pos = l

    elif pos <= l:
        ans += r - pos
        pos = r

    elif l < pos < r:
        if pos - l < r - pos:
            ans += pos - l
            pos = l
            ans += r - pos
            pos = r
        else:
            ans += r - pos
            pos = r
            ans += pos - l
            pos = l
    ans += 1

l, r = s[-1]

if pos >= r:
    ans += pos - l
    pos = l
    ans += n - pos
elif pos <= l:
    ans += n - pos
    pos = n
elif l < pos < r:
    ans += pos - l
    pos = l
    ans += n - pos
    pos = n

print(ans)
