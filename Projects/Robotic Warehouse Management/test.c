#include <stdio.h>
#include <stdlib.h>
#include "WearhouseManager.h"
#define LOG_BUFFER_LEN 1024
#define NUM_OF_TEST_TRUCKS 5


typedef enum{
	PACKAGE_CREATE = 0,
	PACKAGE_DESTROY, 

	MANIFEST_NODE_CREATE,
	MANIFEST_NODE_DESTROY,

	WEARHOUSE_CREATE,
	WEARHOUSE_EMPTY_FULL, //5
	WEARHOUSE_PACKAGE_PRIORITY,
	WEARHOUSE_DESTROY,

	ROBOT_CREATE,
	ROBOT_EMPTY_FULL,
	ROBOT_GET_PRIO_PACKAGE, // 10
	ROBOT_REMOVE_WEARHOUSE_PACKAGE,
	ROBOT_LOAD_ONE_PACKAGE,
	ROBOT_LOAD_PACKAGES,
	ROBOT_GET_DESTINATION_HIGHEST_PRIO_PKG,
	ROBOT_DESTROY, // 15

	TRUCK_CREATE,
	TRUCK_EMPTY_FULL,
	TRUCK_ROBOT_UNLOAD_SIZE,	
	TRUCK_DESTROY, 

	ROBOT_UNLOAD_PACKAGES, // 20

	PARKINGLOT_CREATE,
	PARKINGLOT_ADD_ROBOT,
	PARKINGLOT_REMOVE_ROBOT,
	PARKINGLOT_PENDING_ROBOTS,
	PARKINGLOT_ARRIVED_TRUCKS_EMPTY, // 25
	PARKINGLOT_TRUCKS_IN_TRANSIT,
	PARKINGLOT_DESTROY,

	TRUCK_DEPARTED,
	TRUCK_ARRIVED,
	TRUCK_UPDATE_TRANSIT_TIMES, // 30
	TRUCK_TRANSFER_ROBOTS,
	TRUCK_UPDATE_DEPARTURES
}Test;

void logger(const char* file, Test test, char* output){
	char full_file_path[256];
	snprintf(full_file_path, 256, "%s%d", file, (int) test);
	FILE *f = fopen(full_file_path, "a");
	if(f == NULL)
		goto file_open_exception;

	fprintf(f,"%s",output);
	fclose(f);

	file_open_exception:
	return;

}

int main(int argc, char** argv){
	if(argc < 4){
		fprintf(stderr, "USAGE: %s <wearhouse file path> <output file path> <test_number>\n",argv[0]);
		exit(1);
	}

	char *wearhouse_path = argv[1];
	char * output_path = argv[2];
	Test test = (Test) atoi(argv[3]);
	char buf[LOG_BUFFER_LEN];

	long size;
	Package* package;
	Package* package_aux;
	Manifest* manifest;
	Manifest* m_iterator;
	Wearhouse *wearhouse;
	Robot *robot;
	Robot *r_iterator;
	Truck *truck;
	Truck *trucks[NUM_OF_TEST_TRUCKS];
	Parkinglot *parkinglot;

	switch(test){
	case PACKAGE_CREATE:
		package = create_package(1, NULL);
		snprintf(buf, LOG_BUFFER_LEN-1,"%ld %d\n", package->priority, (int) (package->destination == NULL));
		logger(output_path, PACKAGE_CREATE, buf);
		free(package);

		package = create_package(16, "Arad");
		snprintf(buf, LOG_BUFFER_LEN-1, "%ld %s\n", package->priority, package->destination);
		logger(output_path, PACKAGE_CREATE, buf);
//		free(package->destination);
//		free(package);
		break;

	case PACKAGE_DESTROY:
		package = create_package(16, "Brasov");
		destroy_package(package);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (int)(package!=NULL));
		logger(output_path, PACKAGE_DESTROY, buf);
		break;

	case MANIFEST_NODE_CREATE:
		manifest = create_manifest_node();
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int)(manifest != NULL));
		logger(output_path, MANIFEST_NODE_CREATE, buf);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int)(manifest->package == NULL),
				(int)(manifest->next == NULL),
				(int)(manifest->prev == NULL));
		logger(output_path, MANIFEST_NODE_CREATE, buf);
