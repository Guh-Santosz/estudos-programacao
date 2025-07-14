#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	typedef struct no
	{
		int ra;
		char nome[20];
		struct no *next;
	}no;

	struct no *a, *b, *c;
	char getnome[20];
	int k = 0, achou;

	a = NULL;
	b = NULL;
	c = NULL;

		for(int i = 0; i < 5; i++)
		{
			if(c == NULL)
			{
				a = (no*)malloc(sizeof(no));

				printf("\n|Digite o RA: ");
				scanf("%d", &a->ra);
				fflush(stdin);

				printf("\n|Digite o nome: ");
				fgets(a->nome, 20, stdin);
				fflush(stdin);

				b = a;
				c = a;

				a->next = NULL;
				system("cls");
			}
			else
			{
				a = (no*)malloc(sizeof(no));

				printf("\n|Digite o RA: ");
				scanf("%d", &a->ra);
				fflush(stdin);

				printf("\n|Digite o nome: ");
				fgets(a->nome, 20, stdin);
				fflush(stdin);

				b->next = a;
				b = a; 
				a->next = NULL;
				system("cls");
			}
		}
			a = c;

			system("cls");

			while(a != NULL)
			{
				k++;
				printf("\n> Numero do registro: %d", k);
				printf("\n> Numero do RA: %d", a->ra);
				printf("\n> Nome: %s\n", a->nome);
				a = a->next;
			}
				system("pause");
			b = c;
     		k = 0;
     		printf("\n Informe o nome a ser consultado");
     		scanf("%s", getnome);

     		achou =0;
 
     		while(b != NULL)
     		{
         		k++;
 
         		if(strcmp(getnome, b->nome)==0)
         		{
           			printf("\n O nome se encontrado na Lista seguinte %d posição  \n",k);
            		system("pause");
            		break;
            		achou = 1;
         		}
         		b = b->next;
     }
 
     if(achou == 0)
     {
         printf("\n Registro não consta na Lista \n");
         system("pause");
     }
}
