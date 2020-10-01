import java.io.*;
import java.util.Scanner;

public class QuickSort{

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter the size of the array:");
        int n = in.nextInt();

        // Input array
        int[] arr = new int[n];
        System.out.println("Enter the array elements (one by one): ");
        for (int i = 0; i < n; ++i) {
            arr[i] = in.nextInt();
        }

        // Apply QuickSort sort algo
        arr = quickSort(arr, 0, n - 1);

        // Print sorted array
        System.out.println("Sorted array elements: ");
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static int[] quickSort(int[] arr, int l, int r) {
        if (l < r) {
            // partition the array w.r.t pivot element
            int p = partition(arr, l, r);

            // Divide the array
            quickSort(arr, l, p - 1);
            quickSort(arr, p + 1, r);
        }
        return arr;
    }

    public static int partition(int[] arr, int l, int r) {
        int i = l;
        // Choose last element as pivot element
        int pivot = arr[r];

        for (int j = l; j < r; ++j) {
            if (arr[j] <= pivot) {
                swap(arr, i, j);
                i++;
            }
        }
        swap(arr, i, r);
        return i;
    }


    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
