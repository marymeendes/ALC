#include <stdio.h>
#include <math.h>

//função que exibe matrizes
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

//função que zera matrizes
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

//funções que verificam se é ortogonal ou não
float calculaDeterminante(int ordem, float matrizA[ordem][ordem])
{   
    int i = 0, j = 0, k = 0;	
    float factor = 0;	
    float temp = 0;	
    int count = 0;	

    for(i = 0; i < ordem - 1; i++)
    {
        if(matrizA[i][i] == 0)
        {
            for(k = i; k < ordem; k++)
            {
                if(matrizA[k][i] != 0)
                {
                    for(j = 0; j < ordem; j++)
                    {
                        temp = matrizA[i][j];
                        matrizA[i][j] = matrizA[k][j];
                        matrizA[k][j] = temp;
                    }
                    k = ordem;
                }
            }
            count++;
        }

        if(matrizA[i][i] != 0)
        {
            for(k = i + 1; k < ordem; k++)
            {
                factor = -1.0 * matrizA[k][i] /  matrizA[i][i];
                for(j = i; j < ordem; j++)
                {
                    matrizA[k][j] = matrizA[k][j] + (factor * matrizA[i][j]);
                }
            }
        }
    }

    temp = 1.0;
    	
    for(i = 0; i < ordem; i++)
        temp *= matrizA[i][i];

    if(count % 2 == 0)
       return temp;
    else
        return -1 * temp;
}

void ehOrtogonal(int ordem, float matriz[ordem][ordem]){
	
	if(calculaDeterminante(ordem, matriz) != 0){
	
		int i, j, k = 0, verifica = 1;
		float mTransposta[ordem][ordem];
		
		zeros_m(ordem, mTransposta);
		
		//construindo a transposta
		for (i=0; i < ordem; i++){
			for (j=0; j < ordem; j++){
				mTransposta[j][i] = matriz[i][j];
			}
		}
		
		// imprimindo a transposta
		printf("\nMatriz Transposta: \n");
		show_m(ordem, mTransposta);
		
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
		
		//calculando a inversa
		for(j=0; j < ordem; j++){
			
			pivo = matriz[j][j];
			p = pivo/pivo;
			for(k=0; k < ordem; k++){
				matriz[j][k] = matriz[j][k] / pivo; 
				id[j][k] = id[j][k] / pivo; 
			}
			
			for(i=0; i < ordem; i++){
				if(i != j){
					m = matriz[i][j]/p;
					
					for(k=0; k < ordem; k++){
						matriz[i][k] = matriz[i][k] - (m * matriz[j][k]); 
						id[i][k] = id[i][k] - (m * id[j][k]); 
					}
				}		
			}
		}
		
		//Resultado
		
		//imprimindo a inversa
		printf("\nMatriz Inversa: \n");
		show_m(ordem, id);
		
		///////////////////// segunda parte ///////////////////////////
		
		//comparando com a transposta com a inversa	
		for(i = 0; i < ordem; i++){
			
			for(j = 0; j < ordem; j++){
				
				if(id[i][j] != mTransposta[i][j])
					verifica = 0;
			}
		}
		
		if(verifica)
			printf("\nLogo, a matriz inserida eh Ortogonal. \n");
		else
			printf("\nLogo, a matriz inserida nao eh Ortogonal. \n");
	
	}else printf("Determinante da matriz inserida eh %.1f e portanto ela nao pode ser ortogonal, pois nao eh inversivel.\n", calculaDeterminante(ordem, matriz)); 
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
		printf("\n");
		printf("----------- Resultado -----------\n");
		printf("\n");
		
		ehOrtogonal(ordem, matriz);

	}	
	return 0;
}


