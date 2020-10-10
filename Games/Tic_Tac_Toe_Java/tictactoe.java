import java.util.Scanner;

public class tictactoe {
    public static void main(String Args[]) {

        Scanner kb = new Scanner(System.in);
        char[][] m = new char[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = '_';
            }
        }
        Print(m);

        int k = 1, x = 0, o = 0, out = 0;
        int xx = -1, yy = -1;
        wd: while (out != 1) {
            while (xx == -1 && yy == -1) {
                System.out.println("Enter the coordinates:");

                String c = kb.nextLine();

                if (Character.isDigit(c.charAt(0)) == true && Character.isDigit(c.charAt(2)) == true) {
                    String[] cc = c.split(" ");
                    xx = Integer.parseInt(cc[0]);
                    yy = Integer.parseInt(cc[1]);
                    if ((xx <= 3 && xx >= 1) && (yy <= 3 && yy >= 1)) {
                        if (m[xx - 1][yy - 1] == '_') {
                            if (k % 2 == 1) {
                                m[xx - 1][yy - 1] = 'X';
                                x++;
                            } else {
                                m[xx - 1][yy - 1] = 'O';
                                o++;
                            }
                            Print(m);

                            char win = ' ';
                            int l = 0;
                            if (m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != '_') {
                                win = m[0][0];
                                l++;
                            } else if (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != '_') {
                                win = m[0][0];
                                l++;
                            } else {
                                for (int i = 0; i < 3; i++) {
                                    if (m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != '_') {
                                        win = m[i][0];
                                        l++;
                                    } else if (m[0][i] == m[1][i] && m[1][i] == m[2][i] && m[0][i] != '_') {
                                        win = m[0][i];
                                        l++;
                                    } else {
                                    }
                                }
                            }
                            if (Math.abs(x - o) >= 2) {
                                System.out.println("Impossible");
                                out = 1;
                            } else if (l == 0 && k == 9) {
                                System.out.println("Draw");
                                out = 1;
                            } else if (l == 1) {
                                System.out.println(win + " wins");
                                out = 1;
                            } else if (l > 1) {
                                System.out.println("Impossible");
                                out = 1;
                            } else if (k <= 9) {
                                k++;
                                xx = -1;
                                yy = -1;
                                continue wd;
                            } else {
                                System.out.println("Impossible");
                                out = 1;
                            }
                        } else {
                            System.out.println("This cell is occupied! Choose another one!");
                            xx = -1;
                            yy = -1;
                        }
                    } else {
                        System.out.println("Coordinates should be from 1 to 3!");
                        xx = -1;
                        yy = -1;
                    }
                } else {
                    System.out.println("You should enter numbers!");
                }

            }
            kb.close();
        }
    }

    static void Print(char[][] m) {
        System.out.println("---------");
        for (int i = 0; i < 3; i++) {
            System.out.print("| ");
            for (int j = 0; j < 3; j++) {
                System.out.print(m[i][j] + " ");
            }

            System.out.print("|");
            System.out.println();
        }
        System.out.println("---------");
    }
}