import sys
all_data = sys.stdin.read().split('\n')

alpha = 'abcdefghijklmnopqrstuvwxyz'.upper()

cipher = all_data[0]
key = all_data[1]
ans = ''

for i in range(min(len(key), len(cipher))):
    ans += alpha[(alpha.index(cipher[i]) - alpha.index(key[i])) % 26]

key = key + ans

for i in range(len(ans), len(cipher)):
    ans += alpha[(alpha.index(cipher[i]) - alpha.index(key[i])) % 26]
    key += alpha[(alpha.index(cipher[i]) - alpha.index(key[i])) % 26]

print(ans)
