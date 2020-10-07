import java.util.*;
public class Main
{
public static void main(String[] args) {
int n,i;
int fact,rem;
Scanner sc = new Scanner(System.in);
System.out.print("\nEnter the number : ");
n = sc.nextInt();
int sum = 0;
int temp = n;
while(n != 0)
{
i = 1;
fact = 1;
rem = n % 10;

while(i <= rem)
{
fact = fact * i;
i++;
}
sum = sum + fact;
n = n / 10;
}

if(sum == temp)
System.out.println(temp + " is a strong number\n");
else
System.out.println(temp + " is not a strong number\n");

System.out.println();
}
}
