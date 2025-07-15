#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define quantidade 12

int main()
{
    system("color 0F");

    char refrigeracao[quantidade], categorias[quantidade], classificacao[quantidade][250] = {"Barato", "Normal", "Caro"};
    float precos[quantidade], custo_de_estocagem[quantidade], impostos[quantidade], preco_final[quantidade];
    int indice[quantidade];

        for(int i = 0; i < quantidade; i++)
        {
            printf("\n |Digite o preco do produto %d: R$ ", i + 1);
            scanf("%f", &precos[i]);
            fflush(stdin);

            system("cls");

            printf("\n > O Produto precisa de refrigeracao?\n\n");
            printf("        |S - sim | N - nao|");

            printf("\n\n |Digite: ");
            scanf("%c", &refrigeracao[i]);
            fflush(stdin);

                refrigeracao[i] = toupper(refrigeracao[i]);

                system("cls");

                printf("\n > Digite a categoria do produto: \n\n");
                printf("        |A - Alimentacao | L - Limpeza| V - Vestuario|");

                printf("\n\n |Digite: ");
                scanf("%c", &categorias[i]);
                fflush(stdin);

                categorias[i] = toupper(categorias[i]);

                    if(precos[i] <= 50 )
                    {
                        if(categorias[i] == 'A')
                        {
                            custo_de_estocagem[i] = 5;
                        }
                        else if(categorias[i] == 'L')
                        {
                            custo_de_estocagem[i] = 10;
                        }
                        else if(categorias[i] == 'V')
                        {
                            custo_de_estocagem[i] = 15;
                        }
                    }


                    else if(precos[i] > 50 && precos[i] <= 70)
                    {
                        if(refrigeracao[i] == 'S')
                        {
                            custo_de_estocagem[i] = 21;
                        }
                        else
                        {
                            custo_de_estocagem[i] = 12;
                        }
                    }


                    else
                    {
                        if(refrigeracao[i] == 'S')
                        {
                            if(categorias[i] == 'A')
                            {
                                custo_de_estocagem[i] = 6;
                            }
                            else if(categorias[i] == 'L')
                            {
                                custo_de_estocagem[i] = 2;
                            }
                            else
                            {
                                custo_de_estocagem[i] = 4;
                            }
                        }
                        else
                        {
                            if(categorias[i] == 'A' || categorias[i] == 'V')
                            {
                                custo_de_estocagem[i] = 0;
                            }
                            else
                            {
                                custo_de_estocagem[i] = 1;
                            }
                        }
                    }

                if(categorias[i] == 'A' && refrigeracao[i] == 'S')
                {
                    impostos[i] = 0.04;
                }
                else
                {
                    impostos[i] = 0.02;
                }

                preco_final[i] = precos[i] + custo_de_estocagem[i] + (precos[i] * impostos[i]);

                if(preco_final[i] <= 50)
                {
                    indice[i] = 0;
                }
                else if(preco_final[i] > 50 && preco_final[i] <= 70)
                {
                    indice[i] = 1;
                }
                else
                {
                    indice[i] = 2;
                }


                printf("\n\n");
                system("pause");
                system("cls");
        }

        printf("\n-> Relatorio Final:");

        printf("\n\n |Produto|  |Custo de Estoque|  |Imposto|   |Classificacao| |Valor Final|\n\n\n");

        for(int i = 0; i < quantidade; i++)
        {
            printf("      %d..........%.2f.............%.2f %...........%s.........R$ %.2f\n\n", i + 1, custo_de_estocagem[i], impostos[i] * 100, classificacao[indice[i]], preco_final[i]);
        }


        printf("\n\n\n\n");
        return 0;
}