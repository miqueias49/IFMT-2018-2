#include <stdio.h>
#include <stdlib.h>

FILE* data;

int db_add(int* index, char* nome, float* qtd, float* preco )//
{
	if((data = fopen("estoque.txt","a+")) != NULL)
	{
		printf("%d %s %f %f\n", *index, nome, *qtd, *preco );
	}else 
	{
		printf("falha em abrir arquivo\n");
	}
	fclose(data);
	return 0;
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

