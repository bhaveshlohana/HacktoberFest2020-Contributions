import java.util.Scanner;

public class Main {


    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        String lines = "- - -";
        String lines2 = "|";
        int[] steps = new int[9];
        String[] graphic = new String[9];
        System.out.println("Tic-Tac-Toe by Rescor\n");
        System.out.println("Вы играете крестиками. Для выбора поля введите его номер:");
        System.out.println("1|2|3");
        System.out.println(lines);
        System.out.println("4|5|6");
        System.out.println(lines);
        System.out.println("7|8|9\n");

        for (int i = 0; i < graphic.length; i++){
            graphic[i] = " ";
        }

        for (int x = 0; x < steps.length+1; x++) {

            if (graphic[0].equals(graphic[1]) && graphic[0].equals(graphic[2]) && !graphic[0].equals(" ")) {
                System.out.println("Выиграли "+graphic[0]);
                break;
            }
            if (graphic[3].equals(graphic[4]) && graphic[3].equals(graphic[5]) && !graphic[3].equals(" ")){
                System.out.println("Выиграли "+graphic[3]);
                break;
            }
            if (graphic[6].equals(graphic[7]) && graphic[6].equals(graphic[8]) && !graphic[6].equals(" ")){
                System.out.println("Выиграли "+graphic[6]);
                break;
            }
            if (graphic[0].equals(graphic[4]) && graphic[0].equals(graphic[8]) && !graphic[0].equals(" ")){
                System.out.println("Выиграли "+graphic[0]);
                break;
            }
            if (graphic[2].equals(graphic[4]) && graphic[2].equals(graphic[6]) && !graphic[2].equals(" ")){
                System.out.println("Выиграли "+graphic[2]);
                break;
            }
            if (graphic[0].equals(graphic[3]) && graphic[0].equals(graphic[6]) && !graphic[0].equals(" ")){
                System.out.println("Выиграли "+graphic[0]);
                break;
            }
            if (graphic[1].equals(graphic[4]) && graphic[1].equals(graphic[7]) && !graphic[1].equals(" ")){
                System.out.println("Выиграли "+graphic[1]);
                break;
            }
            if (graphic[2].equals(graphic[5]) && graphic[2].equals(graphic[8]) && !graphic[2].equals(" ")){
                System.out.println("Выиграли "+graphic[2]);
                break;
            }

            System.out.println("Ваш ход: ");
            steps[x] = scanner.nextInt();

            graphic[steps[x]-1] = "x";



            while (true){
                boolean hasNumber = false;
                int random = 0 + (int) (Math.random() * 9);
                for (int z: steps) {
                    if (z == random) {
                        hasNumber = true;
                        break;
                    }
                }
                if (!hasNumber) {
                    x++;
                    steps[x] = random;
                    graphic[random-1] = "o";
                    break;
                    }
                }
				
            System.out.println(graphic[0]+lines2+graphic[1]+lines2+graphic[2]);
            System.out.println(lines);
            System.out.println(graphic[3]+lines2+graphic[4]+lines2+graphic[5]);
            System.out.println(lines);
            System.out.println(graphic[6]+lines2+graphic[7]+lines2+graphic[8]+"\n");
            }
        }
}