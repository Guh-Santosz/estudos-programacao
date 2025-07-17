using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace ThreadedProcessing
{
    class Program
    {
        static long ProcessRange(int start, int end)
        {
            long sum = 0;

            for (int i = start; i < end; i++) 
            {
                if (IsPrime(i)) sum += i;
            }

            return sum;
        }
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
            Console.WriteLine("> Iniciando threads...\n");

            const int count = 50000000;

            int threadCount = Environment.ProcessorCount;
            Console.WriteLine($"|Utilizado {threadCount} threads\n");

            var stopwatch = Stopwatch.StartNew();

            int rangePerThread = count / threadCount;
            Task<long>[] tasks = new Task<long>[threadCount];

            for (int i = 0; i < threadCount; i++) 
            { 
                int startRange = i * rangePerThread + 2;
                int endRange = (i == threadCount - 1) ? count : (i + 1) * rangePerThread;

                tasks[i] = Task.Run(() => ProcessRange(startRange, endRange));
            }

            Task.WaitAll(tasks);
            long totalSum = 0;

            foreach (var task in tasks) 
            {
                totalSum += task.Result;
            }

            stopwatch.Stop();
            Console.WriteLine($"|Soma dos números primos: {totalSum}\n");
            Console.WriteLine($"|Tempo de processamento com threads {stopwatch.ElapsedMilliseconds} ms\n");
            Console.WriteLine("> Pressione qualquer tecla para continuar...");
            Console.ReadKey();
        }
    }
}
