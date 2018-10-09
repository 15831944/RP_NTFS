using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace TestPQCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("entry Floppy");
                args.ToList().ForEach(u => {
                    Console.WriteLine(u);
                });
                if (args.Count() >= 4)
                {
                    Console.WriteLine("FloppyIsRepet" + args[3]);
                    FloppyEx.IsRepet = args[3] != "0";
                }
                new FloppyEx().SendFuction(args[0], int.Parse(args[1]), new DirectoryInfo(args[2]));
            }
            catch (Exception ex)
            {
                Console.WriteLine("&&FloppyTestPQCSharp&&" + ex.Message+ "&&EndFloppyTestPQCSharp&&");
            }
        }
    }
}
