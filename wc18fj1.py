actors = [int(input()) for _ in range(int(input()))]

most1 = (0, 0)
most2 = (0, 0)


for a in actors:
    if actors.count(a) > most1[1]:
        most1 = (a, actors.count(a))
    if a != most1[0] and actors.count(a) > most2[1]:
        most2 = (a, actors.count(a))

print(most1[1] + most2[1])
