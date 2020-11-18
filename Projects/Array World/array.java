import java.util.Scanner;
public class array {

 public static void main(String[] args) {
  try {
   new ProcessBuilder("cmd", "/c", "color f0").inheritIO().start();
  } catch (Exception e) {}
  stop(15);
  System.out.println("\n\n\n");
  System.out.print("\t\t\t\t\t    /****\\          |****\\         |****\\           /****\\           \\**\\  /**/\n");
  stop(55);
  System.out.print("\t\t\t\t\t   /**/\\**\\         |**  */        |**  */         /**/\\**\\           \\**\\/**/ \n");
  stop(55);
  System.out.print("\t\t\t\t\t  /********\\        |****|         |****|         /********\\           \\****/\n");
  stop(55);
  System.out.print("\t\t\t\t\t /**/    \\**\\       |**|\\*\\        |**|\\*\\       /**/    \\**\\           |**|\n");
  stop(55);
  System.out.println("\t\t\t\t\t/**/      \\**\\      |**| \\*\\       |**| \\*\\     /**/      \\**\\          |**|   ");
  stop(50);

  int[] arr = null;
  Scanner in = new Scanner(System.in);
  int choice;
  boolean quit = false, sorted = false;
  do {
   System.out.println("\n\t\t\t\t\t\t\tMenu\n" +
    "\t\t\t\t\t\t\t1. Enter length of array\n" +
    "\t\t\t\t\t\t\t2. Enter elements in array\n" +
    "\t\t\t\t\t\t\t3. find the second highest in array\n" +
    "\t\t\t\t\t\t\t4. find the second lowest  in array\n" +
    "\t\t\t\t\t\t\t5. find average\n" +
    "\t\t\t\t\t\t\t6. Sort array in descending order\n" +
    "\t\t\t\t\t\t\t7. Sort array in ascending order\n" +
    "\t\t\t\t\t\t\t8. Search element\n" +
    "\t\t\t\t\t\t\t9. Quit\n" +
    "\t\t\t\t\t\t\tEnter your choice");
   choice = in .nextInt();

   switch (choice) {
    case 1:
     System.out.println("\t\t\t\t\t\t\tEnter:");
     int x = in .nextInt();
     arr = new int[x];
     System.out.println("\t\t\t\t\t\t\tArray of length " + x + " has been created");
     break;
    case 2:
     if (arr == null) {
      System.out.println("\t\t\t\t\t\t\tselect option 1 first as no array exists");
     } else {
      for (int i = 0; i < arr.length; i++) {
       System.out.println("\t\t\t\t\t\t\tEnter element no." + (i + 1));
       int temp = in .nextInt();
       arr[i] = temp;
      }
     }
     break;
    case 3:
     if (arr == null) {
      System.out.println("\t\t\t\t\t\t\tselect option 1 first as no array exists");
     } else {
      int high = Integer.MIN_VALUE, high2 = Integer.MIN_VALUE;
      for (int i = 0; i < arr.length; i++) {
       if (arr[i] > high) {
        high2 = high;
        high = arr[i];
       }
	else if( arr[i] < high && arr[i]>high2){
	high2 = arr[i];
	}
      }
      System.out.println("\t\t\t\t\t\t\tSecond highest element is " + high2);
     }
     break;
    case 4:
     if (arr == null) {
      System.out.println("\t\t\t\t\t\t\tselect option 1 first as no array exists");
     } else {
      int low = Integer.MAX_VALUE, low2 = Integer.MAX_VALUE;
      for (int i = 0; i < arr.length; i++) {
       if (arr[i] < low) {
        low2 = low;
        low = arr[i];
       }
	else if( arr[i] > low && arr[i]<low2){
	low2 = arr[i];
	}
      }
      System.out.println("\t\t\t\t\t\t\tSecond lowest element is " + low2);
     }
     break;
    case 5:
     if (arr == null) {
      System.out.println("\t\t\t\t\t\t\tselect option 1 first as no array exists");
     } else {
      float sum = 0f;
      for (int i: arr) {
       sum += i;

      }
      System.out.println("\t\t\t\t\t\t\tAverage is " + (float)(sum) / 2);
     }
     break;
    case 6:
     if (arr == null) {
      System.out.println("\t\t\t\t\t\t\tselect option 1 first as no array exists");
     } else {

      for (int i = 0; i < arr.length; i++) {

       boolean b = false;

       for (int j = 0; j < arr.length - i - 1; j++) {

        if (arr[j] < arr[j + 1]) {
         arr[j] = arr[j] ^ arr[j + 1];
         arr[j + 1] = arr[j] ^ arr[j + 1];
         arr[j] = arr[j] ^ arr[j + 1];
         b = true;
        }
       }
       if (!b) {
        break;
       }
      }
      System.out.println("\t\t\t\t\t\t\tarray is now sorted in Descending order");

      for (int i: arr) {
       System.out.println("\t\t\t\t\t\t\t" + i);
      }
     }
     break;
    case 7:
     if (arr == null) {
      System.out.println("\t\t\t\t\t\t\tselect option 1 first as no array exists");
     } else {
      for (int i = 0; i < arr.length; i++) {
       boolean b = false;

       for (int j = 0; j < arr.length - i - 1; j++) {

        if (arr[j] > arr[j + 1]) {

         arr[j] = arr[j] ^ arr[j + 1];
         arr[j + 1] = arr[j] ^ arr[j + 1];
         arr[j] = arr[j] ^ arr[j + 1];
         b = true;
        }
       }
       if (!b) {
        break;
       }
      }
      sorted = true;
      System.out.println("\t\t\t\t\t\t\tarray is now sorted in Ascending order");
      for (int i: arr) {
       System.out.println("\t\t\t\t\t\t\t" + i);
      }
     }

     break;
    case 8:
     if (arr == null) {
      System.out.println("\t\t\t\t\t\t\tselect option 1 first as no array exists");
     } else if (!sorted) {
      System.out.println("\t\t\t\t\t\t\tEnter number to search");
      int z = in .nextInt();
      boolean found = false;
      for (int i = 0; i < arr.length; i++) {
       if (z == arr[i]) {
        System.out.println("\t\t\t\t\t\t\tNumber found at index " + i);
        found = true;
       }
      }
      if (!found) {
       System.out.println("\t\t\t\t\t\t\tSpecified element doesn't exist");
      }
     } else {
      System.out.println("\t\t\t\t\t\t\tEnter number to search");
      int z = in .nextInt();
      boolean found = false;

      int mid = 0, result, start = 0, end = arr.length - 1;
      while (start <= end) {
       mid = (start + end) / 2;
       if (arr[mid] == z) {
        System.out.println("\t\t\t\t\t\t\tNumber found at index " + mid);
        found = true;
        break;
       } else if (arr[mid] > z) {
        end = mid - 1;

       } else {
        start = mid + 1;

       }
      }
      if (!found) {
       System.out.println("\t\t\t\t\t\t\tSpecified element doesn't exist");
      }

     }
     break;
    case 9:
     quit = true;

     break;
    default:
     System.out.println("\t\t\t\t\t\t\tSelect options from 1-9");
   }

  } while (!quit);

 }
 static void stop(int i) {
  try {
   Thread.sleep(i);
  } catch (Exception e) {

  }
 }


}
