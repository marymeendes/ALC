//Algoritmo para a Questão 11 da lista de ALC
//Letras A, B e C
//Recebe uma matriz quadrada, a eleva ao quadrado calcula o traço da matriz resultante, exibindo o número de flops
//Verifica se a matriz é Ortogonal
//Escolhe, aleatoriamente, duas colunas distintas da matriz inserida e calcula o produto interno entre elas, também 
//exibindo o número de flops 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

///////////////PROTÓTIPOS////////////////////////

void show_m(int ordem, double matriz[ordem][ordem]);
void zeros_m(int ordem, double matriz[ordem][ordem]);
double calculaTraco(int ordem, double matriz[ordem][ordem]);
void quadradoMatrizQuadrada(int ordem, double matrizA[ordem][ordem]);
void produtoInterno(int ordem, double matriz[ordem][ordem]);
void makes_id(int ordem, double matriz[ordem][ordem]);
void ehOrtogonal(int ordem, double matriz[ordem][ordem]);

int main(void)
{
	int ordem, i, j;
	
	printf("Digite a ordem da matriz A (que deve ser quadrada):\n");
	scanf("%d", &ordem);
	
	if(ordem < 2)
		printf("A matriz a ser inserida nao pode ter ordem inferior a 2.\n");
	else
	{
		double matrizA[ordem][ordem];
		
		printf("Insira a matriz: \n");
		
		for(i = 0; i < ordem; i++)
		{ 
			for(j = 0; j < ordem; j++)
		  	{
		   		scanf("%lf", &matrizA[i][j]);
			}	 
		}
		printf("\n");
		printf("----------- Resultado -----------\n");
		printf("\n");
		
		quadradoMatrizQuadrada(ordem, matrizA);
		ehOrtogonal(ordem, matrizA);
		produtoInterno(ordem, matrizA);
		
	}	
	return 0;
}

///////////////////FUNÇÕES CITADAS NOS PROTÓTIPOS//////////////////////////

void show_m(int ordem, double matriz[ordem][ordem])
{
	int i, j;

	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			printf("%.2lf ", matriz[i][j]);
		}

		printf("\n");
	}
}

void zeros_m(int ordem, double matriz[ordem][ordem])
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

double calculaTraco(int ordem, double matriz[ordem][ordem]){
	int i, j; 
	double traco = 0;
		
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

void quadradoMatrizQuadrada(int ordem, double matrizA[ordem][ordem]){
	int i, j, X, Aux = 0;
	double matrizC[ordem][ordem];
	
	zeros_m(ordem, matrizC);
	
	for(i=0; i < ordem; i++)
	{
        for(j=0; j < ordem; j++)
        {
			for(X=0; X<ordem; X++)
            {
            	Aux += matrizA[i][X] * matrizA[X][j];
            }
            matrizC[i][j]=Aux;
            Aux=0;
        }
    }
    
	printf("Matriz A elevada ao quadrado: \n");
	show_m(ordem, matrizC);
	
	printf("Traco da matriz A ao quadrado eh igual a: %.1lf \n", calculaTraco(ordem, matrizC));
	
}

void produtoInterno(int ordem, double matriz[ordem][ordem]){
	int i, col1, col2, flops = 0;
	double produtoria = 0;
	
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
	
	printf("\nProduto Interno da coluna %d com a coluna %d eh igual a: %lf \n", col1+1, col2+1, produtoria);
	printf("Numero de flops necessarios para o calculo: %d\n", flops);	
}

void makes_id(int ordem, double matriz[ordem][ordem])
{
	int i, j;

	for(i = 0; i < ordem; i++)
	{
		for(j = 0; j < ordem; j++)
		{
			if (i == j)
				matriz[i][j] = 1;
			else
				matriz[i][j] = 0;	
		}
	}
}

void ehOrtogonal(int ordem, double matriz[ordem][ordem]){

	int i, j, X, Aux = 0, verifica = 1;
	double mTransposta[ordem][ordem];
	double matrizR[ordem][ordem];
	double matrizId[ordem][ordem];
	
	zeros_m(ordem, mTransposta);
	zeros_m(ordem, matrizR);
	makes_id(ordem, matrizId);
	
	//construindo a transposta
	for (i=0; i < ordem; i++){
		for (j=0; j < ordem; j++){
			mTransposta[j][i] = matriz[i][j];
		}
	}

	//multiplicando matriz por mTransposta
	for(i=0; i<ordem; i++)
	{
        for(j=0; j<ordem; j++)
        {
            matrizR[i][j]=0;
            
                for(X=0; X<ordem; X++)
                {
                	Aux += matriz[i][X] * mTransposta[X][j];
                }
                
            matrizR[i][j]=Aux;
            Aux=0;
        }
    }

    //comparando o resultado da multiplicação com a identidade	
	for(i = 0; i < ordem; i++){
		
		for(j = 0; j < ordem; j++){
			
			if(matrizR[i][j] != matrizId[i][j])
				verifica = 0;
		}
	}

	if(verifica)
		printf("\nA matriz inserida eh Ortogonal\n");
	else
		printf("\nA matriz inserida nao eh Ortogonal\n");

}


