#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

char palavra[35], tema[35], palpite, exibir[35];
bool receba = false, encerrar = false;
int vidas = 5;

void teste()
{
    while(vidas > 0 && !encerrar)
    {
        receba = false;

        printf("            |Tema: %s|\n", tema);
        printf("\n|Vidas: %d\n", vidas);
        printf("\n> Descubra a palavra:\n\n");

        printf("        ");

        for(int i = 0; i < strlen(palavra); i++)
        {
            printf("%c ", exibir[i]);
        }

            printf("\n\n> Digite uma letra: ");
            scanf(" %c", &palpite);

            for(int i = 0; i < strlen(palavra); i++)
            {
                if(palpite == palavra[i])
                {
                    receba = true;
                    exibir[i] = palavra[i];
                }
            }

            if(receba)
            {
                printf("\nParabens!, voce acertou a letra!");
            }
            else
            {
                printf("\nA palavra nao possui a letra %c!", palpite);
                vidas--;
            }
            if(strcmp(exibir, palavra) == 0)
            {
                encerrar = true;
            }

            printf("\n\n");
            system("pause");
            system("cls");
    }

    if(vidas == 0)
    {
        printf("        |Game Over|");
    }
    if(encerrar)
    {
        printf("    |Parabens, voce venceu!");
    }


}
int main()
{
    printf("\n|Digite o tema do jogo: ");
    fgets(tema, 35, stdin);
    fflush(stdin);

    tema[strcspn(tema, "\n")] = '\0';
    tema[0] = toupper(tema[0]);

    system("cls");

    printf("\n|Digite a palavra do jogo: ");
    fgets(palavra, 35, stdin);
    fflush(stdin);

    system("cls");

    palavra[strcspn(palavra, "\n")] = '\0';

        for(int i = 0; i < strlen(palavra); i++)
        {
            exibir[i] = '_';
        }

    teste();
}
