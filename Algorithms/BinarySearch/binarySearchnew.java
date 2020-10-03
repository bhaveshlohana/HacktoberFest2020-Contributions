import java.util.*;

public class binarySearch
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int N = sc.nextInt();
        System.out.println("Enter the elements in the array");
        int[] array = new int[N];
        for(int i=0;i<N;i++)
        {
            array[i]=sc.nextInt();
        }
        System.out.println("Enter the element to be searched in the array");
        int search = sc.nextInt();
        int first = 0;
        int last= array.length - 1;
        int mid = (first + last)/2;
        while (first <= last)
        {
            if(array[mid]< search)
                first = mid+1;
            else if(array[mid]==search)
            {
                System.out.println("Found");
                break;
            }
            else
            {
                last=mid-1;
            }
            mid = (first+last)/2;
        }

    }
}
