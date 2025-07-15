#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct no
{
    int ra;
    char nome[20];
    int idade;
    struct no *next;
}no;

struct no *inicio, *auxiliar, *corrente;

void remover()
{
    char mander[20];
    bool achou = false;

    printf("\t----'Remover registro de aluno'----\n\n");

    if(inicio == NULL)
    {
        printf("> Cadastre um aluno primeiro\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("> Digite o nome do aluno a ser deletado: ");
        fgets(mander, 20, stdin);

        mander[strcspn(mander, "\n")] = '\0';

        for(int i = 0; i < strlen(mander); i++)
        {
            mander[i] = toupper(mander[i]);
        }

        if(strcmp(inicio->nome, mander) == 0)
        {
            inicio = inicio->next;
            free(corrente);
            achou = true;
        }
        else
        {
            corrente = inicio;

            while(corrente != NULL)
            {

                if(strcmp(corrente->nome, mander) == 0)
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

        if(achou)
        {
            printf("\n> Aluno removido com sucesso\n\n");
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
void cadastro()
{
    int quantidade;

    fflush(stdin);

    printf("\t----'Cadastro de aluno'----\n\n");
    printf("> Digite quantos alunos serao cadastrados: ");
    scanf("%d", &quantidade);
    fflush(stdin);


    system("cls");

        for(int i = 0; i < quantidade; i++)
        {
            if(inicio == NULL)
            {
                corrente = (no*)malloc(sizeof(no));

                printf("\t----'Cadastro de aluno'----\n\n");
                printf("|Digite o nome do(a) aluno(a) %d: ", i + 1);
                fgets(corrente->nome, 20, stdin);
                fflush(stdin);


                corrente->nome[strcspn(corrente->nome, "\n")] = '\0';

                for(int k = 0; k < strlen(corrente->nome); k++)
                {
                    corrente->nome[k] = toupper(corrente->nome[k]);
                }

                printf("\n|Digite o RA do(a) aluno(a) %s: ", corrente->nome);
                scanf("%d", &corrente->ra);
                fflush(stdin);


                printf("\n|Digite a idade do(a) aluno(a) %s: ", corrente->nome);
                scanf("%d", &corrente->idade);
                fflush(stdin);


                corrente->next = NULL;
                inicio = corrente;
                auxiliar = corrente;

                printf("\n");
                system("pause");
                system("cls");
            }
            else
            {
                corrente = (no*)malloc(sizeof(no));

                printf("\t----'Cadastro de aluno'----\n\n");
                printf("|Digite o nome do(a) aluno(a) %d: ", i + 1);
                fgets(corrente->nome, 20, stdin);
                fflush(stdin);

                corrente->nome[strcspn(corrente->nome, "\n")] = '\0';

                for(int k = 0; k < strlen(corrente->nome); k++)
                {
                    corrente->nome[k] = toupper(corrente->nome[k]);
                }

                printf("\n|Digite o RA do(a) aluno(a) %s: ", corrente->nome);
                scanf("%d", &corrente->ra);
                fflush(stdin);


                printf("\n|Digite a idade do(a) aluno(a) %s: ", corrente->nome);
                scanf("%d", &corrente->idade);
                fflush(stdin);


                auxiliar->next = corrente;
                auxiliar = corrente;
                corrente->next = NULL;

                system("cls");

            }

        }

        printf("\t----'Cadastro de aluno'----\n\n");
        printf("> Cadastro realizado com sucesso!\n\n");
        system("pause");
        system("cls");
}

void exibir()
{
    if(inicio == NULL)
    {
        printf("\t----'Exibindo alunos'----\n\n");
        printf("> Nao ha alunos cadastrados ainda...\n\n");

        system("pause");
        system("cls");
    }
    else
    {
        corrente = inicio;

        printf("\t----'Exibir alunos'----\n\n");

        while(corrente != NULL)
        {
            printf("|RA|: %d", corrente->ra);
            printf("\n|NOME|: %s", corrente->nome);
            printf("\n|IDADE|: %d", corrente->idade);
            printf("\n\n");

            corrente = corrente->next;
        }

        system("pause");
        system("cls");
    }
}

void pesquisar()
{
    if(inicio == NULL)
    {
        printf("\t----'Pesquisa de alunos'----\n\n");
        printf("> Nao ha alunos cadastrados ainda...\n\n");

        system("pause");
        system("cls");
    }
    else
    {
        char nome[20];
        bool receba = false;

        corrente = inicio;

        printf("\t----'Pesquisa de alunos'----\n\n");
        printf("> Digite o nome do aluno a ser pesquisado: ");
        fgets(nome, 20, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        for(int i = 0; i < strlen(nome); i++)
        {
            nome[i] = toupper(nome[i]);
        }
        fflush(stdin);

        system("cls");

        while(corrente != NULL)
        {
            if(strcmp(nome, corrente->nome) == 0)
            {
                receba = true;
                printf("\t----'Pesquisa de alunos'----\n\n");
                printf("> Informacoes do(a) aluno(a) encontrado(a):\n\n");

                printf("|RA|: %d", corrente->ra);
                printf("\n|NOME|: %s|", corrente->nome);
                printf("\n|IDADE:| %d|", corrente->idade);
                printf("\n\n");

                system("pause");
                system("cls");
                receba = true;
                break;
            }

            corrente = corrente->next;
        }

        if(!receba)
        {
            printf("\t----'Pesquisa de alunos'----\n\n");
            printf("> Aluno nao encontrado\n\n");
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

    do
    {
        printf("\t----'Sistema de aluno'----\n\n");
        printf("[1] - Cadastro de alunos\n");
        printf("[2] - Exibir alunos\n");
        printf("[3] - Pesquisar alunos\n");
        printf("[4] - Remover registro\n");
        printf("[5] - Emcerrar Sistema\n");
        printf("\n|: ");
        scanf("%d", &opercao);
        fflush(stdin);

        system("cls");

        switch(opercao)
        {
            case 1:

                cadastro();

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

                printf("\t----'Sistema de aluno'----\n\n");
                printf("> Programa encerrado!\n\n");
                system("pause");
                system("cls");

                return 0;
                break;

            default:

                printf("\t----'Sistema de aluno'----\n\n");
                printf("> Digite um numero valido!\n\n");

                system("pause");
                system("cls");

                break;
        }

    }while(opercao != 5);
}
