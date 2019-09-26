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
	BigInt numb_sm11, numb_sm12, numb_sm13;
	BigInt numb_sm22, numb_sm23;
	BigInt numb_sm33;


/* ======= fazendo os bigints ======= */
	big_val(numb_1, num);
	big_val(numb_2, num2);
	big_val(numb_3, num3);


	big_sum(numb_sm11, numb_1, numb_1);
	big_sum(numb_sm12, numb_1, numb_2);
	big_sum(numb_sm13, numb_1, numb_3);

	big_sum(numb_sm22, numb_2, numb_2);
	big_sum(numb_sm23, numb_2, numb_3);

	big_sum(numb_sm33, numb_3, numb_3);
	

	/* prints */
	
	printf("\n\n_______ 1 * 1 ___________________________\n");
	big_print2(numb_1);
	big_print2(numb_sm11);

	printf("\n\n_______ 1 * 2 ___________________________\n");
	big_print2(numb_1);
	big_print2(numb_2);
	big_print2(numb_sm12);

	printf("\n\n_______ 1 * 3 ___________________________\n");
	big_print2(numb_1);
	big_print2(numb_3);
	big_print2(numb_sm13);




	printf("\n\n_______ 2 * 2 ___________________________\n");
	big_print2(numb_2);
	big_print2(numb_sm22);

	printf("\n\n_______ 2 * 3 ___________________________\n");
	big_print2(numb_2);
	big_print2(numb_3);
	big_print2(numb_sm23);




	printf("\n\n_______ 3 * 3 ___________________________\n");
	big_print2(numb_3);
	big_print2(numb_sm33);

	
	return 0;
}
