S = input()
T = input()

ans = 0

m = 0

for i in range(0, min(len(S), len(T))):
    if S[i] != T[i]:
        break
    m += 1

ans += len(S) + len(T) - 2 * m

print(ans)

