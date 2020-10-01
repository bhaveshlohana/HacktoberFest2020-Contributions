import java.io.*;
import java.util.Scanner;

public class ShellSort{

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

        // Apply shell sort algo
        shellSort(arr);

        // Print sorted array
        System.out.println("Sorted the array elements: ");
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void shellSort(int[] arr) {
        int temp, n = arr.length;

        for (int interval = n / 2; interval >= 1; interval /= 2) {
            // Traverse through array comparing elems at intervals
            for (int i = interval; i < n; ++i) {
                for (int j = i - interval; j >= 0; j -= interval) {
                    if (arr[j + interval] > arr[j]) {
                        break;
                    } else {
                        temp = arr[j + interval];
                        arr[j + interval] = arr[j];
                        arr[j] = temp;
                    }
                }

            }
        }
    }
}
