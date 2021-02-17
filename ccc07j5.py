A = int(input())
B = int(input())

N = int(input())

motels = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]

ans = [[0 for __ in range(34)] for _ in range(34)]
new_motels = []


for _ in range(N):
    new_motels.append(int(input()))

new_motels.sort()

for i, m in enumerate(motels):
    if not new_motels:
        break
    if new_motels[0] < m:
        motels.insert(i, new_motels[0])
        del new_motels[0]


for i_, m1 in enumerate(motels):
    for j, m2 in enumerate(motels[i_ + 1:], start=i_ + 1):
        if A <= m2 - m1 <= B:
            if m1:
                for k in reversed(range(0, i_)):
                    if ans[k][i_]:
                        ans[i_][j] += ans[k][i_]
            else:
                ans[i_][j] += ans[0][i_] + 1
        if m2 - m1 > B:
            break


t = 0
for i in reversed(range(0, 13 + N)):
    t += ans[i][13 + N]


print(t)