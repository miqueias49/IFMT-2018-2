#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

FILE* data;

void db_add(char* tam, ... )//
{
	va_list lista;
	int ct = 1 , i;
	
	for ( i = 0; tam[i] != '\0'; i++)
	{
		if (tam[i] == '%') 
		{
			printf(" %d %c \n", ct,tam[i+1]);
			ct ++;
		}
	}

	if((data = fopen("estoque.txt","a+")) != NULL)
	{

	}else 
	{
		printf("falha em abrir arquivo\n");
	}

	printf("%d\n", ct);
	fclose(data);
}
		
void menu_1()
{
	system("clear");
	printf("+--------------------------------------------------------------+\n");
	printf("|                                                              |\n");
	printf("+--------------------------------------------------------------+\n");
	printf("|    Opcao                                                     |\n");
	printf("|                                                              |\n");
	printf("|      1  >  incluir produto                                   |\n");
	printf("|      2  >  consultar produto                                 |\n");
	printf("|      3  >  remover produto                                   |\n");
	printf("|                                                              |\n");
	printf("+--------------------------------------------------------------+\n");
}
void menu_2 ()//
{
	system("clear");
	printf("+--------------------------------------------------------------+\n");
//========================================================================================

//========================================================================================
	printf("+--------------------------------------------------------------+\n");
	printf("| 		1 - excluir | 2 - editar | 3 - menu principal          |\n");
	printf("+--------------------------------------------------------------+\n");
}
void menu_3()
{
	system("clear");
	printf("+--------------------------------------------------------------+\n");
//========================================================================================

//========================================================================================
	printf("+--------------------------------------------------------------+\n");
	printf("|                   1 - salvar | 2 - cancelar                  |\n");
	printf("+--------------------------------------------------------------+\n");
}
