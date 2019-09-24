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

	long num = 2;
	long num2 = 10;
	long num3 = 300000;
	BigInt numb_1, numb_2, numb_3;
	BigInt numb_m1, numb_m2;


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


/* ======= fazendo as multiplicacoes ======= */

	big_mul(numb_m1, numb_1, numb_2);
	big_mul(numb_m2, numb_1, numb_3);



	/* prints */
	
	printf("\n\nMultiplicacao 2*10 _________________________\n");
	big_print2(numb_m1);

	printf("\n\nMultiplicacao 2*300000 _________________________\n");
	big_print2(numb_m2);


	return 0;
}
