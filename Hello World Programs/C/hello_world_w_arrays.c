#include <stdio.h>
#define A 214741 //this will be the highest value that would be entered by the user

//this function will save the variable value
int enterNum(void)
{
  int e;    
  scanf("%d", &e);
  return e;
}

int main(void)
{
  int n, i=0, a[A];
  printf("\n This program will print the amount of 'Hello, World!' that you enter.\n > Please enter an entire number: ");
    n=enterNum();
    //the number must be positive so i force the user to put a >0 value (another option is to use assert but i don't need it here)
    while(n<=0)
    {
            printf("\n The value must be positive.\n  > Try again: ");
              n=enterNum();
    }
  while (i<n)
  {
    a[i]=i;
    printf("\n  |-| Hello, World! |-|    (%d/%d)",a[i]+1,n); //this prints the "Hello World!" and shows a counter on the side.
    i++;
  }
  printf("\n\n"); //this is just a visual fix
  return 0;
}