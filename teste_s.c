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

	long num = 1000000000000000000;
	long num2 = 1;
	long num3 = 1000;
	BigInt numb_1, numb_2, numb_3;
	BigInt numb_sm11;
	BigInt numsl_1, numsl_11;


/* ======= fazendo os bigints ======= */
	big_val(numb_1, num);
	big_sum(numb_sm11, numb_1, numb_1);


	/* prints */
	
	printf("\n\nBigInt 11 _________________________\n");
	big_print2(numb_sm11);


/* ======= shift =======*/
	big_shl(numsl_11,numb_sm11, 10);
	big_print2(numsl_11);


	return 0;
}

