#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int main()
{

printf("\n                       ----'Sisteminha do Balacubaco'----\n\n");

//Declarando variáveis:

    int quantidade, i, indice_maior = 0, indice_menor = 0;
    float total = 0, maior = 0, menor = 999999999;
    bool validacao_um = true, validacao_dois = true, validacao_tres = true;

//Coletando a quantidade de vendedores:

//Validando entrada de quantidade:

        do
        {
            if(validacao_um == false)
            {
                printf("\n    -> Digite um numero valido!\n");
            }

            printf("\n > Digite a quantidade de vendedores: ");
            scanf("%d", &quantidade);
            fflush(stdin);

            validacao_um = false;
        }
        while(quantidade < 1);

//Declarando vetores com a quantidade de vendedores:

    char nomes[quantidade][50];
    float vendas[quantidade], percentual[quantidade], salarios[quantidade];

        system("cls");

//Iniciando loop para as informações dos vendedores:

        for(i = 0; i < quantidade; i++)
        {
//Limpando Buffer:

            printf("\n");
            fflush(stdin);

//Coletando nome dos vendedores:

            printf(" |Digite o nome do funcionario %d: ", i + 1);
            fgets(nomes[i], 50, stdin);
            fflush(stdin);

//Tirando a quebra de linha e deixando a primeira letra maiúscula:

            nomes[i][strcspn(nomes[i], "\n")] = '\0';
            nomes[i][0] = toupper(nomes[i][0]);

            printf("\n");

//Coletando o total de vendas dos funcionarios:


//Validando entrada de vendas:

                printf(" |Digite o total de vendas do(a) %s: R$ ", nomes[i]);
                scanf("%f", &vendas[i]);
                fflush(stdin);

                printf("\n");

            while(vendas[i] < 0)
            {
                printf("\n    -> Digite um numero valido!\n\n");

                printf(" |Digite o total de vendas do(a) %s: R$ ", nomes[i]);
                scanf("%f", &vendas[i]);
                fflush(stdin);

                printf("\n");
            }

//Coletando o percentual de venda de cada colaborador:

//Validando entrada de percentual de venda:

                printf(" |Digite a porcentagem da comissao do(a) %s: ", nomes[i]);
                scanf("%f", &percentual[i]);
                fflush(stdin);

            while(percentual[i] < 1)
            {
                printf("\n    -> Digite um numero valido!\n\n");

                printf(" |Digite a porcentagem da comissao do(a) %s: ", nomes[i]);
                scanf("%f", &percentual[i]);
                fflush(stdin);
            }

//Fazendo calculo de salario por porcentagem e somando o total de vendas gerais:

            salarios[i] = vendas[i] * (percentual[i] / 100);
            total += vendas[i];

//Descobrindo o maior e o menor salário e seu respectivo dono:

                if(salarios[i] > maior)
                {
                    maior = salarios[i];
                    indice_maior = i;
                }
                if(salarios[i] < menor)
                {
                    menor = salarios[i];
                    indice_menor = i;
                }

                system("cls");
        }

//Exibindo o relatório:

            printf("\n                           ----'Relatorio Final'----\n\n");

            printf("\n -> O maior valor a receber eh de R$ %.2f do vendedor(a) %s\n", maior, nomes[indice_maior]);
            printf("\n -> O menor valor a receber eh de R$ %.2f do vendedor(a) %s\n", menor, nomes[indice_menor]);
            printf("\n\n |O total de vendas foi de: R$ %.2f\n\n\n\n\n\n\n\n\n\n\n\n", total);

            return 0;
}
