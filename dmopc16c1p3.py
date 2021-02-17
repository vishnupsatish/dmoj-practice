N = int(input())

shoes = list(map(int, input().split()))

dp = []

for i, current in enumerate(shoes):
    if i == 0:
        dp.append(current)
        continue

    normal_minus1 = shoes[i - 1]
    normal_minus2 = shoes[i - 2]

    if i == 1:
        dp.append(normal_minus1 + current - min(normal_minus1, current) / 2)
        continue

    normal_minus3 = shoes[i - 3]

    dp_minus1 = dp[i - 1]
    dp_minus2 = dp[i - 2]
    dp_minus3 = dp[i - 3]

    if i == 2:
        dp_minus3 = 0

    dp.append(min(current + dp_minus1,
                  dp_minus2 + normal_minus1 + current - min(normal_minus1, current) / 2,
                  dp_minus3 + normal_minus2 + normal_minus1 + current - min(normal_minus2, normal_minus1, current)))

print(round(float(dp[N - 1]), 1))
