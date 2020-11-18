#include <stdio.h>
#include "WearhouseManager.h"


Package *create_package(long priority, const char* destination)
{
	Package *package = (Package*)malloc(sizeof(Package));
	package->destination = (char*)malloc(MAX_DESTINATION_NAME_LEN * sizeof(char));
	package->priority = priority;
	if(destination == NULL)
	{
		package->destination = NULL;
	}
	else
	{
		strcpy(package->destination, destination);
	}

	return package;
}

void destroy_package(Package* package)
{
	free(package->destination);
	free(package);
}

Manifest* create_manifest_node(void)
{
	Manifest *manifest = (Manifest*)malloc(sizeof(Manifest));
	manifest->package = NULL;
	manifest->prev = NULL;
	manifest->next = NULL;

	return manifest;
}

void destroy_manifest_node(Manifest* manifest_node)
{
	Manifest* p = manifest_node;

    if(p == NULL) return;
    if(p->next == NULL && p->prev == NULL)
    {
        free(p);
        return;
    }
    if(p->next != NULL && p->prev == NULL)
    {
        Manifest* del = p;
        p = p->next;
        free(del);
        return;
    }
    if(p->next == NULL && p->prev != NULL)
    {
        Manifest* del = p;
        p = p->prev;
        free(del);
        return;
    }
    if(p->next != NULL && p->prev != NULL)
    {
        Manifest* del = p;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = NULL;
        p->prev = NULL;
        free(del);
        return;
    }
}

Wearhouse* create_wearhouse(long capacity)
{
	if(capacity == 0)
	{
		return NULL;
	}
	Wearhouse *wearhouse = (Wearhouse*)malloc(sizeof(Wearhouse));
	wearhouse->capacity = capacity;
	wearhouse->size = 0;
	wearhouse->packages = (Package**)malloc(sizeof(Package*) * capacity);

	return wearhouse;
}

Wearhouse *open_wearhouse(const char* file_path){
	ssize_t read_size;
	char* line = NULL;
	size_t len = 0;
	char* token = NULL;
	Wearhouse *w = NULL;


	FILE *fp = fopen(file_path, "r");
	if(fp == NULL)
		goto file_open_exception;

	if((read_size = getline(&line, &len, fp)) != -1){
		token = strtok(line, ",\n ");
		w = create_wearhouse(atol(token));

		free(line);
		line = NULL;
		len = 0;
	}

	while((read_size = getline(&line, &len, fp)) != -1){
		token = strtok(line, ",\n ");
		long priority = atol(token);
		token = strtok(NULL, ",\n ");
		Package *p = create_package(priority, token);
		w->packages[w->size++] = p;

		free(line);
		line = NULL;
		len = 0;
	}

	free(line);


	fclose(fp);
	return w;

	file_open_exception:
	return NULL;
}

long wearhouse_is_empty(Wearhouse *w)
{
	if(w->size == 0) return 1;	
	return 0;
}

long wearhouse_is_full(Wearhouse *w)
{
	if(w->size >= w->capacity) return 1;
	return 0;
}

long wearhouse_max_package_priority(Wearhouse *w)
{
	if(w == NULL) return 0;

	long max = -1, i;

	for(i = 0; i < w->size; i++)
	{
		if(w->packages[i]->priority > max)
		{
			max = w->packages[i]->priority;
		}
	}

	return max;
}

long wearhouse_min_package_priority(Wearhouse *w)
{
	if(w == NULL) return 0;

	long min = 1000000, i;

	for(i = 0; i < w->size; i++)
	{
		if(w->packages[i]->priority < min)
		{
			min = w->packages[i]->priority;
		}
	}

	return min;
}


void wearhouse_print_packages_info(Wearhouse *w){
	for(long i = 0; i < w->size; i++){
		printf("P: %ld %s\n",
				w->packages[i]->priority,
				w->packages[i]->destination);
	}
	printf("\n");
}

void destroy_wearhouse(Wearhouse* wearhouse)
{
	for(long i = 0; i < wearhouse->size; i++)
	{
		destroy_package(wearhouse->packages[i]);
	}
	free(wearhouse->packages);
	free(wearhouse);
}


Robot* create_robot(long capacity)
{
	Robot *robot = (Robot*)malloc(sizeof(Robot));
	robot->capacity = capacity;
	robot->next = NULL;
	robot->manifest = NULL;
	robot->size = 0;

	return robot;	
}

