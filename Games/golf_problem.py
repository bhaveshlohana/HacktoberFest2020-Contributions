import random

def random_pars():
    return [random.randint(1, 5) for i in range(18)]

pars_list = random_pars()
player_list = list(input().split(','))

#score calculation
def par_scores(key):
    par_list = {"albatross" : -3, "eagle" : -2, "birdie" : -1, "par" : 0, "bogey" : 1, "double-bogey" : 2, "triple-bogey" : 3}
    if key in par_list:
       return par_list[key]


def player_score():
    return sum([par_scores(player_list[i]) for i in range(0, len(player_list))])

def sum_pars():
    return sum(pars_list)
def output():
    return "{} over {}".format(player_score() - sum_pars(), sum_pars()) if(player_score() > sum_pars()) else "{} under {}".format(sum_pars() - player_score(), sum_pars())
print(output())
