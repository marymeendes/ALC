
/* Questão 1 - a) Algoritmo que recebe uma matriz de >=2 e verifica se ela é uma matriz de Vandermonde
b)Calcula norma de Frobenius, norma linha, norma coluna de A e produto interno entre a primeira linha e a segunda coluna, bem como o ângulo entre esses dois vetores.
c)Calcula o determinante da matriz inserida usando a fórmula específica para matrizes de Vandermonde
*/

#include <stdio.h>
#include <math.h>

int verificaVandermonde (int ordem, float matriz[ordem][ordem]){
	int i, j, verifica = 1;
	float aux;
	
	for(i = 0; i < ordem; i++){
		if(matriz[i][0] != 1){
			verifica = 0;
		}		
	}
		
	for(i = 0; i < ordem; i++)
	{
		aux = matriz[i][1];
				
		for(j = 1; j < ordem; j++)
	  	{
	   		if(matriz[i][j] != pow(aux, j)){
	   			verifica = 0;
			}
	  	}	 
	}
		
	return verifica;
}

void normaFrobenius(int ordem, float matriz[ordem][ordem]){
	float aux = 0;
	int i, j;
	float resultado;
	
	for(i = 0; i < ordem; i++)
	{ 
		for(j = 0; j < ordem; j++)
	  	{
	   		aux += pow(matriz[i][j], 2);
		}	 
	}
	resultado = sqrt(aux);
	
	printf("\n");
	
	printf("A norma de Frobenius da matriz inserida eh igual a: %f\n", resultado);
}

float modulo(float numero){
	if(numero > 0)
		return numero;
	else
		return -(numero);
}

void normaLinha(int ordem, float matriz[ordem][ordem]){
	
	int i, j;
	float aux = 0, maiorsoma = 0;
	
	for(i = 0; i < ordem; i++)
 	{
  		for(j = 0; j < ordem; j++)
		{
			aux += modulo(matriz[i][j]);
		}
		
		if(aux > maiorsoma)
		{
			maiorsoma = aux;
		}
		
		aux = 0;
  	}
  	
  	printf("A norma linha da matriz inserida eh igual a: %f\n", maiorsoma);
}

void normaColuna(int ordem, float matriz[ordem][ordem]){
		
	int i, j; 
	float aux = 0, maiorsoma = 0;
	
	for(i = 0; i < ordem; i++)
 	{
  		for(j = 0; j < ordem; j++)
		{
			aux += modulo(matriz[j][i]);
		}
		
		if(aux > maiorsoma)
		{
			maiorsoma = aux;
		}
		
		aux = 0;
  	}
  	
  	printf("A norma coluna da matriz inserida eh igual a: %f\n", maiorsoma);
}

float produtoInterno(int ordem, float matriz[ordem][ordem]){
	int i;
	float produtoria = 0;
	
	for(i = 0; i < ordem; i++)
	{
		produtoria += matriz[0][i] * matriz[i][1];
	}
	
	return produtoria;	
}

float moduloVetorLinha(int ordem, float matriz[ordem][ordem]){
	int i; 
	float modulo = 0;
	
	for(i = 0; i < ordem; i++)
	{
		modulo += pow(matriz[0][i], 2); 
	}
	
	return sqrt(modulo);	
}

float moduloVetorColuna(int ordem, float matriz[ordem][ordem]){
	int i; 
	float modulo = 0;
	
	for(i = 0; i < ordem; i++)
	{
		modulo += pow(matriz[i][1], 2); 
	}
	
	return sqrt(modulo);	
}

void anguloDe2Vetores(int ordem, float matriz[ordem][ordem]){
	float cossenoTeta = 0;
	
	cossenoTeta = (float)produtoInterno(ordem, matriz) / (moduloVetorLinha(ordem, matriz) * moduloVetorColuna(ordem, matriz));
	
	if(cossenoTeta == 0.866025)
		printf("Angulo entre os dois vetores eh igual a: 30º\n");
	else if(cossenoTeta == 0.707107)
		printf("Angulo entre os dois vetores eh igual a: 45º\n");
	else if(cossenoTeta == 0.5)
		printf("Angulo entre os dois vetores eh igual a: 60º\n");
	else if(cossenoTeta == 0)
		printf("Angulo entre os dois vetores eh igual a: 90º\n");
	else if(cossenoTeta == -1)
		printf("Angulo entre os dois vetores eh igual a: 180º\n");	
	else
		printf("Angulo entre os dois vetores eh igual ao arc cos(%f)\n", cossenoTeta);	
}

void determinanteVandermonde(int ordem, float matriz[ordem][ordem]){
	
	if(verificaVandermonde(ordem, matriz)){
		
		int i, j = 1, k;
		float produto = 1;
			
		for (i=1; i<ordem; i++){
			for(k=0; k<i; k++){
				produto *= (matriz[i][j] - matriz[k][j]);
			}		
		}
		
		printf("O determinante da matriz inserida eh: %f \n", produto);
	}else printf("Nao eh possivel calcular o determinante pela regra das matrizes de Vandermonde, pois a matriz nao eh de Vandermonde.");
}

int main(void)
{
	int ordem, i, j;
	
	printf("Digite a ordem da matriz:\n");
	scanf("%d", &ordem);
	
	if(ordem < 2)
		printf("A matriz a ser inserida nao pode ter ordem inferior a 2.\n");
	else
	{
		float matriz[ordem][ordem];
		
		printf("Insira a matriz: \n");
		
		for(i = 0; i < ordem; i++)
		{ 
			for(j = 0; j < ordem; j++)
		  	{
		   		scanf("%f", &matriz[i][j]);
			}	 
		}
		
		printf("----------- Resultado -----------\n");
			
		if(verificaVandermonde(ordem, matriz))	
			printf("A matriz inserida eh matriz de Vandermonde.\n");
		else
			printf("A matriz inserida nao eh matriz de Vandermonde.\n");	
		
		normaFrobenius(ordem, matriz);
		normaLinha(ordem, matriz);
		normaColuna(ordem, matriz);
		printf("O produto interno da 1a linha com a 2a coluna da matriz inserida eh igual a: %f \n", produtoInterno(ordem, matriz));
		anguloDe2Vetores(ordem, matriz);
		determinanteVandermonde(ordem, matriz);
		
	}	
	return 0;
}
