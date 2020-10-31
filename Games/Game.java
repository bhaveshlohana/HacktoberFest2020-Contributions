
import java.util.Random;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author tasmi
 */
public class Game {
    public static void main(String []args)
    {
        int num,ans;
        Scanner kb=new Scanner(System.in);
        System.out.println("enter a number between 0-20 :");
        num=kb.nextInt();
        Random n=new Random();
        ans=n.nextInt(21);
        if(num==ans)
            System.out.println("\nCongrats!you won!");
        else
            System.out.println("\nBetter luck next time!");
        System.out.println("\nYou entered : "+num+"\t Number appeared : "+ans);
        
    }
    
}