int robot_is_full(Robot* robot)
{
	if(robot->size >= robot->capacity) return 1;
	return 0;	
}

int robot_is_empty(Robot* robot){
	if(robot->size == 0) return 1;
	return 0;
}

Package* robot_get_wearhouse_priority_package(Wearhouse *w, long priority)
{
	long i;

	for(i = 0; i < w->size; i++)
	{
		if(w->packages[i]->priority == priority)
		{
			return w->packages[i];
		}
	}

	return NULL;
}

void robot_remove_wearhouse_package(Wearhouse *w, Package* package)
{
	int i, j;

	for(i = 0; i < w->size; i++)
	{
		if(w->packages[i] == package)
		{
			break;
		}
	}
	for(j = i; j < w->size - 1; j++)
	{
		w->packages[j] = w->packages[j+1];
	}
	w->size--;
}

void robot_load_one_package(Robot* robot, Package* package)
{
	if(robot == NULL) return;
	if(robot->size == robot->capacity)
	{
		return;
	}
	Manifest *new_manifest_node = (Manifest*)malloc(sizeof(Manifest));
	new_manifest_node->package = package;
	new_manifest_node->prev = NULL;
	new_manifest_node->next = NULL;
	robot->size++;

	if(robot->manifest == NULL)
	{
		robot->manifest = new_manifest_node;
		return;
	}
	else
	{
		Manifest *p = robot->manifest, *previous = NULL;

		//Parcurgerea pachetelor in oridnea data conditia luand in considerare si cazul in care prioritatile sunt egale
		while(p != NULL && (package->priority < p->package->priority || (p->package->priority == package->priority && strcmp(package->destination, p->package->destination) > 0)))
		{
			previous = p;
			p = p->next;
		}

		//Inserarea pachetului pentru fiecare din cazurile listei
		if(p != NULL)
	    {
	    	if(previous != NULL)
	        {
	        	new_manifest_node->next = p;
	            new_manifest_node->prev = previous;
	            previous->next = new_manifest_node;
	            p->prev = new_manifest_node;
	            return;
	        }
	        else
	        {
	        	new_manifest_node->next = robot->manifest;
	            robot->manifest = new_manifest_node;
	            return;
	        }
	    }
	    else
	    {
	        new_manifest_node->prev = previous;
	        previous->next = new_manifest_node;
	        return;
	    }
	}
}

long robot_load_packages(Wearhouse* wearhouse, Robot* robot)
{
	long sol = 0;

	//Utilizarea functiilor precedente aeriseste codul si face algoritmul mai usor de inteles
	while(wearhouse->size > 0 && robot->size < robot->capacity)
	{
		sol++;
		Package *new = robot_get_wearhouse_priority_package(wearhouse, wearhouse_max_package_priority(wearhouse)); //Extrage pachetul cu prioritatea cea mai mare
		robot_load_one_package(robot, new); //Incarca pachetul extras in robot
		robot_remove_wearhouse_package(wearhouse, new); //Actualizeaza depozitul, eliminand pachetul introdus in robot
	}

	return sol;
}

Package* robot_get_destination_highest_priority_package(Robot* robot, const char* destination)
{
	int max = -1;
	Manifest *p = robot->manifest;
	Package *sol = p->package;

	while(p != NULL)
	{
		if(p->package->destination == destination)
		{
			if(p->package->priority >= max)
			{
				max = p->package->priority;
				sol = p->package;
			}
		}
		p = p->next;
	}

	return sol;
}

void destroy_robot(Robot* robot)
{
	Manifest *q = robot->manifest;

	while(q != NULL)
	{
		Manifest *del = q;
		q = q->next;
		destroy_manifest_node(del);
	}
	free(robot->manifest);
	free(robot);
}

