#include <stdio.h>
#include <math.h>

void show_m(int ordem, float matriz[ordem][ordem])
{
	int i, j;

	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			printf("%.1f ", matriz[i][j]);
		}

		printf("\n");
	}
}

int fatorCholesky(int ordem, float matriz[ordem][ordem]){
	int i, j, k, l, verifica = 1;

	for(i=0; i < ordem; i++){

		for(k=0; k <= i-1; k++)
			matriz[i][i] -= pow(matriz[k][i], 2);

		if(matriz[i][i] <= 0){
			verifica = 0;
			return verifica;
		}

		matriz[i][i] = sqrt(matriz[i][i]);

		for(j=i+1; j <= ordem; j++){
				
			for(k=0; k <= i-1; k++)
				matriz[i][j] -= (matriz[k][i]*matriz[k][j]); 

			matriz[i][j] /= matriz[i][i];
		}
		
		// l seria o j das colunas da matriz
		for (l=0; l < ordem; l++){
			if(i>l)
				matriz[i][l] = 0;
		}
	}

	show_m(ordem, matriz);

	return verifica;
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
		
		printf("Matriz positiva definida ou nao? %d\n", fatorCholesky(ordem, matriz));
				
	}	
	return 0;
}
