#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//expo: calculates e^n
int expo(int e, int n){
	int en, answer;
	if(n == 0){
		return 1;
	}
	else{
		en = expo(e, n/2);
		answer = en*en;
		if(n%2 == 1){
			answer = answer * e;
		}
	}
	return answer;
}
//isPrime: Verify if n is a prime number.
//Return 1 if true, else false.
int isPrime(int n){
	int i, answer;
	
	for(i = 2; i <= sqrt(n) ; i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1; 
}

/* Pm: Calculates the produtory of the first n prime numbers. */
int Pm(int n){
	int counter, j, k;
	j = n;
	counter = 0;
	k = 2;
	while(j > 0){
		if(isPrime(k)){
			counter += k;
			j --;
		}
		k++;
	}
	return counter;
}
/* S: Calculates how many distints (a,b) distint numbers that divides n
 * return that many values */
int S(int n)
{
	int i, j, counter;
	counter = 0;
	for(i = 2; i <= n; i++){
		for(j = 1; j <i; j++){
			if ((n%i == 0) && (i%j == 0)){
				counter++;
				//printf("(%d, %d)\n", j, i);
			}
		}
		//printf("i = %d\n", i);
	}
	return counter;
				 
}

/* E(m,n): Calculates the highest k, that 2^k is divisor of the number 
 * (S(Pm(m)^n)) */
int E(int m, int n){
	int aux, answer, divisor;
	aux = Pm(m);
	aux = expo(aux, n);
	aux = S(aux);
	printf("%d\n",aux);
	divisor = 1;
	answer = -1;
	
	while(aux%divisor == 0){
		answer ++;
		divisor = divisor*2;
	}
	return answer;
	
	
}
/* Q(n): Weirdo function described in the end of the enunciate. */
int Q(int n){
	int i, sum;
	sum = 0;
	
	for(i = 1; i <= n; i++){
		sum += E(5, i);
		printf("%d-%d\n",i,sum);
	}
	
	return sum;
}
	
/* Main(): Used to verify the functions */
int main(){
	int n, answer;
	n = 10;
	answer = S(n);
	//printf("%d\n", answer);
	//printf("%d\n", isPrime(3));
	//printf("%d\n", Pm(25)*Pm(25));
	//printf("%d\n", expo(9, 5));
	//printf("%d\n", E(2,1));
	printf("%d\n", Q(5));
	//Ele buga aqui, por ter que calcular numeros enormes de produto de primos.
	return 0;
}
