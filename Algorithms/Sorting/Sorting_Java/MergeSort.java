import java.io.*;
import java.util.Scanner;

public class MergeSort{

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // Input size
        System.out.println("Enter size of the array: ");
        int n = in.nextInt();

        // Input array
        int[] arr = new int[n];
        System.out.println("Enter the array elements (one by one): ");
        for (int i = 0; i < n; ++i) {
            arr[i] = in.nextInt();
        }

        // Apply merge sort algo
        mergeSort(arr, 0, n - 1);

        // Print sorted array
        System.out.println("Sorted the array elements: ");
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void mergeSort(int[] arr, int lb, int ub) {
        if (lb < ub) {
            // Find the mid point
            int mid = (lb + ub) / 2;

            // Divide the array at mid point and apply mergesort
            mergeSort(arr, lb, mid);
            mergeSort(arr, mid + 1, ub);

            // Merge the two sorted arrays
            merge(arr, lb, mid, ub);
        }
    }

    public static void merge(int[] arr, int lb, int mid, int ub) {
        // Copy the elements in big array into 2 small arrays, inorder to sort inplace

        int n1 = mid - lb + 1;
        int n2 = ub - mid;

        // Declare two arrays & Copy the elements
        int[] left = new int[n1];
        int[] right = new int[n2];

        for (int i = 0; i < n1; ++i) {
            left[i] = arr[lb + i];
        }

        for (int i = 0; i < n2; ++i) {
            right[i] = arr[mid + i + 1];
        }

        int i = 0, j = 0, k = lb;

        // Merge
        while (i < n1 && j < n2) {
            if (left[i] < right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // array which are left in left or right arrays
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (i < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}
