
public class FizzBuzz {
    public String play(int number) {
        String value = "";
        if (number == 0) value = "ZERO";
        if(number == 1) value = "ONE";
        if(number == 2) value = "TWO";
        if(isDivisibleBythree(number) && isGreaterThanTwo(number)) value = "FIZZ";
        if(isDivisibleByFive(number) && isGreaterThanTwo(number)) value = "BUZZ";
        if(isDivisibleByFive(number) && isDivisibleBythree(number) && isGreaterThanTwo(number)) value = "FIZZBUZZ";
        return value;
    }

    private boolean isDivisibleByFive(int number) {
        return number % 5 == 0;
    }

    private boolean isDivisibleBythree(int number) {
        return number % 3 == 0;
    }

    private boolean isGreaterThanTwo(int number) {
        return number > 2;
    }
}
