from itertools import permutations

bs = []

n = int(input())

wrk = []

cur = ['Bessie', 'Buttercup', 'Belinda', 'Beatrice', 'Bella', 'Blue', 'Betsy', 'Sue']

for i in range(n):
    inp = input().split()
    bs.append((inp[0], inp[-1]))


def chk():
    for a, b in bs:
        if abs(perm.index(a) - perm.index(b)) != 1:
            return False
    return True


for perm in permutations(cur):
    if chk():
        wrk.append(perm)

wrk.sort()

for e in wrk[0]:
    print(e)
