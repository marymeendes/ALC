#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	int i, j, ordem, k = 0;
	
	printf("Informe a ordem da matriz: \n");
	scanf("%d", &ordem);
	
	float matriz[ordem][ordem];
	float id[ordem][ordem];
	float pivo = 0, p = 0, m = 0;
	
	//construindo a identidade
	for(i=0; i < ordem; i++){
		for(j=0; j < ordem; j++){
			if(i == j)
				id[i][j] = 1;
			else
				id[i][j] = 0;
		}
	}
	
	//recebendo a matriz
	printf("Insira a matriz: \n");
	
	for(i=0; i < ordem; i++){
		for(j=0; j < ordem; j++){
			scanf("%f", &matriz[i][j]);	
		}
	}
	
	//imprimindo a matriz recebida
	printf("Matriz Original: \n");
	show_m(ordem, matriz);
	
	//calculando a inversa
	for(j=0; j < ordem; j++){
		
		pivo = matriz[j][j];
		//p = pivo/pivo;
		for(k=0; k < ordem; k++){
			matriz[j][k] = matriz[j][k] / pivo; 
			id[j][k] = id[j][k] / pivo; 
		}
		
		for(i=0; i < ordem; i++){
			if(i != j){
				m = matriz[i][j];
				
				for(k=0; k < ordem; k++){
					matriz[i][k] = matriz[i][k] - (m * matriz[j][k]); 
					id[i][k] = id[i][k] - (m * id[j][k]); 
				}
			}		
		}
	}
	
	//Resultados
	
	//imprimindo a identidade
	printf("\n Matriz Identidade:\n");
	show_m(ordem, matriz);
	
	//imprimindo a inversa
	printf("\n Matriz Inversa: \n");
	show_m(ordem, id);

	return 0;
}
