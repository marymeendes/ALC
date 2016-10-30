//Algoritmo da questão 15 da lista
//Funções: recebe uma matriz A e avalia se ela é tridiagonal, ortogonal ou positiva definida
//A função fatorCholesky foi adaptada do algoritmo do livro usado nas aulas de ALC,  Fundamentals of Matrix Computations
//A função ehOrtogonal têm trechos adaptados do algoritmo do site http://coisasdapaloma.blogspot.com.br/2013/01/achar-matriz-inversa-em-c.html


#include <stdio.h>
#include <math.h>

//PROTÓTIPOS

void show_m(int ordem, double matriz[ordem][ordem]);
void zeros_m(int ordem, double matriz[ordem][ordem]);
void makes_id(int ordem, double matriz[ordem][ordem]);
void ehTridiagonal(int ordem, double matriz[ordem][ordem]);
int ehSimetrica (int ordem, double matriz[ordem][ordem]);
void fatorCholesky(int ordem, double matriz [ordem][ordem]);
void ehOrtogonal(int ordem, double matriz[ordem][ordem]);

//MAIN

int main(void)
{
	int ordem, i, j;
	
	printf("Digite a ordem da matriz:\n");
	scanf("%d", &ordem);
	
	if(ordem < 2)
		printf("A matriz a ser inserida nao pode ter ordem inferior a 2.\n");
	else
	{
		double matriz[ordem][ordem];
		
		printf("Insira a matriz: \n");
		
		for(i = 0; i < ordem; i++)
		{ 
			for(j = 0; j < ordem; j++)
		  	{
		   		scanf("%lf", &matriz[i][j]);
			}	 
		}
		printf("\n");
		printf("----------- Resultado -----------\n");
		printf("\n");
		
		ehTridiagonal(ordem, matriz);
		ehOrtogonal(ordem, matriz);
		fatorCholesky(ordem, matriz);
	}	
	return 0;
}

//FUNCOES CITADAS NOS PROTÓTIPOS

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

void ehTridiagonal(int ordem, double matriz[ordem][ordem]){
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
		printf("\nA matriz inserida eh matriz tridiagonal.\n");
	else
		printf("\nA matriz inserida nao eh matriz tridiagonal.\n");
}

int ehSimetrica (int ordem, double matriz[ordem][ordem]){
	int i, j, verifica = 1;
	double mTransposta[ordem][ordem];
	
	zeros_m(ordem, mTransposta);
	
	//construindo a transposta
	for (i=0; i < ordem; i++){
		for (j=0; j < ordem; j++){
			mTransposta[j][i] = matriz[i][j];
		}
	}
	
	//comparando a transposta com a matriz original
	for(i = 0; i < ordem; i++){
		
		for(j = 0; j < ordem; j++){
			
			if(matriz[i][j] != mTransposta[i][j])
				verifica = 0;
		}
	}
	
	return verifica;	
}

// funcao que verifica se eh positiva definida ou nao
void fatorCholesky(int ordem, double matriz[ordem][ordem]){
	int i, j, k, l, verifica = 1;

	if(ehSimetrica(ordem, matriz)){

		for(i=0; i < ordem; i++){
	
			for(k=0; k <= i-1; k++)
				matriz[i][i] -= pow(matriz[k][i], 2);
	
			if(matriz[i][i] <= 0){
				verifica = 0;
				//return verifica;
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
		
		if(verifica){	
			printf("\nA matriz inserida eh positiva definida.\n");
			
			printf("E seu Fator de Cholesky eh: \n");
			show_m(ordem, matriz);
		}
		else
			printf("\nA matriz inserida nao eh positiva definida.\n");
	}
	else
		printf("\nA matriz inserida nao eh simetrica, logo, nao eh positiva definida.\n");
		
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
