#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct
{
    int codigo;
    char nome[20];
    char sobrenome[15];
    int rg;
    float salario;
    int cpf;
    char endereco[50];

}cliente;

void alterar()
{
    system("cls");

    int c;
    char nome[20];
    c = 0;

        FILE * fptr;
        cliente fatec;

        printf("-----'ALTERACAO'----\n");

        printf("\nInforme o nome a ser alterado: ");
        gets(nome);
        fflush(stdin);

            fptr = fopen("arquivo", "rb+");

                if(fptr == NULL)
                {
                    printf("\nErro na abertura do arquivo\n\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    fread(&fatec, sizeof(fatec), 1, fptr);

                    while((!feof(fptr)) && (strcmp(nome, fatec.nome)) != 0)
                    {
                        c++;
                        fread(&fatec, sizeof(fatec), 1, fptr);
                    }
                    if(feof(fptr))
                    {
                        printf("\nRegistro nao encontrado no arquivo\n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        fseek(fptr, c * sizeof(fatec), SEEK_SET);
                        {
                            system("cls");
                            printf("-------ALTERANDO DADOS-------\n");

                            printf("\nNome--------------------%s", fatec.nome);
                            printf("\n\nAltere: ");
                            gets(fatec.nome);
                            fflush(stdin);

                            printf("\nSobrenome--------------------%s", fatec.sobrenome);
                            printf("\n\nAltere: ");
                            gets(fatec.sobrenome);
                            fflush(stdin);

                            printf("\nEndereco--------------------%s", fatec.endereco);
                            printf("\n\nAltere: ");
                            gets(fatec.endereco);
                            fflush(stdin);


                        }
                    }

                    fwrite(&fatec,sizeof(fatec),1,fptr);

                        printf("\nDados alterados com sucesso\n\n");
                        system("pause");
                        system("cls");
                        fclose(fptr);


                }
}

void inserir()
{
    char numstr[20];
    char resp;

    FILE *fptr;//Atribuição de ponteiro ao arquivo
    cliente fatec;//Associando a variável fatec ao struct

    fptr = fopen("arquivo", "ab");//AB -> Inserir Registro

        if(fptr == NULL)
        {
            printf("\nErro na abertura do arquivo\n");
            system("pause");
        }
        else
        {
            do
            {
                system("cls");

                printf("---------CADASTRO---------\n");

                    printf("\n|Informe o codigo do cliente: ");
                    scanf("%d", &fatec.codigo);
                    fflush(stdin);

                    printf("\n|Informe o nome do cliente: ");
                    gets(fatec.nome);
                    fflush(stdin);

                    printf("\n|Informe o sobrenome do cliente: ");
                    gets(fatec.sobrenome);
                    fflush(stdin);

                    printf("\n|Informe o endereco do cliente: ");
                    gets(fatec.endereco);

                    printf("\n|Informe o RG do cliente: ");
                    gets(numstr);

                    fatec.rg = atoi(numstr);
                    fflush(stdin);

                    printf("\n|Informe o cpf do cliente: ");
                    gets(numstr);

                    fatec.cpf = atoi(numstr);

                    printf("\n|Informe o salario do cliente: R$ ");
                    gets(numstr);
                    fflush(stdin);

                    fatec.salario = atof(numstr);

                    fwrite(&fatec, sizeof(fatec),1,fptr);

                    printf("\n> Deseja continuar o cadastro [S] - SIM [N] - NAO: ");

            }while(getchar() == 's' || getchar() == 'S');

            fclose(fptr);
            system("cls");
            main();
        }
}
void consulta()
{
    FILE * file;
    cliente fatec;

    file = fopen("arquivo", "rb");

    if(file == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("------CONSULTA-----\n\n");

        while (fread(&fatec, sizeof(fatec), 1, file))
        {
            printf("|Codigo: %d\n", fatec.codigo);
            printf("|Nome: %s\n", fatec.nome);
            printf("|Sobrenome: %s\n", fatec.sobrenome);
            printf("|RG: %d\n", fatec.rg);
            printf("|CPF: %d\n", fatec.cpf);
            printf("|Salario: R$ %.2f\n", fatec.salario);
            printf("|Endereco: %s\n\n", fatec.endereco);
            printf("\n");
        }
        fclose(file);

        system("pause");
        system("cls");

        main();
    }
}

void pesquisar()
{
    bool nice = false;
    char pesquisa[20];
    int k = 0;

    FILE * receba;

    cliente fatec;

        receba = fopen("arquivo", "rb");

            if(receba == NULL)
            {
                printf("\nErro ao abrir o arquivo\n");
                system("pause");
                system("cls");
                main();
            }
            else
            {
                system("cls");
                printf("-----PESQUISA-----\n");

                printf("\nInforme o nome do cliente: ");
                gets(pesquisa);
                fflush(stdin);
            }

                while(fread(&fatec, sizeof(fatec),1, receba))
                {
                    k++;

                    if(strcmp(pesquisa, fatec.nome) == 0)
                    {
                        printf("\n> Sobre  o cliente: %s", fatec.nome);
                        printf("\n|O registro foi encontrado na posicao: %d\n\n", k);
                        printf("|Codigo: %d\n", fatec.codigo);
                        printf("|Nome: %s\n", fatec.nome);
                        printf("|Sobrenome: %s\n", fatec.sobrenome);
                        printf("|RG: %d\n", fatec.rg);
                        printf("|CPF: %d\n", fatec.cpf);
                        printf("|Salario: R$ %.2f\n", fatec.salario);
                        printf("|Endereco: %s", fatec.endereco);

                        nice = true;
                        printf("\n\n");
                        system("pause");
                        system("cls");
                        main();
                        break;
                    }
                }
                if(nice)
                {
                    fclose(receba);
                }
                else
                {
                    printf("\nRegistro nao foi encontrado no arquivo\n");
                    system("pause");
                    system("cls");
                    main();
                }


}
int main()
{
    int escolha;
    do{


    printf("> As operacoes disponiveis:\n\n");
    printf("\t[1] - CADASTRO\n");
    printf("\t[2] - CONSULTA\n");
    printf("\t[3] - ALTERAR\n");
    printf("\t[4] - PESQUISA\n");
    printf("\t[5] - SAIR\n\n");
    printf("|Digite o que deseja: ");
    scanf("%d", &escolha);
    fflush(stdin);



        switch(escolha)
        {
            case 1:

                inserir();

                break;

            case 2:

                consulta();

                break;

            case 3:

                alterar();

                break;

            case 4:

                pesquisar();

                break;

            default:

                printf("\n> Digite um numero valido!\n\n");
                system("pause");
                system("cls");
   }



        }while(escolha != 5);

}
