//========================================================================================
//
// 1) 	Implementar uma busca sequencial em um vetor com 50 mil posicoes.
// 		
// 		a) gerar o vetor com numeros randomicos
// 		b) gerar randomicamente o numero para busca
// 		c) calcular o tempo de busca
// 		d) repetir a operacao 3 vezes e calcular o tempo medio
//
// 2)	Implementar uma busca binaria em um vetor com 50 mil posicoes.
// 		
// 		a) gerar o vetor com numeros randomincos
// 		b) ordenar vetor
// 		c) gerar numero randomico para busca
// 		d) calcular tempo de busca 
// 		e) repetir a operacao 3 vezes e calcular tempo medio
//
//========================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define	count 50

void popula_vet (int* data, int a);
int verifica(int* data,int a , int num);


int main( int argc, char** argv )
{
	int i;
	srand(time(NULL));
	int data[count];

	for ( i = 0; i < count; i++)
	{	
		data[i] = 0;
	}// fim do for i
	

	popula_vet(data,count);

	if(argc > 1)
	{

		if ( strcmp("-b",argv[1]) == 0 ) 
		{
			printf("binario\n\n");

		}else 
		if ( strcmp("-s",argv[1]) == 0) 
		{
			printf("sequencial\n\n");
		}else 
		{
			printf("opcao invalida\n");
		}
	}
	return 0;
}


void popula_vet (int* data, int a)//
{	
	int num ,i;
	for ( i = 0; i < a; i++)
	{
		while (1) 
		{
			num = rand() % a;

			if ( verifica(data,a,num) ) 
			{
				data[i] = num;
				break;
			}else 
			if (i == (a-1) ) 
			{
				break;
			}
		}// fim do while 
	}
}




  int verifica(int* data,int a , int num) //
{

	int i;
	for ( i = 0; i < a; i++)
	{
		if (data[i] == num)
		{
			return 0;
   		}
	}
	return 1;
}



int busca_sequencial()
{

}
