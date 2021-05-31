from itertools import combinations

K = int(input())

a = [9, 2, 9, 9]

for i in range(1, len(a) + 1):
    for l in list(set(combinations(a, i))):
        print(l)