void robot_unload_packages(Truck* truck, Robot* robot)
{
	Manifest *p = robot->manifest, *new_p = NULL;

	while(p != NULL)
	{
		if(strcmp(truck->destination, p->package->destination) == 0)
		{
			if(truck->size == truck->capacity) return;
			truck->size++;	
			if(robot->size == 0)
			{
				truck->size--;
				return;
			}
			robot->size--;

			new_p = p->next;
			//Actualizarea legaturilor din manifestul robotului prin stergerea pachetelui gasit
			if(p->next == NULL && p->prev == NULL)
			{
				robot->manifest = NULL;
			}
			else
			{
				if(p->next == NULL)
				{
					p->prev->next = NULL;
				}
				else
				{
					if(p == robot->manifest)
					{
						robot->manifest->next->prev = NULL;
						robot->manifest = robot->manifest->next;
					}
					else
					{
						p->next->prev = p->prev;
						p->prev->next = p->next;
					}
				}
			}
			//Introducerea pachetului gasit in manifestul tirului in ordine sortata
			if(truck->manifest != NULL)
			{
				Manifest *q = truck->manifest;

				while(q->next != NULL)
				{
					q = q->next;
				}

				p->next = NULL;
				p->prev = q;
				q->next = p;
			}
			else
			{
				p->next = NULL;
				p->prev = NULL;
				truck->manifest = p;
			}
			p = new_p;
		}
		else
		{
			p = p->next;
		}
	}
}

// Attach to specific truck
int robot_attach_find_truck(Robot* robot, Parkinglot *parkinglot){
	int found_truck = 0;
	long size = 0;
	Truck *arrived_iterator = parkinglot->arrived_trucks->next;
	Manifest* m_iterator = robot->manifest;


	while(m_iterator != NULL){
		while(arrived_iterator != parkinglot->arrived_trucks){
			size  = truck_destination_robots_unloading_size(arrived_iterator);
			if(strncmp(m_iterator->package->destination, arrived_iterator->destination, MAX_DESTINATION_NAME_LEN) == 0 &&
					size < (arrived_iterator->capacity-arrived_iterator->size)){
				found_truck = 1;
				break;
			}

			arrived_iterator = arrived_iterator->next;
		}

		if(found_truck)
			break;
		m_iterator = m_iterator->next;
	}

	if(found_truck == 0)
		return 0;


	Robot* prevr_iterator = NULL;
	Robot* r_iterator = arrived_iterator->unloading_robots;
	while(r_iterator != NULL){
		Package *pkg = robot_get_destination_highest_priority_package(r_iterator, m_iterator->package->destination);
		if(m_iterator->package->priority >= pkg->priority)
			break;
		prevr_iterator = r_iterator;
		r_iterator = r_iterator->next;
	}

	robot->next = r_iterator;
	if(prevr_iterator == NULL)
		arrived_iterator->unloading_robots = robot;
	else
		prevr_iterator->next = robot;

	return 1;
}

void robot_print_manifest_info(Robot* robot){
	Manifest *iterator = robot->manifest;
	while(iterator != NULL){
		printf(" R->P: %s %ld\n", iterator->package->destination, iterator->package->priority);
		iterator = iterator->next;
	}

	printf("\n");
}



Truck* create_truck(const char* destination, long capacity, long transit_time, long departure_time)
{
	Truck *truck = (Truck*)malloc(sizeof(Truck));
	truck->destination = (char*)malloc(MAX_DESTINATION_NAME_LEN * sizeof(char));
	if(destination == NULL) truck->destination = NULL;
	else strcpy(truck->destination, destination);
	truck->capacity = capacity;
	truck->size = 0;
	truck->departure_time = departure_time;
	truck->in_transit_time = 0;
	truck->transit_end_time = transit_time;
	truck->next = NULL;
	truck->manifest = NULL;
	truck->unloading_robots = NULL;

	return truck;
}

int truck_is_full(Truck *truck)
{
	if(truck->size >= truck->capacity) return 1;
	return 0;
}

int truck_is_empty(Truck *truck)
{
	if(truck->size == 0) return 1;
	return 0;
}

long truck_destination_robots_unloading_size(Truck* truck)
{
	Robot *p = truck->unloading_robots;

	while(p != NULL)
	{
		Manifest *q = p->manifest;
		while(q != NULL)
		{
			if(strcmp(q->package->destination, truck->destination) == 0)
			{
				return p->size;
			}
			q = q->next;
		}
		p = p->next;
	}

	return 0;
}


