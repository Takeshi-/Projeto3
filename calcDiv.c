#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 2
#define N 2

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

int factorial(int f) {
	if ( f == 0 ) 
        return 1;
    return(f * factorial(f - 1));
}

int S(int vet[]){
	int i, j = N,count = 0;
	for(i=1;i<=N;i++){
		/*for ( j= i; j <= N;j++){
			count += j*N*(M-1)+pow(N,M-1);
		}*/
		//for(j = i; j <= N; j++){
			count += i * pow(N+1, M-1);
			//count += i * pow(N+1+(pow(N+1, M-1)/M-1), M-1);
			printf("%d\n", count);
		//}
		
	}
	count *= (M);
	count += pow(N, M);
	//count -= ();
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
