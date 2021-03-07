M = int(input())

K = int(input())

people = {input(): int(input()) for i in range(K)}

people_list = list(people)

dp = [([people_list[:i]], max(people[a] for a in people_list[:i])) for i in range(1, M + 1)]

for i, elem in enumerate(people_list[M:], start=M):
    best = [0, float('inf')]

    for j, check in enumerate(dp[i - M:], start=i - M):
        ppl, score = check
        current = score + max([people[p] for p in people_list[j + 1:i + 1]])
        if best[1] > current:
            best = (ppl + [[p for p in people_list[j + 1:i + 1]]], current)

    dp.append(best)

print(f'Total Time: {dp[-1][1]}')

for person in dp[-1][0]:
    print(' '.join(person))
