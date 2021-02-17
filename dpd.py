n, W = map(int, input().split())

items = []

for _ in range(n):
    items.append(tuple(map(int, input().split())))

# sol = [[-1 for _ in range(W + 1)] for __ in range(n + 1)]

sol = {}


def knapsack(W_, items_):
    if W_ == 0 or not items_:
        sol[(len(items_), W_)] = 0
        return 0

    weight, value = items_[0]

    if sol.get((len(items_), W_)) != -1 and sol.get((len(items_), W_)):
        return sol[(len(items_), W_)]


    print('first', '\n', items, "\n")

    print('second', '\n', items[1:], '\n')


    if weight > W_:
        sol[(len(items_), W_)] = knapsack(W_, items_[1:])
        return sol[(len(items_), W_)]
    else:
        sol[(len(items_), W_)] = max(value + knapsack(W_ - weight, items_[1:]), knapsack(W_, items_[1:]))
        return sol[(len(items_), W_)]


print(knapsack(W, items))

print(sol[(len(items), W)])
