import java.util.Scanner;
import java.text.DecimalFormat;
import java.lang.Math;
import java.io.IOException;

public class IMC
{
	public static void menu()
	{
		System.out.println("\t----'Cálculo de IMC'----\n");
	}
	public static void limpar()
	{
		 if (System.getProperty("os.name").toLowerCase().contains("win")) 
		 {
                try 
                {
                    new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
                } 
                catch (IOException | InterruptedException e) 
                {
                    System.out.println("Não foi possível limpar a tela.");
                    e.printStackTrace();
                }
           }
             else 
             {
                System.out.println("Limpeza de tela disponível apenas no Windows.");
             }
	}
	public static void main(String args[])
	{
		{Scanner sc = new Scanner(System.in);

			DecimalFormat deci = new DecimalFormat("0.00");

			String obesidade[] = {"0", "I", "II", "III"};
			float peso, altura;
			double imc;
			int indice;

			menu();

			System.out.print("|Digite seu peso(Kg): ");
			peso = sc.nextFloat();

			System.out.print("\n|Digite sua altura(m): ");
			altura = sc.nextFloat();

				imc = peso / Math.pow(altura, 2);

				limpar();
				menu();

				System.out.println("> O IMC pertencente a esses dados é de: " + deci.format(imc));

				if(imc < 18.5)
				{
					System.out.println("> A classificação do paciente é: MAGREZA");
					indice = 0;
				}
				else if(imc >= 18.5 && imc <= 24.9)
				{
					System.out.println("> A classificação do paciente é: NORMAL");
					indice = 0;
				}
				else if(imc >= 25 && imc <= 29.9)
				{
					System.out.println("> A classificação do paciente é: SOBREPESO");
					indice = 1;
				}
				else if(imc >= 30 && imc <= 39.9)
				{
					System.out.println("> A classificação do paciente é: OBESIDADE");
					indice = 2;
				}
				else
				{
					System.out.println("> A classificação do paciente é: OBESIDADE GRAVE");
					indice = 3;
				}

					System.out.println("> O grau de obesidade do paciente é de " + obesidade[indice]);
		}
	}
}