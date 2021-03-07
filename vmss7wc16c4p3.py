D, I, R = map(int, input().split())

R = R if D + I > R else D + 1

word1, word2 = input().split()

N, M = len(word1), len(word2)

dp = [[0] * (M + 1) for _ in range(N + 1)]

for m in range(1, N + 1):
    for n in range(1, M + 1):
        if word1[m - 1] == word2[n - 1]:
            dp[m][n] = dp[m - 1][n - 1] + 1
        else:
            dp[m][n] = max(dp[m - 1][n], dp[m][n - 1])

lcs = dp[N][1:]

indexes = [i for i, elem in enumerate(lcs[1:], start=1) if elem != lcs[i - 1]]

if lcs[0] == 1:
    indexes = [0] + indexes

chars = {}

for i in indexes:
    chars[word2[i]] = chars.get(word2[i], 0) + 1


def get_score(inp1, inp2, chars_loc):
    ans = 0

    # done = [False] * len(chars)

    print(chars_loc)

    for i, elem1 in enumerate(inp1):
        elem2 = inp2[i]

        print(chars_loc.get(elem1), chars_loc.get(elem2))

        if elem1 == '0':
            ans += I
            continue
        if elem2 == '0':
            ans += D
            continue

        if (elem1 == elem2) or (chars_loc.get(elem1) and chars_loc.get(elem2)):
            continue

        if not chars_loc.get(elem1) and not chars_loc.get(elem2):
            ans += R
            continue

    return ans


print(get_score('intention', 'execution', chars))
