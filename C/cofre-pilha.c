#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Combinação correta: Esquerda, Direita, Esquerda, Direita

typedef struct pile
{
	bool lefOrRight;
	struct pile *next;
}pile;

struct pile *new, *top, *start;
bool userGuess[4];

int menu(int number)
{
	int choose = 1;

	do
	{	
		if(choose <= 0 || choose > 3)
		{
			system("cls");
			printf("\t---'SENHA DO COFRE'---\n\n");
			printf("> Numero invalido!\n\n");
			system("pause");
			system("cls");
		}

		printf("\t---'SENHA DO COFRE'---\n\n");

		printf("|Numero de escolhas: %d\n\n", 4 - number);

		printf("> Descubra a combinacao correta para o cofre, escolha 4 movimentos:\n\n");

		printf("[1] - Esquerda\n");
		printf("[2] - Direita\n");
		printf("[3] - Encerrar programa\n\n");

		printf("|:");
		scanf("%d", &choose);
		fflush(stdin);
	
	}while(choose != 1 && choose != 2 && choose != 3);

	return choose;
}
void createPile()
{
	for(int i = 0; i < 4; i++)
	{
		new = (pile*)malloc(sizeof(pile));

		if(start == NULL)
		{
			start = new;
			top = new;
			new->next = NULL;
		}
		else
		{
			top->next = new;
			top = new;
			new->next = NULL;
		}

		if(i % 2 == 0) new->lefOrRight = false;
		else new->lefOrRight = true;
	}
}

bool result()
{
	int i = 0, finalTest = 0;

	new = start;

	while(new != NULL)
	{	
		if(new->lefOrRight == userGuess[i]) finalTest++;
		i++;
		new = new->next;
	}

	if(finalTest == 4) return true;
	else return false;
}

int main()
{
	new = NULL;
	top = NULL;
	start = NULL;
	int choose;

	createPile();
	
	for(int i = 0; i < 4; i++)
	{
		system("cls");
		choose = menu(i);

		switch(choose)
		{
			case 1:

				userGuess[i] = false;
				break;

			case 2:

				userGuess[i] = true;
				break;

			case 3:

				system("cls");
				printf("\t---'SENHA DO COFRE'---\n\n");
				printf("> Programa encerrado\n\n");
				system("pause");
				return 0;
		}
	}

	system("cls");
	printf("\t---'RESULTADO'---\n\n");

	if(result())
	{
		printf("|Parabens, voce abriu o cofre!\n\n");
		system("pause");
		return 0;
	}
	else
	{
		printf("|Infelizmente voce nao conseguiu abrir o cofre\n\n");
		system("pause");
		return 0;
	}
}