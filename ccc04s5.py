while True:
    m, n = map(int, input().split())
    if m == 0:
        break

    rep = {'.': 0}

    grid = [list(input()) for _ in range(m)]
    for i, _ in enumerate(grid):
        grid[i] = [int(e) if e != '.' and e != '*' else rep.get(e, e) for e in grid[i]]

    dp = [[0] * n for _ in range(m)]

    for c in range(n - 1):
        for r in range(m - 1, -1, -1):
            if grid[r][c] == '*':
                dp[r][c] = 0
                continue
            dp[r][c] = max(grid[r][c], dp[r][c])
            if r != m - 1 and c == 0:
                dp[r][c] += dp[r + 1][c]

            a = dp[r][c]

            if grid[r][c + 1] == '*':
                continue

            so_far = 0
            for b in range(r, -1, -1):
                if grid[b][c + 1] == '*':
                    break
                so_far += grid[b][c + 1]
                dp[b][c + 1] = max(dp[b][c + 1], a + so_far)
            so_far = 0
            for b in range(r, m):
                if grid[b][c + 1] == '*':
                    break
                so_far += grid[b][c + 1]
                dp[b][c + 1] = max(dp[b][c + 1], a + so_far)

        for r in dp:
            for e in r:
                print(e, end=' ')
            print()

        print('\n\n\n\n')

    # for r in range()

    print(dp[m - 1][n - 1])
