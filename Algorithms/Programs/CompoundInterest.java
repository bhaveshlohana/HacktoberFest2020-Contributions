import java.util.Scanner;
import static java.lang.Math.*;

// Other imports go here
// Do NOT change the class name


class CompoundInterest
{
    public static void main(String[] args)
    {  
       Scanner sc=new Scanner(System.in);
       int tc=sc.nextInt();
       double pa,r,t,i;
       double ci;
      for(i=0;i<tc;i++)
      {
        pa=sc.nextDouble();
        r=sc.nextDouble();
        t=sc.nextDouble();
        ci=(double)pa*pow(1+(r/100),t);  //double c=(double)p*pow((1+(r/100)),t);
        System.out.printf("%.1f",ci);
      }
      
    }
}