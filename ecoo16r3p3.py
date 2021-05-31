N = int(input())

dic = {input(): True for _ in range(N)}

for _ in range(10):
    inp = input()
    dp = [float('inf')] * (len(inp) + 1)

    dp[0] = 0

    for i in range(len(inp)):
        for j in range(i, len(inp) + 1):
            if dic.get(inp[i:j]):
                dp[j] = min(dp[j], dp[i] + 1)

    print(dp[-1] - 1)
