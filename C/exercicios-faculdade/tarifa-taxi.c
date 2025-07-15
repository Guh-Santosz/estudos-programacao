#include <stdio.h>

int main()
{
    float km, tarifa, taxakm, valortotal;
    int zona, cleber;

            printf("----Calculando tarifa de taxi----\n\n");
            printf("Escolha a zona de destino: \n\n");

            printf("1 - Zona Norte\n2 - Zona Central\n3 - Zona Sul\n4 - Zona Leste\n5 - Zona Oeste\n\n");
            printf("Escolha um numero equivalente a regiao: ");
            scanf("%d", &zona);

                if(zona == 1)
                {
                    tarifa = 3.00;
                    cleber = 1;
                }
                else if(zona == 2)
                {
                    tarifa = 4.50;
                    cleber = 1;
                }
                else if(zona == 4)
                {
                    tarifa = 6.00;
                    cleber = 1;
                }
                else if(zona == 5)
                {
                    tarifa = 7.50;
                    cleber = 1;
                }
                else
                {
                    printf("\n\nDigite um numero valido\n\n");
                }

                if(cleber == 1)
                {

                    printf("\n\nDigite a distancia do percurso em quilometros: ");
                    scanf("%f", &km);

                        taxakm = km * 1.50;

                        valortotal = taxakm + tarifa;

                    printf("\n\nO valor total da viagem eh de: R$ %.2f\n\n", valortotal);

                }
}
