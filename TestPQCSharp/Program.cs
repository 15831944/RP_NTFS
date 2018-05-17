using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace TestPQCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入路径");
            var i = Console.ReadLine();
            Console.WriteLine("请输入Com值");
            var com = Console.ReadLine();
            Console.WriteLine("请输入Node值");
            var node = int.Parse(Console.ReadLine());
            do
            {
                try
                {
                    DirectoryInfo info = new DirectoryInfo(i);
                    new Floppy().SendFuction(com, node, info);
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex);
                }
            }
            while (!string.IsNullOrEmpty(Console.ReadKey().KeyChar.ToString()));
        }
    }
}
