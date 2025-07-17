using System;
using System.Diagnostics;

namespace SeqeuntialProcessing
{
    class Program
    {
        static bool IsPrime(int number)
        {
            if (number <= 1) return false;
            if (number <= 3) return true;
            if (number % 2 == 0 || number % 3 == 0) return false;

            int i = 5;

            while (i * i <= number)
            {
                if (number % i == 0 || number % (i + 2) == 0) return false;
                i += 6;
            }
            return true;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("> Iniciando sequencial...\n");

            const int count = 50000000;

            var stopwatch = Stopwatch.StartNew();

            long sum = 0;

            for (int i = 2; i < count; i++)
            { 
                if(IsPrime(i))
                {
                    sum += i;
                }
            }

            stopwatch.Stop();

            Console.WriteLine($"|A soma dos números primos é: {sum}\n");
            Console.WriteLine($"|Tempo de processamento: {stopwatch.ElapsedMilliseconds} ms\n");
            Console.WriteLine("> Pressione qualquer tecla para sair...");
            Console.ReadKey();

        }
    }
}