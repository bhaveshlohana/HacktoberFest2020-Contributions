using System;
using System.IO;

namespace CharCount
{
    class Program
    {
        static void Main()
        {
            // https://stackoverflow.com/a/6081967
            // Allow Console.ReadLine to read more than 254 characters
            Console.SetIn(new StreamReader(Console.OpenStandardInput(500000), Console.InputEncoding, false, 500000));
            Console.WriteLine("Please paste the input string:");

            var input = Console.ReadLine();

            if (input != null)
            {
                var charCount = input.Length;
                Console.WriteLine("That's " + charCount + " characters.");
            }

            Console.ReadLine();
        }
    }
}