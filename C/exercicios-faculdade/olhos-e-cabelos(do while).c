#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main()
{

//Declarando as variáveis:

    int idade, i = 0, pessoas_incriveis = 0, soma_idade = 0, baixos = 0, ruivos_sem_azul = 0;
    float altura, peso, media_idade, percentual_azul, olhos_azuis = 0,  quantidade;
    char cor_dos_olhos, cor_do_cabelo;
    bool receba;

//Coletando qunatidade para iniciar o loop:

        printf(" -> Digite a qunatidade de pessoas: ");
        scanf("%f", &quantidade);

//Validando a quantidade de pessoas:

            while(quantidade < 1)
            {
                printf("\n    > Digite um numero valido: ");
                while((getchar()) != '\n');
                scanf("%f", &quantidade);
            }

        system("cls");

//iniciando loop:

            do
            {
                //Coletando dados dos usuários:

                printf("\n    |Digite a idade da pessoa numero %d: ", i + 1);
                scanf("%d", &idade);

                //Validando idade:

                    while(idade < 1)
                    {
                        printf("\n      > Digite uma idade valida: ");
                        scanf("%d", &idade);

                    }

                printf("\n\n    |Digite o peso da pessoa numero %d: ", i + 1);
                scanf("%f", &peso);

                //Validando peso:

                    while(peso < 1)
                    {
                        printf("\n      > Digite um peso valido: ");
                        scanf("%f", &peso);
                    }

                printf("\n\n    |Digite a altura da pessoa numero %d: ", i + 1);
                scanf("%f", &altura);

                //Validando altura:

                    while(altura < 1)
                    {
                        printf("\n      > Digite uma altura valida: ");
                        scanf("%f", &altura);
                    }

                system("cls");

                printf("\n        P - Preto| C - Castanho | V - Verde | A - Azul\n\n");
                printf("    |Digite a cor dos olhos da pessoa numero %d: ", i + 1);
                scanf(" %c", &cor_dos_olhos);

                //Deixando maiúscula:

                    cor_dos_olhos = toupper(cor_dos_olhos);

                //Validadando cor dos olhos:

                    while(cor_dos_olhos != 'P' && cor_dos_olhos != 'C' && cor_dos_olhos != 'V' && cor_dos_olhos != 'A')
                    {
                        printf("\n      > Digite uma cor valida: ");
                        scanf(" %c", &cor_dos_olhos);

                        cor_dos_olhos = toupper(cor_dos_olhos);
                    }

                system("cls");

                printf("\n        P - Preto| C - Castanho | L - Louro | R - Ruivo\n\n");
                printf("    |Digite a cor do cabelo da pessoa numero %d: ", i + 1);
                scanf(" %c", &cor_do_cabelo);

                //Deixando maiúscula:

                    cor_do_cabelo = toupper(cor_do_cabelo);

                //Validando cor do cabelo:

                    while(cor_do_cabelo != 'P' && cor_do_cabelo != 'C' && cor_do_cabelo != 'L' && cor_do_cabelo != 'R')
                    {
                        printf("\n      > Digite uma cor valida: ");
                        scanf(" %c", &cor_do_cabelo);

                        cor_do_cabelo = toupper(cor_do_cabelo);
                    }

                //Elaborando procedimentos:

                //Descobrindo pessoas com peso < 60 e idade > 50:

                    if(idade > 50 && peso < 60)
                    {
                        pessoas_incriveis++;
                    }

                //Descobrindo a média de idade da galera < 1.50:

                    if(altura < 1.50)
                    {
                        soma_idade += idade;
                        baixos++;
                    }

                //Descobrindo a quantidade de pessoas com olhos azuis:

                    if(cor_dos_olhos == 'A')
                    {
                        olhos_azuis++;
                        receba = true;
                    }

                //Identificando quem é ruivo e n tem olho azul:

                    if(cor_do_cabelo == 'R')
                    {
                        if(cor_dos_olhos != 'A')
                        {
                            ruivos_sem_azul++;
                        }
                    }

                    system("cls");

                i++;
            }
            while(i < quantidade);


            //Validando a média da idade dos baixinhos:

                    if(baixos > 0)
                    {
                        media_idade = soma_idade / baixos;
                    }
                    else
                    {
                        media_idade = 0;
                    }

            //Validando percentual:

                        if(receba)
                        {
                            percentual_azul = (olhos_azuis / quantidade) * 100;
                        }

             //Exibindo resultados:

            printf("\n\n  > A quantidade de pessoas com idade maior que 50 e peso menor que 60 eh de: %d\n\n", pessoas_incriveis);
            printf("\n  > A media de idade das pessoas menores de 1,50 eh de: %.2f\n\n", media_idade);
            printf("\n  > O percentual de pessoas com olhos azuis eh de: %.2f%%\n\n", percentual_azul);
            printf("\n  > A quantidade de pessoas ruivas sem olhos azuis : %d\n\n", ruivos_sem_azul);
}
