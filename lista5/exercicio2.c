#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alinha_nome (char *nome);
void concatena(int tamanho_destino,char *destino, char *src);

int main( int argc, char** argv )
{


	char nome[30] = {"miqueias miranda"};
	char full[50];
	char sexo[2] = {"M"};
	char cor[2] = {"D"};
	float altura = 1.65;
	float peso = 63.2;
	char Peso[10];
	char alt[10];
	full[0] = '\0';
	


	FILE *fp;
	if((fp = fopen("dados.txt","a+")) == NULL)
	{
			printf(" Não foi possível abrir o arquivo.\n Verifique se o arquivo existe ou se tem permissão para lê-lo.\n");
			exit(1);
	}else 
	{	


		while(1)
		{

		printf("Cadastramento dos modelos\n");
		
		printf("Nome:\n");
		scanf("%s", nome);

		fflush(stdin);
		__fpurge(stdin);

		printf("sexo: (M/F)\n");
		scanf("%c", &sexo[0]);


		fflush(stdin);
		__fpurge(stdin);

		printf("Cor dos olhos:\n");
		printf("A / B / C /D\n");
		scanf("%c", &cor[0] );

		printf("Altura:\n");
		scanf("%f", &altura);

		printf("Peso:\n");
		scanf("%f", &peso);
		





		sprintf(alt,"%.2f",altura); // converte float em string
		sprintf(Peso,"%.1f", peso); // 


		alinha_nome(nome);
		

		concatena(50,full, nome);
		concatena(50,full, sexo);
		concatena(50,full, cor);
		concatena(50,full, alt);
		concatena(50,full, Peso);

		fprintf(fp,"%s\n", full);
		int test = 0;
		printf("digite um numero negativo para sair:\n");
		scanf("%d", &test);

		if (test < 0) 
		{
			break;
		}
		} // fim while

		rewind(fp);
		
		while (1)
		{
		
		char ch;

		while (1) 
		{

			ch = fgetc(fp);
			if (ch == '\n') 
			{
				break;
			}else 
			if (ch == EOF) 
			{
				break;
			}
			printf("%c", ch);
		}// fim do while 
		printf("\n");
		if ( ch == EOF) 
		{
			break;
		}
		
		}

	}
	fclose(fp);
	return 0;
}// fim da função main 

void alinha_nome (char *nome)//
{
	int tam, i, j;
	for ( i = 0; i < 30 ; i++) // varre o vetor
	{
		if (nome[i] == '\0' ) // testa se caracter e nulo, se nulo executa o if
		{
			j = i;
			while(j) 
			{
				if (j == 29) 
				{
					nome[j] = '\0';
					break;
				}
				nome[j] = ' ';
				j++;
			}// fim do for j 

		}
		tam++;

	}// fim do for i
}

void concatena(int tamanho_destino,char *destino, char *src)//
{
 	int /*tam,*/ i, j;

	j = 0;
	i = 0;

	while(1)
	{

		if (i == (tamanho_destino - 1)) 
		{
			break;
		}else 

		if (destino[i] == '\0') 
		{
			while(1)
			{

				if (src[j] != '\0') 
				{
					destino[i] = src[j];
					j++;
					i++;
				}else 
				{
					destino[i] = '\0';
					break;

				}

			}// fim do for j 
		}
		i++;
	}// fim do for i
}

