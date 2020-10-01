using System;
using System.Text;

namespace PwdGenerator
{
	class Program
	{
		//Code to generate a simple 8 character long password
		static string generateSimplePass(int length)
		{
			const string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			StringBuilder res = new StringBuilder();
			Random rnd = new Random();
			while (0 < length--)
			{
				res.Append(validChars[rnd.Next(validChars.Length)]);
			}
			return res.ToString();
		}

		//Code to generate a complex 12 character long password with symbols
		static string generateComplexPass(int length)
		{
			const string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*_-()";
			StringBuilder res = new StringBuilder();
			Random rnd = new Random();
			while (0 < length--)
			{
				res.Append(validChars[rnd.Next(validChars.Length)]);
			}
			return res.ToString();
		}

		static void Main(string[] args)
		{
			//Prompt user to choose type of password and store choice
			Console.WriteLine("Please choose the type of password:");
			Console.WriteLine("1. Simple (8 characters)\n2. Complex (16 characters + symbols\n");
			Console.Write("Type: ");
			int choice = Convert.ToInt32(Console.ReadLine());

			//If user types 1, console is cleared and generateSimplePass is called
			if (choice == 1)
            {
				Console.Clear();
				int length = 8;
				string pass = generateSimplePass(length);
				Console.Write("Generated password: " + pass);
			}
			//If user types 2, console is cleared and generateComplexPass is called
			if (choice == 2)
            {
				Console.Clear();
				int length = 16;
				string pass = generateComplexPass(length);
				Console.Write("Generated password: " + pass);
			}

			
		}
	}
}