//		free(manifest);
		break;

	case MANIFEST_NODE_DESTROY:
		manifest = create_manifest_node();
		destroy_manifest_node(manifest);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (int)(manifest!=NULL));
		logger(output_path, MANIFEST_NODE_DESTROY, buf);
		break;

	case WEARHOUSE_CREATE:
		wearhouse = create_wearhouse(0);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (int)(wearhouse==NULL));
		logger(output_path, WEARHOUSE_CREATE, buf);

		wearhouse = create_wearhouse(5000);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (int)(wearhouse!=NULL));
		logger(output_path, WEARHOUSE_CREATE, buf);

		snprintf(buf, LOG_BUFFER_LEN-1,"%ld %ld\n", wearhouse->capacity, wearhouse->size);
		logger(output_path, WEARHOUSE_CREATE, buf);


		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d",
				(int)sizeof(wearhouse->packages),
				(int)(wearhouse->packages[0] == NULL),
				(int)(wearhouse->packages[999] != NULL));
		logger(output_path, WEARHOUSE_CREATE, buf);
		break;

	case WEARHOUSE_EMPTY_FULL:

		wearhouse = create_wearhouse(5);
		snprintf(buf, LOG_BUFFER_LEN-1,"%ld %ld %ld\n",
				wearhouse->size,
				wearhouse_is_empty(wearhouse),
				wearhouse_is_full(wearhouse));
		logger(output_path, WEARHOUSE_EMPTY_FULL, buf);

		wearhouse->size = 3;
		snprintf(buf, LOG_BUFFER_LEN-1,"%ld %ld %ld\n",
				wearhouse->size,
				wearhouse_is_empty(wearhouse),
				wearhouse_is_full(wearhouse));
		logger(output_path, WEARHOUSE_EMPTY_FULL, buf);
		wearhouse->size = 5;
		snprintf(buf, LOG_BUFFER_LEN-1,"%ld %ld %ld\n",
				wearhouse->size,
				wearhouse_is_empty(wearhouse),
				wearhouse_is_full(wearhouse));
		logger(output_path, WEARHOUSE_EMPTY_FULL, buf);
		break;
	case WEARHOUSE_PACKAGE_PRIORITY:
		wearhouse = open_wearhouse(wearhouse_path);
		long max = wearhouse_max_package_priority(wearhouse);
		long min = wearhouse_min_package_priority(wearhouse);

		snprintf(buf, LOG_BUFFER_LEN-1,"%ld %ld \n", max, min);
		logger(output_path, WEARHOUSE_PACKAGE_PRIORITY, buf);
		break;


	case WEARHOUSE_DESTROY:
		wearhouse = open_wearhouse(wearhouse_path);
		destroy_wearhouse(wearhouse);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (wearhouse != NULL));
		logger(output_path, WEARHOUSE_DESTROY, buf);
		break;

	case ROBOT_CREATE:
		robot = create_robot(0);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (robot != NULL));
		logger(output_path, ROBOT_CREATE, buf);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %ld %ld\n",
				(int) (robot->manifest == NULL),
				(int) (robot->next == NULL),
				robot->size,
				robot->capacity
		);
		logger(output_path, ROBOT_CREATE, buf);


		robot = create_robot(50);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (robot != NULL));
		logger(output_path, ROBOT_CREATE, buf);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (robot->manifest == NULL),
				(int) (robot->next == NULL),
				(int)(robot->size == 0),
				(int) (robot->capacity == 50)
		);
		logger(output_path, ROBOT_CREATE, buf);
		break;

	case ROBOT_EMPTY_FULL:
		robot = create_robot(5);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (robot->capacity == 5),
				(int) (robot->size == 0),
				robot_is_empty(robot),
				robot_is_full(robot));
		logger(output_path, ROBOT_EMPTY_FULL, buf);

		robot->size = 3;
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (robot->capacity == 5),
				(int) (robot->size == 0),
				robot_is_empty(robot),
				robot_is_full(robot));
		logger(output_path, ROBOT_EMPTY_FULL, buf);

		robot->size = 5;
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (robot->capacity == 5),
				(int) (robot->size == 0),
				robot_is_empty(robot),
				robot_is_full(robot));
		logger(output_path, ROBOT_EMPTY_FULL, buf);
		break;

	case ROBOT_GET_PRIO_PACKAGE:
		wearhouse = open_wearhouse(wearhouse_path);
		robot = create_robot(5);
		package = robot_get_wearhouse_priority_package(wearhouse, -1);

		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (int) (package == NULL));
		logger(output_path, ROBOT_GET_PRIO_PACKAGE, buf);

		for(int i = 0; i < 10; i++){
			package = robot_get_wearhouse_priority_package(wearhouse, i);
			snprintf(buf, LOG_BUFFER_LEN-1,"%d %ld %s\n",
					(int) (package != NULL), package->priority, package->destination);
			logger(output_path, ROBOT_GET_PRIO_PACKAGE, buf);
		}

//		destroy_wearhouse(wearhouse);
		break;

	case ROBOT_REMOVE_WEARHOUSE_PACKAGE:
		wearhouse = open_wearhouse(wearhouse_path);

		while(!wearhouse_is_empty(wearhouse)){
			size = wearhouse->size;
			package = wearhouse->packages[0];
			robot_remove_wearhouse_package(wearhouse, package);
			package_aux = robot_get_wearhouse_priority_package(wearhouse, package->priority);

			snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",(int) (size != wearhouse->size), package != package_aux);
			logger(output_path, ROBOT_REMOVE_WEARHOUSE_PACKAGE, buf);
		}
