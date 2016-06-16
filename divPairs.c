#include <stdio.h>
#include <stdlib.h>


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

int isPrime(int n){
	int i, answer;
	
	for(i = 2; i < n/2; i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1; 
}

int Pm(int n){
	int counter, j, k;
	j = n;
	counter = 1;
	k = 2;
	while(j > 0){
		if(isPrime(k)){
			counter = counter * k;
			j --;
		}
		k++;
	}
	return counter;
}

int S(int n)
{
	int i, j, counter;
	counter = 0;
	for(i = 2; i <= n; i++){
		for(j = 1; j <i; j++){
			if ((n%i == 0) && (i%j == 0)){
				counter++;
				printf("(%d, %d)\n", j, i);
			}
		}
		//printf("i = %d\n", i);
	}
	return counter;
				 
}


int E(int m, int n){
	int aux, answer, divisor;
	aux = Pm(m);
	aux = expo(aux, n);
	aux = S(aux);
	divisor = 1;
	answer = -1;
	
	while(aux%divisor == 0){
		answer ++;
		divisor = divisor*2;
	}
	return answer;
	
	
}

int Q(int n){
	int i, summer;
	summer = 0;
	for(i = 1; i <= n; i++){
		summer = summer + E(904961, i);
	}
	return summer;
}
	

int main(){
	int n, answer;
	n = 10;
	answer = S(n);
	printf("%d\n", answer);
	printf("%d\n", isPrime(3));
	printf("%d\n", Pm(2));
	printf("%d\n", expo(10, 5));
	printf("%d\n", E(2,1));
	printf("%d\n", Q(8)); //Ele buga aqui, por ter que calcular numeros enormes de produto de primos.
	return 0;
}
