#include<stdio.h>
void insertstr(int a,int ar[],int op,int adre,int variable,int index,...)
{   
    switch(variable)
    {
        case 1:
        {
            if (op==1)
            {
                int temp[a+1];
                temp[0]=adre;
                    for (int i=1;i<a+1;i++)
                        {
                            temp[i]=ar[i-1];
                        }
                    for (int i=0;i<a+1;i++)
                        {   
                        printf("%d\t",temp[i]);
                        } 
                break;
            }
    

    
            else if (op==2 && variable==1)
            {
                int temp[a];
                for (int i=1;i<a;i++)
                        {
                            temp[i]=ar[i];
                        }
                for (int i=1;i<a;i++)
                        {
                            ar[i-1]=temp[i];
                        }

                for (int i=0;i<a-1;i++)
                    {   
                    printf("%d\t",ar[i]);
                } 
                break;
            }
        }

        case 2 :
        {
            if (op==1)
            {
            
            ar[a]=adre;
            
            for (int i=0;i<(a+1);i++)
                {
                    printf("%d\t",ar[i]);
                }
            break; 
            }

            else if (op==2 && variable==2)
            {
            
            for (int i=0;i<(a-1);i++)
                {
                    printf("%d\t",ar[i]);
                }
            break;
            }
        }


        
        case 3:                                                                                 
        {
            if (op==1)
            {
                    int temp[a];
                        for (int i=0;i<a;i++)
                        {
                            temp[i]=ar[i];
                        }
                    ar[index]=adre;
                        for (int i=index+1;i<a+1;i++)
                        {
                            ar[i]=temp[i-1];
                        }
                        for (int i=0;i<a+1;i++)
                        {
                            printf("%d\t",ar[i]);
                        } 
                        break;
                }
            else if(op==2)
            {
                int temp[a];
                    for (int i=0;i<a;i++)
                    {
                    temp[i]=ar[i];
                    }
                    for (int i=0;i<index;i++)
                    {
                        ar[i]=temp[i];
                    }
                    for (int i=index+1;i<a;i++)
                    {
                        ar[i-1]=temp[i];
                    }

                    for (int i=0;i<a-1;i++)
                    {
                        printf("%d\t",ar[i]);
                    } 
                break;
                    
            }
        }
        
        
    }
}
    

int main(){
    int a,b=0,c,d,i;
    printf("Enter the size of array:");
    scanf("%d",&a);
    int ar[a];
    printf("Enter the elements in array:");
    for (int i=0;i<a;i++)
    {
        scanf("%d",&ar[i]) ;
    }
    printf("if you want to add an element press 1 or if you want to remove element press 2: ");
    scanf("%d",&i);
    if (i==1){
    printf("Enter the Element you want to add: ");
    scanf("%d",&b);
    }
     
    printf("Enter 1 if you want to enter or remove the element from starting \nFrom ending enter 2 \nIf by index enter 3\t");
    scanf("%d",&c);
    if ((c==3 && i==2)||(c==3 && i==1)){
    printf("Enter the index number :");
    scanf("%d",&d);
    }
    insertstr(a,ar,i,b,c,d);
    return 0;
}