//		destroy_wearhouse(wearhouse);

		break;
	case ROBOT_LOAD_ONE_PACKAGE:
		wearhouse = open_wearhouse(wearhouse_path);
		robot = create_robot(5);

		robot_load_one_package(robot, wearhouse->packages[0]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %ld %s %d\n",
				(int) (robot->manifest != NULL),
				(int) (robot->manifest->package != NULL),
				robot->manifest->package->priority,
				robot->manifest->package->destination,
				!robot_is_empty(robot));
		logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);

		robot_load_one_package(robot, wearhouse->packages[1]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int) (robot->manifest->next != NULL),
				(int) (robot->manifest->package->priority > robot->manifest->next->package->priority));
		logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);
		m_iterator = robot->manifest;
		while(m_iterator != NULL){
			snprintf(buf, LOG_BUFFER_LEN-1,"%ld %s\n",
					m_iterator->package->priority,
					m_iterator->package->destination);
			logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);
			m_iterator = m_iterator->next;
		}


		robot_load_one_package(robot, wearhouse->packages[2]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int) (robot->manifest->next != NULL),
				(int) (robot->manifest->package->priority > robot->manifest->next->package->priority),
				(int)(robot->manifest->next->package->priority > robot->manifest->next->next->package->priority));
		logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);
		m_iterator = robot->manifest;
		while(m_iterator != NULL){
			snprintf(buf, LOG_BUFFER_LEN-1,"%ld %s\n",
					m_iterator->package->priority,
					m_iterator->package->destination);
			logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);
			m_iterator = m_iterator->next;
		}

		robot_load_one_package(robot, wearhouse->packages[3]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int) (robot->manifest->package->priority == 9),
				(int) (robot->manifest->package->priority > robot->manifest->next->package->priority),
				(int)(robot->manifest->next->package->priority > robot->manifest->next->next->package->priority));
		logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);
		m_iterator = robot->manifest;
		while(m_iterator != NULL){
			snprintf(buf, LOG_BUFFER_LEN-1,"%ld %s\n",
					m_iterator->package->priority,
					m_iterator->package->destination);
			logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);
			m_iterator = m_iterator->next;
		}

		robot_load_one_package(robot, wearhouse->packages[4]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int) (robot->manifest->package->priority == 9),
				(int) (robot->manifest->package->priority == robot->manifest->next->package->priority),
				(int)(robot->manifest->next->package->priority > robot->manifest->next->next->package->priority));
		logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);
		m_iterator = robot->manifest;
		while(m_iterator != NULL){
			snprintf(buf, LOG_BUFFER_LEN-1,"%ld %s\n",
					m_iterator->package->priority,
					m_iterator->package->destination);
			logger(output_path, ROBOT_LOAD_ONE_PACKAGE, buf);
			m_iterator = m_iterator->next;
		}

//		destroy_wearhouse(wearhouse);
		break;


	case ROBOT_LOAD_PACKAGES:
		wearhouse = open_wearhouse(wearhouse_path);
		robot = create_robot(5);
		robot_load_packages(wearhouse, robot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (robot->manifest != NULL),
				(int) (robot->manifest->package != NULL),
				!robot_is_empty(robot),
				robot_is_full(robot));
		logger(output_path, ROBOT_LOAD_PACKAGES, buf);

		m_iterator = robot->manifest;
		while(m_iterator != NULL){
			snprintf(buf, LOG_BUFFER_LEN-1,"%ld %s\n",
					m_iterator->package->priority,
					m_iterator->package->destination);
			logger(output_path, ROBOT_LOAD_PACKAGES, buf);
			m_iterator = m_iterator->next;
		}
		break;

	case ROBOT_GET_DESTINATION_HIGHEST_PRIO_PKG:
		wearhouse = open_wearhouse(wearhouse_path);
		robot = create_robot(6);
		for(int i = 0; i < 6; i++){
			robot_load_one_package(robot, wearhouse->packages[i]);
		}

		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (robot->manifest != NULL),
				(int) (robot->manifest->package != NULL),
				!robot_is_empty(robot),
				robot_is_full(robot));
		logger(output_path, ROBOT_GET_DESTINATION_HIGHEST_PRIO_PKG, buf);

		m_iterator = robot->manifest;
		while(m_iterator != NULL){
			snprintf(buf, LOG_BUFFER_LEN-1,"%ld %s\n",
					m_iterator->package->priority,
					m_iterator->package->destination);
			logger(output_path, ROBOT_GET_DESTINATION_HIGHEST_PRIO_PKG, buf);
			m_iterator = m_iterator->next;
		}
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (robot->manifest != NULL),
				(int) (robot->manifest->package != NULL),
				!robot_is_empty(robot),
				robot_is_full(robot));
		logger(output_path, ROBOT_GET_DESTINATION_HIGHEST_PRIO_PKG, buf);

		package = robot_get_destination_highest_priority_package(robot, "Arad");
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %ld\n",
				(int) (package != NULL),
				package->priority);
		logger(output_path, ROBOT_GET_DESTINATION_HIGHEST_PRIO_PKG, buf);
		break;
	case ROBOT_DESTROY:
		robot = NULL;
		robot = create_robot(5);
		destroy_robot(robot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d \n",
				(int) (robot != NULL));
		logger(output_path, ROBOT_DESTROY, buf);
		break;

	case TRUCK_CREATE:
		truck = create_truck(NULL, 0, 0, 0);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %ld %ld %d %ld %ld %ld %d\n",
				(int) (truck != NULL),
				(int) (truck->manifest == NULL),
				(int) (truck->unloading_robots == NULL),
				truck->capacity,
				truck->size,
				(int) (truck->destination == NULL),
				truck->in_transit_time,
				truck->transit_end_time,
				truck->departure_time,
				(int) (truck->next == NULL)
		);
		logger(output_path, TRUCK_CREATE, buf);

		truck = create_truck("Timisoara", 5, 10, 18);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %ld %ld %d %ld %ld %ld %d\n",
				(int) (truck != NULL),
				(int) (truck->manifest == NULL),
				(int) (truck->unloading_robots == NULL),
				truck->capacity,
				truck->size,
				(int) (truck->destination != NULL),
				truck->in_transit_time,
				truck->transit_end_time,
				truck->departure_time,
				(int) (truck->next == NULL)
		);
		logger(output_path, TRUCK_CREATE, buf);


		break;
	case TRUCK_EMPTY_FULL:
		truck = create_truck(NULL, 3, 0, 0);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				truck_is_empty(truck),
				truck_is_full(truck));
		logger(output_path, TRUCK_EMPTY_FULL, buf);

		truck->size = 1;
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				truck_is_empty(truck),
				truck_is_full(truck));
		logger(output_path, TRUCK_EMPTY_FULL, buf);

		truck->size = 3;
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				truck_is_empty(truck),
				truck_is_full(truck));
		logger(output_path, TRUCK_EMPTY_FULL, buf);

		break;
	case  TRUCK_ROBOT_UNLOAD_SIZE:
		wearhouse = open_wearhouse(wearhouse_path);
		truck = create_truck("Arad", 10, 0, 0);
		size = truck_destination_robots_unloading_size(truck);
		snprintf(buf, LOG_BUFFER_LEN-1,"%ld\n", size);
		logger(output_path, TRUCK_ROBOT_UNLOAD_SIZE, buf);

		robot = create_robot(5);
		robot_load_packages(wearhouse, robot);

		r_iterator = create_robot(3);
		robot_load_packages(wearhouse, r_iterator);


		truck->unloading_robots = robot;
		robot->next = r_iterator;

		size = truck_destination_robots_unloading_size(truck);
		snprintf(buf, LOG_BUFFER_LEN-1,"%ld\n", size);
		logger(output_path, TRUCK_ROBOT_UNLOAD_SIZE, buf);
