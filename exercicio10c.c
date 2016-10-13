#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float norm2(int n, float b[])
{
	//for vectors
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
 


         



int main ()
{
	int n;
    printf("Entre com a dimensao\n");
    scanf("%d", &n);
    
    float a [n][n];
    float b[n],t[n];
    float x[n]; // soh usa pro sor
    float w; // soh usa pro sor
    int i, j;
    float k;
    printf("Entre com a matriz A\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
				scanf("%f", &a[i][j]);
				
            }
           
       printf("Entre com o vetor b\n");        
       for(i=0;i<n;i++)
        {
          scanf("%f",&b[i]);
          
       }
    
       printf("Entre com a tolerancia\n");
       scanf("%f",&k);
       printf("\n");  
       
     
       printf("Entre com valores iniciais para x\n");
       
       for(i=0;i<n;i++)
           scanf("%f",&x[i]); 
           
      printf("Entre com w entre 0 e 2\n");
      
      
      do
         scanf("%f",&w);
      while (!(w>0 && w<2));
       
      do
    {
		for(i=0;i<n;i++)
		   t[i]=0;
		sor(n,w,a,b,x);
		for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                t[i] += a[i][j]*x[j];
        for(i=0;i<n;i++)
            t[i]-=b[i];     
	  
	}
    while((norm2(n,t)>k));
       
    printf("------Resultado por SOR------\n");
    for (i=0;i<n;i++) 
         printf("x%d: %f\n", i, x[i]);
     
   
          
       
          
		return 0;
            
	
}
