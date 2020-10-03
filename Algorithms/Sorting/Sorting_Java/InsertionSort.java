import java.util.Scanner;

public class InsertionSort {
    public static void insertionSort (int[] a) {
        int temp, ind, n = a.length;
        // Loop through the array
        for (int i = 0; i < n; ++i) {
            ind = i;
            for (int j = i - 1; j >= 0; --j) {
                if (a[j] > a[ind]) {
                    temp = a[j];
                    a[j] = a[ind];
                    a[ind] = temp;
                    ind = j;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n;
        System.out.print("Enter the size of the array: ");
        n = in.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; ++i) {
            arr[i] = in.nextInt();
        }

        // Apply the insertion sort algo
        insertionSort(arr);

        System.out.println("The sorted array is: ");
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
    }
}
