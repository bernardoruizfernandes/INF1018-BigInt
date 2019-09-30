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
	long num2 = -5;
	BigInt numb_1, numb_2;
	BigInt numb_sr1, numb_sr2;



/* ==================================================================================== */
	big_val(numb_1, num);
	big_val(numb_2, num2);

	big_shr(numb_sr1,numb_1, 10);
	big_shr(numb_sr2,numb_2, 5);



	/* prints */
	
	printf("\n\n_______ BigInt 1 ___________________________\n");
	big_print(numb_1);
	big_print(numb_sr1);

	printf("\n\n_______ BigInt 2 ___________________________\n");
	big_print(numb_2);
	big_print(numb_sr2);



	return 0;
}
