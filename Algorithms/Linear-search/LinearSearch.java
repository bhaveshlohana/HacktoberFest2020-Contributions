import java.util.*;
class linsrch
{
    int arr[];
  public static void main()
  {
      Scanner SC=new Scanner(System.in);
      int n=SC.nextInt();
      
      arr=new int[n];
      for(int i=0;i<n;i++)
      {arr[i]=SC.nextInt();}
      
      int key1=SC.nextInt();
    }
    
    void linears(int key)
    {
        for(int i=0;i<arr.length;i++)
        {
          if(arr[i]==key)
          {System.out.println("Element found at"+i);
          break;}
          }
          
       }
   }
      
      