//		destroy_wearhouse(wearhouse);
		break;
	case TRUCK_DESTROY:
		truck = create_truck("Arad", 10, 0, 0);
		destroy_truck(truck);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d \n",
				(int) (truck != NULL));
		logger(output_path, TRUCK_DESTROY, buf);
		break;
	case ROBOT_UNLOAD_PACKAGES:
		wearhouse = open_wearhouse(wearhouse_path);
		robot = create_robot(10);
		robot_load_packages(wearhouse, robot);

		truck = create_truck("Arad", 10, 0, 0);
		robot_unload_packages(truck, robot);

		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int) (truck->size == 1),
				(int) (strncmp("Bistrita", robot->manifest->package->destination, MAX_DESTINATION_NAME_LEN) == 0));
		logger(output_path, ROBOT_UNLOAD_PACKAGES, buf);

		free(robot->manifest->package->destination);
		robot->manifest->package->destination = strdup("Arad");

		robot_unload_packages(truck, robot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int) (truck->size == 2),
				(int) (strncmp("Craiova", robot->manifest->package->destination, MAX_DESTINATION_NAME_LEN) == 0));
		logger(output_path, ROBOT_UNLOAD_PACKAGES, buf);

//		destroy_truck(truck);
		truck = create_truck("Craiova", 10, 0, 0);
		free(robot->manifest->next->package->destination);
		robot->manifest->next->package->destination = strdup("Craiova");
		robot->manifest->next->package->priority = 7;
		free(robot->manifest->next->next->package->destination);
		robot->manifest->next->next->package->destination = strdup("Craiova");
		robot->manifest->next->next->package->priority = 5;
		robot_unload_packages(truck, robot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d %d\n",
				(int) (truck->size == 3),
				(int) (truck->unloading_robots == NULL),
				(int) (truck->manifest != NULL),
				(int) (truck->manifest->next != NULL),
				(int) (truck->manifest->next->next != NULL),
				(int) (truck->manifest->next->next->next == NULL));
		logger(output_path, ROBOT_UNLOAD_PACKAGES, buf);

//		destroy_truck(truck);
//		destroy_robot(robot);
//		destroy_wearhouse(wearhouse);
		break;
	case PARKINGLOT_CREATE:
		parkinglot = create_parkinglot();
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d\n",
				(int) (parkinglot != NULL),
				(int) (parkinglot->arrived_trucks != NULL),
				(int) (parkinglot->departed_trucks != NULL),
				(int) (parkinglot->pending_robots != NULL),
				(int) (parkinglot->standby_robots != NULL));
		logger(output_path, PARKINGLOT_CREATE, buf);

		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (parkinglot->arrived_trucks == parkinglot->arrived_trucks->next),
				(int) (parkinglot->departed_trucks == parkinglot->departed_trucks->next),
				(int) (parkinglot->pending_robots == parkinglot->pending_robots->next),
				(int) (parkinglot->standby_robots == parkinglot->standby_robots->next));
		logger(output_path, PARKINGLOT_CREATE, buf);
		break;
	case PARKINGLOT_ADD_ROBOT:
		robot = create_robot(10);
		r_iterator = create_robot(20);
		parkinglot = create_parkinglot();

		parkinglot_add_robot(parkinglot, robot);
		parkinglot_add_robot(parkinglot, r_iterator);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (parkinglot->pending_robots == parkinglot->pending_robots->next),
				(int) (parkinglot->standby_robots != parkinglot->standby_robots->next),
				(int) (parkinglot->standby_robots != parkinglot->standby_robots->next->next),
				(int) (parkinglot->standby_robots == parkinglot->standby_robots->next->next->next));
		logger(output_path, PARKINGLOT_ADD_ROBOT, buf);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int) (parkinglot->standby_robots->next->capacity == 20),
				(int) (parkinglot->standby_robots->next->next->capacity == 10));
		logger(output_path, PARKINGLOT_ADD_ROBOT, buf);

