import java.util.*;
class TransposeOfMatrix {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of rowsXcolumns");
        int r = scanner.nextInt();
        int c = scanner.nextInt();
        int A[][] = new int[r][c];
        System.out.println("Enter elements of the matrix:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                A[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        System.out.println("Transpose of matrix: ");
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                System.out.print(A[j][i] + " ");
            }
            System.out.println();
        }          
    }
}