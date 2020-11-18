#ifndef WEARHOUSEMANAGER_H_
#define WEARHOUSEMANAGER_H_
#include <stdlib.h>
#include <string.h>

#define MAX_DESTINATION_NAME_LEN 20

typedef struct Package{
	long priority;
	char* destination;
}Package;

typedef struct Manifest{
	Package* package;
	struct Manifest* next;
	struct Manifest* prev;
}Manifest;

typedef struct Wearhouse{
	Package ** packages;
	long size;
	long capacity;
}Wearhouse;

typedef struct Robot{
	Manifest *manifest;
	long size;
	long capacity;
	struct Robot *next;
}Robot;

typedef struct Truck{
	Manifest *manifest;
	Robot *unloading_robots;
	char* destination;
	long size;
	long capacity;
	long in_transit_time;
	long transit_end_time;
//	long time_to_depature;
	long departure_time;
	struct Truck* next;
}Truck;

typedef struct Parkinglot{ // liste circulare cu santinela
	Truck* arrived_trucks;
	Truck* departed_trucks;
	Robot* pending_robots;
	Robot* standby_robots;
}Parkinglot;





Package *create_package(long priority, const char* destination);
void destroy_package(Package* package);

Manifest* create_manifest_node(void);
void destroy_manifest_node(Manifest* manifest_node);

Wearhouse* create_wearhouse(long capacity);
Wearhouse *open_wearhouse(const char* file_path);
long wearhouse_is_empty(Wearhouse *w);
long wearhouse_is_full(Wearhouse *w);
long wearhouse_max_package_priority(Wearhouse *w);
long wearhouse_min_package_priority(Wearhouse *w);
void wearhouse_print_packages_info(Wearhouse *w);
void destroy_wearhouse(Wearhouse* w);

Robot* create_robot(long capacity);
int robot_is_full(Robot* robot);
int robot_is_empty(Robot* robot);
Package* robot_get_wearhouse_priority_package(Wearhouse *w, long priority);
void robot_remove_wearhouse_package(Wearhouse *w, Package* package);
void robot_load_one_package(Robot* robot, Package* package);
long robot_load_packages(Wearhouse* w, Robot* robot);
Package* robot_get_destination_highest_priority_package(Robot* robot, const char* destination);
int robot_attach_find_truck(Robot* robot, Parkinglot *parcking);
void robot_unload_packages(Truck* truck, Robot* robot);
void robot_print_manifest_info(Robot* robot);
void destroy_robot(Robot* r);

Truck* create_truck(const char* destination, long capacity, long transit_time, long departure_time);
int truck_is_full(Truck *truck);
int truck_is_empty(Truck *truck);
long truck_destination_robots_unloading_size(Truck* truck);
void truck_arrived(Parkinglot *parkinglot, Truck* truck);
void truck_departed(Parkinglot *parkinglot, Truck* truck);
void truck_transfer_unloading_robots(Parkinglot* parkinglot, Truck* truck);
void truck_update_transit_times(Parkinglot* parkinglot);
void truck_update_depatures(Parkinglot* parkinglot, long day_hour);
void truck_print_info(Truck* truck);
void destroy_truck(Truck* truck);

Parkinglot* create_parkinglot(void);
Parkinglot* open_parckinglot(const char* file_path);
void parkinglot_add_robot(Parkinglot* parkinglot, Robot *robot);
void parkinglot_remove_robot(Parkinglot *parckinglot, Robot* robot);
int parckinglot_are_robots_peding(Parkinglot* parkinglot);
int parkinglot_are_arrived_trucks_empty(Parkinglot* parkinglot);
int parkinglot_are_trucks_in_transit(Parkinglot* parkinglot);
void parkinglot_print_arrived_trucks(Parkinglot* parkinglot);
void parkinglot_print_departed_trucks(Parkinglot* parkinglot);
void parkinglot_print_pending_robots(Parkinglot* parkinglot);
void parkinglot_print_standby_robots(Parkinglot* parkinglot);
void destroy_parkinglot(Parkinglot* parkinglot);

void robot_swarm_collect(Wearhouse *wearhouse, Parkinglot *parkinglot);
void robot_swarm_assign_to_trucks(Parkinglot *parkinglot);
void robot_swarm_deposit(Parkinglot* parkinglot);



#endif /* WEARHOUSEMANAGER_H_ */
