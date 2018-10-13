//////////////////////////////////////////////////
//
// Create by: Miqueias da Silva Miranda
//
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////
//
//	Prototipos de função
//
//////////////////////////////////////////////////
//
void urna(FILE *f);
void apuracao(FILE *f);
//
//////////////////////////////////////////////////
//
//////////////////////////////////////////////////
//
// 		ENUNCIADO EXECICIO 1
//
// 		Elabore um algoritmo, e o programa em C, para apurar o resultado de uma eleição que possua, no
//		máximo, 100 eleitores. Suponha que existam 5 candidatos cujos códigos de identificação são: 1, 2, 3, 4,5. 
//		Considere um arquivo texto (denominado “votos.txt”) que contém, em cada linha, um determinado voto
//		(um voto é representado pelo código de identificação do candidato). O programa deverá apresentar,
//		como resultado, o código de identificação e a quantidade de votos do candidato mais votado, o código de
//		identificação e a quantidade de votos do candidato menos votado e a quantidade de votos nulos (um
//		voto nulo é um voto cujo código de identificação é inválido).
//
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//
// Função principal
//
//////////////////////////////////////////////////
//
int main( int argc, char** argv )
{
	FILE *f;

	f = fopen("votos.txt","a+");	//	Abre o arquivo no modo apende
									//	se o arquivo existir ele salva o conteudo novo 
									//	preservando o conteudo antigo
									//
									//	CUIDADO
									//	O modo (a), serve apanas para escrita
									//	para ler e escrever use (a+). 
		
	if (f == NULL) // testa a 
	{
		printf(" O arquivo no pode ser aberto \n");
	}else 
	{
		system("clear");

		urna(f);	//	Chama a função Urna.

		rewind(f);	//	A função rewind(),  retorna o cursor de leitura 
					//	para o início do arquivo.
					//
					//	Esta é uma funação standard e pertence a biblioteca
					//	STDIO.H

		apuracao(f);//	Chama a função Apuracao.
	}
			
	fclose(f);	// fecha o Arquivo

	return 0;
}
//
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//
// funcao:	Urna
//
// descrição:	Responsavel pela coletas dos dados referente
//		as opções dos eleitores. Se o eleitor entrar com um
//		número diferente de qualquer número dos candidatos, será
//		considerado nulo.
//		Número negativos saem da função.
//
// protótipo:	void urna(FILE *f);		
//
//////////////////////////////////////////////////
//
void urna(FILE *f)// passando o ponteiro do arquivo
{


	while (1) 
	{
		
		printf("+----------------------------------------------+\n");
		printf("|     Eleições dos Sacanas 2018                |\n");
		printf("+----------------------------------------------+\n");
		printf("|  Candidato 1                                 |\n");
		printf("|  Candidato 2                                 |\n");
		printf("|  Candidato 3                                 |\n");
		printf("|  Candidato 4                                 |\n");
		printf("|  Candidato 5                                 |\n");
		printf("+----------------------------------------------+\n");
	
		int num;

		printf(">> "); //firula, cursor para indicação de  entrada de dados
		scanf("%d",&num);
		if (num < 0) 
		{
			break;
		}
		fprintf(f, "%d\n", num);
	}// fim do while 
}
//
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//
// Funçao:	Apuracao
//
// descrição:	Realiza a contagem dos votos, separando
//		entre os candidatos e nulos.
//		Apresenta em forma de contagem bruta de votos e 
//		em forma de percentagem.
//
//        -->	Esta função ainda está incompleta. | :P
//
// protótipo:	void apuracao(FILE *f);
//
//////////////////////////////////////////////////
//
void apuracao(FILE *f)//
{
	int num;
	int candidato1 = 0;
	int candidato2 = 0;
	int candidato3 = 0;
	int candidato4 = 0;
	int candidato5 = 0;
	int nulos = 0;
	int n_amostral = 0;

	//	Este while realiza a contagem dos votos
	while(1)
	{

		fscanf(f,"%d", &num);
		if (feof(f)) 
		{
			break;
		}else 
		{
			switch (num) 
			{
				case 1 :
					candidato1 ++;
					break;				
				case 2 :
					candidato2 ++;
					break;				
				case 3 :
					candidato3 ++;
					break;				
				case 4 :
					candidato4 ++;
					break;				
				case 5 :
					candidato5 ++;
					break;				
				default:
					nulos ++;
			}		
		}
		n_amostral++;
	}

		//////////////////////////////////////////////////
		//
		// calcula a percentagem dos votos
		//
		//////////////////////////////////////////////////
		//
		float candidato1_p = ((100*candidato1)/n_amostral);
		float candidato2_p = ((100*candidato2)/n_amostral);
		float candidato3_p = ((100*candidato3)/n_amostral);
		float candidato4_p = ((100*candidato4)/n_amostral);
		float candidato5_p = ((100*candidato5)/n_amostral);
		float nulos_p = ((100*nulos)/n_amostral);
		//
		//////////////////////////////////////////////////

	
	int maior = candidato1;

	if (candidato2 > maior ) maior = candidato2;
	if (candidato3 > maior ) maior = candidato3;
	if (candidato4 > maior ) maior = candidato4;
	if (candidato5 > maior ) maior = candidato5;

	
	printf("%d\n",maior);


	printf("\n");
	printf("+----------------------------------------------+\n");
	printf("|    Totalização dos votos                     |\n");
	printf("+----------------------------------------------+\n");
	printf("    Votos Validos: %d\n", n_amostral);
	printf("+----------------------------------------------+\n");

	printf("Candidato 1: %.0f%% \n      Votos Totais: %d\n\n", candidato1_p, candidato1);
	printf("Candidato 2: %.0f%% \n      Votos Totais: %d\n\n", candidato2_p, candidato2);
	printf("Candidato 3: %.0f%% \n      Votos Totais: %d\n\n", candidato3_p, candidato3);
	printf("Candidato 4: %.0f%% \n      Votos Totais: %d\n\n", candidato4_p, candidato4);
	printf("Candidato 5: %.0f%% \n      Votos Totais: %d\n\n", candidato5_p, candidato5);

	printf("+----------------------------------------------+\n");
	printf("Total Nulos: %.0f %% \nVotos: %d\n", nulos_p, nulos);
	printf("+----------------------------------------------+\n");

}
//
//////////////////////////////////////////////////
