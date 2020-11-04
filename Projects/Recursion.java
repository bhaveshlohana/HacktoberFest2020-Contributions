import java.util.Scanner;

public class Recursion{
    public static void main (String[] args){
        Scanner tastiera = new Scanner(System.in);
        countingDown(3);

    }
    public static void countingDown(int num){
        if(num<1){
            System.out.println();
        }else{ 
            System.out.println(num);
            num-=1;
            countingDown(num);
        }
        
    }
}