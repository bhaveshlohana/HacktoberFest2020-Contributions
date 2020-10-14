/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package armstrong;


import java.lang.Math;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Armstrong {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        long count,num,rem,temp,sum=0;
        
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter Number:");
        num=sc.nextLong();
        
        temp=num;
        count=0;
        while(num>0)
        {
            num=num/10;
            count++;
        }
        
        num=temp;
        
        while(num>0)
        {
            rem=num%10;
            sum=(long) (sum+Math.pow(rem,count));
            num=num/10;
        }
        
        System.out.println(sum);
        
        if(temp==sum)
            System.out.println("It is an Armstrong Number.");
        else
            System.out.println("It is not an Armstrong Number.");
    }
    
}
