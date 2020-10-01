
// Java program to illustrate
// CopyOnWriteArrayList class
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.*;
 
public class ConcurrentDemo extends Thread {
 
    static CopyOnWriteArrayList l = new CopyOnWriteArrayList();
 
    public void run()
    {
        // Child thread trying to
        // add new element in the
        // Collection object
        l.add("D");
    }
 
    public static void main(String[] args)
        throws InterruptedException
    {
        l.add("A");
        l.add("B");
        l.add("c");
 
        // We create a child thread
        // that is going to modify
        // ArrayList l.
        ConcurrentDemo t = new ConcurrentDemo();
        t.run();
 
        Thread.sleep(1000);
 
        // Now we iterate through
        // the ArrayList and get
        // exception.
        Iterator itr = l.iterator();
        while (itr.hasNext()) {
            String s = (String)itr.next();
            System.out.println(s);
            Thread.sleep(1000);
        }
        System.out.println(l);
    }
}
