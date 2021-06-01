letters = {
    ('x.', 'xx'): 'A',
    ('xx', 'xx'): 'B',
    ('x.x', 'xxx'): 'C',
    ('xx', '.x'): 'D',
    ('xxx', '.xx'): 'E',
}


def solve(s):
    n = len(s[0])
    dp = [''] * (n + 1)
    for i in range(2, n + 1):
        cur_2 = (s[0][i - 2:i], s[1][i - 2:i])
        cur_3 = (s[0][i - 3:i], s[1][i - 3:i])
        if i == 2:
            if cur_2 in letters:
                dp[i] = letters[cur_2]
                continue
        if cur_2 in letters:
            dp[i] = dp[i - 2] + letters[cur_2]
        if cur_3 in letters:
            dp[i] = dp[i - 3] + letters[cur_3]

    print(dp[-1])


for _ in range(5):
    a = [input(), input()]
    solve(a)
