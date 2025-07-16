import java.util.Scanner;
import java.util.InputMismatchException;

class fibonacci_sequence
{
	public static void main(String[] args) 
	{
		{Scanner sc = new Scanner(System.in);
			
			int number;

			try
			{
				System.out.print("|Enter a number: ");
				number = sc.nextInt();

				int num = 1, result = 0, temp = 1;

				for(int i = 0; i < number; i++)
				{
            		System.out.printf("%d\n", result);
            		num = temp;
            		temp = result;
            		result = temp + num;
				}

			}
			catch(InputMismatchException e)
			{
				System.out.println("\n\n> Enter a valid number");
			}

			sc.close();
		}
		
	}
}