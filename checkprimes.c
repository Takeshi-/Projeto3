#include <stdio.h>
#include <stdlib.h>

int isPrime(int n){
	int i;
	for(i = 2; i <= n/2; i++){
		if(n%i == 0){
		return 0;
		}
	}
	return 1;
}

int main(){
	int j;
	int i = 215;
	int counter = 0;
	for(j = 2; i > j; j++){
		if(isPrime(j)){
			i = i - j;
			counter ++;
		}
	}
	printf("Counter = %d\n", counter);
	return 0;
}
