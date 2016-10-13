#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float norm2(int n, float b[])
{
   int i;
   float s = 0;
   
	for(i=0;i<n;i++)
	   s += b[i]*b[i];
	   
	   s = sqrt(s);
	   return s;
		  
}
void sor (int n,float w, float a[][n], float b[], float x[])
{
	float sub1 =0;
	float sub2 =0;
	int i,j;
	for(i=0;i<n;i++)
	{
        for(j=0;j<i;j++)
		{
			sub1 += a[i][j]*x[j];
		 
		}
		
		for(j=(i+1);j<n;j++)
		{
			sub2 += a[i][j]*x[j];
		 
		}
		
		x[i] = (1-w)*x[i] + (w/a[i][i])*(b[i]-(sub1+sub2));
		sub1 = 0;
		sub2 = 0;
		
	}	
	
	
}
void show_m(int ordem, float matriz[ordem][ordem])
{
	int i, j;
	
	printf("______choleski_______\n");
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			printf("%.1f ", matriz[i][j]);
		}

		printf("\n");
	}
}
void fatorCholesky(int ordem, float matriz[ordem][ordem]){
	int i, j, k, l;

	for(i=0; i < ordem; i++){

		for(k=0; k <= i-1; k++)
			matriz[i][i] -= pow(matriz[k][i], 2);


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

}

int main (void){
	float matriz[3][3];
	
	int linha = 0, coluna = 0, i , j, v;
	while(coluna!=3){
		if(coluna<3){
			if(linha<3){
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
	
	
	
	float b[3];
	coluna = 0;
	for(coluna = 0; coluna < 3; coluna++){
		printf("\nDigite o valor presente na coluna: %d do vetor b:\n", coluna);
		scanf("%f", &b[coluna]);
	}
	
	//L+U
	
	float lu[3][3];
	
	for(i = 0; i<3; i++){
		for(j = 0; j<3; j++){
			lu[i][j] = - matriz[i][j];
		}
	}
	
	for(i = 0; i<3; i++){
		lu[i][i] = 0;
	}
	
	//D-1
	
	float D[3][3];
	
	for(i = 0; i<3; i++){
		for(j = 0; j<3; j++){
			D[i][j] = 0;
		}
	}
	
	for(i = 0; i<3; i++){
		D[i][i] = 1/matriz[i][i];
	}
	
	// MULTIPLICAÇÃO
	
	float T[3][3];
	
	for(i = 0; i<3; i++){
		for(j = 0; j<3; j++){
			T[i][j] = 0;
		}
	}
	
	for (i = 0 ; i < 3; i++ )
      for (j = 0; j < 3; j++)
         for (v = 0; v < 3; v++)
            T[i][j] = T[i][j] + D[i][v] * lu[v][j];
	
	
	float det, w;
	det = -(T[0][1]*T[1][0]*-1 + T[1][2]*T[2][1]*-1);
	
	w = 2/(1+sqrt(1-pow(sqrt(det),2)));
	
	float t[3];
    float x[3];
	float k;
	 printf("Digite a tolerancia\n");
       scanf("%f",&k);
       printf("\n");  
       
     
       printf("Digite o valor inicial de x\n");
       
       for(i=0;i<3;i++)
           scanf("%f",&x[i]); 
    
    do
    {
		for(i=0;i<3;i++)
		   t[i]=0;
		sor(3,w,matriz,b,x);
		for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                t[i] += matriz[i][j]*x[j];
        for(i=0;i<3;i++)
            t[i]-=b[i];     
	  
	}
    while((norm2(3,t)>k));
       
    printf("______Sor______\n");
    for (i=0;i<3;i++) 
         printf("%f\n", x[i]);
    
    
    fatorCholesky(3, matriz);
	//system("PAUSE");
	return 0;
}
