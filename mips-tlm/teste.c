#include <stdio.h>
#include <stdlib.h>

#define NUMEROCORES 1

volatile int procCounter = 0;
volatile int* gLock = (int *)(100*1024*1024);
volatile int lock1 = 0;
volatile int count = 0;
volatile int vet[10000];

void AcquireGlobalLock(){ while(*gLock){}}
void ReleaseGlobalLock(){*gLock = 0;}

void AcquireLocalLock(volatile int *lock)
{
	int i;
	AcquireGlobalLock();
	while(*lock)
	{
		ReleaseGlobalLock();
		for(i=0; i < 10; i++) {}
		AcquireGlobalLock();
	}
	*lock = 1;
	ReleaseGlobalLock();
}

void ReleaseLocalLock(volatile int *lock)
{
	AcquireGlobalLock();
	*lock = 0;
	ReleaseGlobalLock();
}

void intercala(volatile int *v, int p, int q, int r)
{
	int i, j, k;
	int w[10000];

	i = p; 
	j = q;
	k = 0;

	while (i < q && j <= r) {
		if (v[i] <= v[j])  
			w[k++] = v[i++];
		else  
			w[k++] = v[j++];
	}

	while (i < q)  
		w[k++] = v[i++];

	while (j <= r)  
		w[k++] = v[j++];

	for (i = p; i <= r; i++)  
		v[i] = w[i-p];
} 

void quick(volatile int *vetor, int inicio, int fim)
{
    int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) quick(vetor, inicio, j);
   if(i < fim) quick(vetor, i, fim);  

}

void main2()
{
	int procNumber,i,n;
	
	AcquireLocalLock(&lock1);
	
	procNumber = procCounter;
	procCounter++;
	
	if (procNumber >= NUMEROCORES)
	{
		ReleaseLocalLock(&lock1);
		return;
	}
	
	if (procNumber == 0)
	{
		//scanf("%d",&n);
		n= 10000;
		for ( i = 0 ; i < n ; i++ )
			vet[i]=n-i;
	}
	ReleaseLocalLock(&lock1);

	quick(vet,n/NUMEROCORES*procNumber,n/(NUMEROCORES-procNumber)-1);

	AcquireLocalLock(&lock1);
	count++;
	ReleaseLocalLock(&lock1);

	if (count == NUMEROCORES)
	{
		intercala(vet,0,n/2,n-1);
		/*for (i = 0; i < n; i ++)
			printf("%d ",vet[i]);
		printf("\n");*/
	}
	
}

int main(int ac, char *av[])
{
	main2();
	return 0;
}
