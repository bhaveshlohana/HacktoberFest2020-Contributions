/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reversenumber;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class ReverseNumber {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
         int num,rev=0,rem=0;
        
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter Number:");
        num=sc.nextInt();
        
        rev=0;
        
        while(num>0)
        {
            rem=num%10;
            rev=(rev*10)+rem;
            num=num/10;
            
        }
        
        System.out.println("The Reverse of the number is "+rev);
    }
    
}
