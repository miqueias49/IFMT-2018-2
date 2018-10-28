#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

	struct lista{
		char telefone[15];
		char cidade[30];
		int hora, minuto, segundo;
	};

	typedef struct lista LISTA;


int main( int argc, char** argv )
{
	FILE *arq1, *arq2;
	FILE *out1, *out2;

	LISTA lista1, lista2;

	if ((arq1 = fopen("lista1.txt","a+")) == NULL ) 
	{
		printf("Erro em abrir arquivo --> lista1.txt\n");
	}else 
	if ((arq2 = fopen("lista2.txt","a+")) == NULL ) 
	{
		printf("Erro em abrir arquivo --> lista2.txt\n");
	}else 
	if ((out1 = fopen("out1.txt","w+")) == NULL) 
	{
		printf("Erro em abrir arquivo --> out1.txt\n");
	}else 
	if ((out2 = fopen("out2.txt","w+")) == NULL) 
	{
		printf("Erro em abrir arquivo --> out2.txt\n");
	}
	else 
	{
//////////////////////////////////////////////////
// 
// 		Carga util do programa
//
// 		
		int item = 1;
		rewind(arq1);
		while (1) 
		{
			__fpurge(stdin);
			fscanf(arq1,"%s%s%d%d%d", lista1.telefone, lista1.cidade, &lista1.hora, &lista1.minuto, &lista1.segundo);
			if (feof(arq1)) 
			{

				rewind(arq2);
				while (1) 
				{	
					__fpurge(stdin);
					fscanf(arq2,"%s%s%d%d%d", lista2.telefone, lista2.cidade, &lista2.hora, &lista2.minuto, &lista2.segundo);
					if (feof(arq2)) 
					{
						break;
					}
					fprintf(out2,"%s %s %d %d %d\n", lista2.telefone, lista2.cidade, 0, 0, 0);
				}// fim do while 

				printf("Concluído.\n");
				break;
			}else 
			{
				printf("\nTestando %dº item da lista \n", item);
				printf("l1 > %s %s\n", lista1.telefone, lista1.cidade);

				rewind(arq2);
				while (1) 
				{
					__fpurge(stdin);

					fscanf(arq2,"%s%s%d%d%d", lista2.telefone, lista2.cidade, &lista2.hora, &lista2.minuto, &lista2.segundo);
					if (feof(arq2)) 
					{
						break;
					}

					printf("l2 > %s %s\n", lista2.telefone, lista2.cidade);

					if (!(strcmp(lista1.telefone, lista2.telefone)) && !(strcmp(lista1.cidade, lista2.cidade))) 
					{
						lista1.segundo += lista2.segundo;
						lista1.minuto += lista2.minuto;
						lista1.hora += lista2.hora;
						while (1) 
						{
							if (lista1.segundo > 59 ) 
							{
								lista1.segundo -= 60;
								lista1.minuto += 1;
							}else 
							if (lista1.minuto > 59 ) 
							{
								lista1.minuto -= 60;
								lista1.hora +=1;		
							}else 
							{
								break;
							}
						}// fim do while
					} 
				}// fim do while 
				fprintf(out1, "%s %s %d %d %d\n", lista1.telefone, lista1.cidade, lista1.hora, lista1.minuto, lista1.segundo);
				item++;
			}
		}// fim do while
	}


	rewind(out1);
	rewind(out2);
	rewind(arq1);
	rewind(arq2);
//////////////////////////////////////////////////
//	while (1) 
//	{
//		fscanf( out1 ,"%s %s %d %d %d", lista1.telefone, lista1.cidade, &lista1.hora, &lista1.minuto, &lista1.segundo);
//
//		if (feof(out1)) 
//		{
//			printf("asd\n");
//			break;
//		}
//
//		fprintf(arq1 ,"%s %s %d %d %d\n", lista1.telefone, lista1.cidade, lista1.hora, lista1.minuto, lista1.segundo);
//	}// fim do while 
//////////////////////////////////////////////////
	fclose(arq2);
	fclose(arq1);
	fclose(out1);
	fclose(out2);

	return 0;
}// fim da função main 
