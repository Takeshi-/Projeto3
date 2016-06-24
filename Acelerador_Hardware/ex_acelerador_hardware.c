#include <stdio.h>
#include <stdlib.h>

volatile int *lock = (int *) (100*1024*1024);
volatile int *prime = (int *) (100*1024*1024+2);


void test(){
	*lock = 0;
	int i;
	
	for (i = 0; i < 30; i++){
		printf("prime[%d] = %d\n", i, prime[i]);
	}
	printf("%d\n", *lock);
	printf("%d\n", *lock);
}

int main() {
	
	test();
	
	return 0;
}
