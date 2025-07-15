#include<stdio.h>
#include<stdlib.h>

int main()
{
   float matriz[3][3], soma[3], coluna[3], diagonal = 0;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                printf("|Informe os dados da matriz: ");
                scanf("%f", &matriz[i][j]);

                soma[i] += matriz[i][j];
                coluna[j] += matriz[i][j];
            }
        }

        system("cls");

        printf("> A matriz digitada foi: ");

        for(int i = 0; i < 3; i++)
        {
            printf("\n");

            for(int j = 0; j < 3; j++)
            {
                if(j > 0)
                {
                    printf("\t");
                }
                printf("%2.f",matriz[i][j]);
            }
        }

        system("cls");

        printf("> A soma de cada linha e coluna da matriz eh de: \n\n");

        for(int i = 0; i < 3; i++)
        {
            printf("\t%.2f", soma[i]);
        }

        printf("\n\n");

        for(int i = 0; i < 3; i++)
        {
            printf("\t%2.f", coluna[i]);
        }
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(i == j)
                    {
                        diagonal += matriz[i][j];
                    }
                }
            }
            printf("\n\n");
            system("pause");
            system("cls");

            printf("> A soma da diagona principal eh de: %.2f", diagonal);
            printf("\n\n");
}