void truck_print_info(Truck* truck){
	printf("T: %s %ld %ld %ld %ld %ld\n", truck->destination, truck->size, truck->capacity,
			truck->in_transit_time, truck->transit_end_time, truck->departure_time);

	Manifest* m_iterator = truck->manifest;
	while(m_iterator != NULL){
		printf(" T->P: %s %ld\n", m_iterator->package->destination, m_iterator->package->priority);
		m_iterator = m_iterator->next;
	}

	Robot* r_iterator = truck->unloading_robots;
	while(r_iterator != NULL){
		printf(" T->R: %ld %ld\n", r_iterator->size, r_iterator->capacity);
		robot_print_manifest_info(r_iterator);
		r_iterator = r_iterator->next;
	}
}


void destroy_truck(Truck* truck)
{
	free(truck->destination);
	free(truck->unloading_robots);
	free(truck->manifest);
	free(truck);
}

Parkinglot* create_parkinglot(void)
{
	Parkinglot *parkinglot = (Parkinglot*)malloc(sizeof(Parkinglot));
	parkinglot->arrived_trucks = (Truck*)malloc(sizeof(Truck));
	parkinglot->arrived_trucks->next = parkinglot->arrived_trucks;
	parkinglot->departed_trucks = (Truck*)malloc(sizeof(Truck));
	parkinglot->departed_trucks->next = parkinglot->departed_trucks;
	parkinglot->pending_robots = (Robot*)malloc(sizeof(Robot));
	parkinglot->pending_robots->next = parkinglot->pending_robots;
	parkinglot->standby_robots = (Robot*)malloc(sizeof(Robot));
	parkinglot->standby_robots->next = parkinglot->standby_robots;

	return parkinglot;
}

Parkinglot* open_parckinglot(const char* file_path){
	ssize_t read_size;
	char* line = NULL;
	size_t len = 0;
	char* token = NULL;
	Parkinglot *parkinglot = create_parkinglot();

	FILE *fp = fopen(file_path, "r");
	if(fp == NULL)
		goto file_open_exception;

	while((read_size = getline(&line, &len, fp)) != -1){
		token = strtok(line, ",\n ");
		// destination, capacitym transit_time, departure_time, arrived
		if(token[0] == 'T'){
			token = strtok(NULL, ",\n ");
			char *destination = token;

			token = strtok(NULL, ",\n ");
			long capacity = atol(token);

			token = strtok(NULL, ",\n ");
			long transit_time = atol(token);

			token = strtok(NULL, ",\n ");
			long departure_time = atol(token);

			token = strtok(NULL, ",\n ");
			int arrived = atoi(token);

			Truck *truck = create_truck(destination, capacity, transit_time, departure_time);

			if(arrived)
				truck_arrived(parkinglot, truck);
			else
				truck_departed(parkinglot, truck);

		}else if(token[0] == 'R'){
			token = strtok(NULL, ",\n ");
			long capacity = atol(token);

			Robot *robot = create_robot(capacity);
			parkinglot_add_robot(parkinglot, robot);

		}

		free(line);
		line = NULL;
		len = 0;
	}
	free(line);

	fclose(fp);
	return parkinglot;

	file_open_exception:
	return NULL;
}

void parkinglot_add_robot(Parkinglot* parkinglot, Robot *robot)
{
	//Introducerea unui robot in parcare consta in 2 cazuri care se trateaza similar
	if(robot->size == 0)
	{
		//Lista de roboti este goala
		if(parkinglot->standby_robots->next == parkinglot->standby_robots)
		{
			robot->next = parkinglot->standby_robots;
			parkinglot->standby_robots->next = robot;
			return;
		}
		Robot *p = parkinglot->standby_robots;

		//Parcurgerea listei de roboti pana la gasirea locului unde trebuie introdus pentru ca aceasta sa ramana sortata
		while(p->next != parkinglot->standby_robots && robot->capacity < p->next->capacity)
		{
			p = p->next;
		}
		if(p->next != parkinglot->standby_robots)
		{
			robot->next = p->next;
			p->next = robot;
		}
		else
		{
			robot->next = parkinglot->standby_robots;
			p->next = robot;
		}
	}
	else
	{
		if(parkinglot->pending_robots->next == parkinglot->pending_robots)
		{
			robot->next = parkinglot->pending_robots;
			parkinglot->pending_robots->next = robot;
			return;
		}
		Robot *p = parkinglot->pending_robots;

		while(p->next != parkinglot->pending_robots && robot->size < p->next->size)
		{
			p = p->next;
		}
		if(p->next != parkinglot->pending_robots)
		{
			robot->next = p->next;
			p->next = robot;
		}
		else
		{
			robot->next = parkinglot->pending_robots;
			p->next = robot;
		}
	}
}

