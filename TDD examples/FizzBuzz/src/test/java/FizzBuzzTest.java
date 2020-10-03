import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/*SUM OF KATA  :
* 1 - We have from 1 to 100 like entry point
* 2- If number is in range of 0 to 2 returns the number name on string format
* 2 - If Number is divisible by 3 returns FIZZ
* 3. If number is divisible by 5 returns BUZZ
* 4. If number is divisible by 3 and 5 return FIZZBUZZ
* */

class FizzBuzzTest {
    private static FizzBuzz fizzBuzz;

    @BeforeAll
    static void beforeAll() {
        fizzBuzz = new FizzBuzz();
    }

    @Test
    void ifNumberIsZeroShouldReturnZero() {
        String actual = fizzBuzz.play(0);
        assertEquals("ZERO" , actual);
    }

    @Test
    void ifNumberIsOneShouldReturnOne() {
        String actual = fizzBuzz.play(1);
        assertEquals("ONE" , actual);
    }
    @Test
    void ifNumberIs2ShouldReturnTwo() {
        String actual = fizzBuzz.play(2);
        assertEquals("TWO" , actual);
    }
    @Test
    void ifNumberIs3ShouldReturnFizz() {
        String actual = fizzBuzz.play(3);
        assertEquals("FIZZ" , actual);
    }
    @Test
    void ifNumberIs5ShouldReturnBuzz() { ;
        String actual = fizzBuzz.play(5);
        assertEquals("BUZZ" , actual);
    }
    @Test
    void ifNumberIsDivisibleBy3ShouldReturnFizz() {
        String actual = fizzBuzz.play(6);
        assertEquals("FIZZ" , actual);
    }
    @Test
    void ifNumberIsDivisibleBy5ShouldReturnBuzz() {
        String actual = fizzBuzz.play(10);
        assertEquals("BUZZ" , actual);
    }

    @Test
    void ifNumberIsDivisibleBy5AndBy3ShouldReturnFizzBuzz() {
        String actual = fizzBuzz.play(15);
        assertEquals("FIZZBUZZ" , actual);
    }

}