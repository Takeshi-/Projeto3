#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMEROCORES 4

volatile int procCounter = 0;
volatile int* gLock = (int *)(100*1024*1024);
volatile int lock1 = 0;
volatile int lock2 = 0;
volatile int lock3 = 0;

volatile int expo_count = -1;
volatile int totalSum_Pm = 0;
volatile int total_S_aux = 0;
volatile int done_S = 0;
volatile int done_Pm = 0;
volatile int done_E = 0;
volatile int pm_done = 0;
volatile int dekkoh = 0;

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
	
	for(i = 2; i <= n/2 ; i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1; 
}

/* Pm: Calculates the sum of the first n prime numbers. */
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
void S(int n,int *counter)
{
	int i, j, aux=0;
	int procNumber;
	
	AcquireLocalLock(&lock1);
	
	procNumber = procCounter;
	printf("%d\n", procNumber);
	
	if(procNumber >= NUMEROCORES){
		ReleaseLocalLock(&lock1);
		return;
	}
	procCounter++;
	ReleaseLocalLock(&lock1);
	
	for(i = procNumber+2; i <= n; i+=NUMEROCORES){
		
		for(j = 1; j <i; j++){
			if ((n%i == 0) && (i%j == 0)){
				aux++;
			}
		}
	}
	
	AcquireLocalLock(&lock2);
	total_S_aux += aux;
	done_S++;
	ReleaseLocalLock(&lock2);
	
	if (done_S == NUMEROCORES){
		(*counter) = total_S_aux;
		AcquireLocalLock(&lock1);
		procCounter = 0;
		done_S = 0;
		ReleaseLocalLock(&lock1);
		pm_done = 1;
	} else{
		while(pm_done == 0);
	}
}

/* E(m,n): Calculates the highest k, that 2^k is divisor of the number 
 * (S(Pm(m)^n)) */
void E(int m, int n, int  *result){
	int aux, answer, divisor,help;
	AcquireLocalLock(&lock1);
	if(expo_count == -1){
		done_E = 0;
		expo_count = expo(Pm(m), n);
	}
	ReleaseLocalLock(&lock1);
	
	S(expo_count,&help);
	expo_count = -1;
	AcquireLocalLock(&lock1);
	if(done_E == 0){
		done_E = 1;
		divisor = 2;
		answer = 0;
		while(help%divisor == 0){
			answer++;
			divisor = divisor*2;
		}
		*result = answer;
	}
	ReleaseLocalLock(&lock1);
}
/* Q(n): Weirdo function described in the end of the enunciate. */
int Q(int n){
	int i, sum,aux = 0;
	
	for(i = 1;i <= n; i ++){
		E(18, i, &sum);
		
		aux += sum;
	}
//	if (dekkoh == NUMEROCORES)
//		printf("%d\n", sum);
	return aux;	
}
	
/* Main(): Used to verify the functions */
int main(){
	int n, answer;
	n = 28;
//	S(n, &answer);
	//printf("%d\n", isPrime(3));
	//printf("%d\n", Pm(25)*Pm(25));
	//printf("%d\n", expo(9, 5));
	answer = Q(2);
	AcquireLocalLock(&lock3);
		printf("%d\n", answer);
		for(n = 0; n < 1; n++){}
	ReleaseLocalLock(&lock3);
	//Q(5);
	//Ele buga aqui, por ter que calcular numeros enormes de produto de primos.
	return 0;
}
