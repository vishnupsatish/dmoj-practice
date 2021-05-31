pi = 3.14

S, R = map(int, input().split())

if S**2 > pi*R**2:
    print('SQUARE')
else:
    print('CIRCLE')