//		destroy_robot(robot);
//		destroy_robot(r_iterator);
		parkinglot->standby_robots->next = parkinglot->standby_robots;
		robot = create_robot(10);
		r_iterator = create_robot(20);
		wearhouse = open_wearhouse(wearhouse_path);
		robot_load_packages(wearhouse, robot);
		parkinglot_add_robot(parkinglot, robot);
		parkinglot_add_robot(parkinglot, r_iterator);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (parkinglot->pending_robots != parkinglot->pending_robots->next),
				(int) (parkinglot->standby_robots != parkinglot->standby_robots->next),
				(int) (parkinglot->pending_robots->next->capacity == 10),
				(int) (parkinglot->standby_robots->next->capacity == 20));
		logger(output_path, PARKINGLOT_ADD_ROBOT, buf);
//		destroy_robot(robot);
//		destroy_robot(r_iterator);
		parkinglot->standby_robots->next = parkinglot->standby_robots;
		parkinglot->pending_robots->next = parkinglot->pending_robots;
		robot = create_robot(10);
		r_iterator = create_robot(20);
		wearhouse = open_wearhouse(wearhouse_path);
		robot_load_packages(wearhouse, robot);
		robot_load_packages(wearhouse, r_iterator);
		parkinglot_add_robot(parkinglot, robot);
		parkinglot_add_robot(parkinglot, r_iterator);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (parkinglot->pending_robots != parkinglot->pending_robots->next),
				(int) (parkinglot->standby_robots == parkinglot->standby_robots->next),
				(int) (parkinglot->pending_robots != parkinglot->pending_robots->next->next),
				(int) (parkinglot->pending_robots == parkinglot->pending_robots->next->next->next));
		logger(output_path, PARKINGLOT_ADD_ROBOT, buf);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int) (parkinglot->pending_robots->next->size == 20),
				(int) (parkinglot->pending_robots->next->next->size == 10));
		logger(output_path, PARKINGLOT_ADD_ROBOT, buf);
//		destroy_wearhouse(wearhouse);
//		destroy_robot(robot);
//		destroy_robot(r_iterator);
		break;
	case PARKINGLOT_REMOVE_ROBOT:
		robot = create_robot(10);
		r_iterator = create_robot(20);
		parkinglot = create_parkinglot();

		parkinglot_add_robot(parkinglot, robot);
		parkinglot_add_robot(parkinglot, r_iterator);
		parkinglot_remove_robot(parkinglot, robot);

		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (parkinglot->pending_robots == parkinglot->pending_robots->next),
				(int) (parkinglot->standby_robots != parkinglot->standby_robots->next),
				(int) (parkinglot->standby_robots == parkinglot->standby_robots->next->next),
				(int) (parkinglot->standby_robots->next->capacity == 20));
		logger(output_path, PARKINGLOT_REMOVE_ROBOT, buf);

		parkinglot_remove_robot(parkinglot, r_iterator);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int) (parkinglot->pending_robots == parkinglot->pending_robots->next),
				(int) (parkinglot->standby_robots == parkinglot->standby_robots->next));
		logger(output_path, PARKINGLOT_REMOVE_ROBOT, buf);


		parkinglot->standby_robots->next = parkinglot->standby_robots;
		wearhouse = open_wearhouse(wearhouse_path);
		robot_load_packages(wearhouse, robot);
		robot_load_packages(wearhouse, r_iterator);
		parkinglot_add_robot(parkinglot, robot);
		parkinglot_add_robot(parkinglot, r_iterator);
		parkinglot_remove_robot(parkinglot, r_iterator);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int) (parkinglot->standby_robots == parkinglot->standby_robots->next),
				(int) (parkinglot->pending_robots != parkinglot->pending_robots->next),
				(int) (parkinglot->pending_robots == parkinglot->pending_robots->next->next),
				(int) (parkinglot->pending_robots->next->capacity == 10));
		logger(output_path, PARKINGLOT_REMOVE_ROBOT, buf);


		parkinglot_remove_robot(parkinglot, robot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int) (parkinglot->pending_robots == parkinglot->pending_robots->next),
				(int) (parkinglot->standby_robots == parkinglot->standby_robots->next));
		logger(output_path, PARKINGLOT_REMOVE_ROBOT, buf);

