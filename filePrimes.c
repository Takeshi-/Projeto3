#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n){
	int i;
	for(i = 2; i <= n/2;i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int i, counter = 0;
	FILE *fp;
	
	fp = fopen("Primes.txt", "w");
	if(fp != NULL){
		for(i = 2; counter < 1000; i++){
			if(isPrime(i) == 1){
				fprintf(fp, "%d %d\n",counter,  i);
				counter ++;
			}
		}
		fclose(fp);
	}
	
	
	return 0;
}
