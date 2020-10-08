def activity_selection(activities):
    
    activities.sort(key = sort_second)
    i = 0
    print("\nSelecionando atividades...\n")
    print(f"{activities[i]}", end = "") # A primeira atividade sempre será selecionada!

    for j in range(len(activities)):
        if activities[j][1][0] >= activities[i][1][1]:  # Se o Início da próxima atividade for MAIOR que o fim da anterior.
            print(f" -> {activities[j]}", end = "")
            i = j

def sort_second(val): 
    return val[1][1]


if __name__ == "__main__":

    activities = [("A",(0,6)),("B",(3,4)),("C",(1,2)),("D",(5,9)),("E",(5,7)),("F",(8,9))]
    activity_selection(activities)
    