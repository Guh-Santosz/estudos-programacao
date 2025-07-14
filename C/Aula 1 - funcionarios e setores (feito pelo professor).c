#include <stdlib.h>
#include <stdio.h>

int main()
{
    float salario, total;
    int i,j,n,fdepto;

    float maior,menor;
    int mdepto,ndepto,te,mte;

    maior=0;
    menor =2000;
    total=0;
    mte=0;

    for(i=0; i<3; i++)
    {
        printf("\n Informe o numero do funcionario do depto %d",i+1);
        scanf("%d",&n);
        total=0;
        for(j=0; j<n; j++)
        {
            printf("\n Informe o salario");
            scanf("%f",&salario);
            printf("\n Informe o Tempo de Empresa");
            scanf("%d",&te);
            total += salario;

            // Item B
            if(te > mte)
            {
                mte=te;
                fdepto = i+1;
            }
            // item C
            if (salario > maior)
            {
                maior = salario;
                mdepto =i+1;
            }

            if(salario < menor)
            {
                menor = salario;
                ndepto = i+1;
            }

        }
        printf("\n Total do salario do Depto %d e de %.2f",i+1,total);
        printf("\n\n");
        system("pause");
    }
    printf("\n O maior tempo de empresa %d pertence ao Depto %d",mte,fdepto);

    printf("\n O maior salario encontrado %.2f pertence ao Depto %d",maior,mdepto);

    printf("\n O menor salario encontrado %.2f pertence ao Depto %d",menor, ndepto);

    printf("\n\n");
    system("pause");

}
