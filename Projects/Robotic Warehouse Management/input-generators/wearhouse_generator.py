#!/usr/bin/env python3

import sys
import numpy as np

arguments = sys.argv
if len(arguments) != 3:
    print('Usage: ', arguments[0], '<file_name> <number of entries>')
    exit(0)

num_entries = int(arguments[2])

entries = []
cities = ['Arad','Alba-Iulia', 'Bacau', 'Baia-Mare', 'Bistrita', 'Botosani', 'Brasov', 'Cluj-Napoca', 'Constanta',
          'Craiova', 'Deva', 'Focsani', 'Hunedoara', 'Iasi', 'Oradea', 'Piatra-Neamt', 'Pitesti', 'Ploiesti', 'Sibiu', 'Sinaia',
          'Suceava', 'Timisoara', 'Tulcea']
for i in range(num_entries):
    entries.append((np.random.randint(0, 10), cities[np.random.randint(0, len(cities))]))

with open(arguments[1], 'w') as f:
    f.write(str(num_entries) + '\n')
    for e in entries:
        f.write(str(e[0]) + ',' + e[1] + '\n')










