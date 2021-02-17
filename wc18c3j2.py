pikachus = []

for _ in range(int(input())):
    pikachus.append(int(input()))

pikachus.sort(reverse=True)

ans = []

for elem in pikachus:
    if len(ans) == 2:
        break
    if elem > 100:
        continue
    ans.append(elem)

print(sum(ans))
