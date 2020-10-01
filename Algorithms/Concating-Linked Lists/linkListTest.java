import java.io.*;
public class linkListTest
{
    protected static linkedList L1,L2;
    
    public static void main(String args[])throws IOException
    {
        
        int num;
        
        L1=new linkedList();
        L2=new linkedList();
        
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        
        for(int a=0;a<5;a++)
        {
            System.out.println("Enter a Number : ");
            
            try
            {
                num=Integer.parseInt(br.readLine());
                
                L1.Insert(num);
                
                System.out.println("Inserted : "+num);
            }
            
            catch(Exception e)
            {
                System.out.println(e);
            }
        }
        
        System.out.println("\nCreadted List is\n");
        
        L1.Traverse();
        System.out.print("\n---OVER---");
        
       for(int a=0;a<5;a++)
        {
            System.out.println("Enter a Number : ");
            
            try
            {
                num=Integer.parseInt(br.readLine());
                
                L2.Insert(num);
                
                System.out.println("Inserted : "+num);
            }
            
            catch(Exception e)
            {
                System.out.println(e);
            }
        }
        
        System.out.println("\nCreadted List is\n");
        
        L2.Traverse();
        System.out.print("\n---OVER---"); 
        
        
        L1.Concat(L2.start);
        
        System.out.println("\nCombined List\n");
        L1.Traverse();
        System.out.println("\n---Process Over---");
        
     
    }
        
        
    }