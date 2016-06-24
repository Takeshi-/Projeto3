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
		fprintf(fp,"{2 ");
		for(i = 3; counter < 10000; i++){
			if(isPrime(i) == 1){
				fprintf(fp, ",%d ", i);
				counter ++;
			}
		}
		fprintf(fp, "}\n");
		fclose(fp);
	}
	
	
	return 0;
}
