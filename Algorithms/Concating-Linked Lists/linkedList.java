public class linkedList
{
    protected Node start;
    
    public linkedList()
    {
        start=null;
    }


    public boolean isEmpty()
    {
        return(start==null);
    }
    
    public void Insert(int val)
    {
        Node nptr,ptr,save=null;
        
        nptr=new Node(val,null);
        
        boolean ins=false;
        
        if(start==null)
            start=nptr;
        else
        if(val<=start.getData())
        {
            nptr.setLink(start);
            start=nptr;
        }
        else
        {
            save=start;
            ptr=start.getLink();
            
            while(ptr!=null)
            {
                if(val>=save.getData()&&val<=ptr.getData())
                {
                    save.setLink(nptr);
                    nptr.setLink(ptr);
                    ins=true;
                    break;
                }
                else
                {
                    save=ptr;
                    ptr=ptr.getLink();
                }
            }
            
            if(ins==false)
            {
                save.setLink(nptr);
            }
        }
            
    }
    
    public void Traverse()
    {
        Node ptr=start;
        
        System.out.print(start.getData()+"--->");
        ptr=start.getLink();
        
        while(ptr.getLink()!=null)
        {
            System.out.print(ptr.getData()+"--->");
            ptr=ptr.getLink();
        }
        
        System.out.print(ptr.getData()+"!!!");
        System.out.println();
    }
    
    public void Concat(Node L2)
    {
        Node ptr,save=null;
        
        save =ptr=start;
        
        while(ptr!=null)
        {
            save=ptr;
            ptr=ptr.getLink();
        }
        
        save.setLink(L2);
    }
    
    
}