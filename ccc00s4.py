distance = int(input())

N = int(input())

ans = [0] * (distance + 1)

clubs = []

for _ in range(N):
    clubs.append(int(input()))

for i, _ in enumerate(ans):
    ans[0] = 0
    min_val = float('inf')
    for c in clubs:
        if c <= i and ans[i - c] != -1:
            min_val = min(min_val, ans[i - c] + 1)

    if min_val != float('inf'):
        ans[i] = min_val
    else:
        ans[i] = -1


if ans[distance] != -1:
    print(f'Roberta wins in {ans[distance]} strokes.')
else:
    print('Roberta acknowledges defeat.')
