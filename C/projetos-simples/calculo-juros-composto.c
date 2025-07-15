#include<stdio.h>
#include<math.h>

int main()
{
    float juros, capital, montante;
    int tempo;

        printf("-----------------------\n");
        printf("| Calculo De Montante |");
        printf("\n-----------------------\n");

            printf("\nDigite seu capital inicial: ");
            scanf("%f", &capital);

            printf("\nDigite a taxa de juros: ");
            scanf("%f", &juros);

            printf("\nDigite o tempo da operacao: ");
            scanf("%d", &tempo);

                juros = juros/100;

                montante = capital * pow((juros + 1 ), tempo);

                printf("\nMontante eh igual a : R$ %.2f", montante);
}