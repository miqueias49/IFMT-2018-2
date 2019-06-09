#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alinha_nome (char *nome);
void concatena(int tamanho_destino,char *destino, char *src);
void minera_dados(FILE *fp);

int main( int argc, char** argv )
{


	char nome[30];
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
			int test = 0;
			printf("digite um numero negativo para sair:\n");
			scanf("%d", &test);
			fflush(stdin);
			__fpurge(stdin);
			if (test < 0) 
			{
				break;
			}

			//////////////////////////////////////////////////
			//
			printf("Cadastramento dos modelos\n");
			printf("Nome:\n");

//			scanf("%30s",nome);
//
			gets(nome);

//			fflush(stdin);
//			__fpurge(stdin);
			
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
			//
			//////////////////////////////////////////////////


			alinha_nome(nome); 

			concatena(50,full, nome);
			concatena(50,full, sexo);
			concatena(50,full, cor);
			concatena(50,full, alt);
			concatena(50,full, Peso);

			fprintf(fp,"%s\n", full);


		} // fim while

		rewind(fp);
		
	}

	rewind(fp);


	minera_dados(fp);

	fclose(fp);
	return 0;
}// fim da função main 

//////////////////////////////////////////////////

void alinha_nome (char *nome)//
{

//	char swap[30];
	int tam, i, j;
	for ( i = 0; i < 30 ; i++) // varre o vetor
	{
		if (nome[i] == '\0' ) // testa se caracter e nulo, se nulo executa o if
		{
			j = i;
			while(j) 
			{
				if (j == 30) 
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

//////////////////////////////////////////////////

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

//////////////////////////////////////////////////

void minera_dados(FILE *fp)
{
	char linha[50];

	FILE *men, *woman;
	if ((men = fopen("homens.bin","ab+")) == NULL) 
	{
		printf("Não foi posível abrir homens.bin\n");
	}
	
	if ((woman = fopen("mulheres.bin","ab+")) == NULL) 
	{
		printf("Não foi posível abrir mulheres.bin\n");
	}

	while (1)
	{
		fgets(linha, 50, fp);
		if ( feof(fp))
		{
			break;
		}
		if (linha[30] == 'M') 
		{
			fputs(linha,men);	
		}else 
		if (linha[30] == 'F') 
		{
			fputs(linha, woman);	
		}
	}

	fclose(men);
	fclose(woman);
}

//////////////////////////////////////////////////
