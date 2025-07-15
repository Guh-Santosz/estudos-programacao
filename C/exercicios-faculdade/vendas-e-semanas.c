#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define quantidade 5
#define semanas 4

int main()
{
    system("color 0f");

    char vendedores[quantidade][30];
    float vendas[quantidade][semanas], total_mes = 0, total_semana[semanas], total_vendedor[quantidade];

    for(int i = 0; i < quantidade; i++)
    {
        total_semana[i] = 0;
        total_vendedor[i] = 0;
    }

        for(int i = 0; i < quantidade; i++)
        {
            printf("\n|Digite o nome do vendedor %d: ", i + 1);
            fgets(vendedores[i], 30, stdin);
            fflush(stdin);

            vendedores[i][strcspn(vendedores[i], "\n")] = '\0';

            vendedores[i][0] = toupper(vendedores[i][0]);

            system("cls");

            for(int j = 0; j < semanas; j++)
            {
                printf("\n|Digite quanto o(a) vendedor(a) %s vendeu na semana %d: R$ ", vendedores[i], j + 1);
                scanf("%f", &vendas[i][j]);
                fflush(stdin);

                total_vendedor[i] += vendas[i][j];
                total_semana[j] += vendas[i][j];

                total_mes += vendas[i][j];

                system("cls");
            }
        }

        printf("\n\t\t\t ----'RELATORIO FINAL'----\n\n");


        for(int i = 0; i < quantidade; i++)
        {
            printf("> Sobre o(a) vendedor(a) %s:\n\n", vendedores[i]);

            for(int j = 0; j < semanas; j++)
            {
                printf("|Semana %d -> \t |Vendas: R$ %.2f|\n", j + 1, vendas[i][j]);
            }

            printf("\n|Total de vendas: R$ %.2f|\n\n", total_vendedor[i]);
            printf("\n");
        }



        printf("-> O total de vendas por semana foi de:\n\n");

            for(int i = 0; i < semanas; i++)
            {
                printf("|Semana %d: R$ %.2f\n", i + 1, total_semana[i]);
            }

            printf("\n|O total de vendas do mes foi de: R$ %.2f", total_mes);
}
