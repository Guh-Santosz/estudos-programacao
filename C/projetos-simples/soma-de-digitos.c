#include<stdio.h>
#include<string.h>

int soma(char numero[], int tamanho, int resultado)
{	
	if(tamanho >= 0)
	{
		int digito = numero[tamanho] - '0';
		resultado += digito;
		tamanho -= 1;
		return soma(numero, tamanho, resultado);
	}
	else
	{
		return resultado;
	}
}

int main()
{
	char numero[20];
	int resultado = 0;

	printf("|Digite um numero: ");
	fgets(numero, 20, stdin);
	fflush(stdin);

	numero[strcspn(numero, "\n")] = '\0';
	
	int tamanho = strlen(numero) - 1;
	resultado = soma(numero, tamanho, resultado);

	printf("\n> Resultado: %d", resultado);
}