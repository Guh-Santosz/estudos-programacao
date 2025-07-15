#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pilha
{
	int numero;
	struct pilha *back;
}pilha;

typedef struct fila
{
	int num;
	struct fila *next, *back;
}fila;

struct pilha *novo, *top; 
struct fila *corrente, *auxiliar, *inicio;

void criarPilha(int dado)
{
	novo = (pilha*)malloc(sizeof(pilha));

	novo->numero = dado;

	if(top == NULL)
	{
		top = novo;
		novo->back = NULL;
	}
	else
	{
		novo->back = top;
		top = novo;
	}
}

void exibirPilha()
{
	if(top == NULL)
	{
		printf("\n\t> Pilha vazia\n");
	}
	else
	{
		novo = top;

		printf("\n\t> Dados da pilha: ");

		while(novo != NULL)
		{
			printf("%d ", novo->numero);
			novo = novo->back;
		}
	}
}

void exibirFila()
{
	if(corrente == NULL)
	{
		printf("\n\t> Fila vazia\n");
	}
	else
	{
		corrente = auxiliar;

		printf("\n\t> Dados da fila: ");
		while(corrente != NULL)
		{
			printf("%d ", corrente->num);
			corrente = corrente->back;
		}	
	}
}

void RemoverCriar()
{
	novo = top;

	while(novo != NULL)
	{
		corrente = (fila*)malloc(sizeof(fila));
		corrente->num = novo->numero;

		if(inicio == NULL)
		{
			auxiliar = corrente;
			inicio = corrente;
			corrente->next = NULL;
			corrente->back = NULL;
		}
		else
		{
			auxiliar->next = corrente;
			corrente->back = auxiliar;
			corrente->next = NULL;
			auxiliar = corrente;
		}

		novo = novo->back;
		free(top);
		top = novo;
	}
}

int main()
{
	srand(time(NULL));

	novo = NULL;
	top = NULL;
	corrente = NULL;
	auxiliar = NULL;
	inicio = NULL;

	printf("|Fila antes da insercao:\n");
	exibirFila();

	for(int i = 0; i < 15; i++)
	{
		int aleatorio = (rand() % 100) + 1;
		criarPilha(aleatorio);
	}
	printf("\n|Pilha antes da remocao:\n");
	exibirPilha();

	RemoverCriar();

	printf("\n\n|Fila depois da insercao:\n");
	exibirFila();

	printf("\n\n|Pilha depois da remocao:\n");
	exibirPilha();
}