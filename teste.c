#include <stdio.h>
#include "bigint.h"


void big_print2(BigInt res){
	
	int n = 16;

	while(n--)
		printf("%02x", res[n]);

	printf("\n");
	return;
}


int main (void){

	long teste = 98118;
	BigInt b, c;

	big_val(b, teste);
	big_print2(b);
	
	big_comp2(c, b);
	big_print2(c);

	return 0;
}	
