#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 15
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

void Pm(int n, int vet[]){
	int j, k, i =0;
	j = n;
	k = 2;
	while(j > 0){
		if(isPrime(k)){
			vet[i++] = k;
			j --;
		}
		k++;
	}
}

void quadrados(int mat[][N+1], int vet[]){
	int i, j, k =0;
	for(i = 0; i < SIZE; i++){
		for(j = 0; j <= N; j++){
			mat[i][j] = pow(vet[i], j);
		}
	}
}

int S (int mat[][N+1]){
	int i, j, k, counter;
	counter = 0;
	for(i = 0; i < SIZE; i++){
		for(j = 0; j <N; j++){
			for(k = 1; k < j; k++)
			if (mat[i][j]%k == 0){
				counter++;
			}
		}
	}
	return counter;
}

int main(){
	int vet[SIZE], mat[SIZE][N+1], i, j;
	Pm(SIZE, vet);
	quadrados(mat, vet);
//	for(i = 0; i < SIZE; i++){
//		for(j = 0; j <= N; j++)
//			printf("%d ", mat[i][j]);
//		printf("\n");
//	}
	printf("\n");
	return 0;
}
