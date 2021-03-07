input()

switches = list(map(int, list(input())))

ans = [switches[0]] * len(switches)

for i, s in enumerate(switches[1:], start=1):
    if s == 0:
        ans[i] = ans[i - 1]
    elif s == 1 and switches[i - 1] == 1:
        ans[i] = ans[i - 1]
    else:
        ans[i] = ans[i - 1] + 2

print(ans[-1])
