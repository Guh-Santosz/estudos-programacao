#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct no
{
	int valor;
	struct no *esquerda, *direita;
}no;

struct no *raiz, *root;

no *criarNo(no *auxiliar, int val)
{
    auxiliar = (no*)malloc(sizeof(no));
    auxiliar->valor = val;
    auxiliar->esquerda = NULL;
    auxiliar->direita = NULL;

    if(raiz == NULL) raiz = auxiliar;

    return auxiliar;
}

no *inserir(no *corrente, int val)
{
    if(corrente == NULL) corrente = criarNo(corrente, val);
    else
    {
        if(corrente->valor > val) corrente->esquerda = inserir(corrente->esquerda, val);
        else if(corrente->valor < val) corrente->direita = inserir(corrente->direita, val);
        else printf("\n> Valor %d ja existe na raiz\n\n", val);
    }

    return corrente;
}

void  exibir(no *perc)
{
    if(perc == NULL) return;
    else
    {
        exibir(perc->esquerda);
        printf("> Valor: %d\n\n", perc->valor);      
        exibir(perc->direita);  
    }
}

int main()
{
	root = NULL;
	raiz = NULL;
	int operacao, valor;

    do
    {
        printf("\t----'Menu de escolhas'----\n\n");
        printf("[1] - Inserir numero\n");
        printf("[2] - Exibir numero\n");
        printf("[3] - Encerrar Sistema\n");
        printf("\n|: ");
        scanf("%d", &operacao);

        system("cls");

        switch(operacao)
        {
            case 1:

            	printf("\t----'Inserir numero'----\n\n");
            	printf("|Digite um numero: ");
            	scanf("%d", &valor);

                root = inserir(root, valor);

                system("pause");
				system("cls");

                break;

            case 2:

            	printf("\t----'Exibindo raiz'----\n\n");
            	
                exibir(raiz);
            	system("pause");
            	system("cls");

                break;

            case 3:

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

    }while(operacao != 3);
}
