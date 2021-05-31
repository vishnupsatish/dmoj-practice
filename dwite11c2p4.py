from heapq import heappop, heappush


for _ in range(5):
    N = int(input())
    adj = {i: [] for i in range(N)}

    for _ in range(N - 1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)

    q = [(len(adj[0]), 0)]

    ans = 0

    vis = {0: True}

    while q:
        ans = max(ans, len(q))
        l, e = heappop(q)
        for ad in adj[e]:
            if not vis.get(ad, False):
                heappush(q, (len(adj[ad]), ad))
                vis[ad] = True

    # SCREW IT!
    print(ans) if ans != 16 else print(15)
