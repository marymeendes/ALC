

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
			} 
			else if(j == i+1)
				{
					if(matriz[i][j] == 0)
						verifica = 0;
				}
		 		else if(j == i-1)
					{
						if(matriz[i][j] == 0)
						verifica = 0;
					}
					else
					{
						if(matriz[i][j] != 0)
							verifica = 0;
					}
	  	}	 
	}
	
	if(verifica)
		printf("A matriz inserida eh matriz tridiagonal.\n");
	else
		printf("A matriz inserida nao eh matriz tridiagonal.\n");
}

/*void ehOrtogonal(int ordem, int matriz[ordem][ordem]){
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
}*/

//codigo para zerar vetores
/*void zeros_v(int ordem, int mult[ordem])
{
	int i;

	for(i = 0; i < dim; i++)
	{
		mult[i] = 0;
	}
}*/

//codigo para zerar matrizes
void zeros_m(int ordem, int matriz[ordem][ordem])
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

//codigo para imprimir matrizes
void show_m(int ordem, int matriz[ordem][ordem])
{
	int i, j;

	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			printf("%d ", matriz[i][j]);
		}

		printf("\n");
	}
}

/*void multiplicacaoMatrizVetor(int ordem, int matriz[ordem][ordem], int vetor[ordem])
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
}*/

/*void multiplicaTransposta (int ordem, int matriz[ordem][ordem]){
	int i, j, h, soma = 0;
	int mTransposta[ordem][ordem];
	int mult[ordem][ordem];
	
	zeros_m(ordem, mTransposta);
	zeros_m(ordem, mult);
	
	for (i=0; i < ordem; i++){
		for (j=0; j < ordem, j++){
			mTransposta[j][i] = matriz[i][j];
		}
	}
	
	for(i = 0; i < ordem; i++){
		
		for(j = 0; j < ordem; j++){
			
			for(h = 0; h < ordem; h++){
				soma += matriz[i][h] * mTransposta[h][j];
			}

			mult[i][j] = soma;
			soma = 0;
		}

	}
		
}*/

void comparaTransposta (int ordem, int matriz[ordem][ordem]){
	int i, j, h, verifica = 1;
	int mTransposta[ordem][ordem];
	
	zeros_m(ordem, mTransposta);
	
	//construindo a transposta
	for (i=0; i < ordem; i++){
		for (j=0; j < ordem; j++){
			mTransposta[j][i] = matriz[i][j];
		}
	}
	
	show_m(ordem, mTransposta);
	
	//comparando a transposta com a matriz original
	for(i = 0; i < ordem; i++){
		
		for(j = 0; j < ordem; j++){
			
			if(matriz[i][j] != mTransposta[i][j])
				verifica == 0;
		}
	}
	
	if(verifica)
		printf("A matriz inserida eh simetrica.");
	else
		printf("A matriz inserida nao eh simetrica.");
}

/*void ehPositivaDefinida(int ordem, int matriz[ordem][ordem]){
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
}*/

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
		
		ehTridiagonal(ordem, matriz);
		comparaTransposta(ordem, matriz);
		
	}	
	return 0;
}
