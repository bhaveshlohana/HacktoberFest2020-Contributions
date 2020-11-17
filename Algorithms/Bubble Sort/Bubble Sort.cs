using System;

namespace Bubble_Sort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] sampleArray = { 3, 2, 4, 1, 5 };
            int swapPlaceholder;

            Console.WriteLine("Original Array:");
            foreach (int a in sampleArray)
            Console.Write(a + " ");
            Console.WriteLine("\n");

            for (int j = 0; j <= sampleArray.Length - 2; j++)
            {
                for (int i = 0; i <= sampleArray.Length - 2; i++)
                {
                    if (sampleArray[i] > sampleArray[i + 1])
                    {
                        swapPlaceholder = sampleArray[i + 1];
                        sampleArray[i + 1] = sampleArray[i];
                        sampleArray[i] = swapPlaceholder;
                    }
                }
            }

            
            Console.WriteLine("Sorted Array:");
            foreach (int a in sampleArray)
            Console.Write(a + " ");
            Console.WriteLine("\n");
        }
    }
}
