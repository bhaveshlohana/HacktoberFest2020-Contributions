import java.util.Scanner;

class SelectionSort {
  public static void selectionSort (int[] arr) {
    int minInd, temp, n = arr.length;
    // Iterate over the array
    for (int i = 0; i < n - 1; ++i) {
        minInd = i;
        // Select the minimum element in right half of the array
        for (int j = i + 1; j < n; ++j) {
            if (arr[minInd] > arr[j]) {
                minInd = j;
            }
        }
        // swap the minimum element with the element at ith position
        temp = arr[minInd];
        arr[minInd] = arr[i];
        arr[i] = temp;
    }
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

        // Apply Selection sort
        selectionSort(a);

        // Print array
        System.out.print("Array: ");
        for (int i = 0; i < n; ++i)
        {
            System.out.print(a[i] + " ");

        }
        System.out.println();
  }
}
