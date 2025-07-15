#include<stdio.h>
#include<string.h> //Biblioteca de string
#include<ctype.h>

int main()
{

//declarando variaveis:

    int quantidade, i, maior = 0;

//Coletando a quantidade de pessoas:

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &quantidade);

    system("cls");

//Declarando variáveis com base na quantidade:

    int idade[quantidade];
    char mander[quantidade][99];
    char nome[99];

    //iniciando loop:

        for(i = 0; i < quantidade; i++)
        {
            //Coletando dados:

            printf("\n\n    |Digite o nome da pessoa %d: ", i + 1);
            scanf("%98s", &mander[i]);

            printf("\n\n    |Digite a idade da pessoa %d: ", i + 1);
            scanf("%d", &idade[i]);

            system("cls");

                if(idade[i] > maior)
                {
                    maior = idade[i];

                    //Aumentando a primeira letra do nome:

                    mander[i][0] = toupper(mander[i][0]);

                    //nome que vai receber, nome que dará:

                    strcpy(nome, mander[i]);
                }
        }

        system("cls");

        //Exibindo resultados:

        printf("\n    > A pessoa mais velha eh %s com %d anos de idade\n\n", nome, maior);
}
