using System;
class Sort
{
  public static void SelectionSort(int[] input)
  {
    for (var i = 0; i < input.Length; i++)
    {
      var min = i;
      for(var j = i + 1; j < input.Length; j++) { 
        if(input[min] > input[j])
        {
          min = j;
        }
      }

      if(min != i)
      {
        var lowerValue = input[min];
        input[min] = input[i];
        input[i] = lowerValue;
      }
    }
  }
}
