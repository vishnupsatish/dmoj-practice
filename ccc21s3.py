from math import ceil

N = int(input())

friends = []

for _ in range(N):
    friends.append(list(map(int, input().split())))


def cost(pos):
    ans = 0
    for p, w, d in friends:
        if pos > p:
            if pos <= p + d:
                continue
            ans += (pos - (p + d)) * w
        else:
            if pos >= p - d:
                continue

            ans += ((p - d) - pos) * w

    return ans


left = 0
right = 1000000001

while left < right:
    mid = (left + right) // 2
    if cost(mid) < cost(mid + 1):
        right = mid
    else:
        left = mid + 1

ans = cost(left)

print(min(int(ans), ceil(ans)))
