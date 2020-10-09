/**
 * A digital clock that shows the time without stopping
 * 
 * @author IryaDev
 */

public class DigitalClock {
    public static void main(String[] args) throws InterruptedException {
        int hours = 0, minutes = 0, seconds = 0;
 
        while (true) {
            //Show
            //If it is less than 10, we write a 0 in front
            if (hours < 10) {
                System.out.print("0");
            }
            System.out.print(hours + ":");
 
            if (minutes < 10) {
                System.out.print("0");
            }
            System.out.print(minutes + ":");
 
            if (seconds < 10) {
                System.out.print("0");
            }
            //Line break
            System.out.println(seconds);
 
            //Increase time
            seconds++;
 
            //Check the time
            if (seconds == 60) {
                //Reset seconds
                seconds = 0;
                //Increase minutes
                minutes++;
                if (minutes == 60) {
                    //Reset minutes
                    minutes = 0;
                    //Increase hours
                    hours++;
                    if (hours == 24) {
                        //Reset hours
                        hours = 0;
                    }
                }
            }
 
            Thread.sleep(1000);
 
        }
 
    }
 
}