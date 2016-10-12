//questao 02 c)
// 2) a) Construa um algoritmo em C que faça a multiplicação de uma matriz de tamanho mxn por
// um vetor de tamanho nx1. Insira no seu código o cálculo do número total de flops.
// 
// b) Construa um algoritmo em C que faça a multiplicação de uma matriz A(mxn) por uma
// matriz B(nxk) e que calcule o número total de flops.
//
// c) Construa um algoritmo que calcule o determinante de uma matriz de ordem menor ou igual
// a 4.

#include <stdio.h>
#include <math.h>

#define max 4

//FUNCAO PARA ZERAR UM VETor
void zeros_v(int dim, int mult[dim])
{
	int i;

	for(i = 0; i < dim; i++)
	{
		mult[i] = 0;
	}
}

void multiplicacaoMatrizVetor(int dim, int matriz[dim][dim], int vetor[dim])
{
	int i, j, mult[max], flops;

	flops = 0;

	zeros_v(dim, mult);
	
	for(i = 0; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			mult[i] += matriz[i][j]*vetor[j];
		}

		flops += 5;
		printf("%d\n", mult[i]);
	}

	printf("Numero de flops: %d\n", flops);
}

// b) Construa um algoritmo em C que faça a multiplicação de uma matriz A(mxn) por uma
// matriz B(nxk) e que calcule o número total de flops.

void MultiplicarMatrizes(int m, int n, int l, int k, int matrizA[m][n], int matrizB[l][k])
{
	int i, j, h, flops, mult[m][k], soma = 0;


	flops = 0;

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < k; j++)
		{
			for(h = 0; h < l; h++)
			{
				soma += matrizA[i][h] * matrizB[h][j];
			}

			mult[i][j] = soma;
			soma = 0;
		}

		flops += 5;
	}

	printf("Resultado da multiplicacao das matrizes:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < k; j++)
		{
			printf("%d ", mult[i][j]);
		}

		printf("\n");
	}
	printf("Numero de flops: %d\n", flops);
}

int main(void)
{
	int i, j;
	int dim;

	printf("\nPrimeira Prova de Implementacao de Algebra Linear Computacional 2016.2\n\n");

	printf("Questao 02 a)\n");

	printf("A dimensão da matriz é: ");
	scanf("%d", &dim);

	int matriz[dim][dim];

	if(dim > 4)
	{
		printf("Inserir dimensão menor ou igual a 4.\n");
		return 0;
	}
	
	int vetor[dim];

	printf("Insira a matriz:\n");
	for(i = 0; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			scanf("%d", &matriz[i][j]);
		}	
	}

	printf("Insira o vetor:\n");
	for(i = 0; i < dim; i++)
	{
		scanf("%d", &vetor[i]);
	}
	printf("Resultado: \n");
	multiplicacaoMatrizVetor(dim, matriz, vetor);

	
	// b) Construa um algoritmo em C que faça a multiplicação de uma matriz A(mxn) por uma
	// matriz B(nxk) e que calcule o número total de flops.
	printf("\nQuestao 02 b)\n");

	int m, n, l, k;

	printf("Dimensao da matriz A: ");
	scanf("%d x %d", &m, &n);

	printf("Dimensao da matriz B: ");
	scanf("%d x %d", &l, &k);

	int matrizA[m][n], matrizB[l][k];

	if(l != n)
	{
		printf("Impossivel calcular produto entre as matrizes A e B\n");
		return 0;
	}

	printf("Matriz A:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &matrizA[i][j]);
		}
	}

	printf("Matriz B:\n");
	for(i = 0; i < l; i++)
	{
		for(j = 0; j < k; j++)
		{
			scanf("%d", &matrizB[i][j]);
		}
	}

	printf("Resultado:\n");
	MultiplicarMatrizes(m, n, l, k, matrizA, matrizB);

	printf("\nQuestao 02 c)\n");

	printf("Insira a dimensao da matriz:\n");
	scanf("%d", &dim);

	if(dim > 4)
	{
		printf("Por favor, insira um valor menor ou igual a 4.\n");
		return 0;
	}	

	printf("Insira a matriz: \n");

	for(i = 0; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			scanf("%d", &matriz[i][j]);
		}
	}

	int det;
	
	if(dim == 1)
	{
		det = matriz[0][0];
	}

	if(dim == 2)
	{
		det = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	}

	if(dim == 3)
	{
		det  = ((matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1] * matriz[1][2] * matriz[2][0]) + (matriz[0][2] * matriz[1][0] * matriz[2][1])) - ((matriz[0][2] * matriz[1][1] * matriz[2][0]) + (matriz[0][0] * matriz[1][2] * matriz[2][1]) + (matriz[0][1] * matriz[1][0] * matriz[2][2]));
	}

	if(dim == 4)
	{	
		det = (matriz[0][0] * ((matriz[1][1]*matriz[2][2]*matriz[3][3]) + (matriz[1][2]*matriz[2][3]*matriz[3][1]) + (matriz[1][3]*matriz[2][1]*matriz[3][2])
          - ((matriz[1][2]*matriz[2][1]*matriz[3][3]) + (matriz[1][1]*matriz[2][3]*matriz[3][2]) + (matriz[1][3]*matriz[2][2]*matriz[3][1]) )))
         
          + ( (-matriz[0][1]) * ((matriz[1][0]*matriz[2][2]*matriz[3][3]) + (matriz[1][2]*matriz[2][3]*matriz[3][0]) + (matriz[1][3]*matriz[2][0]*matriz[3][0])
          - ((matriz[1][2]*matriz[2][0]*matriz[3][3]) + (matriz[1][0]*matriz[2][3]*matriz[3][2]) + (matriz[1][3]*matriz[2][2]*matriz[3][0]) )))
         
          + ( matriz[0][2] * ((matriz[1][0]*matriz[2][1]*matriz[3][3]) + (matriz[1][1]*matriz[2][3]*matriz[3][0]) + (matriz[1][3]*matriz[2][0]*matriz[3][1])
          - ((matriz[1][1]*matriz[2][0]*matriz[3][3]) + (matriz[1][0]*matriz[2][3]*matriz[3][1]) + (matriz[1][3]*matriz[2][1]*matriz[3][0]) )))
         
          + ((-matriz[0][3]) * ((matriz[1][0]*matriz[2][1]*matriz[3][2]) + (matriz[1][1]*matriz[2][3]*matriz[3][0]) + (matriz[1][3]*matriz[2][0]*matriz[3][1])
          - ((matriz[1][1]*matriz[2][0]*matriz[3][2]) + (matriz[1][0]*matriz[2][3]*matriz[3][1]) + (matriz[1][3]*matriz[2][1]*matriz[3][0]))));    
	
	}

	printf("O determinante da matriz e: %d\n", det);

	return 0;
}  
