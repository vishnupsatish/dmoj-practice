n = input()

seq = list(map(int, input().split()))

ans = [seq[0]]


def binary(elem):
    left = 0
    right = len(ans) - 1
    if elem > max(ans):
        ans.append(elem)
        return

    while left < right:
        mid = (right + left) // 2
        if ans[mid] > elem:
            right = mid
            continue
        left = mid + 1

    ans[left] = elem


for s in seq:
    binary(s)

print(len(ans))
