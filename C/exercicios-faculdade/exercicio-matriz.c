#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define quantidade 5
#define lojas 4

int main()
{
    system("color 0f");

    float frete[quantidade][lojas], precos[quantidade][lojas], impostos[quantidade][lojas], planilha_final[quantidade][lojas], total[quantidade][lojas], maior = 0;
    char nome[quantidade][20];
    int maior_loja;

        for(int i = 0; i < quantidade; i ++)
        {
            printf("\n|Digite o nome do produto %d: ", i+1);
            fgets(nome[i], 20, stdin);
            fflush(stdin);
            nome[i][0] = toupper(nome[i][0]);
            nome[i][strcspn(nome[i], "\n")] = '\0';

            system("cls");

            for(int j = 0; j < lojas; j++)
            {
                printf("\n|Digite o preco do produto %s na loja %d: R$ ", nome[i], j + 1);
                scanf("%f", &precos[i][j]);
                fflush(stdin);

                impostos[i][j] = precos[i][j] * 0.05;

                printf("\n|Digite o preco do frete do produto %s na loja %d: R$ ", nome[i], j + 1);
                scanf("%f", &frete[i][j]);
                fflush(stdin);

                printf("\n");
                system("pause");
                system("cls");
            }
        }

            for(int i = 0; i < quantidade; i++)
            {
                printf("\n> Sobre o produto %s: \n\n\n", nome[i]);

                printf("\t              PRECO        FRETE       IMPOSTO      TOTAL    \n");

                for(int j = 0; j < lojas; j++)
                 {
                     printf("\n");
                     printf("\tLoja %d: || R$ %.2f  ||  R$ %.2f  ||  R$ %.2f  ||  R$ %.2f  ||", j + 1, precos[i][j], frete[i][j], impostos[i][j], frete[i][j] + precos[i][j] + impostos[i][j]);
                     printf("\n\n");


                     total[i][j] = precos[i][j] + frete[i][j] + impostos[i][j];

                     if(maior < total[i][j])
                     {
                         maior = total[i][j];
                         maior_loja = j + 1;
                     }
                }
            }

            printf("\n -> A loja com maior custo final de um produto eh a %d com o valor de R$ %.2f\n\n", maior_loja, maior);

            return 0;
}
