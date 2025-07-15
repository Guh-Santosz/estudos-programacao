#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct no
{
	int ra;
	char nome[20];
	struct no *next, *back;
}no;

struct no *inicio, *auxiliar, *corrente, *fim;

void enterdata()
{
	printf("|Digite o nome do coleguinha: ");
	fgets(corrente->nome, 20, stdin);
	fflush(stdin);

	corrente->nome[strcspn(corrente->nome, "\n")] = '\0';

	printf("\n|Digite o RA: ");
	scanf("%d", &corrente->ra);
	fflush(stdin);

	system("cls");	
}
void exibir()
{
	printf("\t---'Exibir Dados'---\n\n");

	corrente = inicio;

	printf("> Exibindo normal:\n\n");

	while(corrente != NULL) 
	{
		printf("|Nome: %s\n", corrente->nome);
		printf("|RA: %d\n\n", corrente->ra);

		corrente = corrente->next;
	}

	printf("> Exibindo ao contrario:\n\n");

	corrente = fim;

	while(corrente != NULL) 
	{
		printf("|Nome: %s\n", corrente->nome);
		printf("|RA: %d\n\n", corrente->ra);

		corrente = corrente->back;
	}

	system("pause");
	system("cls");
}
void inserir()
{
	int quantidade;

	printf("\t---'Inserir Dados'---\n\n");

	printf("> Digite quantos alunos serao cadastrados: ");
	scanf("%d", &quantidade);
	fflush(stdin);

	system("cls");

	for(int i = 0; i < quantidade; i++)
	{
		printf("\t---'Inserir Dados'---\n\n");

		corrente = (no*)malloc(sizeof(no));

		enterdata();

		if(inicio == NULL)
		{
			inicio = corrente;
			auxiliar = corrente;
			auxiliar->back = NULL;
			corrente->next = NULL;
			fim = corrente;
		}
		else
		{
			auxiliar->next = corrente;
			corrente->back = auxiliar;
			auxiliar = corrente;
			corrente->next = NULL;
			fim = corrente;
		}
	}
}
void pesquisar()
{
	printf("\t---'Pesquisar Dados'---\n\n");

	int pesquisa;
	bool achou = false;

	printf("|Digite o RA do aluno: ");
	scanf("%d", &pesquisa);
	fflush(stdin);

	corrente = inicio;

	while(corrente != NULL)
	{
		if(corrente->ra == pesquisa)
		{
			printf("\n> Dados da aluno:\n");
			printf("\n|Nome|: %s\n", corrente->nome);
			printf("|RA|: %d\n\n", corrente->ra);

			achou = true;
			system("pause");
			system("cls");
			break;
		}

		corrente = corrente->next;
	}

	if(!achou) 
	{
		printf("\n> Aluno nao encontrado\n\n");
	
		system("pause");
		system("cls");
	}

}
void remover()
{
	printf("\t---'Remover Dados'---\n\n");

	int pesquisa;
	bool achou = false;

	fflush(stdin);
	printf("|Digite o RA do aluno a ser deletado: ");
	scanf("%d", &pesquisa);
	fflush(stdin);

	corrente = inicio;

	if(inicio == NULL)
	{
		printf("\n> Cadastre alunos primeiro\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		if(inicio->ra == pesquisa)
		{
			inicio = inicio->next;
			inicio->back = NULL;
			free(corrente);
			achou = true;
		}
		else
		{
			while(corrente->next != NULL)
			{
				if(corrente->ra == pesquisa)
				{
					corrente = corrente->next;
            		corrente->back = auxiliar;
            		corrente = auxiliar->next;
            		auxiliar->next = corrente->next;
            		free(corrente); 

					achou = true;
				}

				auxiliar = corrente;
				corrente = corrente->next;

				if(corrente->ra == pesquisa && achou == false)
				{
					fim = fim->back;
					fim->next = NULL;
					auxiliar->next = NULL;
					free(corrente);

					achou = true;
				}
			}
		}
		if(achou)
		{
			printf("\n> Aluno encontrado e removido\n\n");
	
			system("pause");
			system("cls");	
		}
		else 
		{
			printf("\n> Aluno nao encontrado\n\n");
	
			system("pause");
			system("cls");
		}
	}
}
int main()
{
	inicio = NULL;
	auxiliar = NULL;
	corrente = NULL;

	int opercao;
	bool receba = true;

	do
	{
		printf("\t---'Menu de Escolhas'---\n\n");
		printf("[1] - Cadastro\n");
		printf("[2] - Exibir\n");
		printf("[3] - Pesquisar\n");
		printf("[4] - Remover\n");
		printf("[5] - Sair\n\n");

		printf("|: ");
		scanf("%d", &opercao);

		system("cls");

		switch(opercao) 
		{
			case 1:

				inserir();
				break;

			case 2:

				exibir();
				break;

			case 3:

				pesquisar();
				break;

			case 4:

				remover();
				break;

			case 5:

				printf("\t---'Menu de Escolhas'---\n\n");
				printf("> Programa encerrado!\n\n");

				return 0;

				break;
		}

	}while(receba);
}