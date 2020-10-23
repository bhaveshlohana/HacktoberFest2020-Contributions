#include <stdio.h>
#include "WearhouseManager.h"

#define WORKING_DAYS 7
#define HOURES_PER_DAY 24


char *wearhouse_path;
char *parkinglot_path;

int main(int argc, char** argv){
	if(argc < 3){
		fprintf(stderr, "USAGE: %s <wearhouse_file_path> <parkinglot_file_path>\n", argv[0]);
		exit(EXIT_FAILURE);
	}


	wearhouse_path = argv[1];
	parkinglot_path = argv[2];

	Wearhouse* wearhouse = open_wearhouse(wearhouse_path);
	Parkinglot *parkinglot = open_parckinglot(parkinglot_path);
	long day, hour;

	for(day = 0; day < WORKING_DAYS; day++){
		for(hour = 0; hour < HOURES_PER_DAY; hour++){
			printf("***********************\n");
			printf("Day: %ld Hour: %ld\n", day, hour);
			printf("***********************\n");
			printf("Wearhose packages:\n");
			wearhouse_print_packages_info(wearhouse);
			printf("Arrived trucks info:\n");
			parkinglot_print_arrived_trucks(parkinglot);
			printf("Departed trucks info:\n");
			parkinglot_print_departed_trucks(parkinglot);
			printf("Parkinglot pending robots:\n");
			parkinglot_print_pending_robots(parkinglot);
			printf("Parkinglot standby robots:\n");
			parkinglot_print_standby_robots(parkinglot);
			printf("***********************\n");

			robot_swarm_collect(wearhouse, parkinglot);
			robot_swarm_assign_to_trucks(parkinglot);
			robot_swarm_deposit(parkinglot);

			truck_update_depatures(parkinglot, hour);
			truck_update_transit_times(parkinglot);
		}


		if (wearhouse_is_empty(wearhouse) &&
			!parckinglot_are_robots_peding(parkinglot) &&
			parkinglot_are_arrived_trucks_empty(parkinglot)){
			break;
		}
	}

	// House keeping
	while(parkinglot_are_trucks_in_transit(parkinglot)){
		truck_update_transit_times(parkinglot);
	}


	printf("***********************\n");
	printf("Day: %ld Hour: %ld\n", day, hour);
	printf("***********************\n");
	printf("Wearhose packages:\n");
	wearhouse_print_packages_info(wearhouse);
	printf("Arrived trucks info:\n");
	parkinglot_print_arrived_trucks(parkinglot);
	printf("Departed trucks info:\n");
	parkinglot_print_departed_trucks(parkinglot);
	printf("Parkinglot pending robots:\n");
	parkinglot_print_pending_robots(parkinglot);
	printf("Parkinglot standby robots:\n");
	parkinglot_print_standby_robots(parkinglot);
	printf("***********************\n");



	destroy_parkinglot(parkinglot);
	destroy_wearhouse(wearhouse);
	return 0;

}
