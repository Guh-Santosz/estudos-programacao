#include<stdio.h>
#include <conio.h>
#include<stdbool.h>

int main()
{
    int quantidade, i, l, total_pecas = 0, quantidade_homens = 0, quantidade_muie = 0;
    bool sexo;

    printf("\n                      ---- 'SISTEMINHA DO BALACUBACO' ----     \n\n\n");

        printf(" -> Digite a quantidade de operarios do mes: ");
        scanf("%d", &quantidade);

        if(quantidade <= 1)
        {
            printf("\n\n        |Parabens amigo, a empresa ta falida :)\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            return 0;
        }

        system("cls");

    int pecas[quantidade], pecas_homi[quantidade], pecas_muie[quantidade],total_homi = 0, total_muie = 0;
    float salarios[quantidade], total = 0, media_homi, media_muie, maior = 0;
    char sexo_funcionarios[quantidade];

            for(i = 0; i < quantidade; i++)
            {

                printf("\n                         M - Masculino | F - Feminino \n");
                printf("                        ______________________________\n\n");


                printf("\n  |Digite o sexo do operario %d (M ou F): ", i + 1);

                while ((getchar()) != '\n');
                scanf(" %c",&sexo_funcionarios[i]);

                    while(sexo_funcionarios[i] != 'm' && sexo_funcionarios[i] != 'f' && sexo_funcionarios[i] != 'M' && sexo_funcionarios[i] != 'F')
                    {
                        printf("\n      -> Por favor, insira um sexo valido: ");
                        while ((getchar()) != '\n');

                        scanf(" %c",&sexo_funcionarios[i]);
                    }

                printf("\n  |Digite o numero de pecas produzido pelo operario %d: ", i + 1);
                while ((getchar()) != '\n');
                scanf("%d", &pecas[i]);


                while(pecas[i] < 0)
                {
                    printf("\n      -> Por favor, insira um numero valido: ");
                        while ((getchar()) != '\n');

                        scanf("%d",&pecas[i]);
                }

                        if(sexo_funcionarios[i] == 'M' || sexo_funcionarios[i] == 'm')
                        {
                            pecas_homi[i] = pecas[i];
                            pecas_muie[i] = 0;

                            quantidade_homens++;
                        }
                        else if (sexo_funcionarios[i] == 'F' || sexo_funcionarios[i] == 'f')
                        {
                            pecas_muie[i] = pecas[i];
                            pecas_homi[i] = 0;

                            quantidade_muie++;
                        }

                total_homi += pecas_homi[i];
                total_muie += pecas_muie[i];
                total_pecas += pecas[i];

                system("cls");
            }

            if(quantidade_muie == 0)
            {
                total_muie = 0;
                media_muie = 0;
            }
            else
            {
                media_muie = total_muie / quantidade_muie;
            }

            if(quantidade_homens == 0)
            {
                total_homi = 0;
                media_homi = 0;
            }
            else
            {
                media_homi = total_homi / quantidade_homens;
            }


            printf("\n                         ---- 'RELATORIO FINAL' ----     \n\n");


            for(l = 0; l < quantidade; l++)
            {
                if(pecas[l] <= 30)
                {
                    salarios[l] = 1412;
                }
                else if(pecas[l] > 30 && pecas[l] < 36)
                {
                    salarios[l] = 1412 + (1412 * 0.03) * (pecas[l] - 30);;
                }
                else if(pecas[l] > 35)
                {
                    salarios[l] = 1412 + (1412 * 0.05) * (pecas[l] - 30);
                }

                    total += salarios[l];

                    if(salarios[l] > maior)
                    {
                        maior = salarios[l];
                        i = l;

                        if(sexo_funcionarios[l] == 'M' || sexo_funcionarios[l] == 'm')
                        {
                            sexo = true;
                        }
                        else if(sexo_funcionarios[l] == 'F' || sexo_funcionarios[l] == 'f')
                        {
                            sexo = false;
                        }
                    }

                printf("\n  --| O salario do operario %d eh de: R$ %.2f",l + 1, salarios[l]);
            }
            printf("\n\n      |-> O total da folha de pagamento de fabrica eh de: R$ %.2f",total);
            printf("\n      |-> O total de pecas produzidas foi de: %d\n\n", total_pecas);
            printf("\n > A media de pecas produzidas por homens eh de: %.1f", media_homi);
            printf("\n > A media de pecas produzidas por mulheres eh de: %.1f\n\n", media_muie);

                if(sexo)
                {
                     printf("\n > O operario com o maior salario foi o numero %d com seu salario: R$ %.2f\n\n\n", i + 1, maior);
                }
                else
                {
                    printf("\n > A operaria com o maior salario foi a numero %d com seu salario: R$ %.2f\n\n\n\n\n", i + 1, maior);
                }

                return 0;
}
