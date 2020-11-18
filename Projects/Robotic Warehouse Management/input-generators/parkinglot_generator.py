#!/usr/bin/env python3

import sys
import numpy as np

arguments = sys.argv
if len(arguments) != 4:
    print('Usage: ', arguments[0], '<file_name> <num of trucks> <num of robots>')
    exit(0)

total_truck_entries = int(arguments[2])
num_arrived_entries = total_truck_entries - int(total_truck_entries * 30.0 / 100.0)
num_departed_entries = total_truck_entries - num_arrived_entries

total_robot_entries = int(arguments[3])

cities = ['Arad', 'Alba-Iulia', 'Bacau', 'Baia-Mare', 'Bistrita', 'Botosani', 'Brasov', 'Cluj-Napoca', 'Constanta',
          'Craiova', 'Deva', 'Focsani', 'Hunedoara', 'Iasi', 'Oradea', 'Piatra-Neamt', 'Pitesti', 'Ploiesti', 'Sibiu', 'Sinaia',
          'Suceava', 'Timisoara', 'Tulcea']
transit_times = [10, 9, 5, 12, 11, 12, 3, 8, 4, 3, 6, 3, 6, 7, 9, 10, 2, 1, 5, 2, 8, 11, 4]


arrived_entries = []
departure_times = np.random.permutation(np.array([i for i in range(0, 24)]))
# city, capacity, transit_time, departure, [arrived=1, departed = 0]
for i in range(num_arrived_entries):
    index = np.random.randint(0, len(cities))

    arrived_entries.append((cities[index], np.random.randint(5, 10), transit_times[index],
                            departure_times[int(np.random.randint(0, 24))]))

# city, capacity, transit_time, departure, [arrived=1, departed = 0]
departed_entries = []
departure_times = np.random.permutation(np.array([i for i in range(0, 24)]))
for i in range(num_departed_entries):
    index = np.random.randint(0, len(cities))
    departed_entries.append((cities[index], np.random.randint(5, 10), transit_times[index],
                             departure_times[int(np.random.randint(0, 24))]))


robot_swarm = []
for i in range(total_robot_entries):
    robot_swarm.append(np.random.randint(2, 6))


with open(arguments[1], 'w') as f:
    for e in arrived_entries:
        f.write('T,' + e[0] + ',' + str(e[1]) + ',' + str(e[2]) + ',' + str(e[1]) + ',1' + '\n')

    for e in departed_entries:
        f.write('T,' + e[0] + ',' + str(e[1]) + ',' + str(e[2]) + ',' + str(e[1]) + ',0' + '\n')

    for r in robot_swarm:
        f.write('R,' + str(r) + '\n')








