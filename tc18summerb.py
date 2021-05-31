C, D, E = map(int, input().split())

# ans = 2
if C | D != C or C ^ D != E or C ^ E != D or D ^ E != C and D & E != 0:
    print(0)
else:
    print((2 ** bin(E).count('1')))
