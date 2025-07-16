package pkg11.pkg05;

import java.util.Scanner;

public class Main 
{

    public static void main(String[] args) 
    {
          double vet[][] = new double[10][20];
          int soma = 0;
          int val = 0;
          int numero = 30;
          
            for(int i = 0; i < 10 ; i++)
            {
                
                for(int d = 0; d < 20; d++)
                {
                     vet[i][d] = Math.rint(Math.random()*200);
                     
                     if(vet[i][d] == numero)
                     {
                         System.out.println("O valor está na posição: " + i + ", " + d);
                         val = 1;
                         soma++;
                     } 
                }
             
            }
            
                if(val != 1)
                {
                    System.out.println("Valor não encontrado");
                    
                }
                else
                {
                    System.out.println("\nO valor foi encontrado " + soma + " vez(es)" );
                }

    }
    
}
