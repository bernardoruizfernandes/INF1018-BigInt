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

	long num = 10000000000000;
	long num2 = -1;

	BigInt numb_1, numb_2;
	BigInt numb_sr1, numb_sa1, numb_m, numb_m2, numb_m3;



/* ==================================================================================== */
	big_val(numb_1, num);
	big_val(numb_2, num2);

	big_mul(numb_m,numb_1,numb_1);
	big_mul(numb_m2,numb_m,numb_m);
	big_mul(numb_m3,numb_m,numb_2);

	big_shr(numb_sr1,numb_m3, 80);
	big_sar(numb_sa1,numb_m3, 80);



	/* prints */
	
	printf("\n\n_______ BigInt 1 ___________________________\n");
	big_print2(numb_m3);
	big_print2(numb_sr1);

	printf("\n\n_______ BigInt 2 ___________________________\n");
	big_print2(numb_m3);
	big_print2(numb_sa1);



	return 0;
}
