using System;
using System.Linq;

namespace UnnecessaryComplexHelloWorld
{
    public abstract class Printable { }
    public class H_1 : Printable { }
    public class E_2 : Printable { }
    public class L_3_4_10 : Printable { }
    public class O_5_8 : Printable { }
    public class SPACE_6 : Printable { }
    public class W_7 : Printable { }
    public class R_9 : Printable { }
    public class D_11 : Printable { }

    public class Program
    {
        public static void Main(string[] args)
        {
            string message = string.Join(string.Empty, typeof(Program)
                .Assembly
                .GetTypes()
                .Where(t => t.IsSubclassOf(typeof(Printable)))
                .Select(t => t.Name.Split('_'))
                .Select(b => new {
                    Char = b[0].Length == 1 ? b[0][0] : ' ',
                    Positions = b.Skip(1).Select(s => int.Parse(s)).ToArray()
                })
                .SelectMany(b => b.Positions.Select(p => new { Char = b.Char, Pos = p }))
                .OrderBy(x => x.Pos)
                .Select(x => x.Char));

            Console.WriteLine(message);
            Console.ReadKey();
        }
    }
}