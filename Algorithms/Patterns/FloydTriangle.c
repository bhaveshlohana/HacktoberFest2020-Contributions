// C program to print Floyd Triangle
 #include <conio.h>
 #include <stdio.h>
 
        //function to print floyd triangle
 
 		void displayFloydTriangle(int n)
 		{
 			 int row, col, temp = 1;  
               for (row = 1; row <= n; row++)  
                {  
                  for (col = 1; col <= row; col++)  
                  
                     printf("%d ",temp++);  
                     
                 printf("\n");
                 }  
        }  
        
        //main function to control program execution by calling other functions
        
        int main()
        {
        	int num;
        	
        	printf("Enter the number of lines ");
        	  scanf("%d",&num);
        	  
        	  //calling function in main
        	  
        	 displayFloydTriangle(num);
			 
		return 0;	    
		}
		 