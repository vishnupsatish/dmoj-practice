input()

cows = input()

gaps = []

largest_gap = 0

prev = False

for i, c in enumerate(cows):
    if c == '0':
        largest_gap += 1
    elif c == '1' and largest_gap != 0:
        gaps.append(largest_gap)
        largest_gap = 0

left_gap = 0
right_gap = 0

for l in cows:
    if l == '1':
        break
    left_gap += 1

for l in cows[::-1]:
    if l == '1':
        break
    right_gap += 1

if cows[0] == '0':
    gaps = gaps[1:]

gaps.sort(reverse=True)


def get():
    ans = 0

    if '1' not in cows:
        print(len(cows) - 1)
        return

    if '11' in cows:
        print(1)
        return

    if len(gaps) == 1 and not left_gap and not right_gap:
        print(gaps[0] // 3 + 1)
        return

    if left_gap != 0 and right_gap != 0:
        ans = max(ans, min(gaps + [left_gap - 1, right_gap - 1]))

    if left_gap != 0:
        try:
            new_gaps = gaps[:]
            new_gaps[0] = gaps[0] // 2
            ans = max(ans, min(new_gaps + [left_gap - 1]))
        except IndexError:
            pass

        new_gaps = gaps[:]
        ans = max(ans, min(new_gaps + [(left_gap - 1) // 2]))

    if right_gap != 0:
        try:
            new_gaps = gaps[:]
            new_gaps[0] = gaps[0] // 2
            ans = max(ans, min(new_gaps + [right_gap - 1]))
        except IndexError:
            pass

        new_gaps = gaps[:]
        ans = max(ans, min(new_gaps + [(right_gap - 1) // 2]))

    try:
        new_gaps = gaps[:]
        new_gaps[0] = gaps[0] // 2
        new_gaps[1] = gaps[1] // 2
        ans = max(ans, min(new_gaps))

        new_gaps = gaps[:]
        new_gaps[0] = gaps[0] // 3
        ans = max(ans, min(new_gaps))
    except IndexError:
        pass

    print(ans + 1)


get()
