N, K = map(int, input().split())

positions = {}

moves = []

cows = []

for c in range(N):
    positions[c] = [c]
    cows.append(c)

for pos in range(K):
    moves.append((list(map(int, input().split()))))

for i in range(N*K):
    c1, c2 = moves[i % len(moves)]
    cows[c1 - 1], cows[c2 - 1] = cows[c2 - 1], cows[c1 - 1]
    c1, c2 = c2, c1
    cc1 = cows[c1 - 1] + 1
    cc2 = cows[c2 - 1] + 1
    if c2 - 1 not in positions[cc1 - 1]:
        positions[cc1 - 1].append(c2 - 1)
    if c1 - 1 not in positions[cc2 - 1]:
        positions[cc2 - 1].append(c1 - 1)


for l in positions:
    print(len(positions[l]))
