using System;

namespace ElectricityBill
{
    class Program
    {
        static void Main(string[] args)
        {
            int unitsConsumed;
            int totalCost;
            int minimumCost = 50;


            Console.WriteLine("Welcome To Electricity Bill Calculating Software");
            Console.ReadLine();

            Console.WriteLine("Enter your consumed units");
            unitsConsumed = Convert.ToInt32(Console.ReadLine());

            if(unitsConsumed <= 50)
            {
                totalCost = minimumCost;
                Console.WriteLine(totalCost);
                Console.ReadLine();
            }
            else if(unitsConsumed <= 100)
            {
                totalCost = (unitsConsumed - 50) * 5 + 50;
                Console.WriteLine(totalCost);
                Console.ReadLine();
            }
            else if (unitsConsumed <= 150)
            {
                totalCost = minimumCost + (minimumCost *  5) + (unitsConsumed - 100) * 7;
                Console.WriteLine(totalCost);
                Console.ReadLine();
            }
            else if (unitsConsumed <= 300)
            {
                totalCost = minimumCost + (minimumCost * 5) + (minimumCost * 7) + (unitsConsumed - 150) * 12;
                Console.WriteLine(totalCost);
                Console.ReadLine();
            }
            else if(unitsConsumed > 300)
            {
                totalCost = minimumCost + (minimumCost * 5) + (minimumCost * 7) + (150 * 12) + (unitsConsumed -300) * 25;
                Console.WriteLine(totalCost);
                Console.ReadLine();
            }


        }
    }
}
