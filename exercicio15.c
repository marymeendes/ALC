
#include <stdio.h>
#include <math.h>

void ehTridiagonal(int ordem, int matriz[ordem][ordem]){
	int i, j, verifica = 1;
		
	for(i = 0; i < ordem; i++)
	{		
		for(j = 0; j < ordem; j++)
	  	{
	   		if(i == j)
			{
	   			if(matriz[i][j] == 0)
					verifica = 0;		
			} else if(j == i+1)
					{
						if(matriz[i][j] == 0)
							verifica = 0;
			} else if(j == i-1)
					{
						if(matriz[i][j] == 0)
						verifica = 0;
					}
	  	}	 
	}
	
	if(verifica)
		printf("A matriz inserida eh matriz tridiagonal.\n");
	else
		printf("A matriz inserida nao eh matriz tridiagonal.\n");
}

void ehOrtogonal(int ordem, int matriz[ordem][ordem]){
	int i, j, verifica = 1;
		
	for(i = 0; i < ordem; i++)
	{		
		for(j = 0; j < ordem; j++)
	  	{
	   		if(i == j)
			{
	   			if(matriz[i][j] == 0)
					verifica = 0;		
			} else if(j == i+1)
					{
						if(matriz[i][j] == 0)
							verifica = 0;
			} else if(j == i-1)
					{
						if(matriz[i][j] == 0)
						verifica = 0;
					}
	  	}	 
	}
	
	if(verifica)
		printf("A matriz inserida eh matriz tridiagonal.\n");
	else
		printf("A matriz inserida nao eh matriz tridiagonal.\n");
}

void zeros_v(int ordem, int mult[ordem])
{
	int i;

	for(i = 0; i < dim; i++)
	{
		mult[i] = 0;
	}
}

void zeros_m(int linhas, int colunas, int vetor[linhas][colunas])
{
	int i, j;

	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			vetor[i][j] = 0;
		}
	}
}

void multiplicacaoMatrizVetor(int ordem, int matriz[ordem][ordem], int vetor[ordem])
{
	int i, j, mult[ordem];

	zeros_v(ordem, mult);
	
	for(i = 0; i < ordem; i++)
	{
		for(j = 0; j < ordem; j++)
		{
			mult[i] += matriz[i][j]*vetor[j];
		}
		printf("%d\n", mult[i]);
	}
}

int transposta (int ordem, )

void ehPositivaDefinida(int ordem, int matriz[ordem][ordem]){
	int i, j, verifica = 1;
		
	for(i = 0; i < ordem; i++)
	{		
		for(j = 0; j < ordem; j++)
	  	{
	   		if(i == j)
			{
	   			if(matriz[i][j] == 0)
					verifica = 0;		
			} else if(j == i+1)
					{
						if(matriz[i][j] == 0)
							verifica = 0;
			} else if(j == i-1)
					{
						if(matriz[i][j] == 0)
						verifica = 0;
					}
	  	}	 
	}
	
	if(verifica)
		printf("A matriz inserida eh matriz tridiagonal.\n");
	else
		printf("A matriz inserida nao eh matriz tridiagonal.\n");
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
		int matriz[ordem][ordem];
		
		printf("Insira a matriz: \n");
		
		for(i = 0; i < ordem; i++)
		{ 
			for(j = 0; j < ordem; j++)
		  	{
		   		scanf("%d", &matriz[i][j]);
			}	 
		}
		
		printf("----------- Resultado -----------\n");
		
	}	
	return 0;
}
