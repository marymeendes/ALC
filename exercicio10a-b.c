#include <stdio.h>
#include<math.h>

int main(void){
	
	int k, i, j, a = 0;
	
	printf("Entre com a dimensao.\n");
	
	scanf("%d", &k);
	
	int matriz[k][k];
	int vetorb[k];
	int Rt[k][k];
	
	printf("Entre com A.\n");
	
	for(i = 0; i < k; i++)
	{
		for(j = 0; j < k; j++)
		{
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Entre com o vetor b.\n");
	
	for(i = 0; i < k; i++)
	{
		scanf("%d", &vetorb[i]);
	}
	
	//ACHANDO R
	int n, l, verifica = 1;

	for(i=0; i < k; i++){

		for(n=0; n <= i-1; n++)
			matriz[i][i] -= pow(matriz[n][i], 2);

		if(matriz[i][i] <= 0){
			verifica = 0;
			printf("A matriz A nao eh positiva definida.\n");
			return verifica;
		}

		matriz[i][i] = sqrt(matriz[i][i]);

		for(j=i+1; j <= k; j++){
				
			for(n=0;n <= i-1; n++)
				matriz[i][j] -= (matriz[n][i]*matriz[n][j]); 

			matriz[i][j] /= matriz[i][i];
		}
		
		// l seria o j das colunas da matriz
		for (l=0; l < k; l++){
			if(i>l)
				matriz[i][l] = 0;
		}
	}
	
	//imprime R
	printf("\n");
	printf("-----Fator de Cholesky-----\n");
	for(i = 0; i < k; i++){
		for(j = 0; j < k; j++){
			printf("%d ", matriz[i][j]);
		}

		printf("\n");
	}
	
	//FAZENDO A T DE R
	
	for(i = 0; i < k; i++)
	{
		for(j = 0; j < k; j++)
		{
			Rt[i][j] = matriz[j][i];
		}
	}
	
	//Rt*R*x = b;
	//R*x = y;
	//Rt*y = b;
	
	
	//SUBSTITUICAO PRA FRENTE: Rt*y = b;
	
	int y[k];
	int contador = 0;
	
	for(i = 0; i < k; i++)
	{	
		for(j = 0; j < i; j++)
		{
			if(i == 0 && j == 0){
				y[i] = vetorb[i]/Rt[i][j];
			}
			
			else{
				contador = contador + (Rt[i][j]*y[j]);
			}
			 			 
		}
		
		y[i] = (vetorb[i]-contador)/Rt[i][i];
		contador = 0;

	}
	
	//SUBSTITUICAO PRA TRAS: R*x = y
	int x[k];
	
	contador = 0;
	
	for(i = 3; i >= 0; i--)
	{	
		for(j = 3; j > i; j--)
		{
			if(i == 3 && j == 3)
			{
				x[i] = y[i]/matriz[i][j];
			}
			
			else
			{
				contador = contador + (matriz[i][j]*x[j]);
			}	 			 
		}
		
		x[i] = (y[i]-contador)/matriz[i][i];
		contador = 0;

	}                                      
	
	printf("\n");
	printf("------Resultado por Cholesky-------\n");
	printf("x: ");
	
	for(i = 0; i < k; i++)
	{
		printf("%d ", x[i]);
	}
	
	return 0;
	
}
