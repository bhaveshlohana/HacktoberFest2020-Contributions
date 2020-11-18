#please install pycricbuzz pakage before running this program
from pycricbuzz import Cricbuzz
c=Cricbuzz()
matches=c.matches()

for match in matches:
    print(match)
    if(match['mchstate'] != 'nextlive'):
        print(c.livescore(match['id']))
        print(c.commentary(match['id']))
        print(c.scorecard(match['id']),end="")