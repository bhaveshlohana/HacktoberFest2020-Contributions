import java.io.*;
import java.util.Scanner;

public class CountingSort {

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        r = -1;

        // Input size
        System.out.print("Enter size of the array: ");
        int n = in.nextInt();

        // Input array
        int[] arr = new int[n];
        System.out.println("Enter the array elements (one by one): ");
        for (int i = 0; i < n; ++i) {
            arr[i] = in.nextInt();
	    if (r < arr[i]) {
                r = arr[i];
            }
        }

        // Apply countingSort sort algo
        arr = countingSort(arr, r);

        // Print sorted array
        System.out.println("Enter the array elements (one by one): ");
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static int[] countingSort(int[] arr, int r) {
        int n = arr.length;
        int[] sarr = new int[arr.length];
        int[] counts = new int[r + 1];

        // Counting array elements
        for (int i = 0; i < n; ++i) {
            counts[arr[i]]++;
        }

        // Cummulative freqs
        for (int i = 1; i < r + 1; ++i) {
            counts[i] += counts[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            sarr[counts[arr[i]] -  1] = arr[i];
            counts[arr[i]]--;
        }

        return sarr;
    }
}
