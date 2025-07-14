#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct no
{
	char nome[20];
	int ra;
	struct no *next;
}no;

struct no *inicio, *corrente, *auxiliar;

void inserir()
{
	corrente = (no*)malloc(sizeof(no));

	printf("|Digite o nome do aluno: ");
	fgets(corrente->nome, 20, stdin);
	fflush(stdin);

	corrente->nome[strcspn(corrente->nome, "\n")] = '\0';
	int tamanho = strlen(corrente->nome);

	for(int i = 0; i < tamanho; i++)
	{
		corrente->nome[i] = toupper(corrente->nome[i]);
	}

	printf("\n\n|Digite o RA do(a) aluno(a) %s: ", corrente->nome);
	scanf("%d", &corrente->ra);

	if(inicio == NULL)
	{
		inicio = corrente;
		auxiliar = corrente;
		corrente->next = NULL;
	}
	else
	{
		corrente->next = NULL;
		auxiliar->next = corrente;
		auxiliar = corrente;
	}

	system("cls");
	printf("> Dados armazenados com sucesso\n\n");
	system("pause");
	system("cls");
}
void exibir()
{
	if(inicio == NULL)
	{
		printf("> Lista vazia\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		corrente = inicio;

		while(corrente != NULL)
		{
			printf("|Nome: %s\n", corrente->nome);
			printf("|RA: %d\n\n", corrente->ra);

			corrente = corrente->next;
		}

		system("pause");
		system("cls");
	}
}
void remover()
{
	char pesquisa[20];
	bool achou = false;

	if(inicio == NULL)
	{
		printf("> Lista vazia\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("|Digite o nome do aluno a ser removido: ");
		fgets(pesquisa, 20, stdin);
		fflush(stdin);

		pesquisa[strcspn(pesquisa, "\n")] = '\0';
		int tamanho = strlen(pesquisa);

		for(int i = 0; i < tamanho; i++)
		{
			pesquisa[i] = toupper(pesquisa[i]);
		}

		corrente = inicio;
		auxiliar = inicio;

		if(strcmp(inicio->nome, pesquisa) == 0)
		{
			achou = true;

			if(inicio->next == NULL)
			{
				free(corrente);
				inicio = NULL;
				corrente = NULL;
				auxiliar = NULL;
			}
			else
			{
				inicio = inicio->next;
				free(corrente);
				corrente = inicio;
			}
		}
		else
		{
			while(corrente != NULL)
			{	
				if(strcmp(corrente->nome, pesquisa) == 0)
				{
					auxiliar->next = corrente->next;
					free(corrente);
					achou = true;
					break;
				}

				auxiliar = corrente;
				corrente = corrente->next;
			}
		}
	}

	system("cls");

	if(achou)
	{
		printf("> Aluno deletado com sucesso\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("> Aluno nao encontrado\n\n");
		system("pause");
		system("cls");
	}
}
void consulta()
{
	char pesquisa[20];
	bool achou = false;

	if(inicio == NULL)
	{
		printf("> Lista vazia\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("|Digite o nome do aluno a ser encontrado: ");
		fgets(pesquisa, 20, stdin);
		fflush(stdin);

		pesquisa[strcspn(pesquisa, "\n")] = '\0';
		int tamanho = strlen(pesquisa);

		for(int i = 0; i < tamanho; i++)
		{
			pesquisa[i] = toupper(pesquisa[i]);
		}

		system("cls");
		corrente = inicio;

		while(corrente != NULL)
		{
			if(strcmp(corrente->nome, pesquisa) == 0)
			{
				printf("> Aluno encontrado:\n\n");
				printf("|Nome: %s\n", corrente->nome);
				printf("|RA: %d\n\n", corrente->ra);
				
				achou = true;
				system("pause");
				system("cls");
				break;
			}
			corrente = corrente->next;
		}
		if(!achou)
		{
			printf("> Aluno nao encontrado\n\n");
			system("pause");
			system("cls");
		}
	}
}
int main()
{
	system("cls");

	int escolha;

	inicio = NULL;
	auxiliar = NULL;
	corrente = NULL;

	do
	{
		printf("[1] - Inserir dados\n");
		printf("[2] - Exibir dados\n");
		printf("[3] - Deletar dados\n");
		printf("[4] - Consultar dados\n");
		printf("[5] - Sair\n\n");
		
		printf("|: ");
		scanf("%d", &escolha);
		fflush(stdin);

		system("cls");

		switch(escolha)
		{
			case 1:

				inserir();
				break;

			case 2:

				exibir();
				break;

			case 3:

				remover();
				break;

			case 4:
				
				consulta();
				break;

			case 5:

				system("cls");
				printf("> Programa encerrado\n\n");
				break;

			default:

				system("cls");
				printf("> Digite um numero valido\n\n");

				system("pause");
				system("cls");
		}
	}
	while(escolha != 5);
}