void parkinglot_remove_robot(Parkinglot *parkinglot, Robot* robot)
{
	//Se decide din ce lista trebuie extras robotul, algoritmul fiind acelasi
	if(robot->size == 0)
	{
		Robot *p = parkinglot->standby_robots;

		while(p->next != parkinglot->standby_robots && p->next != robot)
		{
			p = p->next;
		}
		//Actualizarea legaturii in lista de roboti
		p->next = p->next->next;
	}
	else
	{
		Robot *p = parkinglot->pending_robots;

		while(p->next != parkinglot->pending_robots && p->next != robot)
		{
			p = p->next;
		}
		p->next = p->next->next;
	}	
}

int parckinglot_are_robots_peding(Parkinglot* parkinglot)
{
	if(parkinglot->pending_robots->next != parkinglot->pending_robots) return 1;
	return 0;
}

int parkinglot_are_arrived_trucks_empty(Parkinglot* parkinglot)
{
	Truck *p = parkinglot->arrived_trucks;
	
	if(p == parkinglot->arrived_trucks->next) return 1;
	while(p->next != parkinglot->arrived_trucks)
	{
		if(p->next->size == 0) return 1;
		p = p->next;
	}
	
	return 0;
}


int parkinglot_are_trucks_in_transit(Parkinglot* parkinglot)
{
	if(parkinglot->departed_trucks->next != parkinglot->departed_trucks) return 1;
	return 0;
}


void destroy_parkinglot(Parkinglot* parkinglot)
{
	free(parkinglot->arrived_trucks);
	free(parkinglot->departed_trucks);
	free(parkinglot->pending_robots);
	free(parkinglot->standby_robots);
	free(parkinglot);
}

void parkinglot_print_arrived_trucks(Parkinglot* parkinglot){
	Truck *iterator = parkinglot->arrived_trucks->next;
	while(iterator != parkinglot->arrived_trucks){

		truck_print_info(iterator);
		iterator = iterator->next;
	}

	printf("\n");

}

void parkinglot_print_departed_trucks(Parkinglot* parkinglot){
	Truck *iterator = parkinglot->departed_trucks->next;
	while(iterator != parkinglot->departed_trucks){
		truck_print_info(iterator);
		iterator = iterator->next;
	}
	printf("\n");

}

void parkinglot_print_pending_robots(Parkinglot* parkinglot){
	Robot *iterator = parkinglot->pending_robots->next;
	while(iterator != parkinglot->pending_robots){
		printf("R: %ld %ld\n", iterator->size, iterator->capacity);
		robot_print_manifest_info(iterator);
		iterator = iterator->next;
	}
	printf("\n");

}

void parkinglot_print_standby_robots(Parkinglot* parkinglot){
	Robot *iterator = parkinglot->standby_robots->next;
	while(iterator != parkinglot->standby_robots){
		printf("R: %ld %ld\n", iterator->size, iterator->capacity);
		robot_print_manifest_info(iterator);
		iterator = iterator->next;
	}
	printf("\n");

}


void truck_departed(Parkinglot *parkinglot, Truck* truck)
{
	// TODO: 3.5
	// Search through arrived list, if exists node is found remove it
	// Note: this must remove the node from the list, NOT deallocate it
	Truck *p = parkinglot->arrived_trucks;
	Truck *q = parkinglot->departed_trucks;
	int ok = 0;

	//Se verifica daca tirul exista in lista
	if(parkinglot->arrived_trucks != parkinglot->arrived_trucks->next)
	{
		while(p->next != parkinglot->arrived_trucks)
		{
			if(p->next == truck)
			{
				ok = 1;
				break;
			}
			p = p->next;
		}
	}
	//Se elimina tirul din lista daca a fost gasit acutalizand legaturile
	if(ok == 1)
	{
		p->next = p->next->next;
	}

	//Se introduce tirul eliminat in cealalta lista pastrand-o sortata
	while(q->next != parkinglot->departed_trucks && truck->departure_time > q->next->departure_time)
	{
		q = q->next;
	}
	truck->next = q->next;
	q->next = truck;
}


