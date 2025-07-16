import java.util.Scanner;
import java.io.IOException;

public class cifra
{

	public static void menu()
	{
		System.out.println("\t-------'Cifra de César'-------\n");
	}

	public static void limpar()
	{
		try 
		{
           new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } 
        catch(IOException | InterruptedException e) 
        {
            e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		{Scanner sc = new Scanner(System.in);

			String palavra;
			int deslocamento, tamanho;

			menu();

			System.out.print("|Digite o deslocamento da cifra: ");
			deslocamento = sc.nextInt();
			sc.nextLine();

			limpar();
			
			menu();

			System.out.print("|Digite a palavra a ser codificada: ");
			palavra = sc.nextLine();

			tamanho = palavra.length();
			char[] caracteres = palavra.toCharArray();
			
				for(int i = 0; i < tamanho; i++)
				{
					if(caracteres[i] != ' ' && caracteres[i] != ',' && caracteres[i] != '.' && caracteres[i] != '?' && caracteres[i] != '!')
					{
						caracteres[i] += deslocamento;
					}
				}

			limpar();

			menu();

			String cifra = new String(caracteres);
			System.out.println("|A palavra codificada é: " + cifra);
		}
	}
}