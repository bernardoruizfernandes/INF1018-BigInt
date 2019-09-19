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

	long num = 1000000;
	long num2 = 1;
	long num3 = 1000;
	BigInt numb_1, numb_2, numb_3;
	BigInt numb_c1, numb_c2, numb_s12, numb_s13;


/* ======= fazendo os bigints ======= */
	big_val(numb_1, num);
	big_val(numb_2, num2);
	big_val(numb_3, num3);

	/* prints */
	
	printf("\n\nBigInt 1 _________________________\n");
	big_print2(numb_1);

	printf("\n\nBigInt 2 _________________________\n");
	big_print2(numb_2);

	printf("\n\nBigInt 3 _________________________\n");
	big_print2(numb_3);
	
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

/* ======= comparacao dos bigints ======= */
	big_comp2(numb_c1, numb_1);
	big_comp2(numb_c2, numb_2);

	/* prints */
	printf("\n\ninverte a2 (1) _________________________\n");
	big_print2(numb_c1);

	printf("\n\ninverte a2 (2) _________________________\n");
	big_print2(numb_c2);
	
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

/* ======= somando bigints ======= */
	big_sum(numb_s12, numb_1, numb_2);
	big_sum(numb_s13, numb_1, numb_3);
	
	/* prints */

	printf("\n\nSoma (1)(2) _________________________\n");
	big_print2(numb_s12);

	printf("\n\nSoma (1)(3) _________________________\n");
	big_print2(numb_s13);

	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	return 0;
}	
