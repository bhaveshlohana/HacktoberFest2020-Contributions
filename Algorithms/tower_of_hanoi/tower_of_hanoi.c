#include <stdio.h>
#include <stdlib.h>
void towerofhanoi(int num,char Beg,char Aux,char Des){
  if(num==1){
    printf("Move disk 1 from %c to %c\n",Beg,Des);
    return;
  }
  towerofhanoi(num-1,Beg,Des,Aux);
  printf("Move disk %d from %c to %c\n",num,Beg,Des);
  towerofhanoi(num-1,Aux,Beg,Des);
}
int main() {
  int n;
  printf("\n Enter number of disks\n");
  scanf("%d",&n);
  printf("\nEnter characters for:\n");
  char A,B,C;
  printf("\nBeginning rod\n");
  A=getche();
  printf("\nAuxillary Rod\n");
  B=getche();
  printf("\nDestination Rod\n");
  C=getche();
  printf("\n");
  towerofhanoi(n,A,B,C);
  /* code */
  return 0;
}
