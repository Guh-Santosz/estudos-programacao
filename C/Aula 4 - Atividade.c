#include<stdio.h>
#include<stdlib.h>

int main()
{
//Declarando variáveis:

    int tamanho, i;

    //Pedindo o tamanho do vetor ao usuário:

        printf("Digite quantas idades voce digitara: ");
        scanf("%d", &tamanho);

        while(tamanho < 1)
        {
            printf("\n    > Digite um numero valido\n");
            printf("Digite quantas idades voce digitara: ");
            scanf("%d", &tamanho);
        }

        system("cls");

        //Declarando vetor:

        int numeros[tamanho];

        //Iniciando loop:

        for(i = 0; i < tamanho; i++)
        {
            //Coletando as idades do usuário:

            printf("\n |Digite a idade numero %d: ", i + 1);
            scanf("%d", &numeros[i]);

            //Validando idades(se for menor q 1):

            while(numeros[i] < 1)
            {
                printf("\n    > Digite um numero valido\n");
                printf("\n |Digite a idade numero %d: ", i + 1);
                scanf("%d", &numeros[i]);

            }

            //Verificando se é par ou não:

                if(numeros[i] % 2 == 0)
                {
                    printf("\n -> A idade %d eh par\n\n", numeros[i]);

                    system("pause");
                }
                else
                {
                    printf("\n -> A idade %d eh impar\n\n", numeros[i]);

                    system("pause");
                }
        }

        return 0;
}
