using System;
using System.Threading;

namespace HelloWorldWithLoader
{
    public class Program
    {
        public static void Main(string[] args)
        {
            ShowProgressLoader(15, 100);

            var inputName = GetUsersName();

            ExitConsoleApp(inputName);
        }

        private static void ShowProgressLoader(int msTimeout, int maxValue)
        {
            for (int i = 0; i <= maxValue; i++)
            {
                var message = i == maxValue ? $"\r{i}% Complete!\n" : $"\rLoading: {i}%";
                Console.Write(message);
                Thread.Sleep(msTimeout);
            }
        }

        private static string GetUsersName()
        {
            Console.WriteLine("\nWhat's your name?");

            var inputName = Console.ReadLine();

            Console.WriteLine($"\nHello {inputName}.");
            return inputName;
        }

        private static void ExitConsoleApp(string usersName)
        {
            for (int i = 3; i >= 0; i--)
            {
                var message = i == 0 ? $"\rGoodbye! {usersName}  " : $"\rExiting in {i}";
                Console.Write(message);
                Thread.Sleep(1000);
            }

            Environment.Exit(0);
        }
    }
}
 