import java.util.Scanner;

public class jogo_advinhe
{
	public static void main(String[] args) 
	{
	    {Scanner sc = new Scanner(System.in);
	    
		    int palpite = 0, num = 12, pontos = 100, tentativa = 0;
		
		   System.out.println("   ---- Jogo do Advinho ----\n");
		   System.out.println("* Advinhe um número de 0 a 100:\n");
		   
		        while(palpite != num)
		        {
		            System.out.print("  |Digite seu palpite: ");
		            
		            palpite = sc.nextInt();
		            
		                if(palpite > num)
		                {
		                    System.out.println("\n    -> O número é menor\n");
		                }
		                else if(palpite < num)
		                {
		                    System.out.println("\n    -> O número é maior\n");
		                }
		                
		                tentativa++;
		                
		                    if(tentativa > 1)
		                    {
		                        pontos -= 10;
		                    }
		            
		        }
		        
		            System.out.println("\n:: Parabéns você encontrou o número secreto! ::\n");
		            System.out.println("Você conseguiu em " + tentativa + " tentativas");
		            System.out.println("Você conquistou " + pontos + " pontos");
		        
	    }
	}
}