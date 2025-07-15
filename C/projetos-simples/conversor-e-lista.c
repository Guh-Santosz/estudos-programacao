#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct no
{
   int bit;
   struct no *next, *back; 
}no;

struct no *new, *end;
int displayNumber;
bool validation;

void Insert()
{
    int number;
    validation = true;

    printf("\t----'Inserir'----\n\n");

    printf("|Digite um numero decimal: ");
    scanf("%d", &number);
    fflush(stdin);

    displayNumber = number;

    while(number != 1)
    {
        new = (no*)malloc(sizeof(no));
        new->bit = number % 2;

        if(end == NULL)
        {
            end = new;
            end->next = NULL;
            end->back = NULL;
        }
        else
        {
           new->back = end;
           new->next = NULL;
           end->next = new;
           end = new;
        }

        number /= 2;
    }

    new = (no*)malloc(sizeof(no));
    new->bit = 1;
    new->back = end;
    end->next = new;
    new->next = NULL;
    end = new;

    system("cls");
    printf("\t----'Inserir'----\n\n");

    printf("> Numero convertido com sucesso!\n\n");
    system("pause");
    system("cls");
}

void Show()
{
    printf("\t----'Exibir'----\n\n");

    if(!validation)
    {
        printf("> Insira um numero antes de exibir\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        new = end;

        printf("|O numero %d em binario eh: ", displayNumber);

        while(new != NULL)
        {
            printf("%d", new->bit);

            new = new->back;
        }

        end = NULL;

        printf("\n\n");
        system("pause");
        system("cls");
    }
}

int main()
{
    int choose;
    validation = false;
    new = NULL;
    end = NULL;

    do
    {
        printf("\t----'Menu de escolhas'----\n\n");
        printf("[1] - Inserir numero decimal\n");
        printf("[2] - Exibir numero binario\n");
        printf("[3] - Sair\n\n");

        printf("|: ");
        scanf("%d", &choose);
        fflush(stdin);

        system("cls");

        switch(choose) 
        {
            case 1:

                Insert();
                break;

            case 2:

                Show();
                break;

            case 3:

                system("cls");
                printf("\t----'Menu de escolhas'----\n\n");
                printf("> Programa encerrado\n\n");

                system("pause");
                system("taskkill /pid cmd.exe");

                break;

            default:

                system("cls");
                printf("\t----'Menu de escolhas'----\n\n");
                printf("> Digite um numero valido\n\n");

                system("pause");
                system("cls");
        }

    }while(choose != 3);
}
