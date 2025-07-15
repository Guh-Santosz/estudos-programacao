#include<stdio.h>

int main()
{
    int i, resultado = 0, sla = 1, num = 1;

        for(i = 0; i <= 9; i++)
        {
            resultado = sla + num;
            printf("%d\n", resultado);
            num = sla;
            sla = resultado;
            resultado = sla + num;

        }

}
