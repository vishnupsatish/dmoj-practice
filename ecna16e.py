a = input()

ans = len(a)

for i in range(len(a)):
    for j in range(i + 1, len(a)):
        cnt = a.count(a[i:j])
        ans = min(ans, len(a) - ((j - i) * cnt) + cnt + (j - i))

print(ans)
