import java.util.Scanner;
import java.util.Random;

public class pedra_papel_tesoura
{
    public static void jogo(int b, int c)
    {
        if(b == 1 || b == 2 || b == 3)
	    {
	           if(b == 1)
	           {
	               System.out.print("\nVocê escolheu PEDRA!");
	                    
	               if(c == 0)
	               {
	                   System.out.print("\nA máquina escolheu PEDRA também!");
	                   System.out.print("\n\nResultado: EMPATE!");
	               }
	               else if(c == 1)
	               {
	                   System.out.print("\nA máquina escolheu PAPEL!");
	                   System.out.print("\n\nResultado: VOCÊ PERDEU!");
	               }
	               else
	               {
	                   System.out.print("\nA máquina escolheu TESOURA!");
	                   System.out.print("\n\nResultado: VOCÊ GANHOU!");
	               }
	                    
	                }
	                else if(b == 2)
	                {   
	                    System.out.print("\nVocê escolheu PAPEL!");
	                    
	                    if(c == 0)
	                    {
	                        System.out.print("\nA máquina escolheu PEDRA!");
	                        System.out.print("\n\nResultado: VOCÊ GANHOU!");
	                    }
	                    else if(c == 1)
	                    {
	                        System.out.print("\nA máquina escolheu PAPEL também!");
	                        System.out.print("\n\nResultado: EMPATE!");
	                    }
	                    else
	                    {
	                        System.out.print("\nA máquina escolheu TESOURA!");
	                        System.out.print("\n\nResultado: VOCÊ PERDEU!");
	                    }
	                }
	                else
	                {
	                    System.out.print("\nVocê escolheu TESOURA!");
	                    
	                    if(c == 0)
	                    {
	                        System.out.print("\nA máquina escolheu PEDRA!");
	                        System.out.print("\n\nResultado: VOCÊ PERDEU!");
	                    }
	                    else if(c == 1)
	                    {
	                        System.out.print("\nA máquina escolheu PAPEL!");
	                        System.out.print("\n\nResultado: VOCÊ GANHOU!");
	                    }
	                    else
	                    {
	                        System.out.print("\nA máquina escolheu TESOURA!");
	                        System.out.print("\n\nResultado: EMPATE!");
	                    }
	                }
	            }
    }

    public static int continuar()
    {
        {Scanner op = new Scanner(System.in);
            
            int valor;
            
            System.out.print("\n\n    Deseja continuar?");
            System.out.print("\n     1 - SIM");
            System.out.println("\n     2 - NÃO");
            
            System.out.print("\nEscolha aqui: ");
            valor = op.nextInt();

            return valor;
        }
    }

    public static int menu()
    {
        {Scanner la = new Scanner(System.in);
    
                    System.out.println("\n1 - Pedra\n2 - Papel\n3 - Tesoura");
	                System.out.print("\nQual número você quer jogar: ");
	                    int a = la.nextInt();
	                   
	                   return a;
        }
    }
    
	public static void main(String[] args) 
	{
	    {Scanner sc = new Scanner(System.in);
	        
	        Random rand = new Random();
	        
	        int percorrer = rand.nextInt(3);
	       
	        int palpite = 0;
	        
	        System.out.println("    ---- 'Pedra, Papel ou Tesoura' ----     ");
	        System.out.println("\nDigite um número com base no que quer jogar: ");
	        
	        palpite = menu();
	        
	            while(palpite != 1 && palpite != 2 && palpite != 3)
	            {
	                System.out.print("\n    -> Digite um número válido!\n");
	                palpite = menu();
	            }
	           
	            jogo(palpite, percorrer);
	            
	            int teste = continuar();

                        while(teste == 1)
                        {
                            percorrer = rand.nextInt(3);
                            
                            palpite = menu();
                            jogo(palpite, percorrer);
                            teste = continuar();
                        }
                
                        while(teste != 1 && teste != 2)
                        {
                            System.out.print("\n    -> Digite um número válido!");
                            teste = continuar();
                            
                                while(teste == 1)
                                {
                                    percorrer = rand.nextInt(3);
                            
                                    palpite = menu();
                                    jogo(palpite, percorrer);
                                    teste = continuar();
                                }
                        }
                        System.out.println("\nOBRIGADO POR JOGAR :)\n\n");
	    }
	}
}