#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct	pessoa 
{
	char nome[30];
	char sexo;
	char cor;
	float altura;
	int peso;
};

int main( int argc, char** argv )
{

//	struct pessoa modelo ;// = {"Jase Maria",'M','A',1.60,63};

	FILE *fp;
	if((fp = fopen("dados.txt","a+")) == NULL)
	{
			printf(" Não foi possível abrir o arquivo.\n Verifique se o arquivo existe ou se tem permissão para lê-lo.\n");
			exit(1);
	}else 
	{
		char ch;
		char nome[30];
		int i;
		for (i = 0; 1  ; i++)
		{
 			ch = getc(fp);
			if (ch == ';') 
			{
				nome[i] = '\0';
				break;
			}
			nome[i] = ch;

		}// fim do for i
		printf("%s\n",nome);

	}
	fclose(fp);
	return 0;
}// fim da função main 
