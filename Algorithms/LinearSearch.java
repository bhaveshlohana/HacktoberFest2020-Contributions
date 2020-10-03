import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter array size");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter array elements");
		for(int i =0 ;i<n;i++){
		    arr[i] = sc.nextInt();
		}
		System.out.println("Enter number to search");
		int k = sc.nextInt();
		int i =0;
		for(i=0;i<n;i++){
		    if(arr[i]==k){
		        System.out.println(k + " is at index "+i);
		        break;
		    }
		}
		if(i==n){
		    System.out.println("Number is not in the array");
		}
		
	}
}