//		destroy_wearhouse(wearhouse);
//		destroy_robot(robot);
//		destroy_robot(r_iterator);
		break;
	case PARKINGLOT_PENDING_ROBOTS:
		parkinglot = create_parkinglot();
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int) (!parckinglot_are_robots_peding(parkinglot)));
		logger(output_path, PARKINGLOT_PENDING_ROBOTS, buf);

		wearhouse = open_wearhouse(wearhouse_path);
		robot = create_robot(10);
		robot_load_packages(wearhouse, robot);
		parkinglot_add_robot(parkinglot, robot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int) (parckinglot_are_robots_peding(parkinglot)));
		logger(output_path, PARKINGLOT_PENDING_ROBOTS, buf);

//		destroy_wearhouse(wearhouse);
//		destroy_robot(robot);
		break;
	case PARKINGLOT_ARRIVED_TRUCKS_EMPTY:
		robot = create_robot(5);
		wearhouse = open_wearhouse(wearhouse_path);
		robot_load_packages(wearhouse, robot);
		truck = create_truck("Arad", 10, 0, 0);
		parkinglot = create_parkinglot();
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int) (parkinglot_are_arrived_trucks_empty(parkinglot)));
		logger(output_path, PARKINGLOT_ARRIVED_TRUCKS_EMPTY, buf);

		parkinglot->arrived_trucks->next = truck;
		truck->next= parkinglot->arrived_trucks;
		robot_unload_packages(truck, robot);

		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int) (!parkinglot_are_arrived_trucks_empty(parkinglot)));
		logger(output_path, PARKINGLOT_ARRIVED_TRUCKS_EMPTY, buf);

		break;
	case PARKINGLOT_TRUCKS_IN_TRANSIT:
		truck = create_truck("Arad", 10, 0, 0);
		parkinglot = create_parkinglot();
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int) (!parkinglot_are_trucks_in_transit(parkinglot)));
		logger(output_path, PARKINGLOT_TRUCKS_IN_TRANSIT, buf);

		parkinglot->departed_trucks->next = truck;
		truck->next = parkinglot->departed_trucks;

		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int) (parkinglot_are_trucks_in_transit(parkinglot)));
		logger(output_path, PARKINGLOT_TRUCKS_IN_TRANSIT, buf);
//		destroy_truck(truck);

		break;
	case PARKINGLOT_DESTROY:
		parkinglot = create_parkinglot();
		destroy_parkinglot(parkinglot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n", (int)(parkinglot!=NULL));
		logger(output_path, PARKINGLOT_DESTROY, buf);
		break;

	case TRUCK_DEPARTED:
		parkinglot = create_parkinglot();

		trucks[0] = create_truck("Arad", 10, 12, 8);
		trucks[1] = create_truck("Craiova", 5, 4, 2);
		trucks[2] = create_truck("Brasov", 5, 4, 14);
		trucks[3] = create_truck("Arad", 5, 12, 16);
		trucks[4] = create_truck("Arad", 8, 12, 5);
		parkinglot->arrived_trucks->next = trucks[3];
		trucks[3]->next = trucks[4];
		trucks[4]->next = parkinglot->arrived_trucks;
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int)(parkinglot->departed_trucks == parkinglot->departed_trucks->next)
		);
		logger(output_path, TRUCK_DEPARTED, buf);

		truck_departed(parkinglot, trucks[0]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int)(parkinglot->departed_trucks != parkinglot->departed_trucks->next),
				(int)(parkinglot->arrived_trucks->next == trucks[3]),
				(int)(parkinglot->arrived_trucks->next->next == trucks[4]),
				(int)(parkinglot->arrived_trucks == trucks[4]->next)
		);
		logger(output_path, TRUCK_DEPARTED, buf);

		truck_departed(parkinglot, trucks[1]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int)(parkinglot->departed_trucks != parkinglot->departed_trucks->next),
				(int)(parkinglot->arrived_trucks->next == trucks[3]),
				(int)(parkinglot->arrived_trucks->next->next == trucks[4]),
				(int)(parkinglot->arrived_trucks == trucks[4]->next)
		);
		logger(output_path, TRUCK_DEPARTED, buf);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int)(parkinglot->departed_trucks->next->departure_time == 2),
				(int)(parkinglot->departed_trucks->next->next->departure_time == 8)
		);
		logger(output_path, TRUCK_DEPARTED, buf);


		truck_departed(parkinglot, trucks[2]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int)(parkinglot->departed_trucks != parkinglot->departed_trucks->next),
				(int)(parkinglot->arrived_trucks->next == trucks[3]),
				(int)(parkinglot->arrived_trucks->next->next == trucks[4]),
				(int)(parkinglot->arrived_trucks == trucks[4]->next)
		);
		logger(output_path, TRUCK_DEPARTED, buf);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int)(parkinglot->departed_trucks->next->departure_time == 2),
				(int)(parkinglot->departed_trucks->next->next->departure_time == 8),
				(int)(parkinglot->departed_trucks->next->next->next->departure_time == 14)
		);
		logger(output_path, TRUCK_DEPARTED, buf);


		truck_departed(parkinglot, trucks[3]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d\n",
				(int)(parkinglot->departed_trucks->next->departure_time == 2),
				(int)(parkinglot->departed_trucks->next->next->departure_time == 8),
				(int)(parkinglot->departed_trucks->next->next->next->departure_time == 14),
				(int)(parkinglot->departed_trucks->next->next->next->next->departure_time == 16),
				(int)(parkinglot->arrived_trucks->next->departure_time == 5)
		);
		logger(output_path, TRUCK_DEPARTED, buf);

		truck_departed(parkinglot, trucks[4]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d %d\n",
				(int)(parkinglot->departed_trucks->next->departure_time == 2),
				(int)(parkinglot->departed_trucks->next->next->departure_time == 5),
				(int)(parkinglot->departed_trucks->next->next->next->departure_time == 8),
				(int)(parkinglot->departed_trucks->next->next->next->next->departure_time == 14),
				(int)(parkinglot->departed_trucks->next->next->next->next->next->departure_time == 16),
				(int)(parkinglot->arrived_trucks->next == parkinglot->arrived_trucks)
		);
		logger(output_path, TRUCK_DEPARTED, buf);

