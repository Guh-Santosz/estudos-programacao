#include<stdio.h>

int main()
{
    int funcionarios = 3;
    int i, l, nov[funcionarios], dez[funcionarios], jan[funcionarios], pontuacao, j, p;
    int soma[funcionarios], maior_jan = 0, maior_dez = 0, maior_nov = 0;
    float media[funcionarios];

        printf(" -> Pontuacao dos funcionarios no mes de novembro:\n");

        for(l = 0; l < funcionarios; l++)
        {
            printf("\n  |Digite a pontuacao do funcionario numero %d: ", l + 1);
            scanf("%d", &pontuacao);

            nov[l] = pontuacao;

            if(maior_nov < pontuacao)
            {
                maior_nov = pontuacao;
            }
        }

        printf("\n -> Pontuacao dos funcionarios no mes de dezembro:\n");

        for(i = 0; i < funcionarios; i++)
        {
            printf("\n  |Digite a pontuacao do funcionario numero %d: ", i + 1);
            scanf("%d", &pontuacao);

            dez[i] = pontuacao;

            if(maior_dez < pontuacao)
            {
                maior_dez = pontuacao;
            }
        }

        printf("\n -> Pontuacao dos funcionarios no mes de janeiro:\n");

        for(j = 0; j < funcionarios; j++)
        {
            printf("\n  |Digite a pontuacao do funcionario numero %d: ", j + 1);
            scanf("%d", &pontuacao);

            jan[j] = pontuacao;

            if(maior_jan < pontuacao)
            {
                maior_jan = pontuacao;
            }
        }
        printf("\n\n");

        for(p = 0; p < funcionarios; p++)
        {
            soma[p] = nov[p] + dez[p] + jan[p];
            media[p] = soma[p] / 3;

            printf("\n * |A pontuacao geral do funcionario %d eh de: %d\n", p + 1, soma[p]);
            printf("\n * |A media dos pontos do funcionario %d eh de: %.1f\n", p + 1, media[p]);
            printf("\n");

        }

            if(maior_nov > maior_dez && maior_nov > maior_jan)
            {
                printf("\n  -> A maior pontuacao atingida nos tres meses foi de: %d", maior_nov);
            }

            else if(maior_dez > maior_nov && maior_dez > maior_jan)
            {
                printf("\n  -> A maior pontuacao atingida nos tres meses foi de: %d", maior_dez);
            }

            else if(maior_jan > maior_nov && maior_dez < maior_jan)
            {
                printf("\n  -> A maior pontuacao atingida nos tres meses foi de: %d\n\n", maior_jan);
            }

            else if(maior_jan == maior_dez && maior_jan == maior_nov)
            {
                printf("\n  -> A maior pontuacao atingida nos tres meses foi de: %d\n\n", maior_jan);
            }
}
