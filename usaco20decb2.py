import itertools

N = int(input())

petals = list(map(int, input().split()))

flowers = list(range(N)) * 2

all_combs = list(set(list(itertools.combinations(flowers, 2))))

ans = 0

for comb in all_combs:
    start, end = comb
    current_petals = petals[start:end + 1]

    try:
        avg = sum(current_petals)/len(current_petals)
    except:
        avg = float('inf')

    if avg in current_petals:
        ans += 1

print(ans)
