#include <stdio.h>
#include <stdlib.h>

int main( int argc, char** argv )
{
	FILE *fp;
	if((fp = fopen("dados.txt","r")) == NULL)
	{
			printf(" Não foi possível abrir o arquivo.\n Verifique se o arquivo existe ou se tem permissão para lê-lo.\n");
			exit(1);
	}else 
	{
		char ch;

		do 
		{
			ch = getc(fp);
			if (ch == EOF) 
			{
				break;
			}
			printf("%c", ch );
		} while (1);


	}
	fclose(fp);
	return 0;
}// fim da função main 
