#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int SIZE = 0;
float BAG_SIZE = 0.f;
int getValue(char message[]);
void setArray(float arr[][4]);
void calculateProfitWeighteg(int arr[][4]);
void printTable(float arr[][4]);
void findProfitByWeight(float arr[][4]);
void sortBag(float arr[][4]);
void copyArray(float copyTo[4], float from[4]);
float knapSack(float arr[][4]);

int main(){
	
	SIZE = getValue("Enter Number of Items: ");
	BAG_SIZE = getValue("Enter Size of Bag: ");
	float totalProfit;
	float arr[SIZE][4];
	setArray(arr);
	system("cls");
	
	findProfitByWeight(arr);
	sortBag(arr);
	totalProfit = knapSack(arr);
	printTable(arr);
	printf("\nTotal Profit : %.2f", totalProfit);
	getch();
	return 0;
}

int getValue(char message[]){
	int size;
	printf("%s",message);
	scanf("%d", &size);
	return size;
}


void setArray(float arr[][4]){
	printf("\n");
	int i = 0;
	for(;i<SIZE;i++){		
		printf("Enter %d element profit : ",(i+1));
		scanf("%f", &arr[i][0]);
		printf("Enter %d element weight : ",(i+1));
		scanf("%f", &arr[i][1]);		
	}
	
}

void printTable(float arr[][4]){
	int i, j;
	char *strs[1][5] = {"|" ,"profit |", "weight |", "p/w |", "used |"};
	for(j=0; j<5; j++){
		
		//calculate line width
		if(j == 1){
			int temp = (SIZE+1) * 8;
			for(i = 0; i<temp; i++){
				printf("-");
			}
			printf("\n");
		}
		
		printf("%8s ", strs[0][j]);		
		
		for(i=0; i<SIZE; i++){
			if(j == 0){
				printf("%7d ", i+1);
				continue;
			}
			printf("%7.2f ", arr[i][j-1]);
		}
		printf("\n");
	}
}

void findProfitByWeight(float arr[][4]){
	int i;
	for(i=0; i<SIZE; i++){
		arr[i][2] = arr[i][0]/arr[i][1];
	}
	
}
void sortBag(float arr[][4]){
	int i=0, j;
	for(; i<SIZE; i++){
		for(j=0; j<i; j++){
			if(arr[i][2] > arr[j][2]){
				float temp[4];
				copyArray(temp, arr[i]);
				copyArray(arr[i], arr[j]);
				copyArray(arr[j], temp);
			}
		}	
	}	
}

void copyArray(float copyTo[4], float from[4]){
	int i;
	for(i=0; i<4; i++){
		copyTo[i] = from[i];
	}	
}

float knapSack(float arr[][4]){
	float profit = 0.f;
	int tempSize = BAG_SIZE;
	int i;
	for(i=0; i<SIZE; i++){
		float itemSize = arr[i][1];
		
		if(tempSize > 0.0f){					
			if(itemSize > tempSize){
				float portion = tempSize/itemSize;
				arr[i][3] = portion * arr[i][0];
				tempSize = 0;
				profit += arr[i][3];
			}
			else{
				tempSize -= itemSize;
				arr[i][3] = arr[i][0];
				profit += arr[i][3];
			}
		}
		else{
			arr[i][3] = 0.f;
		}

	}
	
	return profit;
}

