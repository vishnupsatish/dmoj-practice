input()

seq1 = list(map(int, input().split()))

input()

seq2_dict = {int(a): i for i, a in enumerate(input().split())}

# seq2_dict = {seq2[i]: i for i in range(len(seq2))}
seq2 = list(seq2_dict)

lis = []

for elem in seq1:
    if seq2_dict.get(elem) is not None:
        lis.append(seq2_dict.get(elem))


def binary(elem, ans):
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


def lis_():
    if not lis:
        return 0
    ans1 = [lis[0]]
    for s in lis:
        binary(s, ans1)

    return len(ans1)


print(lis_())
