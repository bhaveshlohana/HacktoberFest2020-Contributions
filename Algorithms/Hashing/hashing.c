#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int m=50;
int A[50];
int hashCode(int key)
    {
        return key % 47;
    }
int hashCode1(int key)
{
    return (7-(key%7));
}
void insert_by_linear_probing(int value){
    int pos,n=0;
    int probes=0;

	 pos=hashCode(value);
	while(A[pos]!= INT_MIN) { // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break and goto bottom of the loop to insert element
		if(A[pos]== INT_MAX)
            break;
        if (A[pos] == value)
        {
		/* case where already existing key matches the given key */
		printf("\n (%d) already exists, hence not allowed to renter the same value again\n",value);
		return;
	    }
		pos = (pos+1)%m;
		n++;
		if(n==m)
		break;      // If table is full we should break.
	}

	if(n==m)
    {
           printf("Hash table was full of elements no Place to insert this element\n\n");
    }

	else
    {
       A[pos] = value;
     printf("\n value (%d) has been inserted at (%d) \n", value,pos);  //Inserting element
     printf("\n (%d) number of probes is required for (%d)  \n",n+1,value);
    }

}

void Delete_by_linear_probing(int value){

	int n=0;
	int pos=hashCode(value);



	while(n++ != m){
		if(A[pos]==INT_MIN){
			printf("Element not found in hash table\n");
			break;
		}
		else if(A[pos]==value){
			A[pos]=INT_MAX;
			printf("Element deleted at pos (%d)\n\n",pos);
			break;
		}
		else{
			pos = (pos+1) % m;
		}
	}
	if(--n==m)
        printf("Element not found in hash table\n");
}

void search_by_linear_probing(int value){
	int n=0;
	int pos=hashCode(value);


	while(n++ != m){
		if(A[pos]==value){
			printf("Element found at index %d\n",pos);
			break;
		}
		else
            if(A[pos]==INT_MAX ||A[pos]!=INT_MIN)
                pos = (pos+1) %m;
	}
	if(--n==m) printf("Element not found in hash table\n");
}


void insert_by_quadratic_probing(int value){
    int pos,n=0;

	 pos=hashCode(value);
      int h=1;
	while(A[pos]!= INT_MIN) {  // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break and goto bottom of the loop to insert element
		if(A[pos]== INT_MAX)
            break;
         if (A[pos] == value)
        {
		/* case where already existing key matches the given key */
		printf("\n (%d) already exists, hence not allowed to renter the same value again\n",value);
		return;
	    }
		pos = (pos+(h*h))%m;
		h++;
		n++;
		if(n==m)
		break;      // If table is full we should break, if not check this, loop will go to infinite loop.
	}

	if(n==m)
    {
           printf("Hash table was full of elements\nNo Place to insert this element\n\n");

    }

	else
    {
           A[pos] = value;
    printf("\n value (%d) has been inserted at (%d) \n", value,pos);  //Inserting element
      printf("\n  (%d) number of probes is required for (%d)  \n",n+1,value);
    }

}

void Delete_by_quadratic_probing(int value){

	int n=0;
	int pos=hashCode(value);

int h=1;

	while(n++ != m){
		if(A[pos]==INT_MIN){
			printf("Element not found in hash table\n");
			break;
		}
		else if(A[pos]==value){
			A[pos]=INT_MAX;
			printf("Element deleted at pos (%d)\n\n",pos);
			break;
		}
		else{

			pos = (pos+(h*h)) % m;
            h++;
		}
	}
	if(--n==m)
        printf("Element not found in hash table\n");
}

void search_by_quadratic_probing(int value){
	int n=0;
	int pos=hashCode(value);


	while(n++ != m){
		if(A[pos]==value){
			printf("Element found at index %d\n",pos);
			break;
		}
		else
            if(A[pos]==INT_MAX ||A[pos]!=INT_MIN)
                pos = (pos+1) %m;
	}
	if(--n==m) printf("Element not found in hash table\n");
}




void insert_by_double_hashing(int value){
    int pos,n=0;
	 int pos1=hashCode(value);
	 int pos2=hashCode1(value);
     pos=pos1;
    int h=1;
	while(A[pos]!= INT_MIN) {  // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break and goto bottom of the loop to insert element
		if(A[pos]== INT_MAX)
            break;
         if (A[pos] == value)
        {
		/* case where already existing key matches the given key */
		printf("\n (%d) already exists, hence not allowed to renter the same value again\n",value);
		return;
	    }
		pos = (pos1+(h*pos2))%m;
		h++;
		n++;
		if(n==m)
		break;      // If table is full we should break, if not check this, loop will go to infinite loop.
	}

	if(n==m)
    {
           printf("Hash table was full of elements\nNo Place to insert this element\n\n");
    }

	else
    {
           A[pos] = value;
    printf("\n value (%d) has been inserted at (%d) \n", value,pos);  //Inserting element
      printf("\n (%d) number of probes is required for (%d)  \n",n+1,value);
    }

}

