#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float norm2(int k, float vetorb[])
{
	//for vectors
  int i;
   float s = 0;
	
   
	for(i=0;i<k;i++)
	   s += vetorb[i]*vetorb[i];
	   
	   s = sqrt(s);
	   return s;
		  
}

int main(void){
	
	int i, j, k, a = 0, flag;
	
	srand( (unsigned)time(NULL) );
	
	printf("Entre com a dimensao.\n");
	
	scanf("%d", &k);
	
	float matriz[k][k];
	float vetorb[k];
	float Rt[k][k];
	float x[k], y[k], t[k];
	float r1,r2; // stores the residue, r1
	 //stores the previous iteration residue and r2 stores the current;
	float sub1 = 0;
	float sub2 = 0;
	float tol;
	
	
	
//gera matriz aleatória:		
	for(i = 0; i < k; i++)
	{
		for(j = 0; j < k; j++)
		{
			a = 1 + (rand() % 500);
			
			matriz[i][j] = a;
			
			if (k == 2)
			{
				if(i == 1 && j == 1)
				{
					matriz[i][j] = matriz[0][0];
				}
			}
		
			if (i > 0 && j < i)
			{
				matriz[i][j] = matriz[j][i];
			}

		}
	
	}
	
	printf("\nA matriz A gerada foi: \n");
	
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("%.1f ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\nEntre com o vetor b.\n");
	for(i = 0; i < k; i++)
	{
		scanf("%f", &vetorb[i]);
	}
	
	//PARA RESOLVER GAUS
	printf("\nEntre com uma tolerancia.\n");
	scanf("%f", &tol);
	
	//----------------------------N O R M A  D E  F R O B E N I U S--------------------------------------------
	
	float aux = 0;
	float resultado;
	
	for(i = 0; i < k; i++)
	{ 
		for(j = 0; j < k; j++)
	  	{
	   		aux += pow(matriz[i][j], 2);
		}	 
	}
	resultado = sqrt(aux);
	
	printf("\n");
	
	printf("A norma de Frobenius da matriz inserida eh igual a: %f\n", resultado);
	
	//----------------------------G A U S S - S E I D E L------------------------------------------------------
	
	
	for(i=0;i<k;i++)
	    {
           for(j=0;j<i;j++)
			   sub1 += matriz[i][j]*x[j];
		
		   for(j=(i+1);j<k;j++)
			  sub2 += matriz[i][j]*x[j];
		
		    x[i] = (1-1)*x[i] + (1/matriz[i][i])*(vetorb[i]-(sub1+sub2));
		    sub1 = 0;
		    sub2 = 0;
		
	    }
	    
	    for(i=0;i<k;i++)
		    t[i]=0;
	
		for(i=0;i<k;i++)
            for(j=0;j<k;j++)
                t[i] += matriz[i][j]*x[j];
        for(i=0;i<k;i++)
            t[i]-=vetorb[i];
        r2 = norm2(k,t);	
        
    do
    {
		r1 = r2;
	
	    for(i=0;i<k;i++)
	    {
           for(j=0;j<i;j++)
			   sub1 += matriz[i][j]*x[j];
		
		   for(j=(i+1);j<k;j++)
			  sub2 += matriz[i][j]*x[j];
		
		    x[i] = (1-1)*x[i] + (1/matriz[i][i])*(vetorb[i]-(sub1+sub2));
		    sub1 = 0;
		    sub2 = 0;
		
	    }
	    
	    for(i=0;i<k;i++)
		    t[i]=0;
	
		for(i=0;i<k;i++)
            for(j=0;j<k;j++)
                t[i] += matriz[i][j]*x[j];
        for(i=0;i<k;i++)
            t[i]-=vetorb[i];
        r2 = norm2(k,t);
        if ( r2 > r1);
        {
			flag = 0;
			break;
		}	
	}
    while((r2>tol));
    
    if(flag)
    {
		printf("\nEsse sistema nao converge por gauss-seidel.\n");
	}
	else
	{
		printf("\n-------Resultado por Gauss-Seidel-------\n");
	    for(i=0;i<k;i++)
        {
		   printf("x: %.3f\n", x[i]);  
                   
	    }
	 }
	 
	//-------------------------------------------F I M  D E  G A U S S - S E I D E L---------------------------------
	
	float s = 0;
	
	if(!(flag))
	{
		//||b - Ax||
	
		 float mult1[k], res1[k];
		 
		
		//calcula Ax
		 for(i = 0; i < k; i++)
		 {
		     for(j = 0; j < k; j++)
		     {
		         mult1[i] += matriz[i][j]*x[j];
		     }
		 }
		 
		//b - Ax
	 	for(i = 0; i < k; i++)
	 	{
	 		res1[i] = vetorb[i] - mult1[i];
		}
		
	   
	   //||b-Ax||
		for(i=0;i<k;i++)
		   s += res1[i]*res1[i];
		   
		   s = sqrt(s);
		   
		printf("\nNorma do residuo de Gauss:\n");
		printf("%f\n", s);
		
		s = 0;

		
	}
	
	for(i=0;i<k;i++)
	{
		x[i] = 0;
	}

	//----------------------------C H O L E S K Y---------------------------------------------
	//ACHANDO R PARA RESOLVER CHOLESKY
	int n, l, verifica = 1;
	
	for(i=0; i < k; i++){

		for(n=0; n <= i-1; n++)
			matriz[i][i] -= pow(matriz[n][i], 2);

		if(matriz[i][i] <= 0){
			verifica = 0;
			printf("\nA matriz gerada nao eh positiva definida.\n");
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
		printf("%.3f ", x[i]);
	}
	//-------------------------------F I M D E C H O L E S K Y-----------------------------------------------------
	
	//||b - Ax||

	 float mult2[k], res2[k];
	 
	
	//calcula Ax
	 for(i = 0; i < k; i++)
	 {
	     for(j = 0; j < k; j++)
	     {
	         mult2[i] += matriz[i][j]*x[j];
	     }
	 }
	 
	//b - Ax
 	for(i = 0; i < k; i++)
 	{
 		res2[i] = vetorb[i] - mult2[i];
	}
	
   
   //||b-Ax||
	for(i=0;i<k;i++)
	   s += res2[i]*res2[i];
	   
	   s = sqrt(s);
	   
	printf("\nNorma do residuo de Cholesky:\n");
	printf("%f\n", s);


	
	return 0;
	
}
