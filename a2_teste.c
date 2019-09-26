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
	BigInt numb_1, numb_2;
	BigInt numb_c1, numb_c2;



/* ==================================================================================== */
	big_val(numb_1, num);
	big_val(numb_2, num2);

	big_comp2(numb_c1, numb_1);
	big_comp2(numb_c2, numb_2);



	/* prints */
	
	printf("\n\n_______ BigInt 1 ___________________________\n");
	big_print2(numb_1);
	big_print2(numb_c1);

	printf("\n\n_______ BigInt 2 ___________________________\n");
	big_print2(numb_2);
	big_print2(numb_c1);



	return 0;
}
