# Idea: https://imgur.com/a/xmrY6ke

num = int(input())

a = []

for i in range(num):
    a.append(input().split('-'))

m = int(input())

d = {'O': 0, 'V': 0, 'N': 0, 'OV': 0, 'NO': 0, 'NV': 0, 'NOV': 0}

for i in range(m):
    d[''.join(sorted(input()))] += 1
        
for e in a:
    ok = False
    for x in range(d['OV'] + 1):
        for y in range(d['NO'] + 1):
            for z in range(d['NV'] + 1):
                o = max(0, int(e[0]) - d['O'] - x - (d['NO'] - y))
                v = max(0, int(e[1]) - d['V'] - z - (d['OV'] - x))
                n = max(0, int(e[2]) - d['N'] - y - (d['NV'] - z))
                if o + v + n <= d['NOV']:
                    ok = True
                    break
            if ok:
                break
        if ok:
            break
    print('DA' if ok else 'NE')
