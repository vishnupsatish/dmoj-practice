N = int(input())

tasks = list(filter(lambda a: a != 0, sorted(list(map(int, input().split())))))

sum_arr = [[0 for i in range(sum(tasks) // 2 + 1)] for j in range(2)]


def main():
    if N == 1:
        return tasks[0]

    for i, t in enumerate(tasks):
        sum_arr[i % 2][i] = 1
        for j, _ in enumerate(sum_arr[i % 2]):
            sum_arr[i % 2][j] = max(sum_arr[i % 2][j], sum_arr[i % 2 - 1][j - t])
        del sum_arr[0]
        sum_arr.append(sum_arr[-1])

    max_ans = 0

    for i, row in reversed(list(enumerate(sum_arr))):
        for j, elem in reversed(list(enumerate(row))):
            max_ans = j
            break

    return abs((sum(tasks) - max_ans) - max_ans)


print(main())
