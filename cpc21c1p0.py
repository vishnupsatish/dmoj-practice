import string

s = input()

for char in string.ascii_lowercase:
    if char in s:
        continue
    print(char)
    break