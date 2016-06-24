#include <stdio.h>
#include <stdlib.h>

volatile int procCounter = 0;
#define LOCK_ADDRESS 0x800000;

volatile int *lock = ( volatile int *) LOCK_ADDRESS;

void AcquireLock(){
	while (*lock);
}

void ReleaseLock()
{
	*lock = 0;
}

void RecursiveHello( int n, int procNumber)
{
	if (n) 
		printf("Hi from processor PowerPC %d!\n",RecursiveHello(n - 1, procNumber);
}

int main( int ac, char *av[])
{

	int procNumber;
	AcquireLock();
	procNumber = procCounter;
	procCounter ++;
	ReleaseLock();
	if (procNumber % 2)
		for (i = 0; i < 100000; i ++);
	
	
	RecursiveHello(10, procNumber);
	return 0;

}
