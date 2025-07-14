#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char ref,resp;

    char transp;

    int pais;

    float valor, imposto,total, frete, seguro;

    do
    {
        printf("\n Informe o valor do Produto");
        scanf("%f",&valor);

        printf("\n Pais de Origem ");
        scanf("%d",&pais);

        printf("\n Informe o meio de Transporte");
        printf("\n [T] - Terrestre - [F] - Fluvial [A] - Aereo");
        scanf(" %c",&transp);
        transp = toupper (transp);

        printf("\n Informe quanto a Refrigeração");
        printf("\n [S] - Sim ou [N] - Não");
        scanf(" %c",&ref);
        ref = toupper(ref);

        // calculo do imposto

        if (valor <=100)
        {
            imposto = valor * 0.05;
        }
        else
        {
            imposto = valor * 0.10;

        }

// Calculo do transporte

        if( ref == 'S' && pais == 1)
        {
            frete = 50;

        }
        else if( ref == 'S' &&  pais == 2)
        {
            frete = 35;

        }
        else if ( ref == 'S' && pais == 3)
        {
            frete = 24;

        }
        else if (ref == 'N' && pais == 1)
        {
            frete = 12;
        }
        else if (ref == 'N' && pais == 2 )
        {
            frete = 36;
        }
        else
        {
            frete = 60;
        }

        if (pais == 2 && transp == 'A')
        {
            seguro = valor /2;
        }else {
            seguro = 0;
        }


        total = valor+frete+imposto+seguro;

        printf("\n --------------------------------------------------");
        printf("\n Valor do Produto unitário %.2f",valor);
        printf ("\n Valor do imposto devido do produto %.2f", imposto);
        printf("\n Valor do Transporte Frete %.2f", frete);
        printf("\n Valor do Seguro %.2f", seguro);
        printf("\n --------------------------------------------------");
        printf("\n Valor Total do Produto %.2f",total);
        printf("\n --------------------------------------------------");
        printf("\n\n");
        system("pause");

        printf("\n Deseja continuar o processamento");
        scanf(" %c",&resp);
        resp = toupper(resp);


    }while (resp != 'N');
}





