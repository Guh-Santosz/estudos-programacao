#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	int valor;
	struct node *esquerda, *direita, *embaixo;
}node;

struct node *raiz, *root, *auxiliar, *corrente;

void enterdata()
{
    printf("|Digite um numero: ");
    scanf("%d", &corrente->valor);
}

void inserir_esquerda()
{
    auxiliar = raiz;

    while(auxiliar->esquerda != NULL) auxiliar = auxiliar->esquerda;

    auxiliar->esquerda = corrente;
}

void inserir_direita()
{
    auxiliar = raiz;

    while(auxiliar->direita != NULL) auxiliar = auxiliar->direita;

    auxiliar->direita = corrente;
}

void inserir_embaixo()
{
    auxiliar = raiz;

    while(auxiliar->embaixo != NULL) auxiliar = auxiliar->embaixo;

    auxiliar->embaixo = corrente;  
}

void inserir()
{
    corrente = (node*)malloc(sizeof(node));
    corrente->esquerda = NULL;
    corrente->direita = NULL;
    corrente->embaixo = NULL;
    int op;

    enterdata();

    if(raiz == NULL)
    {
        raiz = corrente;
        printf("\n\n> Raiz inserida com sucesso!\n\n");
        system("pause");
    }
    else
    {
        printf("> Digite onde quer inserir a raiz:\n");
        printf("[1] - Esquerda [2] - Direita [3] - Embaixo\n");
        printf("|: ");
        scanf("%d", &op);
    }

    if(op == 1) inserir_esquerda();
    else if(op == 2) inserir_direita();
    else if(op == 3) inserir_embaixo();
    else printf("\n\n> Digite um numero valido!\n\n");
}

void exibir(node *root)
{
    if(raiz == NULL) printf("> Arvore vazia!\n\n");
    else
    {
        printf("|Valor: %d\n", root->valor);

        if(root->esquerda != NULL) exibir(root->esquerda);
        if(root->direita != NULL) exibir(root->direita);
        if(root->embaixo != NULL) exibir(root->embaixo);
    }
}

int main()
{
    root = NULL;
    raiz = NULL; 
    auxiliar = NULL; 
    corrente = NULL;
    int operacao;

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
                inserir();
                system("cls");

                break;

            case 2:

                printf("\t----'Exibindo raiz'----\n\n");
                root = raiz;
                exibir(raiz);
                system("pause");
                system("cls");

                break;

            case 3:

                printf("\t----'Sistema de aluno'----\n\n");
                printf("> Programa encerrado!\n\n");

                break;

            default:

                printf("\t----'Sistema de aluno'----\n\n");
                printf("> Digite um numero valido!\n\n");

                system("pause");
                system("cls");

                break;
        }

    }while(operacao != 3);
}
