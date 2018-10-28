#include <stdio.h>
#include <stdlib.h>

char voto[1][100],candMaisVotado, candMenosVotado;

int i=1, j=1, votosCan1, votosCan2, votosCan3, votosCan4, votosCan5, votosNulos = 0, maisVotado, menosVotado,m,o;

/* Inicio das Funções */

char computarVoto(char n){
	
	/*Contagem de Votos */
	
	if(voto[i][j] == '1'){
		votosCan1 = votosCan1 +1;	
	}
	if(voto[i][j] == '2'){
		votosCan2 = votosCan2 +1;	
	}
	if(voto[i][j] == '3'){
		votosCan3 = votosCan3 +1;	
	}
	if(voto[i][j] == '4'){
		votosCan4 = votosCan4 +1;	
	}
	if(voto[i][j] == '5'){
		votosCan5 = votosCan5 +1;
	}
	if(voto[i][j] != '1' && voto[i][j] != '2' && voto[i][j] != '3' && voto[i][j] != '4' && voto[i][j] != '5'){
		votosNulos = votosNulos +1;
	}
}
	/*Comparação do MAIS Votado*/
int contagem1(int m){

	if(votosCan1 > votosCan2 && votosCan1 > votosCan3 && votosCan1 > votosCan4 && votosCan1 > votosCan5)
	{
		maisVotado = votosCan1;
		candMaisVotado = '1';
	}else
	if(votosCan2 > votosCan1 && votosCan2 > votosCan3 && votosCan2 > votosCan4 && votosCan2 > votosCan5)
	{
		maisVotado = votosCan2;
		candMaisVotado = '2';
	}else
	if(votosCan3 > votosCan1 && votosCan3 > votosCan2 && votosCan3 > votosCan4 && votosCan3 > votosCan5)
	{
		maisVotado = votosCan3;
		candMaisVotado = '3';
	}else
	if(votosCan4 > votosCan1 && votosCan4 > votosCan2 && votosCan4 > votosCan3 && votosCan4 > votosCan5)
	{
		maisVotado = votosCan4;
		candMaisVotado = '4';
	}else
	if(votosCan5 > votosCan1 && votosCan5 > votosCan2 && votosCan5 > votosCan3 && votosCan5 > votosCan4)
	{
		maisVotado = votosCan5;
		candMaisVotado = '5';
	}
}
		/*Comparação do MENOS Votado*/
	
int contagem2(int o){
	if(votosCan1 < votosCan2 && votosCan1 < votosCan3 && votosCan1 < votosCan4 && votosCan1 < votosCan5)
	{
		menosVotado = votosCan1;
		candMenosVotado = '1';
	}
	if(votosCan2 < votosCan1 && votosCan2 < votosCan3 && votosCan2 < votosCan4 && votosCan2 < votosCan5){
		menosVotado = votosCan2;
		candMenosVotado = '2';
	}
	if(votosCan3 < votosCan1 && votosCan3 < votosCan2 && votosCan3 < votosCan4 && votosCan3 < votosCan5){
		menosVotado = votosCan3;
		candMenosVotado = '3';
	}
	if(votosCan4 < votosCan1 && votosCan4 < votosCan2 && votosCan4 < votosCan3 && votosCan4 < votosCan5){
		menosVotado = votosCan4;
		candMenosVotado = '4';
	}
	if(votosCan5 < votosCan1 && votosCan5 < votosCan2 && votosCan5 < votosCan3 && votosCan5 < votosCan4){
		menosVotado = votosCan5;
		candMenosVotado = '5';
	}
	
}


/* Inicio do Programa */

void main(){	
	FILE *votos;
	votos = fopen("Votação.txt","w");
	if(votos == NULL){
			printf("ERRO AO ABRIR ARQUIVO!!!");
	}else{
		fprintf(votos,"\n || 1 - Candidato A || 2 - Candidato B || 3 - Candidato C || 4 - Candidato D || 5 - Candidato E ||");
		fprintf(votos,"\n###-----### Votos Computados ###-----###");
		for( i = 1 ; i <=5 ; i++){
			//fflush(stdin);
			printf("\n||1 - Candidato A||2 - Candidato B||3 - Candidato C||4 - Candidato D||5 - Candidato E||");
			printf("\n Digite o Codigo de Identificacao do candidato que deseja votar:");
			scanf(" %c", &voto[i][j]);

			fprintf(votos,"\n %c",voto[i][j]);
			/*system("cls");*/
			computarVoto(voto[i][j]);						
		}
		contagem1(m);
		contagem2(o);
		
		fprintf(votos,"\n###-----### Votos Computados ###-----###");		
		fprintf(votos,"\n Candidato 1 : %d",votosCan1);	
		fprintf(votos,"\n Candidato 2 : %d",votosCan2);
		fprintf(votos,"\n Candidato 3 : %d",votosCan3);
		fprintf(votos,"\n Candidato 4 : %d",votosCan4);
		fprintf(votos,"\n Candidato 5 : %d",votosCan5);
	
		fprintf(votos,"\n Candidato Mais Votado: Candidato %c com %d votos.", candMaisVotado,maisVotado);
		fprintf(votos,"\n Candidato Menos Votado: Candidato %c com %d votos.", candMenosVotado,menosVotado);
		fprintf(votos,"\n Votos Nulos: %d",votosNulos);
		
		fclose(votos);
	}
}	
