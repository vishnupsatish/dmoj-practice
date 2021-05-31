instr = [(1, 7), (1, 4), (2, 1), (3, 4), (3, 5)]

while True:
    a = int(input())
    b = int(input())
    if a == 0:
        break
    instr.append((a, b))


def an():
    ans = []
    done = {}
    for _ in range(7):
        for i in range(1, 8):
            if i in done:
                continue
            for a, b in instr:
                if i == b and a not in ans:
                    break
            else:
                ans.append(i)
                done[i] = True
                break
        else:
            return 'Cannot complete these tasks. Going to bed.'
    return ans


lul = an()
print(*lul) if type(lul) == list else print(lul)
