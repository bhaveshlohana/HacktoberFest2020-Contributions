#include<stdio.h>

// function for checking valid index
int valid_index(int *AT,int *BT,int *flag,int t,int processes){
  int i,index=0,value=2147483647;
  for(i=0;i<processes;i++){
    if((AT[i]<=t)&&(BT[i]<=value)&&(flag[i]!=1)){
      value=BT[i];
      index=i;
    }
  }
  return index;
}

// function for checking completion of all process
int condition(int *flag,int processes){
  int i,j=1;
  for(i=0;i<processes;i++){
    if(flag[i]!=1){
      j=0;
      break;
    }
  }
  return j;
}

int max_CT(int *CT,int processes){
  int index=0;
  int value = CT[0];
  for(int i=1;i<processes;i++){
    if(value<CT[i]){
      value = CT[i];
      index = i;
    }
  }
  return index;
}

void main(){
	int processes;

	printf("Enter the number of processes :\n");
	scanf("%d",&processes);

	int AT[processes],BT[processes],CT[processes],flag[processes];

	printf("Enter the Arrival time and Burst time of the processes in the sequence of processes :\n");
	for(int i=0;i<processes;i++){
			scanf("%d %d",&AT[i],&BT[i]);
      flag[i]=0;
	}

	int sort_AT[processes],sort_BT[processes],BTtemp[processes];

	for(int i=0;i<processes;i++){
		sort_AT[i] = AT[i];
	}
  float sum_BT=0;
	for(int i=0;i<processes;i++){
		sort_BT[i] = BT[i];
    sum_BT += BT[i];
	}

// sorting AT(Arrival time) and BT(Burst time)
	int temp1,temp2;
	for (int i=0;i<processes;i++){
        	for (int j=0;j<(processes-i-1);j++){
         		if (sort_AT[j]>sort_AT[j + 1])
            		{
                		temp1 = sort_AT[j];
                		sort_AT[j] = sort_AT[j + 1];
                		sort_AT[j + 1] = temp1;

				            temp2 = sort_BT[j];
                		sort_BT[j] = sort_BT[j + 1];
                		sort_BT[j + 1] = temp2;
            		}
       		 }
    	}

  for(int i=0;i<processes;i++){
    		BTtemp[i] = sort_BT[i];
    }

// Main Algorithm
int TAT[processes],WT[processes];
int t=sort_AT[0];
int index,i=100;
while(1){
  index=valid_index(sort_AT,sort_BT,flag,t,processes);
  flag[index]=1;
  if(index==i){
    index+=1;
    t=sort_AT[index];
  }
    t+=sort_BT[index];
    i=index;
    CT[i]=t;
		TAT[i] = CT[i] - sort_AT[i];
		WT[i] = TAT[i] - sort_BT[i];
    printf("P%d\t",i+1);
    if(condition(flag,processes)){
      break;
    }
}

	float avg_TAT,avg_WT,Throughput;
	float sum_TAT=0,sum_WT=0;
	for(int i=0;i<processes;i++){
		sum_TAT = sum_TAT + TAT[i];
		sum_WT = sum_WT + WT[i];
	}
	avg_TAT = sum_TAT/processes;
	avg_WT = sum_WT/processes;
  Throughput = sum_BT/CT[max_CT(CT,processes)];

	printf("\n----------------------------------------\n");
	printf("P.No.\t AT\t BT\t CT\t TAT\t WT\n");
	for(int i=0;i<processes;i++){

		printf("%d\t %d\t %d\t %d\t %d\t %d\n",(i+1),sort_AT[i],sort_BT[i],CT[i],TAT[i],WT[i]);
	}

	printf("Average TAT is %f\n",avg_TAT);
	printf("Average WT is %f\n",avg_WT);
  printf("Throughput is %f\n",Throughput);

}
