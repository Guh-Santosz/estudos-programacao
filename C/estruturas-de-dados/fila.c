#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int valor;
	struct no *next;
}no;

struct no *auxiliar, *corrente, *primeiro;

void enterdata()
{
	printf("> Digite um numero: ");
	scanf("%d", &corrente->valor);
	system("cls");
}

void inserir()
{
	corrente = (no*)malloc(sizeof(no));

	enterdata();

	if(primeiro == NULL)
	{
		auxiliar = corrente;
		primeiro = corrente;
	}
	else
	{
		auxiliar->next = corrente;
		auxiliar = corrente; 
	}

	corrente->next = NULL;
}

void exibir()
{
	if(primeiro == NULL)
	{
		printf("> Fila vazia\n\n");
	}
	else
	{
		if(primeiro->next != NULL) printf("> Primeiro da fila %d proximo da fila %d\n\n", primeiro->valor, primeiro->next->valor);
		else printf("> Primeiro da fila %d nao ha proximos na fila\n\n", primeiro->valor);
	}
}

void remover()
{
	if(primeiro == NULL)
	{
		printf("> Fila vazia\n\n");
	}
	else
	{
		corrente = primeiro;
		primeiro = primeiro->next;
		free(corrente);
		printf("> O primeiro da fila saiu\n\n");
	}
}

int main()
{	
	corrente = NULL;
	auxiliar = NULL;
	primeiro = NULL;

	int operacao;
	
	do
    {
        printf("\t----'Menu de escolhas'----\n\n");
        printf("[1] - Inserir numero\n");
        printf("[2] - Exibir numero\n");
        printf("[3] - Remover numero\n");
        printf("[4] - Encerrar Sistema\n");
        printf("\n|: ");
        scanf("%d", &operacao);

        system("cls");

        switch(operacao)
        {
            case 1:

                printf("\t----'Inserir na fila'----\n\n");
                inserir();
                printf("> Numero %d inserido com sucesso\n\n", corrente->valor);
                system("pause");
                system("cls");

                break;

            case 2:

                printf("\t----'Exibir fila'----\n\n");
                exibir();
                system("pause");
                system("cls");

                break;

            case 3:

                printf("\t----'Sair primeiro da fila'----\n\n");
                remover();
                system("pause");
                system("cls");                

                break;

            case 4:

            	printf("\t----'Menu de escolhas'----\n\n");
                printf("> Programa encerrado!\n\n");

                break;

            default:

                printf("\t----'Menu de escolhas'----\n\n");
                printf("> Digite um numero valido!\n\n");

                system("pause");
                system("cls");

                break;
        }

    }while(operacao != 4);

	return 0;
}