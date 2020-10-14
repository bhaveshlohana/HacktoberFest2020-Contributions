/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package digitcount;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class DigitCount {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int num,count=0;
        
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter Number:");
        num=sc.nextInt();
        
        while(num>0)
        {
            num=num/10;
            count++;
        }
        
        System.out.println("The Number of Digits is "+count);
    }
    
}
