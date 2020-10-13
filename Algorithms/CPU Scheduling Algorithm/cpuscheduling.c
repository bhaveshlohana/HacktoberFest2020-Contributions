#include<stdio.h>
#include<stdlib.h>
void gantdisp(int gant[10][2],int n)
{
	for(int i=0;i<n;i++)
	     printf("| P[%d] (%d) |",gant[i][0],gant[i][1]);
	printf("\n");
}
void main()
{
	do
	{
		printf("1. FCFS\n2. SJB\n3. Round Robin\n4. Priority\n5. Exit\nEnter your choice: ");
		int ch;
		scanf("%d",&ch);
		int bt[10],proc[10],gant[20][2];
		int n;
		int wt=0,tt=0;	
		double twt=0,ttt=0;		
		switch(ch)
		{
			case 1:
			printf("Enter number of processes :");
			scanf("%d",&n);
			for(int i=0;i<n;i++)
			{
				proc[i]=i+1;
				printf("Enter the burst time of process %d :",proc[i]);
				scanf("%d",&bt[i]);
			}
			printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
			for(int i=0;i<n;i++)
			{
				tt=tt+bt[i];
				printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i],bt[i],wt,tt);
				printf("\n");
				gant[i][0]=proc[i];
				gant[i][1]=tt;
				twt+=wt;
				ttt+=tt;
				wt+=bt[i];
			}
			printf("Average waiting time : %f sec \n",(twt/n));
			printf("Average turnaround time : %f sec\n\n",(ttt/n));
			gantdisp(gant,n);
			break;

			case 2:
			printf("Enter number of processes :");
			scanf("%d",&n);
			for(int i=0;i<n;i++)
			{
				proc[i]=i+1;
				printf("Enter the burst time of process %d :",proc[i]);
				scanf("%d",&bt[i]);
			}
			int min,pos;
			for(int i=0;i<n;i++)
			{
				min=bt[i];
				for(int j=i;j<n;j++)
				{
					if(bt[j]<min)
					{
						min=bt[j];
						pos=j;
					}
				}
				int temp=bt[i];
				bt[i]=bt[pos];
				bt[pos]=temp;
				temp=proc[i];
				proc[i]=proc[pos];
				proc[pos]=temp;
			}			
			printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
			for(int i=0;i<n;i++)
			{
				tt=tt+bt[i];
				printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i],bt[i],wt,tt);
				gant[i][0]=proc[i];
				gant[i][1]=tt;
				twt+=wt;
				ttt+=tt;
				wt+=bt[i];
			}
			printf("Average waiting time : %f sec\n",(twt/n));
			printf("Average turnaround time : %f sec\n",(ttt/n));
			break;

			case 3:
			printf("Enter number of processes :");
			scanf("%d",&n);
			int at[10],rbt[10],tq=0;
			int wta[10];
			for(int i=0;i<n;i++)
			{
				proc[i]=i+1;
				printf("Enter the arrival time and burst time of process %d :",proc[i]);
				scanf("%d",&at[i]);
				scanf("%d",&bt[i]);
				wta[i]=0;
				rbt[i]=bt[i];
			}
			printf("Enter the time quantum : ");
			scanf("%d",&tq);
			int flag=0;
			int t=0,k=0;
			int wq[10],atq[10];
			for(int i=0;i<n;i++)
			{
				int min=at[i];
				pos=i;
				for(int j=i;j<n;j++)
				{
					if(at[j]<min)
					{
						min=at[j];
						pos=j;
					}
				}
				atq[k++]=pos;
			}
			wq[0]=atq[0];
			t=at[atq[0]],k=1;
			int z=0,x=0;
			printf("Process\tWaiting time\tTurnaround time\n");
			while(flag==0)
			{
				if(rbt[wq[0]]!=0)
				{
				if(rbt[wq[0]]>tq)
				{
					int a=t+tq;
					while(t!=a)
					{
						t++;
						rbt[wq[0]]--;
						if(k!=n)
						if(at[atq[k]]==t)
							wq[++z]=atq[k++];
					}
					gant[x][0]=wq[0];
					gant[x++][1]=t;
				}			
				else
				{
					while(t!=(t+rbt[wq[0]]))
					{
						t++;
						rbt[wq[0]]--;
						if(k!=n)
						if(at[atq[k]]==t)
							wq[++z]=atq[k++];
					}
					wta[wq[0]]=t-(at[wq[0]]+bt[wq[0]]);
					printf("%d\t\t%d\t\t%d\n",(wq[0]+1),wta[wq[0]],(wta[wq[0]]+bt[wq[0]]));
					gant[x][0]=wq[0]+1;
					gant[x++][1]=t;
					twt+=wta[wq[0]];
					ttt+=wta[wq[0]]+bt[wq[0]];
				}   
				}
				int temp=wq[0];
				for(int i=0;i<=z;i++)
				{
					if(i<=z-1)
						wq[i]=wq[i+1];
					else
						wq[i]=temp;
				}
				for(int i=0;i<n;i++)
				{	
					if(rbt[i]!=0)
					{
						flag=0;
						break;
					}
					else
						flag=1;
				}
			}
			printf("Average waiting time : %f sec\n",(twt/n));
			printf("Average turnaround time : %f sec\n\n",(ttt/n));
			gantdisp(gant,x);			
			break;

			case 4:			
			printf("Enter number of processes :");
			scanf("%d",&n);
			int pr[10];
			for(int i=0;i<n;i++)
			{
				proc[i]=i+1;
				printf("Enter the burst time and priority of process %d :",proc[i]);
				scanf("%d",&bt[i]);
				scanf("%d",&pr[i]);
			}
			for(int i=0;i<n;i++)
			{
				min=pr[i];
				pos=i;
				for(int j=i;j<n;j++)
				{
					if(pr[j]<min)
					{
						min=pr[j];
						pos=j;
					}
				}
				int temp=bt[i];
				bt[i]=bt[pos];
				bt[pos]=temp;
				temp=pr[i];
				pr[i]=pr[pos];
				pr[pos]=temp;
				temp=proc[i];
				proc[i]=proc[pos];
				proc[pos]=temp;
			}
			printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
			for(int i=0;i<n;i++)
			{
				tt=tt+bt[i];
				printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i],bt[i],wt,tt);
				gant[i][0]=proc[i];
				gant[i][1]=tt;
				twt+=wt;
				ttt+=tt;
				wt+=bt[i];
			}
			printf("Average waiting time : %f sec \n",(twt/n));
			printf("Average turnaround time : %f sec\n\n",(ttt/n));
			gantdisp(gant,n);
			break;
		
			case 5:
			exit(0);
			default:printf("Enter correct choice !! \n");
		}
	}while(1);
}
