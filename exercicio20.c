/*
20) Construa um algoritmo que receba p vetores de tamanho p. Compare as normas de cada
vetor. Calcule a norma 1, norma 2 e norma infinito. Calcule a distância entre quaisquer desses
dois vetores usando a norma 1, 2 e infinito. Construa um algoritmo que calcule o produto
interno e o do ângulo entre quais quer desses dois vetores x e y. Construa um algoritmo que
calcule a norma 1, norma infinito e norma de Frobenius de matrizes na qual cada vetor
representa vetor representa uma linha. Calcule a calcule a distância entre quaisquer dessas
matrizes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int p;
	
	printf("Digite a quantidade p de vetores e do tamanho deles: ");
	scanf("%d", &p);
	
	float vetores[p][p];
	
	printf("\nDigite abaixo o valor de cada  campo dos vetores:");
	
	int i, j, k;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			printf("\nVetor %d, campo %d, valor: ", i , j);
			scanf("%f", &vetores[i][j]);
		}
	}
	
	// NORMA 1
	
	int num = 1;
	float somatorio = 0, norma = 0, modulo = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			modulo = vetores[i][j];
			if(modulo < 0)
				modulo *= -1;
			somatorio += (pow(modulo,num));
		}
		norma = pow(somatorio, 1/num);
		printf("\nVetor %d, NORMA %d = %f\n", i, num, norma);
		norma = 0;
		somatorio = 0;
		modulo = 0;
	}
	
	// NORMA 2
	
	num = 2;
	somatorio = 0;
	norma = 0;
	modulo = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			modulo = vetores[i][j];
			if(modulo < 0)
				modulo *= -1;
			somatorio += (pow(modulo,num));
		}
		norma = sqrt(somatorio);
		printf("\nVetor %d, NORMA %d = %f\n", i, num, norma);
		norma = 0;
		somatorio = 0;
		modulo = 0;
	}
	
	// NORMA INFINITO
	norma = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			if(vetores[i][j] > norma)
				norma = vetores[i][j];
		}
		if(norma < 0)
			norma *= -1;
		printf("\nVetor %d, NORMA INFINITO = %f\n", i, norma);
		norma = 0;
	}
	
	//DISTÂNCIA ENTRE 2 VETORES COM NORMA 1
	
	num = 1;
	somatorio = 0;
	norma = 0;
	modulo = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			if(i != j){
				for(k = 0; k < p; k++) {
					modulo = vetores[i][k] - vetores[j][k];
					if(modulo < 0)
						modulo *= -1;
					somatorio += (pow(modulo,num));
				}
				norma = pow(somatorio, 1/num);
				printf("\nA distancia do vetor %d para o vetor %d com norma %d eh: %f\n", i, j, num, norma);
				norma = 0;
				somatorio = 0;
				modulo = 0;
			
			}
		}
	}
	
	//DISTÂNCIA ENTRE 2 VETORES COM NORMA 2
	
	num = 2;
	somatorio = 0;
	norma = 0;
	modulo = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			if(i != j){
				for(k = 0; k < p; k++) {
					modulo = vetores[i][k] - vetores[j][k];
					if(modulo < 0)
						modulo *= -1;
					somatorio += (pow(modulo,num));
				}
				norma = sqrt(somatorio);
				printf("\nA distancia do vetor %d para o vetor %d com norma %d eh: %f\n", i, j, num, norma);
				norma = 0;
				somatorio = 0;
				modulo = 0;
			
			}
		}
	}
	
	//DISTÂNCIA ENTRE 2 VETORES COM NORMA INFINITO
	
	norma = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			if(i != j){
				for(k = 0; k < p; k++) {
					if((vetores[i][k] - vetores[j][k]) > norma)
						norma = vetores[i][k] - vetores[j][k];
				}
				if(norma < 0)
					norma *= -1;
				printf("\nA distancia do vetor %d para o vetor %d com norma infinito eh: %f\n", i, j, norma);
				norma = 0;
			}
		}
	}
	
	//PRODUTO INTERNO E ANGULO
	
	float produto = 0, angulo = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			if(i != j){
				for(k = 0; k < p; k++) {
					produto += vetores[i][k] * vetores[j][k]; 
				}
				angulo = acos(produto);
				printf("\nO produto entre os vetores %d e %d eh %f, e o seu angulo eh %f\n", i, j, produto, angulo);
				angulo = 0;
				produto = 0;
			
			}
		}
	}
	
	//NORMA 1 DE MATRIZ
	
	modulo = 0;
	somatorio = 0;
	float max = 0;
	for(i = 0; i < p; i++){
		for(j = 0; j < p; j++){
			modulo = vetores[j][i];
			if(modulo < 0)
				modulo *= -1;
			somatorio += modulo;
		}
		if(somatorio > max)
			max = somatorio;
		somatorio = 0;
	}
	
	printf("\nNorma 1 da matriz formada: %f\n", max);
	
	// NORMA INFINITO DE MATRIZ
	norma = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			if(vetores[i][j] > norma)
				norma = vetores[i][j];
		}
		if(norma < 0)
			norma *= -1;
	}
	printf("\nNorma infinito da matriz formada: %f\n", i, norma);
	
	//NORMA DE FROBENIUS DE MATRIZ
	
	modulo = 0;
	somatorio = 0;
	for(i = 0; i < p; i++){
		for(j = 0; j < p; j++){
			modulo = vetores[j][i];
			if(modulo < 0)
				modulo *= -1;
			modulo = pow(modulo, 2);
			somatorio += modulo;
		}
	}
	
	somatorio = sqrt(somatorio);
	printf("\nNorma Frobenius da matriz formada: %f\n", somatorio);
	
	//DISTANCIA DE MATRIZES
	
	float matriz[p][p];
	
	printf("\nDigite abaixo o valor de cada  campo das matrizes:");
	
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			printf("\nDigite o valor da matriz: [%d][%d]: ", i , j);
			scanf("%f", &matriz[i][j]);
		}
	}
	
	norma = 0;
	for(i = 0; i < p; i++) {
		for(j = 0; j < p; j++) {
			if(vetores[i][j] > norma)
				norma = vetores[i][j] - matriz[i][j];
		}
		if(norma < 0)
			norma *= -1;
	}
	printf("\nDistancia da primeira para a segunda matriz: %f\n", norma);
	
	return 0;
}
