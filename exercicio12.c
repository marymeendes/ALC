 /*
12) Construa um algoritmo que avalie se uma matriz A de ordem k é triangular superior ou inferior. 
Caso seja triangular peça ao usuário que insira o vetor b. Resolva o sistema Ax = b. 
Sendo x o vetor solução do sistema. Retorne também um vetor unitário de mesma direção e sentido de x.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int ordem, triangular = 0, superior = 0, inferior = 0;
	printf("Digite o valor da ordem da matriz: ");
	scanf("%d", &ordem);
	float matriz[ordem][ordem];
	
	int linha = 0, coluna = 0;
	while(coluna!=ordem){
		if(coluna<ordem){
			if(linha<ordem){
				printf("\nDigite o valor presente na coluna: %d, e na linha: %d da matriz A:\n", coluna, linha);
				scanf("%f", &matriz[coluna][linha]);
				linha++;
			}else{
				linha=0;
				coluna++;
			}
		}else{
			coluna++;
		}
	}
	
	
	
	linha = 0;
	coluna = 0;
	int posicao=1;
	while(coluna!=ordem){
		if(coluna<ordem){
			if(linha<ordem){
				if(linha>=posicao){
					if(!matriz[coluna][linha]==0)
						break;
				}
				linha++;
			}else{
				linha=0;
				coluna++;
				posicao++;
			}
		}else{
			coluna++;
		}
	}
	if(coluna == ordem){
		printf("Eh triangular inferior!\n");
		triangular = 1;
		inferior = 1;
	}
	
	
	
	linha = ordem-1;
	coluna = 0;
	posicao = -1;
	while(coluna!=ordem){
		if(coluna<ordem){
			if(linha!=-1){
				if(linha<=posicao){
					if(!matriz[coluna][linha]==0)
						break;
				}
				linha--;
			}else{
				linha=ordem-1;
				coluna++;
				posicao++;
			}
		}else{
			coluna++;
		}
	}
	if(coluna == ordem){
		printf("Eh triangular superior!\n");
		triangular = 1;
		superior = 1;
	}
	
	
	
	if(triangular == 1){
		float b[ordem], x[ordem];
		coluna = 0;
		for(coluna = 0; coluna < ordem; coluna++){
			printf("\nDigite o valor presente na coluna: %d do vetor b:\n", coluna);
			scanf("%f", &b[coluna]);
			x[coluna]=1;
		}
		
		printf("\nO vetor x eh:\n");
		int diferenca = 0;
		if(inferior == 1){
			diferenca = 0;
			posicao=1;
			for(coluna = 0; coluna < ordem; coluna++){
				if(posicao!=1){
					for(linha = 0; linha < posicao-1; linha++){
						diferenca += matriz[coluna][linha]*x[linha];
					}
				}
				x[coluna] = (b[coluna]-diferenca)/matriz[coluna][coluna];
				posicao++;
				diferenca = 0;
			}
		}
		if(superior == 1){
			diferenca = 0;
			posicao=-1;
			for(coluna = ordem-1; coluna > -1; coluna--){
				if(posicao!=-1){
					for(linha = ordem-1; linha > coluna; linha--){
						diferenca += matriz[coluna][linha]*x[linha];
					}
				}
				x[coluna] = (b[coluna]-diferenca)/matriz[coluna][coluna];
				posicao++;
				diferenca = 0;
			}
		}
		for(coluna = 0; coluna < ordem; coluna++){
			printf("[%f]\n", x[coluna]);
		}
		printf("\nO vetor unitario de mesma direcao e sentido de x eh:\n");
		
		float comprimento = 0;
		float v[ordem];
		
		for(coluna = 0; coluna < ordem; coluna++){
			comprimento += pow(x[coluna],2);
		}
		
		comprimento = sqrt(comprimento);
		
		for(coluna = 0; coluna < ordem; coluna++){
			v[coluna] = x[coluna]/comprimento;
		}
		
		for(coluna = 0; coluna < ordem; coluna++){
			printf("[%f]\n", v[coluna]);
		}
	} else {
		printf("Não eh triangular superior nem inferior!\n");
	}
	
	return 0;
}
