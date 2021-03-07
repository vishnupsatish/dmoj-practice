N, start = map(int, input().split())

fuel_cells = 0

planets = []

for i in range(N):
    gain, lose = map(int, input().split())
    if i == start - 1:
        fuel_cells += gain
        continue
    planets.append((gain - lose, lose))

planets.sort(key=lambda e: e[1])

planets_count = 1

for i, start in enumerate(planets):
    net, loss = start
    if net >= 0 and loss <= fuel_cells:
        planets_count += 1
        fuel_cells += net

print(fuel_cells, planets_count, sep='\n')
