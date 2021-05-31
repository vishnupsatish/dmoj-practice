import sys

sys.setrecursionlimit(100000)

N, M = map(int, input().split())

adj = {i: [] for i in range(1, N + 1)}

dp = [0] * (N + 1)

for _ in range(M):
    n1, n2 = map(int, input().split())
    adj[n1].append(n2)


def dfs(start):
    visited[start] = True

    for a in adj[start]:
        if not visited[a]:
            dfs(a)

        dp[start] = max(dp[start], dp[a] + 1)


visited = [False] * (N + 1)

for n in range(1, N + 1):
    if not visited[n]:
        dfs(n)

print(max(dp))
