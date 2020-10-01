//this is a very simple exhaustive search for the plot point (50,50)
//usually searches are used to find matrices or full solutions

//the fitness test is [abs(goalx - x) + abs(goaly - y) == 0].
//This is to test how fit both X and Y points are, and how close their combined value is to 0 (full fitness)

sol=FALSE
x=1
y=1
goalx = sample(50,1)
goaly = sample(50,1)

while (sol==FALSE)
{
 if ( abs(goalx - x) + abs(goaly - y) == 0 ) sol=TRUE
 else {
   x = x + 1
   if (x > 100) {
     x = 1
     y = y + 1
   }
   # we should never get to this point
   if (y > 100) {
     break;
   }
 }
}
print(x)
print(y)