from sys import stdin

input = stdin.readline

N = int(input())

s = 0

for _ in range(N):
    s ^= int(input())

print(s)
