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

#define	count 50000

void popula_vet (int* data, int a);

int verifica(int* data,int a , int num);



int busca_binaria(int* data, int contador, int chave );
int busca_sequencial(int* data, int contador, int chave);
void quickSort(int* data, int inicio, int fim);
int particiona(int* data, int inicio, int final);

int main( int argc, char** argv )
{

	srand(time(NULL)); // gera semente

	int i;
	int data[count], buscar;

	clock_t inicio,final;


	for ( i = 0; i < count; i++) // inicializa vetor
	{	
		data[i] = 0;
	}

	inicio = clock();
	popula_vet(data,count); // executa funcao 
	
	final = clock();
	printf("populacao completa\ntempo de execucao: %lu s\n", (final - inicio) / CLOCKS_PER_SEC );

	if(argc > 1)
	{
		buscar = rand() % count;

		if ( strcmp("-b",argv[1]) == 0 ) 
		{
			system("clear");
			printf("busca binaria\n");
			printf("%d\n",buscar);
			quickSort(data,0,count-1);
			printf("%d\n", busca_binaria(data, count, buscar));
			final = clock();

			printf("segundos %lu \n", (final - inicio) / CLOCKS_PER_SEC );
		
		}else 
		if ( strcmp("-s",argv[1]) == 0) 
		{
			system("clear");
			printf("sequencial\n");
			printf("%d\n",buscar);
			printf("%d\n", busca_sequencial(data, count, buscar));
		}else 
		{
			printf("opcao invalida\n");
		}
	}
	else 
	{
		printf("\n\nUse as seguintes opcoes\n");
		printf(" 	-b  executa busca binaria\n");
		printf(" 	-s  executa busca sequencial\n\n\n");
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

			if ( verifica(data, i,num) ) 
			{
				data[i] = num;
				break;
			}
		}
	}
}

  int verifica(int* data,int a , int num) // virifica se o numero ja exite
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

int busca_sequencial(int* data, int contador, int chave)//
{
	int i;
	 for ( i = 0; i < contador; i++)
	 {
	 	if (data[i] == chave)
		{
			return i;
		}
	 }
	 return -1;
}

int busca_binaria(int* data, int contador, int chave )
{
	int menor, maior, meio;

	menor = 0;

	maior = contador - 1;
	while (menor <= maior) 
	{
		meio = (maior + menor)/2;
		if (chave < data[meio]) 
		{
			maior = meio -1;
		}else 
		if (chave > data[meio]) 
		{
			menor = meio + 1;
		}else 
		{
			return meio;
		}

	} 
	return -1;
}

int particiona(int* data, int inicio, int final)
{
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = data[inicio];

	while (esq < dir) 
	{
		while (data[esq] <= pivo) 
		{
			esq++;
		}
		while (data[dir] > pivo) 
		{
			dir--;
		}
		if( esq < dir)
		{
			aux = data[esq];
			data[esq] = data[dir];
			data[dir] = aux;
		}
	}
	data[inicio] = data[dir];
	data[dir] = pivo;
	return dir;

}

void quickSort(int* data, int inicio, int fim)
{
	int pivo;
	if(fim > inicio)
	{
		pivo = particiona(data, inicio, fim);
		quickSort(data, inicio, pivo-1);
		quickSort(data, pivo+1, fim);
	}	
}


