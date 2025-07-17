using System;
using System.IO;

class Usuario
{
    public int id;
    public string nome;
    public int idade;

    public Usuario(int userId, String name, int age)
    {
        this.id = userId;
        this.nome = name;
        this.idade = age;
    }
}
class Program
{
    public static void Editar()
    {
        List<Usuario> Pessoas = CarregarUsuarios();

        Console.WriteLine("\t----'MENU DE ESCOLHAS'----\n");

        Console.Write("|Digite o ID do usuário a ser alterado: ");
        int id = Convert.ToInt32(Console.ReadLine());

        var user = Pessoas.FirstOrDefault(user => user.id == id);

        Console.Clear();

        Console.WriteLine("\t----'MENU DE ESCOLHAS'----\n");

        if (user != null)
        {
            Console.Write("|Digite o novo nome: ");
            user.nome = Console.ReadLine();

            Console.Write("\n\n|Digite o nova idade: ");
            user.idade = Convert.ToInt32(Console.ReadLine());

            SalvarUsuarios(Pessoas);
        }
        else
        {
            Console.WriteLine("> Usuário não encontrado");

        }

        Console.WriteLine("Pressione qualquer tecla para continuar");
        Console.ReadKey();
        Console.Clear();

    }
    public static void Excluir()
    {
        List<Usuario> Pessoa = CarregarUsuarios();

        Console.WriteLine("\t----'EXCLUINDO USUÁRIOS'----\n");

        Console.Write("|Digite o ID do usuário a ser excluído: ");
        int id = Convert.ToInt32(Console.ReadLine());

        var user = Pessoa.RemoveAll(user => user.id == id);

        Console.Clear();

        Console.WriteLine("\t----'EXCLUINDO USUÁRIOS'----\n");

        if (user > 0)
        {
            SalvarUsuarios(Pessoa);
            Console.WriteLine("> Usuário removido com sucesso");
        }
        else
        {
            Console.WriteLine("> Usuário não encontrado");
        }

        Console.WriteLine("Pressione qualquer tecla para continuar");
        Console.ReadKey();
        Console.Clear();

    }
    public static void Exibir()
    {
        Console.WriteLine("\t----'EXIBINDO USUÁRIOS'----\n");
        
        if (!File.Exists("Usuarios.bin") || new FileInfo("Usuarios.bin").Length == 0)
        {
            Console.WriteLine("> Não há usuários cadastrados\n");
        }
        else
        {
            using (BinaryReader read = new BinaryReader(File.Open("Usuarios.bin", FileMode.Open)))
            {
                while (read.BaseStream.Position < read.BaseStream.Length)
                {
                    int id = read.ReadInt32();

                    char[] nomeChar = read.ReadChars(50);
                    string nome = new string(nomeChar).Trim();

                    int idade = read.ReadInt32();

                    Console.WriteLine($"|ID| {id}\n|NOME| {nome}\n|IDADE| {idade}\n");
                }
            }
        }
        
        Console.WriteLine("\nPressione qualquer tecla para continuar...");
        Console.ReadKey();
        Console.Clear();
    }
    public static void Cadastrar()
    {
        Console.WriteLine("\t----'CADASTRO DE USUÁRIOS'----\n");
        Console.Write("|Digite quantos usuários serão cadastrados: ");
        int quantidade = Convert.ToInt32(Console.ReadLine());

        for(int i = 1; i <= quantidade; i++)
        {
            Console.Clear();

            Console.WriteLine("\t----'CADASTRO DE USUÁRIOS'----\n");

            Console.Write($"|Digite o ID do usuário {i}: ");
            int id = Convert.ToInt32(Console.ReadLine());

            Console.Write($"\n|Digite o nome do usuário {i}: ");
            string nome = Console.ReadLine();

            Console.Write($"\n|Digite a idade do usuário {i}: ");
            int idade = Convert.ToInt32(Console.ReadLine());

            using(BinaryWriter write = new BinaryWriter(File.Open("Usuarios.bin", FileMode.Append)))
            {
                Usuario NovoUser = new Usuario(id, nome, idade);

                write.Write(NovoUser.id);
                write.Write(NovoUser.nome.PadRight(50).ToCharArray());
                write.Write(NovoUser.idade);
            }
        }
    
        Console.Clear();
        Console.WriteLine("\t----'CADASATRO DE USUÁRIOS'----\n");
        Console.WriteLine("> Usuários cadastrados com sucesso");
        Console.WriteLine("\nPressione qualquer tecla para continuar...");
        Console.ReadKey();
        Console.Clear();
    }

    public static List<Usuario> CarregarUsuarios()
    {
        List<Usuario> user = new List<Usuario>();

        if (File.Exists("Usuarios.bin"))
        {
            using (BinaryReader read = new BinaryReader(File.Open("Usuarios.bin", FileMode.Open)))
            {
                while (read.BaseStream.Position < read.BaseStream.Length)
                {
                    int id = read.ReadInt32();
                    char[] nomes = read.ReadChars(50);
                    string Nome = new string(nomes).Trim();
                    int idade = read.ReadInt32();

                    user.Add(new Usuario(id, Nome, idade));
                }
            }
        }
        return user;
    }

    public static void SalvarUsuarios(List<Usuario> usuarios)
    {
        using (BinaryWriter write = new BinaryWriter(File.Open("Usuarios.bin", FileMode.Create)))
        {
            foreach (var u in usuarios)
            {
                write.Write(u.id);
                write.Write(u.nome.PadRight(50).ToCharArray());
                write.Write(u.idade);
            }
        }
    }
    public static void Main(string[] args)
    {
        int operacao;

        do
        {
            Console.Clear();
            Console.WriteLine("\t----'MENU DE ESCOLHAS'----\n");
            Console.WriteLine("[1] - Cadastro de usuários");
            Console.WriteLine("[2] - Exibir usuários");
            Console.WriteLine("[3] - Editar usuários");
            Console.WriteLine("[4] - Excluir usuários");
            Console.WriteLine("[5] - Sair\n");

            Console.Write("|: ");
            operacao = Convert.ToInt32(Console.ReadLine());

            Console.Clear();

            switch (operacao)
            {
                case 1:

                    Cadastrar();
                    break;

                case 2:

                    Exibir();
                    break;

                case 3:

                    Editar();
                    break;

                case 4:

                    Excluir();
                    break;

                case 5:

                    Console.Write("> Programa encerrado");
                    break;

                default:

                    Console.Write("> Digite um numero valido!");
                    break;
            }

        } while (operacao != 5);
    }
}