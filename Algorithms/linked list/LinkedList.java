class node
{
    int data;
    node next;
}
import java.util.*;
class sinlinlist
{
    static Scanner SC=new Scanner(System.in);
    node start,prev,item;
    sinlinlist()
    {
        start=prev=item=null;
    }
    
    void create()
    {
        item=new node();
        System.out.println("ENter data");
        item.data=SC.nextInt();
        item.next=null;
        if(start==null)
        {
            start=prev=item;
        }
            else
            {
                prev.next=item;
            }
            prev=item;
    }
     
    void disp()
    {
        if(start==null)
        {
            System.out.println("List empty");
        }
            else
            {
                node temp=start;
                while(temp!=null)
                {
                    System.out.println(temp.data);
                    temp=temp.next;
                }
            }
        }
        void insert()
        {
            node p1=null,p2=null;
            int r;
            if(start==null)
            System.out.println("Cant insert in empty list");
            else
            {
                System.out.println("Enter data before which to insert");
                r=SC.nextInt();
                p1=start;
                while(p1!=null&&p1.data!=r)
                {
                    p2=p1;
                    p1=p1.next;
                }
                if(p1==null)
                System.out.println("data not found");
                else if (p1==start)
                {
                    item=new node();
                    System.out.println("Enter data.");
                    item.data=SC.nextInt();
                    item.next=start;
                    start=item;
                }
                else
                {
                    item=new node();
                    System.out.println("Enter data");
                    item.data=SC.nextInt();
                    item.next=p1;
                    p2.next=item;
                }
            }
        }
        
        void deletion()
        {
            if(start==null)
            {
                System.out.println("List empty");
            }
            else
            {
                System.out.println("Enter data to be deleted");
                int k=SC.nextInt();
                node p1=start,p2=null;
                while(p1!=null&&p1.data!=k)
                {
                    p2=p1;
                    p1=p1.next;
                }
                if(p1==null)
                {
                    System.out.println("Data to be deleted not found");
                }
                else if(p1==start)
                {
                    start=start.next;
                }
                else if (p1.next==null)
                {
                    prev=p2;
                    p2.next=null;
                }
                else
                {
                    p2.next=p1.next;
                }
            }
        }
        void reversal()
        {
            if(start==null)
            {System.out.println("EMpty list");}
            else{
            int count=0;
            node temp=start;
            while(temp!=null)
            {
                count++;
                temp=temp.next;
            }
            node f=start;
            node l=start;
            while(l.next!=null)
            {
                l=l.next;
            }
            for(int i=1;i<=count/2;i++)
            {
                int k=f.data;
                f.data=l.data;
                l.data=k;
                temp=start;
                while(temp.next!=null)
                {
                    temp=temp.next;
                }
                l=temp;
                f=f.next;
            }
        }}
        
        void sort()
        {
            for(node p1=start;p1.next!=null;p1=p1.next)
            {
                for(node p2=p1.next;p2!=null;p2=p2.next)
                {
                    if(p1.data>p2.data)
                    {
                        int t=p1.data;
                        p1.data=p2.data;
                        p2.data=t;
                    }
                }
            }
        }
}
    
