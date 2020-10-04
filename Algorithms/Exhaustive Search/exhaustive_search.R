//this is a very simple exhaustive search for the number 21
//usually searches are used to find 2D numbers, matrices or full solutions

//the fitness test is i+14==35
//the value we're looking for is 21


sol=FALSE
i=1
while (sol==FALSE)
{
 if (i+14==35) sol=TRUE
 else i=i+1
}
print(i)