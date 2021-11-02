n = int(input())

cur = tuple((tuple(str(i) for i in range(n, 0, -1)), [], []))

mp = {0: 'A', 1: 'B', 2: 'C'}
memo = {}


def pos_moves(state):
    ret = []
    if (len(state[1]) == 0 and len(state[0]) != 0) or (len(state[0]) != 0 and state[0][-1] < state[1][-1]):
        ret.append((0, 1))
    if (len(state[2]) == 0 and len(state[0]) != 0) or (len(state[0]) != 0 and state[0][-1] < state[2][-1]):
        ret.append((0, 2))
    if (len(state[0]) == 0 and len(state[1]) != 0) or (len(state[1]) != 0 and state[1][-1] < state[0][-1]):
        ret.append((1, 0))
    if (len(state[2]) == 0 and len(state[1]) != 0) or (len(state[1]) != 0 and state[1][-1] < state[2][-1]):
        ret.append((1, 2))
    if (len(state[0]) == 0 and len(state[2]) != 0) or (len(state[2]) != 0 and state[2][-1] < state[0][-1]):
        ret.append((2, 0))
    if (len(state[1]) == 0 and len(state[2]) != 0) or (len(state[2]) != 0 and state[2][-1] < state[1][-1]):
        ret.append((2, 1))
    return ret

q = [(cur, 0)]
vis = set()

prev = {0: -1}
val = {0: ''}
cnt = 1

while q:
    cur, curcnt = q.pop(0)
    if len(cur[-1]) == n:
        moves = []
        cr = curcnt
        while cr != 0:
            moves.append(val[cr])
            cr = prev[cr]
        for e in moves[::-1]:
            print(mp[int(e[0])] + mp[int(e[1])])
        break

    for a, b in pos_moves(cur):
        nxt = [list(y) for y in cur]
        nxt[b].append(nxt[a][-1])
        nxt[a].pop()

        tup = tuple(tuple(a) for a in nxt)
        if tup not in vis:
            vis.add(tup)
            q.append((tup, cnt))
            prev[cnt] = curcnt
            val[cnt] = str(a) + str(b)

            cnt += 1
