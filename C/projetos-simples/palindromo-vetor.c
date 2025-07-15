#include<stdio.h>
#include<string.h>

int main()
{
    char palpite[20], palindromo[20];
    int l = 0, tamanho = 0;

        printf("\n|Digite uma palavra: ");
        fgets(palpite, 20, stdin);
        fflush(stdin);

        palpite[strcspn(palpite, "\n")] = '\0';

            for(int i = strlen(palpite) - 1; i >= 0 ; i--)
            {
                palindromo[l] = palpite[i];
                l++;
            }
            for(int i = 0; i < strlen(palpite); i++)
            {
                if(palpite[i] == palindromo[i])
                {
                    tamanho++;
                }
            }

                if(tamanho == strlen(palpite))
                {
                    printf("\nEh palindromo");
                }
                else
                {
                    printf("\nNao eh um palindromo");
                }
}