void Delete_by_double_hashing(int value){

	int n=0;
	int pos;
   int pos1=hashCode(value);
	 int pos2=hashCode1(value);
     pos=pos1;
    int h=1;

	while(n++ != m){
		if(A[pos]==INT_MIN){
			printf("Element not found in hash table\n");
			break;
		}
		else if(A[pos]==value){
			A[pos]=INT_MAX;
			printf("Element deleted at pos (%d)\n\n",pos);
			break;
		}
		else{

			pos = (pos1+(h*pos2)) % m;
            h++;
		}
	}
	if(--n==m)
        printf("Element not found in hash table\n");
}

void search_by_double_hashing(int value){
	int n=0;
	int pos=hashCode(value);


	while(n++ != m){
		if(A[pos]==value){
			printf("Element found at index %d\n",pos);
			break;
		}
		else
            if(A[pos]==INT_MAX ||A[pos]!=INT_MIN)
                pos = (pos+1) %m;
	}
	if(--n==m) printf("Element not found in hash table\n");
}
int main(){


	for(int i=0;i<m;i++)
    {
         A[i]=INT_MIN; //Assigning INT_MIN indicates that cell is empty

    }
        int choice=0;
       printf("Enter 1 for linear probing, 2 for quadratic probing, 3 for double hashing \n");
       scanf("%d",&choice);
    if(choice==1)
    { int ch,value;
        do{
		printf("Enter your choice for linear probing\n");
		printf(" 1-> Insert\n 2-> Delete\n 3-> Searching\n 4-> Exit\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				 printf("Inserting element in Hashtable\n");
		     //setting up upper and lower limit for element of array
              int lower = 0, upper = 999;
               srand(time(0));
               for(int i=0;i<40;i++)
              {
                 insert_by_linear_probing((rand() % (upper - lower + 1))+lower);
              }
				break;
			case 2:
              printf("Deleting in Hashtable \n Enter the value to delete-:");
		      scanf("%d", &value);
		      Delete_by_linear_probing(value);
              break;
			case 3:
				  printf("Searching in Hashtable \n Enter the key to search-:");
		         scanf("%d", &value);
                search_by_linear_probing(value);
				break;
			default:
				printf("Enter correct choice\n");
				break;
		}
	}while(ch);

    }
    else if(choice==2)
    {
       int ch,value;
        do{
		printf("Enter your choice for quadratic hashing\n");
		printf(" 1-> Insert\n 2-> Delete\n 3-> Searching\n 4-> Exit\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				 printf("Inserting element in Hashtable\n");
		     //setting up upper and lower limit for element of array
              int lower = 0, upper = 999;
               srand(time(0));
               for(int i=0;i<40;i++)
              {
                 insert_by_quadratic_probing((rand() % (upper - lower + 1))+lower);
              }
				break;
			case 2:
              printf("Deleting in Hashtable \n Enter the value to delete-:");
		      scanf("%d", &value);
		      Delete_by_quadratic_probing(value);
              break;
			case 3:
				  printf("Searching in Hashtable \n Enter the key to search-:");
		         scanf("%d", &value);
                search_by_quadratic_probing(value);
				break;
			default:
				printf("Enter correct choice\n");
				break;
		}
	}while(ch);

    }

	else if(choice==3)
    {
         int ch,value;
        do{
		printf("Enter your choice for double hashing\n");
		printf(" 1-> Insert\n 2-> Delete\n 3-> Searching\n 4-> Exit\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				 printf("Inserting element in Hashtable\n");
		     //setting up upper and lower limit for element of array
              int lower = 0, upper = 999;
               srand(time(0));
               for(int i=0;i<40;i++)
              {
                 insert_by_double_hashing((rand() % (upper - lower + 1))+lower);
              }
				break;
			case 2:
              printf("Deleting in Hashtable \n Enter the value to delete-:");
		      scanf("%d", &value);
		      Delete_by_double_hashing(value);
              break;
			case 3:
				  printf("Searching in Hashtable \n Enter the key to search-:");
		         scanf("%d", &value);
                search_by_double_hashing(value);
				break;
			default:
				printf("Enter correct choice\n");
				break;
		}
	}while(ch);
    }
    else{
         printf("Enter correct option\n");
    }
	return 0;
}

