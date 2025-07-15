#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
	char letter;
	struct no *next, *back;
}no;

struct no *new, *aux, *start; 

int main()
{
	new = NULL;
	aux = NULL;
	start = NULL;
	char word[20];
	int length, count = 0;

	printf("\t----'IDENTIFICADOR DE PALINDROMOS'----\n\n");
	printf("|Digite algo: ");
	fgets(word, 20, stdin);
	fflush(stdin);

	word[strcspn(word, "\n")] = '\0';

	length = strlen(word);

	if(length == 1)
	{
		system("cls");
		printf("> %s nao eh um palindromo\n", word);
	}
	else
	{
		for(int i = 0; i < length; i++)
		{
			new = (no*)malloc(sizeof(no));

			new->letter = word[i];

			if(start == NULL)
			{
				start = new;
				aux = new;
				new->next = NULL;
				new->back = NULL;
			}
			else
			{
				aux->next = new;
				new->back = aux;
				new->next = NULL;
				aux = new;
				start = new;
			}
		}

		new = start;

		while(new != NULL)
		{
			if(new->letter == word[count]) count++;
			new = new->back;
		}
	}

	system("cls");

	if(count == length) printf("> %s eh um palindromo\n", word);
	else printf("> %s nao eh um palindromo\n", word);

	return 0;
}