
# include <stdio.h>


int main(void)
{
    int changeOwed;
    int check;
    char invisibleChar;
    int count = 0;
	int numQ=0, numD=0, numN=0, numP=0;
    
      /***Run this loop until the user inputs a number and it is greater than or equal to 0***/
    do{
          printf("How much change is owed (in cents)?\n");
        check = scanf("%d", &changeOwed); // returns 1 if the input is a number and returns 0 otherwise
        
        //Get's rid of any extra invisible characters if the input is a char/String
        do{
            scanf("%c",&invisibleChar);
        }while(invisibleChar != '\n');
            
    }while(check == 0 || !(changeOwed >=0 ));
    
    
    int c = changeOwed;// The variable c was only used to shorten my typing
    //Continue to do this loop until 
	while(c > 0){
	
	    //Use as many quarters needed
		while(c >= 25){
			count ++;
			numQ++;
			c = c - 25;
		}
		//Use as many dimes needed
		while(c >= 10){
			count ++;
			numD++;
			c = c - 10;
		}
		//Use as many nickels needed
		while(c >= 5){
			count ++;
			numN++;
			c = c - 5;
		}
		//Use as many pennies needed
		while(c >= 1){
			count ++;
			numP++;
		c = c - 1;
		}

	}
    
 	printf("Quarters: %d, Dimes: %d, Nickels: %d, Pennies: %d\nNumber of coins used= %d\n\n", numQ, numD, numN, numP, count);
   
    system("pause"); //Comment this out if you are not using windows operating system
}
