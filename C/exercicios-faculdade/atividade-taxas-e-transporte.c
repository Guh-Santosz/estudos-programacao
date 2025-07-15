#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    int quantidade, i, pais;
    char transporte, escolha;
    float preco, valor_unitario, valor_transporte, seguro;

        printf("\n         ----'Sisteminha do Balacubaco' ----\n\n\n");

        printf("    -> Digite a quantidade de produtos: ");
        scanf("%d", &quantidade);

        system("cls");

        if(quantidade < 1)
        {
            printf("\n\n    -> A empresa declarou falencia :)\n\n\n");

            return 0;
        }
            for(i = 0; i < quantidade; i++)
            {
                printf("\n  > Digite o preco do produto %d: R$ ", i + 1);
                scanf("%f", &preco);

                    while(preco < 0)
                    {
                        printf("\n     -> Digite um preco valido: \n");
                        printf("\n  > Digite o preco do produto %d: ", i + 1);
                        scanf("%f", &preco);
                    }

                printf("\n  > Digite o pais de origem do produto %d:", i + 1);
                printf("\n\n      1 - EUA | 2 - Mexico | 3 - Outros\n\n");
                printf(" |Digite aqui: ");
                scanf("%d", &pais);

                    while(pais != 1 && pais != 2 && pais != 3)
                    {
                        printf("\n  > Digite o pais de origem do produto %d:", i + 1);
                        printf("\n\n      1 - EUA | 2 - Mexico | 3 - Outros\n\n");
                        printf("\n     -> Digite um pais valido: \n");
                        printf("\n |Digite aqui: ");
                        scanf("%d", &pais);
                    }
                printf("\n  > Digite meio de transporte do produto %d:", i + 1);
                printf("\n\n      T - Terrestre | F - Fluvial |A - Aerio\n\n");
                printf(" |Digite aqui: ");
                scanf(" %c", &transporte);

                transporte = toupper(transporte);

                    while(transporte != 'T' && transporte != 'F' && transporte != 'A')
                    {
                        printf("\n  > Digite meio de transporte do produto %d:", i + 1);
                        printf("\n\n      T - Terrestre | F - Fluvial | A - Aerio\n\n");
                        printf("\n     -> Digite um transporte valido: \n");
                        printf("\n |Digite aqui: ");
                        scanf(" %c", &transporte);

                        transporte = toupper(transporte);
                    }

                    printf("\n  > Digite se o produto %d eh perigoso ou nao:", i + 1);
                    printf("\n\n        S - Sim | N - Nao\n\n");
                    printf(" |Digite aqui: ");
                    scanf(" %c", &escolha);

                    escolha = toupper(escolha);

                        while(escolha != 'S' && escolha != 'N')
                        {
                            printf("\n  > Digite se o produto %d eh perigoso ou nao:", i + 1);
                            printf("\n\n        S - Sim | N - Nao\n\n");
                            printf("\n     -> Digite um numero valido: \n");
                            printf("\n |Digite aqui: ");
                            scanf(" %c", &escolha);

                            escolha = toupper(escolha);
                        }

                            if(preco <= 100)
                            {
                                valor_unitario = (preco * 0.05);
                            }
                            else if(preco > 100)
                            {
                                valor_unitario = (preco * 0.1);
                            }

                                if(escolha == 'S')
                                {
                                    if(pais == 1)
                                    {
                                        valor_transporte = 50;
                                    }
                                    else if(pais == 2)
                                    {
                                        valor_transporte = 35;
                                    }
                                    else
                                    {
                                        valor_transporte = 24;
                                    }
                                }

                                else if(escolha == 'N')
                                {
                                    if(pais == 1)
                                    {
                                        valor_transporte = 12;
                                    }
                                    else if(pais == 2)
                                    {
                                        valor_transporte = 35;
                                    }
                                    else
                                    {
                                        valor_transporte = 60;
                                    }
                                }

                                if(pais == 2 && transporte == 'A')
                                {
                                    seguro = preco * 0.5;
                                }
                                else
                                {
                                    seguro = 0;
                                }

                system("cls");

                printf("    Sobre o produto %d: \n\n", i + 1);
                printf("     |-> O preco unitario do produto %d eh de: R$ %.2f", i + 1, preco);
                printf("\n     |-> O imposto do produto %d eh de: R$ %.2f", i + 1, valor_unitario);
                printf("\n     |-> O valor do transporte do produto %d eh de: R$ %.2f", i + 1, valor_transporte);
                printf("\n     |-> O valor do seguro do produto %d eh de: R$ %.2f\n\n", i + 1, seguro);

                system(" pause");
            }

            return 0;
}
