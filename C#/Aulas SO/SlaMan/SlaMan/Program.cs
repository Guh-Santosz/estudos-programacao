using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

class CompararPerformance
{
    static async Task Main()
    {
        int numeroArquivos = 10;

        Console.WriteLine("Sínctono VS Assíncrono\n");
        Console.WriteLine("========================\n");
        Console.WriteLine($"|Proc {numeroArquivos} numeroArquivos...\n");

        Console.WriteLine("> Processo Síncrono\n");
        Stopwatch cronometroSincrono = Stopwatch.StartNew();

        for(int i = 0; i <= numeroArquivos; i++)
        {
            ProcessarArquivoSincrono(i);
        }
        
        cronometroSincrono.Stop();

        Console.WriteLine($"|Sincrono concluido em: {cronometroSincrono.ElapsedMilliseconds} ms\n");

        Console.WriteLine("> Processo Assincrono\n");
        Stopwatch cronometroAssincrono = Stopwatch.StartNew();

        var tarefas = new List<Task>();

        for(int i = 0;i <= numeroArquivos;i++)
        {
            tarefas.Add(ProcessarArquivoAssincrono(i));
        }

        await Task.WhenAll(tarefas);

        cronometroAssincrono.Stop();

        Console.WriteLine($"> Assincrono concluido em: {cronometroAssincrono.ElapsedMilliseconds} ms\n");

        Console.WriteLine("|Resultado Final: ");
        Console.WriteLine($"Sinc: {cronometroSincrono.ElapsedMilliseconds} ms\n");
        Console.WriteLine($"- Sinc: {cronometroSincrono.ElapsedMilliseconds} ms\n");
        Console.WriteLine($"- Assinc: {cronometroAssincrono.ElapsedMilliseconds} ms\n");
        Console.WriteLine($"- Ganho de performance: {Math.Round((double)cronometroSincrono.ElapsedMilliseconds / cronometroAssincrono.ElapsedMilliseconds, 1)} x mais rápido\n");
    }

    static void ProcessarArquivoSincrono(int numeroArquivo)
    {
        Console.WriteLine($"Sinc Arquivo: {numeroArquivo}\n");
        Thread.Sleep(500);

        Console.WriteLine($"> Concluido sinc arquivo {numeroArquivo}\n");
    }

    static async Task ProcessarArquivoAssincrono(int numeroArquivo)
    {
        Console.WriteLine($"Assinc Arquivo: {numeroArquivo}\n");
        await Task.Delay(500);

        Console.WriteLine($"> Concluido assinc arquivo {numeroArquivo}\n");
    }
}


