from heapq import heappop, heappush, heapify

N = int(input())

machines = [0]

for _ in range(N):
    s, e = map(int, input().split())
    p = machines[0]
    if p > s:
        heappush(machines, e)
    else:
        machines[0] = e
        heapify(machines)

print(len(machines))
