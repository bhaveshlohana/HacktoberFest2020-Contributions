import java.util.Scanner;

class BubbleSort {
    public static int[] bubbleSort (int[] arr) {
        // Temperory varaible for sorting
        int temp;
        int n = arr.length;
        // Bubble sort algorithm
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        return arr;
    }

    public static void main(String[] args) {
        int a[];   // only a array reference
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        n = sc.nextInt();

        a = new int[n];

        // Take array input
        System.out.println("Enter values into array:");
        for (int i = 0; i < n; ++i)
        {
            System.out.printf("Enter %d index elem:", i);
            a[i] = sc.nextInt();
        }

        // Apply bubble sort
        a = bubbleSort(a);

        // Print array
        System.out.print("Array: ");
        for (int i = 0; i < n; ++i)
        {
            System.out.print(a[i] + " ");

        }
        System.out.println();
    }
}
