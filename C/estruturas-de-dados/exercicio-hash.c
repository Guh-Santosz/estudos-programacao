#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct pilha
{
	int classe;
	struct pilha *back;
	struct no *next;
}pilha;

typedef struct no
{
	char nome[20];
	struct no *next;
}no;

struct pilha *novo, *topo;
struct no *corrente, *auxiliar;

int countClasse;

void criarArmas(no *auxiliar, char armas[])
{
	corrente = (no*)malloc(sizeof(no));

	strcpy(corrente->nome, armas);
	corrente->next = NULL;
	auxiliar->next = corrente;
}

void percorrerArmas(char armas[], no *corrente)
{
	if(corrente == NULL)
	{
		criarArmas(auxiliar, armas);
		return;
	}
	else
	{
		if(strcmp(armas, corrente->nome) == 0)
		{
			printf("\n> A arma %s ja foi cadastrada\n\n", corrente->nome);
			system("pause");
			system("cls");

			return;
		}
		else
		{
			auxiliar = corrente;
			corrente = corrente->next;
			percorrerArmas(armas, corrente);
		}
	}
}

void criarClasse(int hash, int contador, char armas[])
{
	novo = (pilha*)malloc(sizeof(pilha));
	corrente = (no*)malloc(sizeof(no));

	if(contador == 1)
	{
		strcpy(corrente->nome, armas);
		corrente->next = NULL;
		auxiliar = corrente;

		novo->classe = hash;
		novo->back = NULL;
		novo->next = corrente;
	}
	else
	{
		strcpy(corrente->nome, armas);
		corrente->next = NULL;
		auxiliar = corrente;

		novo->classe = hash;
		novo->back = topo;
		novo->next = corrente;
	}

	topo = novo;
}

void percorrerClasses(int hash, char armas[], pilha *novo)
{
	if(novo == NULL)
	{
		countClasse++;
		criarClasse(hash, countClasse, armas);
		return;
	}
	else
	{
		if(novo->classe == hash)
		{
			corrente = novo->next;
			percorrerArmas(armas, corrente);
			return;
		}
		else
		{
			percorrerClasses(hash, armas, novo->back);
		}
	}
}

void inserir()
{
	char armas[20];
	int soma = 0, hash;

	printf("\t----'Inserir armas'----\n\n");
	printf("|Digite o nome da arma: ");
	fgets(armas, 20, stdin);
	fflush(stdin);

	armas[strcspn(armas, "\n")] = '\0';

	int tamanho = strlen(armas);

	for(int i = 0; i < tamanho; i++)
	{
		armas[i] = toupper(armas[i]);
		soma += (armas[i]);
	}

	hash = (soma % 5) + 1;

	percorrerClasses(hash, armas, topo);
}

void exibirArmas(no *corrente)
{
	if(corrente != NULL)
	{
		printf(" < %s > ", corrente->nome);
	}
	else return;

	corrente = corrente->next;
	exibirArmas(corrente);
}

void exibir(pilha *top)
{
	struct pilha *percorrer;

	percorrer = top;

	if(percorrer != NULL)
	{
		printf("\n|Classe %d:", percorrer->classe);

		corrente = percorrer->next;
		exibirArmas(corrente);
	}
	else return;

	percorrer = percorrer->back;
	exibir(percorrer);
}

int main()
{
 	int opercao;
 	novo = NULL;
 	topo = NULL;
 	countClasse = 0;

    do
    {
        printf("\t----'Menu de escolhas'----\n\n");
        printf("[1] - Inserir arma\n");
        printf("[2] - Exibir dados\n");
        printf("[3] - Encerrar Sistema\n");
        printf("\n|: ");
        scanf("%d", &opercao);
        fflush(stdin);

        system("cls");

        switch(opercao)
        {
            case 1:

                inserir();
                system("cls");

                break;

            case 2:

            	printf("\t----'Exibir armas'----\n");
                exibir(topo);

                printf("\n\n");
                system("pause");
                system("cls");

                break;

            case 3:

                printf("\t----'Menu de escolhas'----\n\n");
                printf("> Programa encerrado!\n\n");

                system("pause");
                system("cls");
                return 0;

                break;

            default:

                printf("\t----'Menu de escolhas'----\n\n");
                printf("> Digite um numero valido!\n\n");

                system("pause");
                system("cls");
                return 0;
        }

    }while(opercao != 4);
}