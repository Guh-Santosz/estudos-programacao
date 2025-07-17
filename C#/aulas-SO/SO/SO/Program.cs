using System.Diagnostics;

class Program
{
    static void Main()
    {
        Console.WriteLine("\t--- 'Simulação Básica de Sistemas Operacionais' ---");

        while(true) 
        {
            Console.WriteLine("\nEscolha uma opção:\n");

            Console.WriteLine("[1] - Listar processos em execução");
            Console.WriteLine("[2] - Capturar entrada do usuáro e salvar em arquivo");
            Console.WriteLine("[3] - Exibir uso de memória");
            Console.WriteLine("[4] - Sair");

            Console.Write("\n|Digite a opção desejada: ");
            string escolha = Console.ReadLine();

            switch(escolha)
            {
                case "1":

                    ListarProcessos();
                    break;

                case "2":

                    CapturarEntrada();
                    break;

                case "3":

                    ExibirMemoria();
                    break;

                case "4":

                    Console.WriteLine("Encerrando...");
                    return;
                    break;

                default:

                    Console.WriteLine("Opção inválida, tente novamente.");
                    break;
            }
        }
    }

    static void ListarProcessos()
    {
        Console.WriteLine("\n|Processos em execução:\n");

        var processos = Process.GetProcesses().Take(10);

        foreach (var processo in processos)
        {
            Console.WriteLine($"|PID: {processo.Id}| - |Nome: {processo.ProcessName}|");
        }
    }

    static void CapturarEntrada()
    {
        Console.Write("\n|Digite algo para ser salvo no log: ");
        string entrada = Console.ReadLine();
        string caminhoArquivo = "Log.txt";

        File.AppendAllText(caminhoArquivo, $"{DateTime.Now}: {entrada}{Environment.NewLine}");
        Console.WriteLine("> Entrada salva no arquivo Log.txt");
    }

    static void ExibirMemoria()
    {
        var memoria = Process.GetCurrentProcess().PrivateMemorySize64 / 1024 / 1024;
        Console.WriteLine($"\n|Uso de memória do programa: {memoria}MB|");
    }
}