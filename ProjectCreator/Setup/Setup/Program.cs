using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Setup
{
    class Program
    {
        static void Main(string[] args)
        {
            Environment.SetEnvironmentVariable("CotEngine", string.Format("{0}\\", Directory.GetCurrentDirectory()), EnvironmentVariableTarget.User);
        }
    }
}
