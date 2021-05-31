from sys import stdin

input = stdin.readline

N, M = map(int, input().split())

a = [list(input()) for _ in range(N)]

for i in range(len(a)):
    for j in range(len(a[i])):
        a[i][j] = 1 if a[i][j] == 'X' else 0

psa = [[0] * M for i in range(N)]

psa[0][0] = a[0][0]

for i in range(1, M):
    psa[0][i] = (psa[0][i - 1] + a[0][i])

for i in range(1, N):
    psa[i][0] = (psa[i - 1][0] + a[i][0])

for r in range(1, N):
    for c in range(1, M):
        psa[r][c] = psa[r - 1][c] + psa[r][c - 1] - psa[r - 1][c - 1] + a[r][c]


def generate(s, pos):
    r, c = pos
    temp = [(r - 1, c), (r + 1, c), (r, c + 1), (r, c - 1)]
    for nr, nc in temp:
        if nr - s + 1 < 0 or nc - s + 1 < 0 or nr > N - 1 or nc > M - 1:
            continue
        if nr == s - 1:
            if psa[nr][nc] - psa[nr][nc - s] == 0:
                yield nr, nc
        elif nc == s - 1:
            if psa[nr][nc] - psa[nr - s][nc] == 0:
                yield nr, nc
        else:
            if psa[nr][nc] - psa[nr - s][nc] - psa[nr][nc - s] + psa[nr - s][nc - s] == 0:
                yield nr, nc


def bfs(s):
    # vis = {(s - 1, s - 1): True}
    vis = [[False] * M for _ in range(N)]
    q = [(s - 1, s - 1)]
    while q:
        e = q.pop(0)
        r, c = e
        if r == N - 1 and c == M - 1:
            return True
        for nr, nc in generate(s, e):
            if not vis[nr][nc]:
                vis[nr][nc] = True
                q.append((nr, nc))
    return False


l = 1
r = min(N, M) + 1

while l < r:
    mid = (l + r) // 2
    if psa[mid - 1][mid - 1] != 0:
        r = mid
        continue
    if bfs(mid):
        l = mid + 1
    else:
        r = mid

print(l - 1)
