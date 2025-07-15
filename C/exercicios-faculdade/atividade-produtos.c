#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

char estoque(char a[])
{
    char produtos_em_estoque[6][99] = {"BORRACHA", "OLEO", "MATERIA PRIMA", "FITA ADESIVA", "COCA COLA", "GUSTAVO DELICIA"};
    int quantidade[6] = {51, 2, 78, 10, 22, 1}, qntd;
    bool receba = false;

        for(int i = 0; i < 6; i++)
        {
            if(strcmp(a, produtos_em_estoque[i]) == 0)
            {
                qntd = i;
                receba = true;
                break;
            }
        }
        for(int g = 0; g < strlen(a); g++)
        {
            if(g > 0)
            {
                a[g] = tolower(a[g]);
            }
        }

        if(receba)
        {
            printf("\n      -> A quantidade de %s no estoque eh de: %d\n\n", a, quantidade[qntd]);
        }
        else
        {
            printf("\n      -> O produto %s nao se encontra no estoque\n\n", a);
        }
}

int main()
{
    char palpite[99], produto[99];

        printf("  > Digite o produto: ");
        fgets(palpite,sizeof(palpite), stdin);

        palpite[strcspn(palpite, "\n")] = '\0';

        strcpy(produto, palpite);

        for(int p = 0; p < strlen(produto); p++)
        {
            produto[p] = toupper(produto[p]);
        }

        estoque(produto);

        return 0;
}
