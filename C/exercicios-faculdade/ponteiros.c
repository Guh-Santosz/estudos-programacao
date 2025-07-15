#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>

void menu()
{
	printf("\t----'Cadastro de alunos'----\n\n");
}
int main()
{
	typedef struct no
	{
		int ra;
		char nome[20];
		int idade;
	}no;

	int quantidade;

	menu();

	printf("> Digite a quantidade de alunos que deseja cadastrar: ");
	scanf("%d", &quantidade);
	fflush(stdin);

	system("cls");

	struct no *pnt[quantidade];

		for(int i = 0; i < quantidade; i++)
		{
			pnt[i] = NULL;
			pnt[i] = (no*)malloc(sizeof(no));

			menu();

			printf("|Digite o nome do(a) aluno(a) %d: ", i + 1);
			fgets(pnt[i]->nome, 20, stdin);
			fflush(stdin);

			pnt[i]->nome[strcspn(pnt[i]->nome, "\n")] = '\0';
			pnt[i]->nome[0] = toupper(pnt[i]->nome[0]);

			printf("\n|Digite o RA do(a) aluno(a) %s: ", pnt[i]->nome);
			scanf("%d", &pnt[i]->ra);
			fflush(stdin);

			printf("\n|Digite a idade do(a) aluno(a) %s: ", pnt[i]->nome);
			scanf("%d", &pnt[i]->idade);
			fflush(stdin);

			printf("\n");
			system("pause");
			system("cls");
		}
			printf("\t----'Exibindo dados'----\n\n");

			for(int i = 0; i < quantidade; i++)
			{
				printf("|RA|:...%d", pnt[i]->ra);
				Sleep(1000);
				printf("\n|NOME|:...%s", pnt[i]->nome);
				Sleep(1000);
				printf("\n|IDADE|:...%d\n\n", pnt[i]->idade);
				Sleep(1000);
			}
}