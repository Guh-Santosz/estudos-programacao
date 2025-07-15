#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int valor;
	struct no *next;
}no;

struct no *novo, *topo;

void enterdata()
{
	printf("> Digite um numero: ");
	scanf("%d", &novo->valor);
	system("cls");
}

void push()
{
	novo = (no*)malloc(sizeof(no));

	enterdata();

	if(topo == NULL)
	{
		topo = novo;
		novo->next = NULL;
	}
	else
	{
		novo->next = topo;
		topo = novo; 
	}
}

void top()
{
	if(topo == NULL)
	{
		printf("> Pilha vazia\n\n");
	}
	else
	{
		printf("|Top da pilha: %d\n\n", topo->valor);
	}
}

void pop()
{
	if (topo == NULL)
	{
		printf("> Pilha vazia\n\n");
	}
	else
	{
		novo = topo;
		topo = topo->next;
		free(novo);
		printf("> Topo removido com sucesso\n\n");
	}
}

int main()
{
	novo = NULL;
	topo = NULL;
	int operacao;

	do
    {
        printf("\t----'Menu de escolhas'----\n\n");
        printf("[1] - Push\n");
        printf("[2] - top\n");
        printf("[3] - pop\n");
        printf("[4] - Encerrar Sistema\n");
        printf("\n|: ");
        scanf("%d", &operacao);

        system("cls");

        switch(operacao)
        {
            case 1:

                printf("\t----'Inserir na pilha'----\n\n");

               	push();
                system("pause");
                system("cls");

                break;

            case 2:

                printf("\t----'Exibir topo da pilha'----\n\n");
 				
 				top();
                system("pause");
                system("cls");

                break;

            case 3:

                printf("\t----'Pesquisar na raiz'----\n\n");

                pop();
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
}