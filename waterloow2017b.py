import random
import string

N, K = map(int, input().split())


def get():
    global K
    if K > N:
        return 'WRONGANSWER'

    A = input()


    new_str = []

    letters = [x for x in list(string.ascii_lowercase) if x not in A]

    if not letters:
        return 'WRONGANSWER'

    old = 1

    for i, char in enumerate(A):
        if K:
            new_str.append(char)
            K -= 1
        else:
            try:
                new_str.append(random.choice(letters))
            except:
                new_str.append(A[old % len(A)])
                old += 2
    return ''.join(new_str)


print(get())
