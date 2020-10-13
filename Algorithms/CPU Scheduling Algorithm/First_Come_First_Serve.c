#include<stdio.h>

// Function for finding the index of process with highest Completion Time(CT)
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

	int AT[processes],BT[processes];

	printf("Enter the Arrival time and Burst time of the processes in the sequence of processes :\n");
	for(int i=0;i<processes;i++){
			scanf("%d %d",&AT[i],&BT[i]);
	}

	int sort_AT[processes],sort_BT[processes];;

	for(int i=0;i<processes;i++){
		sort_AT[i] = AT[i];
	}
	float sum_BT=0;
	for(int i=0;i<processes;i++){
		sort_BT[i] = BT[i];
		sum_BT += BT[i];
	}

  // Sorting AT(Arrival Time) and BT(Burst Time)
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


	int CT[processes];
	if(sort_AT[0]!=0){
		CT[0]=sort_AT[0]+sort_BT[0];
	}
	else{
		CT[0]=sort_BT[0];
	}
	for(int i=1;i<processes;i++){
		if(CT[i-1]<sort_AT[i]){
			CT[i] = (sort_AT[i]-CT[i-1])+sort_BT[i];
		}
		else{
			CT[i] = CT[i-1] + sort_BT[i];
		}
	}

	int TAT[processes],WT[processes];
	for(int i=0;i<processes;i++){
		TAT[i] = CT[i] - sort_AT[i];
		WT[i] = TAT[i] - sort_BT[i];
	}

	float avg_TAT,avg_WT,Throughput;
	int sum_TAT=0,sum_WT=0;
	for(int i=0;i<processes;i++){
		sum_TAT = sum_TAT + TAT[i];
		sum_WT = sum_WT + WT[i];
	}
	avg_TAT = sum_TAT/processes;
	avg_WT = sum_WT/processes;
	Throughput = sum_BT/CT[max_CT(CT,processes)];

	printf("----------------------------------------\n");
	printf("P.No.\t AT\t BT\t CT\t TAT\t WT\n");
	for(int i=0;i<processes;i++){

		printf("%d\t %d\t %d\t %d\t %d\t %d\n",(i+1),sort_AT[i],sort_BT[i],CT[i],TAT[i],WT[i]);
	}

	printf("Average TAT is %f\n",avg_TAT);
	printf("Average WT is %f\n",avg_WT);
	printf("Throughput is %f\n",Throughput);

}
