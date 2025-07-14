#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char produtos_em_estoque[2][99] = { "Oleo", "Borracha"};
    char produto[99], receba[99];

    printf("|Digite um produto: ");
    scanf("%s", &produto);

    produto[0] = toupper(produto[0]);

    strcpy(receba, produto);

    if(strcmp(receba, produtos_em_estoque[0]) == 0 || strcmp(receba, produtos_em_estoque[1]) == 0)
    {
        printf("\n\n  -> Tem no estoque\n\n");
    }
    else
    {
        printf("\n\n  -> Nao tem no estoque\n\n");
    }

}
