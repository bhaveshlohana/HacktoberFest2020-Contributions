import java.util.ArrayList;
import java.util.List;

public class Main {

    private static final int FIRST_NUMBER = 0;
    private static final int LAST_NUMBER = 100;

    public static void main(String[] args) {
        FizzBuzz fizzBuzz = new FizzBuzz();

        for(int number = FIRST_NUMBER ; number<= LAST_NUMBER ; number++){
            System.out.println("Numero : " + number + " RESPUESTA : " + fizzBuzz.play(number) );
        }
    }
}
