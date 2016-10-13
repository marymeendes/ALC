//Algoritmo para a Questão 11 da lista de ALC
//Letras A e C
//Recebe uma matriz quadrada, a eleva ao quadrado calcula o traço da matriz resultante, exibindo o número de flops
//Escolhe, aleatoriamente, duas colunas distintas da matriz inserida e calcula o produto interno entre elas, também 
//exibindo o número de flops 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void show_m(int ordem, float matriz[ordem][ordem]);
void zeros_m(int ordem, float matriz[ordem][ordem]);
float calculaTraco(int ordem, float matriz[ordem][ordem]);
void quadradoMatrizQuadrada(int ordem, float matrizA[ordem][ordem]);
void produtoInterno(int ordem, float matriz[ordem][ordem]);

int main(void)
{
	int ordem, i, j;
	
	printf("Digite a ordem da matriz A (que deve ser quadrada):\n");
	scanf("%d", &ordem);
	
	if(ordem < 2)
		printf("A matriz a ser inserida nao pode ter ordem inferior a 2.\n");
	else
	{
		float matrizA[ordem][ordem];
		
		printf("Insira a matriz: \n");
		
		for(i = 0; i < ordem; i++)
		{ 
			for(j = 0; j < ordem; j++)
		  	{
		   		scanf("%f", &matrizA[i][j]);
			}	 
		}
		printf("\n");
		printf("----------- Resultado -----------\n");
		printf("\n");
		
		quadradoMatrizQuadrada(ordem, matrizA);
		produtoInterno(ordem, matrizA);
		
	}	
	return 0;
}

void show_m(int ordem, float matriz[ordem][ordem])
{
	int i, j;

	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			printf("%.2f ", matriz[i][j]);
		}

		printf("\n");
	}
}

void zeros_m(int ordem, float matriz[ordem][ordem])
{
	int i, j;

	for(i = 0; i < ordem; i++)
	{
		for(j = 0; j < ordem; j++)
		{
			matriz[i][j] = 0;
		}
	}
}

float calculaTraco(int ordem, float matriz[ordem][ordem]){
	int i, j; 
	float traco = 0;
		
	for(i=0; i < ordem; i++)
	{
        for(j=0; j < ordem; j++)
        {
        	if(i == j)
        		traco += matriz[i][j]; 
		}		
	}
		
	return traco;
}

void quadradoMatrizQuadrada(int ordem, float matrizA[ordem][ordem]){
	int i, j, X, Aux = 0, flops = 0;
	float matrizC[ordem][ordem];
	
	zeros_m(ordem, matrizC);
	
	for(i=0; i < ordem; i++)
	{
        for(j=0; j < ordem; j++)
        {
			for(X=0; X<ordem; X++)
            {
            	Aux += matrizA[i][X] * matrizA[X][j];
            	flops += 2;
            }
            matrizC[i][j]=Aux;
            Aux=0;
        }
    }
    
	printf("Matriz A elevado ao quadrado: \n");
	show_m(ordem, matrizC);
	
	printf("Traco da matriz A ao quadrado eh igual a: %.1f \n", calculaTraco(ordem, matrizC));
	printf("Numero de flops necessarios para elevar a matriz inserida ao quadrado: %d\n", flops);
	
}

void produtoInterno(int ordem, float matriz[ordem][ordem]){
	int i, col1, col2, flops = 0;
	float produtoria = 0;
	
	srand( (unsigned)time(NULL) );

	col1 = rand() % ordem;
    col2 = rand() % ordem; 

	while(col1 == col2){
    	col2 = rand() % ordem; 
	}
	
	for(i = 0; i < ordem; i++)
	{
		produtoria += matriz[i][col1] * matriz[i][col2];
		flops += 2;
	}
	
	printf("Produto Interno da coluna %d com a coluna %d eh igual a: %f \n", col1+1, col2+1, produtoria);
	printf("Numero de flops necessarios para o calculo: %d\n", flops);	
}