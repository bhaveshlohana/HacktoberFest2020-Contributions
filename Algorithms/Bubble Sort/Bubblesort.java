public class BubbleSort {
	static void bubbleSort(int[] arr) {
        int n = arr.length;
        int temp = 0;
         for(int i=0; i < n; i++){
                 for(int j=1; j < (n-i); j++){
                          if(arr[j-1] > arr[j]){
                                 //swap elements
                                 temp = arr[j-1];
                                 arr[j-1] = arr[j];
                                 arr[j] = temp;
                         }

                 }
         }

    }
    void burbuja(int[] A) {
        int i, j, aux;
        for (i = 0; i < A.length - 1; i++) {
            for (j = 0; j < A.length - i - 1; j++) {
                if (A[j + 1] < A[j]) {
                    aux = A[j + 1];
                    A[j + 1] = A[j];
                    A[j] = aux;
                }
            }
        }
}
    public static void main(String[] args) {
                int arr[] ={3,60,35,2,45,320,5};

                System.out.println("Array Before Bubble Sort");
                for(int i=0; i < arr.length; i++){
                        System.out.print(arr[i] + " ");
                }
                System.out.println();

                bubbleSort(arr);//sorting array elements using bubble sort

                System.out.println("Array After Bubble Sort");
                for(int i=0; i < arr.length; i++){
                        System.out.print(arr[i] + " ");
                }

        }
}