//		destroy_parkinglot(parkinglot);
		break;
	case TRUCK_ARRIVED:
		parkinglot = create_parkinglot();
		trucks[0] = create_truck("Arad", 10, 12, 8);
		trucks[1] = create_truck("Craiova", 5, 4, 2);
		trucks[2] = create_truck("Brasov", 5, 4, 14);
		trucks[3] = create_truck("Arad", 5, 12, 16);
		trucks[4] = create_truck("Arad", 8, 12, 5);
		parkinglot->departed_trucks->next = trucks[3];
		trucks[3]->next = trucks[4];
		trucks[4]->next = parkinglot->departed_trucks;
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d\n",
				(int)(parkinglot->arrived_trucks == parkinglot->arrived_trucks->next),
				(int)(parkinglot->departed_trucks->next == trucks[3]),
				(int)(parkinglot->departed_trucks->next->next == trucks[4]),
				(int)(parkinglot->departed_trucks == trucks[4]->next)
		);
		logger(output_path, TRUCK_ARRIVED, buf);

		wearhouse = open_wearhouse(wearhouse_path);
		robot = create_robot(100);
		robot_load_packages(wearhouse, robot);
		robot_print_manifest_info(robot);

		robot_unload_packages(trucks[0], robot);

		truck_print_info(trucks[0]);
		printf("*************\n");
		robot_print_manifest_info(robot);

		truck_arrived(parkinglot, trucks[0]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d %d %d\n",
				(int)(parkinglot->arrived_trucks != parkinglot->arrived_trucks->next),
				(int)(parkinglot->arrived_trucks->next->in_transit_time == 0),
				(int)(parkinglot->arrived_trucks->next->size == 0),
				(int)(parkinglot->arrived_trucks->next->manifest == NULL),
				(int)(parkinglot->departed_trucks->next == trucks[3]),
				(int)(parkinglot->departed_trucks->next->next == trucks[4]),
				(int)(parkinglot->departed_trucks == trucks[4]->next)
		);
		logger(output_path, TRUCK_ARRIVED, buf);


		robot_unload_packages(trucks[1], robot);

		truck_print_info(trucks[1]);
		printf("*************\n");
		robot_print_manifest_info(robot);

		truck_arrived(parkinglot, trucks[1]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d %d %d %d\n",
				(int)(parkinglot->arrived_trucks->next->destination[0] == 'A'),
				(int)(parkinglot->arrived_trucks->next->next->destination[0] == 'C'),
				(int)(parkinglot->arrived_trucks->next->in_transit_time == 0),
				(int)(parkinglot->arrived_trucks->next->size == 0),
				(int)(parkinglot->arrived_trucks->next->manifest == NULL),
				(int)(parkinglot->departed_trucks->next == trucks[3]),
				(int)(parkinglot->departed_trucks->next->next == trucks[4]),
				(int)(parkinglot->departed_trucks == trucks[4]->next)
		);
		logger(output_path, TRUCK_ARRIVED, buf);


		robot_unload_packages(trucks[2], robot);

		truck_print_info(trucks[2]);
		printf("*************\n");
		robot_print_manifest_info(robot);

		truck_arrived(parkinglot, trucks[2]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d %d %d %d %d\n",
				(int)(parkinglot->arrived_trucks->next->destination[0] == 'A'),
				(int)(parkinglot->arrived_trucks->next->next->destination[0] == 'B'),
				(int)(parkinglot->arrived_trucks->next->next->next->destination[0] == 'C'),
				(int)(parkinglot->arrived_trucks->next->in_transit_time == 0),
				(int)(parkinglot->arrived_trucks->next->size == 0),
				(int)(parkinglot->arrived_trucks->next->manifest == NULL),
				(int)(parkinglot->departed_trucks->next == trucks[3]),
				(int)(parkinglot->departed_trucks->next->next == trucks[4]),
				(int)(parkinglot->departed_trucks == trucks[4]->next)
		);
		logger(output_path, TRUCK_ARRIVED, buf);



		robot_unload_packages(trucks[3], robot);

		truck_print_info(trucks[3]);
		printf("*************\n");
		robot_print_manifest_info(robot);

		truck_arrived(parkinglot, trucks[3]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d %d %d %d %d\n",
				(int)(parkinglot->arrived_trucks->next->destination[0] == 'A'),
				(int)(parkinglot->arrived_trucks->next->next->destination[0] == 'A'),
				(int)(parkinglot->arrived_trucks->next->departure_time < parkinglot->arrived_trucks->next->next->departure_time),
				(int)(parkinglot->arrived_trucks->next->next->next->destination[0] == 'B'),
				(int)(parkinglot->arrived_trucks->next->next->next->next->destination[0] == 'C'),
				(int)(parkinglot->arrived_trucks->next->in_transit_time == 0),
				(int)(parkinglot->arrived_trucks->next->size == 0),
				(int)(parkinglot->arrived_trucks->next->manifest == NULL),
				(int)(parkinglot->departed_trucks->next != parkinglot->departed_trucks)
		);
		logger(output_path, TRUCK_ARRIVED, buf);


		robot_unload_packages(trucks[4], robot);

		truck_print_info(trucks[4]);
		printf("*************\n");
		robot_print_manifest_info(robot);

		truck_arrived(parkinglot, trucks[4]);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d %d %d %d %d %d %d  %d %d %d\n",
				(int)(parkinglot->arrived_trucks->next->destination[0] == 'A'),
				(int)(parkinglot->arrived_trucks->next->next->destination[0] == 'A'),
				(int)(parkinglot->arrived_trucks->next->next->next->destination[0] == 'A'),
				(int)(parkinglot->arrived_trucks->next->departure_time < parkinglot->arrived_trucks->next->next->departure_time),
				(int)(parkinglot->arrived_trucks->next->next->departure_time < parkinglot->arrived_trucks->next->next->next->departure_time),
				(int)(parkinglot->arrived_trucks->next->next->next->next->destination[0] == 'B'),
				(int)(parkinglot->arrived_trucks->next->next->next->next->next->destination[0] == 'C'),
				(int)(parkinglot->arrived_trucks->next->in_transit_time == 0),
				(int)(parkinglot->arrived_trucks->next->size == 0),
				(int)(parkinglot->arrived_trucks->next->manifest == NULL),
				(int)(parkinglot->departed_trucks->next == parkinglot->departed_trucks),
				(int)(robot->size == 86)
		);
		logger(output_path, TRUCK_ARRIVED, buf);
		break;
	case TRUCK_UPDATE_TRANSIT_TIMES:
		parkinglot = create_parkinglot();
		truck = create_truck("Sinaia", 10, 2, 8);
		truck_departed(parkinglot, truck);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d\n",
				(int)(parkinglot->departed_trucks->next != parkinglot->departed_trucks)

		);
		logger(output_path, TRUCK_UPDATE_TRANSIT_TIMES, buf);

		truck_update_transit_times(parkinglot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int)(parkinglot->departed_trucks->next != parkinglot->departed_trucks),
				(int)(parkinglot->arrived_trucks->next == parkinglot->arrived_trucks),
				(int)(parkinglot->departed_trucks->next->in_transit_time == 1)

		);
		logger(output_path, TRUCK_UPDATE_TRANSIT_TIMES, buf);


		truck_update_transit_times(parkinglot);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int)(parkinglot->departed_trucks->next == parkinglot->departed_trucks),
				(int)(parkinglot->arrived_trucks->next != parkinglot->arrived_trucks),
				(int)(parkinglot->arrived_trucks->next->in_transit_time == 0)

		);
		logger(output_path, TRUCK_UPDATE_TRANSIT_TIMES, buf);

		break;
	case TRUCK_TRANSFER_ROBOTS:
		parkinglot = create_parkinglot();
		truck = create_truck("Arad", 10, 12, 8);
		truck->unloading_robots = create_robot(10);
		truck->unloading_robots->next = create_robot(20);
		truck_transfer_unloading_robots(parkinglot, truck);

		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int)(parkinglot->standby_robots->next->capacity == 20),
				(int)(parkinglot->standby_robots->next->next->capacity == 10),
				(int)(truck->unloading_robots == NULL)
		);
		logger(output_path, TRUCK_TRANSFER_ROBOTS, buf);
		break;

	case TRUCK_UPDATE_DEPARTURES:
		parkinglot = create_parkinglot();
		truck = create_truck("Arad", 10, 12, 8);
		truck_arrived(parkinglot, truck);
		truck = create_truck("Arad", 10, 12, 16);
		truck_arrived(parkinglot, truck);

		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int)(parkinglot->arrived_trucks->next->departure_time == 8),
				(int)(parkinglot->arrived_trucks->next->next->departure_time == 16),
				(int)(parkinglot->departed_trucks == parkinglot->departed_trucks->next)
		);
		logger(output_path, TRUCK_UPDATE_DEPARTURES, buf);

		truck_update_depatures(parkinglot, 8);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d\n",
				(int)(parkinglot->departed_trucks != parkinglot->departed_trucks->next),
				(int)(parkinglot->arrived_trucks->next->departure_time == 16)
		);
		logger(output_path, TRUCK_UPDATE_DEPARTURES, buf);

		truck_update_depatures(parkinglot, 16);
		snprintf(buf, LOG_BUFFER_LEN-1,"%d %d %d\n",
				(int)(parkinglot->departed_trucks != parkinglot->departed_trucks->next),
				(int)(parkinglot->departed_trucks->next != parkinglot->departed_trucks->next->next),
				(int)(parkinglot->arrived_trucks->next == parkinglot->arrived_trucks)
		);
		logger(output_path, TRUCK_UPDATE_DEPARTURES, buf);
		break;
	default:
		break;
	}

	return 0;
}
