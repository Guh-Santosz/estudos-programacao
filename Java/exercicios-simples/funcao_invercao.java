import java.util.Scanner;

public class funcao_invercao
{
    public static void inverte(int tamanho, int[] inverso)
    {
        System.out.print("\nO inverso dos números é: ");
        
        for(int i = tamanho - 1; i >= 0; i--)
        {
            System.out.print(inverso[i]);
        }
        
    }
    
	public static void main(String[] args) 
	{
	    {Scanner sc = new Scanner(System.in);
	        
	        int limite;
	        
	        System.out.print(" --> Digite o a quantidade de números que irá digitar: ");
	        
	        limite = sc.nextInt();
	        
	       int numero[];
	       numero = new int[limite];
	       
	       System.out.println("");
	       
	            for(int i = 0; i <= (limite - 1); i++)
	            {
	                System.out.print(" |Digite um número: ");
	                
	                numero[i] = sc.nextInt();
	            }
	            
	            inverte(limite, numero);
	        
	    }
	    
	}
}