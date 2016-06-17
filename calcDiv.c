#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 3
#define N 3

int isPrime(int n){
	int i, answer;
	
	for(i = 2; i <= sqrt(n); i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1; 
}

void Pm(int vet[]){
	int j, k, i =0;
	j = M;
	k = 2;
	while(j > 0){
		if(isPrime(k)){
			vet[i++] = k;
			j --;
		}
		k++;
	}
}

int sum(int n){
	int i, counter = 0;
	for(i = 1; i < n; i++){
		counter += i;
	}
	return counter;
}

int S(int vet[]){
	int i, j = N,count = 0;
	for(i=1;i<M;i++){
		count+=(j*N*(M-i)-1);
		j--;
		if (j==0)
			j=N;
	}
	return count;
}

int main(){
	int vet[M], i;
	Pm(vet);
	for(i = 0; i < M; i++)
		printf("%d ", vet[i]);
	printf("\n");
	printf("%d\n",S(vet));
	return 0;
}
