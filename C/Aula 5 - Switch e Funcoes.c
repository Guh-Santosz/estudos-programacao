#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define quantidade 3

char produto[quantidade][20];

void cadastro()
{
    int i;

    for(i = 0; i < quantidade; i++)
    {
        printf("\n |Informe o nome do produto %d: ", i + 1);
        fgets(produto[i], 20, stdin);
        fflush(stdin);
    }

    printf("\n");
    system("pause");
    main();
}

void exibir_produtos()
{
    int i;

    for(i = 0; i < quantidade; i++)
    {
        printf("\n |O produto numero %d eh o: %s", i + 1, produto[i]);
    }

    printf("\n");
    system("pause");
    main();

}


void consulta()
{
    int i = 0;
    char prod[100];
    bool valor = false;

    printf("\n |Digite o nome do produto: ");
    fgets(prod, 100, stdin);
    fflush(stdin);


    for(i = 0; i < quantidade; i++)
    {
        if(strcmp(prod, produto[i]) == 0)
        {
            valor = true;
        }
    }

    if(valor)
    {
        printf("\n |O produto %s tem no estoque", prod);
    }
    else
    {
       printf("\n |O produto %s nao tem no estoque", prod);
    }

    printf("\n");
    system("pause");
    main();

}
void classificacao()
{

    int i, x, l;
    char prod[quantidade][20], temp[20];

        for(i = 0; i < quantidade; i++)
        {
            strcpy(prod[i], produto[i]);
        }

        for(x = 0; x < quantidade; x++)
        {
            if(strcmp(prod[x], prod[x + 1]) > 0)
            {
                strcpy(temp, prod[x + 1]);
                strcpy(prod[x + 1], prod[x]);
                strcpy(prod[x], temp);
            }
        }

            printf("\n > Os produtos em ordem alfabetica sao: \n");

        for(l = 0; l < quantidade; l++)
        {
            printf("\n |%s", prod[l]);
        }
        printf("\n");
        system("pause");
        main();
}

int main()
{
    int op;

        system("cls");

        printf("\n      [1] - Cadastro de produto");
        printf("\n      [2] - Exibir os produtos");
        printf("\n      [3] - Consulta dos produtos");
        printf("\n      [4] - Classificacao dos produtos");
        printf("\n      [5] - Sair do sistema");

            printf("\n\n > Qual a opcao que deseja: ");
            scanf("%d", &op);

            fflush(stdin);

            system("cls");

            switch(op)
            {
                case 1:

                    cadastro();
                    break;

                case 2:

                    exibir_produtos();
                    break;

                case 3:

                    consulta();
                    break;

                case 4:


                    classificacao();
                    break;

                case 5:

                    printf("\n Ate logo : )\n\n\n");
                    return 0;
                    break;
            }

}
