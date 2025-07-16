import java.util.Scanner;
import java.text.DecimalFormat;

public class funcionarios_e_pontos
{
	public static void main(String[] args) 
	{
	    {Scanner sc = new Scanner(System.in);
	    
	    DecimalFormat deci = new DecimalFormat("0.0");
	        
	        float media[];
	        int funcionarios = 3, dez[], nov[], jan[], maior = 0, soma[];
	        
	        soma = new int[funcionarios];
	        nov = new int[funcionarios];
	        dez = new int [funcionarios];
	        jan = new int[funcionarios];
	        media = new float[funcionarios];
	        
	            for(int i = 0; i < 3; i++)
	            {
	                if(i == 0)
	                {
	                    System.out.println(" -> Pontuações do mês de Novembro: \n");
	                }
	                else if(i == 1)
	                {
	                    System.out.println("\n -> Pontuações do mês de Dezembro: \n");
	                }
	                else
	                {
	                     System.out.println("\n -> Pontuações do mês de Janeiro: \n");
	                }
	                
	                    for(int l = 0; l < funcionarios; l++)
	                    {
	                        if(i == 0)
	                        {
	                            System.out.print("    |Digite a pontuação do funcionário " + (l + 1) + " : ");
	                            nov[l] = sc.nextInt();
	                        }
	                        else if(i == 1)
	                        {
	                            System.out.print("    |Digite a pontuação do funcionário " + (l + 1) + " : ");
	                            dez[l] = sc.nextInt();
	                        }
	                        else
	                        {
	                            System.out.print("    |Digite a pontuação do funcionário " + (l + 1) + " : ");
	                            jan[l] = sc.nextInt();
	                        }
	                        
	                            if(nov[l] > maior)
	                            {
	                                maior = nov[l];
	                            }
	                            if(dez[l] > maior)
	                            {
	                                maior = dez[l];
	                            }
	                            if(jan[l] > maior)
	                            {
	                                maior = jan[l];
	                            }
	                    }
	            }
	            
	            for(int x = 0; x < funcionarios; x++)
	            {
	                soma[x] = nov[x] + dez[x] + jan[x]; 
	                media[x] = soma[x] / 3;
	                
	                System.out.print("\n\n      >> A pontuação geral do funcionário " + (x + 1) + " foi de: " + soma[x]);
	                System.out.print("\n\n      >> A média de pontuação do funcionário " + (x + 1) + " foi de: " + deci.format(media[x]) + "\n");
	            }
	            
	                System.out.print("\n\n  -> A maior pontuação nos três meses foi de: " + maior + " \n\n");
	   }
    }
}