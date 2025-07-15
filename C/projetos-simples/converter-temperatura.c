#include<stdio.h>

int main()
{
    int escolha;
    float temperatura;

        printf("----CONVERSAO DE TEMPERATURA----\n\n");
        printf("Escolha o que quer converter:\n\n");
        printf("1 - De Celsius para Fahrenheit\n2 - De Fahrenheit para Celsius\n\n");

        printf("Digite um numero equivalente as opcoes: ");
        scanf("%d", &escolha);

            printf("\nQual a temperatura para a conversao:  ");
            scanf("%f", &temperatura);

                switch(escolha)
                {
                case 1:

                    temperatura = temperatura*1.8 + 32;
                    printf("\ntemperatura de celsius para fahreinheit eh: F %.1f\n\n", temperatura);

                case 2:
                    temperatura = (temperatura - 32) / 1.8;
                    printf("\ntemperatura de farenheit para celsius eh: C %.1f\n\n", temperatura);

                default:
                    printf("\nDigite uma opcao valida\n\n");
                }



}
