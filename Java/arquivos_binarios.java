import java.io.FileInputStream;//Permite a leitura do dado em si
import java.io.FileOutputStream;//Permite a gravação do dado em si
import java.io.DataInputStream;//Permite a leitura dos bytes do dado
import java.io.DataOutputStream;//Permite a gravação dos bytes do dado
import java.io.IOException;//Permite usar try e catch
import java.util.Scanner;//O famoso input brabo

public class arquivos_binarios
{
	public static void escrever(int numero)
	{
		try(DataOutputStream escreva = new DataOutputStream(new FileOutputStream("Teste.bin")))//Isso aqui beira o santanismo
		{
			escreva.writeInt(numero);//É necessário especificar o tipo de dado gravado para evitar B.O(int, float, etc)
		}
		catch(IOException e)
		{
			System.out.print("Não foi possível abrir o arquivo");
		}
	}
	public static void ler()
	{
		try(DataInputStream leia = new DataInputStream(new FileInputStream("Teste.bin")))//Isso aqui beira o santanismo
		{
			int numero_lido = leia.readInt();//É necessário especificar o tipo de dado lido para evitar B.O(int, float, etc)
			System.out.print("O número registrado foi: " + numero_lido);
		}
		catch(IOException e)
		{
			System.out.print("Não foi possível ler o arquivo");
		}
	}
	public static void main(String[] args)
	{
		{Scanner sc = new Scanner(System.in);

			int num;

			System.out.print("|Digite um número para ser registrado em um arquivo: ");
			num = sc.nextInt();

			escrever(num);
			ler();

			sc.close();
		}
	}
}