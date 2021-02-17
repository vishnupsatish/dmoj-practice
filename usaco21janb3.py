N = int(input())

cow_heights = sorted(list(map(int, input().split())), reverse=True)

stall_heights = list(map(int, input().split()))

ans = 1

for h in cow_heights:

    curr = 0
    deleted = False
    to_delete = None
    for i, s in enumerate(stall_heights):
        if h <= s:
            curr += 1
            if not deleted:
                to_delete = i
                deleted = True

    ans *= curr

    if to_delete is not None:
        del stall_heights[to_delete]


print(ans)
