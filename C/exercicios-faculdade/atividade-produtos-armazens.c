#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define produtos 2
#define armazem 2

int main()
{
    system("color 0F");

    char nome_produtos[produtos][20];
    float custos[produtos][armazem], soma_produto[produtos], soma_armazem[armazem], montante_produto[produtos], montante_armazem[armazem];
    int quantidade[produtos][armazem], menor = 100, indice = 0;

    printf("                ----'CONTROLE DE PRODUTOS POR ARMAZEM'----\n\n");

    for(int i = 0; i < armazem; i++)
    {
        soma_armazem[i] = 0;
        soma_produto[i] = 0;
        montante_produto[i] = 0;
        montante_armazem[i] = 0;

    }
        for(int i = 0; i < produtos; i++)
        {
            printf("|Digite o nome do produto %d: ", i + 1);
            fgets(nome_produtos[i], 20, stdin);

            fflush(stdin);
            nome_produtos[i][strcspn(nome_produtos[i], "\n")] = '\0';

            nome_produtos[i][0] = toupper(nome_produtos[i][0]);

            system("cls");

            for(int j = 0; j < armazem; j++)
            {
                printf("|Digite o custo do produto %s no armazem %d: R$ ", nome_produtos[i], j + 1);
                scanf("%f", &custos[i][j]);
                fflush(stdin);

                printf("\n|Digite a quantidade do produto %s no armazem %d: ", nome_produtos[i], j + 1);
                scanf("%d", &quantidade[i][j]);
                fflush(stdin);

                montante_produto[i] += quantidade[i][j] * custos[i][j];
                soma_produto[i] += quantidade[i][j];
                soma_armazem[j] += quantidade[i][j];
                montante_armazem[j] += quantidade[i][j] * custos[i][j];

                    if(i == 1)
                    {
                        if(quantidade[1][j] < menor)
                        {
                            indice = j + 1;
                            menor = quantidade[1][j];
                        }
                    }

                system("cls");
            }
        }

        system("cls");

        printf("\t----'RELATÓRIO FINAL'----\n\n");

        printf("Conclui-se que: \n");

            for(int i = 0; i < produtos; i++)
            {
                printf("\n> Sobre o produto: %s\n", nome_produtos[i]);

                for(int j = 0; j < armazem; j++)
                {
                    printf("\t\n|Armazem %d ->  |Quantidade: %d|  |Custos: R$ %.2f|  |Total: R$ %.2f|", j + 1, quantidade[i][j], custos[i][j], quantidade[i][j] * custos[i][j]);
                }

                printf("\n");
            }

            printf("\n------------------------------------------------------------------------------\n\n");


            for(int i = 0; i < produtos; i++)
            {
                printf("\n> O montante do produto %s foi: R$ %.2f\n",nome_produtos[i], montante_produto[i]);
                printf("> A soma de quantidade do produto %s: %.0f\n", nome_produtos[i], soma_produto[i]);
                printf("> A soma de quantidade do armazem %d: %.0f\n", i + 1, soma_armazem[i]);
                printf("\n");
            }
            printf("\n-> A menor quantidade do produto %s pertence ao armazem: %d\n\n", nome_produtos[1], indice);

                for(int j = 0; j < armazem; j++)
                {
                    printf("-> O montante do armazem %d foi de: R$ %.2f\n", j + 1, montante_armazem[j]);
                }
}