void truck_arrived(Parkinglot *parkinglot, Truck* truck)
{
	if(parkinglot == NULL || truck == NULL) return;

	// TODO: 3.5
	// Search through departed list, if exists node is found remove it
	// Note: this must remove the node not deallocate it
	Truck *p = parkinglot->departed_trucks;
	Truck *q = parkinglot->arrived_trucks;
	int ok = 0;

	//Algoritmul este similar cu cel de la functia precedenta
	if(parkinglot->departed_trucks != parkinglot->departed_trucks->next)
	{
		while(p->next != parkinglot->departed_trucks)
		{
			if(p->next == truck)
			{
				ok = 1;
				break;
			}
			p = p->next;
		}
	}
	if(ok == 1)
	{
		p->next = p->next->next;
	}

	while(q->next != parkinglot->arrived_trucks && (strcmp(truck->destination, q->next->destination) > 0 || (truck->departure_time > q->next->departure_time && strcmp(truck->destination, q->next->destination) == 0)))
	{
		q = q->next;
	}
	truck->next = q->next;
	q->next = truck;
	truck->manifest = NULL;
	truck->size = 0;
	truck->in_transit_time = 0;
}

void truck_transfer_unloading_robots(Parkinglot* parkinglot, Truck* truck)
{
	Robot *p = truck->unloading_robots, *new = NULL;

	//Parcurgerea robotilor pentru a fi transferati in alta  lista
	while(p != NULL)
	{
		new = p->next;
		Robot *q = parkinglot->standby_robots;

		//Parcurgerea listei in care trebuie introdusi robotii pentru a o mentine sortata si introducerea robotului
		while(q->next != parkinglot->standby_robots && p->capacity < q->next->capacity)
		{
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
		p = new;
	}
	truck->unloading_robots = NULL;
}


// Depends on parking_turck_departed
void truck_update_depatures(Parkinglot* parkinglot, long day_hour)
{
	Truck *p = parkinglot->arrived_trucks, *new = NULL;

	while(p->next != parkinglot->arrived_trucks)
	{
		if(p->next->departure_time == day_hour)
		{
			new = p->next->next; //Retinerea urmatorului pointer
			truck_departed(parkinglot, p->next); //Modificarea legaturilor
			p = new;
		}
		else p = p->next;
	}
}

// Depends on parking_turck_arrived
void truck_update_transit_times(Parkinglot* parkinglot){
	Truck *p = parkinglot->departed_trucks, *new = NULL;

	while(p->next != parkinglot->departed_trucks)
	{
		p->next->in_transit_time++;
		if(p->next->in_transit_time == p->next->transit_end_time)
		{
			new = p->next->next;
			truck_arrived(parkinglot, p->next);
			p = new;
		}
		else p = p->next;
	}
}

void robot_swarm_collect(Wearhouse *wearhouse, Parkinglot *parkinglot){
	Robot *head_robot = parkinglot->standby_robots;
	Robot *current_robot = parkinglot->standby_robots->next;
	while(current_robot != parkinglot->standby_robots){

		// Load packages from wearhouse if possible
		if(!robot_load_packages(wearhouse, current_robot)){
			break;
		}

		// Remove robot from standby list
		Robot *aux = current_robot;
		head_robot->next = current_robot->next;
		current_robot = current_robot->next;

		// Add robot to the
		parkinglot_add_robot(parkinglot, aux);
	}
}


void robot_swarm_assign_to_trucks(Parkinglot *parkinglot){

	Robot *current_robot = parkinglot->pending_robots->next;

	while(current_robot != parkinglot->pending_robots){
		Robot* aux = current_robot;
		current_robot = current_robot->next;
		parkinglot_remove_robot(parkinglot, aux);
		int attach_succeded = robot_attach_find_truck(aux, parkinglot);
		if(!attach_succeded)
			parkinglot_add_robot(parkinglot, aux);
	}
}

void robot_swarm_deposit(Parkinglot* parkinglot){
	Truck *arrived_iterator = parkinglot->arrived_trucks->next;
	while(arrived_iterator != parkinglot->arrived_trucks){
		Robot *current_robot = arrived_iterator->unloading_robots;
		while(current_robot != NULL){
			robot_unload_packages(arrived_iterator, current_robot);
			Robot *aux = current_robot;
			current_robot = current_robot->next;
			arrived_iterator->unloading_robots = current_robot;
			parkinglot_add_robot(parkinglot, aux);
		}
		arrived_iterator = arrived_iterator->next;
	}
}

