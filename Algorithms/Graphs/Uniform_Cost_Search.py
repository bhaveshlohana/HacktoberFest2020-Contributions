def uniform_cost_search(graph, start, goal):    
    path = []    
    explored_nodes = list()    
    
    if start == goal:    
        return path, explored_nodes    
    
    path.append(start)    
    path_cost = 0    
    
    frontier = [(path_cost, path)]    
    while len(frontier) > 0:    
        path_cost_till_now, path_till_now = pop_frontier(frontier)    
        current_node = path_till_now[-1]    
        explored_nodes.append(current_node)    
    
        if current_node == goal:    
            return path_till_now, explored_nodes    
    
        neighbours = graph[current_node]    
    
        neighbours_list_int = [int(n) for n in neighbours]    
        neighbours_list_int.sort(reverse=False)    
        neighbours_list_str = [str(n) for n in neighbours_list_int]    
    
        for neighbour in neighbours_list_str:    
            path_to_neighbour = path_till_now.copy()    
            path_to_neighbour.append(neighbour)    
    
            extra_cost = 1    
            neighbour_cost = extra_cost + path_cost_till_now    
            new_element = (neighbour_cost, path_to_neighbour)    
    
            is_there, indexx, neighbour_old_cost, _ = get_frontier_params_new(neighbour, frontier)    
    
            if (neighbour not in explored_nodes) and not is_there:    
                frontier.append(new_element)    
            elif is_there:    
                if neighbour_old_cost > neighbour_cost:    
                    frontier.pop(indexx)    
                    frontier.append(new_element)    
    
    return None, None  
